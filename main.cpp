#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <iomanip>
#include <random>
#include <exception>
#include <chrono> 
#include <cmath> 
#include <functional>
#include <vector>


using namespace std;

namespace function {

    class Random {
    private:
        int _seed;
        int _min;
        int _max;
    public:
        Random() : _seed(0), _min(0), _max(1) {};
        Random(int seed, int min, int max) : _seed(seed), _min(min), _max(max) {};
        int generate_random_number() {
            mt19937 mt(_seed);
            uniform_int_distribution<int> distribution(_min, _max);
            _seed++;
            return distribution(mt);
        }
    };
    template<typename T>
    struct Node {
    public:
        T key;
        Node<T>* left;
        Node<T>* right;
        Node() : key(0), left(nullptr), right(nullptr) {}
        Node(T value) : key(value), left(nullptr), right(nullptr) {}
    };
    template<typename T>
    class SearchTree {
    private:
        Node<T>* root;
        void clear(Node<T>* node) {
            if (node) {
                clear(node->left);
                clear(node->right);
                delete node;
            }
        }
        Node<T>* copy(Node<T>* node) {
            if (!node) {
                return nullptr;
            }
            Node<T>* new_node = new Node<T>(node->key);
            new_node->left = copy(node->left);
            new_node->right = copy(node->right);
            return new_node;
        }

        void print(Node<T>* node) {
            if (node) {
                print(node->left);
                std::cout << node->key << " ";
                print(node->right);
            }
        }
        bool insert(Node<T>*& node, T val) {
            if (!node) {
                node = new Node<T>(val);
                return true;
            }
            if (val < node->key) {
                return insert(node->left, val);
            }
            else if (val > node->key) {
                return insert(node->right, val);
            }
            return false;
        }
        bool contains(Node<T>* node, T val) {
            if (!node) {
                return false;
            }
            if (val < node->key) {
                return contains(node->left, val);
            }
            else if (val > node->key) {
                return contains(node->right, val);
            }
            return true;
        }
        bool erase(Node<T>*& node, T val) {
            if (!node) {
                return false;
            }
            if (val < node->key) {
                return erase(node->left, val);
            }
            else if (val > node->key) {
                return erase(node->right, val);
            }
            else {
                if (!node->left) {
                    Node<T>* temp = node->right;
                    delete node;
                    node = temp;
                }
                else if (!node->right) {
                    Node<T>* temp = node->left;
                    delete node;
                    node = temp;
                }
                else {
                    Node<T>* temp = node->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    node->key = temp->key;
                    erase(node->right, temp->key);
                }
                return true;
            }
        }
    public:
        SearchTree() : root(nullptr) {}
        SearchTree(const SearchTree& other) : root(copy(other.root)) {}
        ~SearchTree() {
            clear(root);
        }
        Node<T>* get_root() const {
            return root;
        }

        SearchTree<T>& operator=(const SearchTree<T>& other) {
            if (this != &other) {
                clear(root);
                root = copy(other.root);
            }
            return *this;
        }

        SearchTree<T>& completion(size_t count) {
            size_t cur_count = 0;
            Random test_seed(0, 0, count * 10);
            while (cur_count != count) {
                if (insert(test_seed.generate_random_number()))
                    cur_count++;
            }
            return *this;
        }

        void print() {
            print(root);
            std::cout << std::endl;
        }
        bool insert(T val) {
            return insert(root, val);
        }
        bool contains(T val) {
            return contains(root, val);
        }
        bool erase(T val) {
            return erase(root, val);
        }
    };

    double get_time_completion(size_t count) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i <= 100; i++) {
            SearchTree<int> test_set;
            test_set.completion(count);
        }
        auto end = std::chrono::high_resolution_clock::now();
        double rezult = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 100;
        return rezult / count;
    }
   

    template <typename T>
    SearchTree<T> unionSets(const SearchTree<T>& first, const SearchTree<T>& second) {
        SearchTree<T> result;
        Node<T>* set_first = first.get_root();
        Node<T>* set_second = second.get_root();

        while (set_first && set_second) {
            if (set_first->key < set_second->key) {
                result.insert(set_first->key);
                set_first = set_first->right;
            }
            else if (set_first->key > set_second->key) {
                result.insert(set_second->key);
                set_second = set_second->right;
            }
            else {
                result.insert(set_first->key);
                set_first = set_first->right;
                set_second = set_second->right;
            }
        }
        while (set_first) {
            result.insert(set_first->key);
            set_first = set_first->right;
        }
        while (set_second) {
            result.insert(set_second->key);
            set_second = set_second->right;
        }

        return result;
    }
    /*template <typename T>
    SearchTree<T> symmetric(const SearchTree<T>& first, const SearchTree<T>& second) {
        SearchTree<T> result;
        Node<T>* set_first = first.get_root();
        Node<T>* set_second = second.get_root();

        while (set_first ) {
            if (set_second.c) {
                set_first = set_first->right;
            }
            else if (set_first->key > set_second->key) {
                result.insert(set_second->key);
                set_second = set_second->right;
            }
            else {
                set_first = set_first->right;
                set_second = set_second->right;
            }
        }
        while (set_first) {
            result.insert(set_first->key);
            set_first = set_first->right;
        }
        while (set_second) {
            result.insert(set_second->key);
            set_second = set_second->right;
        }

        return result;
    }
    */
}
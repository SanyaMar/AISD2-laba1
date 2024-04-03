#include "main.cpp"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;
using namespace function;


TEST(Tests1, Tree_int) {
    SearchTree<int> tree;
    tree.insert(1);
    tree.insert(10);
    tree.insert(100);
    tree.insert(1000);
    tree.print();
    cout << tree.contains(5) << endl;
    cout << tree.contains(10) << endl;
    tree.insert(20);
    tree.insert(30);
    tree.print();
    tree.erase(30);
    tree.print();
    SearchTree<int> tree_2 = tree;
    SearchTree<int> tree_3(tree_2);
    tree_2.print();
    tree_3.print();
}

TEST(Tests2, Union_int) {
    SearchTree<int> tree1;
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
    tree1.insert(4);
    tree1.print();
    SearchTree<int> tree2;
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(1);
    tree2.insert(2);
    tree2.print();
    SearchTree<int> tree3;
    /*tree3.insert(7);
    tree3.insert(8);
    tree3.insert(9);
    tree3.insert(2);
    tree3.print();*/
    tree3 = unionSets(tree1, tree2);
    tree3.print();


}
TEST(Tests3, Tree_float) {
    SearchTree<float> tree;
    tree.insert(0.1);
    tree.insert(0.2);
    tree.insert(0.03);
    tree.insert(0.001);
    tree.print();
    cout << tree.contains(5) << endl;
    cout << tree.contains(0.1) << endl;
    tree.insert(0.02);
    tree.insert(0.04);
    tree.print();
    tree.erase(0.03);
    tree.print();
    SearchTree<float> tree_2 = tree;
    SearchTree<float> tree_3(tree_2);
    tree_2.print();
    tree_3.print();
}

TEST(Tests4, Union_float) {
    SearchTree<float> tree1;
    tree1.insert(0.1);
    tree1.insert(0.2);
    tree1.insert(0.3);
    tree1.insert(0.4);
    tree1.print();
    SearchTree<float> tree2;
    tree2.insert(0.5);
    tree2.insert(0.6);
    tree2.insert(0.1);
    tree2.insert(0.2);
    tree2.print();
    SearchTree<float> tree3;
    tree3 = unionSets(tree1, tree2);
    tree3.print();
}
TEST(Tests5, Symmetric) {
    SearchTree<int> tree1;
    tree1.insert(1);
    tree1.insert(2);
    tree1.insert(3);
    tree1.insert(4);
    tree1.print();
    SearchTree<int> tree2;
    tree2.insert(5);
    tree2.insert(6);
    tree2.insert(1);
    tree2.insert(2);
    tree2.print();
    SearchTree<int> tree3;
    tree3 = symmetric(tree1, tree2);
    tree3.print();
}
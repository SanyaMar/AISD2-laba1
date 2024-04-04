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
    tree3 = unionSets(tree1, tree2);
    tree3.print();


}

TEST(Tests3, Rand) {
    Random seed(8, 0, 1000);
    cout << "1 "<<seed.generate_random_number() << endl;
    cout <<"2 "<< seed.generate_random_number() << endl;
}

//TEST(Tests3, Time_com) {
//    SearchTree<int> set1;
//    SearchTree<int> set2;
//    SearchTree<int> set3;
//    set1.completion(1000);
//    set2.completion(10000);
//    set3.completion(100000);
//    vector<int> v1(1000);
//    vector<int> v2(10000);
//    vector<int> v3(100000);
//    cout << "1000" << endl;
//
//    cout << "set1: " << get_time_completion(1000) << " ms" << endl;
//    cout << "vector1: " << get_time_completion_vector(1000) << " ms" << endl;
//
//    cout << "set1: " << get_time_contains(set1,1000) << " ms" << endl;
//    cout << "vector1: " << get_time_contains_vector(v1,1000) << " ms" << endl;
//
//    cout << "set1: " << get_time_erase(set1,1000) << " ms" << endl;
//    cout << "vector1: " << get_time_erase_vector(v1,1000) << " ms" << endl;
//
//    cout << "set1: " << get_time_insert(set1,1000) << " ms" << endl;
//    cout << "vector1: " << get_time_insert_vector(v1,1000) << " ms" << endl << endl;
//
//    cout << "10000" << endl;
//
//    cout << "set2: " << get_time_completion(10000) << " ms" << endl;
//    cout << "vector2: " << get_time_completion_vector(10000) << " ms" << endl;
//
//    cout << "set2: " << get_time_contains(set2, 10000) << " ms" << endl;
//    cout << "vector2: " << get_time_contains_vector(v2, 10000) << " ms" << endl;
//
//    cout << "set2: " << get_time_erase(set2, 10000) << " ms" << endl;
//    cout << "vector2: " << get_time_erase_vector(v2, 10000) << " ms" << endl;
//
//    cout << "set2: " << get_time_insert(set2, 10000) << " ms" << endl;
//    cout << "vector2: " << get_time_insert_vector(v2, 10000) << " ms" << endl << endl;
//
//    cout << "100000" << endl;
//
//    cout << "set3: " << get_time_completion(100000) << " ms" << endl;
//    cout << "vector2: " << get_time_completion_vector(100000) << " ms" << endl;
//
//    cout << "set3: " << get_time_contains(set3, 100000) << " ms" << endl;
//    cout << "vector2: " << get_time_contains_vector(v3, 100000) << " ms" << endl;
//
//    cout << "set3: " << get_time_erase(set3, 100000) << " ms" << endl;
//    cout << "vector2: " << get_time_erase_vector(v3, 100000) << " ms" << endl;
//
//    cout << "set3: " << get_time_insert(set3, 100000) << " ms" << endl;
//    cout << "vector2: " << get_time_insert_vector(v3, 100000) << " ms" << endl << endl;
//}
//1000
//set1: 12.888 ms
//vector1 : 11.31 ms
//set1 : 0.011 ms
//vector1 : 0.014 ms
//set1 : 0.012 ms
//vector1 : 0.013 ms
//set1 : 12.07 ms
//vector1 : 13.948 ms
//
//10000
//set2 : 11.9822 ms
//vector2 : 10.6535 ms
//set2 : 0.0012 ms
//vector2 : 0.0026 ms
//set2 : 0.001 ms
//vector2 : 0.0028 ms
//set2 : 1.067 ms
//vector2 : 1.3422 ms
//
//100000
//set3 : 12.9172 ms
//vector2 : 10.787 ms
//set3 : 0.00012 ms
//vector2 : 0.00185 ms
//set3 : 0.00011 ms
//vector2 : 0.00167 ms
//set3 : 0.10973 ms
//vector2 : 0.15005 ms
 
 
 
 
TEST(Tests3, Symmetric) {
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
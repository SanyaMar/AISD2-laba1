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

TEST(Tests3, Time_com) {
    SearchTree<int> s3;
    s3.completion(1000);

    cout << "1000 = " << get_time_completion(1000) << " ms";
}

//TEST(Tests3, Symmetric) {
//    SearchTree<int> tree1;
//    tree1.insert(1);
//    tree1.insert(2);
//    tree1.insert(3);
//    tree1.insert(4);
//    tree1.print();
//    SearchTree<int> tree2;
//    tree2.insert(5);
//    tree2.insert(6);
//    tree2.insert(1);
//    tree2.insert(2);
//    tree2.print();
//    SearchTree<int> tree3;
//    tree3 = symmetric(tree1, tree2);
//    tree3.print();
//}
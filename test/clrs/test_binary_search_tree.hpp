#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "binary_search_tree.hpp"
using namespace BST;

TEST(bst, insert_walk){
    BinarySearchTree<Node<int, int>> bst;
    for (auto i : {3, 1, 5, 0, 2, 4, 6}){
        bst.insert(new Node<int, int>(i));
    }
    EXPECT_NE(bst.root, nullptr);

    std::vector<int> X;
    auto display = [&](Node<int, int>* node){
        std::cout << node->key << ", ";
        X.push_back(node->key);
    };

    X.clear();
    bst.walk_inorder(bst.root, display);
    std::cout << std::endl;
    EXPECT_THAT(X, ::testing::ElementsAre(0, 1, 2, 3, 4, 5, 6));

    X.clear();
    bst.walk_preorder(bst.root, display);
    std::cout << std::endl;
    EXPECT_THAT(X, ::testing::ElementsAre(3, 1, 0, 2, 5, 4, 6));

    X.clear();
    bst.walk_postorder(bst.root, display);
    std::cout << std::endl;
    EXPECT_THAT(X, ::testing::ElementsAre(0, 2, 1, 4, 6, 5, 3));

    X.clear();
    bst.walk_queue(bst.root, display);
    std::cout << std::endl;
    EXPECT_THAT(X, ::testing::ElementsAre(3, 1, 5, 0, 2, 4, 6));
}

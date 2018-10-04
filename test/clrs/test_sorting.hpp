#pragma once
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "sorting.hpp"
using namespace sorting;

auto generate_data(int size=10){
    std::vector<Node<int, int>> X;
    for (int i = 0; i < size; ++i){
        X.push_back(Node<int, int>(rand()%100));
    }
    return X;
}

template<class T>
void display(const T& X){
    for (const auto& i : X){
        std::cout << i.key << ", ";
    }
    std::cout << std::endl;
}

template<class T>
void test_sort_function(void (*fun)(T&), T& X){
    auto Y = X;
    std::sort(Y.begin(), Y.end(), 
            [](const auto& x, const auto& y){
            return x.key < y.key;
            });
    fun(X);
    EXPECT_EQ(X.size(), Y.size());
    for (int i = 0; i < X.size(); ++i){
        EXPECT_EQ(X[i].key, Y[i].key);
    }
}

TEST(sorting, bubble_sort){
    for (int i = 0; i < 20; ++i){
        auto X{generate_data(i)};
        test_sort_function(bubble_sort, X);
    }
}

TEST(sorting, insertion_sort){
    for (int i = 0; i < 20; ++i){
        auto X{generate_data(i)};
        test_sort_function(insertion_sort, X);
    }
}

TEST(sorting, selection_sort){
    for (int i = 0; i < 20; ++i){
        auto X{generate_data(i)};
        test_sort_function(selection_sort, X);
    }
}

TEST(sorting, merge_sort){
    for (int i = 0; i < 20; ++i){
        auto X{generate_data(i)};
        test_sort_function(merge_sort, X);
    }
}

TEST(sorting, quick_sort){
    for (int i = 0; i < 20; ++i){
        auto X{generate_data(i)};
        test_sort_function(quick_sort, X);
    }
}


#pragma once
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <gtest/gtest.h>
#include "sorting.hpp"
using namespace std;

auto data(int size=10){
    vector<Node<int, int>> X;
    for (int i = 0 ; i < size; ++i)
        X.push_back(Node<int, int>(rand()%100));
    vector<Node<int, int>> Y{X};
    sort(Y.begin(), Y.end(), [](const auto& x, const auto& y){
            return x.key < y.key;
            });
    return make_tuple(X, Y);
}

TEST(sorting, bubble){
    vector<Node<int, int>> X, Y;
    tie(X, Y) = data(5);
    for (auto& i:Y)
        cout << i.key << ", ";
    cout << endl;
}

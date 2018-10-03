#pragma once

enum Color{
    WHITE,
    GRAY,
    BLACK,
};

template<typename K, typename V>
struct Node{
    Node(K key=0, V value=0){
        this->key = key;
        this->value = value;
    }
    K key;
    V value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    Node* prev = nullptr;
    Node* next = nullptr;
    Color color = Color::WHITE;
};

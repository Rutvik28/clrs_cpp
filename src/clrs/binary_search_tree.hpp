#pragma once
#include <deque>
#include "common.hpp"

namespace BST{
    template<class N>
    class BinarySearchTree{
    public:
        N* root = nullptr;
        void insert(N* node){
            if (root == nullptr){
                root = node;
                return;
            }
            _insert(root, node);
        }

        template<class F>
        void walk_inorder(N* node, F& fun){
            if (node == nullptr){
                return;
            }
            walk_inorder(node->left, fun);
            fun(node);
            walk_inorder(node->right, fun);
        }

        template<class F>
        void walk_preorder(N* node, F& fun){
            if (node == nullptr){
                return;
            }
            fun(node);
            walk_preorder(node->left, fun);
            walk_preorder(node->right, fun);
        }

        template<class F>
        void walk_postorder(N* node, F& fun){
            if (node == nullptr){
                return;
            }
            walk_postorder(node->left, fun);
            walk_postorder(node->right, fun);
            fun(node);
        }

        template<class F>
        void walk_queue(N* node, F& fun){
            std::deque<N*> queue_nodes;
            queue_nodes.push_back(node);
            _walk_queue(queue_nodes, fun);
        }

    private:
        void _insert(N* current_node, N* new_node){
            if (new_node->key < current_node->key){
                if (current_node->left == nullptr){
                    current_node->left = new_node;
                    new_node->parent = current_node;
                }
                else{
                    _insert(current_node->left, new_node);
                }
            }
            else{
                if (current_node->right == nullptr){
                    current_node->right = new_node;
                    new_node->parent = current_node;
                }
                else{
                    _insert(current_node->right, new_node);
                }
            }
        }

        template<class F>
        void _walk_queue(std::deque<N*>& queue_nodes, F& fun){
            std::deque<N*> new_queue_nodes;
            while (!queue_nodes.empty()){
                auto node = queue_nodes.front();
                queue_nodes.pop_front();
                fun(node);
                if (node->left != nullptr){
                    new_queue_nodes.push_back(node->left);
                }
                if (node->right != nullptr){
                    new_queue_nodes.push_back(node->right);
                }
            }
            if (!new_queue_nodes.empty()){
                _walk_queue(new_queue_nodes, fun);
            }
        }
    };
}

#pragma once
#include "common.hpp"

namespace sorting{
    template<class T>
    void bubble_sort(T& X){
        for (int i = 0; i < X.size(); ++i){
            for (int j = 1; j < X.size()-i; ++j){
                if (X[j-1].key > X[j].key){
                    std::swap(X[j-1], X[j]);
                }
            }
        }
    }

    template<class T>
    void insertion_sort(T& X){
        for (int i = 1; i < X.size(); ++i){
            for (int j = i; j > 0; --j){
                if (X[j-1].key > X[j].key){
                    std::swap(X[j-1], X[j]);
                }
            }
        }
    }

    template<class T>
    void selection_sort(T& X){
        for (int i = 0 ; i < X.size(); ++i){
            int smallest = i;
            for (int j = i; j < X.size(); ++j){
                if (X[j].key < X[smallest].key){
                    smallest = j;
                }
            }
            std::swap(X[i], X[smallest]);
        }
    }

    template<class T, class U>
    void _merge_sort(T& X, U left, U right){
        if (right - left < 2){
            return;
        }
        U middle = left + (right - left) / 2;
        _merge_sort(X, left, middle);
        _merge_sort(X, middle, right);
        T tmp;
        auto pleft = left;
        auto pright = middle;
        while (pleft < middle && pright < right){
            if (pleft->key <= pright->key){
                tmp.push_back(*pleft);
                pleft++;
            }
            else{
                tmp.push_back(*pright);
                pright++;
            }
        }
        if (pleft == middle){
            copy(pright, right, back_inserter(tmp));
        }
        else{
            copy(pleft, middle, back_inserter(tmp));
        }
        copy(tmp.begin(), tmp.end(), left);
    }

    template<class T>
    void merge_sort(T& X){
        _merge_sort(X, X.begin(), X.end());
    }

    template<class T, class U>
    void _quick_sort(T& X, U left, U right){
        U pivit = left;
        auto smaller = left;
        auto larger = left;
        while (true){
            for (; smaller < right; ++smaller){
                if (smaller->key < pivit->key){
                    break;
                }
            }
            for (; larger < right; ++larger){
                if (larger->key > pivit->key){
                    break;
                }
            }
            if (smaller <= larger){
                break;
            }
            std::swap(*smaller, *larger);
        }
        std::swap(*pivit, *smaller);
    }

    template<class T>
    void quick_sort(T& X){
    }
}


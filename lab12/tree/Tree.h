#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <vector>
#include <memory>
#include <math.h>
#include <utility>
#include <iostream>

namespace tree {

    template<class T>
    class Tree {
    public:
        Tree() : root_(nullptr) {};

        Tree(const T &val);

        std::unique_ptr<Tree<T>> Left() { return left_; }

        std::unique_ptr<Tree<T>> Right() { return right_; }

        int Size();

        int Depth();

        T Value();

        int max(int val_1, int val_2);

        void Insert(T value);

        Tree<T> *Root();

        T value;
    private:
        std::unique_ptr<Tree<T>> root_;
        std::unique_ptr<Tree<T>> left_;
        std::unique_ptr<Tree<T>> right_;
    };

    template<class T>
    Tree<T>::Tree(const T &val) {
        value = val;
        this->right_ = nullptr;
        this->left_ = nullptr;
        this->root_ = std::make_unique<Tree<T>>();
        root_->value = val;
    }


    template<class T>
    Tree<T> *Tree<T>::Root() {
        return this;
    }

    template<class T>
    int Tree<T>::Size() {
        if (left_ == nullptr)
            if (right_ == nullptr)
                return 1;
            else
                return 1 + this->right_->Size();
        else {
            if (right_ == nullptr)
                return 1 + this->left_->Size();
            else
                return (this->left_->Size() + this->right_->Size() + 1);
        }

    }

    template<class T>
    int Tree<T>::Depth() {
        if (left_ == nullptr)
            if (right_ == nullptr)
                return 1;
            else
                return 1 + this->right_->Depth();
        else {
            if (right_ == nullptr)
                return 1 + this->left_->Depth();
            else
                return 1 + max(this->left_->Depth(), this->right_->Depth());
        }

    }

    template<class T>
    int Tree<T>::max(int val_1, int val_2) {
        if (val_1 > val_2)
            return val_1;
        else
            return val_2;
    }

    template<class T>
    T Tree<T>::Value() {
        return value;
    }

    template<class T>
    void Tree<T>::Insert(T val) {
        Tree<T> *actualNode = Tree<T>::Root();
        std::unique_ptr<Tree<T>> NewValue = std::make_unique<Tree<T>>();
        while (true) {
            if (val < actualNode->value)
                if (actualNode->right_ == nullptr) {
                    actualNode->right_ = std::make_unique<Tree<T>>();
                    actualNode->right_->value = val;
                    break;
                } else
                    actualNode = actualNode->right_.get();
            else {
                if (actualNode->left_ == nullptr) {
                    actualNode->left_ = std::make_unique<Tree<T>>();
                    actualNode->left_->value = val;
                    break;
                } else
                    actualNode = actualNode->left_.get();
            }
        }


    }

}


#endif //JIMP_EXERCISES_TREE_H
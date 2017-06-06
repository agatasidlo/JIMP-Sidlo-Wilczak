#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include "../tree/Tree.h"
#include <vector>

namespace tree {

    template<class T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator() : root_(nullptr) {}

        InOrderTreeIterator(Tree<T> *tree);

        void Iteration(Tree<T> *tree);

        std::vector<T> GetValues() const;

        T operator++();

        T operator*() const;

        bool operator!=(const InOrderTreeIterator &i) const;

    private:
        std::vector<T> values_;
        Tree<T> *root_;
    };

    template<class T>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<T> *vertex);

        InOrderTreeIterator<T> begin();

        InOrderTreeIterator<T> end();

    private:
        Tree<T> *ptr_;
    };

    template<class T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Tree<T> *tree) {
        root_ = tree;
        Iteration(root_);
    }

    template<class T>
    void InOrderTreeIterator<T>::Iteration(Tree<T> *tree) {
        if (tree->right_.get())
            Iteration(tree->right_.get());
        values_.insert(values_.begin(), tree->value);
        if (tree->left_.get())
            Iteration(tree->left_.get());
    }

    template<class T>
    std::vector<T> InOrderTreeIterator<T>::GetValues() const {
        return values_;
    }

    template<class T>
    T InOrderTreeIterator<T>::operator++() {
        values_.pop_back();
    }

    template<class T>
    T InOrderTreeIterator<T>::operator*() const {
        return values_.back();
    }

    template<class T>
    bool InOrderTreeIterator<T>::operator!=(const InOrderTreeIterator &i) const {
        if (i.values_ != values_)
            return true;
        else
            return false;
    }

    template<class T>
    InOrderTreeView<T>::InOrderTreeView(Tree<T> *vertex) {
        ptr_ = vertex;
    }

    template<class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        return InOrderTreeIterator<T>(ptr_);

    }

    template<class T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        return InOrderTreeIterator<T>();
    }

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    }


    template<class T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator() : root_(nullptr) {}

        PreOrderTreeIterator(Tree<T> *tree);

        void Iteration(Tree<T> *tree);

        std::vector<T> GetValues() const;

        T operator++();

        T operator*() const;

        bool operator!=(const PreOrderTreeIterator &i) const;

    private:
        std::vector<T> values_;
        Tree<T> *root_;
    };

    template<class T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView(Tree<T> *vertex);

        PreOrderTreeIterator<T> begin();

        PreOrderTreeIterator<T> end();

    private:
        Tree<T> *ptr_;
    };

    template<class T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(Tree<T> *tree) {
        root_ = tree;
        Iteration(root_);
    }

    template<class T>
    void PreOrderTreeIterator<T>::Iteration(Tree<T> *tree) {
        values_.insert(values_.begin(), tree->value);
        if (tree->right_.get())
            Iteration(tree->right_.get());
        if (tree->left_.get())
            Iteration(tree->left_.get());
    }

    template<class T>
    std::vector<T> PreOrderTreeIterator<T>::GetValues() const {
        return values_;
    }

    template<class T>
    T PreOrderTreeIterator<T>::operator++() {
        values_.pop_back();
    }

    template<class T>
    T PreOrderTreeIterator<T>::operator*() const {
        return values_.back();
    }

    template<class T>
    bool PreOrderTreeIterator<T>::operator!=(const PreOrderTreeIterator &i) const {
        if (i.values_ != values_)
            return true;
        else
            return false;
    }

    template<class T>
    PreOrderTreeView<T>::PreOrderTreeView(Tree<T> *vertex) {
        ptr_ = vertex;
    }

    template<class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::begin() {
        return PreOrderTreeIterator<T>(ptr_);

    }

    template<class T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::end() {
        return PreOrderTreeIterator<T>();
    }

    template<class T>
    PreOrderTreeView<T> PreOrder(Tree<T> *tree) {
        return PreOrderTreeView<T>(tree);
    }


    template<class T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator() : root_(nullptr) {}

        PostOrderTreeIterator(Tree<T> *tree);

        void Iteration(Tree<T> *tree);

        std::vector<T> GetValues() const;

        T operator++();

        T operator*() const;

        bool operator!=(const PostOrderTreeIterator &i) const;

    private:
        std::vector<T> values_;
        Tree<T> *root_;
    };

    template<class T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView(Tree<T> *vertex);

        PostOrderTreeIterator<T> begin();

        PostOrderTreeIterator<T> end();

    private:
        Tree<T> *ptr_;
    };

    template<class T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(Tree<T> *tree) {
        root_ = tree;
        Iteration(root_);
    }

    template<class T>
    void PostOrderTreeIterator<T>::Iteration(Tree<T> *tree) {
        if (tree->right_.get())
            Iteration(tree->right_.get());
        if (tree->left_.get())
            Iteration(tree->left_.get());
        values_.insert(values_.begin(), tree->value);

    }

    template<class T>
    std::vector<T> PostOrderTreeIterator<T>::GetValues() const {
        return values_;
    }

    template<class T>
    T PostOrderTreeIterator<T>::operator++() {
        values_.pop_back();
    }

    template<class T>
    T PostOrderTreeIterator<T>::operator*() const {
        return values_.back();
    }

    template<class T>
    bool PostOrderTreeIterator<T>::operator!=(const PostOrderTreeIterator &i) const {
        if (i.values_ != values_)
            return true;
        else
            return false;
    }

    template<class T>
    PostOrderTreeView<T>::PostOrderTreeView(Tree<T> *vertex) {
        ptr_ = vertex;
    }

    template<class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        return PostOrderTreeIterator<T>(ptr_);

    }

    template<class T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        return PostOrderTreeIterator<T>();
    }

    template<class T>
    PostOrderTreeView<T> PostOrder(Tree<T> *tree) {
        return PostOrderTreeView<T>(tree);
    }


}

#endif //JIMP_EXERCISES_TREEITERATORS_H
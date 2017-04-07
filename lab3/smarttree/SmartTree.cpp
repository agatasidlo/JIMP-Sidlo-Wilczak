#include <ostream>
#include <sstream>
#include<string>
#include<iostream>
#include <memory>
#include <regex>
#include "SmartTree.h"

namespace datastructures {


    std::unique_ptr<SmartTree> CreateLeaf(int value) {

        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>(value);
        leaf->value = value;
        leaf->right = nullptr;
        leaf->left = nullptr;
        return leaf;
    }

    std::unique_ptr<SmartTree>
    InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left = std::move(left_subtree);
        return tree;
    }

    std::unique_ptr<SmartTree>
    InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right = std::move(right_subtree);
        return tree;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if (unique_ptr == nullptr)
            return;
        PrintTreeInOrder(unique_ptr->left, out);
        *out << unique_ptr->value << ", ";
        PrintTreeInOrder(unique_ptr->right, out);

    }

    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        std::stringstream dtree;
        if (tree != nullptr) {
            dtree << "[";
            std::string str = std::to_string(tree->value);
            dtree <<str;
            if (tree->left != nullptr) {
                dtree << " ";
                dtree << DumpTree(tree->left);
            } else {
                dtree << " ";
                dtree << "[none]";
            }
            if (tree->right != nullptr) {
                dtree << " ";
                dtree << DumpTree(tree->right);
            } else {
                dtree << " ";
                dtree << "[none]";
            }
            dtree << "]";
        }
        std::string result = dtree.str();
        return result;
    }

}

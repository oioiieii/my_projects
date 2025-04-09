#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

namespace CustomTrees {
    ref class TreeNode {
    public:
        int key;
        TreeNode^ left;  // Используем "^" для управляемых указателей
        TreeNode^ right;

        TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
    };

    
    // Класс для узла B дерева
    ref class BTreeNode {
    public:
        System::Collections::Generic::List<int>^ keys;  // Ключи узла
        System::Collections::Generic::List<BTreeNode^>^ children;  // Дочерние узлы (для внутренних узлов)
        bool isLeaf;  // Флаг, является ли узел листом

        // Конструктор для листового узла
        BTreeNode(bool leaf) {
            isLeaf = leaf;
            keys = gcnew System::Collections::Generic::List<int>();
            children = gcnew System::Collections::Generic::List<BTreeNode^>();
        }

        // Конструктор для внутреннего узла
        BTreeNode() {
            isLeaf = false;
            keys = gcnew System::Collections::Generic::List<int>();
            children = gcnew System::Collections::Generic::List<BTreeNode^>();
        }
    };

    ref class RBTreeNode {
    public:
        int key;
        RBTreeNode^ left;
        RBTreeNode^ right;
        RBTreeNode^ parent;
        bool isRed;  // true для красного, false для чёрного

        RBTreeNode(int key) {
            this->key = key;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
            isRed = true;  // Новый узел всегда красный
        }
    };

    ref class RBTree {
    public:
        RBTreeNode^ root;

    private:

        // Левый поворот
        void LeftRotate(RBTreeNode^ x) {
            RBTreeNode^ y = x->right;
            x->right = y->left;
            if (y->left != nullptr) {
                y->left->parent = x;
            }
            y->parent = x->parent;
            if (x->parent == nullptr) {
                root = y;
            }
            else if (x == x->parent->left) {
                x->parent->left = y;
            }
            else {
                x->parent->right = y;
            }
            y->left = x;
            x->parent = y;
        }

        // Правый поворот
        void RightRotate(RBTreeNode^ y) {
            RBTreeNode^ x = y->left;
            y->left = x->right;
            if (x->right != nullptr) {
                x->right->parent = y;
            }
            x->parent = y->parent;
            if (y->parent == nullptr) {
                root = x;
            }
            else if (y == y->parent->right) {
                y->parent->right = x;
            }
            else {
                y->parent->left = x;
            }
            x->right = y;
            y->parent = x;
        }

        // Восстановление свойств красно-чёрного дерева после вставки
        void FixInsert(RBTreeNode^ node) {
            while (node->parent != nullptr && node->parent->isRed) {
                if (node->parent == node->parent->parent->left) {
                    RBTreeNode^ uncle = node->parent->parent->right;
                    if (uncle != nullptr && uncle->isRed) {
                        node->parent->isRed = false;
                        uncle->isRed = false;
                        node->parent->parent->isRed = true;
                        node = node->parent->parent;
                    }
                    else {
                        if (node == node->parent->right) {
                            node = node->parent;
                            LeftRotate(node);
                        }
                        node->parent->isRed = false;
                        node->parent->parent->isRed = true;
                        RightRotate(node->parent->parent);
                    }
                }
                else {
                    RBTreeNode^ uncle = node->parent->parent->left;
                    if (uncle != nullptr && uncle->isRed) {
                        node->parent->isRed = false;
                        uncle->isRed = false;
                        node->parent->parent->isRed = true;
                        node = node->parent->parent;
                    }
                    else {
                        if (node == node->parent->left) {
                            node = node->parent;
                            RightRotate(node);
                        }
                        node->parent->isRed = false;
                        node->parent->parent->isRed = true;
                        LeftRotate(node->parent->parent);
                    }
                }
            }
            root->isRed = false;
        }

    public:
        RBTree() {
            root = nullptr;
        }

        void Insert(int key) {
            RBTreeNode^ newNode = gcnew RBTreeNode(key);
            if (root == nullptr) {
                root = newNode;
                root->isRed = false;  // Корень всегда чёрный
                return;
            }
            RBTreeNode^ current = root;
            RBTreeNode^ parent = nullptr;
            while (current != nullptr) {
                parent = current;
                if (key < current->key) {
                    current = current->left;
                }
                else {
                    current = current->right;
                }
            }
            newNode->parent = parent;
            if (key < parent->key) {
                parent->left = newNode;
            }
            else {
                parent->right = newNode;
            }
            FixInsert(newNode);
        }
    };

}


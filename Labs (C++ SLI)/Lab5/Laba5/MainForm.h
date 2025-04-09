#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include "sad.h"
#include "paint_area.h"


namespace Laba5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public Form {
    private:
        
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ panelForTreeView;
    private: System::Windows::Forms::TextBox^ outputTextBox;

    private: System::Windows::Forms::Label^ panelForBalanced;

    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;

    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ zaglushka;
    private: System::Windows::Forms::Label^ zaglushka1;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Button^ button7;





        CustomTrees::TreeNode ^ root = nullptr;

        // Задание 1: Генерация дерева
        void GenerateTree(int n, int minVal, int maxVal) {
            ClearTree(root);
            root = nullptr;
            Random^ rand = gcnew Random();

            for (int i = 0; i < n; i++) {
                int val = rand->Next(minVal, maxVal);
                root = InsertNodeRandom(root, val, rand);
            }

            area->Root = root;
        }

        CustomTrees::TreeNode^ InsertNodeRandom(CustomTrees::TreeNode^ node, int key, Random^ rand) {
            if (!node) return gcnew CustomTrees::TreeNode(key);

            // Случайно выбираем направление (влево или вправо)
            if (rand->Next(0, 2) == 0) {
                // Вставляем в левое поддерево
                node->left = InsertNodeRandom(node->left, key, rand);
            }
            else {
                // Вставляем в правое поддерево
                node->right = InsertNodeRandom(node->right, key, rand);
            }

            return node;
        }


        void ClearTree(CustomTrees::TreeNode^ node) {
            if (!node) return;
            ClearTree(node->left);
            ClearTree(node->right);
            delete node;
        }

        // Задача 2: Сумма всех элементов дерева
        int ComputeSum(CustomTrees::TreeNode^ node) {
            if (!node) return 0;
            return node->key + ComputeSum(node->left) + ComputeSum(node->right);
        }

        // Задача 3: Произведение элементов, кратных 3
        int ComputeProduct(CustomTrees::TreeNode^ node) {
            if (!node) return 1;
            int leftProduct = ComputeProduct(node->left);
            int rightProduct = ComputeProduct(node->right);
            int product = (node->key % 3 == 0) ? node->key : 1;
            return product * leftProduct * rightProduct;
        }

        // Функция для подсчета количества потомков (включая текущую вершину)
        int countDescendants(CustomTrees::TreeNode^ node) {
            if (node == nullptr) {
                return 0;
            }
            return 1 + countDescendants(node->left) + countDescendants(node->right);
        }

        // Функция для вычисления высоты поддерева
        int getHeight(CustomTrees::TreeNode^ node) {
            if (node == nullptr) {
                return 0;
            }
            return 1 + std::max(getHeight(node->left), getHeight(node->right));
        }

        // Задание 4: Найти вершины, у которых количество потомков в левом поддереве не равно количеству потомков в правом поддереве
        System::Collections::Generic::List<CustomTrees::TreeNode^> ^ findNodesWithDifferentDescendantCount(CustomTrees::TreeNode ^ node) {
            List<CustomTrees::TreeNode^>^ result = gcnew List<CustomTrees::TreeNode^>();
            if (node == nullptr) {
                return result;
            }

            // Подсчитываем количество потомков в левом и правом поддереве
            int leftDescendants = countDescendants(node->left);
            int rightDescendants = countDescendants(node->right);

            // Если количество потомков не равно, добавляем вершину в результат
            if (leftDescendants != rightDescendants) {
                result->Add(node);
            }

            // Рекурсивно проверяем левое и правое поддеревья
            List<CustomTrees::TreeNode^>^ leftResult = findNodesWithDifferentDescendantCount(node->left);
            List<CustomTrees::TreeNode^>^ rightResult = findNodesWithDifferentDescendantCount(node->right);

            // Добавляем найденные результаты из поддеревьев
            result->AddRange(leftResult);
            result->AddRange(rightResult);

            return result;
        }

        // Задание 5: Найти вершины, для которых высота левого поддерева не равна высоте правого поддерева
        List<CustomTrees::TreeNode^>^ findNodesWithDifferentSubtreeHeight(CustomTrees::TreeNode^ node) {
            List<CustomTrees::TreeNode^>^ result = gcnew List<CustomTrees::TreeNode^>();
            if (node == nullptr) {
                return result;
            }

            // Вычисляем высоту левого и правого поддерева
            int leftHeight = getHeight(node->left);
            int rightHeight = getHeight(node->right);

            // Если высоты не равны, добавляем вершину в результат
            if (leftHeight != rightHeight) {
                result->Add(node);
            }

            // Рекурсивно проверяем левое и правое поддеревья
            List<CustomTrees::TreeNode^>^ leftResult = findNodesWithDifferentSubtreeHeight(node->left);
            List<CustomTrees::TreeNode^>^ rightResult = findNodesWithDifferentSubtreeHeight(node->right);

            // Добавляем найденные результаты из поддеревьев
            result->AddRange(leftResult);
            result->AddRange(rightResult);

            return result;
        }



        // Задача 6: Определение числа вхождений элемента x
        int CountOccurrences(CustomTrees::TreeNode^ node, int x) {
            if (!node) return 0;
            int count = (node->key == x) ? 1 : 0;
            return count + CountOccurrences(node->left, x) + CountOccurrences(node->right, x);
        }

        // Задача 7: Максимальный элемент и количество его повторений
        void FindMaxAndCount(CustomTrees::TreeNode^ node, int& maxVal, int& count) {
            if (!node) return;
            if (node->key > maxVal) {
                maxVal = node->key;
                count = 1;
            }
            else if (node->key == maxVal) {
                count++;
            }
            FindMaxAndCount(node->left, maxVal, count);
            FindMaxAndCount(node->right, maxVal, count);
        }

        // Задача 8: Проверить наличие хотя бы двух одинаковых элементов
        bool HasDuplicate(CustomTrees::TreeNode^ node, std::unordered_map<int, int>& frequency) {
            if (!node) return false;
            int temp_key = node->key;
            frequency[temp_key]++;
            if (frequency[temp_key] > 1) return true;
            return HasDuplicate(node->left, frequency) || HasDuplicate(node->right, frequency);
        }

        bool HasDuplicates(CustomTrees::TreeNode^ root) {
            std::unordered_map<int, int> frequency;
            return HasDuplicate(root, frequency);
        }

        // Задача 9: Найти максимальное количество одинаковых элементов
        void CountFrequencies(CustomTrees::TreeNode^ node, std::unordered_map<int, int>& frequency) {
            if (!node) return;
            int temp_key = node->key;
            frequency[temp_key]++;
            CountFrequencies(node->left, frequency);
            CountFrequencies(node->right, frequency);
        }

        int FindMaxFrequency(CustomTrees::TreeNode^ root) {
            std::unordered_map<int, int> frequency;
            CountFrequencies(root, frequency);
            int maxFrequency = 0;
            for (auto pair : frequency) {
                if (pair.second > maxFrequency) {
                    maxFrequency = pair.second;
                }
            }
            return maxFrequency;
        }

        // Задача 10: Проверка симметрии дерева
        bool IsSymmetric(CustomTrees::TreeNode^ left, CustomTrees::TreeNode^ right) {
            if (!left && !right) return true;
            if (!left || !right) return false;
            return left->key == right->key && IsSymmetric(left->left, right->right) && IsSymmetric(left->right, right->left);
        }

        bool IsTreeSymmetric(CustomTrees::TreeNode^ node) {
            if (!node) return true;
            return IsSymmetric(node->left, node->right);
        }

      


        // Задача 11: Проверка на дерево поиска
        bool IsBSTUtil(CustomTrees::TreeNode^ node, int minVal, int maxVal) {
            if (!node) return true;
            if (node->key < minVal || node->key > maxVal) return false;
            return IsBSTUtil(node->left, minVal, node->key - 1) && IsBSTUtil(node->right, node->key + 1, maxVal);
        }

        bool IsBinarySearchTree(CustomTrees::TreeNode^ root) {
            return IsBSTUtil(root, INT_MIN, INT_MAX);
        }

        // Задача 12: Листья дерева в порядке возрастания
        void CollectLeaves(CustomTrees::TreeNode^ node, std::vector<int>& leaves) {
            if (!node) return;
            if (!node->left && !node->right) {
                leaves.push_back((int)node->key);
            }
            CollectLeaves(node->left, leaves);
            CollectLeaves(node->right, leaves);
        }

        std::vector<int> GetLeavesInOrder(CustomTrees::TreeNode^ root) {
            std::vector<int> leaves;
            CollectLeaves(root, leaves);
            std::sort(leaves.begin(), leaves.end());
            return leaves;
        }

        // Задача 13: Формирование сбалансированных деревьев из отрицательных и неотрицательных элементов
        void CollectNodes(CustomTrees::TreeNode^ node, std::vector<int>& negatives, std::vector<int>& nonNegatives) {
            if (!node) return;
            int temp = node->key;
            if (node->key < 0) negatives.push_back(temp);
            else nonNegatives.push_back(temp);
            CollectNodes(node->left, negatives, nonNegatives);
            CollectNodes(node->right, negatives, nonNegatives);
        }

        CustomTrees::TreeNode^ BuildBalancedTree(std::vector<int>& values, int start, int end) {
            if (start > end) return nullptr;
            int mid = (start + end) / 2;
            CustomTrees::TreeNode^ node = gcnew CustomTrees::TreeNode(values[mid]);
            node->left = BuildBalancedTree(values, start, mid - 1);
            node->right = BuildBalancedTree(values, mid + 1, end);
            return node;
        }

        Tuple<CustomTrees::TreeNode^, CustomTrees::TreeNode^>^ BuildBalancedTrees(CustomTrees::TreeNode^ root) {
            std::vector<int> negatives, nonNegatives;
            CollectNodes(root, negatives, nonNegatives);
            std::sort(negatives.begin(), negatives.end());
            std::sort(nonNegatives.begin(), nonNegatives.end());
            CustomTrees::TreeNode^ negativeTree = BuildBalancedTree(negatives, 0, negatives.size() - 1);
            CustomTrees::TreeNode^ nonNegativeTree = BuildBalancedTree(nonNegatives, 0, nonNegatives.size() - 1);
            return gcnew Tuple<CustomTrees::TreeNode^, CustomTrees::TreeNode^>(negativeTree, nonNegativeTree);
        }

        // Задача 14: Пути от корня к листьям с минимальной суммой
        void FindMinSumPaths(CustomTrees::TreeNode^ node, std::vector<int>& currentPath, int& minSum, std::vector<std::vector<int>>& minPaths, int currentSum) {
            if (!node) return;
            int temp = node->key;
            currentPath.push_back(temp);
            currentSum += node->key;

            if (!node->left && !node->right) {
                if (currentSum < minSum) {
                    minSum = currentSum;
                    minPaths.clear();
                    minPaths.push_back(currentPath);
                }
                else if (currentSum == minSum) {
                    minPaths.push_back(currentPath);
                }
            }
            else {
                FindMinSumPaths(node->left, currentPath, minSum, minPaths, currentSum);
                FindMinSumPaths(node->right, currentPath, minSum, minPaths, currentSum);
            }

            currentPath.pop_back();
        }

        std::vector<std::vector<int>> GetMinSumPaths(CustomTrees::TreeNode^ root) {
            std::vector<std::vector<int>> minPaths;
            std::vector<int> currentPath;
            int minSum = INT_MAX;
            FindMinSumPaths(root, currentPath, minSum, minPaths, 0);
            return minPaths;
        }

        // Задача 15: Последний уровень с положительными элементами
        void FindLastPositiveLevel(CustomTrees::TreeNode^ node, int level, int& lastLevel) {
            if (!node) return;
            if (node->key > 0) lastLevel = std::max(lastLevel, level);
            FindLastPositiveLevel(node->left, level + 1, lastLevel);
            FindLastPositiveLevel(node->right, level + 1, lastLevel);
        }

        int GetLastPositiveLevel(CustomTrees::TreeNode^ root) {
            int lastLevel = -1;
            FindLastPositiveLevel(root, 0, lastLevel);
            return lastLevel;
        }

        // Выполнение задач 11–15
        void RunTreeAnalysis() {
            outputTextBox->AppendText("Операции для задач 11–15:\r\n");

            
        }

        // Задача 16: На каждом уровне найти максимальный элемент
        void FindMaxPerLevel(CustomTrees::TreeNode^ node, int level, std::vector<int>& maxValues) {
            if (!node) return;
            if (level >= maxValues.size()) {
                maxValues.push_back((int)node->key);
            }
            else {
                int temp = node->key;
                maxValues[level] = std::max((int)maxValues[level], temp);
            }
            FindMaxPerLevel(node->left, level + 1, maxValues);
            FindMaxPerLevel(node->right, level + 1, maxValues);
        }

        std::vector<int> GetMaxPerLevel(CustomTrees::TreeNode^ root) {
            std::vector<int> maxValues;
            FindMaxPerLevel(root, 0, maxValues);
            return maxValues;
        }

        // Задача 17: Количество внутренних узлов и листьев на каждом уровне
        void CountNodesPerLevel(CustomTrees::TreeNode^ node, int level, std::vector<int>& internalCounts, std::vector<int>& leafCounts) {
            if (!node) return;
            if (level >= internalCounts.size()) {
                internalCounts.push_back(0);
                leafCounts.push_back(0);
            }

            if (!node->left && !node->right) {
                leafCounts[level]++;
            }
            else {
                internalCounts[level]++;
            }

            CountNodesPerLevel(node->left, level + 1, internalCounts, leafCounts);
            CountNodesPerLevel(node->right, level + 1, internalCounts, leafCounts);
        }

        std::pair<std::vector<int>, std::vector<int>> GetNodeCountsPerLevel(CustomTrees::TreeNode^ root) {
            std::vector<int> internalCounts, leafCounts;
            CountNodesPerLevel(root, 0, internalCounts, leafCounts);
            return { internalCounts, leafCounts };
        }

        // Задача 18: Суммы элементов на нечетных уровнях
        void SumOddLevels(CustomTrees::TreeNode^ node, int level, int& oddSum) {
            if (!node) return;
            if (level % 2 == 1) {
                oddSum += node->key;
            }
            SumOddLevels(node->left, level + 1, oddSum);
            SumOddLevels(node->right, level + 1, oddSum);
        }

        int GetSumOfOddLevels(CustomTrees::TreeNode^ root) {
            int oddSum = 0;
            SumOddLevels(root, 0, oddSum);
            return oddSum;
        }

        // Задача 19: Минимальный и максимальный путь между листьями
        void FindLeafPaths(CustomTrees::TreeNode^ node, int currentDepth, int& minDepth, int& maxDepth) {
            if (!node) return;
            if (!node->left && !node->right) {
                minDepth = std::min(minDepth, currentDepth);
                maxDepth = std::max(maxDepth, currentDepth);
            }
            FindLeafPaths(node->left, currentDepth + 1, minDepth, maxDepth);
            FindLeafPaths(node->right, currentDepth + 1, minDepth, maxDepth);
        }

        std::pair<int, int> GetMinMaxLeafPaths(CustomTrees::TreeNode^ root) {
            int minDepth = INT_MAX, maxDepth = 0;
            FindLeafPaths(root, 0, minDepth, maxDepth);
            return { minDepth, maxDepth };
        }

        // Задача 20: Удаление минимального количества вершин для строгого бинарного дерева
        CustomTrees::TreeNode^ MakeStrictlyBinary(CustomTrees::TreeNode^ node) {
            if (!node) return nullptr;

            node->left = MakeStrictlyBinary(node->left);
            node->right = MakeStrictlyBinary(node->right);

            if (!node->left && !node->right) return node;
            if (!node->left) return node->right;
            if (!node->right) return node->left;

            return node;
        }

        CustomTrees::TreeNode^ CopyTree(CustomTrees::TreeNode^ root) {
            if (root == nullptr) {
                return nullptr; // Если корень пуст, возвращаем nullptr
            }

            // Создаем новый узел с тем же значением ключа
            CustomTrees::TreeNode^ newRoot = gcnew CustomTrees::TreeNode(root->key);

            // Рекурсивно копируем левое и правое поддеревья
            newRoot->left = CopyTree(root->left);
            newRoot->right = CopyTree(root->right);

            return newRoot; // Возвращаем новый корень дерева
        }


        // Задача 21: Обходы дерева
        void InOrderTraversal(CustomTrees::TreeNode^ node, std::vector<int>& result) {
            if (!node) return;
            InOrderTraversal(node->left, result);
            result.push_back((int)node->key);
            InOrderTraversal(node->right, result);
        }

        void PostOrderTraversal(CustomTrees::TreeNode^ node, std::vector<int>& result) {
            if (!node) return;
            PostOrderTraversal(node->left, result);
            PostOrderTraversal(node->right, result);
            result.push_back((int)node->key);
        }

        void PreOrderTraversal(CustomTrees::TreeNode^ node, std::vector<int>& result) {
            if (!node) return;
            result.push_back((int)node->key);
            PreOrderTraversal(node->left, result);
            PreOrderTraversal(node->right, result);
        }

        // Задача 22: Преобразование в B+ дерево
        void SplitChild(CustomTrees::BTreeNode^ parent, int childIndex, int m) {
            CustomTrees::BTreeNode^ child = parent->children[childIndex];
            int medianIndex = m / 2;

            // Создаем новый узел для правой части
            CustomTrees::BTreeNode^ newChild = gcnew CustomTrees::BTreeNode(child->isLeaf);

            // Переносим половину ключей в новый узел
            for (int i = medianIndex + 1; i < child->keys->Count; i++) {
                newChild->keys->Add(child->keys[i]);
            }
            child->keys->RemoveRange(medianIndex + 1, child->keys->Count - medianIndex - 1);

            // Если это не лист, переносим соответствующие дочерние узлы
            if (!child->isLeaf) {
                for (int i = medianIndex + 1; i < child->children->Count; i++) {
                    newChild->children->Add(child->children[i]);
                }
                child->children->RemoveRange(medianIndex + 1, child->children->Count - medianIndex - 1);
            }

            // Добавляем новый узел к родителю
            parent->children->Insert(childIndex + 1, newChild);
            parent->keys->Insert(childIndex, child->keys[medianIndex]);
            child->keys->RemoveAt(medianIndex);
        }

        void InsertNonFull(CustomTrees::BTreeNode^ node, int key, int m) {
            int i = node->keys->Count - 1;

            if (node->isLeaf) {
                // Найти позицию для вставки ключа
                while (i >= 0 && key < node->keys[i]) {
                    i--;
                }
                node->keys->Insert(i + 1, key);
            }
            else {
                // Найти подузел для вставки
                while (i >= 0 && key < node->keys[i]) {
                    i--;
                }
                i++;

                // Если подузел полон, нужно его разделить
                if (node->children[i]->keys->Count == m) {
                    SplitChild(node, i, m);

                    // После разделения обновляем индекс
                    if (key > node->keys[i]) {
                        i++;
                    }
                }
                InsertNonFull(node->children[i], key, m);
            }
        }

        CustomTrees::BTreeNode^ Insert(CustomTrees::BTreeNode^ root, int key, int m) {
            // Если корень заполнен, создаем новый корень
            if (root->keys->Count == m) {
                CustomTrees::BTreeNode^ newRoot = gcnew CustomTrees::BTreeNode(false);
                newRoot->children->Add(root);
                SplitChild(newRoot, 0, m);
                InsertNonFull(newRoot, key, m);
                return newRoot;
            }
            else {
                InsertNonFull(root, key, m);
                return root;
            }
        }

        // Вспомогательная функция для генерации случайного числа в указанном диапазоне
        int GenerateRandomInRange(int min, int max) {
            if (min == max) return  -120 + rand()%(240);
            return min + rand() % (max - min);
        }

        // Метод для проверки и добавления недостающих ключей в узлы дерева
        void EnsureMinimumKeysInBTree(CustomTrees::BTreeNode^ node, int m, int minRange, int maxRange) {
            if (node == nullptr) return;

            // Если в текущем узле меньше m - 1 ключей, добавляем недостающие ключи
            while (node->keys->Count < m - 1) {
                int randomKey = GenerateRandomInRange(minRange, maxRange);
                node->keys->Add(randomKey);
                node->keys->Sort(); // Упорядочиваем ключи после добавления
            }

            // Обновляем диапазоны для потомков
            for (int i = 0; i <= node->children->Count - 1; i++) {
                int childMinRange = (i == 0) ? minRange : node->keys[i - 1] + 1;
                int childMaxRange = (i == node->keys->Count) ? maxRange : node->keys[i] - 1;
                EnsureMinimumKeysInBTree(node->children[i], m, childMinRange, childMaxRange);
            }
        }

        // Обертка для вызова функции проверки от корня
        void ValidateBTree(CustomTrees::BTreeNode^ root, int m) {
            srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел
            EnsureMinimumKeysInBTree(root, m, -120, 120);
        }

        CustomTrees::BTreeNode^ BuildBTree(System::Collections::Generic::List<int>^ values, int m) {
            if (m < 3) {
                throw gcnew System::ArgumentException("m должно быть >= 3");
            }

            CustomTrees::BTreeNode^ root = gcnew CustomTrees::BTreeNode(true); // Создаем пустой корень
            for each (int value in values) {
                root = Insert(root, value, m - 1);
            }
            ValidateBTree(root, m);
            return root;
        }

        List<int>^ convertToManagedList(const std::vector<int>& vec) {
            List<int>^ managedList = gcnew List<int>();
            for (int i = 0; i < vec.size(); ++i) {
                managedList->Add(vec[i]);
            }
            return managedList;
        }
       
        // Задача 23: Преобразование B+ дерева в красно-черное дерево
        void ConvertBTreeToRBTree(CustomTrees::BTreeNode^ bNode, CustomTrees::RBTree^ rbTree) {
            if (bNode == nullptr) {
                return;
            }
            for each (int key in bNode->keys) {
                rbTree->Insert(key);
            }
            for each (CustomTrees::BTreeNode ^ child in bNode->children) {
                ConvertBTreeToRBTree(child, rbTree);
            }
        }

    public:
        
        paint_area^ area;
        paint_area^ areaWithDeleted;
        paint_area^ areaBTree;
        paint_area^ areaRBTree;
        paint_area^ areaBalansedPos;
        paint_area^ areaBalansedNeg;

            
        MainForm() {
            InitializeComponent();

            //Панель для обычного дерева
            area = gcnew paint_area();
            area->Location = System::Drawing::Point(panelForTreeView->Location.X, panelForTreeView->Location.Y);
            area->Width = panelForTreeView->Width;
            area->Height = panelForTreeView->Height;
            area->BackColor = Color::White;
            panelForTreeView->BackColor = area->BackColor;
            area->maxHeightPanel = panelForTreeView->Height;
            area->maxWidthPanel = panelForTreeView->Width;
            area->parent = panelForTreeView;
            this->Controls->Add(area);
            
            area->BringToFront();
            
            areaWithDeleted = gcnew paint_area();
            areaWithDeleted->Location = System::Drawing::Point(panelForTreeView->Location.X, panelForTreeView->Location.Y);
            areaWithDeleted->Width = panelForTreeView->Width;
            areaWithDeleted->Height = panelForTreeView->Height;
            areaWithDeleted->BackColor = Color::White;
            panelForTreeView->BackColor = areaWithDeleted->BackColor;
            areaWithDeleted->maxHeightPanel = panelForTreeView->Height;
            areaWithDeleted->maxWidthPanel = panelForTreeView->Width;
            areaWithDeleted->parent = panelForTreeView;
            this->Controls->Add(areaWithDeleted);
            
            areaWithDeleted->BringToFront();


            //Панель для B+ дерева
            areaBTree = gcnew paint_area();
            areaBTree->Location = System::Drawing::Point(panelForTreeView->Location.X, panelForTreeView->Location.Y);
            areaBTree->Width = panelForTreeView->Width;
            areaBTree->Height = panelForTreeView->Height;
            areaBTree->BackColor = Color::White;
            //panelForTreeView->BackColor = areaBTree->BackColor;
            areaBTree->maxHeightPanel = panelForTreeView->Height;
            areaBTree->maxWidthPanel = panelForTreeView->Width;
            areaBTree->parent = panelForTreeView;
            this->Controls->Add(areaBTree);
            
            areaBTree->BringToFront();

            //Панель для RB дерева
            areaRBTree = gcnew paint_area();
            areaRBTree->Location = System::Drawing::Point(panelForTreeView->Location.X, panelForTreeView->Location.Y);
            areaRBTree->Width = panelForTreeView->Width;
            areaRBTree->Height = panelForTreeView->Height;
            areaRBTree->BackColor = Color::White;
            //panelForTreeView->BackColor = areaRBTree->BackColor;
            areaRBTree->maxHeightPanel = panelForTreeView->Height;
            areaRBTree->maxWidthPanel = panelForTreeView->Width;

            areaRBTree->parent = panelForTreeView;
            
            this->Controls->Add(areaRBTree);

            areaRBTree->BringToFront();

            areaBalansedPos = gcnew paint_area();
            areaBalansedPos->Location = System::Drawing::Point(panelForBalanced->Location.X, panelForBalanced->Location.Y);
            areaBalansedPos->Width = panelForBalanced->Width;
            areaBalansedPos->Height = panelForBalanced->Height;
            areaBalansedPos->BackColor = Color::White;
            panelForBalanced->BackColor = areaBalansedPos->BackColor;
            areaBalansedPos->maxHeightPanel = panelForBalanced->Height;
            areaBalansedPos->maxWidthPanel = panelForBalanced->Width;
            this->Controls->Add(areaBalansedPos);

            areaBalansedPos->BringToFront();
                       
            areaBalansedNeg = gcnew paint_area();
            areaBalansedNeg->Location = System::Drawing::Point(panelForBalanced->Location.X, panelForBalanced->Location.Y);
            areaBalansedNeg->Width = panelForBalanced->Width;
            areaBalansedNeg->Height = panelForBalanced->Height;
            areaBalansedNeg->BackColor = Color::White;
            panelForBalanced->BackColor = areaBalansedNeg->BackColor;
            areaBalansedNeg->maxHeightPanel = panelForBalanced->Height;
            areaBalansedNeg->maxWidthPanel = panelForBalanced->Width;
            this->Controls->Add(areaBalansedNeg);

            areaBalansedNeg->BringToFront();

            panelForTreeView->BackColor = Color::White;
            panelForTreeView->BackColor = Color::White;

            areaBalansedNeg->parent = panelForBalanced;
            areaBalansedPos->parent = panelForBalanced;

            zaglushka->BringToFront();
            zaglushka1->BringToFront();
            areaBTree->Hide();
            areaWithDeleted->Hide();
            areaRBTree->Hide();
            areaBalansedPos->Hide();
        }

        ~MainForm() {
            ClearTree(root);
        }


private: System::Void InitializeComponent() {
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->panelForTreeView = (gcnew System::Windows::Forms::Label());
    this->outputTextBox = (gcnew System::Windows::Forms::TextBox());
    this->panelForBalanced = (gcnew System::Windows::Forms::Label());
    this->button2 = (gcnew System::Windows::Forms::Button());
    this->button3 = (gcnew System::Windows::Forms::Button());
    this->button4 = (gcnew System::Windows::Forms::Button());
    this->button5 = (gcnew System::Windows::Forms::Button());
    this->button6 = (gcnew System::Windows::Forms::Button());
    this->label3 = (gcnew System::Windows::Forms::Label());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->zaglushka = (gcnew System::Windows::Forms::Label());
    this->zaglushka1 = (gcnew System::Windows::Forms::Label());
    this->label4 = (gcnew System::Windows::Forms::Label());
    this->button7 = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // button1
    // 
    this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button1->Location = System::Drawing::Point(85, 554);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(545, 94);
    this->button1->TabIndex = 0;
    this->button1->Text = L"ВЫЧИСЛИТЬ";
    this->button1->UseVisualStyleBackColor = true;
    this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
    // 
    // panelForTreeView
    // 
    this->panelForTreeView->BackColor = System::Drawing::SystemColors::ActiveCaption;
    this->panelForTreeView->Location = System::Drawing::Point(12, 72);
    this->panelForTreeView->Name = L"panelForTreeView";
    this->panelForTreeView->Size = System::Drawing::Size(1423, 402);
    this->panelForTreeView->TabIndex = 3;
    // 
    // outputTextBox
    // 
    this->outputTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->outputTextBox->Location = System::Drawing::Point(1441, 72);
    this->outputTextBox->Multiline = true;
    this->outputTextBox->Name = L"outputTextBox";
    this->outputTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->outputTextBox->Size = System::Drawing::Size(471, 954);
    this->outputTextBox->TabIndex = 4;
    // 
    // panelForBalanced
    // 
    this->panelForBalanced->BackColor = System::Drawing::SystemColors::ActiveCaption;
    this->panelForBalanced->Location = System::Drawing::Point(754, 554);
    this->panelForBalanced->Name = L"panelForBalanced";
    this->panelForBalanced->Size = System::Drawing::Size(681, 259);
    this->panelForBalanced->TabIndex = 6;
    // 
    // button2
    // 
    this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button2->Location = System::Drawing::Point(757, 905);
    this->button2->Name = L"button2";
    this->button2->Size = System::Drawing::Size(678, 49);
    this->button2->TabIndex = 7;
    this->button2->Text = L"Показать сбалансированное положительное дерево";
    this->button2->UseVisualStyleBackColor = true;
    this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
    // 
    // button3
    // 
    this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button3->Location = System::Drawing::Point(757, 837);
    this->button3->Name = L"button3";
    this->button3->Size = System::Drawing::Size(678, 56);
    this->button3->TabIndex = 8;
    this->button3->Text = L"Показать сбалансированное отрицательное дерево";
    this->button3->UseVisualStyleBackColor = true;
    this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
    // 
    // button4
    // 
    this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button4->Location = System::Drawing::Point(85, 822);
    this->button4->Name = L"button4";
    this->button4->Size = System::Drawing::Size(545, 63);
    this->button4->TabIndex = 10;
    this->button4->Text = L"Показать B дерево";
    this->button4->UseVisualStyleBackColor = true;
    this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
    // 
    // button5
    // 
    this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button5->Location = System::Drawing::Point(85, 664);
    this->button5->Name = L"button5";
    this->button5->Size = System::Drawing::Size(545, 73);
    this->button5->TabIndex = 11;
    this->button5->Text = L"Показать обычное дерево";
    this->button5->UseVisualStyleBackColor = true;
    this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
    // 
    // button6
    // 
    this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button6->Location = System::Drawing::Point(85, 891);
    this->button6->Name = L"button6";
    this->button6->Size = System::Drawing::Size(545, 68);
    this->button6->TabIndex = 12;
    this->button6->Text = L"Показать RB дерево";
    this->button6->UseVisualStyleBackColor = true;
    this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
    // 
    // label3
    // 
    this->label3->AutoSize = true;
    this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label3->Location = System::Drawing::Point(562, 26);
    this->label3->Name = L"label3";
    this->label3->Size = System::Drawing::Size(294, 24);
    this->label3->TabIndex = 18;
    this->label3->Text = L"ВИЗУАЛИЗАЦИЯ ДЕРЕВЬЕВ";
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label1->Location = System::Drawing::Point(1559, 26);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(247, 24);
    this->label1->TabIndex = 19;
    this->label1->Text = L"ВЫВОД РЕЗУЛЬТАТОВ:";
    // 
    // label2
    // 
    this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label2->Location = System::Drawing::Point(899, 501);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(398, 41);
    this->label2->TabIndex = 20;
    this->label2->Text = L"13 задание";
    this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // zaglushka
    // 
    this->zaglushka->BackColor = System::Drawing::Color::WhiteSmoke;
    this->zaglushka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->zaglushka->Location = System::Drawing::Point(12, 72);
    this->zaglushka->Name = L"zaglushka";
    this->zaglushka->Size = System::Drawing::Size(1423, 402);
    this->zaglushka->TabIndex = 21;
    this->zaglushka->Text = L"(место для дерева)";
    this->zaglushka->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // zaglushka1
    // 
    this->zaglushka1->BackColor = System::Drawing::Color::WhiteSmoke;
    this->zaglushka1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->zaglushka1->Location = System::Drawing::Point(752, 554);
    this->zaglushka1->Name = L"zaglushka1";
    this->zaglushka1->Size = System::Drawing::Size(683, 259);
    this->zaglushka1->TabIndex = 22;
    this->zaglushka1->Text = L"(место для дерева)";
    this->zaglushka1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // label4
    // 
    this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label4->Location = System::Drawing::Point(152, 501);
    this->label4->Name = L"label4";
    this->label4->Size = System::Drawing::Size(398, 41);
    this->label4->TabIndex = 23;
    this->label4->Text = L"ФУНКЦИОНАЛЬНЫЕ КНОПКИ";
    this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
    // 
    // button7
    // 
    this->button7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
    this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button7->Location = System::Drawing::Point(85, 743);
    this->button7->Name = L"button7";
    this->button7->Size = System::Drawing::Size(545, 73);
    this->button7->TabIndex = 24;
    this->button7->Text = L"Показать cтрого бинарное дерево";
    this->button7->UseVisualStyleBackColor = true;
    this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
    // 
    // MainForm
    // 
    this->BackColor = System::Drawing::Color::White;
    this->ClientSize = System::Drawing::Size(1924, 981);
    this->Controls->Add(this->button7);
    this->Controls->Add(this->label4);
    this->Controls->Add(this->zaglushka1);
    this->Controls->Add(this->zaglushka);
    this->Controls->Add(this->label2);
    this->Controls->Add(this->label1);
    this->Controls->Add(this->label3);
    this->Controls->Add(this->button6);
    this->Controls->Add(this->button5);
    this->Controls->Add(this->button4);
    this->Controls->Add(this->button3);
    this->Controls->Add(this->button2);
    this->Controls->Add(this->outputTextBox);
    this->Controls->Add(this->panelForTreeView);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->panelForBalanced);
    this->Name = L"MainForm";
    this->Text = L"Лабораторная работа №5";
    this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
    this->ResumeLayout(false);
    this->PerformLayout();

}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    zaglushka->Hide();
    zaglushka1->Hide();

    GenerateTree(30, -120, 120);

    outputTextBox->Clear();
    if (!root) {
        outputTextBox->AppendText("Дерево пустое.\r\n");
        return;
    }

    // Задание 2: Сумма всех элементов
    int sum = ComputeSum(root);
    outputTextBox->AppendText("2) Сумма элементов: " + sum.ToString() + "\r\n");

    // Задание 3: Произведение элементов, кратных 3
    int product = ComputeProduct(root);
    outputTextBox->AppendText("3) Произведение элементов кратных 3: " + product.ToString() + "\r\n");

    //Задание 4:
    List<CustomTrees::TreeNode^>^ nodesWithDifferentDescendantCount = findNodesWithDifferentDescendantCount(root);
    String^ nodesWithDifferentDescendantString = "";
    for each (CustomTrees::TreeNode ^ node in nodesWithDifferentDescendantCount) {
        nodesWithDifferentDescendantString += node->key.ToString() + " ";
    }
    outputTextBox->AppendText("4) Вершины, у которых количество потомков в левом поддереве не равно количеству потомков в правом поддереве: " + nodesWithDifferentDescendantString + "\r\n");

    //Задание 5:
    List<CustomTrees::TreeNode^>^ nodesWithDifferentSubtreeHeight = findNodesWithDifferentSubtreeHeight(root);
    String^ nodesWithDifferentSubtreeHeightString = "";
    for each (CustomTrees::TreeNode ^ node in nodesWithDifferentSubtreeHeight) {
        nodesWithDifferentSubtreeHeightString += node->key.ToString() + " ";
    }
    outputTextBox->AppendText("5) Вершины, для которых высота левого поддерева не равна высоте правого поддерева: " + nodesWithDifferentSubtreeHeightString + "\r\n");

    // Задача 6: Число вхождений элемента x
    int x = 8;
    int occurrences = CountOccurrences(root, x);
    outputTextBox->AppendText("6) Число вхождений элемента " + x.ToString() + ": " + occurrences.ToString() + "\r\n");
    
    // Задание 7: Максимальный элемент и количество его повторений
    int maxVal = INT_MIN, count = 0;
    FindMaxAndCount(root, maxVal, count);
    outputTextBox->AppendText("7) Максимальный элемент: " + maxVal.ToString() + "\r\n");
    outputTextBox->AppendText("   Количество повторений максимального элемента: " + count.ToString() + "\r\n");

    // Задача 8: Проверка на наличие дубликатов
    bool duplicates = HasDuplicates(root);
    outputTextBox->AppendText("8) Есть дубликаты: " + (duplicates ? "Да" : "Нет") + "\r\n");

    // Задача 9: Максимальное количество одинаковых элементов
    int maxFrequency = FindMaxFrequency(root);
    outputTextBox->AppendText("9) Максимальное количество одинаковых элементов: " + maxFrequency.ToString() + "\r\n");

    // Задание 10: Проверка симметрии дерева
    bool symmetric = IsTreeSymmetric(root);
    outputTextBox->AppendText("10) Дерево " + (symmetric ? "симметрично" : "не симметрично") + ".\r\n");

    // Задача 11: Проверка на дерево поиска
    bool isBST = IsBinarySearchTree(root);
    outputTextBox->AppendText("11) Дерево " + (isBST ? "является" : "не является") + " деревом поиска.\r\n");

    // Задача 12: Листья дерева в порядке возрастания
    auto leaves = GetLeavesInOrder(root);
    outputTextBox->AppendText("12) Листья в порядке возрастания: ");
    for (int leaf : leaves) {
        outputTextBox->AppendText(leaf.ToString() + " ");
    }
    outputTextBox->AppendText("\r\n");

    // Задача 13: Формирование сбалансированных деревьев
    auto balancedTrees = BuildBalancedTrees(root);
    outputTextBox->AppendText("13) Сбалансированные деревья созданы (отрицательные и неотрицательные).\r\n");
    areaBalansedNeg->Root = balancedTrees->Item1;
    areaBalansedPos->Root = balancedTrees->Item2;

    // Задача 14: Пути с минимальной суммой
    auto minSumPaths = GetMinSumPaths(root);
    outputTextBox->AppendText("14) Пути с минимальной суммой:\r\n");
    for (const auto& path : minSumPaths) {
        for (int node : path) {
            outputTextBox->AppendText(node.ToString() + " ");
        }
        outputTextBox->AppendText("\r\n");
    }

    // Задача 15: Последний уровень с положительными элементами
    int lastPositiveLevel = GetLastPositiveLevel(root);
    outputTextBox->AppendText("15) Последний уровень с положительными элементами: " + lastPositiveLevel.ToString() + "\r\n");

    // Задача 16: Максимальный элемент на каждом уровне
    auto maxPerLevel = GetMaxPerLevel(root);
    outputTextBox->AppendText("16) Максимальные элементы по уровням:\r\n");
    for (size_t i = 0; i < maxPerLevel.size(); i++) {
        outputTextBox->AppendText("Уровень " + i.ToString() + ": " + maxPerLevel[i].ToString() + "\r\n");
    }

    // Задача 17: Внутренние узлы и листья на уровнях
    auto temp_ans = GetNodeCountsPerLevel(root);
    auto internalCounts = temp_ans.first;
    auto leafCounts = temp_ans.second;
    outputTextBox->AppendText("17) Количество узлов по уровням:\r\n");
    for (size_t i = 0; i < internalCounts.size(); i++) {
        outputTextBox->AppendText("Уровень " + i.ToString() + ": Внутренние узлы = " + internalCounts[i].ToString() +
            ", Листья = " + leafCounts[i].ToString() + "\r\n");
    }

    // Задача 18: Сумма элементов на нечетных уровнях
    int oddLevelSum = GetSumOfOddLevels(root);
    outputTextBox->AppendText("18) Сумма элементов на нечетных уровнях: " + oddLevelSum.ToString() + "\r\n");

    // Задача 19: Минимальный и максимальный путь между листьями
    auto temp_ans1 = GetMinMaxLeafPaths(root);
    auto minPath = temp_ans1.first;
    auto maxPath = temp_ans1.second;
    outputTextBox->AppendText("19) Минимальный путь между листьями: " + minPath.ToString() + "\r\n");
    outputTextBox->AppendText("    Максимальный путь между листьями: " + maxPath.ToString() + "\r\n");

    // Задача 20: Удаление минимального количества вершин для строгого бинарного дерева
    outputTextBox->AppendText("20) Дерево преобразовано в строго бинарное.\r\n");
    area->Root = CopyTree(root);
    areaWithDeleted->Root = MakeStrictlyBinary(root);

    // Задача 21: Обходы дерева
    std::vector<int> inOrder, postOrder, preOrder;
    InOrderTraversal(root, inOrder);
    PostOrderTraversal(root, postOrder);
    PreOrderTraversal(root, preOrder);

    outputTextBox->AppendText("21) Обходы: \r\nИнфиксный обход: ");
    for (int key : inOrder) {
        outputTextBox->AppendText(key.ToString() + " ");
    }
    outputTextBox->AppendText("\r\n");

    outputTextBox->AppendText("Постфиксный обход: ");
    for (int key : postOrder) {
        outputTextBox->AppendText(key.ToString() + " ");
    }
    outputTextBox->AppendText("\r\n");

    outputTextBox->AppendText("Префиксный обход: ");
    for (int key : preOrder) {
        outputTextBox->AppendText(key.ToString() + " ");
    }
    outputTextBox->AppendText("\r\n");

    // Задача 22: Преобразование в  B+ дерево
    std::vector<int> allElements;
    InOrderTraversal(root, allElements);
    CustomTrees::BTreeNode^ bTreeRoot = BuildBTree(convertToManagedList(allElements), 4);
    outputTextBox->AppendText("22) B+ дерево построено.\r\n");
    areaBTree->Root = bTreeRoot;

    //// Задача 23: Преобразование B+ дерева в красно-черное дерево
    CustomTrees::RBTree^ rbTree = gcnew CustomTrees::RBTree();
    ConvertBTreeToRBTree(bTreeRoot, rbTree);
    outputTextBox->AppendText("23) RB дерево построено.\r\n");
    areaRBTree->Root = rbTree;
    
}
void HidePanels() {
    areaBalansedPos->Hide();
    areaBalansedNeg->Hide();
}

void HideMainPanels() {
    area->Hide();
    areaWithDeleted->Hide();
    areaBTree->Hide();
    areaRBTree->Hide();
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    //Все панели hide
    HidePanels();
    areaBalansedPos->Show();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    HidePanels();
    areaBalansedNeg->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    HideMainPanels();
    areaBTree->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    HideMainPanels();
    area->Show();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
    HideMainPanels();
    areaRBTree->Show();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
    HideMainPanels();
    areaWithDeleted->Show();
}
};
}

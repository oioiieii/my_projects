#pragma once

#include "sad.h"
#include <limits.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


ref class paint_area : public Panel
{
public:
    Label^ parent = nullptr;

    void correctCenter() {
        if (this->parent != nullptr) {
            // Получаем родительскую панель
            
                // Вычисляем центр по оси Y
                int parentCenterY = this->parent->Location.Y + this->parent->Height / 2;
                int newY = parentCenterY - this->Height / 2;

                // Устанавливаем новое местоположение панели
                this->Location = System::Drawing::Point(this->Location.X, newY);
        }
    }

    paint_area() : Panel()
    {
        this->DoubleBuffered = true; // Для уменьшения мерцания
        this->Font = gcnew System::Drawing::Font(this->Font->FontFamily, 14);
    }

    // Свойство для установки корня любого типа
    property Object^ Root
    {
        Object^ get() { return root; }
        void set(Object^ value)
        {
            root = value;
            AdjustSize();
            this->Invalidate(); // Запуск перерисовки
        }
    }

    int treeDepth;
    int maxWidthPanel = INT_MAX;
    int maxHeightPanel = INT_MAX;
    int nodeRadius = 23;

private:
    Object^ root; // Универсальный указатель на корень дерева

    // Пересчет размеров панели
    void AdjustSize()
    {
        if (root == nullptr)
        {
            this->Size = System::Drawing::Size(400, 300);
            return;
        }

        treeDepth = CalculateDepth(root);
        int vertSpasing = 50;
        int padding = 5;
        
        if (dynamic_cast<CustomTrees::BTreeNode^>(root) != nullptr) {
            vertSpasing += 20;
        }

        int countLastLevelNodes = Math::Pow(2, treeDepth);
        int minHeight = treeDepth * vertSpasing + padding;      // Высота: уровень * расстояние между уровнями

        if (minHeight > maxHeightPanel) minHeight = maxHeightPanel;

        this->Size = System::Drawing::Size(this->Width, minHeight);
        correctCenter();
    }

    // Расчет глубины дерева (универсальный метод)
    int CalculateDepth(Object^ node)
    {
        if (dynamic_cast<CustomTrees::RBTree^>(node) != nullptr) {
            node = ((CustomTrees::RBTree^)node)->root;
        }
        if (node == nullptr) return 0;

        if (dynamic_cast<CustomTrees::TreeNode^>(node) != nullptr)
        {
            auto tn = (CustomTrees::TreeNode^)node;
            return 1 + Math::Max(CalculateDepth(tn->left), CalculateDepth(tn->right));
        }
        else if (dynamic_cast<CustomTrees::RBTreeNode^>(node) != nullptr)
        {
            auto rn = (CustomTrees::RBTreeNode^)node;
            return 1 + Math::Max(CalculateDepth(rn->left), CalculateDepth(rn->right));
        }
        else if (dynamic_cast<CustomTrees::BTreeNode^>(node) != nullptr)
        {
            auto bpn = (CustomTrees::BTreeNode^)node;
            if (bpn->isLeaf) return 1;

            int maxDepth = 0;
            for each (auto child in bpn->children)
            {
                maxDepth = Math::Max(maxDepth, CalculateDepth(child));
            }
            return 1 + maxDepth;
        }

        return 0;
    }

public:
    // Переопределение метода OnPaint
    virtual void OnPaint(PaintEventArgs^ e) override
    {
        Panel::OnPaint(e);

        if (root != nullptr)
        {
            DrawTree(e->Graphics, root, this->Width / 2, 30, this->Width / 4, 50);
        }
    }
private:
    // Универсальный метод для рисования дерева
    void DrawTree(Graphics^ g, Object^ node, int x, int y, int offset, int verticalSpacing)
    {
        if (node == nullptr) return;

        if (dynamic_cast<CustomTrees::TreeNode^>(node) != nullptr)
        {
            auto tn = (CustomTrees::TreeNode^)node;
            DrawTreeNode(g, tn, x, y, offset, verticalSpacing);
        }
        else if (dynamic_cast<CustomTrees::RBTree^>(node) != nullptr)
        {
            auto rn = (CustomTrees::RBTree^)node;
            DrawRBNode(g, rn->root, x, y, offset, verticalSpacing);
        }
        else if (dynamic_cast<CustomTrees::BTreeNode^>(node) != nullptr)
        {
            auto bpn = (CustomTrees::BTreeNode^)node;
            //немного поменять offset
            DrawBTreeNode(g, bpn, 0, this->Width, y, verticalSpacing + 20);
        }
    }

    // Метод для рисования обычного узла дерева
    void DrawTreeNode(Graphics^ g, CustomTrees::TreeNode^ node, int x, int y, int offset, int verticalSpacing)
    {
        if (node == nullptr) return;

        // Рисуем узел
        DrawNodeCircle(g, x, y, node->key.ToString(), nullptr);

        // Левый потомок
        if (node->left != nullptr)
        {
            int childX = x - offset;
            int childY = y + verticalSpacing;
            g->DrawLine(gcnew Pen(Color::Black, 2), x, y + nodeRadius, childX, childY);
            DrawTreeNode(g, node->left, childX, childY, offset / 2, verticalSpacing);
        }

        // Правый потомок
        if (node->right != nullptr)
        {
            int childX = x + offset;
            int childY = y + verticalSpacing;
            g->DrawLine(gcnew Pen(Color::Black, 2), x, y + nodeRadius, childX, childY);
            DrawTreeNode(g, node->right, childX, childY, offset / 2, verticalSpacing);
        }
    }

    // Метод для рисования красно-черного узла
    void DrawRBNode(Graphics^ g, CustomTrees::RBTreeNode^ node, int x, int y, int offset, int verticalSpacing)
    {
        if (node == nullptr) return;

        // Рисуем узел
        DrawNodeCircle(g, x, y, node->key.ToString(), node->isRed ? Brushes::Red : Brushes::Black);

        // Левый потомок
        if (node->left != nullptr)
        {
            int childX = x - offset;
            int childY = y + verticalSpacing;
            g->DrawLine(gcnew Pen(Color::Black, 2), x, y + nodeRadius, childX, childY);
            DrawRBNode(g, node->left, childX, childY, offset / 2, verticalSpacing);
        }

        // Правый потомок
        if (node->right != nullptr)
        {
            int childX = x + offset;
            int childY = y + verticalSpacing;
            g->DrawLine(gcnew Pen(Color::Black, 2), x, y + nodeRadius, childX, childY);
            DrawRBNode(g, node->right, childX, childY, offset / 2, verticalSpacing);
        }
    }

    // Метод для рисования B+ узла
    void DrawBTreeNode(Graphics^ g, CustomTrees::BTreeNode^ node, int a, int b, int y, int verticalSpacing)
    {
        if (node == nullptr) return;

        // Находим середину текущей области [a, b]
        int x = a + (b - a) / 2;

        // Рисуем прямоугольник для ключей
        String^ keysStr = "";
        bool first = true;

        for each (auto it in node->keys) {
            if (!first) {
                keysStr += ", ";  // Добавляем разделитель перед каждым элементом, кроме первого
            }
            keysStr += System::Convert::ToString(it);
            first = false;
        }

        // Вычисляем размеры текста и прямоугольника
        SizeF textSize = g->MeasureString(keysStr, this->Font);
        Rectangle nodeRect(x - (int)textSize.Width / 2 - 5, y - nodeRadius, (int)textSize.Width + 10, nodeRadius * 2);

        // Рисуем прямоугольник и текст
        g->FillRectangle(Brushes::White, nodeRect);
        g->DrawRectangle(gcnew Pen(Color::Black, 2), nodeRect);
        g->DrawString(keysStr, this->Font, Brushes::Black, PointF(nodeRect.X + 5, nodeRect.Y + (nodeRect.Height - textSize.Height) / 2));

        // Обрабатываем потомков
        if (!node->isLeaf) {
            int numChildren = node->children->Count;
            int childWidth = (b - a) / numChildren; // Ширина области для каждого ребенка
            int childY = y + verticalSpacing;

            for (int i = 0; i < numChildren; i++) {
                int childA = a + i * childWidth;        // Левая граница области для ребенка
                int childB = childA + childWidth;      // Правая граница области для ребенка
                int childX = childA + (childB - childA) / 2; // Середина области ребенка

                // Соединяем линией текущий узел с ребенком
                g->DrawLine(gcnew Pen(Color::Black, 2), x, y + nodeRadius, childX, childY);

                // Рекурсивный вызов для ребенка
                DrawBTreeNode(g, node->children[i], childA, childB, childY, verticalSpacing);
            }
        }
    }
    // Вспомогательный метод для рисования круга узла
    void DrawNodeCircle(Graphics^ g, int x, int y, String^ text, Brush^ fill)
    {
        fill = fill == nullptr ? Brushes::White : fill;
        Rectangle nodeRect(x - nodeRadius, y - nodeRadius, nodeRadius * 2, nodeRadius * 2);
        g->FillEllipse(fill, nodeRect);
        g->DrawEllipse(gcnew Pen(Color::Black, 2), nodeRect);

        // Пишем текст
        SizeF textSize = g->MeasureString(text, this->Font);
        PointF textPos(x - textSize.Width / 2, y - textSize.Height / 2);
        g->DrawString(text, this->Font, fill == Brushes::Black ? Brushes::White : Brushes::Black, textPos);
    }
};

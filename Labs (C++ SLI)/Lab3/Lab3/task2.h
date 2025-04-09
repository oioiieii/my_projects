#pragma once
#include <climits>
#include <cstring>
#include <algorithm>
using namespace System;

class task2
{
private:
    static void rightShift(int*& array, int n, int indexStartShift, int newNum) {
        int* shiftArray = new int[n];
        //копируем все до
        for (int i = 0;  i < indexStartShift + 1; i++) {
            shiftArray[i] = array[i];
        }
        shiftArray[indexStartShift + 1] = newNum;
        for (int i = indexStartShift + 1; i < n - 1; i++) {
            shiftArray[i + 1] = array[i];
        }
        delete[] array;
        array = shiftArray;
    }
public: 
    //‘ункци€ восстановлени€ маршрута
    static void repairPath(int*& currentPath, int** paths, int n, int currentIndex) {

        System::Diagnostics::Debug::Write("\n");
        for (int j = 0; j < n; j++) {
            System::Diagnostics::Debug::Write(currentPath[j] + " ");
        }
        System::Diagnostics::Debug::Write("\n");

        //провер€ем переход влево
        if (paths[currentPath[currentIndex - 1] - 1][currentPath[currentIndex] - 1] != currentPath[currentIndex - 1]) {
            //сдвигаем массив вправо
            rightShift(currentPath, n, currentIndex - 1, paths[currentPath[currentIndex - 1] - 1][currentPath[currentIndex] - 1]);
            //добавл€ем то что там на самом деле в массив currentPath и вызываем рекурсию дл€ этой точки
            repairPath(currentPath, paths, n, currentIndex);
        }
        //провер€ем переход вправо
        if (paths[currentPath[currentIndex] - 1][currentPath[currentIndex + 1] - 1] != currentPath[currentIndex]) {
            //сдвигаем массив вправо на 1 элемент
            rightShift(currentPath, n, currentIndex, paths[currentPath[currentIndex] - 1][currentPath[currentIndex + 1] - 1]);
            //добавл€ем то что там на самом деле в массив currentPath и вызываем рекурсию дл€ этой точки
            repairPath(currentPath, paths, n, currentIndex + 1);
        }

    }
    

    // ‘ункци€ дл€ нахождени€ минимальной стоимости пути
    static int tsp(int** graph,int start, int* vertices, int n, int** paths, String^% currentPath) {
  
        // ѕеременна€ дл€ хранени€ минимальной длины пути
    int minPath = INT_MAX;

    // ѕеребор всех возможных перестановок
    do {
        // »нициализируем текущий путь
        int currentPathWeight = 0;


        // —читаем вес пути от начальной вершины к первой вершине из перестановки
        int k = start; // 0 заменить на старт
        for (int i = 0; i < n - 1; i++) {
            currentPathWeight += graph[k][vertices[i] - 1];

            k = vertices[i] - 1; // перемещаемс€ к следующей вершине
        }

        // ƒобавл€ем путь обратно в начальную вершину
        currentPathWeight += graph[k][start];

        // ќбновл€ем минимальный путь, если текущий меньше
        if (currentPathWeight < minPath) {
            minPath = currentPathWeight;
            currentPath = "";
            int N = 9;
            int k = start;
            for (int i = 0; i < n - 1; i++) {
                
                //¬осстанавливаем путь через рекурсию
                int* tecCurrentPath = new int[N];
                for (int i = 0; i < N; i++) {
                    tecCurrentPath[i] = 0;
                }
                if (paths[k][vertices[i] - 1] != k + 1) {
                    tecCurrentPath[0] = k + 1;
                    tecCurrentPath[1] = paths[k][vertices[i] -1];
                    tecCurrentPath[2] = vertices[i];

                    repairPath(tecCurrentPath, paths, N, 1);
                }
                else {
                    tecCurrentPath[0] = k + 1;
                    tecCurrentPath[1] = vertices[i];
                }
                
                //‘ормируем строку
                for (int i = 0; i < N - 1; i++) {
                    if (tecCurrentPath[i + 1] == 0) break;

                    currentPath += Convert::ToString(tecCurrentPath[i]) + " >> ";
                }

                

                k = vertices[i] - 1;
            }

            //ƒобавл€ем переход в конец
            int* tecCurrentPath = new int[N];
            for (int i = 0; i < N; i++) {
                tecCurrentPath[i] = 0;
            }
            if (paths[k][start] != k + 1) {
                tecCurrentPath[0] = k + 1;
                tecCurrentPath[1] = paths[k][start];
                tecCurrentPath[2] = start + 1;

                repairPath(tecCurrentPath, paths, N, 1);
            }
            else {
                tecCurrentPath[0] = k + 1;
                tecCurrentPath[1] = start + 1;
            }
            //‘ормируем строку
            for (int i = 0; i < N - 1; i++) {
                if (tecCurrentPath[i + 1] == 0) break;

                currentPath += Convert::ToString(tecCurrentPath[i]) + " >> ";
            }
            currentPath += Convert::ToString(start + 1);
        }

    } while (std::next_permutation(vertices, vertices + n - 1));

    delete[] vertices; // ќсвобождаем пам€ть

    return minPath;
}
};


#pragma once
#include <limits.h>
using namespace System::Diagnostics;

class FlowsInGraphs
{
public:	
	int** graphMatrix; //Матрица графа
	int n; //количество вершин
	int widthFlow = 0;
	
	int weightCut;
	int* Cut; //Множество S определяющее разрез
	int lenCut;

	FlowsInGraphs(int** graphMatrix, int n) {
		this->graphMatrix = graphMatrix;
		this->n = n;
	}

	//Берем произвольный путь если это возможно
	bool FindRandomPath() {
		int startNumVertex = 0; //Исток
		int endNumVertex = n - 1; //Cток

		int* tecPath = new int[n]; //Текущий путь, содержит номера вершин
		tecPath[0] = startNumVertex;
		int tecIndexTecPath = 0;

		int* passedVertex = new int[n]; //Пройденные вершины
		passedVertex[0] = startNumVertex;
		int tecIndexPassedVertex = 1;

		while (tecPath[tecIndexTecPath] != endNumVertex) {
			//Ищем вхождение
			int nextEntry = FindNextEntry(tecPath[tecIndexTecPath], passedVertex, tecPath);
			if (nextEntry == -1) {
				if (tecIndexTecPath == 0) return false; //Если мы не нашли вхождение и мы в начальной то выходим
				passedVertex[tecIndexPassedVertex++] = tecPath[tecIndexTecPath--];
			}
			else {
				tecPath[++tecIndexTecPath] = nextEntry;
			}
		}	
		
		//Обрабатываем 
		PathProcessing(tecPath, tecIndexTecPath + 1);

		//Удаляю массивы
		delete[] tecPath;
		delete[] passedVertex;

		return true;
	}

	void PathProcessing(int* tecPath, int lenPath) {
		int minBandWidth = INT_MAX; //Минимальная пропускная способность пути
		
		//Определяем минимальную пропускную способность
		for (int i = 0; i < lenPath - 1; i++) {
			if (graphMatrix[tecPath[i]][tecPath[i + 1]] < minBandWidth) minBandWidth = graphMatrix[tecPath[i]][tecPath[i + 1]];
		}

		//Преобразуем матрицу
		for (int i = 0; i < lenPath - 1; i++) {
			graphMatrix[tecPath[i]][tecPath[i + 1]] -= minBandWidth;
			graphMatrix[tecPath[i + 1]][tecPath[i]] += minBandWidth;
		}

		widthFlow += minBandWidth;
	}

	//Функция проверяющая, что мы еще не проходили эту вершину
	bool CheckVertex(int numVertex, int* passedVertex, int* tecPath) {
		for (int i = 0; i < n; i++) {
			if (passedVertex[i] == numVertex) return false;
		}
		for (int i = 0; i < n; i++) {
			if (tecPath[i] == numVertex) return false;
		}
		return true;
	}

	//Функция, находящая следующее вхождение
	int FindNextEntry(int tecNumVertex, int* passedVertex, int* tecPath) {
		for (int i = n - 1; i > 0; i--) {
			if (graphMatrix[tecNumVertex][i] != 0 && graphMatrix[tecNumVertex][i] != INT_MAX) {
				if (!CheckVertex(i, passedVertex, tecPath)) continue; //Проверяем что мы еще не были в этой вершине
				return i;
			}
		}
		return -1; //Не нашли дальнейше вхождение
	}

	void CalculateMaxFlow() {
		//Пока можем найти путь находим
		while (FindRandomPath());
		//Теперь находим разрез
		FindMinCut();
	}

	void FindMinCut() {
		int minWeightCut = INT_MAX;
		//Перебираем возможные варианты
		for (int i = 1; i < n - 1; i++) {
			int* vertices = new int[n];
			for (int j = 1; j < n - 1; j++) {
				vertices[j - 1] = j;
			}

			do {
				int* S = new int[i + 1];
				int* T = new int[n - i];
				
				S[0] = 0; //Исток
				T[n - i - 1] = n - 1; //Сток

				//Заполнение S
				for (int k = 0; k < i; k++) {
					S[k + 1] = vertices[k];
				}
				int tempIndex = 0;
				for (int m = 0; m < n; m++) {
					bool flag = true;
					for (int k = 0; k < i + 1; k++) {
						if (S[k] == m) {
							flag = false; break;
						}
					}
					if (!flag) continue;
					//Этого нет в T
					T[tempIndex++] = m;
				}


				int tecWeightCut = WeightСut(S, T, i + 1);
				
				if (tecWeightCut != -1 && tecWeightCut < minWeightCut) {
					minWeightCut = tecWeightCut;
					weightCut = 0;
					for (int I = 0; I < i + 1; I++) {
						for (int  J = 0; J < n - i - 1; J++) {
							if (graphMatrix[S[I]][T[J]] != INT_MAX) {
								weightCut += graphMatrix[T[J]][S[I]];
							}
						}
					}
					Cut = new int[i + 1];
					for (int k = 0; k < i + 1; k++) {
						Cut[k] = S[k];
					}
					lenCut = i + 1;
				}
				delete[] S;
				delete[] T;

			} while (NextSet(vertices, n - 2, i));
			
			delete[] vertices;
		}
		//weightCut = minWeightCut;
	}

	//Функция подсчитывающая вес разреза
	int WeightСut(int* S, int* T, int lenS) {
		int weightCut = 0;
		bool isNormalCut = false; //Следит за тем чтобы разрез проходил через рёбра
		for (int i = 0; i < lenS; i++) {
			for (int j = 0; j < n - lenS; j++) {
				if (graphMatrix[S[i]][T[j]] != INT_MAX) {
					isNormalCut = true;
					weightCut += graphMatrix[S[i]][T[j]];
				}
			}
		}
		if (isNormalCut) return weightCut;
		return -1; //Не является разрезом
	}

	//Функция генерирующая сочетания из N по M
	bool NextSet(int* a, int n, int m)
	{
		int k = m;
		for (int i = k - 1; i >= 0; --i)
			if (a[i] < n - k + i + 1)
			{
				++a[i];
				for (int j = i + 1; j < k; ++j)
					a[j] = a[j - 1] + 1;
				return true;
			}
		return false;
	}

};


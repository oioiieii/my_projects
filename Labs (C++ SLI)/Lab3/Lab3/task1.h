#pragma once

static class task1
{
public:
	/**
	* @brief Метод Дейкстры
	*
	* Нахождение минимальных путей методом Дейкстры
	*
	* @param n Количество вершин графа.
	* @param A Матрица смежности графа (матрица связей).
	* @param start Индекс начальной вершины.
	* @param iter Количестов произведенных итераций.
	*
	* @return Массив минимальных путей (из выбранной вершины в во все отсальные).
	*/
	static int* Dijkstra(int n, int** A, int start, int& iter) {
		bool* passed = new bool[n];
		int* minPaths = new int[n];
		int inf = 10000;

		for (int i = 0; i < n; i++) {
			minPaths[i] = inf;
			passed[i] = false;
		}
		minPaths[start] = 0;
		passed[start] = true;
		int tec = start;

		while (true) {
			//пересчет всех невыделенных точек
			//куда можно пойти из текущей
			for (int i = 0; i < n; i++) {
				if (A[tec][i] == 0) continue;
				int temp = A[tec][i] + minPaths[tec];
				if (passed[i] == false && temp < minPaths[i]) {
					minPaths[i] = temp;
				}
			}

			//Выбираем новую текущую вершину
			int min = inf;
			for (int i = 0; i < n; i++) {
				if (passed[i] == false && minPaths[i] < min) {
					min = minPaths[i];
					tec = i;
				}
			}

			passed[tec] = true;
			iter++;
			//Если мы отметили все вершины то выходим
			if (min == inf) {
				break;
			}
		}

		return minPaths;
	}

	/**
	* @brief Метод Флойда
	*
	* Нахождение минимальных путей методом Флойда
	*
	* @param n Количество вершин графа.
	* @param A Матрица смежности графа (матрица связей).
	* @param iter Количестов произведенных итераций.
	*
	* @return Двумерный массив минимальных путей (из любой вершины в во все отсальные).
	*/
	static int** Floyd(int n, int** A, int& iter) {
		int** A1 = new int* [n];

		for (int i = 0; i < n; i++) {
			A1[i] = new int[n];
			for (int j = 0; j < n; j++) {
				A1[i][j] = A[i][j];
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == k || j == k || i == j) continue;
					iter++;
					int temp = A1[i][k] + A1[k][j];
					if ((temp < A1[i][j] || A1[i][j] == 0) && temp != 0) {
						A1[i][j] = temp;
					}
				}
			}
		}
		return A1;
	}

	//Переопределение метода Флойда для ОЛИ
	static int** Floyd(int n, int** A, int** Paths) {
		int** A1 = new int* [n];

		for (int i = 0; i < n; i++) {
			A1[i] = new int[n];
			for (int j = 0; j < n; j++) {
				A1[i][j] = A[i][j];
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == k || j == k || i == j) continue;
					int temp = A1[i][k] + A1[k][j];
					if ((temp < A1[i][j] || A1[i][j] == 0) && A1[i][k]!=0 && A1[k][j] != 0) {
						A1[i][j] = temp;
						Paths[i][j] = k + 1;
					}
				}
			}
		}
		return A1;
	}
};


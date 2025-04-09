#pragma once
#include "limits.h"
#include <iostream>
#include <vector>

class AssignmentTask
{
public:
	int** mainMatrix; //Таблица олицетворяющая затраты
	int n = 0; //Количество вакансий
	int m = 0; //Количество сотрудников

	AssignmentTask(int** mainMatrix, int n, int m) {
		this->mainMatrix = mainMatrix;
		this->n = n;
		this->m = m;

		mainMatrixCopy = new int*[n];
		for (int i = 0; i < n; i++) {
			mainMatrixCopy[i] = new int[m];
			for (int j = 0; j < m; j++) {
				mainMatrixCopy[i][j] = mainMatrix[i][j];
			}
		}
		markedZeros = new std::pair<int, int>[m];
	}

	std::pair<int, int>* markedZeros; // По факту является ответом
	int countMarkedZeros = 0;
	
	bool findMin = true;
	int answerZ = 0;

	void CalculateTask() {
		//Сначала вычитаем
		SubtractMinElements();
		
		while (true) {
			//1 ШАГ - Помечаем нули
			countMarkedZeros = GetMarkedZeros();

			//Вывести в Debug mainMatrixCopy 
			for (int i = 0; i < n; i++) {
				String^ row = "";
				for (int j = 0; j < m; j++) {
					row += String::Format("{0,2} ", mainMatrixCopy[i][j].ToString()); // Форматируем каждый элемент с шириной 2
				}
				Debug::WriteLine(row); // Печатаем строку в консоль отладки
			}
			Debug::WriteLine("");

			String^ row = "";
			for (int j = 0; j < countMarkedZeros; j++) {
				row += String::Format("{0,2} ", markedZeros[j].first.ToString()); // Форматируем каждый элемент с шириной 2
			}
			Debug::WriteLine(row); // Печатаем строку в консоль отладки
			Debug::WriteLine("");
			if (countMarkedZeros == m) break; //Отмеченные нули и есть оптимальное решение


			//2 ШАГ - ПОИСК МИНИМАЛЬНОГО НАБОРА
			std::vector<int> markedRows;
			std::vector<int> markedColumns;
		
			FindMinimalSet(markedRows, markedColumns);

			row = "MarkedRows: ";
			for (int j = 0; j < markedRows.size(); j++) {
				row += String::Format("{0,2} ", markedRows[j].ToString()); // Форматируем каждый элемент с шириной 2
			}
			Debug::WriteLine(row); // Печатаем строку в консоль отладки
			Debug::WriteLine("");

			row = "MarkedColumns: ";
			for (int j = 0; j < markedColumns.size(); j++) {
				row += String::Format("{0,2} ", markedColumns[j].ToString()); // Форматируем каждый элемент с шириной 2
			}
			Debug::WriteLine(row); // Печатаем строку в консоль отладки
			Debug::WriteLine("");

			//3 ШАГ - ПОЛУЧЕНИЕ НОВОЙ МАТРИЦЫ
			ChangingMainMatrixCopy(markedRows, markedColumns);

			//Снимаем отметки
			delete[] markedZeros;
			markedZeros = new std::pair<int, int>[m];
			countMarkedZeros = 0;
		}

		//Подсчет целефой функции
		for (int i = 0; i < countMarkedZeros; i++) {
			answerZ += mainMatrix[markedZeros[i].first][markedZeros[i].second];
		}
		answerZ *= findMin ? 1 : -1;
	}

private:
	int** mainMatrixCopy; //Копия начальной матрицы

	void ChangingMainMatrixCopy(std::vector<int>& markedRows, std::vector<int>& markedColumns) {
		//Поис минимального элемента
		int minElement = INT_MAX;
		for (int i = 0; i < n; i++) {
			//Проверка строки
			bool badRow = false;
			for (int k = 0; k < markedRows.size(); k++) {
				if (markedRows[k] == i) {
					badRow = true;
					break;
				}
			}
			if (badRow) continue;

			for (int j = 0; j < m; j++) {
				//Проверка столбца
				bool badColumn = false;
				for (int k = 0; k < markedColumns.size(); k++) {
					if (markedColumns[k] == j) {
						badColumn = true;
						break;
					}
				}
				if (badColumn) continue;

				if (mainMatrixCopy[i][j] < minElement) {
					minElement = mainMatrixCopy[i][j];
				}
			}
		}

		//Вычитание из нотмеченных элементов минимального
		for (int i = 0; i < n; i++) {
			//Проверка строки
			bool badRow = false;
			for (int k = 0; k < markedRows.size(); k++) {
				if (markedRows[k] == i) {
					badRow = true;
					break;
				}
			}
			if (badRow) continue;

			for (int j = 0; j < m; j++) {
				//Проверка столбца
				bool badColumn = false;
				for (int k = 0; k < markedColumns.size(); k++) {
					if (markedColumns[k] == j) {
						badColumn = true;
						break;
					}
				}
				if (badColumn) continue;

				mainMatrixCopy[i][j] -= minElement;
			}
		}

		//Прибавление минимального к элементам на пересечении отмеченных строк и столбцов
		for (int i = 0; i < n; i++) {
			//Проверка строки
			bool badRow = true;
			for (int k = 0; k < markedRows.size(); k++) {
				if (markedRows[k] == i) {
					badRow = false;
					break;
				}
			}
			if (badRow) continue;

			for (int j = 0; j < m; j++) {
				//Проверка столбца
				bool badColumn = true;
				for (int k = 0; k < markedColumns.size(); k++) {
					if (markedColumns[k] == j) {
						badColumn = false;
						break;
					}
				}
				if (badColumn) continue;

				mainMatrixCopy[i][j] += minElement;
			}
		}
	}

	//Функция поиска минимального набора
	void FindMinimalSet(std::vector<int>& markedRows, std::vector<int>& markedColumns) {

		//Отмечаем строки в которы нет ни одного отмеченного нуля
		for (int i = 0; i < n; i++) {
			bool badRow = false;
			for (int j = 0; j < countMarkedZeros; j++) {
				if (markedZeros[j].first == i) {
					badRow = true;
					break;
				}
			}
			if (badRow) continue;
			markedRows.push_back(i);
		}

		//Отмечаем столбцы, содержащие перечеркнутый 0, хотя бы в одной из отмеченных строк
		for (int j = 0; j < m; j++) {
			for (int i = 0; i < n; i++) {
				bool badRow = true;
				for (int k = 0; k < markedRows.size(); k++) {
					if (markedRows[k] == i) {
						badRow = false;
						break;
					}
					else if (markedRows[k] > i) break;
				}
				if (badRow)continue;
				if (mainMatrixCopy[i][j] == 0) markedColumns.push_back(j);
			}
		}

		//Отмечаем все строки содержащие отмеченный 0 в отмеченных столбцах
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				bool badColumn = true;
				for (int k = 0; k < markedColumns.size(); k++) {
					if (markedColumns[k] == j) {
						badColumn = false;
						break;
					}
					else if (markedColumns[k] > j) break;
				}
				if (badColumn)continue;
				
				//Если это помеченный ноль то помечаем строку
				if (mainMatrixCopy[i][j] == 0) {
					for (int k = 0; k < countMarkedZeros; k++) {
						if (markedZeros[k].first == i && markedZeros[k].second == j) {
							markedRows.push_back(i);
							break;
						}
					}
				}
			}
		}

		//Инвертируем помеченные строки
		std::vector<int> invertMarkedRows;
		for (int i = 0; i < n; i++) {
			bool badRow = false;
			for (int k = 0; k < markedRows.size(); k++) {
				if (markedRows[k] == i) {
					badRow = true;
					break;
				}
			}
			if (badRow)continue;

			invertMarkedRows.push_back(i);
		}
		markedRows = invertMarkedRows;
	}

	//Функиця помечающая нули
	int GetMarkedZeros() {
		int countMarkedZeros = 0;

		while (true) {
			int minCounterZero = INT_MAX;
			int numMinRow = -1;

			for (int i = 0; i < n; i++) {
				bool badRow = false;
				int tecRowCounterZeros = 0;
				for (int j = 0; j < m; j++) {
					//Проверяем что эту строку или столбец еще не вычеркнули
					bool badColumn = false;
					for (int k = 0; k < countMarkedZeros; k++) {
						if (markedZeros[k].first == i) {
							badRow = true;
							break;
						}
						else if (markedZeros[k].second == j) {
							badColumn = true;
							break;
						}
					}
					if (badRow) break;
					else if (badColumn) continue;
					
					if (mainMatrixCopy[i][j] == 0) tecRowCounterZeros++;
				}
				if (tecRowCounterZeros != 0 && tecRowCounterZeros < minCounterZero) {
					minCounterZero = tecRowCounterZeros;
					numMinRow = i;
				}
			}
			if (numMinRow == -1) break;
			else {
				for (int j = 0; j < m; j++) {
					if (mainMatrixCopy[numMinRow][j] == 0) {
						bool badColumn = false;
						for (int k = 0; k < countMarkedZeros; k++) {
							if (markedZeros[k].second == j) {
								badColumn = true;
								break;
							}
						}
						if (badColumn) continue;
						markedZeros[countMarkedZeros++] = std::pair<int, int>(numMinRow, j);
						break;
					}
				}
			}
		}

		return countMarkedZeros;
	}

	//Функция вычитающая минимальные элементы
	void SubtractMinElements() {
		//Работаем со строками
		for (int i = 0; i < n; i++) {
			int minElementInRow = INT_MAX;
			for (int j = 0; j < m; j++) {
				if (mainMatrixCopy[i][j] < minElementInRow) minElementInRow = mainMatrixCopy[i][j];
			}

			for (int j = 0; j < m; j++) {
				mainMatrixCopy[i][j] -= minElementInRow;
			}
		}
		//Работаем со столбцами
		for (int i = 0; i < n; i++) {
			int minElementInRow = INT_MAX;
			for (int j = 0; j < m; j++) {
				if (mainMatrixCopy[j][i] < minElementInRow) minElementInRow = mainMatrixCopy[j][i];
			}

			for (int j = 0; j < m; j++) {
				mainMatrixCopy[j][i] -= minElementInRow;
			}
		}
	}
};


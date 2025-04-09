#pragma once
#include <omp.h>
#include <vector>
#include <chrono>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;
	using namespace chrono;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ txtMatrixSize;
	private: System::Windows::Forms::TextBox^ txtThreads;
	private: System::Windows::Forms::Button^ btnRun;


	private: System::Windows::Forms::DataGridView^ B_dataGrid;
	private: System::Windows::Forms::DataGridView^ C_dataGrid;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ A_dataGrid;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ results;







#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->txtMatrixSize = (gcnew System::Windows::Forms::TextBox());
			this->txtThreads = (gcnew System::Windows::Forms::TextBox());
			this->btnRun = (gcnew System::Windows::Forms::Button());
			this->B_dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->C_dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->A_dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->results = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_dataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_dataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_dataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// txtMatrixSize
			// 
			this->txtMatrixSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtMatrixSize->Location = System::Drawing::Point(419, 307);
			this->txtMatrixSize->Name = L"txtMatrixSize";
			this->txtMatrixSize->Size = System::Drawing::Size(100, 29);
			this->txtMatrixSize->TabIndex = 0;
			this->txtMatrixSize->Text = L"100";
			this->txtMatrixSize->TextChanged += gcnew System::EventHandler(this, &Form1::txtMatrixSize_TextChanged);
			// 
			// txtThreads
			// 
			this->txtThreads->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtThreads->Location = System::Drawing::Point(909, 312);
			this->txtThreads->Name = L"txtThreads";
			this->txtThreads->Size = System::Drawing::Size(100, 29);
			this->txtThreads->TabIndex = 0;
			this->txtThreads->Text = L"2";
			// 
			// btnRun
			// 
			this->btnRun->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRun->Location = System::Drawing::Point(238, 392);
			this->btnRun->Name = L"btnRun";
			this->btnRun->Size = System::Drawing::Size(309, 58);
			this->btnRun->TabIndex = 1;
			this->btnRun->Text = L"Решить вместе";
			this->btnRun->UseVisualStyleBackColor = true;
			this->btnRun->Click += gcnew System::EventHandler(this, &Form1::btnRun_Click);
			// 
			// B_dataGrid
			// 
			this->B_dataGrid->AllowUserToAddRows = false;
			this->B_dataGrid->AllowUserToDeleteRows = false;
			this->B_dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->B_dataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->B_dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->B_dataGrid->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->B_dataGrid->DefaultCellStyle = dataGridViewCellStyle1;
			this->B_dataGrid->Location = System::Drawing::Point(419, 83);
			this->B_dataGrid->Name = L"B_dataGrid";
			this->B_dataGrid->ReadOnly = true;
			this->B_dataGrid->RowHeadersVisible = false;
			this->B_dataGrid->Size = System::Drawing::Size(309, 144);
			this->B_dataGrid->TabIndex = 5;
			// 
			// C_dataGrid
			// 
			this->C_dataGrid->AllowUserToAddRows = false;
			this->C_dataGrid->AllowUserToDeleteRows = false;
			this->C_dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->C_dataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->C_dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->C_dataGrid->ColumnHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->C_dataGrid->DefaultCellStyle = dataGridViewCellStyle2;
			this->C_dataGrid->Location = System::Drawing::Point(875, 83);
			this->C_dataGrid->Name = L"C_dataGrid";
			this->C_dataGrid->ReadOnly = true;
			this->C_dataGrid->RowHeadersVisible = false;
			this->C_dataGrid->Size = System::Drawing::Size(309, 144);
			this->C_dataGrid->TabIndex = 6;
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(648, 392);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(309, 58);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Решить только многопоточный";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// A_dataGrid
			// 
			this->A_dataGrid->AllowUserToAddRows = false;
			this->A_dataGrid->AllowUserToDeleteRows = false;
			this->A_dataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->A_dataGrid->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->A_dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->A_dataGrid->ColumnHeadersVisible = false;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->A_dataGrid->DefaultCellStyle = dataGridViewCellStyle3;
			this->A_dataGrid->Location = System::Drawing::Point(55, 83);
			this->A_dataGrid->Name = L"A_dataGrid";
			this->A_dataGrid->ReadOnly = true;
			this->A_dataGrid->RowHeadersVisible = false;
			this->A_dataGrid->Size = System::Drawing::Size(309, 144);
			this->A_dataGrid->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(117, 307);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(283, 24);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Введите размерность матриц";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(429, 506);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(313, 24);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Сравнение скорости выполнения";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(139, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 24);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Матрица A";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(513, 46);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(106, 24);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Матрица B";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(608, 312);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(281, 24);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Введите количество потоков ";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(846, 46);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(362, 24);
			this->label6->TabIndex = 14;
			this->label6->Text = L"Результирующая матрица C = A x B - 11";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// results
			// 
			this->results->Location = System::Drawing::Point(143, 546);
			this->results->Multiline = true;
			this->results->Name = L"results";
			this->results->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->results->Size = System::Drawing::Size(903, 148);
			this->results->TabIndex = 15;
			this->results->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->checkBox1->Location = System::Drawing::Point(264, 349);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(669, 28);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"Выводить матрицы на форму\? (Рекомендуется отключить при N > 500)";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->ClientSize = System::Drawing::Size(1256, 787);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->results);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->A_dataGrid);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->C_dataGrid);
			this->Controls->Add(this->B_dataGrid);
			this->Controls->Add(this->btnRun);
			this->Controls->Add(this->txtThreads);
			this->Controls->Add(this->txtMatrixSize);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Name = L"Form1";
			this->Text = L"Лабораторная работа №8";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_dataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_dataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_dataGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Функция умножения матриц (последовательная)
		void MultiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
			int rows = A.size();
			int cols = B[0].size();
			int inner = A[0].size();

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					C[i][j] = 0;
					for (int k = 0; k < inner; k++) {
						C[i][j] += A[i][k] * B[k][j];
					}
					C[i][j] -= 11;
				}
			}
		}

		// Функция умножения матриц (параллельная)
		void MultiplyMatricesParallel(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int threads) {
			int rows = A.size();
			int cols = B[0].size();
			int inner = A[0].size();

			#pragma omp parallel for shared(A, B, C) num_threads(threads)
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					C[i][j] = 0;
					for (int k = 0; k < inner; k++) {
						C[i][j] += A[i][k] * B[k][j];
					}
					C[i][j] -= 11;
				}
			}
		}

		void FillMatrixRandomly(vector<vector<int>>& matrix, int minVal, int maxVal) {
			int rows = matrix.size();
			int cols = matrix[0].size();
			for (int i = 0; i < rows; ++i) {
				for (int j = 0; j < cols; ++j) {
					matrix[i][j] = minVal + (rand() % (maxVal - minVal + 1));
				}
			}
		}


		void DisplayVectorInDataGridView(const vector<vector<int>>& vector2D, DataGridView^ dataGridView) {
			if (!checkBox1->Checked) return;

			dataGridView->Rows->Clear(); // Очистка DataGridView перед выводом
			dataGridView->Columns->Clear(); // Очистка колонок

			// Создание колонок в DataGridView
			for (int i = 0; i < vector2D[0].size(); ++i) {
				DataGridViewTextBoxColumn^ column = gcnew DataGridViewTextBoxColumn();
				column->FillWeight = 1;
				column->MinimumWidth = 55;
				dataGridView->Columns->Add(column);
			}

			int heightRow = vector2D.size() <= 5 ? dataGridView->Height / vector2D.size() : -1;
			dataGridView->ScrollBars = ScrollBars::Both;
			if (heightRow != -1) dataGridView->ScrollBars = ScrollBars::Horizontal;
			// Заполнение DataGridView строками из вектора
			for (int i = 0; i < vector2D.size(); ++i) {
				DataGridViewRow^ row = gcnew DataGridViewRow(); // Создание новой строки в DataGridView
				row->CreateCells(dataGridView); // Создание ячеек в строке

				for (int j = 0; j < vector2D[i].size(); ++j) {
					row->Cells[j]->Value = vector2D[i][j]; // Установка значения ячейки
				}
				if(heightRow != -1) row->MinimumHeight = heightRow;
				dataGridView->Rows->Add(row); // Добавление строки в DataGridView
			}
		}

		vector<vector<int>>* A;
		vector<vector<int>>* B;
		vector<vector<int>>* C;

		// Обработчик нажатия кнопки
		void btnRun_Click(System::Object^ sender, System::EventArgs^ e) {
			button1->Enabled = true;
			results->Text = "";
			A_dataGrid->Columns->Clear();
			B_dataGrid->Columns->Clear();
			C_dataGrid->Columns->Clear();

			int size = Int32::Parse(txtMatrixSize->Text); // Размер матрицы
			int threads = Int32::Parse(txtThreads->Text); // Количество потоков

			A = new vector<vector<int>>(size, vector<int>(size));
			B = new vector<vector<int>>(size, vector<int>(size));
			C = new vector<vector<int>>(size, vector<int>(size, 0));

			FillMatrixRandomly(*A, -10, 10);
			FillMatrixRandomly(*B, -10, 10);

			DisplayVectorInDataGridView(*A, A_dataGrid);
			DisplayVectorInDataGridView(*B, B_dataGrid);

			// Последовательное выполнение
			auto startSeq = omp_get_wtime();
			MultiplyMatrices(*A, *B, *C);
			auto endSeq = omp_get_wtime();
			auto durationSeq = endSeq - startSeq;

			// Параллельное выполнение
			
			auto startPar = omp_get_wtime();
			MultiplyMatricesParallel(*A, *B, *C, threads);
			auto endPar = omp_get_wtime();
			auto durationPar = endPar - startPar;
			// Вывод результатов
			results->AppendText("Последовательное выполнение: " + Math::Round(durationSeq, 3).ToString() + " секунд" + "\r\n");
			results->AppendText("Параллельное выполнение задания (" + threads.ToString() + " потоков): " + Math::Round(durationPar, 3).ToString() + " секунд ");
		
			DisplayVectorInDataGridView(*C, C_dataGrid);
		}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	int threads = Int32::Parse(txtThreads->Text); // Количество потоков

	auto startPar = omp_get_wtime();
	MultiplyMatricesParallel(*A, *B, *C, threads);
	auto endPar = omp_get_wtime();
	auto durationPar = endPar - startPar;

	results->AppendText("\r\n" + "Параллельное выполнение задания (" + threads.ToString() + " потоков) : " + Math::Round(durationPar, 3).ToString() + " секунд ");
}
private: System::Void txtMatrixSize_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	button1->Enabled = false;
	results->Text = "";
	A_dataGrid->Columns->Clear();
	B_dataGrid->Columns->Clear();
	C_dataGrid->Columns->Clear();
	if (Convert::ToInt32(txtMatrixSize->Text) > 500) {
		checkBox1->Checked = false;
	}
	else {
		checkBox1->Checked = true;
	}
}
};
}

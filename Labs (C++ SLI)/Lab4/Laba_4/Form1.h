#pragma once
#include "FlowsInGraphs.h"
#include "AssignmentTask.h"
#include <vector>
#include <sstream>

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			CreateTable(dataGridView2, 2, 16 * 2 + 1);
			int valuesX[32] = { 1,2,1,4,2,3,2,4,2,6,3,6,4,5,4,7,4,8,5,2,5,8,6,5,6,8,6,9,7,8,8,9 };
			int valuesS[16] = { 25, 14, 23, 19, 16, 15, 4, 22, 28, 6, 26, 24, 27, 18, 14, 18 };
			// Заполнение DataGridView значениями
			int k_temp = 0;
			
			dataGridView2->Rows[0]->Cells[0]->Value = "Дуга";
			dataGridView2->Rows[1]->Cells[0]->Value = "Вес";
			
			for (int i = 0; i < 32; i++)
			{
				
				dataGridView2->Rows[0]->Cells[i + 1]->Value = valuesX[i];
				if (i % 2 == 0) dataGridView2->Rows[1]->Cells[i + 1]->Value = valuesS[k_temp++];
				else {
					dataGridView2->Rows[1]->Cells[i + 1]->Value = "";
				}
			}



			CreateTable(dataGridView1, 5, 5);
			
			
			int values11[5][5] = {
				{27, 25, 20, 19, 21},
				{19, 13, 12, 20, 16},
				{26, 19, 10, 22, 25},
				{10, 14, 10, 8, 12},
				{14, 15, 18, 19, 13}
			};

			// Заполнение DataGridView значениями
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					dataGridView1->Rows[i]->Cells[j]->Value = values11[i][j];
				}
			}

			

			//
			//TODO: Add the constructor code here
			//
			int n = 8;
			int** graphMatrix = new int* [n];
			for (int i = 0; i < n; i++) {
				graphMatrix[i] = new int[n];
			}

			// Заполнение массива значениями
			int values[8][8] = {
				{0, 32, 95, 75, 57, INT_MAX, INT_MAX, INT_MAX},
				{0, 0, 5, INT_MAX, 23, INT_MAX, INT_MAX, 16},
				{0, 0, 0, 18, INT_MAX, 6, INT_MAX, INT_MAX},
				{0, INT_MAX, 0, 0, 24, 9, INT_MAX, INT_MAX},
				{0, 0, 0, 0, INT_MAX, 0, 20, 94},
				{INT_MAX, INT_MAX, 0, 0, 11, 0, 7, INT_MAX},
				{INT_MAX, INT_MAX, INT_MAX, 0, 0, 0, 0, 81},
				{INT_MAX, 0, INT_MAX, INT_MAX, 0, INT_MAX, 0, 0}
			};
			/*int  values[4][4] = {
				{0, 1, 1, 0},
				{0, 0, 1, 1},
				{0, 0, 0, 1},
				{0, 0, 0, 0},
				
			};*/

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					graphMatrix[i][j] = values[i][j];
				}
			}

			


			//Для 2 задания
			n = 5;
			int** mainMatrix = new int* [n];
			for (int i = 0; i < n; i++) {
				mainMatrix[i] = new int[n];
			}

			// Заполнение массива значениями
			int values1[5][5] = {
				{27, 25, 20, 19, 21},
				{19, 13, 12, 20, 16},
				{26,19 ,10 ,22 ,25 },
				{10, 14, 10, 8,12 },
				{14, 15, 18, 19, 13},
			};

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					mainMatrix[i][j] = -1 * values1[i][j];
				}
			}
			
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
	private: System::Windows::Forms::Label^ label3;
	protected:


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ task1_panel;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ lbl_iter2;
	private: System::Windows::Forms::Label^ lbl_iter1;
	private: System::Windows::Forms::Label^ label7;


private: System::Windows::Forms::MaskedTextBox^ txt_n;










	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::MaskedTextBox^ txt_n_arc;






private: System::Windows::Forms::Label^ label1;

private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ txt_ans_maxFlow;
private: System::Windows::Forms::Label^ txt_ans_minCut;
private: System::Windows::Forms::Panel^ task2_panel;
private: System::Windows::Forms::Label^ txt_ans_optim;

private: System::Windows::Forms::Label^ label10;










private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Label^ label20;

private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Button^ button4;

private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::DataGridView^ dataGridView1;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::CheckBox^ checkBox1;
private: System::Windows::Forms::DataGridView^ dataGridView2;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label12;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::Label^ label5;





















	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->task1_panel = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->txt_ans_minCut = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_ans_maxFlow = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_n_arc = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->lbl_iter2 = (gcnew System::Windows::Forms::Label());
			this->lbl_iter1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txt_n = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->task2_panel = (gcnew System::Windows::Forms::Panel());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txt_ans_optim = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->task1_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->task2_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(289, 81);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(230, 24);
			this->label3->TabIndex = 17;
			this->label3->Text = L"НАЧАЛЬНЫЕ ДАННЫЕ";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(42, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(341, 48);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Задание 1";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(407, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(331, 48);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Задание 2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// task1_panel
			// 
			this->task1_panel->Controls->Add(this->dataGridView2);
			this->task1_panel->Controls->Add(this->txt_ans_minCut);
			this->task1_panel->Controls->Add(this->label6);
			this->task1_panel->Controls->Add(this->txt_ans_maxFlow);
			this->task1_panel->Controls->Add(this->label1);
			this->task1_panel->Controls->Add(this->label2);
			this->task1_panel->Controls->Add(this->txt_n_arc);
			this->task1_panel->Controls->Add(this->label14);
			this->task1_panel->Controls->Add(this->lbl_iter2);
			this->task1_panel->Controls->Add(this->lbl_iter1);
			this->task1_panel->Controls->Add(this->label7);
			this->task1_panel->Controls->Add(this->txt_n);
			this->task1_panel->Controls->Add(this->label4);
			this->task1_panel->Controls->Add(this->button1);
			this->task1_panel->Location = System::Drawing::Point(41, 128);
			this->task1_panel->Name = L"task1_panel";
			this->task1_panel->Size = System::Drawing::Size(696, 569);
			this->task1_panel->TabIndex = 20;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->ColumnHeadersVisible = false;
			this->dataGridView2->Location = System::Drawing::Point(55, 186);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->Size = System::Drawing::Size(612, 100);
			this->dataGridView2->TabIndex = 32;
			this->dataGridView2->CellPainting += gcnew System::Windows::Forms::DataGridViewCellPaintingEventHandler(this, &Form1::dataGridView2_CellPainting);
			// 
			// txt_ans_minCut
			// 
			this->txt_ans_minCut->AutoSize = true;
			this->txt_ans_minCut->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txt_ans_minCut->Location = System::Drawing::Point(443, 433);
			this->txt_ans_minCut->Name = L"txt_ans_minCut";
			this->txt_ans_minCut->Size = System::Drawing::Size(20, 24);
			this->txt_ans_minCut->TabIndex = 28;
			this->txt_ans_minCut->Text = L"\?";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(47, 433);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(374, 24);
			this->label6->TabIndex = 26;
			this->label6->Text = L"Соответствующий минимальный разрез";
			// 
			// txt_ans_maxFlow
			// 
			this->txt_ans_maxFlow->AutoSize = true;
			this->txt_ans_maxFlow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txt_ans_maxFlow->Location = System::Drawing::Point(439, 386);
			this->txt_ans_maxFlow->Name = L"txt_ans_maxFlow";
			this->txt_ans_maxFlow->Size = System::Drawing::Size(20, 24);
			this->txt_ans_maxFlow->TabIndex = 25;
			this->txt_ans_maxFlow->Text = L"\?";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(214, 386);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(207, 24);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Максимальный поток ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(253, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 24);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Кол-во дуг";
			// 
			// txt_n_arc
			// 
			this->txt_n_arc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->txt_n_arc->Location = System::Drawing::Point(365, 131);
			this->txt_n_arc->Mask = L"00";
			this->txt_n_arc->Name = L"txt_n_arc";
			this->txt_n_arc->Size = System::Drawing::Size(70, 29);
			this->txt_n_arc->TabIndex = 18;
			this->txt_n_arc->Text = L"16";
			this->txt_n_arc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_n_arc->ValidatingType = System::Int32::typeid;
			this->txt_n_arc->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox2_MaskInputRejected);
			this->txt_n_arc->TextChanged += gcnew System::EventHandler(this, &Form1::maskedTextBox2_TextChanged);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(154, 82);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(393, 24);
			this->label14->TabIndex = 16;
			this->label14->Text = L"Введите дуги, связывающих вершины:";
			// 
			// lbl_iter2
			// 
			this->lbl_iter2->AutoSize = true;
			this->lbl_iter2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_iter2->Location = System::Drawing::Point(231, 433);
			this->lbl_iter2->Name = L"lbl_iter2";
			this->lbl_iter2->Size = System::Drawing::Size(0, 24);
			this->lbl_iter2->TabIndex = 15;
			// 
			// lbl_iter1
			// 
			this->lbl_iter1->AutoSize = true;
			this->lbl_iter1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_iter1->Location = System::Drawing::Point(231, 386);
			this->lbl_iter1->Name = L"lbl_iter1";
			this->lbl_iter1->Size = System::Drawing::Size(0, 24);
			this->lbl_iter1->TabIndex = 14;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(286, 338);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(149, 24);
			this->label7->TabIndex = 13;
			this->label7->Text = L"РЕЗУЛЬТАТЫ";
			// 
			// txt_n
			// 
			this->txt_n->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->txt_n->Location = System::Drawing::Point(468, 20);
			this->txt_n->Mask = L"0";
			this->txt_n->Name = L"txt_n";
			this->txt_n->Size = System::Drawing::Size(70, 29);
			this->txt_n->TabIndex = 7;
			this->txt_n->Text = L"9";
			this->txt_n->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_n->ValidatingType = System::Int32::typeid;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(164, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(271, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Введите количество вершин";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button1->Location = System::Drawing::Point(86, 482);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(540, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// task2_panel
			// 
			this->task2_panel->Controls->Add(this->label30);
			this->task2_panel->Controls->Add(this->label29);
			this->task2_panel->Controls->Add(this->label28);
			this->task2_panel->Controls->Add(this->label27);
			this->task2_panel->Controls->Add(this->label26);
			this->task2_panel->Controls->Add(this->label25);
			this->task2_panel->Controls->Add(this->label24);
			this->task2_panel->Controls->Add(this->label23);
			this->task2_panel->Controls->Add(this->label22);
			this->task2_panel->Controls->Add(this->label17);
			this->task2_panel->Controls->Add(this->label16);
			this->task2_panel->Controls->Add(this->label15);
			this->task2_panel->Controls->Add(this->label12);
			this->task2_panel->Controls->Add(this->label11);
			this->task2_panel->Controls->Add(this->label9);
			this->task2_panel->Controls->Add(this->label8);
			this->task2_panel->Controls->Add(this->label5);
			this->task2_panel->Controls->Add(this->checkBox1);
			this->task2_panel->Controls->Add(this->textBox2);
			this->task2_panel->Controls->Add(this->textBox1);
			this->task2_panel->Controls->Add(this->dataGridView1);
			this->task2_panel->Controls->Add(this->label13);
			this->task2_panel->Controls->Add(this->txt_ans_optim);
			this->task2_panel->Controls->Add(this->label10);
			this->task2_panel->Controls->Add(this->label18);
			this->task2_panel->Controls->Add(this->label19);
			this->task2_panel->Controls->Add(this->label20);
			this->task2_panel->Controls->Add(this->label21);
			this->task2_panel->Controls->Add(this->button4);
			this->task2_panel->Location = System::Drawing::Point(41, 128);
			this->task2_panel->Name = L"task2_panel";
			this->task2_panel->Size = System::Drawing::Size(696, 569);
			this->task2_panel->TabIndex = 21;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label30->Location = System::Drawing::Point(361, 132);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(23, 24);
			this->label30->TabIndex = 51;
			this->label30->Text = L"И";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label29->Location = System::Drawing::Point(334, 132);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(22, 24);
			this->label29->TabIndex = 50;
			this->label29->Text = L"Л";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label28->Location = System::Drawing::Point(305, 132);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(23, 24);
			this->label28->TabIndex = 49;
			this->label28->Text = L"Е";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label27->Location = System::Drawing::Point(277, 132);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(22, 24);
			this->label27->TabIndex = 48;
			this->label27->Text = L"Т";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label26->Location = System::Drawing::Point(248, 132);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(23, 24);
			this->label26->TabIndex = 47;
			this->label26->Text = L"И";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label25->Location = System::Drawing::Point(219, 132);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(23, 24);
			this->label25->TabIndex = 46;
			this->label25->Text = L"Н";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label24->Location = System::Drawing::Point(191, 132);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(22, 24);
			this->label24->TabIndex = 45;
			this->label24->Text = L"Л";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label23->Location = System::Drawing::Point(160, 132);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(25, 24);
			this->label23->TabIndex = 44;
			this->label23->Text = L"О";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label22->Location = System::Drawing::Point(131, 132);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(23, 24);
			this->label22->TabIndex = 43;
			this->label22->Text = L"П";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label17->Location = System::Drawing::Point(102, 132);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(23, 24);
			this->label17->TabIndex = 42;
			this->label17->Text = L"С";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label16->Location = System::Drawing::Point(22, 324);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(23, 24);
			this->label16->TabIndex = 41;
			this->label16->Text = L"А";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(22, 297);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(22, 24);
			this->label15->TabIndex = 40;
			this->label15->Text = L"Т";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(21, 266);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(25, 24);
			this->label12->TabIndex = 39;
			this->label12->Text = L"О";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(21, 238);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 24);
			this->label11->TabIndex = 38;
			this->label11->Text = L"Б";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(21, 209);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(23, 24);
			this->label9->TabIndex = 37;
			this->label9->Text = L"А";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(22, 178);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(22, 24);
			this->label8->TabIndex = 36;
			this->label8->Text = L"Р";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(73, 132);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 24);
			this->label5->TabIndex = 35;
			this->label5->Text = L"И";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->checkBox1->Location = System::Drawing::Point(115, 82);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(495, 28);
			this->checkBox1->TabIndex = 34;
			this->checkBox1->Text = L"Решать матрицу стоимостей (переключение задач)\r\n";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox1_CheckedChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->textBox2->Location = System::Drawing::Point(616, 23);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(51, 29);
			this->textBox2->TabIndex = 33;
			this->textBox2->Text = L"5";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->textBox1->Location = System::Drawing::Point(307, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(51, 29);
			this->textBox1->TabIndex = 32;
			this->textBox1->Text = L"5";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(51, 159);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(588, 203);
			this->dataGridView1->TabIndex = 31;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(365, 23);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(245, 24);
			this->label13->TabIndex = 29;
			this->label13->Text = L", количесвто сотрудников";
			// 
			// txt_ans_optim
			// 
			this->txt_ans_optim->AutoSize = true;
			this->txt_ans_optim->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txt_ans_optim->Location = System::Drawing::Point(443, 423);
			this->txt_ans_optim->Name = L"txt_ans_optim";
			this->txt_ans_optim->Size = System::Drawing::Size(20, 24);
			this->txt_ans_optim->TabIndex = 28;
			this->txt_ans_optim->Text = L"\?";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(211, 423);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(224, 24);
			this->label10->TabIndex = 26;
			this->label10->Text = L"Оптимальное значение";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label18->Location = System::Drawing::Point(231, 433);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(0, 24);
			this->label18->TabIndex = 15;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label19->Location = System::Drawing::Point(231, 386);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(0, 24);
			this->label19->TabIndex = 14;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label20->Location = System::Drawing::Point(286, 386);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(149, 24);
			this->label20->TabIndex = 13;
			this->label20->Text = L"РЕЗУЛЬТАТЫ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label21->Location = System::Drawing::Point(16, 20);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(285, 24);
			this->label21->TabIndex = 6;
			this->label21->Text = L"Введите количество вакансий";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button4->Location = System::Drawing::Point(86, 482);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(540, 57);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Решить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(780, 710);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->task2_panel);
			this->Controls->Add(this->task1_panel);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная работа №4";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->task1_panel->ResumeLayout(false);
			this->task1_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->task2_panel->ResumeLayout(false);
			this->task2_panel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void maskedTextBox2_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {
		
	}
private: System::Void maskedTextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
	int n = Convert::ToInt32(((MaskedTextBox^)sender)->Text);
	
	std::vector <int> tableDataFirstLane;
	std::vector <int> tableDataSecondLane;

	// Перебираем строки и столбцы DataGridView и сохраняем значения
	int k = 0;
	for (int j = 1; j < dataGridView2->ColumnCount; j++)
	{
		tableDataFirstLane.push_back(dataGridView2->Rows[0]->Cells[j]->Value->ToString() != "" ?
			Convert::ToInt32(dataGridView2->Rows[0]->Cells[j]->Value) : 0);
		if (j % 2 == 1) {
			tableDataSecondLane.push_back(dataGridView2->Rows[1]->Cells[j]->Value->ToString() != "" ?
				Convert::ToInt32(dataGridView2->Rows[1]->Cells[j]->Value) : 0);
			k++;
		}
	}

	CreateTable(dataGridView2, 2, n * 2 + 1);

	dataGridView2->Rows[0]->Cells[0]->Value = "Дуга";
	dataGridView2->Rows[1]->Cells[0]->Value = "Вес";

	k = 0;
	for (int j = 1; j < dataGridView2->ColumnCount; j++)
	{
		// Проверка, есть ли данные для текущей ячейки в сохраненном массиве
		if (j < tableDataFirstLane.size() + 1)
		{
			dataGridView2->Rows[0]->Cells[j]->Value = tableDataFirstLane[j - 1];
			if (j % 2 == 1) {
				dataGridView2->Rows[1]->Cells[j]->Value = tableDataSecondLane[k];
				k++;
			}
			else {
				dataGridView2->Rows[1]->Cells[j]->Value = "";
			}
		}
		else {
			dataGridView2->Rows[0]->Cells[j]->Value = "";
			dataGridView2->Rows[1]->Cells[j]->Value = "";
		}
	}
	
}

private: System::Void txt_definitionArc_MaskInputRejected(System::Object^ sender, System::Windows::Forms::MaskInputRejectedEventArgs^ e) {

}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = Convert::ToInt32(txt_n->Text);
		int n_arc = Convert::ToInt32(txt_n_arc->Text);

		int** graphMatrix = new int* [n];
		for (int i = 0; i < n; i++) {
			graphMatrix[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bool flag = true;
				if (graphMatrix[i][j] != 0) {
					for (int k = 1; k < n_arc * 2 + 1; k += 2) {
						if (Convert::ToInt32(dataGridView2->Rows[0]->Cells[k]->Value) == i + 1 && Convert::ToInt32(dataGridView2->Rows[0]->Cells[k + 1]->Value) == j + 1) {
							graphMatrix[i][j] = Convert::ToInt32(dataGridView2->Rows[1]->Cells[k]->Value);
							graphMatrix[j][i] = 0;
							flag = false;
							break;
						}

					}
					if (flag) {
						graphMatrix[i][j] = INT_MAX;
					}
				}
			}
		}

		//Вывести матрицу
		for (int i = 0; i < n; i++) {
			String^ row = "";
			for (int j = 0; j < n; j++) {
				row += graphMatrix[i][j] == INT_MAX ? "inf" : String::Format("{0,3} ", graphMatrix[i][j].ToString()); // Форматируем каждый элемент с шириной 2
			}
			Debug::WriteLine(row); // Печатаем строку в консоль отладки
		}
		Debug::WriteLine("");

		FlowsInGraphs flowsInGraphs(graphMatrix, n);
		flowsInGraphs.CalculateMaxFlow();
		String^ cut = "{";
		for (int i = 0; i < flowsInGraphs.lenCut; i++) {
			cut += (i < flowsInGraphs.lenCut - 1) ? flowsInGraphs.Cut[i].ToString() + ", " : flowsInGraphs.Cut[i].ToString();
		}
		cut += "} (" + flowsInGraphs.weightCut.ToString() + ")";

		txt_ans_maxFlow->Text = flowsInGraphs.widthFlow.ToString();
		txt_ans_minCut->Text = cut;
	}
	
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	((Button^)sender)->BackColor = Color::CornflowerBlue;
	((Button^)sender)->ForeColor = Color::White;
	button3->BackColor = Color::White;
	button3->ForeColor = Color::Black;

	task1_panel->Show();
	task2_panel->Hide();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	((Button^)sender)->BackColor = Color::CornflowerBlue;
	((Button^)sender)->ForeColor = Color::White;
	button2->BackColor = Color::White;
	button2->ForeColor = Color::Black;

	task2_panel->Show();
	task1_panel->Hide();
}

	   int n_table = 5;
	   int m_table = 5;

	   void CreateTable(DataGridView^ dataGridView, int n_table, int m_table)
	   {
		   // Очищаем DataGridView от предыдущих столбцов и строк
		   dataGridView->Columns->Clear();
		   dataGridView->Rows->Clear();

		   // Устанавливаем шрифт для всего DataGridView
		   dataGridView->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 12);  // Шрифт 12, можно выбрать другой шрифт

		   // Устанавливаем выравнивание текста в ячейках по центру
		   dataGridView->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;


		   // Добавляем m столбцов
		   for (int i = 0; i < m_table; i++)
		   {
			   dataGridView->Columns->Add("Column" + i, "Column " + (i + 1)); // Названия столбцов могут быть изменены по вашему усмотрению
		   }

		   // Добавляем n строк
		   for (int i = 0; i < n_table; i++)
		   {
			   dataGridView->Rows->Add(); // Создаем пустую строку
		   }
		   // Устанавливаем минимальную ширину для столбцов
		   for each (DataGridViewColumn^ column in dataGridView->Columns)
		   {
			   column->MinimumWidth = 50; // Минимальная ширина столбца
		   }

		   for each(DataGridViewRow^ row in dataGridView->Rows)
		   {
			   row->MinimumHeight = 40; // Минимальная высота строки
		   }

		   // Устанавливаем режим автоматического изменения размера столбцов
		   dataGridView->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;

		   // Устанавливаем режим автоматического изменения размера строк
		   dataGridView->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

		   // Запрещаем изменение ширины столбцов и высоты строк пользователем
		   dataGridView->AllowUserToResizeColumns = false; // Запрещаем изменение ширины столбцов
		   dataGridView->AllowUserToResizeRows = false;    // Запрещаем изменение высоты строк
	   }

	   void SaveTableData(std::vector<std::vector<int>>& tableData, DataGridView^ dataGridView)
	   {
		   tableData.clear(); // Очищаем предыдущие данные

		   // Перебираем строки и столбцы DataGridView и сохраняем значения
		   for (int i = 0; i < dataGridView->RowCount; i++)
		   {
			   std::vector<int> row;
			   for (int j = 0; j < dataGridView->ColumnCount; j++)
			   {
				   int cellValue = dataGridView->Rows[i]->Cells[j]->Value->ToString() != "" ?
					  Convert::ToInt32(dataGridView->Rows[i]->Cells[j]->Value) : 0;
				   row.push_back(cellValue);
			   }
			   tableData.push_back(row);
		   }
	   }

	   // Функция для восстановления данных из вектора в DataGridView
	   void RestoreTableData(std::vector<std::vector<int>>& tableData, DataGridView^ dataGridView)
	   {
		   for (int i = 0; i < dataGridView->RowCount; i++)
		   {
			   for (int j = 0; j < dataGridView->ColumnCount; j++)
			   {
				   // Проверка, есть ли данные для текущей ячейки в сохраненном массиве
				   if (i < tableData.size() && j < tableData[i].size())
				   {
					   dataGridView->Rows[i]->Cells[j]->Value = tableData[i][j];
				   }
				   else
				   {
					   dataGridView->Rows[i]->Cells[j]->Value = "0"; // Очищаем ячейки, если данных нет
				   }
			   }
		   }
	   }

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::vector<std::vector<int>> tableData;
	SaveTableData(tableData, dataGridView1);
	n_table = Convert::ToInt32(((TextBox^)sender)->Text);
	CreateTable(dataGridView1, n_table, m_table);
	RestoreTableData(tableData, dataGridView1);
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	std::vector<std::vector<int>> tableData;
	SaveTableData(tableData, dataGridView1);
	m_table = Convert::ToInt32(((TextBox^)sender)->Text);
	CreateTable(dataGridView1, n_table, m_table);
	RestoreTableData(tableData, dataGridView1);
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	UnMarkTable();
	bool inverse = checkBox1->Checked;
	int** mainMatrix = new int* [n_table];
	for (int i = 0; i < n_table; i++) {
		mainMatrix[i] = new int[m_table];
		for (int j = 0; j < m_table; j++) {
			mainMatrix[i][j] = inverse? -1 * Convert::ToInt64(dataGridView1->Rows[i]->Cells[j]->Value) : Convert::ToInt64(dataGridView1->Rows[i]->Cells[j]->Value);
		}
	}

	AssignmentTask assigmentTask(mainMatrix, n_table, m_table);

	assigmentTask.findMin = !inverse;
	assigmentTask.CalculateTask();
	MarkCellsBlue(assigmentTask.markedZeros, assigmentTask.countMarkedZeros);
	txt_ans_optim->Text = assigmentTask.answerZ.ToString();
}
	   void UnMarkTable() {
		   for (int i = 0; i < dataGridView1->RowCount; i++)
		   {
			   for (int j = 0; j < dataGridView1->ColumnCount; j++)
			   {
				   dataGridView1->Rows[i]->Cells[j]->Style->BackColor = Color::White;
			   }
		   }
	   }

	   void MarkCellsBlue(std::pair<int, int>* markedZeros, int markedZerosSize)
	   {
		   // Проверка, что указатель не пустой и размер больше 0
		   if (markedZeros == nullptr || markedZerosSize <= 0) return;

		   // Устанавливаем синий цвет для каждой ячейки, указанной в markedZeros
		   for (int i = 0; i < markedZerosSize; i++)
		   {
			   int row = markedZeros[i].first;  // Индекс строки
			   int col = markedZeros[i].second; // Индекс столбца

			   // Проверяем, что индексы находятся в допустимых пределах
			   if (row >= 0 && row < dataGridView1->RowCount && col >= 0 && col < dataGridView1->ColumnCount)
			   {
				   // Устанавливаем синий цвет фона для указанной ячейки
				   dataGridView1->Rows[row]->Cells[col]->Style->BackColor = System::Drawing::Color::LightGreen;
			   }
		   }
	   }
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked) {
		checkBox1->Text = "Решать матрицу эффективностей (переключение задач)";
	}
	else {
		checkBox1->Text = "Решать матрицу стоимостей (переключение задач)";
	}
}


	   
// Рисуем объединенные ячейки
private: System::Void dataGridView2_CellPainting(System::Object^ sender, System::Windows::Forms::DataGridViewCellPaintingEventArgs^ e) {
	/*e->AdvancedBorderStyle->Right = DataGridViewAdvancedCellBorderStyle::None;*/
	if (e->RowIndex < 1 || e->ColumnIndex < 0)
		return;
	if (e->RowIndex == 1 && e->ColumnIndex % 2 == 1)
	{
		e->AdvancedBorderStyle->Right = DataGridViewAdvancedCellBorderStyle::None;
	}
	else
	{
		e->AdvancedBorderStyle->Right = dataGridView1->AdvancedCellBorderStyle->Right;
	}
}
};
}

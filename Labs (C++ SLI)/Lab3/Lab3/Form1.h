#pragma once
#include "task1.h"
#include "task2.h"

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
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::MaskedTextBox^ tb_start;

	private: System::Windows::Forms::DataGridView^ dataGridView1;








	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ task1_panel;
	private: System::Windows::Forms::Panel^ task2_panel;












	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ ans;
	private: System::Windows::Forms::MaskedTextBox^ tb_start_2;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::CheckedListBox^ towns;
	private: System::Windows::Forms::Label^ ans_Path;
	private: System::Windows::Forms::Label^ lbl_iter1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ lbl_iter2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ a;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ b;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ c;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ d;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ e;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ f;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ g;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ h;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
































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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tb_start = (gcnew System::Windows::Forms::MaskedTextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->a = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->b = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->c = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->d = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->e = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->f = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->g = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->h = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->task1_panel = (gcnew System::Windows::Forms::Panel());
			this->lbl_iter2 = (gcnew System::Windows::Forms::Label());
			this->lbl_iter1 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->task2_panel = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->ans_Path = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->towns = (gcnew System::Windows::Forms::CheckedListBox());
			this->tb_start_2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->ans = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->task1_panel->SuspendLayout();
			this->task2_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(45, 83);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(432, 370);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(226, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ГРАФ";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button1->Location = System::Drawing::Point(183, 120);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(124, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(254, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"ПОЛУЧЕННОЕ РЕШЕНИЕ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(59, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(284, 24);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Выберите начальную вершину";
			// 
			// tb_start
			// 
			this->tb_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->tb_start->Location = System::Drawing::Point(361, 49);
			this->tb_start->Mask = L"0";
			this->tb_start->Name = L"tb_start";
			this->tb_start->Size = System::Drawing::Size(70, 29);
			this->tb_start->TabIndex = 7;
			this->tb_start->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_start->ValidatingType = System::Int32::typeid;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->Padding = System::Windows::Forms::Padding(0, 10, 0, 10);
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->a, this->b,
					this->c, this->d, this->e, this->f, this->g, this->h
			});
			this->dataGridView1->Location = System::Drawing::Point(50, 246);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(400, 92);
			this->dataGridView1->TabIndex = 8;
			// 
			// a
			// 
			this->a->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->a->HeaderText = L"1";
			this->a->Name = L"a";
			this->a->ReadOnly = true;
			this->a->Width = 50;
			// 
			// b
			// 
			this->b->HeaderText = L"2";
			this->b->Name = L"b";
			this->b->ReadOnly = true;
			this->b->Width = 50;
			// 
			// c
			// 
			this->c->HeaderText = L"3";
			this->c->Name = L"c";
			this->c->ReadOnly = true;
			this->c->Width = 50;
			// 
			// d
			// 
			this->d->HeaderText = L"4";
			this->d->Name = L"d";
			this->d->ReadOnly = true;
			this->d->Width = 50;
			// 
			// e
			// 
			this->e->HeaderText = L"5";
			this->e->Name = L"e";
			this->e->ReadOnly = true;
			this->e->Width = 50;
			// 
			// f
			// 
			this->f->HeaderText = L"6";
			this->f->Name = L"f";
			this->f->ReadOnly = true;
			this->f->Width = 50;
			// 
			// g
			// 
			this->g->HeaderText = L"7";
			this->g->Name = L"g";
			this->g->ReadOnly = true;
			this->g->Width = 50;
			// 
			// h
			// 
			this->h->HeaderText = L"8";
			this->h->Name = L"h";
			this->h->ReadOnly = true;
			this->h->Width = 50;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(655, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(230, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"НАЧАЛЬНЫЕ ДАННЫЕ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(44, 448);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(216, 60);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Задание 1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(260, 448);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(218, 45);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Задание 2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(45, 386);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 24);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Метод Дейкстры";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(45, 433);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(145, 24);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Метод Флойда";
			// 
			// task1_panel
			// 
			this->task1_panel->Controls->Add(this->lbl_iter2);
			this->task1_panel->Controls->Add(this->lbl_iter1);
			this->task1_panel->Controls->Add(this->label7);
			this->task1_panel->Controls->Add(this->label6);
			this->task1_panel->Controls->Add(this->label5);
			this->task1_panel->Controls->Add(this->dataGridView1);
			this->task1_panel->Controls->Add(this->tb_start);
			this->task1_panel->Controls->Add(this->label4);
			this->task1_panel->Controls->Add(this->label2);
			this->task1_panel->Controls->Add(this->button1);
			this->task1_panel->Location = System::Drawing::Point(516, 83);
			this->task1_panel->Name = L"task1_panel";
			this->task1_panel->Size = System::Drawing::Size(499, 470);
			this->task1_panel->TabIndex = 13;
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
			this->label7->Location = System::Drawing::Point(82, 346);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(338, 24);
			this->label7->TabIndex = 13;
			this->label7->Text = L"Сравнение количества итераций";
			// 
			// task2_panel
			// 
			this->task2_panel->Controls->Add(this->label13);
			this->task2_panel->Controls->Add(this->label12);
			this->task2_panel->Controls->Add(this->ans_Path);
			this->task2_panel->Controls->Add(this->label11);
			this->task2_panel->Controls->Add(this->label8);
			this->task2_panel->Controls->Add(this->towns);
			this->task2_panel->Controls->Add(this->tb_start_2);
			this->task2_panel->Controls->Add(this->ans);
			this->task2_panel->Controls->Add(this->label10);
			this->task2_panel->Controls->Add(this->button4);
			this->task2_panel->Controls->Add(this->label9);
			this->task2_panel->Location = System::Drawing::Point(516, 83);
			this->task2_panel->Name = L"task2_panel";
			this->task2_panel->Size = System::Drawing::Size(499, 520);
			this->task2_panel->TabIndex = 14;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(139, 436);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(187, 24);
			this->label13->TabIndex = 29;
			this->label13->Text = L"Оптимальный путь:\r\n";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(59, 401);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(184, 24);
			this->label12->TabIndex = 28;
			this->label12->Text = L"Наименьшая сумма";
			// 
			// ans_Path
			// 
			this->ans_Path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ans_Path->Location = System::Drawing::Point(22, 467);
			this->ans_Path->Name = L"ans_Path";
			this->ans_Path->Size = System::Drawing::Size(440, 53);
			this->ans_Path->TabIndex = 27;
			this->ans_Path->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(219, 139);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(231, 20);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Город, в котором живет Оля:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(45, 71);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 20);
			this->label8->TabIndex = 25;
			this->label8->Text = L"Города друзей:";
			// 
			// towns
			// 
			this->towns->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->towns->FormattingEnabled = true;
			this->towns->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Город 1", L"Город 2", L"Город 3", L"Город 4", L"Город 5",
					L"Город 6", L"Город 7", L"Город 8"
			});
			this->towns->Location = System::Drawing::Point(49, 94);
			this->towns->Name = L"towns";
			this->towns->Size = System::Drawing::Size(120, 172);
			this->towns->TabIndex = 24;
			// 
			// tb_start_2
			// 
			this->tb_start_2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->tb_start_2->Location = System::Drawing::Point(303, 164);
			this->tb_start_2->Mask = L"0";
			this->tb_start_2->Name = L"tb_start_2";
			this->tb_start_2->Size = System::Drawing::Size(70, 29);
			this->tb_start_2->TabIndex = 23;
			this->tb_start_2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_start_2->ValidatingType = System::Int32::typeid;
			// 
			// ans
			// 
			this->ans->AutoSize = true;
			this->ans->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ans->Location = System::Drawing::Point(267, 401);
			this->ans->Name = L"ans";
			this->ans->Size = System::Drawing::Size(0, 24);
			this->ans->TabIndex = 13;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(115, 357);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(254, 24);
			this->label10->TabIndex = 3;
			this->label10->Text = L"ПОЛУЧЕННОЕ РЕШЕНИЕ";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->button4->Location = System::Drawing::Point(143, 281);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(211, 57);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Решить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(18, 5);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(444, 49);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Выберите в какие города необходимо заехать. а также начальный город:\r\n\r\n";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1059, 605);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->task1_panel);
			this->Controls->Add(this->task2_panel);
			this->Name = L"Form1";
			this->Text = L"Лабораторная работа №3";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->task1_panel->ResumeLayout(false);
			this->task1_panel->PerformLayout();
			this->task2_panel->ResumeLayout(false);
			this->task2_panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void задание2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
	pictureBox1->Image = Image::FromFile("C:/Users/romas/source/repos/iT1P/Lab3/Lab3/graph.png");
	task2_panel->Hide();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	button2->Height = 60;
	button3->Height = 45;
	task1_panel->Show();
	task2_panel->Hide();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	button2->Height = 45;
	button3->Height = 60;
	task1_panel->Hide();
	task2_panel->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Rows->Clear();
	int start = Convert::ToInt16(tb_start->Text) - 1;
	
	//Количество узлов
	int n = 9;

	//Инициализация матрицы связей
	int A[9][9] = { {0, 3, 0, 0, 6, 4, 0, 6, 0}, // Вершина 1
					{3, 0, 3, 0, 0, 4, 0, 5, 0}, // Вершина 2
					{0, 3, 0, 2, 0, 0, 4, 0, 10}, // Вершина 3
					{0, 0, 2, 0, 2, 0, 0, 0, 0}, // Вершина 4
					{6, 0, 0, 2, 0, 1, 0, 7, 0}, // Вершина 5
					{4, 4, 0, 0, 1, 0, 1, 0, 0}, // Вершина 6
					{0, 0, 4, 0, 0, 1, 0, 5, 0}, // Вершина 7
					{6, 5, 0, 0, 7, 0, 5, 0, 0},// Вершина 8
					{0, 0, 10, 0, 0, 0, 0, 0, 0} };// Вершина 9
		

	int** A1 = new int* [n];
	
	
	for (int i = 0; i < n; i++) {
		A1[i] = new int[n];
		for (int j = 0; j < n; j++) {
			A1[i][j] = A[i][j];
		}
	}
	int iter1 = 0;
	int iter2 = 0;

	int* minPaths = task1::Dijkstra(n, A1, start, iter1);
	int* minPaths1 = task1::Floyd(n, A1, iter2)[start];

	lbl_iter1->Text = Convert::ToString(iter1);
	lbl_iter2->Text = Convert::ToString(iter2);

	// Добавляем строку с минимальными путями
	DataGridViewRow^ row = gcnew DataGridViewRow();
	row->CreateCells(dataGridView1);

	for (int i = 0; i < n; i++) {
		row->Cells[i]->Value = minPaths[i];  // Заполняем ячейки значениями
	}
	row->Height = 46;
	dataGridView1->Rows->Add(row);

	// Освобождаем динамически выделенную память
	for (int i = 0; i < n; i++) {
		delete[] A1[i];
	}
	delete[] A1;
	delete[] minPaths;
	delete[] minPaths1;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//Количество узлов
	int n = 9;

	//Инициализация матрицы связей
	int A[9][9] = { {0, 3, 0, 0, 6, 4, 0, 6, 0}, // Вершина 1
					{3, 0, 3, 0, 0, 4, 0, 5, 0}, // Вершина 2
					{0, 3, 0, 2, 0, 0, 4, 0, 10}, // Вершина 3
					{0, 0, 2, 0, 2, 0, 0, 0, 0}, // Вершина 4
					{6, 0, 0, 2, 0, 1, 0, 7, 0}, // Вершина 5
					{4, 4, 0, 0, 1, 0, 1, 0, 0}, // Вершина 6
					{0, 0, 4, 0, 0, 1, 0, 5, 0}, // Вершина 7
					{6, 5, 0, 0, 7, 0, 5, 0, 0},// Вершина 8
					{0, 0, 10, 0, 0, 0, 0, 0, 0} };// Вершина 9

	int** A1 = new int* [n];
	for (int i = 0; i < n; i++) {
		A1[i] = new int[n];
		for (int j = 0; j < n; j++) {
			A1[i][j] = A[i][j];
		}
	}

	int** paths = new int* [n];
	for (int i = 0; i < n; i++) {
		paths[i] = new int [n];
		for (int j = 0; j < n; j++) {
			paths[i][j] = (A1[i][j] != 0) ?  i+1 : 0;
		}
	}
	int** allMinPaths = task1::Floyd(n, A1, paths);
	
	//Временный вывод в консоль массива paths
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			System::Diagnostics::Debug::Write(paths[i][j] + " ");
		}
		System::Diagnostics::Debug::Write("\n");
	}
	if (tb_start_2->Text == "") return;
	int start = Convert::ToInt16(tb_start_2->Text) - 1;
	if (start == 8 || start == -1) return;
	int count = 0;
	
	// Массив для хранения всех вершин, кроме начальной(вершина 0)
	for (int i = 0; i < n; i++) {
		if (i == 8) {
			count++;
			break;
		}
		if (towns->GetItemChecked(i) && i != start) {
				count++;
			}
	}
	;
	if (count == 0) return;
	int* vertices = new int[count];
	int temp = 0;
	for (int i = 0; i < n; i++) {
		if (i == 8) {
			vertices[temp] = i + 1;
			temp++;
			break;
		}
		if (towns->GetItemChecked(i) && i != start) {
			vertices[temp] = i + 1;
			temp++;
		}
	}
	String^ answerPath;
	int result = task2::tsp(allMinPaths, start, vertices, count + 1, paths, answerPath);
	ans->Text = Convert::ToString(result);
	
	ans_Path->Text = answerPath;
}

};
}

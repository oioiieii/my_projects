#pragma once

#include "classes.h"
#include "XmlWorker.h"


#include "DBWorker.h"

namespace Laba6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::ComponentModel; // Для BindingList


	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			filePath = "manufacturers.xml";
			String^ currentDirectory = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
			filePath = System::IO::Path::Combine(currentDirectory, filePath);

			
			//// Добавляем объект Manufacturer в файл
			//Manufacturer^ newManufacturer = gcnew Manufacturer("NewCorp", "123 New St");
			//bool result = XmlWorker::AddManufacturerToXml(filePath, newManufacturer);

			//if (result)
			//{
			//	MessageBox::Show("Элемент успешно добавлен в XML файл.");
			//}
			//else
			//{
			//	MessageBox::Show("Не удалось добавить элемент в XML файл.");
			//}

			//result = XmlWorker::

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridView^ added_table;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewLinkColumn^ Column2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ log_output;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::DataGridView^ dataGridView2;



	private: System::Windows::Forms::Label^ label5;



	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;








	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->added_table = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewLinkColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->log_output = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->added_table))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(580, 598);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 85);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(507, 525);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(222, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(64, 525);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(229, 52);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Прочитать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(64, 94);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(665, 368);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::dataGridView1_RowsAdded);
			this->dataGridView1->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MainForm::dataGridView1_RowsRemoved);
			this->dataGridView1->RowValidated += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_RowValidated);
			this->dataGridView1->UserAddedRow += gcnew System::Windows::Forms::DataGridViewRowEventHandler(this, &MainForm::dataGridView1_UserAddedRow);
			// 
			// added_table
			// 
			this->added_table->AllowUserToAddRows = false;
			this->added_table->AllowUserToDeleteRows = false;
			this->added_table->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->added_table->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->added_table->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->added_table->ColumnHeadersHeight = 50;
			this->added_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->added_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->added_table->DefaultCellStyle = dataGridViewCellStyle4;
			this->added_table->Location = System::Drawing::Point(64, 598);
			this->added_table->Name = L"added_table";
			this->added_table->Size = System::Drawing::Size(496, 85);
			this->added_table->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(306, 525);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(195, 52);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Изменить";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(848, 188);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(250, 57);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Таблица марки";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(848, 251);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(250, 68);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Таблица производителей";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(848, 325);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(250, 67);
			this->button7->TabIndex = 8;
			this->button7->Text = L"Таблица автомобили";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(848, 398);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(250, 64);
			this->button8->TabIndex = 9;
			this->button8->Text = L"Таблица владельцев";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(848, 94);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(250, 88);
			this->button9->TabIndex = 10;
			this->button9->Text = L"Таблица регистрации";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MainForm::button9_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(829, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(269, 31);
			this->label1->TabIndex = 11;
			this->label1->Text = L"ВЫБОР ТАБЛИЦЫ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(182, 481);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(435, 31);
			this->label2->TabIndex = 12;
			this->label2->Text = L"ФУНКЦИОНАЛЬНЫЕ КНОПКИ";
			// 
			// log_output
			// 
			this->log_output->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_output->Location = System::Drawing::Point(811, 525);
			this->log_output->Multiline = true;
			this->log_output->Name = L"log_output";
			this->log_output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->log_output->Size = System::Drawing::Size(332, 158);
			this->log_output->TabIndex = 13;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(783, 487);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(385, 25);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Результаты выполнения действий";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(206, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(374, 31);
			this->label4->TabIndex = 15;
			this->label4->Text = L"ТАБЛИЦА РЕГИСТРАЦИИ";
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(1245, 413);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(336, 68);
			this->button10->TabIndex = 16;
			this->button10->Text = L"Экспорт в MySQL";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MainForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(1191, 326);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(430, 68);
			this->button11->TabIndex = 17;
			this->button11->Text = L"Обновить данные";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MainForm::button11_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView2->ColumnHeadersHeight = 50;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column4,
					this->Column5, this->Column3
			});
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->Location = System::Drawing::Point(1191, 134);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView2->Size = System::Drawing::Size(430, 186);
			this->dataGridView2->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1198, 94);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(394, 25);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Изменение дополнительных полей";
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(1245, 497);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(336, 68);
			this->button12->TabIndex = 20;
			this->button12->Text = L"Импорт из MySQL";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MainForm::button12_Click);
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Имя поля";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Тип поля";
			this->Column5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"INT", L"STRING", L"DATE" });
			this->Column5->Name = L"Column5";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Стандартное значение";
			this->Column3->Name = L"Column3";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1641, 730);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->log_output);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->added_table);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"Лабораторная работа №6";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->added_table))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		String^ filePath;
		TableType selectTable = TableType::Manufacturers;

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (dataGridView1->SelectedRows->Count > 0) {
			// Получаем первую выделенную строку
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0];

			Object^ object = selectedRow->DataBoundItem;;
			
			bool result = XmlWorker::DeleteFromXml(filePath, object);

			if (result)
			{
				log_output->AppendText("Элемент успешно удален. \r\n");
			}
			else
			{
				log_output->AppendText("Элемент не был удален\r\n");
			}
		}

		//Manufacturer^ newManufacturer = gcnew Manufacturer("NewCorp", "123 New St");
	}
private: System::Void dataGridView1_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e) {
	//MessageBox::Show("Строка добавлена");
}
private: System::Void dataGridView1_RowsRemoved(System::Object^ sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^ e) {
	//MessageBox::Show("Строка удалена");
}
private: System::Void dataGridView1_RowValidated(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//MessageBox::Show("Строка была изменена");
}


private: System::Void dataGridView1_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e) {
	/*MessageBox::Show("Строка добавлена 1 ");*/
}

	   void AddColumnForDynamicFields(List<Tuple<int, String^, String^ >^>^ dynamicFields, DataGridView^ dataGrid) {
		   for each (Tuple<int, String ^, String^> ^ field in dynamicFields) {
			   DataGridViewColumn^ dynamicColumn = nullptr;

				dynamicColumn = gcnew DataGridViewTextBoxColumn();
				dynamicColumn->Name = field->Item2;
				dynamicColumn->HeaderText = field->Item2;
				
			   if (dynamicColumn) {
				   dataGrid->Columns->Add(dynamicColumn);
			   }
		   }
	   }

	   void ShowValuesForDynamicFields(List<IDynamicFields^>^ rowList, DataGridView^ dataGrid) {
		   for (int numRow = 0; numRow < rowList->Count; numRow++){
			   IDynamicFields^ row = rowList[numRow];
			   for (int i = row->getDynamicFields()->Count; i > 0; i--) {
				   dataGrid->Rows[numRow]->Cells[dataGrid->Columns->Count - row->getDynamicFields()->Count + i - 1]->Value = row->getDynamicValues()[i - 1];
			   }
		   }
	   }

	   void RefreshDynamicFields(IDynamicFields^ object, DataGridViewRow^ dataGridRow) {
			for (int i = object->getDynamicFields()->Count; i > 0; i--) {
				object->getDynamicValues()[i - 1] = dataGridRow->Cells[dataGridRow->Cells->Count - object->getDynamicFields()->Count + i - 1]->Value->ToString();
			}
	   }

	   List<String^>^ ReadDynamicFields(DataGridView^ dataGrid, IDynamicFields^ row, int numRow) {
		   List<String^>^ tecDynamicValues = gcnew  List<String^>();
		   
			for (int i = row->getDynamicFields()->Count; i > 0; i--) {
				tecDynamicValues->Add(dataGrid->Rows[numRow]->Cells[dataGrid->Columns->Count - row->getDynamicFields()->Count + i - 1]->Value->ToString());
			}
			return tecDynamicValues;
	   }

	   void ShowTableManufacturers() {
		   dataGridView1->Columns->Clear();

		   DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		   column1->HeaderText = "Код производителя";
		   column1->DataPropertyName = "ManufacturerCode";
		   column1->Name = "ManufacturerCode";
		   column1->ReadOnly = true;
		   dataGridView1->Columns->Add(column1);

		   DataGridViewTextBoxColumn^ column2 = gcnew DataGridViewTextBoxColumn();
		   column2->HeaderText = "Имя";
		   column2->DataPropertyName = "Name";
		   column2->Name = "Name";
		   dataGridView1->Columns->Add(column2);

		   DataGridViewTextBoxColumn^ column3 = gcnew DataGridViewTextBoxColumn();
		   column3->HeaderText = "Адрес";
		   column3->DataPropertyName = "Address";
		   column3->Name = "Address";
		   dataGridView1->Columns->Add(column3);

		   dataGridView1->AutoGenerateColumns = false;

		   added_table->Columns->Clear();
		   added_table->Columns->Add(CopyColumn(column2));
		   added_table->Columns->Add(CopyColumn(column3));
		   added_table->Rows->Add();

		   if (Manufacturer::DynamicFields->Count != 0) {
			   //Заморозить длину столбцов и добавить горизонтальный прокрут
			   //Типо minWidth = tecWidth
			   AddColumnForDynamicFields(Manufacturer::DynamicFields, dataGridView1);
			   AddColumnForDynamicFields(Manufacturer::DynamicFields, added_table);
		   }

		   List<Manufacturer^>^ list = gcnew List<Manufacturer^>();
		   List<IDynamicFields^>^ dynamicFieldsList = gcnew List<IDynamicFields^>();
		   for each (Manufacturer ^ manufacturer in Manufacturer::manufacturers) {
			   list->Add(manufacturer);
			   dynamicFieldsList->Add((IDynamicFields^)manufacturer);
		   }

		   dataGridView1->DataSource = list;

		   if (Manufacturer::DynamicFields->Count != 0) {
			   //Теперь отображаем содержимое
			   ShowValuesForDynamicFields(dynamicFieldsList, dataGridView1);
		   }

		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true;
		   }
	   }

	   void ShowTableBrands() {
		   // Очистим существующие столбцы
		   dataGridView1->Columns->Clear();

		   // Настраиваем столбцы вручную
		   DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		   column1->HeaderText = "Код марки";
		   column1->DataPropertyName = "brandCode"; // Связь с свойством
		   column1->Name = "brandCode";
		   column1->ReadOnly = true;
		   dataGridView1->Columns->Add(column1);

		   DataGridViewTextBoxColumn^ column2 = gcnew DataGridViewTextBoxColumn();
		   column2->HeaderText = "Имя";
		   column2->DataPropertyName = "name"; // Связь с свойством
		   column2->Name = "name";
		   dataGridView1->Columns->Add(column2);


		   DataGridViewComboBoxColumn^ column3 = CreateComboColumn(Manufacturer::manufacturers, "Код произовдителя", "manufacturerCode", TableType::Manufacturers);
		   column3->DataPropertyName = "manufacturer"; // Связь с свойством
		   dataGridView1->Columns->Add(column3);

		   added_table->Columns->Clear();
		   added_table->Columns->Add(CopyColumn(column2));
		   added_table->Columns->Add(CreateComboColumn(Manufacturer::manufacturers, "Код произовдителя", "manufacturerCode", TableType::Manufacturers));
		   added_table->Rows->Add();

		   dataGridView1->AutoGenerateColumns = false;

		   // Добавление динамических полей
		   if (Brand::DynamicFields->Count != 0) {
			   AddColumnForDynamicFields(Brand::DynamicFields, dataGridView1);
			   AddColumnForDynamicFields(Brand::DynamicFields, added_table);
		   }

		   // Заполнение таблицы
		   List<Brand^>^ list = gcnew List<Brand^>();
		   List<IDynamicFields^>^ dynamicFieldsList = gcnew List<IDynamicFields^>();
		   for each (Brand ^ brand in Brand::brands) {
			   list->Add(gcnew Brand(brand, safe_cast<List<Manufacturer^>^>(column3->DataSource)));
			   dynamicFieldsList->Add((IDynamicFields^)brand);
		   }

		   dataGridView1->DataSource = list;

		   if (Brand::DynamicFields->Count != 0) {
			   ShowValuesForDynamicFields(dynamicFieldsList, dataGridView1);
		   }

		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true;
		   }
	   }

	   void MainForm::ShowTableOwners() {
		   // Очистим существующие столбцы
		   dataGridView1->Columns->Clear();

		   // Настраиваем столбцы вручную
		   DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		   column1->HeaderText = "Код владельца";
		   column1->DataPropertyName = "ownerCode"; // Связь с свойством
		   column1->Name = "ownerCode";
		   column1->ReadOnly = true;
		   dataGridView1->Columns->Add(column1);

		   DataGridViewTextBoxColumn^ column2 = gcnew DataGridViewTextBoxColumn();
		   column2->HeaderText = "ФИО владельца";
		   column2->DataPropertyName = "fullName"; // Связь с свойством
		   column2->Name = "fullName";
		   column2->ReadOnly = true;
		   dataGridView1->Columns->Add(column2);

		   DataGridViewTextBoxColumn^ column3 = gcnew DataGridViewTextBoxColumn();
		   column3->HeaderText = "Адрес проживания";
		   column3->DataPropertyName = "address"; // Связь с свойством
		   column3->Name = "address";
		   column3->ReadOnly = true;
		   dataGridView1->Columns->Add(column3);

		   // Настраиваем таблицу добавления для владельцев
		   added_table->Columns->Clear();
		   added_table->Columns->Add(CopyColumn(column2)); // Копируем второй столбец (ФИО владельца)
		   added_table->Columns->Add(CopyColumn(column3)); // Копируем второй столбец (ФИО владельца)
		   added_table->Rows->Add(); // Добавляем пустую строку

		   // Отключаем автогенерацию столбцов
		   dataGridView1->AutoGenerateColumns = false;

		   // Добавление динамических полей
		   if (Laba6::Owner::DynamicFields->Count != 0) {
			   AddColumnForDynamicFields(Laba6::Owner::DynamicFields, dataGridView1);
			   AddColumnForDynamicFields(Laba6::Owner::DynamicFields, added_table);
		   }

		   // Заполнение таблицы
		   List<Laba6::Owner^>^ list = gcnew List<Laba6::Owner^>();
		   List<IDynamicFields^>^ dynamicFieldsList = gcnew List<IDynamicFields^>();
		   for each (Laba6::Owner ^ owner in Laba6::Owner::owners) {
			   list->Add(gcnew Laba6::Owner(owner));
			   dynamicFieldsList->Add((IDynamicFields^)owner);
		   }

		   dataGridView1->DataSource = list;

		   if (Laba6::Owner::DynamicFields->Count != 0) {
			   ShowValuesForDynamicFields(dynamicFieldsList, dataGridView1);
		   }

		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true;
		   }
	   }

	   void MainForm::ShowTableCars() {
		   dataGridView1->Columns->Clear();

		   // Настраиваем столбцы вручную
		   DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		   column1->HeaderText = "Код автомобиля";
		   column1->DataPropertyName = "carCode"; // Связь с свойством
		   column1->Name = "carCode";
		   column1->ReadOnly = true;
		   dataGridView1->Columns->Add(column1);

		   DataGridViewComboBoxColumn^ column2 = CreateComboColumn(Brand::brands, "Код марки автомобиля", "brandCode", TableType::Brands);
		   column2->DataPropertyName = "brand"; // Связь с свойством
		   column2->Name = "brand";
		   dataGridView1->Columns->Add(column2);

		   DataGridViewTextBoxColumn^ column3 = gcnew DataGridViewTextBoxColumn();
		   column3->HeaderText = "Номер кузова";
		   column3->DataPropertyName = "chassisNumber"; // Связь с свойством
		   column3->Name = "chassisNumber";
		   column3->ReadOnly = true;
		   dataGridView1->Columns->Add(column3);

		   DataGridViewTextBoxColumn^ column4 = gcnew DataGridViewTextBoxColumn();
		   column4->HeaderText = "Двигатель";
		   column4->DataPropertyName = "engineNumber"; // Связь с свойством
		   column4->Name = "engineNumber";
		   column4->ReadOnly = true;
		   dataGridView1->Columns->Add(column4);

		   // Настроим таблицу для добавления новых автомобилей
		   added_table->Columns->Clear();
		   added_table->Columns->Add(CopyColumn(column3)); // Копируем третий столбец (Шасси)
		   added_table->Columns->Add(CopyColumn(column4)); // Копируем четвертый столбец (Двигатель)
		   added_table->Columns->Add(CreateComboColumn(Brand::brands, "Марка", "brandCode", TableType::Brands)); // Комбобокс для выбора марки
		   added_table->Rows->Add(); // Добавляем пустую строку

		   // Отключаем автогенерацию столбцов
		   dataGridView1->AutoGenerateColumns = false;

		   // Добавление динамических полей
		   if (Car::DynamicFields->Count != 0) {
			   AddColumnForDynamicFields(Car::DynamicFields, dataGridView1);
			   AddColumnForDynamicFields(Car::DynamicFields, added_table);
		   }

		   // Заполнение таблицы
		   List<Car^>^ list = gcnew List<Car^>();
		   List<IDynamicFields^>^ dynamicFieldsList = gcnew List<IDynamicFields^>();
		   for each (Car ^ car in Car::cars) {
			   list->Add(gcnew Car(car, safe_cast<List<Brand^>^>(column2->DataSource)));
			   dynamicFieldsList->Add((IDynamicFields^)car);
		   }

		   dataGridView1->DataSource = list;

		   if (Car::DynamicFields->Count != 0) {
			   ShowValuesForDynamicFields(dynamicFieldsList, dataGridView1);
		   }

		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true;
		   }
	   }

	   void MainForm::ShowTableRegistrations() {
		   // Очистим существующие столбцы
		   dataGridView1->Columns->Clear();

		   // Настраиваем столбцы вручную
		   DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		   column1->HeaderText = "Код регистрации";
		   column1->DataPropertyName = "registrationCode"; // Связь с свойством
		   column1->Name = "registrationCode";
		   column1->ReadOnly = true;
		   dataGridView1->Columns->Add(column1);

		   DataGridViewComboBoxColumn^ column2 = CreateComboColumn(Laba6::Owner::owners, "Код владельца", "ownerId", TableType::Owners);
		   column2->DataPropertyName = "owner"; // Связь с свойством
		   column2->Name = "owner";
		   dataGridView1->Columns->Add(column2);

		   DataGridViewComboBoxColumn^ column3 = CreateComboColumn(Laba6::Car::cars, "Код автомобиля", "carId", TableType::Cars);
		   column3->DataPropertyName = "car"; // Связь с свойством
		   dataGridView1->Columns->Add(column3);

		   DataGridViewTextBoxColumn^ column4 = gcnew DataGridViewTextBoxColumn();
		   column4->HeaderText = "Дата";
		   column4->DataPropertyName = "date"; // Связь с свойством
		   column4->Name = "date";
		   dataGridView1->Columns->Add(column4);


		   // Настроим таблицу для добавления новых регистраций
		   added_table->Columns->Clear();
		   DataGridViewComboBoxColumn^ column5 = CreateComboColumn(Laba6::Owner::owners, "Код владельца", "ownerId", TableType::Owners);
		   DataGridViewComboBoxColumn^ column6 = CreateComboColumn(Laba6::Car::cars, "Код автомобиля", "carId", TableType::Cars);
		   column5->MinimumWidth = 160;
		   column6->MinimumWidth = 180;
		   added_table->Columns->Add(column5); // Комбобокс для выбора владельца
		   added_table->Columns->Add(column6); // Комбобокс для выбора автомобиля
		   added_table->Columns->Add(CopyColumn(column4)); // Копируем третий столбец (Дата)
		   added_table->Rows->Add(); // Добавляем пустую строку

		   // Отключаем автогенерацию столбцов
		   dataGridView1->AutoGenerateColumns = false;

		   // Добавление динамических полей
		   if (Registration::DynamicFields->Count != 0) {
			   AddColumnForDynamicFields(Registration::DynamicFields, dataGridView1);
			   AddColumnForDynamicFields(Registration::DynamicFields, added_table);
		   }

		   // Заполнение таблицы
		   List<Registration^>^ list = gcnew List<Registration^>();
		   List<IDynamicFields^>^ dynamicFieldsList = gcnew List<IDynamicFields^>();
		   for each (Registration ^ reg in Registration::registrations) {
			   list->Add(gcnew Registration(reg, safe_cast<List<Laba6::Owner^>^>(column2->DataSource), safe_cast<List<Car^>^>(column3->DataSource)));
			   dynamicFieldsList->Add((IDynamicFields^)reg);
		   }

		   dataGridView1->DataSource = list;

		   if (Registration::DynamicFields->Count != 0) {
			   ShowValuesForDynamicFields(dynamicFieldsList, dataGridView1);
		   }

		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true;
		   }
	   }


	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		// Кнопка ПРОЧИТАТЬ

		for (int i = 0; i < 5; i++) {
			auto readData = XmlWorker::ReadFromXml(filePath);

			Manufacturer::manufacturers = gcnew ArrayList(readData->Item1);
			Brand::brands = gcnew ArrayList(readData->Item2);
			Laba6::Owner::owners = gcnew ArrayList(readData->Item3);
			Laba6::Car::cars = gcnew ArrayList(readData->Item4);
			Laba6::Registration::registrations = gcnew ArrayList(readData->Item5);
		}

		ChangeTable();
		log_output->AppendText("Чтение прошло успешно. \r\n");
	}


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Добавляем объект в файл
	DataGridViewRow^ selectedRow = added_table->Rows[0];
	bool result;

	if (selectTable == TableType::Manufacturers) {
		String^ name = selectedRow->Cells[0]->Value->ToString();
		String^ address = selectedRow->Cells[1]->Value->ToString();

		if (name == "" || address == "") {
			return;
		}
		else {
			Manufacturer^ newManufacturer = gcnew Manufacturer(name, address, gcnew List<String^>());
			List<String^>^ newDynamicList = ReadDynamicFields(added_table, newManufacturer, 0);
			newManufacturer = gcnew Manufacturer(newManufacturer->ManufacturerCode, name, address, newDynamicList);
			result = XmlWorker::AddToXml(filePath, newManufacturer);
		}
	}
	else if (selectTable == TableType::Brands) {
		String^ name = selectedRow->Cells[0]->Value->ToString();
		Manufacturer^ manufacturer = (Manufacturer^)selectedRow->Cells[1]->Value;

		if (name == "" || manufacturer == nullptr) {
			return;
		}
		else {
			Brand^ newBrand = gcnew Brand(name, manufacturer, gcnew List<String^>());
			List<String^>^ newDynamicList = ReadDynamicFields(added_table, newBrand, 0);
			newBrand = gcnew Brand(newBrand->getID(), name, manufacturer, newDynamicList);
			result = XmlWorker::AddToXml(filePath, newBrand);
		}
	}
	else if (selectTable == TableType::Owners) {
		String^ fullName = selectedRow->Cells[0]->Value->ToString();
		String^ address = selectedRow->Cells[1]->Value->ToString();

		if (fullName == "" || address == "") {
			return;
		}
		else {

			Laba6::Owner^ newOwner = gcnew Laba6::Owner(fullName, address, gcnew List<String^>());
			List<String^>^ newDynamicList = ReadDynamicFields(added_table, newOwner, 0);
			newOwner = gcnew Laba6::Owner(newOwner->getID(), fullName, address, newDynamicList);
			result = XmlWorker::AddToXml(filePath, newOwner);
		}
	}
	else if (selectTable == TableType::Cars) {
		String^ chassisNumber = selectedRow->Cells[0]->Value->ToString();
		String^ engineNumber = selectedRow->Cells[1]->Value->ToString();
		Brand^ brand = (Brand^)selectedRow->Cells[2]->Value;

		if (chassisNumber == "" || engineNumber == "" || brand == nullptr) {
			return;
		}
		else {
			Car^ newCar = gcnew Car(brand, chassisNumber, engineNumber, gcnew List<String^>());
			List<String^>^ newDynamicList = ReadDynamicFields(added_table, newCar, 0);
			newCar = gcnew Car(newCar->getID(), brand, chassisNumber, engineNumber, newDynamicList);
			result = XmlWorker::AddToXml(filePath, newCar);
		}
	}
	else if (selectTable == TableType::Registrations) {
		Laba6::Owner^ owner = (Laba6::Owner^)selectedRow->Cells[0]->Value;
		Car^ car = (Car^)selectedRow->Cells[1]->Value;
		String^ date = Convert::ToString(selectedRow->Cells[2]->Value->ToString());


		if (owner == nullptr || car == nullptr) {
			return;
		}
		else {
			Registration^ newRegistration = gcnew Registration(owner, car, date, gcnew List<String^>());
			List<String^>^ newDynamicList = ReadDynamicFields(added_table, newRegistration, 0);
			newRegistration = gcnew Registration(newRegistration->getID(), owner, car, date, newDynamicList);

			result = XmlWorker::AddToXml(filePath, newRegistration);
		}
	}

	if (result) {
		log_output->AppendText("Запись успешно добавлена.\r\n");
	}
	else {
		log_output->AppendText("Запись не была произведена\r\n");
	}
}


	   DataGridViewTextBoxColumn^ CopyColumn(DataGridViewTextBoxColumn^ copiedColumn) {
		   DataGridViewTextBoxColumn^ copyColumn = gcnew DataGridViewTextBoxColumn();
		   copyColumn->HeaderText = copiedColumn->HeaderText;
		   copyColumn->DataPropertyName = copiedColumn->DataPropertyName;
		   copyColumn->Name = copiedColumn->Name;
		   return copyColumn;
	   }
	 
	   DataGridViewComboBoxColumn^ CreateComboColumn(ArrayList^ array, String^ headerText, String^ headerName, TableType tableType) {
		   DataGridViewComboBoxColumn^ comboColumn = gcnew DataGridViewComboBoxColumn();
		   comboColumn->HeaderText = headerText;
		   comboColumn->Name = headerName;

		   if (tableType == TableType::Manufacturers) {
			   System::Collections::Generic::List<Manufacturer^>^ itemList = gcnew System::Collections::Generic::List<Manufacturer^>();

			   for each (Manufacturer ^ var in array) {
				   itemList->Add(var);
			   }
			   comboColumn->DataSource = itemList;
			   comboColumn->DisplayMember = "ManufacturerCode";
			   comboColumn->ValueMember = "This";
		   }
		   else if (tableType == TableType::Brands) {
			   System::Collections::Generic::List<Brand^>^ itemList = gcnew System::Collections::Generic::List<Brand^>();

			   for each (Brand ^ var in array) {
				   itemList->Add(var);
			   }
			   comboColumn->DataSource = itemList;
			   comboColumn->DisplayMember = "brandCode";
			   comboColumn->ValueMember = "This";
		   }
		   else if (tableType == TableType::Owners) {
			   System::Collections::Generic::List<Laba6::Owner^>^ itemList = gcnew System::Collections::Generic::List<Laba6::Owner^>();

			   for each (Laba6::Owner ^ var in array) {
				   itemList->Add(var);
			   }
			   comboColumn->DataSource = itemList;
			   comboColumn->DisplayMember = "ownerCode";
			   comboColumn->ValueMember = "This";
		   }
		   else if (tableType == TableType::Cars) {
			   System::Collections::Generic::List<Car^>^ itemList = gcnew System::Collections::Generic::List<Car^>();

			   for each (Car ^ var in array) {
				   itemList->Add(var);
			   }
			   comboColumn->DataSource = itemList;
			   comboColumn->DisplayMember = "carCode";
			   comboColumn->ValueMember = "This";
		   }
		   else {
			   throw gcnew InvalidOperationException("Неизвестный тип");
		   }

		   return comboColumn;
	   }
	   
	   int getId(Object^ obj) {
		   if (dynamic_cast<Manufacturer^>(obj) != nullptr) {
			   return ((Manufacturer^)obj)->ManufacturerCode;
		   }
		   else if (dynamic_cast<Brand^>(obj) != nullptr) {
			   return ((Brand^)obj)->brandCode;
		   }
		   else if (dynamic_cast<Laba6::Owner^>(obj) != nullptr) {
			   return ((Laba6::Owner^)obj)->ownerCode;
		   }
		   else if (dynamic_cast<Car^>(obj) != nullptr) {
			   return ((Car^)obj)->carCode;
		   }
		   else if (dynamic_cast<Registration^>(obj) != nullptr) {
			   return ((Registration^)obj)->registrationCode;
		   }
		   throw gcnew Exception("Не определен тип элемента");
	   }


	   DataGridViewRow^ redactRow = nullptr;



	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (redactRow == nullptr) {
			if (dataGridView1->SelectedRows->Count > 0) {
				// Получаем первую выделенную строку
				redactRow = dataGridView1->SelectedRows[0];
				redactRow->ReadOnly = false;

				button4->Text = "Подтвердить";
			}
		}
		else {
			// Преобразуем DataBoundItem обратно в объект Manufacturer
			Object^ object = redactRow->DataBoundItem;
			RefreshDynamicFields((IDynamicFields^)object, redactRow);
			((IDynamicFields^)object)->getArrayList()[((IDynamicFields^)object)->getID()] = object;
			bool result = XmlWorker::UpdateInXml(filePath, Convert::ToInt64(redactRow->Cells[0]->EditedFormattedValue), object);
			
			if (result)
			{
				log_output->AppendText("Измениение прошло успешно.\r\n");
			}
			else
			{
				log_output->AppendText("Измениение было провалено.\r\n");
			}
			
			redactRow->ReadOnly = true;
			redactRow = nullptr;

			button4->Text = "Изменить";
		}
	}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	selectTable = TableType::Brands;
	ChangeTable();
}


private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	selectTable = TableType::Manufacturers;
	ChangeTable();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	selectTable = TableType::Cars;
	ChangeTable();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	selectTable = TableType::Owners;
	ChangeTable();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	selectTable = TableType::Registrations;
	ChangeTable();
}

	   void ChangeTable() {

		   if (selectTable == TableType::Brands) {
			   label4->Text = "ТАБЛИЦА МАРОК АВТОМОБИЛЕЙ";
			   AddDynamicColumnInDataGridView_2(Brand::DynamicFields);
			   ShowTableBrands();
		   }
		   else if (selectTable == TableType::Manufacturers) {
			   label4->Text = "ТАБЛИЦА ПРОИЗВОДИТЕЛЕЙ";
			   AddDynamicColumnInDataGridView_2(Manufacturer::DynamicFields);
			   ShowTableManufacturers();

		   }
		   else if (selectTable == TableType::Cars) {
			   label4->Text = "ТАБЛИЦА АВТОМОБИЛЕЙ";
			   AddDynamicColumnInDataGridView_2(Car::DynamicFields);

			   ShowTableCars();
		   }
		   else if (selectTable == TableType::Owners) {
			   label4->Text = "ТАБЛИЦА ВЛАДЕЛЬЦЕВ";
			   AddDynamicColumnInDataGridView_2(Laba6::Owner::DynamicFields);

			   ShowTableOwners();
		   }
		   else if (selectTable == TableType::Registrations) {
			   label4->Text = "ТАБЛИЦА РЕГИСТРАЦИЙ";
			   AddDynamicColumnInDataGridView_2(Registration::DynamicFields);

			   ShowTableRegistrations();
		   }

		   //Подбираем размеры для таблицы
		   // Устанавливаем высоту строки и заголовка столбца
		   added_table->Rows[0]->MinimumHeight = (int)(added_table->Height / 2);
		   added_table->ColumnHeadersHeight = (int)(added_table->Height / 2);
	   }
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	DBWorker::ExportAll();
}

	   bool CheckValidate(String^ value, String^ typeField) {
		   try {
			   if (typeField == "INT") {
				   Convert::ToInt32(value);
			   }
			   else if (typeField == "DATE") {
				   DateTime::Parse(value);
			   }
			   else if (typeField == "FLOAT") {
				   Convert::ToSingle(value);
			   }
			   return true;
		   }
		   catch (...) {
			   MessageBox::Show("Стандартное значение не соответствует типу поля");
			   return false;
		   }
		}

	   void AddDynamicColumnInDataGridView_2(List<Tuple<int, String^, String^>^>^ DynamicValues) {
		   dataGridView2->Rows->Clear();
		   for (int i = 0; i < DynamicValues->Count; i++) {
			   Tuple<int, String^, String^>^ var = DynamicValues[i];
			   dataGridView2->Rows->Add();
			   dataGridView2->Rows[i]->Cells[0]->Value = var->Item2;
			   String^ valueForCoboBox = "STRING";
			   if (var->Item1 == (int)FieldType::Integer) {
				   valueForCoboBox = "INT";
			   } 
			   else if (var->Item1 == (int)FieldType::Date) {
				   valueForCoboBox = "DATE";
			   }
			   else if (var->Item1 == (int)FieldType::Float) {
				   valueForCoboBox = "FLOAT";
			   }
			   dataGridView2->Rows[i]->Cells[1]->Value = valueForCoboBox;
			   dataGridView2->Rows[i]->Cells[2]->Value = var->Item3;
		   }
	   }
	   auto GetDynamicFields() {
		   if (selectTable == TableType::Manufacturers)
			   return Manufacturer::DynamicFields;
		   else if (selectTable == TableType::Brands)
			   return Brand::DynamicFields;
		   else if (selectTable == TableType::Cars)
			   return Car::DynamicFields;
		   else if (selectTable == TableType::Owners)
			   return Laba6::Owner::DynamicFields;
		   else if (selectTable == TableType::Registrations)
			   return Registration::DynamicFields;
		   return static_cast<System::Collections::Generic::List<System::Tuple<int, System::String^, System::String^>^>^>(nullptr);
	   }

	   auto GetRecords() {
		   if (selectTable == TableType::Manufacturers)
			   return Manufacturer::manufacturers;
		   else if (selectTable == TableType::Brands)
			   return Brand::brands;
		   else if (selectTable == TableType::Cars)
			   return Car::cars;
		   else if (selectTable == TableType::Owners)
			   return Laba6::Owner::owners;
		   else if (selectTable == TableType::Registrations)
			   return Registration::registrations;

		   return gcnew System::Collections::ArrayList();;
	   }


	   void AddNewField(FieldType type, String^ name, String^ defaultValue) {
		   if (selectTable == TableType::Manufacturers)
			   Manufacturer::AddNewField((int)type, name, defaultValue);
		   else if (selectTable == TableType::Brands)
			   Brand::AddNewField((int)type, name, defaultValue);
		   else if (selectTable == TableType::Cars)
			   Car::AddNewField((int)type, name, defaultValue);
		   else if (selectTable == TableType::Owners)
			   Laba6::Owner::AddNewField((int)type, name, defaultValue);
		   else if (selectTable == TableType::Registrations)
			   Registration::AddNewField((int)type, name, defaultValue);
	   }


private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	auto dynamicFields = GetDynamicFields();
	auto records = GetRecords();

	if (dataGridView2->Rows->Count != 1) {
		// Проверка валидности данных
		for (int i = 0; i < dataGridView2->Rows->Count - 1; i++) {
			if (!CheckValidate(dataGridView2->Rows[i]->Cells[2]->Value->ToString(),
				dataGridView2->Rows[i]->Cells[1]->Value->ToString()))
				return;
		}

		List<String^>^ existingFieldNames = gcnew List<String^>();

		// Проверка на уникальность имен
		for (int i = 0; i < dataGridView2->Rows->Count - 1; i++) {
			String^ nameNewField = dataGridView2->Rows[i]->Cells[0]->Value->ToString();
			if (existingFieldNames->Contains(nameNewField)) {
				MessageBox::Show("Поле с именем \"" + nameNewField + "\" уже существует. Пожалуйста, выберите другое имя.");
				return;
			}
			existingFieldNames->Add(nameNewField);
		}

		// Обобщённые переменные
		

		// Проверка и обновление существующих полей
		for (int i = 0; i < dataGridView2->Rows->Count - 1; i++) {
			if (i > dynamicFields->Count - 1) break;
			String^ nameNewField = dataGridView2->Rows[i]->Cells[0]->Value->ToString();
			String^ typeField = dataGridView2->Rows[i]->Cells[1]->Value->ToString();
			String^ defaultValue = dataGridView2->Rows[i]->Cells[2]->Value->ToString();

			FieldType newType;
			if (typeField == "INT") newType = FieldType::Integer;
			else if (typeField == "STRING") newType = FieldType::String;
			else if (typeField == "DATE") newType = FieldType::Date;
			else if (typeField == "FLOAT") newType = FieldType::Float;

			Tuple<int, String^, String^>^ field = dynamicFields[i];
			String^ currentName = field->Item2;
			int currentType = field->Item1;

			if (currentName == nameNewField) {
				// Проверка типа и обновление значений
				for (int j = 0; j < records->Count; j++) {
					try {
						if (newType == FieldType::Integer)
							Convert::ToInt32(((IDynamicFields^)records[j])->getDynamicValues()[i]);
						else if (newType == FieldType::Date)
							DateTime::Parse(((IDynamicFields^)records[j])->getDynamicValues()[i]);
						else if (newType == FieldType::Float)
							Convert::ToSingle(((IDynamicFields^)records[j])->getDynamicValues()[i]);
					}
					catch (...) {
						((IDynamicFields^)records[j])->getDynamicValues()[i] = defaultValue;
					}
				}
				dynamicFields[i] = gcnew Tuple<int, String^, String^>((int)newType, nameNewField, defaultValue);
			}
			else if (currentType == (int)newType) {
				dynamicFields[i] = gcnew Tuple<int, String^, String^>((int)newType, nameNewField, defaultValue);
			}

		}
	}
		// Добавление или удаление полей
		int additionalFieldsNeeded = dataGridView2->Rows->Count - 1 - dynamicFields->Count;
		if (additionalFieldsNeeded > 0) {
			for (int i = 0; i < additionalFieldsNeeded; i++) {
				String^ nameNewField = dataGridView2->Rows[dynamicFields->Count + i]->Cells[0]->Value->ToString();
				String^ typeField = dataGridView2->Rows[dynamicFields->Count + i]->Cells[1]->Value->ToString();
				FieldType newType = (typeField == "INT") ? FieldType::Integer :
					(typeField == "STRING") ? FieldType::String :
					(typeField == "DATE") ? FieldType::Date : FieldType::Float;

				String^ defaultValue = dataGridView2->Rows[dynamicFields->Count + i]->Cells[2]->Value->ToString();
				AddNewField(newType, nameNewField, defaultValue);
			}
		}
		else if (additionalFieldsNeeded < 0) {
			int removeCount = -additionalFieldsNeeded;
			for (int i = 0; i < removeCount; i++) {
				for each (auto record in records) {
					((IDynamicFields^)record)->getDynamicValues()->RemoveAt(dynamicFields->Count - 1);
				}
				dynamicFields->RemoveAt(dynamicFields->Count - 1);
			}
		}

	ChangeTable();
	// Обновление в XML
	for each (auto record in GetRecords()) {
		XmlWorker::UpdateInXml(filePath, ((IDynamicFields^)record)->getID(), record);
	}
}

	   
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	DBWorker::ImportAll();

	ChangeTable();
}
};

}

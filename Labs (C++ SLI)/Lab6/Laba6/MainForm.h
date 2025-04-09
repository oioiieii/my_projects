#pragma once
#include "classes.h"
#include "XmlWorker.h"

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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->added_table))->BeginInit();
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
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1203, 730);
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

		   List<Manufacturer^>^ list = gcnew List<Manufacturer^>();
		   for each (Manufacturer ^ manufacturer in Manufacturer::manufacturers) {
			   list->Add(gcnew Manufacturer(manufacturer));
		   }

		   BindingList<Manufacturer^>^ bindingList = gcnew BindingList<Manufacturer^>(list);

		   dataGridView1->DataSource = list;
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

		   List<Brand^>^ list = gcnew List<Brand^>();
		   for each (Brand ^ brand in Brand::brands) {
			   
			   list->Add(gcnew Brand(brand, safe_cast<List<Manufacturer^>^>(column3->DataSource)));
		   }

		   BindingList<Brand^>^ bindingList = gcnew BindingList<Brand^>(list);

		   // Привязываем данные
		   dataGridView1->DataSource = bindingList;
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

		   // Создаем список владельцев для привязки к источнику данных
		   List<Laba6::Owner^>^ list = gcnew List<Laba6::Owner^>();
		   for each (Laba6::Owner ^ owner in Laba6::Owner::owners) {
			   list->Add(gcnew Laba6::Owner(owner)); // Преобразуем каждого владельца в объект OwnerInTable
		   }

		   BindingList<Laba6::Owner^>^ bindingList = gcnew BindingList<Laba6::Owner^>(list);

		   // Привязываем данные к dataGridView
		   dataGridView1->DataSource = bindingList;
		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true; // Устанавливаем все строки как доступные только для чтения
		   }
	   }

	   void MainForm::ShowTableCars() {
		   // Очистим существующие столбцы
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

		   // Создаем список автомобилей для привязки к источнику данных
		   List<Laba6::Car^>^ list = gcnew List<Laba6::Car^>();
		   for each (Laba6::Car ^ car in Laba6::Car::cars) {
			   list->Add(gcnew Car(car, safe_cast<List<Brand^>^>(column2->DataSource))); // Преобразуем каждый автомобиль в объект CarInTable
		   }

		   BindingList<Laba6::Car^>^ bindingList = gcnew BindingList<Laba6::Car^>(list);

		   // Привязываем данные к dataGridView
		   dataGridView1->DataSource = bindingList;
		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true; // Устанавливаем все строки как доступные только для чтения
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
		   column4->ReadOnly = true;
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

		   // Создаем список регистраций для привязки к источнику данных
		   List<Laba6::Registration^>^ list = gcnew List<Laba6::Registration^>();
		   for each (Laba6::Registration ^ reg in Laba6::Registration::registrations) {
			   list->Add(gcnew Registration(reg, safe_cast<List<Laba6::Owner^>^>(column2->DataSource), safe_cast<List<Car^>^>(column3->DataSource))); // Преобразуем каждый автомобиль в объект CarInTable
		   }

		   BindingList<Laba6::Registration^>^ bindingList = gcnew BindingList<Laba6::Registration^>(list);

		   // Привязываем данные к dataGridView
		   dataGridView1->DataSource = bindingList;
		   for each (DataGridViewRow ^ row in dataGridView1->Rows) {
			   row->ReadOnly = true; // Устанавливаем все строки как доступные только для чтения
		   }

		   /*DataGridViewComboBoxColumn^ column7 = CreateComboColumn(Laba6::Owner::owners, "Код владельца", "ownerId");
		   column7->Name = "owner1";
		   dataGridView1->Columns->Add(column7);

		   for (int i = 0; i < list->Count; i++) {
			   dataGridView1->Rows[i]->Cells[dataGridView1->ColumnCount - 1]->Value = 0;
		   }*/
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
	
	if (selectTable == TableType::Manufacturers) {
		ShowTableManufacturers();
		ChangeTable();
	}
	else if (selectTable ==TableType::Brands) {
		ShowTableBrands();
		ChangeTable();
	}
	else if (selectTable == TableType::Owners) {
		ShowTableOwners();
		ChangeTable();
	}
	else if (selectTable ==TableType::Cars) {
		ShowTableCars();
		ChangeTable();
	}
	else if (selectTable ==TableType::Registrations) {
		ShowTableRegistrations();
		ChangeTable();
	}
	
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
			Manufacturer^ newManufacturer = gcnew Manufacturer(name, address);
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
			Brand^ newBrand = gcnew Brand(name, manufacturer);
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
			Laba6::Owner^ newOwner = gcnew Laba6::Owner(fullName, address);
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
			Car^ newCar = gcnew Car(brand, chassisNumber, engineNumber);
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
			Registration^ newRegistration = gcnew Registration(owner, car, date);
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
	
	ShowTableBrands();
	selectTable = TableType::Brands;
	ChangeTable();
}



private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	ShowTableManufacturers();
	selectTable = TableType::Manufacturers;
	ChangeTable();
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	ShowTableCars();
	selectTable = TableType::Cars;
	ChangeTable();
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	ShowTableOwners();
	selectTable = TableType::Owners;
	ChangeTable();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	ShowTableRegistrations();
	selectTable = TableType::Registrations;
	ChangeTable();
}

	   void ChangeTable() {
		   if (selectTable == TableType::Brands) {
			   label4->Text = "ТАБЛИЦА МАРОК АВТОМОБИЛЕЙ";
		   }
		   else if (selectTable == TableType::Manufacturers) {
			   label4->Text = "ТАБЛИЦА ПРОИЗВОДИТЕЛЕЙ";
		   }
		   else if (selectTable == TableType::Cars) {
			   label4->Text = "ТАБЛИЦА АВТОМОБИЛЕЙ";
		   }
		   else if (selectTable == TableType::Owners) {
			   label4->Text = "ТАБЛИЦА ВЛАДЕЛЬЦЕВ";
		   }
		   else if (selectTable == TableType::Registrations) {
			   label4->Text = "ТАБЛИЦА РЕГИСТРАЦИЙ";
		   }

		   //Подбираем размеры для таблицы
			// Устанавливаем высоту строки и заголовка столбца
			added_table->Rows[0]->MinimumHeight = (int)(added_table->Height / 2);
			added_table->ColumnHeadersHeight = (int)(added_table->Height / 2);
	   }
};
}

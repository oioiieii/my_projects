#pragma once
#include "classes.h"
#include "XmlWorker.h"


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Collections::Generic;  // добавлено

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
			InitializeData();
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

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ btnAdd;
        System::Windows::Forms::Button^ btnEdit;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::MenuStrip^ menuStrip1;

        // Используем управляемый список вместо неуправляемого вектора
        System::Collections::Generic::List<Manufacturer^>^ manufacturers;  // изменено

        void InitializeComponent(void) {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->btnAdd = (gcnew System::Windows::Forms::Button());
            this->btnEdit = (gcnew System::Windows::Forms::Button());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());

            // Настройка элементов формы
            this->SuspendLayout();

            // dataGridView1
            this->dataGridView1->Location = System::Drawing::Point(12, 36);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(600, 300);
            this->dataGridView1->TabIndex = 0;

            // btnAdd
            this->btnAdd->Location = System::Drawing::Point(12, 350);
            this->btnAdd->Name = L"btnAdd";
            this->btnAdd->Size = System::Drawing::Size(75, 23);
            this->btnAdd->TabIndex = 1;
            this->btnAdd->Text = L"Add";
            this->btnAdd->UseVisualStyleBackColor = true;
            this->btnAdd->Click += gcnew System::EventHandler(this, &Form1::btnAdd_Click);

            // btnEdit
            this->btnEdit->Location = System::Drawing::Point(93, 350);
            this->btnEdit->Name = L"btnEdit";
            this->btnEdit->Size = System::Drawing::Size(75, 23);
            this->btnEdit->TabIndex = 2;
            this->btnEdit->Text = L"Edit";
            this->btnEdit->UseVisualStyleBackColor = true;
            this->btnEdit->Click += gcnew System::EventHandler(this, &Form1::btnEdit_Click);

            // btnDelete
            this->btnDelete->Location = System::Drawing::Point(174, 350);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(75, 23);
            this->btnDelete->TabIndex = 3;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->UseVisualStyleBackColor = true;
            this->btnDelete->Click += gcnew System::EventHandler(this, &Form1::btnDelete_Click);

            // menuStrip1
            this->menuStrip1->Location = System::Drawing::Point(0, 0);
            this->menuStrip1->Name = L"menuStrip1";
            this->menuStrip1->Size = System::Drawing::Size(800, 24);
            this->menuStrip1->TabIndex = 4;
            this->menuStrip1->Text = L"menuStrip1";
            this->menuStrip1->Items->Add("Manufacturers", nullptr, gcnew EventHandler(this, &Form1::menuManufacturers_Click));
            this->menuStrip1->Items->Add("Brands", nullptr, gcnew EventHandler(this, &Form1::menuBrands_Click));

            // Form1
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(800, 450);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->btnAdd);
            this->Controls->Add(this->btnEdit);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->menuStrip1);
            this->MainMenuStrip = this->menuStrip1;
            this->Name = L"Form1";
            this->Text = L"Auto Registration App";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        // Инициализация данных
        void InitializeData() {
            
        }

        // Обновление таблицы
        void updateTable() {
            
        }
        // Обработчики событий
        void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
            
        }

        void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) {
            // Редактирование выделенной записи
        }

        void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
            // Удаление выделенной записи
        }

        void menuManufacturers_Click(System::Object^ sender, System::EventArgs^ e) {
            // Переключение на таблицу Manufacturers
        }

        void menuBrands_Click(System::Object^ sender, System::EventArgs^ e) {
            // Переключение на таблицу Brands
        }

	};
}

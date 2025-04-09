#pragma once
#include "Machine.h"
#include "Cup.h"
#include "Human.h"

#using <mscorlib.dll>
#using <System.dll>
#include <iostream>

using namespace System;
using namespace System::IO;


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
			machine = gcnew CoffeeMachine();
			machine->IndicatorCoffeeChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorCoffeeChanged);
			machine->IndicatorWaterChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorWaterChanged);
			machine->IndicatorCookingChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorCookingChanged);
			machine->WaterChanged += gcnew ResourseChangedHandler(this, &CppCLRWinFormsProject::Form1::OnWaterChanged);
			machine->CoffeeChanged += gcnew ResourseChangedHandler(this, &CppCLRWinFormsProject::Form1::OnCoffeeChanged);
			PictureBoxes = gcnew array<PictureBox^>{Background, BackHand, pctBox_CoffeeMachine, IndicatorCoffee, IndicatorWater, IndicatorMilk, Button, CookingIndicator, pctBox_CoffeeTank, pctBox_WaterTank, pctBox_MilkTank, fixation, pctBox_Cup, FrontHand};
		
		
			human = gcnew Human(machine);
			human->HandMoving += gcnew HandMovingHandler(this, &CppCLRWinFormsProject::Form1::OnHandMoving);
			human->HandEndedMoving += gcnew EndedMovingHandler(this, &CppCLRWinFormsProject::Form1::OnHandEndedMoving);
			Background->BringToFront();
			SettingsPanel->BringToFront();
		}

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ IndicatorWater;
	private: System::Windows::Forms::PictureBox^ IndicatorCoffee;
	private: System::Windows::Forms::PictureBox^ pctBox_Cup;
	private: System::Windows::Forms::PictureBox^ pctBox_CoffeeTank;
	private: System::Windows::Forms::PictureBox^ pctBox_WaterTank;
	private: System::Windows::Forms::PictureBox^ CookingIndicator;
	private: System::Windows::Forms::PictureBox^ Button;

	private:
		CoffeeMachine^ machine;
		Human^ human;
		Cup^ cup;

		bool SelectImprovedMachine = false;

	private: System::Windows::Forms::PictureBox^ BackHand;
	private: System::Windows::Forms::PictureBox^ Background;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pctBox_MilkTank;
	private: System::Windows::Forms::PictureBox^ fixation;
	private: System::Windows::Forms::PictureBox^ IndicatorMilk;
	private: System::Windows::Forms::Panel^ SettingsPanel;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ button3;



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
	private: System::Windows::Forms::PictureBox^ FrontHand;
	private: System::Windows::Forms::PictureBox^ pctBox_CoffeeMachine;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->FrontHand = (gcnew System::Windows::Forms::PictureBox());
			this->pctBox_CoffeeMachine = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pctBox_Cup = (gcnew System::Windows::Forms::PictureBox());
			this->IndicatorCoffee = (gcnew System::Windows::Forms::PictureBox());
			this->IndicatorWater = (gcnew System::Windows::Forms::PictureBox());
			this->pctBox_CoffeeTank = (gcnew System::Windows::Forms::PictureBox());
			this->pctBox_WaterTank = (gcnew System::Windows::Forms::PictureBox());
			this->CookingIndicator = (gcnew System::Windows::Forms::PictureBox());
			this->Button = (gcnew System::Windows::Forms::PictureBox());
			this->BackHand = (gcnew System::Windows::Forms::PictureBox());
			this->Background = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pctBox_MilkTank = (gcnew System::Windows::Forms::PictureBox());
			this->fixation = (gcnew System::Windows::Forms::PictureBox());
			this->IndicatorMilk = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SettingsPanel = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FrontHand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_CoffeeMachine))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_Cup))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorCoffee))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorWater))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_CoffeeTank))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_WaterTank))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CookingIndicator))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Button))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackHand))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_MilkTank))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fixation))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorMilk))->BeginInit();
			this->SettingsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// FrontHand
			// 
			this->FrontHand->BackColor = System::Drawing::Color::Transparent;
			this->FrontHand->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"FrontHand.Image")));
			this->FrontHand->Location = System::Drawing::Point(637, 440);
			this->FrontHand->Name = L"FrontHand";
			this->FrontHand->Size = System::Drawing::Size(184, 127);
			this->FrontHand->TabIndex = 1;
			this->FrontHand->TabStop = false;
			this->FrontHand->LocationChanged += gcnew System::EventHandler(this, &Form1::FrontHand_LocationChanged);
			this->FrontHand->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// pctBox_CoffeeMachine
			// 
			this->pctBox_CoffeeMachine->BackColor = System::Drawing::Color::Transparent;
			this->pctBox_CoffeeMachine->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pctBox_CoffeeMachine.Image")));
			this->pctBox_CoffeeMachine->Location = System::Drawing::Point(264, 306);
			this->pctBox_CoffeeMachine->Name = L"pctBox_CoffeeMachine";
			this->pctBox_CoffeeMachine->Size = System::Drawing::Size(313, 261);
			this->pctBox_CoffeeMachine->TabIndex = 4;
			this->pctBox_CoffeeMachine->TabStop = false;
			this->pctBox_CoffeeMachine->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(42, 447);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 53);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Сделать кофе";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pctBox_Cup
			// 
			this->pctBox_Cup->BackColor = System::Drawing::Color::Transparent;
			this->pctBox_Cup->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pctBox_Cup.Image")));
			this->pctBox_Cup->Location = System::Drawing::Point(384, 398);
			this->pctBox_Cup->Name = L"pctBox_Cup";
			this->pctBox_Cup->Size = System::Drawing::Size(138, 154);
			this->pctBox_Cup->TabIndex = 11;
			this->pctBox_Cup->TabStop = false;
			this->pctBox_Cup->Visible = false;
			this->pctBox_Cup->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// IndicatorCoffee
			// 
			this->IndicatorCoffee->BackColor = System::Drawing::Color::Transparent;
			this->IndicatorCoffee->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IndicatorCoffee.Image")));
			this->IndicatorCoffee->Location = System::Drawing::Point(498, 329);
			this->IndicatorCoffee->Name = L"IndicatorCoffee";
			this->IndicatorCoffee->Size = System::Drawing::Size(21, 21);
			this->IndicatorCoffee->TabIndex = 12;
			this->IndicatorCoffee->TabStop = false;
			this->IndicatorCoffee->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// IndicatorWater
			// 
			this->IndicatorWater->BackColor = System::Drawing::Color::Transparent;
			this->IndicatorWater->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IndicatorWater.Image")));
			this->IndicatorWater->Location = System::Drawing::Point(463, 329);
			this->IndicatorWater->Name = L"IndicatorWater";
			this->IndicatorWater->Size = System::Drawing::Size(22, 21);
			this->IndicatorWater->TabIndex = 11;
			this->IndicatorWater->TabStop = false;
			this->IndicatorWater->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// pctBox_CoffeeTank
			// 
			this->pctBox_CoffeeTank->BackColor = System::Drawing::Color::Transparent;
			this->pctBox_CoffeeTank->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pctBox_CoffeeTank.Image")));
			this->pctBox_CoffeeTank->Location = System::Drawing::Point(454, 143);
			this->pctBox_CoffeeTank->Name = L"pctBox_CoffeeTank";
			this->pctBox_CoffeeTank->Size = System::Drawing::Size(123, 166);
			this->pctBox_CoffeeTank->TabIndex = 13;
			this->pctBox_CoffeeTank->TabStop = false;
			this->pctBox_CoffeeTank->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// pctBox_WaterTank
			// 
			this->pctBox_WaterTank->BackColor = System::Drawing::Color::Transparent;
			this->pctBox_WaterTank->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pctBox_WaterTank.Image")));
			this->pctBox_WaterTank->Location = System::Drawing::Point(264, 143);
			this->pctBox_WaterTank->Name = L"pctBox_WaterTank";
			this->pctBox_WaterTank->Size = System::Drawing::Size(189, 166);
			this->pctBox_WaterTank->TabIndex = 14;
			this->pctBox_WaterTank->TabStop = false;
			this->pctBox_WaterTank->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// CookingIndicator
			// 
			this->CookingIndicator->BackColor = System::Drawing::Color::Transparent;
			this->CookingIndicator->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"CookingIndicator.Image")));
			this->CookingIndicator->Location = System::Drawing::Point(532, 327);
			this->CookingIndicator->Name = L"CookingIndicator";
			this->CookingIndicator->Size = System::Drawing::Size(25, 25);
			this->CookingIndicator->TabIndex = 15;
			this->CookingIndicator->TabStop = false;
			// 
			// Button
			// 
			this->Button->BackColor = System::Drawing::Color::Transparent;
			this->Button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Button.Image")));
			this->Button->Location = System::Drawing::Point(534, 422);
			this->Button->Name = L"Button";
			this->Button->Size = System::Drawing::Size(19, 19);
			this->Button->TabIndex = 16;
			this->Button->TabStop = false;
			// 
			// BackHand
			// 
			this->BackHand->BackColor = System::Drawing::Color::Transparent;
			this->BackHand->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BackHand.Image")));
			this->BackHand->Location = System::Drawing::Point(683, 247);
			this->BackHand->Name = L"BackHand";
			this->BackHand->Size = System::Drawing::Size(184, 141);
			this->BackHand->TabIndex = 17;
			this->BackHand->TabStop = false;
			this->BackHand->Visible = false;
			this->BackHand->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// Background
			// 
			this->Background->BackColor = System::Drawing::Color::Transparent;
			this->Background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Background.Image")));
			this->Background->Location = System::Drawing::Point(-2, 0);
			this->Background->Name = L"Background";
			this->Background->Size = System::Drawing::Size(917, 612);
			this->Background->TabIndex = 18;
			this->Background->TabStop = false;
			this->Background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(42, 321);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 53);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Улучшенная";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pctBox_MilkTank
			// 
			this->pctBox_MilkTank->BackColor = System::Drawing::Color::Transparent;
			this->pctBox_MilkTank->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pctBox_MilkTank.Image")));
			this->pctBox_MilkTank->Location = System::Drawing::Point(204, 235);
			this->pctBox_MilkTank->Name = L"pctBox_MilkTank";
			this->pctBox_MilkTank->Size = System::Drawing::Size(47, 153);
			this->pctBox_MilkTank->TabIndex = 20;
			this->pctBox_MilkTank->TabStop = false;
			this->pctBox_MilkTank->Visible = false;
			this->pctBox_MilkTank->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// fixation
			// 
			this->fixation->BackColor = System::Drawing::Color::Transparent;
			this->fixation->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fixation.Image")));
			this->fixation->Location = System::Drawing::Point(197, 372);
			this->fixation->Name = L"fixation";
			this->fixation->Size = System::Drawing::Size(70, 40);
			this->fixation->TabIndex = 21;
			this->fixation->TabStop = false;
			this->fixation->Visible = false;
			this->fixation->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// IndicatorMilk
			// 
			this->IndicatorMilk->BackColor = System::Drawing::Color::Transparent;
			this->IndicatorMilk->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IndicatorMilk.Image")));
			this->IndicatorMilk->Location = System::Drawing::Point(429, 329);
			this->IndicatorMilk->Name = L"IndicatorMilk";
			this->IndicatorMilk->Size = System::Drawing::Size(22, 21);
			this->IndicatorMilk->TabIndex = 22;
			this->IndicatorMilk->TabStop = false;
			this->IndicatorMilk->Visible = false;
			this->IndicatorMilk->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_Paint);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(42, 262);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(123, 53);
			this->button3->TabIndex = 23;
			this->button3->Text = L"Обычная";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// SettingsPanel
			// 
			this->SettingsPanel->Controls->Add(this->button4);
			this->SettingsPanel->Controls->Add(this->label4);
			this->SettingsPanel->Controls->Add(this->label3);
			this->SettingsPanel->Controls->Add(this->label2);
			this->SettingsPanel->Controls->Add(this->label1);
			this->SettingsPanel->Controls->Add(this->button2);
			this->SettingsPanel->Controls->Add(this->button3);
			this->SettingsPanel->Controls->Add(this->button1);
			this->SettingsPanel->Location = System::Drawing::Point(849, -6);
			this->SettingsPanel->Name = L"SettingsPanel";
			this->SettingsPanel->Size = System::Drawing::Size(195, 607);
			this->SettingsPanel->TabIndex = 24;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(42, 520);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 53);
			this->button4->TabIndex = 30;
			this->button4->Text = L"Выйти";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label4->Location = System::Drawing::Point(19, 149);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(160, 32);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Выбор кофемашины:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label3->Location = System::Drawing::Point(19, 404);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(160, 32);
			this->label3->TabIndex = 28;
			this->label3->Text = L"Действия:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(19, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(160, 107);
			this->label2->TabIndex = 27;
			this->label2->Text = L"Модель работы кофемашины во взаимодействии с человеком";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::Info;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->label1->Location = System::Drawing::Point(24, 199);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(155, 48);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Выбрана обычная кофемашина";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1040, 588);
			this->Controls->Add(this->SettingsPanel);
			this->Controls->Add(this->pctBox_MilkTank);
			this->Controls->Add(this->fixation);
			this->Controls->Add(this->BackHand);
			this->Controls->Add(this->pctBox_CoffeeMachine);
			this->Controls->Add(this->IndicatorMilk);
			this->Controls->Add(this->IndicatorCoffee);
			this->Controls->Add(this->IndicatorWater);
			this->Controls->Add(this->pctBox_CoffeeTank);
			this->Controls->Add(this->pctBox_Cup);
			this->Controls->Add(this->CookingIndicator);
			this->Controls->Add(this->Button);
			this->Controls->Add(this->pctBox_WaterTank);
			this->Controls->Add(this->FrontHand);
			this->Controls->Add(this->Background);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Кофемашина";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->FrontHand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_CoffeeMachine))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_Cup))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorCoffee))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorWater))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_CoffeeTank))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_WaterTank))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->CookingIndicator))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Button))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BackHand))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Background))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pctBox_MilkTank))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fixation))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IndicatorMilk))->EndInit();
			this->SettingsPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	protected:
		void OnIndicatorWaterChanged(bool value) {
			if (value == true) IndicatorWater->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_true.png");
			else IndicatorWater->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_false.png");
		}
		void OnIndicatorCoffeeChanged(bool value) {
			if (value == true) IndicatorCoffee->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_true.png");
			else IndicatorCoffee->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_false.png");
		}
		void OnIndicatorMilkChanged(bool value) {
			if (value == true) IndicatorMilk->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_true.png");
			else IndicatorMilk->Image = Image::FromFile(Application::StartupPath + "/Images/Indicator_false.png");
		}

		void OnIndicatorCookingChanged(bool value) {
			if (value == true) CookingIndicator->Image = Image::FromFile(Application::StartupPath + "/Images/CookingIndicator_true.png");
			else CookingIndicator->Image = Image::FromFile(Application::StartupPath + "/Images/CookingIndicator_false.png");
		}

		void OnWaterChanged(double value) {
			if (value > 75) pctBox_WaterTank->Image = Image::FromFile(Application::StartupPath + "/Images/WaterTank_100.png");
			else if (value > 50) pctBox_WaterTank->Image = Image::FromFile(Application::StartupPath + "/Images/WaterTank_75.png");
			else if (value > 25) pctBox_WaterTank->Image = Image::FromFile(Application::StartupPath + "/Images/WaterTank_50.png");
			else if (value > 0) pctBox_WaterTank->Image = Image::FromFile(Application::StartupPath + "/Images/WaterTank_25.png");
			else pctBox_WaterTank->Image = Image::FromFile(Application::StartupPath + "/Images/WaterTank_0.png");
		}
		void OnCoffeeChanged(double value) {
			if (value > 75) pctBox_CoffeeTank->Image = Image::FromFile(Application::StartupPath + "/Images/CoffeeTank_100.png");
			else if (value > 50) pctBox_CoffeeTank->Image = Image::FromFile(Application::StartupPath + "/Images/CoffeeTank_75.png");
			else if (value > 25) pctBox_CoffeeTank->Image = Image::FromFile(Application::StartupPath + "/Images/CoffeeTank_50.png");
			else if (value > 0) pctBox_CoffeeTank->Image = Image::FromFile(Application::StartupPath + "/Images/CoffeeTank_25.png");
			else pctBox_CoffeeTank->Image = Image::FromFile(Application::StartupPath + "/Images/CoffeeTank_0.png");
		}

		void OnMilkChanged(double value) {
			if (value > 75) pctBox_MilkTank->Image = Image::FromFile(Application::StartupPath + "/Images/MilkTank_100.png");
			else if (value > 50) pctBox_MilkTank->Image = Image::FromFile(Application::StartupPath + "/Images/MilkTank_75.png");
			else if (value > 25) pctBox_MilkTank->Image = Image::FromFile(Application::StartupPath + "/Images/MilkTank_50.png");
			else if (value > 0) pctBox_MilkTank->Image = Image::FromFile(Application::StartupPath + "/Images/MilkTank_25.png");
			else pctBox_MilkTank->Image = Image::FromFile(Application::StartupPath + "/Images/MilkTank_0.png");
		}

		void OnCoffeeInCupChanged(double value, bool haveMilk) {
			if (value == 0) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup.png");
			else if (value < 25) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup_0.png");
			else if (value < 50) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup_25.png");
			else if (value < 75) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup_50.png");
			else if (haveMilk) {
				if (value == 75) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_75.png");
				else if (value == 90) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_90.png"), System::Threading::Thread::Sleep(500);
				else if(value == 100) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_100.png"), System::Threading::Thread::Sleep(1000);
			}
			else {
				if (value < 100) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup_75.png");
				else pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/Cup_100.png");
			}
			Background->Invalidate();
		}
		void OnMilkInCupChanged(double value) {
			if (value < 16) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_75.png");
			else if (value < 18) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_75_1.png");
			else if (value == 20) pctBox_Cup->Image = Image::FromFile(Application::StartupPath + "/Images/CupWithMilk_100.png");

			Background->Invalidate();
		}

		void OnHandMoving(int status, Point^ Loc) {
			switch (status)
			{
			case(1):
				FrontHand->Location = Point(Loc->X - 34, Loc->Y - 68);
				break;
			case(2):
				FrontHand->Location = Point(Loc->X - 14, Loc->Y - 5);
				break;
			case(3):
				FrontHand->Location = Point(Loc->X - 64, Loc->Y - 68);
				break;
			case(4):
				FrontHand->Location = Point(Loc->X - 134, Loc->Y - 54);
				break;
			case(6):
				FrontHand->Location = Point(Loc->X - 52, Loc->Y - 52);
				BackHand->Location = Point(FrontHand->Location.X + 16, FrontHand->Location.Y - 22);
				break;
			case(7):
			case(8):
			case(9):
			case(10):
				MoovingHandsWithTank(Loc, pctBox_WaterTank);
				break;
			case(11):
				FrontHand->Location = Point(Loc->X - 52, Loc->Y - 52);
				BackHand->Location = Point(FrontHand->Location.X + 16, FrontHand->Location.Y - 22);
				break;
			case(12):
				FrontHand->Location = Point(Loc->X - 52, Loc->Y - 52);
				BackHand->Location = Point(FrontHand->Location.X + 16, FrontHand->Location.Y - 22);
				break;
			case(13):
			case(14):
			case(15):
			case(16):
				MoovingHandsWithTank(Loc, pctBox_CoffeeTank);
				break;
			case(18):
				FrontHand->Location = Point(Loc->X - 52, Loc->Y - 52);
				break;
			case(19):
			case(20):
			case(21):
			case(22):
				FrontHand->Location = Point(Loc->X - 37 - 25 +6, Loc->Y - 42 - 10);
				pctBox_MilkTank->Location = Point(Loc->X - 48 / 2 - 25 + 4, Loc->Y - 154 / 2 - 10);
			default:
				break;
			}
			FrontHand->Invalidate();
		}

		void OnHandEndedMoving(int status) {
			switch (status)
			{
			case(0):
				FrontHand->Location = Point(622 - 34, 511 - 68);
				FrontHand->Visible = true;
				FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/HandWithCup.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				break;
			case(1):
				cup = gcnew Cup(machine);
				OnCoffeeInCupChanged(0, 0);
				pctBox_Cup->Visible = true;
				cup->CoffeeInCupChanged += gcnew CoffeeInCupChangedHandler(this, &CppCLRWinFormsProject::Form1::OnCoffeeInCupChanged);
				FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/PointingHand.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				FrontHand->Location = Point(FrontHand->Location.X + 70, FrontHand->Location.Y - 14);
				break;
			case(3):
				if(SelectImprovedMachine) FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/HandWithCup2.png");
				else FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/HandWithCup1.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				FrontHand->Location = Point(FrontHand->Location.X - 134 + 64 + 5, FrontHand->Location.Y - 54 + 68);
				pctBox_Cup->Visible = false;
				break;
			case(4):
				delete cup;
				cup = nullptr;
				break;
			case(5):
				BackHand->Visible = true;
				FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/TakingHand_Left.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				FrontHand->Location = Point(583, 382);
				BackHand->Location = Point(FrontHand->Location.X + 16, FrontHand->Location.Y - 22);
				break;
			case(8):
				OnWaterChanged(100);
				break;
			case(10):
				pctBox_WaterTank->Location = Point(264, 143);
				break;
			case(11):
				FrontHand->Visible = false;
				BackHand->Visible = false;
				break;
			case(14):
				OnCoffeeChanged(100);
				break;
			case(16):
				pctBox_CoffeeTank->Location = Point(454, 143);
				break;
			case(17):
				BackHand->Visible = false;
				break;
			case(18):
				FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/GrippingHand.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				FrontHand->Location = Point(195, 271);
				break;
			case(20):
				OnMilkChanged(100);
				break;
			case(22):
				pctBox_MilkTank->Location = Point(204, 235);
				FrontHand->Image = Image::FromFile(Application::StartupPath + "/Images/TakingHand_Left.png");
				FrontHand->Width = FrontHand->Image->Width;
				FrontHand->Height = FrontHand->Image->Height;
				break;
			default:
				break;
			}
			FrontHand->Invalidate();
		}

		void MoovingHandsWithTank(Point^ Loc, PictureBox^ Tank) {
			int WidthTank = Tank->Width;
			int HeightTank = Tank->Height;
			Tank->Location = Point(Loc->X - WidthTank / 2 - 10, Loc->Y - 166 / 2 - 20);
			FrontHand->Location = Point(Loc->X - 52, Loc->Y - 52);
			BackHand->Location = Point(FrontHand->Location.X + 16, FrontHand->Location.Y - 22);
		}

		void ChangeMachine(bool choice) {
			delete machine;
			if (!choice) {
				machine = gcnew CoffeeMachine();
				
				pctBox_MilkTank->Visible = false;
				fixation->Visible = false;
				IndicatorMilk->Visible = false;
				label1->Text = "Выбрана обычная кофемашина";
			}
			else {
				ImprovedCoffeeMachine^ newMachine = gcnew ImprovedCoffeeMachine();
				machine = newMachine;

				newMachine->MilkChanged += gcnew ResourseChangedHandler(this, &CppCLRWinFormsProject::Form1::OnMilkChanged);
				newMachine->IndicatorMilkChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorMilkChanged);
				
				pctBox_MilkTank->Visible = true;
				fixation->Visible = true;
				IndicatorMilk->Visible = true;
				label1->Text = "Выбрана улучшенная кофемашина";
			}

			//Перезаполнить баки
			OnWaterChanged(100);
			OnMilkChanged(100);
			OnCoffeeChanged(100);

			//Поставить человеку статус 0
			human->ResetStatus();
			FrontHand->Visible = false;
			BackHand->Visible = false;
			pctBox_Cup->Visible = false;

			//Поставить на место баки
			pctBox_CoffeeTank->Location = Point(454, 143);
			pctBox_WaterTank->Location = Point(264, 143);
			pctBox_MilkTank->Location = Point(204, 235);

			//Индикторы сбросить
			OnIndicatorWaterChanged(true);
			OnIndicatorCoffeeChanged(true);
			OnIndicatorMilkChanged(true);
			OnIndicatorCookingChanged(false);

			machine->IndicatorCoffeeChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorCoffeeChanged);
			machine->IndicatorWaterChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorWaterChanged);
			machine->IndicatorCookingChanged += gcnew IndicatorChangedHandler(this, &CppCLRWinFormsProject::Form1::OnIndicatorCookingChanged);
			machine->WaterChanged += gcnew ResourseChangedHandler(this, &CppCLRWinFormsProject::Form1::OnWaterChanged);
			machine->CoffeeChanged += gcnew ResourseChangedHandler(this, &CppCLRWinFormsProject::Form1::OnCoffeeChanged);

			delete cup;
			cup = nullptr;

			Background->Invalidate();
		}
		//Technical
		private:
			array<PictureBox^>^ PictureBoxes;

		System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			PictureBox^ pb1 = (PictureBox^)sender;
			bool flag = true;
			for (int i = 0; i < PictureBoxes->Length; i++) {
				PictureBox^ pb2 = PictureBoxes[i];
				if (pb1 == pb2) {
					flag = false;
					continue;
				}
				if (pb1->Bounds.IntersectsWith(pb2->Bounds) && pb2->Visible) {
					if (flag) {
						pb2->Invalidate();
						
					}
					else {
						// Определяем разницу между верхними границами pb1 и pb2
						int offsetY = pb2->Top - pb1->Top;
						int offsetX = pb2->Left - pb1->Left;

						Image^ image = pb2->Image;
						// Отрисовываем изображение pb2 в области пересечения на pb1
						e->Graphics->DrawImage(image, offsetX, offsetY, image->Width, image->Height);
					}
				}
			}
		}
		   
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			if (cup == nullptr) {
				human->PutCup();
			}
		}

		private: System::Void FrontHand_LocationChanged(System::Object^ sender, System::EventArgs^ e) {
			PictureBox^ pb1 = (PictureBox^)sender;
			for (int i = 0; i < PictureBoxes->Length; i++) {
				PictureBox^ pb2 = PictureBoxes[i];
				pb2->Invalidate();
			}
		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			SelectImprovedMachine = true;
			ChangeMachine(SelectImprovedMachine);
		}
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
			SelectImprovedMachine = false;
			ChangeMachine(SelectImprovedMachine);
		}

		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
			Application::Exit();
		}
};
}

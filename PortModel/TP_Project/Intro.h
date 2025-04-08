#pragma once
#include "Ship.h"
#include <fstream>

public delegate int RestartFormHandler();

namespace TP_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Intro
	/// </summary>

	public ref class Intro : public System::Windows::Forms::Form
	{
	public: RestartFormHandler^ restartForm;
	public:
		Intro(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			// 
			// Создайте экземпляр делегата и привяжите его к методу, который будет обрабатывать событие Paint для PictureBox
			handler = gcnew PictureBoxPaintHandler(this, &Intro::pictureBox_Paint);
			

			//Создание путей
			Path::All_Paths = gcnew array<Path^>{ //Массив путей инициализация
				gcnew Path(gcnew array<Point> {Point(532, 0), Point(514, 143), Point(516, 327), Point(608, 514)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_0)),
				gcnew Path(gcnew array<Point> {Point(703, 727), Point(723, 873), Point(966, 923), Point(1043, 931), /*Point(1078, 930),*/ Point(1120, 931)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_1)),
				gcnew Path(gcnew array<Point> {Point(1449,931),/*Point(1449, 918),*/ Point(1430, 663)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_2)),
				gcnew Path(gcnew array<Point> {Point(1238, 461), Point(1152, 322), Point(1120, 194), Point(1103, -500)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_3)), // путь на выход
				// Пути для круизных кораблей
				gcnew Path(gcnew array<Point> {Point(375, 0), Point(362, 131), Point(352, 274), Point(372, 461)/*, Point(459, 570)*/}, gcnew FinishPathHandler(this, &Intro::Finish_Path_4)),
				gcnew Path(gcnew array<Point> {Point(599, 760), Point(600, 899), Point(600, 951)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_5)),
				gcnew Path(gcnew array<Point> {Point(479, 850), Point(477, 930)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_6)),
				gcnew Path(gcnew array<Point> {Point(598, 800), Point(552, 737), Point(773, 741), Point(844, 703)/*, Point(1066, 534), Point(1125, 205)*/}, gcnew FinishPathHandler(this, &Intro::Finish_Path_7)),
				gcnew Path(gcnew array<Point> {Point(481, 802), Point(481, 734), Point(439, 682), Point(668, 736), Point(902, 688)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_8)),
				gcnew Path(gcnew array<Point> {Point(1032, 581), Point(1098, 443), Point(1131, 264), Point(1179, 56), Point(1194, -500)}, gcnew FinishPathHandler(this, &Intro::Finish_Path_9)/*, gcnew FinishPathHandler(this, &Intro::Finish_Path_7)*/),
			};
			//Инициализация статически
			Transport::frm = this;
			Transport::All_PictureBox = gcnew array<PictureBox^>(1);
			port = gcnew Port(this, pictureBox4, pictureBox5);
			//port->dock->cran->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TP_Project::Intro::pictureBox_Paint);
			Transport::handler = handler;
			
			Ship::All_Ships = gcnew array<Transport^>{};
			CarTech::All_CarsTech = gcnew array<Transport^>{};
			Car::All_Cars = gcnew array<Transport^>{};
			
			CarTech::current_ID = 0;
			Ship::current_ID = 0;

		}

	private:

	#pragma region Finish Paths declaration code
		void Finish_Path_0(Object^ sender);
		void Finish_Path_1(Object^ sender);
		void Finish_Path_2(Object^ sender);
		void Finish_Path_3(Object^ sender);

		void Finish_Path_4(Object^ sender);
		void Finish_Path_5(Object^ sender);
		void Finish_Path_6(Object^ sender);
		void Finish_Path_7(Object^ sender);
		void Finish_Path_8(Object^ sender);
		void Finish_Path_9(Object^ sender);
#pragma endregion

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Intro()
		{
			
			if (components)
			{
				delete components;
			}
			//Может стоит держать статические переменные в классе здесь, а не там
		}

	protected:







	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::TrackBar^ trackBar2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;









	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TrackBar^ trackBar3;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;



	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Timer^ timerClosing;

private: System::Windows::Forms::PictureBox^ pictureBox4;
private: System::Windows::Forms::PictureBox^ pictureBox5;
private: System::Windows::Forms::Timer^ timerCarRoad;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Panel^ panel1;
private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::TrackBar^ trackBar4;










	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Intro::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->trackBar3 = (gcnew System::Windows::Forms::TrackBar());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->timerClosing = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->timerCarRoad = (gcnew System::Windows::Forms::Timer(this->components));
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trackBar4 = (gcnew System::Windows::Forms::TrackBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Intro::timer1_Tick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(1672, 309);
			this->trackBar1->Maximum = 20;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->trackBar1->Size = System::Drawing::Size(227, 45);
			this->trackBar1->TabIndex = 5;
			this->trackBar1->Value = 10;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Intro::trackBar1_Scroll);
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(32, 32);
			this->trackBar2->Maximum = 1;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(207, 45);
			this->trackBar2->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Location = System::Drawing::Point(9, 69);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(100, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Грузовой";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label5->Location = System::Drawing::Point(174, 69);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 17);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Круизный";
			// 
			// label9
			// 
			this->label9->BackColor = System::Drawing::Color::Black;
			this->label9->Font = (gcnew System::Drawing::Font(L"Woodstick", 25));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(1630, -1);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(292, 63);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Настройки";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Woodstick", 15));
			this->label7->Location = System::Drawing::Point(1643, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(276, 45);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Настройки времени:";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Black;
			this->label10->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label10->Font = (gcnew System::Drawing::Font(L"Sosa", 40));
			this->label10->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label10->Location = System::Drawing::Point(1824, 153);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(78, 55);
			this->label10->TabIndex = 12;
			this->label10->Text = L"N";
			this->label10->Click += gcnew System::EventHandler(this, &Intro::label10_Click);
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label11->Location = System::Drawing::Point(1668, 159);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(148, 42);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Сменить состояние";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label12->Location = System::Drawing::Point(1723, 268);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(124, 20);
			this->label12->TabIndex = 8;
			this->label12->Text = L"скорость :";
			// 
			// label13
			// 
			this->label13->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label13->Location = System::Drawing::Point(1796, 167);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(11, 20);
			this->label13->TabIndex = 8;
			this->label13->Text = L":";
			// 
			// label14
			// 
			this->label14->Font = (gcnew System::Drawing::Font(L"Woodstick", 15));
			this->label14->Location = System::Drawing::Point(54, 17);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(201, 45);
			this->label14->TabIndex = 12;
			this->label14->Text = L"Добавление объекта:";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// trackBar3
			// 
			this->trackBar3->Location = System::Drawing::Point(39, 131);
			this->trackBar3->Maximum = 1;
			this->trackBar3->Name = L"trackBar3";
			this->trackBar3->Size = System::Drawing::Size(207, 45);
			this->trackBar3->TabIndex = 6;
			this->trackBar3->Scroll += gcnew System::EventHandler(this, &Intro::trackBar3_Scroll);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label15->Location = System::Drawing::Point(15, 170);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(89, 17);
			this->label15->TabIndex = 8;
			this->label15->Text = L"Корабль";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label16->Location = System::Drawing::Point(187, 170);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(84, 17);
			this->label16->TabIndex = 8;
			this->label16->Text = L"Машина";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label17->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label17->Location = System::Drawing::Point(74, 94);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(153, 20);
			this->label17->TabIndex = 8;
			this->label17->Text = L"Тип объекта:";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label18->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label18->Location = System::Drawing::Point(65, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(150, 20);
			this->label18->TabIndex = 8;
			this->label18->Text = L"Вид корабля:";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::IndianRed;
			this->button3->Font = (gcnew System::Drawing::Font(L"Woodstick", 22));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(1686, 976);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(185, 59);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Выход";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Intro::button3_Click);
			// 
			// timerClosing
			// 
			this->timerClosing->Interval = 1000;
			this->timerClosing->Tick += gcnew System::EventHandler(this, &Intro::timerClosing_Tick);
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->pictureBox4->Location = System::Drawing::Point(545, 915);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(20, 176);
			this->pictureBox4->TabIndex = 15;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->pictureBox5->Location = System::Drawing::Point(515, 915);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(20, 176);
			this->pictureBox5->TabIndex = 15;
			this->pictureBox5->TabStop = false;
			// 
			// timerCarRoad
			// 
			this->timerCarRoad->Enabled = true;
			this->timerCarRoad->Tick += gcnew System::EventHandler(this, &Intro::timerCarRoad_Tick);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->button5->Font = (gcnew System::Drawing::Font(L"Woodstick", 22));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(42, 397);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(229, 59);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Добавить";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Intro::Spawn_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->label17);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->label15);
			this->panel1->Controls->Add(this->trackBar3);
			this->panel1->Location = System::Drawing::Point(1629, 408);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(291, 537);
			this->panel1->TabIndex = 16;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label1);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->trackBar4);
			this->panel3->Location = System::Drawing::Point(9, 238);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(291, 99);
			this->panel3->TabIndex = 14;
			this->panel3->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Woodstick", 13));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(65, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(149, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Вид машины:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label2->Location = System::Drawing::Point(169, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Легковая";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Woodstick", 12));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Location = System::Drawing::Point(9, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Грузовая";
			// 
			// trackBar4
			// 
			this->trackBar4->Location = System::Drawing::Point(32, 32);
			this->trackBar4->Maximum = 1;
			this->trackBar4->Name = L"trackBar4";
			this->trackBar4->Size = System::Drawing::Size(207, 45);
			this->trackBar4->TabIndex = 6;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label18);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->trackBar2);
			this->panel2->Location = System::Drawing::Point(9, 238);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(277, 99);
			this->panel2->TabIndex = 13;
			// 
			// Intro
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1920, 1080);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->trackBar1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"Intro";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"b";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Intro::Intro_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Intro::Intro_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Intro::Intro_MouseClick);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar4))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	PictureBoxPaintHandler^ handler;
	Ship^ SelectedShip = nullptr;
	array<PictureBox^>^ All_PictureBox;
	Port^ port;

	private: System::Void Intro_Load(System::Object^ sender, System::EventArgs^ e) {
		All_PictureBox = gcnew array<PictureBox^>(1);
	
		ShipCargo^ ship = gcnew ShipCargo(Point(532, -100), 0);
		Ship^ ship1 = gcnew Ship(Point(375, -100), 1);
		Ship^ ship3 = gcnew Ship(Point(375, -100), 1);
		ShipCargo^ ship2 = gcnew ShipCargo(Point(532, -1000), 0);

		SelectedShip = ship1;
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = CreateGraphics();
		g->FillEllipse(Brushes::Red, 1258 - 5, 195 - 5, 10, 10); // Красная точка 10x10 пикселей с центром в координатах нажатия
		
		if (timer1->Enabled) timer1->Enabled = false;
		else timer1->Enabled = true;
	}

	   void CalculateTime(int milliseconds, Label^ label) {
		   int seconds = milliseconds / 1000;
		   int minutes = seconds / 60;
		   seconds %= 60;

		   String^ formattedTime = String::Format("{0:D2}:{1:D2}", minutes, seconds);
		   label->Text = formattedTime;
	   }

private: int GlobalTime = 0;
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (Ship::timeSpawn <= 0) {
		gcnew Ship(Point(375, -100), 0);
	}
	else {
		Ship::timeSpawn -= 100;
	}
	if (ShipCargo::timeSpawn <= 0) {
		gcnew ShipCargo(Point(532, -100), 0);
	}
	else {
		ShipCargo::timeSpawn -= 100;
	}
	if (Car::timeSpawn <= 0) {
		gcnew Car();
	}
	else {
		Car::timeSpawn -= 100;
	}

	for (int i = 0; i < Ship::All_Ships->Length; i++)
		{
			Ship::All_Ships[i]->moving();
		}
	
}		

private: System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		   PictureBox^ pb1 = (PictureBox^)sender;

		   for (int i = 0; i < Transport::All_PictureBox->Length; ++i) {
			   PictureBox^ pb2 = Transport::All_PictureBox[i];

			   if (pb1 != pb2 && pb1->Bounds.IntersectsWith(pb2->Bounds)) {
				   // Определяем разницу между верхними границами pb1 и pb2
				   int offsetY = pb2->Top - pb1->Top;
				   int offsetX = pb2->Left - pb1->Left;

				   Image^ image = pb2->Image;
				   // Отрисовываем изображение pb2 в области пересечения на pb1
				   e->Graphics->DrawImage(image, offsetX, offsetY, image->Width, image->Height);
			   }
		   }
	   }
private: System::Void Intro_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	// Получаем текущие координаты мыши
	int mouseX = e->X;
	int mouseY = e->Y;
	SelectedShip->CurrentPath->AddPoint(mouseX, mouseY);

	// Рисуем красную точку на месте нажатия
	Graphics^ g = CreateGraphics();
	g->FillEllipse(Brushes::Red, mouseX - 5, mouseY - 5, 10, 10); // Красная точка 10x10 пикселей с центром в координатах нажатия

	//// Указываем путь к файлу
	String^ filePath = "C:/Users/romas/OneDrive/Рабочий стол/coordinates.txt";

	//// Преобразуем тип String^ в const wchar_t* для использования в WinAPI функциях
	const wchar_t* filePathPtr = (const wchar_t*)(System::Runtime::InteropServices::Marshal::StringToHGlobalUni(filePath)).ToPointer();

	//// Открываем файл для записи
	std::ofstream outFile(filePathPtr, std::ios::app);

	//// Записываем координаты в файл
	if (outFile.is_open()) {
		outFile << "Point(" << mouseX << ", " << mouseY << "),";
		outFile.close();
	}
	else {
		MessageBox::Show("Ошибка при открытии файла!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	//// Освобождаем выделенную память после использования
	System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)filePathPtr));
}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = true;
	timer1->Interval =  10 * trackBar1->Value;
	port->dock->timerCran->Interval =  10 * trackBar1->Value;
	timerCarRoad->Interval = 10 * trackBar1->Value;
	port->berth1->timer->Interval = 20 * trackBar1->Value;
	port->berth2->timer->Interval = 20 * trackBar1->Value;
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

//Кнопка для паузы
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	if (timer1->Enabled) timer1->Enabled = false,  timerCarRoad->Enabled = false, port->dock->timerCran->Enabled = false, port->berth1->timer->Enabled = false, port->berth2->timer->Enabled = false, label10->Text = "N";
	else {
		timer1->Enabled = true, timerCarRoad->Enabled = true, port->dock->timerCran->Enabled = true, label10->Text = "O";
		if (port->berth1->flagBerthWasOn) port->berth1->timer->Enabled = true;
		if (port->berth2->flagBerthWasOn) port->berth2->timer->Enabled = true;
	}
	
}

private: System::Void Refresh_Click(System::Object^ sender, System::EventArgs^ e) {
	restartForm();
}

private: System::Void Intro_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	//Запустим таймер на уничтожение
	if (!timerClosing->Enabled && e->CloseReason != CloseReason::ApplicationExitCall) {
		e->Cancel = true, timerClosing->Enabled = true;
		timer1->Enabled = false;
		port->dock->timerCran->Enabled = false;
	}
	}

private: System::Void timerClosing_Tick(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	delete this;
}
	



	   
private: System::Void timerCarRoad_Tick(System::Object^ sender, System::EventArgs^ e) {
	for (int i = 0; i < Car::All_Cars->Length; i++)
	{
		Car::All_Cars[i]->moving();
	}
}
private: System::Void Spawn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (trackBar3->Value == 0) {
		if (trackBar2->Value == 0) gcnew ShipCargo(Point(532, -120), 0);
		else gcnew Ship(Point(375, -100), 0);
	}
	else {
		if (trackBar4->Value == 0) gcnew CarTech(Point(949, 1109), gcnew FinishPathHandler(port->dock, &Port::Dock::TechCarReady)), port->dock->timerCran->Enabled = true;
		else gcnew Car();
	}
}
private: System::Void trackBar3_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (trackBar3->Value == 0) panel2->Visible = true, panel3->Visible = false;
	else if (trackBar3->Value == 1) panel3->Visible = true, panel2->Visible = false;
}
};

	
}

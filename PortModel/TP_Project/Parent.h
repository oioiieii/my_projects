#pragma once
#include "Intro.h"
//#include <Windows.h>


namespace TP_Project {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace TP_Project;
	
	ref class Main
	{
	public:
		int restartForm() {
			Intro^ form = gcnew Intro;
			form->restartForm = gcnew RestartFormHandler(this, &Main::restartForm);
			form->Show();
			TecForm->Close();
			TecForm = form;
			return 0;
		}
	public:
		Main()
		{
			Intro^ form = gcnew Intro;
			form->restartForm = gcnew RestartFormHandler(this, &Main::restartForm);
			TecForm = form; 
			form->Show();
		}
	private:

		Intro^ TecForm;
	};
}

#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "Parent.h"

using namespace System::Windows::Forms;


[STAThread]


int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TP_Project::Main^ parentForm = gcnew TP_Project::Main;
	Application::Run();
	return 0;
}


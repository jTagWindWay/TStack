#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()   //array<String^>^ args
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Calc::MyForm form;
	Application::Run(%form);
}


//#include "MyForm.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//
//[STAThreadAttribute]
//void main() {
//	Application::EnableVisualStyles();
//	Application::SetCompatibleTextRenderingDefault(false);
//	Calc::MyForm form;
//	Application::Run(%form);
//}

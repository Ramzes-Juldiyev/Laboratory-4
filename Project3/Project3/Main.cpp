#include "MyForm.h"
#include "Function.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project3::MyForm form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}

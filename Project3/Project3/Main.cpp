#include "MyForm.h"
#include "Function.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Project3::MyForm form; //WinFormsTest - ��� ������ �������
    Application::Run(% form);
}

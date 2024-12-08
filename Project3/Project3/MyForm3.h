#pragma once
#include "Function.h"
#include "Class.h"
namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;


	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(346, 211);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 81);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Get total sales of all tickets";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(204, 211);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 81);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Get total sales by passenger";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(301, 169);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(183, 175);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Passport Number";
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 500);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm3";
			this->Text = L"MyForm3";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Airport& airport = Airport::getInstance();
		double totalSales = airport.getTotalSales();
		System::Windows::Forms::MessageBox::Show("Total sales: " + totalSales);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			System::String^ PassportNumber = textBox1->Text;
			string passportNumber = SystemToStl(PassportNumber);
			if (passportNumber.length() > 1) {
				System::Windows::Forms::MessageBox::Show("Total sales by passenger:" +" " + getTotalSales(passportNumber));
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("Error");
			}
		}
		catch (const std::exception&)
		{
			System::Windows::Forms::MessageBox::Show("error");
		}

	}
		   string SystemToStl(String^ s)
		   {
			   using namespace Runtime::InteropServices;
			   const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			   return string(ptr);
		   }
	};
}

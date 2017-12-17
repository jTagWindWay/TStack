#pragma once
#include <string>
#include <iostream>
#include "..\TStack\TCalculator.h"
#include "..\TStack\TCalculator.cpp"
#include "..\TStack\TStack.h"
//#include "stdafx.h"
#include <msclr\marshal_cppstd.h>

using namespace std;

namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  RESULT;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;

	protected:

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
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->RESULT = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(59, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"INFIX\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(50, 136);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"POSTFIX";
			this->label2->UseWaitCursor = true;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(242, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"=";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// RESULT
			// 
			this->RESULT->Location = System::Drawing::Point(432, 78);
			this->RESULT->Name = L"RESULT";
			this->RESULT->Size = System::Drawing::Size(153, 28);
			this->RESULT->TabIndex = 3;
			this->RESULT->Text = L"RESULT";
			this->RESULT->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 67);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(33, 163);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(413, 109);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(625, 313);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->RESULT);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		TCalculator STR;
		String ^ s = Convert::ToString(textBox1->Text);
		msclr::interop::marshal_context context;
		string str = context.marshal_as<string>(s);
			STR.setInfix(str);
			STR.toPostfix();
		string POSTFIX = STR.GetPostfix();	                                                                                      //	msclr::interop::marshal_context context;	//	string str = context.marshal_as<string>(s);
		String^ FINAL_POSTFIX = gcnew String(POSTFIX.c_str());

		textBox3->Text = Convert::ToString(STR.Calculation());
		textBox2->Text = Convert::ToString(FINAL_POSTFIX);
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}


 //private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	// double err = Convert::ToDouble(textBox1->Text);
	// int task = 2, numb_iter, N, M;
	// N = Convert::ToInt32(textBox3->Text);
	// M = Convert::ToInt32(textBox4->Text);
	// numb_iter = Convert::ToInt32(textBox2->Text);
	// if (comboBox1->Text == "Задача 1") task = 1;

	// tsk::init_task(task, N, M, err);
	// slt::init_solve(numb_iter);

	// button3_Click(sender, e);

	// for (int j = 0; j <= tsk::N; j++) {
	//	 dataGridView1->Rows->Add();
	//	 for (int i = 0; i <= tsk::M; i++)
	//		 dataGridView1->Rows[j]->Cells[i]->Value = Convert::ToString(slt::read_result(j, i));
	// }

	// for (int j = 0; j <= tsk::N; j++) {
	//	 dataGridView2->Rows->Add();
	//	 for (int i = 0; i <= tsk::M; i++)
	//		 dataGridView2->Rows[j]->Cells[i]->Value = Convert::ToString(slt::f_(j, i));
	// }
 //}

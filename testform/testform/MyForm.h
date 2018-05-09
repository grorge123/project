#pragma once
#include<iostream>
#include<stack>
namespace testform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(104, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(931, 63);
			this->label1->TabIndex = 0;
			this->label1->Text = L"目前:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(104, 142);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(112, 68);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(104, 142);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(112, 68);
			this->button2->TabIndex = 1;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(243, 142);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(112, 68);
			this->button3->TabIndex = 2;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(392, 142);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(112, 68);
			this->button4->TabIndex = 3;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(104, 246);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(112, 68);
			this->button5->TabIndex = 4;
			this->button5->Text = L"4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button6->Location = System::Drawing::Point(243, 246);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(112, 68);
			this->button6->TabIndex = 5;
			this->button6->Text = L"5";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button7->Location = System::Drawing::Point(392, 246);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(112, 68);
			this->button7->TabIndex = 6;
			this->button7->Text = L"6";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button8->Location = System::Drawing::Point(104, 356);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(112, 68);
			this->button8->TabIndex = 7;
			this->button8->Text = L"7";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button9->Location = System::Drawing::Point(243, 356);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(112, 68);
			this->button9->TabIndex = 8;
			this->button9->Text = L"8";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button10->Location = System::Drawing::Point(392, 356);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(112, 68);
			this->button10->TabIndex = 9;
			this->button10->Text = L"9";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button11->Location = System::Drawing::Point(693, 142);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(112, 68);
			this->button11->TabIndex = 10;
			this->button11->Text = L"+";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button12->Location = System::Drawing::Point(693, 216);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(112, 68);
			this->button12->TabIndex = 11;
			this->button12->Text = L"-";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button13->Location = System::Drawing::Point(826, 142);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(112, 68);
			this->button13->TabIndex = 12;
			this->button13->Text = L"*";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button14->Location = System::Drawing::Point(826, 216);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(112, 68);
			this->button14->TabIndex = 13;
			this->button14->Text = L"/";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button15->Location = System::Drawing::Point(693, 320);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(112, 68);
			this->button15->TabIndex = 14;
			this->button15->Text = L"(";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button16->Location = System::Drawing::Point(826, 320);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(112, 68);
			this->button16->TabIndex = 15;
			this->button16->Text = L")";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button17->Location = System::Drawing::Point(923, 535);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(112, 68);
			this->button17->TabIndex = 16;
			this->button17->Text = L"=";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 615);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	String^ infix;
	String^ postfix;
	char __use(int le, int ri) {
		const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(infix)).ToPointer();
		std::string s = chars, out;
		int c = 0;
		for (int i = ri - 1; i >= le; i--) {//後加減，先遞迴 
			if (s[i] == ')') c++;    //括弧內部分割      
			if (s[i] == '(') c--;
			if (s[i] == '+' && c == 0) { //後加減，先遞迴 
				return __use(le, i) + __use(i + 1, ri);
			}
			if (s[i] == '-' && c == 0) {
				return __use(le, i) - __use(i + 1, ri);
			}
		}
		for (int i = ri - 1; i >= le; i--) { //先乘除，後遞迴 
			if (s[i] == ')') c++;    //括弧內部分割      
			if (s[i] == '(') c--;
			if (s[i] == '*' && c == 0) { //先乘除，後遞迴 
				return __use(le, i)*__use(i + 1, ri);
			}
			if (s[i] == '/' && c == 0) {
				return __use(le, i) / __use(i + 1, ri);
			}
			if (s[i] == '%' && c == 0) {
				return __use(le, i) % __use(i + 1, ri);
			}
		}
		if ((s[le] == '(') && (s[ri - 1] == ')')) return __use(le + 1, ri - 1);  //去除刮號
		if (s[le] == ' ' &&s[ri - 1] == ' ') return  __use(le + 1, ri - 1); //去除左右兩邊空格 
		if (s[le] == ' ') return  __use(le + 1, ri); //去除左邊空格 
		if (s[ri - 1] == ' ') return  __use(le, ri - 1); //去除右邊空格
		int num = 0;
		if (isdigit(s[le]) && isdigit(s[ri - 1])) {//轉成數字 
			for (int i = le; i<ri; i++) num = num * 10 + s[i] - '0';
			return num;
		}
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "1";
		this->label1->Text = L"目前:"+infix;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "2";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "3";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "4";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "5";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "6";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "7";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "8";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "9";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "+";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "-";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "*";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "/";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += "(";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
		infix += ")";
		this->label1->Text = L"目前:" + infix;
	}
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
		this->label1->Text = L"目前:" + char(__use(0,infix->Length));
		infix = "";
	}
};
}

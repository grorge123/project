#include "stdafx.h"
#include "MyForm.h"

using namespace testform;
int main() {
	//�u�Ƭɭ�
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//����GUI
	Application::Run(gcnew MyForm());
	return 0;
}
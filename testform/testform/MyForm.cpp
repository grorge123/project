#include "stdafx.h"
#include "MyForm.h"

using namespace testform;
int main() {
	//優化界面
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//執行GUI
	Application::Run(gcnew MyForm());
	return 0;
}
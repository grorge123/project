#include "stdafx.h"
#include "MyForm.h"

using namespace testform;
int main() {
	//優化gui
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//開啟gui
	Application::Run(gcnew MyForm());
	return 0;
}

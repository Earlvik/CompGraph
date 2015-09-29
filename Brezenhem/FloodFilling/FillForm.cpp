#include "FillForm.h"
#include "Windows.h"

using namespace FloodFilling;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew FillForm);
	return 0;
}

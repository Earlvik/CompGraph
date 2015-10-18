#include "PyramidForm.h"
#include "Windows.h"

using namespace Pyramid;
[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PyramidForm);
	return 0;
}


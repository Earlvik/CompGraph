#pragma once
using namespace System::Drawing;

ref class Line
{
private:
	Point start, finish;
public:
	Line(Point start, Point finish);
	Point Start();
	Point Finish();
};


#include "Line.h"


Line::Line(Point start, Point finish)
{
	this->start = start;
	this->finish = finish;
}

Point Line::Start()
{
	return start;
}

Point Line::Finish()
{
	return finish;
}

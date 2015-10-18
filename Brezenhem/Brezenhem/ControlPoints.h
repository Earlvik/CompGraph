namespace Bezier
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Drawing;

	ref class ControlPoints {
	private:
		array<Point>^ points = gcnew array<Point>(4);
	public:
		ControlPoints(array<Point>^ points) {
			if (points->Length != 4)
			{
				throw gcnew ArgumentException("Not four control poins");
			}
			this->points = points;
		}

		Point Get(int i)
		{
			return points[i];
		}
	};
}
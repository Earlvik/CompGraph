#pragma once
// Трехмерная точка
namespace Pyramid {
	ref class Point3d
	{
	public:
		int X;
		int Y;
		int Z;
		Point3d(int x, int y, int z)
		{
			X = x;
			Y = y;
			Z = z;
		}
	};
}

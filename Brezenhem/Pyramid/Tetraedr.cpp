#include "Tetraedr.h"

using namespace Pyramid;

Tetraedr^ Tetraedr::ToScreen()
{
	Tetraedr^ result = gcnew Tetraedr();
	result->sides = this->sides;
	Matrix^ toScreen = gcnew Matrix(4, 4);
	toScreen->Zero();
	toScreen->Set(0, 0, 1);
	toScreen->Set(1, 1, 1);
	toScreen->Set(3, 3, 1);
	result->vertices = this->vertices->Multiply(toScreen);
	return result;
}

Tetraedr^ Tetraedr::CenterProjection(double x0, double y0, double z0)
{
	if (z0 == 0)
	{
		return ToScreen();
	}
	Tetraedr^ result = gcnew Tetraedr();
	result->sides = this->sides;
	Matrix^ toScreen = gcnew Matrix(4, 4);
	toScreen->Zero();
	toScreen->Set(0, 0, 1);
	toScreen->Set(1, 1, 1);
	toScreen->Set(3, 3, 1);
	toScreen->Set(2, 3, -1.0 / z0);
	result->vertices = this->vertices->Multiply(toScreen);
	result->Move(x0, y0, 0);
	result->vertices->Norm();
	return result;
}

System::Void Tetraedr::Move(double dx, double dy, double dz)
{
	Matrix^ movingMatrix = gcnew Matrix(4, 4);
	movingMatrix->Zero();
	movingMatrix->Set(0, 0, 1);
	movingMatrix->Set(1, 1, 1);
	movingMatrix->Set(2, 2, 1);
	movingMatrix->Set(3, 3, 1);
	movingMatrix->Set(3, 0, dx);
	movingMatrix->Set(3, 1, dy);
	movingMatrix->Set(3, 2, dz);
	this->vertices = this->vertices->Multiply(movingMatrix);
	this->vertices->Norm();
}

System::Void Tetraedr::MoveX(double d)
{
	Move(d, 0, 0);
}
System::Void Tetraedr::MoveY(double d)
{
	Move(0, d, 0);
}
System::Void Tetraedr::MoveZ(double d)
{
	Move(0, 0, d);
}

System::Void Tetraedr::Scale(double s)
{
	Offset();
	Matrix^ movingMatrix = gcnew Matrix(4, 4);
	movingMatrix->Zero();
	movingMatrix->Set(0, 0, s);
	movingMatrix->Set(1, 1, s);
	movingMatrix->Set(2, 2, s);
	movingMatrix->Set(3, 3, 1);
	this->vertices = this->vertices->Multiply(movingMatrix);
	this->vertices->Norm();
	DeOffset();
}

System::Void Tetraedr::Rotate(double rx, double ry, double rz, bool offset)
{
	if (offset)
	{
		Offset();
	}
	
	double sinX = Math::Sin(rx);
	double cosX = Math::Cos(rx);
	double sinY = Math::Sin(ry);
	double cosY = Math::Cos(ry);
	double sinZ = Math::Sin(rz);
	double cosZ = Math::Cos(rz);

	Matrix^ xMatrix = gcnew Matrix(4, 4);
	xMatrix->Zero();
	xMatrix->Set(0, 0, 1);
	xMatrix->Set(1, 1, cosX);
	xMatrix->Set(2, 2, cosX);
	xMatrix->Set(3, 3, 1);
	xMatrix->Set(1, 2, sinX);
	xMatrix->Set(2, 1, -sinX);

	Matrix^ yMatrix = gcnew Matrix(4, 4);
	yMatrix->Zero();
	yMatrix->Set(0, 0, cosY);
	yMatrix->Set(1, 1, 1);
	yMatrix->Set(2, 2, cosY);
	yMatrix->Set(3, 3, 1);
	yMatrix->Set(0, 2, -sinY);
	yMatrix->Set(2, 0, sinY);

	Matrix^ zMatrix = gcnew Matrix(4, 4);
	zMatrix->Zero();
	zMatrix->Set(0, 0, cosZ);
	zMatrix->Set(1, 1, cosZ);
	zMatrix->Set(2, 2, 1);
	zMatrix->Set(3, 3, 1);
	zMatrix->Set(0, 1, sinZ);
	zMatrix->Set(1, 0, -sinZ);

	this->vertices = this->vertices->Multiply(xMatrix);
	this->vertices = this->vertices->Multiply(yMatrix);
	this->vertices = this->vertices->Multiply(zMatrix);
	this->vertices->Norm();

	if (offset)
	{
		DeOffset();
	}
}

System::Void Tetraedr::RotateRight(double r, bool offset)
{
	Rotate(0, r, 0, offset);
}

System::Void Tetraedr::RotateLeft(double r, bool offset)
{
	Rotate(0, -r, 0, offset);
}

System::Void Tetraedr::RotateUp(double r, bool offset)
{
	Rotate(-r, 0, 0, offset);
}

System::Void Tetraedr::RotateCCW(double r, bool offset)
{
	Rotate(0, 0, -r, offset);
}

System::Void Tetraedr::RotateDown(double r, bool offset)
{
	Rotate(r, 0, 0, offset);
}

System::Void Tetraedr::RotateCW(double r, bool offset)
{
	Rotate(0, 0, r, offset);
}

System::Void Tetraedr::Offset()
{
	double centerX = vertices->Get(0, 0);
	double centerY = vertices->Get(0, 1);
	double centerZ = vertices->Get(0, 2);

	Move(-centerX, -centerY, -centerZ);
	off = gcnew Point3d(centerX, centerY, centerZ);
}

System::Void Tetraedr::DeOffset()
{
	Move(off->X, off->Y, off->Z);
}

bool Tetraedr::CheckVisibility(double cameraZ)
{
	for (int i = 0; i < 4; i++)
	{
		if (vertices->Get(i, 2) < cameraZ)
		{
			return false;
		}
	}
	return true;
}

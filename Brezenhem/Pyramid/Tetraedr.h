#pragma once
#include "Matrix.h"
#include "Point3d.h"


namespace Pyramid {

	using namespace System;
	using namespace System::Collections::Generic;

	ref class Tetraedr
	{

	private:
		// Метод сдвига фигуры на координату первой точки (через которую проходит собственная ось вращения)
		System::Void Offset();
		// Метод обратного сдвига фигуры в положение до вызова Offset
		System::Void DeOffset();
		// Значение сдвига, выполненного по Offset
		Point3d^ off;
	public:
		// Матрица вершин
		Matrix^ vertices = gcnew Matrix(4, 4);
		// Матрица граней
		Matrix^ sides = gcnew Matrix(4, 3);

		Tetraedr()
		{
			vertices->Zero();
			sides->Zero();
		}

		Tetraedr(Point3d^ first, Point3d^ second, Point3d^ third, Point3d^ fourth)
		{
			// Запонение матрицы вершин (в четвертом столбце - вспомогательное значение)
			array<double>^ row1 = { first->X, first->Y, first->Z, 1 };
			array<double>^ row2 = { second->X, second->Y, second->Z, 1 };
			array<double>^ row3 = { third->X, third->Y, third->Z, 1 };
			array<double>^ row4 = { fourth->X, fourth->Y, fourth->Z, 1 };
			vertices->SetRow(0, row1);
			vertices->SetRow(1, row2);
			vertices->SetRow(2, row3);
			vertices->SetRow(3, row4);
			// Заполение матрицы граней (обход точек против часовой стрелки)
			array<double>^ side1 = { 0, 1, 2 };
			array<double>^ side2 = { 0, 2, 3 };
			array<double>^ side3 = { 0, 3, 1 };
			array<double>^ side4 = { 1, 3, 2 };
			sides->SetRow(0, side1);
			sides->SetRow(1, side2);
			sides->SetRow(2, side3);
			sides->SetRow(3, side4);
		}

		// Ортогональная проекция
		Tetraedr^ ToScreen();

		// Центральная проекция
		Tetraedr^ CenterProjection(double x0, double y0, double z0);

		// Метод сдвига по оси У
		System::Void MoveY(double d);

		// Метод сдвига по оси Х
		System::Void MoveX(double d);

		// Метод сдвига по оси Z
		System::Void MoveZ(double d);

		// Общий метод сдвига
		System::Void Move(double dx, double dy, double dz);

		// Метод масштабирования
		System::Void Scale(double s);

		// Общий метод поворота
		System::Void Rotate(double rx, double ry, double rz, bool offset);

		// Метод поворота направо
		System::Void RotateRight(double r, bool offset);

		// Метод поворота налево
		System::Void RotateLeft(double r, bool offset);

		// Метод поворота вверх
		System::Void RotateUp(double r, bool offset);

		// Метод поворота против часовой стрелки
		System::Void RotateCCW(double r, bool offset);

		// Метод поворота вниз
		System::Void RotateDown(double r, bool offset);

		// Метод поворота по часовой стрелке
		System::Void RotateCW(double r, bool offset);

		// Проверка нахождения фигуры в "поле зрения" относительно текущей плоскости проекции 
		bool CheckVisibility(double cameraZ);
	};

}

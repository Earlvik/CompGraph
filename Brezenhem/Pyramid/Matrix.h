#pragma once

namespace Pyramid {

	using namespace System;
	using namespace System::Collections::Generic;

	// Матрица чисел
	ref class Matrix
	{
	private:
		// Рабочий массив
		array<double, 2>^ arr;
	public:
		Matrix(int rows, int cols)
		{
			arr = gcnew array<double, 2>(rows, cols);
		}

		String^ ToString() override;

		// Заполнение матрицы нулями
		System::Void Zero();

		// Перемножение матриц
		Matrix^ Multiply(Matrix^ other);

		// Получение значения из матрицы
		double Get(int i, int j);

		// задание значения в матрице
		System::Void Set(int i, int j, double value);

		// Задание значений ряда в матрице
		System::Void SetRow(int i, array<double>^ values);

		// Задание значений колонки в марице
		System::Void SetColumn(int i, array<double>^ values);

		// Нормирование строк матрицы по последней колонке
		System::Void Norm();
	};
}

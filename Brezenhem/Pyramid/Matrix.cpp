#include "Matrix.h"

using namespace Pyramid;
	String^ Matrix::ToString()
	{
		int rows = arr->GetLength(0);
		int cols = arr->GetLength(1);
		String^ result = "";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result += arr[i, j].ToString() + " ";
			}
			result += "\r\n";
		}
		return result;
	}

	System::Void Matrix::Zero()
	{
		int rows = arr->GetLength(0);
		int cols = arr->GetLength(1);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i, j] = 0;
			}
		}
	}

	Matrix^ Matrix::Multiply(Matrix^ other)
	{
		int rows1 = arr->GetLength(0);
		int cols1 = arr->GetLength(1);
		int rows2 = other->arr->GetLength(0);
		int cols2 = other->arr->GetLength(1);

		if (cols1 != rows2)
		{
			throw gcnew ArgumentException("Wrong matrix size");
		}

		Matrix^ result = gcnew Matrix(rows1, cols2);

		for (int i = 0; i < rows1; i++)
		{
			for (int j = 0; j < cols2; j++)
			{
				double sum = 0;
				for (int k = 0; k < cols1; k++)
				{
					sum += arr[i, k] * other->arr[k, j];
				}
				result->arr[i, j] = sum;
			}
		}

		return result;
	}

	double Matrix::Get(int i, int j)
	{
		return arr[i, j];
	}

	System::Void Matrix::Set(int i, int j, double value)
	{
		arr[i, j] = value;
	}

	System::Void Matrix::SetRow(int i, array<double>^ values)
	{
		for (int j = 0; j < values->Length; j++)
		{
			arr[i, j] = values[j];
		}
	}

	System::Void Matrix::SetColumn(int i, array<double>^ values)
	{
		for (int j = 0; j < values->Length; j++)
		{
			arr[j, i] = values[j];
		}
	}

	System::Void Matrix::Norm()
	{
		int rows = arr->GetLength(0);
		int cols = arr->GetLength(1);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i, j] /= arr[i, cols - 1];
			}
		}
	}
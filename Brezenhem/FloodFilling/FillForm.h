/*
*	Заливка и отсечение
*	Лопатин Виктор, группа БПИ121
*	Среда разработки MS VS 2013
*	2015
*/

#pragma once

#include "Line.h"

namespace FloodFilling {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для FillForm
	/// </summary>
	public ref class FillForm : public System::Windows::Forms::Form
	{
	public:
		FillForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FillForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  Workspace;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  AboutMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadMenuItem;
	private: System::Windows::Forms::RadioButton^  LineFillRadio;



	private: System::Windows::Forms::RadioButton^  OtherFillRadio;
	private: System::Windows::Forms::RadioButton^  DrawLineRadio;
	private: System::Windows::Forms::RadioButton^  SliceRadio;
	private: System::Windows::Forms::Button^  ClearButton;

			 // Custom fields
	static const int IDLE = 0, LINEFILL = 1, FLOODFILL = 2, DRAWLINE = 3, SLICE = 4;
	private: int mode = LINEFILL;
	private: Color color;
	private: System::Windows::Forms::Panel^  ColorPanel;
	private: System::Windows::Forms::Button^  ColorButton;
	private: List<Line^>^ lines = gcnew List<Line^>();
	private: Point prevPoint;
	private: bool inProcess = false;



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Workspace = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->AboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LineFillRadio = (gcnew System::Windows::Forms::RadioButton());
			this->OtherFillRadio = (gcnew System::Windows::Forms::RadioButton());
			this->DrawLineRadio = (gcnew System::Windows::Forms::RadioButton());
			this->SliceRadio = (gcnew System::Windows::Forms::RadioButton());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->ColorPanel = (gcnew System::Windows::Forms::Panel());
			this->ColorButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Workspace))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Workspace
			// 
			this->Workspace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Workspace->BackColor = System::Drawing::Color::White;
			this->Workspace->Location = System::Drawing::Point(303, 37);
			this->Workspace->Name = L"Workspace";
			this->Workspace->Size = System::Drawing::Size(764, 367);
			this->Workspace->TabIndex = 0;
			this->Workspace->TabStop = false;
			this->Workspace->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FillForm::Workspace_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->AboutMenuItem, this->LoadMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1093, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AboutMenuItem
			// 
			this->AboutMenuItem->Name = L"AboutMenuItem";
			this->AboutMenuItem->Size = System::Drawing::Size(94, 20);
			this->AboutMenuItem->Text = L"О программе";
			this->AboutMenuItem->Click += gcnew System::EventHandler(this, &FillForm::AboutMenuItem_Click);
			// 
			// LoadMenuItem
			// 
			this->LoadMenuItem->Name = L"LoadMenuItem";
			this->LoadMenuItem->Size = System::Drawing::Size(150, 20);
			this->LoadMenuItem->Text = L"Загрузить изображение";
			this->LoadMenuItem->Click += gcnew System::EventHandler(this, &FillForm::LoadMenuItem_Click);
			// 
			// LineFillRadio
			// 
			this->LineFillRadio->AutoSize = true;
			this->LineFillRadio->Location = System::Drawing::Point(24, 66);
			this->LineFillRadio->Name = L"LineFillRadio";
			this->LineFillRadio->Size = System::Drawing::Size(130, 17);
			this->LineFillRadio->TabIndex = 2;
			this->LineFillRadio->TabStop = true;
			this->LineFillRadio->Text = L"Построчная заливка";
			this->LineFillRadio->UseVisualStyleBackColor = true;
			this->LineFillRadio->CheckedChanged += gcnew System::EventHandler(this, &FillForm::LineFillRadio_CheckedChanged);
			// 
			// OtherFillRadio
			// 
			this->OtherFillRadio->AutoSize = true;
			this->OtherFillRadio->Location = System::Drawing::Point(24, 89);
			this->OtherFillRadio->Name = L"OtherFillRadio";
			this->OtherFillRadio->Size = System::Drawing::Size(115, 17);
			this->OtherFillRadio->TabIndex = 3;
			this->OtherFillRadio->TabStop = true;
			this->OtherFillRadio->Text = L"Обычная заливка";
			this->OtherFillRadio->UseVisualStyleBackColor = true;
			this->OtherFillRadio->CheckedChanged += gcnew System::EventHandler(this, &FillForm::OtherFillRadio_CheckedChanged);
			// 
			// DrawLineRadio
			// 
			this->DrawLineRadio->AutoSize = true;
			this->DrawLineRadio->Location = System::Drawing::Point(24, 112);
			this->DrawLineRadio->Name = L"DrawLineRadio";
			this->DrawLineRadio->Size = System::Drawing::Size(130, 17);
			this->DrawLineRadio->TabIndex = 4;
			this->DrawLineRadio->TabStop = true;
			this->DrawLineRadio->Text = L"Рисование отрезков";
			this->DrawLineRadio->UseVisualStyleBackColor = true;
			this->DrawLineRadio->CheckedChanged += gcnew System::EventHandler(this, &FillForm::DrawLineRadio_CheckedChanged);
			// 
			// SliceRadio
			// 
			this->SliceRadio->AutoSize = true;
			this->SliceRadio->Location = System::Drawing::Point(24, 135);
			this->SliceRadio->Name = L"SliceRadio";
			this->SliceRadio->Size = System::Drawing::Size(174, 17);
			this->SliceRadio->TabIndex = 5;
			this->SliceRadio->TabStop = true;
			this->SliceRadio->Text = L"Отсечение прямоугольником";
			this->SliceRadio->UseVisualStyleBackColor = true;
			this->SliceRadio->CheckedChanged += gcnew System::EventHandler(this, &FillForm::SliceRadio_CheckedChanged);
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(64, 158);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 6;
			this->ClearButton->Text = L"Очистить";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &FillForm::ClearButton_Click);
			// 
			// ColorPanel
			// 
			this->ColorPanel->BackColor = System::Drawing::Color::Red;
			this->ColorPanel->Location = System::Drawing::Point(24, 190);
			this->ColorPanel->Name = L"ColorPanel";
			this->ColorPanel->Size = System::Drawing::Size(21, 21);
			this->ColorPanel->TabIndex = 7;
			// 
			// ColorButton
			// 
			this->ColorButton->Location = System::Drawing::Point(64, 188);
			this->ColorButton->Name = L"ColorButton";
			this->ColorButton->Size = System::Drawing::Size(107, 23);
			this->ColorButton->TabIndex = 8;
			this->ColorButton->Text = L"Выбрать цвет";
			this->ColorButton->UseVisualStyleBackColor = true;
			this->ColorButton->Click += gcnew System::EventHandler(this, &FillForm::ColorButton_Click);
			// 
			// FillForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1093, 423);
			this->Controls->Add(this->ColorButton);
			this->Controls->Add(this->ColorPanel);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->SliceRadio);
			this->Controls->Add(this->DrawLineRadio);
			this->Controls->Add(this->OtherFillRadio);
			this->Controls->Add(this->LineFillRadio);
			this->Controls->Add(this->Workspace);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(1109, 462);
			this->MinimumSize = System::Drawing::Size(1109, 462);
			this->Name = L"FillForm";
			this->Text = L"FillForm";
			this->Load += gcnew System::EventHandler(this, &FillForm::FillForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Workspace))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FillForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 Workspace->Image = gcnew Bitmap(Workspace->Width, Workspace->Height);
				 color = Color::Red;
	}
	private: System::Void LineFillRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((RadioButton^)sender)->Checked)
				 mode = LINEFILL;
	}
	private: System::Void OtherFillRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((RadioButton^)sender)->Checked)
				 mode = FLOODFILL;
	}

	private: System::Void DrawLineRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((RadioButton^)sender)->Checked) {
					 mode = DRAWLINE;
				 }
	}
	private: System::Void SliceRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
				 if (((RadioButton^)sender)->Checked)
				 mode = SLICE;
	}
	private: System::Void ClearButton_Click(System::Object^  sender, System::EventArgs^  e) {
				 Workspace->Image = gcnew Bitmap(Workspace->Width, Workspace->Height);
				 lines = gcnew List<Line^>();
	}
	private: System::Void LoadMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Title = "Загрузить изображение";
		ofd->Filter = "image files (*.bmp, *.jpg)|*.bmp; *.jpg";
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			Workspace->LoadAsync(ofd->FileName);
			lines = gcnew List<Line^>();
		}
	}
private: System::Void Workspace_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 Bitmap^ image = (Bitmap^)Workspace->Image;
			 int xClick = e->X;
			 int yClick = e->Y;
			 if (xClick >= image->Width || yClick >= image->Height) return;
			 switch (mode)
			 {
			 case IDLE: break;
			 case LINEFILL:
				 image = LineFill(image, Point(xClick, yClick));
				 Workspace->Image = image;
				 break;
			 case FLOODFILL:
				 image = FloodFill(image, Point(xClick, yClick));
				 Workspace->Image = image;
				 break;
			 case DRAWLINE:
				 if (inProcess)
				 {
					 lines->Add(gcnew Line(prevPoint, e->Location));
					 inProcess = false;
					 DrawLines();
				 }
				 else
				 {
					 prevPoint = e->Location;
					 inProcess = true;
				 }
				 break;
			 case SLICE:
				 if (inProcess)
				 {
					 Slice(prevPoint, e->Location);
					 inProcess = false;
					 Workspace->Image = gcnew Bitmap(Workspace->Width, Workspace->Height);
					 Image^ image = Workspace->Image;
					 Graphics^ g = Graphics::FromImage(image);
					 Pen^ pen = Pens::Goldenrod;
					 int xl = Math::Min(prevPoint.X, e->Location.X);
					 int xr = Math::Max(prevPoint.X, e->Location.X);
					 int yt = Math::Min(prevPoint.Y, e->Location.Y);
					 int yb = Math::Max(prevPoint.Y, e->Location.Y);
					 g->DrawRectangle(pen, xl, yt, xr - xl, yb - yt);
					 Workspace->Image = image;
					 DrawLines();
				 }
				 else
				 {
					 prevPoint = e->Location;
					 inProcess = true;
				 }
			 }
}

private: Bitmap^ LineFill(Bitmap^ image, Point point)
{
			 Color^ toFill = image->GetPixel(point.X, point.Y);
			 System::Collections::Generic::Stack<Point>^ stack = gcnew System::Collections::Generic::Stack<Point>();
			 stack->Push(Point(point.X, point.Y));
			 while (stack->Count > 0)
			 {
				 Point current = stack->Pop();
				 image->SetPixel(current.X, current.Y, color);
				 int x = current.X;
				 int y = current.Y;
				 while (x > 0)
				 {
					 x--;
					 if ((image->GetPixel(x, y)).Equals(toFill))
					 {
						 image->SetPixel(x, y, color);
					 }
					 else break;
				 }
				 int xLeft = x + 1;
				 x = current.X;
				 while (x < (image->Width - 1))
				 {
					 x++;
					 if ((image->GetPixel(x, y)).Equals(toFill))
					 {
						 image->SetPixel(x, y, color);
					 }
					 else break;
				 }
				 int xRight = x - 1;
				 if (y > 0) {
					 y = current.Y - 1;
					 for (int x = xLeft; x <= xRight; x++)
					 {
						 if ((image->GetPixel(x, y)).Equals(toFill) && ((x == xRight) || !(image->GetPixel(x + 1, y)).Equals(toFill)))
						 {
							 stack->Push(Point(x, y));
						 }
					 }
				 }

				 if (y < (image->Height - 2)) {
					 y = current.Y + 1;
					 for (int x = xLeft; x <= xRight; x++)
					 {
						 if ((image->GetPixel(x, y)).Equals(toFill) && ((x == xRight) || !(image->GetPixel(x + 1, y)).Equals(toFill)))
						 {
							 stack->Push(Point(x, y));
						 }
					 }
				 }
			 }

			 return image;
}

private: Bitmap^ FloodFill(Bitmap^ image, Point point)
{
			 Color^ toFill = image->GetPixel(point.X, point.Y);
			 System::Collections::Generic::Stack<Point>^ stack = gcnew System::Collections::Generic::Stack<Point>();
			 stack->Push(point);
			 while (stack->Count > 0)
			 {
				 Point current = stack->Pop();
				 int x = current.X;
				 int y = current.Y;
				 if ((image->GetPixel(x, y)).Equals(toFill)) {
					 image->SetPixel(x, y, color);
					 if (x < image->Width - 1)
						 stack->Push(Point(x + 1, y));
					 if (x > 0)
						 stack->Push(Point(x - 1, y));
					 if (y < image->Height - 1)
						 stack->Push(Point(x, y + 1));
					 if (y > 0)
						 stack->Push(Point(x, y - 1));
				 }
			 }
			 return image;
}

private: System::Void ColorButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 ColorDialog^ dialog = gcnew ColorDialog();
			 if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 color = dialog->Color;
				 ColorPanel->BackColor = color;
			 }
}

private: System::Void Slice(Point first, Point second)
{

			 int xl = Math::Min(first.X, second.X);
			 int xr = Math::Max(first.X, second.X);
			 int yt = Math::Min(first.Y, second.Y);
			 int yb = Math::Max(first.Y, second.Y);
			 for (int i = 0; i < lines->Count; i++)
			 {
				 Line^ line = lines[i];
				 int code1 = 0;
				 if (line->Start().X < xl) code1 = code1 | 1;
				 if (line->Start().X > xr) code1 = code1 | 2;
				 if (line->Start().Y < yt) code1 = code1 | 4;
				 if (line->Start().Y > yb) code1 = code1 | 8;
				 int code2 = 0;
				 if (line->Finish().X < xl) code2 = code2 | 1;
				 if (line->Finish().X > xr) code2 = code2 | 2;
				 if (line->Finish().Y < yt) code2 = code2 | 4;
				 if (line->Finish().Y > yb) code2 = code2 | 8;

				 Point newStart = line->Start();
				 Point newFinish = line->Finish();
				 if (code1 == 0 && code2 == 0) continue;
				 if ((code1 & code2) > 0)
				 {
					 lines->RemoveAt(i);
					 i--;
				 }
			 }
}

private: System::Void DrawLines()
{
			 Image^ image = Workspace->Image;
			 Graphics^ g = Graphics::FromImage(image);
			 Pen^ pen = gcnew Pen(color);
			 for (int i = 0; i < lines->Count; i++)
			 {
				 Line^ line = lines[i];
				 g->DrawLine(pen, line->Start(), line->Finish());
			 }
			 Workspace->Image = image;
}
private: System::Void AboutMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ message = "Заливка и отсечение \n Виктор Лопатин, группа БПИ121 \n\n Управление: Используйте радио-группу слева для выбора "+
				 "функции. \nРеализованы построчная и обычная заливки с затравкой. Загрузите изображение при помощи кнопки сверху, чтобы залить его."+
				 "\nИспользуйте рисование отрезков для создания заливаемых фигур или отрезков для отсечения. Выбирайте цвет при помощи соответствующей кнопки"+
				 "\nРисование отрезков и области отсечения производится отмечанием мышью двух точек - концов отрезка или углов прямоугольника\n\n2015 год";
			 String^ title = "О программе";
			 MessageBox::Show(this, message, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}

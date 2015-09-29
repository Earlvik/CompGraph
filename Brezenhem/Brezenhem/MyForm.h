/*
*	Алгоритмы Брезенхема
*	Лопатин Виктор, группа БПИ121
*	Среда разработки MS VS 2013
*	Реализованы алгоритмы рисования отрезка, окружности, эллипса
*	2015
*/

#pragma once
#include "State.h"

namespace Brezenhem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  AboutMenuButton;
	private: System::Windows::Forms::ToolStripMenuItem^  ToolChooseMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  EmbeddedMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  CustomMenuItem;
	private: System::Windows::Forms::Button^  LineButton;
	private: System::Windows::Forms::Button^  CircleButton;
	private: System::Windows::Forms::Button^  EllipseButton;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: bool IsCustom = false;
	private: bool InProcess = false;
	private: Point prevPoint;
	private: State State = IDLE;
	private: System::Windows::Forms::Button^  ClearButton;
	private: System::Windows::Forms::Label^  StateLabel;
	protected:


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->AboutMenuButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolChooseMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->EmbeddedMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CustomMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LineButton = (gcnew System::Windows::Forms::Button());
			this->CircleButton = (gcnew System::Windows::Forms::Button());
			this->EllipseButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->StateLabel = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->AboutMenuButton,
					this->ToolChooseMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(726, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AboutMenuButton
			// 
			this->AboutMenuButton->Name = L"AboutMenuButton";
			this->AboutMenuButton->Size = System::Drawing::Size(94, 20);
			this->AboutMenuButton->Text = L"О программе";
			this->AboutMenuButton->Click += gcnew System::EventHandler(this, &MyForm::AboutMenuButton_Click);
			// 
			// ToolChooseMenuItem
			// 
			this->ToolChooseMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->EmbeddedMenuItem,
					this->CustomMenuItem
			});
			this->ToolChooseMenuItem->Name = L"ToolChooseMenuItem";
			this->ToolChooseMenuItem->Size = System::Drawing::Size(123, 20);
			this->ToolChooseMenuItem->Text = L"Способ рисования";
			// 
			// EmbeddedMenuItem
			// 
			this->EmbeddedMenuItem->Checked = true;
			this->EmbeddedMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->EmbeddedMenuItem->Name = L"EmbeddedMenuItem";
			this->EmbeddedMenuItem->Size = System::Drawing::Size(212, 22);
			this->EmbeddedMenuItem->Text = L"Встроенная реализация";
			this->EmbeddedMenuItem->Click += gcnew System::EventHandler(this, &MyForm::EmbeddedMenuItem_Click);
			// 
			// CustomMenuItem
			// 
			this->CustomMenuItem->Name = L"CustomMenuItem";
			this->CustomMenuItem->Size = System::Drawing::Size(212, 22);
			this->CustomMenuItem->Text = L"Собственная реализация";
			this->CustomMenuItem->Click += gcnew System::EventHandler(this, &MyForm::CustomMenuItem_Click);
			// 
			// LineButton
			// 
			this->LineButton->Location = System::Drawing::Point(12, 51);
			this->LineButton->Name = L"LineButton";
			this->LineButton->Size = System::Drawing::Size(163, 23);
			this->LineButton->TabIndex = 1;
			this->LineButton->Text = L"Нарисовать отрезок";
			this->LineButton->Click += gcnew System::EventHandler(this, &MyForm::LineButton_Click);
			// 
			// CircleButton
			// 
			this->CircleButton->Location = System::Drawing::Point(12, 88);
			this->CircleButton->Name = L"CircleButton";
			this->CircleButton->Size = System::Drawing::Size(163, 23);
			this->CircleButton->TabIndex = 2;
			this->CircleButton->Text = L"Нарисовать окружность";
			this->CircleButton->UseVisualStyleBackColor = true;
			this->CircleButton->Click += gcnew System::EventHandler(this, &MyForm::CircleButton_Click);
			// 
			// EllipseButton
			// 
			this->EllipseButton->Location = System::Drawing::Point(12, 123);
			this->EllipseButton->Name = L"EllipseButton";
			this->EllipseButton->Size = System::Drawing::Size(163, 23);
			this->EllipseButton->TabIndex = 3;
			this->EllipseButton->Text = L"Нарисовать эллипс";
			this->EllipseButton->UseVisualStyleBackColor = true;
			this->EllipseButton->Click += gcnew System::EventHandler(this, &MyForm::EllipseButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(196, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(517, 238);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(13, 153);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(162, 23);
			this->ClearButton->TabIndex = 5;
			this->ClearButton->Text = L"Очистить";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->Click += gcnew System::EventHandler(this, &MyForm::ClearButton_Click);
			// 
			// StateLabel
			// 
			this->StateLabel->AutoSize = true;
			this->StateLabel->Location = System::Drawing::Point(13, 183);
			this->StateLabel->Name = L"StateLabel";
			this->StateLabel->Size = System::Drawing::Size(93, 13);
			this->StateLabel->TabIndex = 6;
			this->StateLabel->Text = L"Режим: не задан";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(726, 284);
			this->Controls->Add(this->StateLabel);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->EllipseButton);
			this->Controls->Add(this->CircleButton);
			this->Controls->Add(this->LineButton);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Алгоритмы Брезенхема. Виктор Лопатин 2015";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void EmbeddedMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 EmbeddedMenuItem->Checked = true;
			 CustomMenuItem->Checked = false;
			 InProcess = false;
			 IsCustom = false;
}

private: System::Void CustomMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 EmbeddedMenuItem->Checked = false;
				 CustomMenuItem->Checked = true;
				 IsCustom = true;
				 InProcess = false;
}	
private: System::Void LineButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 InProcess = false;
			 this->State = LINE;
			 StateLabel->Text = "Режим: отрезок";
}
private: System::Void CircleButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 InProcess = false;
			 this->State = CIRCLE;
			 StateLabel->Text = "Режим: окружность";
}
private: System::Void EllipseButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 InProcess = false;
			 this->State = ELLIPSE;
			 StateLabel->Text = "Режим: эллипс";
}

private: System::Void DrawLineEmbedded(System::Windows::Forms::MouseEventArgs^ e) {
 			 Graphics^ g = pictureBox1->CreateGraphics();
			 Color^ col = gcnew Color();
			 Pen^ pen = gcnew Pen(col->Red);
			 if (InProcess) {
				 g->DrawLine(pen, prevPoint, e->Location);
				 InProcess = false;
			 }
			 else {
				 prevPoint = e->Location;
				 InProcess = true;
			 }
}

private: System::Void DrawLineCustom(System::Windows::Forms::MouseEventArgs^ e) {
			 Graphics^ g = pictureBox1->CreateGraphics();
			 if (InProcess) {
				 DrawLineBrezenhem(g, prevPoint, e->Location);
				 InProcess = false;
			 }
			 else {
				 prevPoint = e->Location;
				 InProcess = true;
			 }
}

private: System::Void DrawLineBrezenhem(Graphics^ g, Point start, Point finish) {
			 Color^ col = gcnew Color();
			 Brush^ brush = gcnew SolidBrush(col->Green);
			 int x = start.X;
			 int y = start.Y;
			 int dx = Math::Abs(finish.X - x);
			 int dy = Math::Abs(finish.Y - y);
			 if (dx == 0 && dy == 0) {
				 return;
			 }
			 int s1 = Math::Sign(finish.X - x);
			 int s2 = Math::Sign(finish.Y - y);
			 bool swap = false;
			 if (dy > dx) {
				 swap = true;
				 dx += dy;
				 dy = dx - dy;
				 dx = dx - dy;
			 }

			 int error = 2 * dy - dx;
			 int i = 0;
			 while (i <= dx) {
				 this->DrawPixel(g, brush, x, y);
				 if (error >= 0) {
					 if (swap) {
						 x += s1;
					 }
					 else {
						 y += s2;
					 }
					 error -= 2 * dx;
				 }
				 else {
					 if (swap) {
						 y += s2;
					 }
					 else {
						 x += s1;
					 }
					 error += 2 * dy;
					 i++;
				 }
			 }
}

		 private: System::Void DrawCircleEmbedded(System::Windows::Forms::MouseEventArgs^ e) {
					  Graphics^ g = pictureBox1->CreateGraphics();
					  Color^ col = gcnew Color();
					  Pen^ pen = gcnew Pen(col->Red);
					  if (InProcess) {
						  int x1 = prevPoint.X;
						  int x2 = e->Location.X;
						  int y1 = prevPoint.Y;
						  int y2 = e->Location.Y;
						  int radius = Math::Sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
						  g->DrawEllipse(pen, x1 - radius, y1 - radius, 2*radius, 2*radius);
						  InProcess = false;
					  }
					  else {
						  prevPoint = e->Location;
						  InProcess = true;
					  }
		 }

		 private: System::Void DrawCircleCustom(System::Windows::Forms::MouseEventArgs^ e) {
					  Graphics^ g = pictureBox1->CreateGraphics();
					  if (InProcess) {
						  DrawCircleBrezenhem(g, prevPoint, e->Location);
						  InProcess = false;
					  }
					  else {
						  prevPoint = e->Location;
						  InProcess = true;
					  }
		 }

		private: System::Void DrawCircleBrezenhem(Graphics^ g, Point center, Point second) {
					 Brush^ brush = Brushes::Green;
					 int x = 0;
					 int y = Math::Sqrt((center.X - second.X) * (center.X - second.X) + (center.Y - second.Y) * (center.Y - second.Y));
					 int x1 = center.X;
					 int y1 = center.Y;
					 int d = 2 * (1 - y);
					 int limit = 0;
					 int s1 = 0;
					 int s2 = 0;
					 DrawPixel(g, brush, x + x1, y + y1);
					 DrawPixel(g, brush, x + x1, y1 - y);
					 DrawPixel(g, brush, x1 - x, y + y1);
					 DrawPixel(g, brush, x1 - x, y1 - y);
					 while (y > limit) {
						 if (d < 0) {
							 s1 = 2 * d + 2 * y - 1;
							 if (s1 <= 0) {
								 x += 1;
								 d += 2 * x + 1;
							 }
							 else {
								 x += 1;
								 y -= 1;
								 d += 2 * x - 2 * y + 2;
							 }
						 }
						 else {
							 if (d > 0) {
								 s2 = 2 * d - 2 * x - 1;
								 if (s2 <= 0) {
									 x += 1;
									 y -= 1;
									 d += 2 * x - 2 * y + 2;
								 }
								 else {
									 y -= 1;
									 d -= 2 * y + 1;
								 }
							 }
							 else {
								 x += 1;
								 y -= 1;
								 d += 2 * x - 2 * y + 2;
							 }
						 }
						 DrawPixel(g, brush, x + x1, y + y1);
						 DrawPixel(g, brush, x + x1, y1 - y);
						 DrawPixel(g, brush, x1 - x, y + y1);
						 DrawPixel(g, brush, x1 - x, y1 - y);
					 }
		}

		private: System::Void DrawEllipseEmbedded(System::Windows::Forms::MouseEventArgs^ e) {
					 Graphics^ g = pictureBox1->CreateGraphics();
					 Color^ col = gcnew Color();
					 Pen^ pen = gcnew Pen(col->Red);
					 if (InProcess) {
						 int x1 = prevPoint.X;
						 int x2 = e->Location.X;
						 int y1 = prevPoint.Y;
						 int y2 = e->Location.Y;
						 int dx = x2 - x1;
						 int dy = y2 - y1;
						 int signX = x1 > x2 ? 1 : -1;
						 int signY = y1 > y2 ? 1 : -1;
						 g->DrawEllipse(pen, x1 + signX * dx, y1 + signY * dy, 2 * Math::Abs(dx), 2 * Math::Abs(dy));
						 InProcess = false;
					 }
					 else {
						 prevPoint = e->Location;
						 InProcess = true;
					 }
		}

		private: System::Void DrawEllipseCustom(System::Windows::Forms::MouseEventArgs^ e) {
					 Graphics^ g = pictureBox1->CreateGraphics();
					 if (InProcess) {
						 DrawEllipseBrezenhem(g, prevPoint, e->Location);
						 InProcess = false;
					 }
					 else {
						 prevPoint = e->Location;
						 InProcess = true;
					 }
		}

		private: System::Void DrawEllipseBrezenhem(Graphics^ g, Point center, Point second) {
					 Brush^ brush = gcnew SolidBrush(Color::Green);
					 int x1 = center.X;
					 int y1 = center.Y;
					 int x2 = second.X;
					 int y2 = second.Y;
					 int dx = Math::Abs(x1 - x2);
					 int dy = Math::Abs(y1 - y2);
					 if (dx == 0 || dy == 0) return;

					 int error = dx * dx * dy;
					 int s1 = 2 * dx * dx;
					 int s2 = 2 * dy * dy;
					 int xLimit = s1 * dy;
					 int yLimit = 0;
					 int x = 0;
					 int y = dy;

					 while (yLimit <= xLimit) {
						 DrawPixel(g, brush, x1 + x, y1 + y);
						 DrawPixel(g, brush, x1 - x, y1 + y);
						 DrawPixel(g, brush, x1 + x, y1 - y);
						 DrawPixel(g, brush, x1 - x, y1 - y);
						 x++;
						 error -= s2 * (x - 1);
						 yLimit += s2;
						 if (error <= 0) {
							 error += s1 * (y - 1);
							 y--;
							 xLimit -= s1;
						 }
					 }

					 error = dy * dy * dx;
					 x = dx;
					 y = 0;
					 yLimit = s2 * dx;
					 xLimit = 0;
					 while (yLimit >= xLimit) {
						 DrawPixel(g, brush, x1 + x, y1 + y);
						 DrawPixel(g, brush, x1 - x, y1 + y);
						 DrawPixel(g, brush, x1 + x, y1 - y);
						 DrawPixel(g, brush, x1 - x, y1 - y);
						 y++;
						 error -= s1 * (y - 1);
						 xLimit += s1;
						 if (error < 0) {
							 error += s2 * (x - 1);
							 x--;
							 yLimit -= s2;
						 }
					 }
		}

		 private: System::Void DrawPixel(Graphics^ g, Brush^ brush, int x, int y) {
					  g->FillRectangle(brush, x, y, 1, 1);
		 }

private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 switch (this->State)
			 {
			 case IDLE:
				 return;
			 case LINE:
				 if (IsCustom) {
					 this->DrawLineCustom(e);
				 }
				 else {
					 this->DrawLineEmbedded(e);
				 }
				 break;
			 case CIRCLE:
				 if (IsCustom) {
					 this->DrawCircleCustom(e);
				 }
				 else {
					 this->DrawCircleEmbedded(e);
				 }
				 break;
			 case ELLIPSE:
				 if (IsCustom) {
					 this->DrawEllipseCustom(e);
				 }
				 else {
					 this->DrawEllipseEmbedded(e);
				 }
				 break;
			 default:
				 break;
			 }
}
private: System::Void ClearButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Graphics^ g = pictureBox1->CreateGraphics();
			 g->Clear(Color::White);
			 InProcess = false;
			 this->State = IDLE;
			 StateLabel->Text = "Режим: не задан";
}
private: System::Void AboutMenuButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ message = "Алгоритмы Брезенхема \n Виктор Лопатин, группа БПИ121 \n\n Управление: выберите фигуру нажатием одной из кнопок слева." +
				 "Выберите способ рисования при помощи соответствующего пункта меню. Рисование происходит двумя нажатиями на поле. \n\n При рисовании отрезков " +
				 "нажмите сначала в точке начала отрезка, затем в точке конца. \n При рисовании окружности или нажмите на точку центра, "+
				 "затем на любую точку окружности\nПри рисовании эллипса сначала нажмите в точку центра эллипса, а затем в другую точку экрана. " +
				 "Ширина и высота эллипса будут заданы расстоянием по обеим осям между двумя точками\n\n2015 год";
			 String^ title = "О программе";
			 MessageBox::Show(this, message, title, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}
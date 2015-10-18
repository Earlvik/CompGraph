/*
* Трехмерная графика: Пирамида
* Лопатин Виктор, группа БПИ121
* 2015
* Visual Studio 2013
* Реализованы вращение, сдвиг, масштабирование
* Ортогональная и центральная проекции
* Вращение вокруг глобальной оси или собственной оси, проходящей через первую точку пирамиды
* Сокрытие пирамиды при выходе за поле зрения по плоскости проекции
*/


#pragma once
#include "Matrix.h"
#include "Tetraedr.h"
#include "Point3d.h"

namespace Pyramid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PyramidForm
	/// </summary>
	public ref class PyramidForm : public System::Windows::Forms::Form
	{
	public:
		PyramidForm(void)
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
		~PyramidForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  AboutMenuItem;
	private: System::Windows::Forms::PictureBox^  Workspace;

	private: System::Windows::Forms::Panel^  ControlPanel;
	private: System::Windows::Forms::Button^  CCWRotateButton;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  RightRotateButton;
	private: System::Windows::Forms::Button^  LeftRotateButton;
	private: System::Windows::Forms::Button^  DownRotateButton;



	private: System::Windows::Forms::Button^  UpRotateButton;

	private: System::Windows::Forms::Button^  SmallerButton;
	private: System::Windows::Forms::Button^  BiggerButton;
	private: System::Windows::Forms::Button^  FartherButton;
	private: System::Windows::Forms::Button^  CloserButton;
	private: System::Windows::Forms::Button^  RightButton;
	private: System::Windows::Forms::Button^  LeftButton;
	private: System::Windows::Forms::Button^  DownButton;
	private: System::Windows::Forms::Button^  UpButton;
	private: System::Windows::Forms::Button^  CWRotateButton;
	private: System::Windows::Forms::Button^  CreateButton;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^  CentralBox;
	private: System::Windows::Forms::Button^  CentralButton;
	private: System::Windows::Forms::Button^  ParallelButton;
	private: System::Windows::Forms::CheckBox^  OffestBox;
		
			 // Используемый тетраэдр
			 Tetraedr^ tetra = gcnew Tetraedr();
			 // Флаг включения центральной проекции
			 bool center = false;
			 // Флаг включения поворота вокруг собственной оси
			 bool offset = false;
			 // Предыдущее положение мыши
			 Point prevPoint;
			 // Z-координата плоскости проекции
			 double cameraZ = 0;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->AboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Workspace = (gcnew System::Windows::Forms::PictureBox());
			this->ControlPanel = (gcnew System::Windows::Forms::Panel());
			this->OffestBox = (gcnew System::Windows::Forms::CheckBox());
			this->CWRotateButton = (gcnew System::Windows::Forms::Button());
			this->CCWRotateButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->RightRotateButton = (gcnew System::Windows::Forms::Button());
			this->LeftRotateButton = (gcnew System::Windows::Forms::Button());
			this->DownRotateButton = (gcnew System::Windows::Forms::Button());
			this->UpRotateButton = (gcnew System::Windows::Forms::Button());
			this->SmallerButton = (gcnew System::Windows::Forms::Button());
			this->BiggerButton = (gcnew System::Windows::Forms::Button());
			this->FartherButton = (gcnew System::Windows::Forms::Button());
			this->CloserButton = (gcnew System::Windows::Forms::Button());
			this->RightButton = (gcnew System::Windows::Forms::Button());
			this->LeftButton = (gcnew System::Windows::Forms::Button());
			this->DownButton = (gcnew System::Windows::Forms::Button());
			this->UpButton = (gcnew System::Windows::Forms::Button());
			this->CreateButton = (gcnew System::Windows::Forms::Button());
			this->CentralBox = (gcnew System::Windows::Forms::TextBox());
			this->CentralButton = (gcnew System::Windows::Forms::Button());
			this->ParallelButton = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Workspace))->BeginInit();
			this->ControlPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->AboutMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1358, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// AboutMenuItem
			// 
			this->AboutMenuItem->Name = L"AboutMenuItem";
			this->AboutMenuItem->Size = System::Drawing::Size(62, 24);
			this->AboutMenuItem->Text = L"About";
			this->AboutMenuItem->Click += gcnew System::EventHandler(this, &PyramidForm::AboutMenuItem_Click);
			// 
			// Workspace
			// 
			this->Workspace->BackColor = System::Drawing::Color::White;
			this->Workspace->Enabled = false;
			this->Workspace->Location = System::Drawing::Point(13, 32);
			this->Workspace->Name = L"Workspace";
			this->Workspace->Size = System::Drawing::Size(1333, 278);
			this->Workspace->TabIndex = 1;
			this->Workspace->TabStop = false;
			this->Workspace->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PyramidForm::Workspace_MouseDown);
			this->Workspace->MouseEnter += gcnew System::EventHandler(this, &PyramidForm::Workspace_MouseEnter);
			this->Workspace->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &PyramidForm::Workspace_MouseMove);
			this->Workspace->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &PyramidForm::Workspace_MouseWheel);
			// 
			// ControlPanel
			// 
			this->ControlPanel->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ControlPanel->Controls->Add(this->OffestBox);
			this->ControlPanel->Controls->Add(this->CWRotateButton);
			this->ControlPanel->Controls->Add(this->CCWRotateButton);
			this->ControlPanel->Controls->Add(this->label2);
			this->ControlPanel->Controls->Add(this->label1);
			this->ControlPanel->Controls->Add(this->RightRotateButton);
			this->ControlPanel->Controls->Add(this->LeftRotateButton);
			this->ControlPanel->Controls->Add(this->DownRotateButton);
			this->ControlPanel->Controls->Add(this->UpRotateButton);
			this->ControlPanel->Controls->Add(this->SmallerButton);
			this->ControlPanel->Controls->Add(this->BiggerButton);
			this->ControlPanel->Controls->Add(this->FartherButton);
			this->ControlPanel->Controls->Add(this->CloserButton);
			this->ControlPanel->Controls->Add(this->RightButton);
			this->ControlPanel->Controls->Add(this->LeftButton);
			this->ControlPanel->Controls->Add(this->DownButton);
			this->ControlPanel->Controls->Add(this->UpButton);
			this->ControlPanel->Enabled = false;
			this->ControlPanel->Location = System::Drawing::Point(726, 332);
			this->ControlPanel->Name = L"ControlPanel";
			this->ControlPanel->Size = System::Drawing::Size(620, 153);
			this->ControlPanel->TabIndex = 3;
			// 
			// OffestBox
			// 
			this->OffestBox->AutoSize = true;
			this->OffestBox->Location = System::Drawing::Point(227, 106);
			this->OffestBox->Name = L"OffestBox";
			this->OffestBox->Size = System::Drawing::Size(178, 21);
			this->OffestBox->TabIndex = 16;
			this->OffestBox->Text = L"Rotate around own axis";
			this->OffestBox->UseVisualStyleBackColor = true;
			this->OffestBox->CheckedChanged += gcnew System::EventHandler(this, &PyramidForm::OffestBox_CheckedChanged);
			// 
			// CWRotateButton
			// 
			this->CWRotateButton->Location = System::Drawing::Point(552, 33);
			this->CWRotateButton->Name = L"CWRotateButton";
			this->CWRotateButton->Size = System::Drawing::Size(63, 27);
			this->CWRotateButton->TabIndex = 15;
			this->CWRotateButton->Text = L"CW";
			this->CWRotateButton->UseVisualStyleBackColor = true;
			this->CWRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::CWRotateButton_Click);
			// 
			// CCWRotateButton
			// 
			this->CCWRotateButton->Location = System::Drawing::Point(415, 33);
			this->CCWRotateButton->Name = L"CCWRotateButton";
			this->CCWRotateButton->Size = System::Drawing::Size(63, 27);
			this->CCWRotateButton->TabIndex = 14;
			this->CCWRotateButton->Text = L"CCW";
			this->CCWRotateButton->UseVisualStyleBackColor = true;
			this->CCWRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::CCWRotateButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(486, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 17);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Rotate";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(87, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 17);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Move";
			// 
			// RightRotateButton
			// 
			this->RightRotateButton->Location = System::Drawing::Point(552, 66);
			this->RightRotateButton->Name = L"RightRotateButton";
			this->RightRotateButton->Size = System::Drawing::Size(63, 27);
			this->RightRotateButton->TabIndex = 11;
			this->RightRotateButton->Text = L"Right";
			this->RightRotateButton->UseVisualStyleBackColor = true;
			this->RightRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::RightRotateButton_Click);
			// 
			// LeftRotateButton
			// 
			this->LeftRotateButton->Location = System::Drawing::Point(415, 66);
			this->LeftRotateButton->Name = L"LeftRotateButton";
			this->LeftRotateButton->Size = System::Drawing::Size(63, 27);
			this->LeftRotateButton->TabIndex = 10;
			this->LeftRotateButton->Text = L"Left";
			this->LeftRotateButton->UseVisualStyleBackColor = true;
			this->LeftRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::LeftRotateButton_Click);
			// 
			// DownRotateButton
			// 
			this->DownRotateButton->Location = System::Drawing::Point(480, 99);
			this->DownRotateButton->Name = L"DownRotateButton";
			this->DownRotateButton->Size = System::Drawing::Size(67, 27);
			this->DownRotateButton->TabIndex = 9;
			this->DownRotateButton->Text = L"Down";
			this->DownRotateButton->UseVisualStyleBackColor = true;
			this->DownRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::DownRotateButton_Click);
			// 
			// UpRotateButton
			// 
			this->UpRotateButton->Location = System::Drawing::Point(480, 33);
			this->UpRotateButton->Name = L"UpRotateButton";
			this->UpRotateButton->Size = System::Drawing::Size(67, 27);
			this->UpRotateButton->TabIndex = 8;
			this->UpRotateButton->Text = L"Up";
			this->UpRotateButton->UseVisualStyleBackColor = true;
			this->UpRotateButton->Click += gcnew System::EventHandler(this, &PyramidForm::UpRotateButton_Click);
			// 
			// SmallerButton
			// 
			this->SmallerButton->Location = System::Drawing::Point(325, 66);
			this->SmallerButton->Name = L"SmallerButton";
			this->SmallerButton->Size = System::Drawing::Size(75, 33);
			this->SmallerButton->TabIndex = 7;
			this->SmallerButton->Text = L"Smaller";
			this->SmallerButton->UseVisualStyleBackColor = true;
			this->SmallerButton->Click += gcnew System::EventHandler(this, &PyramidForm::SmallerButton_Click);
			// 
			// BiggerButton
			// 
			this->BiggerButton->Location = System::Drawing::Point(325, 10);
			this->BiggerButton->Name = L"BiggerButton";
			this->BiggerButton->Size = System::Drawing::Size(75, 32);
			this->BiggerButton->TabIndex = 6;
			this->BiggerButton->Text = L"Bigger";
			this->BiggerButton->UseVisualStyleBackColor = true;
			this->BiggerButton->Click += gcnew System::EventHandler(this, &PyramidForm::BiggerButton_Click);
			// 
			// FartherButton
			// 
			this->FartherButton->Location = System::Drawing::Point(227, 67);
			this->FartherButton->Name = L"FartherButton";
			this->FartherButton->Size = System::Drawing::Size(75, 32);
			this->FartherButton->TabIndex = 5;
			this->FartherButton->Text = L"Farther";
			this->FartherButton->UseVisualStyleBackColor = true;
			this->FartherButton->Click += gcnew System::EventHandler(this, &PyramidForm::FartherButton_Click);
			// 
			// CloserButton
			// 
			this->CloserButton->Location = System::Drawing::Point(227, 9);
			this->CloserButton->Name = L"CloserButton";
			this->CloserButton->Size = System::Drawing::Size(75, 33);
			this->CloserButton->TabIndex = 4;
			this->CloserButton->Text = L"Closer";
			this->CloserButton->UseVisualStyleBackColor = true;
			this->CloserButton->Click += gcnew System::EventHandler(this, &PyramidForm::CloserButton_Click);
			// 
			// RightButton
			// 
			this->RightButton->Location = System::Drawing::Point(147, 66);
			this->RightButton->Name = L"RightButton";
			this->RightButton->Size = System::Drawing::Size(63, 27);
			this->RightButton->TabIndex = 3;
			this->RightButton->Text = L"Right";
			this->RightButton->UseVisualStyleBackColor = true;
			this->RightButton->Click += gcnew System::EventHandler(this, &PyramidForm::RightButton_Click);
			// 
			// LeftButton
			// 
			this->LeftButton->Location = System::Drawing::Point(13, 66);
			this->LeftButton->Name = L"LeftButton";
			this->LeftButton->Size = System::Drawing::Size(63, 27);
			this->LeftButton->TabIndex = 2;
			this->LeftButton->Text = L"Left";
			this->LeftButton->UseVisualStyleBackColor = true;
			this->LeftButton->Click += gcnew System::EventHandler(this, &PyramidForm::LeftButton_Click);
			// 
			// DownButton
			// 
			this->DownButton->Location = System::Drawing::Point(74, 99);
			this->DownButton->Name = L"DownButton";
			this->DownButton->Size = System::Drawing::Size(67, 27);
			this->DownButton->TabIndex = 1;
			this->DownButton->Text = L"Down";
			this->DownButton->UseVisualStyleBackColor = true;
			this->DownButton->Click += gcnew System::EventHandler(this, &PyramidForm::DownButton_Click);
			// 
			// UpButton
			// 
			this->UpButton->Location = System::Drawing::Point(74, 33);
			this->UpButton->Name = L"UpButton";
			this->UpButton->Size = System::Drawing::Size(67, 27);
			this->UpButton->TabIndex = 0;
			this->UpButton->Text = L"Up";
			this->UpButton->UseVisualStyleBackColor = true;
			this->UpButton->Click += gcnew System::EventHandler(this, &PyramidForm::UpButton_Click);
			// 
			// CreateButton
			// 
			this->CreateButton->Location = System::Drawing::Point(509, 336);
			this->CreateButton->Name = L"CreateButton";
			this->CreateButton->Size = System::Drawing::Size(172, 75);
			this->CreateButton->TabIndex = 4;
			this->CreateButton->Text = L"Create";
			this->CreateButton->UseVisualStyleBackColor = true;
			this->CreateButton->Click += gcnew System::EventHandler(this, &PyramidForm::CreateButton_Click);
			// 
			// CentralBox
			// 
			this->CentralBox->Location = System::Drawing::Point(357, 327);
			this->CentralBox->Name = L"CentralBox";
			this->CentralBox->Size = System::Drawing::Size(100, 22);
			this->CentralBox->TabIndex = 5;
			// 
			// CentralButton
			// 
			this->CentralButton->Enabled = false;
			this->CentralButton->Location = System::Drawing::Point(342, 355);
			this->CentralButton->Name = L"CentralButton";
			this->CentralButton->Size = System::Drawing::Size(133, 37);
			this->CentralButton->TabIndex = 6;
			this->CentralButton->Text = L"Central Projection";
			this->CentralButton->UseVisualStyleBackColor = true;
			this->CentralButton->Click += gcnew System::EventHandler(this, &PyramidForm::CentralButton_Click);
			// 
			// ParallelButton
			// 
			this->ParallelButton->Enabled = false;
			this->ParallelButton->Location = System::Drawing::Point(203, 355);
			this->ParallelButton->Name = L"ParallelButton";
			this->ParallelButton->Size = System::Drawing::Size(133, 37);
			this->ParallelButton->TabIndex = 7;
			this->ParallelButton->Text = L"Parallel Projection";
			this->ParallelButton->UseVisualStyleBackColor = true;
			this->ParallelButton->Click += gcnew System::EventHandler(this, &PyramidForm::ParallelButton_Click);
			// 
			// PyramidForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1358, 497);
			this->Controls->Add(this->ParallelButton);
			this->Controls->Add(this->CentralButton);
			this->Controls->Add(this->CentralBox);
			this->Controls->Add(this->CreateButton);
			this->Controls->Add(this->ControlPanel);
			this->Controls->Add(this->Workspace);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PyramidForm";
			this->Text = L"PyramidForm";
			this->Load += gcnew System::EventHandler(this, &PyramidForm::PyramidForm_Load);
			this->Shown += gcnew System::EventHandler(this, &PyramidForm::PyramidForm_Shown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Workspace))->EndInit();
			this->ControlPanel->ResumeLayout(false);
			this->ControlPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void PyramidForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

// Метод рисования тетраедра по заданным двумерным координатам
private: System::Void DrawTetraedr(Tetraedr^ tetraedr)
{
			 Graphics^ g = Workspace->CreateGraphics();
			 g->Clear(Color::White);
			 Pen^ pen = Pens::Red;
			 Brush^ brush = Brushes::Red;
			 for (int i = 0; i < 4; i++)
			 {
				 int first = tetraedr->sides->Get(i, 0);
				 int second = tetraedr->sides->Get(i, 1);
				 int third = tetraedr->sides->Get(i, 2);
				 int x1 = tetraedr->vertices->Get(first, 0);
				 int y1 = tetraedr->vertices->Get(first, 1);
				 int x2 = tetraedr->vertices->Get(second, 0);
				 int y2 = tetraedr->vertices->Get(second, 1);
				 int x3 = tetraedr->vertices->Get(third, 0);
				 int y3 = tetraedr->vertices->Get(third, 1);

				 g->FillEllipse(brush, x1 - 4, y1 - 4, 8, 8);
				 g->FillEllipse(brush, x2 - 4, y2 - 4, 8, 8);
				 g->FillEllipse(brush, x3 - 4, y3 - 4, 8, 8);
				 g->DrawLine(pen, x1, y1, x2, y2);
				 g->DrawLine(pen, x2, y2, x3, y3);
				 g->DrawLine(pen, x3, y3, x1, y1);
			 }
}
private: System::Void PyramidForm_Shown(System::Object^  sender, System::EventArgs^  e) {
}

// Первоначальное создание тетераедра
private: System::Void CreateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 Point3d^ first = gcnew Point3d(400, 50, 200);
			 Point3d^ second = gcnew Point3d(300, 150, 200);
			 Point3d^ third = gcnew Point3d(600, 150, 200);
			 Point3d^ fourth = gcnew Point3d(500, 130, 270);
			 Workspace->Enabled = true;
			 ControlPanel->Enabled = true;
			 ParallelButton->Enabled = true;
			 CentralButton->Enabled = true;
			 Tetraedr^ t = gcnew Tetraedr(first, second, third, fourth);
			 tetra = t;
			 center = false;
			 if (!t->CheckVisibility(cameraZ))
			 {
				 Clear();
				 return;
			 }
			 DrawTetraedr(t->ToScreen());

}

// Переключение на ортогональную проекцию
private: System::Void ParallelButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 cameraZ = 0;
			 center = false;
			 if (!tetra->CheckVisibility(cameraZ))
			 {
				 Clear();
				 return;
			 }
			 DrawTetraedr(tetra->ToScreen());
}

// Переключение на центральную проекцию
private: System::Void CentralButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 double z0;
			 if (!Double::TryParse(CentralBox->Text, z0))
			 {
				 MessageBox::Show("Wrong z0 value. Please input a double value into the field above the button");
				 return;
			 }
			 cameraZ = z0;
			 center = true;
			 if (!tetra->CheckVisibility(cameraZ))
			 {
				 Clear();
				 return;
			 }
			 DrawTetraedr(tetra->CenterProjection(Workspace->Width/2.0, Workspace->Height/2.0, z0));	 
}

// Сдвиг вверх по нажатию кнопки
private: System::Void UpButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveY(-5);
			 Draw();
}

// Общий метод рисования тетраэдра
private: System::Void Draw()
{
			 if (!tetra->CheckVisibility(cameraZ))
			 {
				 Clear();
				 return;
			 }
			 if (center)
			 {
				 double z0;
				 if (!Double::TryParse(CentralBox->Text, z0))
				 {
					 MessageBox::Show("Wrong z0 value. Please input a double value into the field above the button");
					 return;
				 }
				 DrawTetraedr(tetra->CenterProjection(Workspace->Width / 2.0, Workspace->Height / 2.0, z0));
			 }
			 else
			 {
				 DrawTetraedr(tetra->ToScreen());
			 }
}

// Сдвиг вниз по нажатию кнопки
private: System::Void DownButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveY(5);
			 Draw();
}

// Сдвиг влево по нажатию кнопки
private: System::Void LeftButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveX(-5);
			 Draw();
}

// Сдвиг вправо по нажатию кнопки
private: System::Void RightButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveX(5);
			 Draw();
}

// Сдвиг ближе по нажатию кнопки
private: System::Void CloserButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveZ(-2);
			 Draw();
}

// Сдвиг дальше по нажатию кнопки
private: System::Void FartherButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->MoveZ(2);
			 Draw();
}

// Увеличение по нажатию кнопки
private: System::Void BiggerButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->Scale(1.1);
			 Draw();
}

// Уменьшение по нажатию кнопки
private: System::Void SmallerButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->Scale(0.9);
			 Draw();
}

// Поворот направо по нажатию кнопки
private: System::Void RightRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateRight(0.05, offset);
			 Draw();
}

// Поворот налево по нажатию кнопки
private: System::Void LeftRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateLeft(0.05, offset);
			 Draw();
}

// Поворот наверх по нажатию кнопки
private: System::Void UpRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateUp(0.05, offset);
			 Draw();
}

// Поворот вниз по нажатию кнопки
private: System::Void DownRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateDown(0.05, offset);
			 Draw();
}

// Поворот по часовой стрелке по нажатию кнопки
private: System::Void CWRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateCW(0.05, offset);
			 Draw();
}

// Поворот против часовой стрелки по нажатию кнопки
private: System::Void CCWRotateButton_Click(System::Object^  sender, System::EventArgs^  e) {
			 tetra->RotateCCW(0.05, offset);
			 Draw();
}

// Переключение режима вращения вокруг собственной оси
private: System::Void OffestBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (OffestBox->Checked)
			 {
				 offset = true;
			 }
			 else
			 {
				 offset = false;
			 }
}

// Обработка использования мыши
private: System::Void Workspace_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 // Поворот при нажатой левой кнопке
			 if (e->Button == Windows::Forms::MouseButtons::Left) {
				 int dx = e->Location.X - prevPoint.X;
				 int dy = e->Location.Y - prevPoint.Y;
				 tetra->Rotate(-dy/50.0, dx/50.0, 0, offset);
				 Draw();
			 }

			 // Движение при нажатой правой кнопке
			 else if (e->Button == Windows::Forms::MouseButtons::Right)
			 {
				 int dx = e->Location.X - prevPoint.X;
				 int dy = e->Location.Y - prevPoint.Y;
				 tetra->Move(dx, dy, 0);
				 Draw();
			 }
			 prevPoint = e->Location;
}
private: System::Void Workspace_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 prevPoint = e->Location;
}
private: System::Void Workspace_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 Workspace->Focus();
}

// Масштабирование по повороту колеса мыши
private: System::Void Workspace_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
			 if (e->Delta > 0)
			 {
				 tetra->Scale(1.1);
			 }
			 else if (e->Delta < 0)
			 {
				 tetra->Scale(0.9);
			 }

			 Draw();
}


// Очистка рабочей области
private: System::Void Clear()
{
			 Graphics^ g = Workspace->CreateGraphics();
			 g->Clear(Color::White);
}
private: System::Void AboutMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("Трехмерная графика: Пирамида. \nЛопатин Виктор, группа БПИ121\nИнструкция по пользованию в файле Manual.pdf");
}
};
}

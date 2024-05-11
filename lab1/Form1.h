#pragma once

#include<math.h>

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int vert_num = 4; // количество вершин фигуры
	const int dimension = 3;// число столбцов матрицы однородных координат
	//3-для двумерной графики, 4 для трехмерной
	double  hmg_p[vert_num][dimension] = { 0 }; // матрица однородных координат // фигуры
	int dek_p[vert_num][dimension - 1] = { 0 }; // матрица экранных координат //фигуры
	double matrix_T[dimension][dimension] = { 0 };// матрица преобразования
	// все массивы матриц инициализированы нулями
	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Void matrix_mult(int number_of_vertex_A, double A[][dimension], double B[][dimension], double C[][dimension]) {
		int i, j, k;
		for (i = 0; i < number_of_vertex_A; i++)
			for (j = 0; j < dimension; j++) {
				C[i][j] = 0;
				for (k = 0; k < dimension; k++)
					C[i][j] += (A[i][k] * B[k][j]);
			}
	}

	private: System::Void hmg2dek(int number_of_vertex_A, double HMG[][dimension], int DEK[][dimension - 1]) {
		for (int i = 0; i < number_of_vertex_A; i++) {
			double a = HMG[i][dimension - 1];
			if (a != 0) {
				DEK[i][0] = HMG[i][0] / a;
				DEK[i][1] = HMG[i][1] / a;
			}
			else {
				System::Windows::Forms::MessageBox::Show("division by zero is impossible! Check the coordinates of the shape and the transformation matrix");
				break;
			}
		}
	}

	private: System::Void make_trans_mat(double x, double y, double result_mat[dimension][dimension]) {
		result_mat[0][0] = 1;
		result_mat[0][1] = 0;
		result_mat[0][2] = 0;

		result_mat[1][0] = 0;
		result_mat[1][1] = 1;
		result_mat[1][2] = 0;

		result_mat[2][0] = x;
		result_mat[2][1] = y;
		result_mat[2][2] = 1;
	}

	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ btn_draw;
	private: System::Windows::Forms::TextBox^ textBox_x1;
	private: System::Windows::Forms::TextBox^ textBox_y1;
	private: System::Windows::Forms::TextBox^ textBox_z1;



	private: System::Windows::Forms::TextBox^ textBox_x4;
	private: System::Windows::Forms::TextBox^ textBox_y4;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_z2;

	private: System::Windows::Forms::TextBox^ textBox_y3;

	private: System::Windows::Forms::TextBox^ textBox_y2;
	private: System::Windows::Forms::TextBox^ textBox_z3;


	private: System::Windows::Forms::TextBox^ textBox_z4;

	private: System::Windows::Forms::TextBox^ textBox_x3;

	private: System::Windows::Forms::TextBox^ textBox_x2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox_transz2;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox_transy3;

	private: System::Windows::Forms::TextBox^ textBox_transy2;
	private: System::Windows::Forms::TextBox^ textBox_transz3;


	private: System::Windows::Forms::TextBox^ textBox_transz1;




	private: System::Windows::Forms::TextBox^ textBox_transy1;

	private: System::Windows::Forms::TextBox^ textBox_transx3;
	private: System::Windows::Forms::TextBox^ textBox_transx2;




	private: System::Windows::Forms::TextBox^ textBox_transx1;
private: System::Windows::Forms::Button^ button_transfer;


private: System::Windows::Forms::TextBox^ textBox_transx;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::TextBox^ textBox_transy;
private: System::Windows::Forms::TextBox^ textBox_scalex;


private: System::Windows::Forms::TextBox^ textBox_scaley;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::TextBox^ textBox_scalez2;

	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox_scaley3;

private: System::Windows::Forms::TextBox^ textBox_scaley2;
private: System::Windows::Forms::TextBox^ textBox_scalez3;


private: System::Windows::Forms::TextBox^ textBox_scalez1;

private: System::Windows::Forms::TextBox^ textBox_scaley1;
private: System::Windows::Forms::TextBox^ textBox_scalex3;


private: System::Windows::Forms::TextBox^ textBox_scalex2;

private: System::Windows::Forms::TextBox^ textBox_scalex1;
private: System::Windows::Forms::Button^ button_scale;


private: System::Windows::Forms::TextBox^ textBox_rotatealpha;

	private: System::Windows::Forms::Label^ label18;
	private: System::Windows::Forms::GroupBox^ groupBox4;
private: System::Windows::Forms::TextBox^ textBox_rotatez2;

	private: System::Windows::Forms::Label^ label20;
	private: System::Windows::Forms::Label^ label21;
	private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::TextBox^ textBox_rotatey3;

private: System::Windows::Forms::TextBox^ textBox_rotatey2;
private: System::Windows::Forms::TextBox^ textBox_rotatez3;


private: System::Windows::Forms::TextBox^ textBox_rotatez1;

private: System::Windows::Forms::TextBox^ textBox_rotatey1;

private: System::Windows::Forms::TextBox^ textBox_rotatex3;

private: System::Windows::Forms::TextBox^ textBox_rotatex2;

private: System::Windows::Forms::TextBox^ textBox_rotatex1;
private: System::Windows::Forms::Button^ button_rotate;
private: System::Windows::Forms::Button^ button_mirror;

private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
private: System::Windows::Forms::Label^ label19;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_draw = (gcnew System::Windows::Forms::Button());
			this->textBox_x1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox_z2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_transz2 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox_transy3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transy2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transz3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transz1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transy1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transx3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transx2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_transx1 = (gcnew System::Windows::Forms::TextBox());
			this->button_transfer = (gcnew System::Windows::Forms::Button());
			this->textBox_transx = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox_transy = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalex = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scaley = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_scalez2 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->textBox_scaley3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scaley2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalez3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalez1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scaley1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalex3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalex2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_scalex1 = (gcnew System::Windows::Forms::TextBox());
			this->button_scale = (gcnew System::Windows::Forms::Button());
			this->textBox_rotatealpha = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_rotatez2 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->textBox_rotatey3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatey2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatez3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatez1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatey1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatex3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatex2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotatex1 = (gcnew System::Windows::Forms::TextBox());
			this->button_rotate = (gcnew System::Windows::Forms::Button());
			this->button_mirror = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label19 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(407, 325);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// btn_draw
			// 
			this->btn_draw->Location = System::Drawing::Point(425, 159);
			this->btn_draw->Name = L"btn_draw";
			this->btn_draw->Size = System::Drawing::Size(81, 41);
			this->btn_draw->TabIndex = 2;
			this->btn_draw->Text = L"Init and Draw";
			this->btn_draw->UseVisualStyleBackColor = true;
			this->btn_draw->Click += gcnew System::EventHandler(this, &Form1::btn_draw_Click);
			// 
			// textBox_x1
			// 
			this->textBox_x1->Location = System::Drawing::Point(61, 35);
			this->textBox_x1->Name = L"textBox_x1";
			this->textBox_x1->Size = System::Drawing::Size(47, 20);
			this->textBox_x1->TabIndex = 0;
			this->textBox_x1->Text = L"100";
			// 
			// textBox_y1
			// 
			this->textBox_y1->Location = System::Drawing::Point(114, 35);
			this->textBox_y1->Name = L"textBox_y1";
			this->textBox_y1->ReadOnly = true;
			this->textBox_y1->Size = System::Drawing::Size(47, 20);
			this->textBox_y1->TabIndex = 0;
			// 
			// textBox_z1
			// 
			this->textBox_z1->Location = System::Drawing::Point(167, 35);
			this->textBox_z1->Name = L"textBox_z1";
			this->textBox_z1->ReadOnly = true;
			this->textBox_z1->Size = System::Drawing::Size(47, 20);
			this->textBox_z1->TabIndex = 0;
			this->textBox_z1->Text = L"1";
			// 
			// textBox_x4
			// 
			this->textBox_x4->Location = System::Drawing::Point(61, 112);
			this->textBox_x4->Name = L"textBox_x4";
			this->textBox_x4->Size = System::Drawing::Size(47, 20);
			this->textBox_x4->TabIndex = 0;
			this->textBox_x4->Text = L"200";
			// 
			// textBox_y4
			// 
			this->textBox_y4->Location = System::Drawing::Point(114, 112);
			this->textBox_y4->Name = L"textBox_y4";
			this->textBox_y4->ReadOnly = true;
			this->textBox_y4->Size = System::Drawing::Size(47, 20);
			this->textBox_y4->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Vertex 1";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(78, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"X";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(131, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(185, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(13, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(10, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Vertex 4";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox_z2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox_y3);
			this->groupBox1->Controls->Add(this->textBox_y2);
			this->groupBox1->Controls->Add(this->textBox_z3);
			this->groupBox1->Controls->Add(this->textBox_z4);
			this->groupBox1->Controls->Add(this->textBox_y4);
			this->groupBox1->Controls->Add(this->textBox_x4);
			this->groupBox1->Controls->Add(this->textBox_z1);
			this->groupBox1->Controls->Add(this->textBox_y1);
			this->groupBox1->Controls->Add(this->textBox_x3);
			this->groupBox1->Controls->Add(this->textBox_x2);
			this->groupBox1->Controls->Add(this->textBox_x1);
			this->groupBox1->Location = System::Drawing::Point(425, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(226, 141);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Init square";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Vertex 3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Vertex 2";
			// 
			// textBox_z2
			// 
			this->textBox_z2->Location = System::Drawing::Point(167, 61);
			this->textBox_z2->Name = L"textBox_z2";
			this->textBox_z2->ReadOnly = true;
			this->textBox_z2->Size = System::Drawing::Size(47, 20);
			this->textBox_z2->TabIndex = 0;
			this->textBox_z2->Text = L"1";
			// 
			// textBox_y3
			// 
			this->textBox_y3->Location = System::Drawing::Point(114, 87);
			this->textBox_y3->Name = L"textBox_y3";
			this->textBox_y3->ReadOnly = true;
			this->textBox_y3->Size = System::Drawing::Size(47, 20);
			this->textBox_y3->TabIndex = 0;
			// 
			// textBox_y2
			// 
			this->textBox_y2->Location = System::Drawing::Point(114, 61);
			this->textBox_y2->Name = L"textBox_y2";
			this->textBox_y2->ReadOnly = true;
			this->textBox_y2->Size = System::Drawing::Size(47, 20);
			this->textBox_y2->TabIndex = 0;
			// 
			// textBox_z3
			// 
			this->textBox_z3->Location = System::Drawing::Point(167, 87);
			this->textBox_z3->Name = L"textBox_z3";
			this->textBox_z3->ReadOnly = true;
			this->textBox_z3->Size = System::Drawing::Size(47, 20);
			this->textBox_z3->TabIndex = 0;
			this->textBox_z3->Text = L"1";
			// 
			// textBox_z4
			// 
			this->textBox_z4->Location = System::Drawing::Point(167, 112);
			this->textBox_z4->Name = L"textBox_z4";
			this->textBox_z4->ReadOnly = true;
			this->textBox_z4->Size = System::Drawing::Size(47, 20);
			this->textBox_z4->TabIndex = 0;
			this->textBox_z4->Text = L"1";
			// 
			// textBox_x3
			// 
			this->textBox_x3->Location = System::Drawing::Point(61, 87);
			this->textBox_x3->Name = L"textBox_x3";
			this->textBox_x3->ReadOnly = true;
			this->textBox_x3->Size = System::Drawing::Size(47, 20);
			this->textBox_x3->TabIndex = 0;
			// 
			// textBox_x2
			// 
			this->textBox_x2->Location = System::Drawing::Point(61, 61);
			this->textBox_x2->Name = L"textBox_x2";
			this->textBox_x2->ReadOnly = true;
			this->textBox_x2->Size = System::Drawing::Size(47, 20);
			this->textBox_x2->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox_transz2);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->textBox_transy3);
			this->groupBox2->Controls->Add(this->textBox_transy2);
			this->groupBox2->Controls->Add(this->textBox_transz3);
			this->groupBox2->Controls->Add(this->textBox_transz1);
			this->groupBox2->Controls->Add(this->textBox_transy1);
			this->groupBox2->Controls->Add(this->textBox_transx3);
			this->groupBox2->Controls->Add(this->textBox_transx2);
			this->groupBox2->Controls->Add(this->textBox_transx1);
			this->groupBox2->Location = System::Drawing::Point(657, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(173, 141);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Transfer matrix";
			// 
			// textBox_transz2
			// 
			this->textBox_transz2->Location = System::Drawing::Point(117, 61);
			this->textBox_transz2->Name = L"textBox_transz2";
			this->textBox_transz2->ReadOnly = true;
			this->textBox_transz2->Size = System::Drawing::Size(47, 20);
			this->textBox_transz2->TabIndex = 0;
			this->textBox_transz2->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(135, 19);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"1";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(81, 19);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 13);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(28, 19);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"X";
			// 
			// textBox_transy3
			// 
			this->textBox_transy3->Location = System::Drawing::Point(64, 87);
			this->textBox_transy3->Name = L"textBox_transy3";
			this->textBox_transy3->ReadOnly = true;
			this->textBox_transy3->Size = System::Drawing::Size(47, 20);
			this->textBox_transy3->TabIndex = 0;
			// 
			// textBox_transy2
			// 
			this->textBox_transy2->Location = System::Drawing::Point(64, 61);
			this->textBox_transy2->Name = L"textBox_transy2";
			this->textBox_transy2->ReadOnly = true;
			this->textBox_transy2->Size = System::Drawing::Size(47, 20);
			this->textBox_transy2->TabIndex = 0;
			this->textBox_transy2->Text = L"1";
			// 
			// textBox_transz3
			// 
			this->textBox_transz3->Location = System::Drawing::Point(117, 87);
			this->textBox_transz3->Name = L"textBox_transz3";
			this->textBox_transz3->ReadOnly = true;
			this->textBox_transz3->Size = System::Drawing::Size(47, 20);
			this->textBox_transz3->TabIndex = 0;
			this->textBox_transz3->Text = L"1";
			// 
			// textBox_transz1
			// 
			this->textBox_transz1->Location = System::Drawing::Point(117, 35);
			this->textBox_transz1->Name = L"textBox_transz1";
			this->textBox_transz1->ReadOnly = true;
			this->textBox_transz1->Size = System::Drawing::Size(47, 20);
			this->textBox_transz1->TabIndex = 0;
			this->textBox_transz1->Text = L"0";
			// 
			// textBox_transy1
			// 
			this->textBox_transy1->Location = System::Drawing::Point(64, 35);
			this->textBox_transy1->Name = L"textBox_transy1";
			this->textBox_transy1->ReadOnly = true;
			this->textBox_transy1->Size = System::Drawing::Size(47, 20);
			this->textBox_transy1->TabIndex = 0;
			this->textBox_transy1->Text = L"0";
			// 
			// textBox_transx3
			// 
			this->textBox_transx3->Location = System::Drawing::Point(11, 87);
			this->textBox_transx3->Name = L"textBox_transx3";
			this->textBox_transx3->ReadOnly = true;
			this->textBox_transx3->Size = System::Drawing::Size(47, 20);
			this->textBox_transx3->TabIndex = 0;
			// 
			// textBox_transx2
			// 
			this->textBox_transx2->Location = System::Drawing::Point(11, 61);
			this->textBox_transx2->Name = L"textBox_transx2";
			this->textBox_transx2->ReadOnly = true;
			this->textBox_transx2->Size = System::Drawing::Size(47, 20);
			this->textBox_transx2->TabIndex = 0;
			this->textBox_transx2->Text = L"0";
			// 
			// textBox_transx1
			// 
			this->textBox_transx1->Location = System::Drawing::Point(11, 35);
			this->textBox_transx1->Name = L"textBox_transx1";
			this->textBox_transx1->ReadOnly = true;
			this->textBox_transx1->Size = System::Drawing::Size(47, 20);
			this->textBox_transx1->TabIndex = 0;
			this->textBox_transx1->Text = L"1";
			// 
			// button_transfer
			// 
			this->button_transfer->Location = System::Drawing::Point(657, 159);
			this->button_transfer->Name = L"button_transfer";
			this->button_transfer->Size = System::Drawing::Size(58, 41);
			this->button_transfer->TabIndex = 2;
			this->button_transfer->Text = L"Transfer";
			this->button_transfer->UseVisualStyleBackColor = true;
			this->button_transfer->Click += gcnew System::EventHandler(this, &Form1::button_transfer_Click);
			// 
			// textBox_transx
			// 
			this->textBox_transx->Location = System::Drawing::Point(721, 170);
			this->textBox_transx->Name = L"textBox_transx";
			this->textBox_transx->Size = System::Drawing::Size(47, 20);
			this->textBox_transx->TabIndex = 0;
			this->textBox_transx->Text = L"20";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(738, 154);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"X";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(791, 154);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Y";
			// 
			// textBox_transy
			// 
			this->textBox_transy->Location = System::Drawing::Point(774, 170);
			this->textBox_transy->Name = L"textBox_transy";
			this->textBox_transy->Size = System::Drawing::Size(47, 20);
			this->textBox_transy->TabIndex = 0;
			this->textBox_transy->Text = L"20";
			// 
			// textBox_scalex
			// 
			this->textBox_scalex->Location = System::Drawing::Point(900, 170);
			this->textBox_scalex->Name = L"textBox_scalex";
			this->textBox_scalex->Size = System::Drawing::Size(47, 20);
			this->textBox_scalex->TabIndex = 0;
			this->textBox_scalex->Text = L"1,5";
			// 
			// textBox_scaley
			// 
			this->textBox_scaley->Location = System::Drawing::Point(953, 170);
			this->textBox_scaley->Name = L"textBox_scaley";
			this->textBox_scaley->Size = System::Drawing::Size(47, 20);
			this->textBox_scaley->TabIndex = 0;
			this->textBox_scaley->Text = L"1,5";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(917, 154);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(14, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"X";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(970, 154);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(14, 13);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Y";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox_scalez2);
			this->groupBox3->Controls->Add(this->label15);
			this->groupBox3->Controls->Add(this->label16);
			this->groupBox3->Controls->Add(this->label17);
			this->groupBox3->Controls->Add(this->textBox_scaley3);
			this->groupBox3->Controls->Add(this->textBox_scaley2);
			this->groupBox3->Controls->Add(this->textBox_scalez3);
			this->groupBox3->Controls->Add(this->textBox_scalez1);
			this->groupBox3->Controls->Add(this->textBox_scaley1);
			this->groupBox3->Controls->Add(this->textBox_scalex3);
			this->groupBox3->Controls->Add(this->textBox_scalex2);
			this->groupBox3->Controls->Add(this->textBox_scalex1);
			this->groupBox3->Location = System::Drawing::Point(836, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(173, 141);
			this->groupBox3->TabIndex = 1;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Scale matrix";
			// 
			// textBox_scalez2
			// 
			this->textBox_scalez2->Location = System::Drawing::Point(117, 61);
			this->textBox_scalez2->Name = L"textBox_scalez2";
			this->textBox_scalez2->ReadOnly = true;
			this->textBox_scalez2->Size = System::Drawing::Size(47, 20);
			this->textBox_scalez2->TabIndex = 0;
			this->textBox_scalez2->Text = L"0";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(135, 19);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(13, 13);
			this->label15->TabIndex = 1;
			this->label15->Text = L"1";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(81, 19);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(14, 13);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Y";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(28, 19);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(14, 13);
			this->label17->TabIndex = 1;
			this->label17->Text = L"X";
			// 
			// textBox_scaley3
			// 
			this->textBox_scaley3->Location = System::Drawing::Point(64, 87);
			this->textBox_scaley3->Name = L"textBox_scaley3";
			this->textBox_scaley3->ReadOnly = true;
			this->textBox_scaley3->Size = System::Drawing::Size(47, 20);
			this->textBox_scaley3->TabIndex = 0;
			this->textBox_scaley3->Text = L"0";
			// 
			// textBox_scaley2
			// 
			this->textBox_scaley2->Location = System::Drawing::Point(64, 61);
			this->textBox_scaley2->Name = L"textBox_scaley2";
			this->textBox_scaley2->ReadOnly = true;
			this->textBox_scaley2->Size = System::Drawing::Size(47, 20);
			this->textBox_scaley2->TabIndex = 0;
			// 
			// textBox_scalez3
			// 
			this->textBox_scalez3->Location = System::Drawing::Point(117, 87);
			this->textBox_scalez3->Name = L"textBox_scalez3";
			this->textBox_scalez3->ReadOnly = true;
			this->textBox_scalez3->Size = System::Drawing::Size(47, 20);
			this->textBox_scalez3->TabIndex = 0;
			this->textBox_scalez3->Text = L"1";
			// 
			// textBox_scalez1
			// 
			this->textBox_scalez1->Location = System::Drawing::Point(117, 35);
			this->textBox_scalez1->Name = L"textBox_scalez1";
			this->textBox_scalez1->ReadOnly = true;
			this->textBox_scalez1->Size = System::Drawing::Size(47, 20);
			this->textBox_scalez1->TabIndex = 0;
			this->textBox_scalez1->Text = L"0";
			// 
			// textBox_scaley1
			// 
			this->textBox_scaley1->Location = System::Drawing::Point(64, 35);
			this->textBox_scaley1->Name = L"textBox_scaley1";
			this->textBox_scaley1->ReadOnly = true;
			this->textBox_scaley1->Size = System::Drawing::Size(47, 20);
			this->textBox_scaley1->TabIndex = 0;
			this->textBox_scaley1->Text = L"0";
			// 
			// textBox_scalex3
			// 
			this->textBox_scalex3->Location = System::Drawing::Point(11, 87);
			this->textBox_scalex3->Name = L"textBox_scalex3";
			this->textBox_scalex3->ReadOnly = true;
			this->textBox_scalex3->Size = System::Drawing::Size(47, 20);
			this->textBox_scalex3->TabIndex = 0;
			this->textBox_scalex3->Text = L"0";
			// 
			// textBox_scalex2
			// 
			this->textBox_scalex2->Location = System::Drawing::Point(11, 61);
			this->textBox_scalex2->Name = L"textBox_scalex2";
			this->textBox_scalex2->ReadOnly = true;
			this->textBox_scalex2->Size = System::Drawing::Size(47, 20);
			this->textBox_scalex2->TabIndex = 0;
			this->textBox_scalex2->Text = L"0";
			// 
			// textBox_scalex1
			// 
			this->textBox_scalex1->Location = System::Drawing::Point(11, 35);
			this->textBox_scalex1->Name = L"textBox_scalex1";
			this->textBox_scalex1->ReadOnly = true;
			this->textBox_scalex1->Size = System::Drawing::Size(47, 20);
			this->textBox_scalex1->TabIndex = 0;
			// 
			// button_scale
			// 
			this->button_scale->Location = System::Drawing::Point(836, 159);
			this->button_scale->Name = L"button_scale";
			this->button_scale->Size = System::Drawing::Size(58, 41);
			this->button_scale->TabIndex = 2;
			this->button_scale->Text = L"Scale";
			this->button_scale->UseVisualStyleBackColor = true;
			this->button_scale->Click += gcnew System::EventHandler(this, &Form1::button_scale_Click);
			// 
			// textBox_rotatealpha
			// 
			this->textBox_rotatealpha->Location = System::Drawing::Point(1079, 170);
			this->textBox_rotatealpha->Name = L"textBox_rotatealpha";
			this->textBox_rotatealpha->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatealpha->TabIndex = 0;
			this->textBox_rotatealpha->Text = L"45";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(1086, 154);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(34, 13);
			this->label18->TabIndex = 1;
			this->label18->Text = L"Alpha";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox_rotatez2);
			this->groupBox4->Controls->Add(this->label20);
			this->groupBox4->Controls->Add(this->label21);
			this->groupBox4->Controls->Add(this->label22);
			this->groupBox4->Controls->Add(this->textBox_rotatey3);
			this->groupBox4->Controls->Add(this->textBox_rotatey2);
			this->groupBox4->Controls->Add(this->textBox_rotatez3);
			this->groupBox4->Controls->Add(this->textBox_rotatez1);
			this->groupBox4->Controls->Add(this->textBox_rotatey1);
			this->groupBox4->Controls->Add(this->textBox_rotatex3);
			this->groupBox4->Controls->Add(this->textBox_rotatex2);
			this->groupBox4->Controls->Add(this->textBox_rotatex1);
			this->groupBox4->Location = System::Drawing::Point(1015, 12);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(173, 141);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Rotate matrix";
			// 
			// textBox_rotatez2
			// 
			this->textBox_rotatez2->Location = System::Drawing::Point(117, 61);
			this->textBox_rotatez2->Name = L"textBox_rotatez2";
			this->textBox_rotatez2->ReadOnly = true;
			this->textBox_rotatez2->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatez2->TabIndex = 0;
			this->textBox_rotatez2->Text = L"0";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(135, 19);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(13, 13);
			this->label20->TabIndex = 1;
			this->label20->Text = L"1";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(81, 19);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(14, 13);
			this->label21->TabIndex = 1;
			this->label21->Text = L"Y";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(28, 19);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(14, 13);
			this->label22->TabIndex = 1;
			this->label22->Text = L"X";
			// 
			// textBox_rotatey3
			// 
			this->textBox_rotatey3->Location = System::Drawing::Point(64, 87);
			this->textBox_rotatey3->Name = L"textBox_rotatey3";
			this->textBox_rotatey3->ReadOnly = true;
			this->textBox_rotatey3->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatey3->TabIndex = 0;
			this->textBox_rotatey3->Text = L"0";
			// 
			// textBox_rotatey2
			// 
			this->textBox_rotatey2->Location = System::Drawing::Point(64, 61);
			this->textBox_rotatey2->Name = L"textBox_rotatey2";
			this->textBox_rotatey2->ReadOnly = true;
			this->textBox_rotatey2->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatey2->TabIndex = 0;
			// 
			// textBox_rotatez3
			// 
			this->textBox_rotatez3->Location = System::Drawing::Point(117, 87);
			this->textBox_rotatez3->Name = L"textBox_rotatez3";
			this->textBox_rotatez3->ReadOnly = true;
			this->textBox_rotatez3->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatez3->TabIndex = 0;
			this->textBox_rotatez3->Text = L"1";
			// 
			// textBox_rotatez1
			// 
			this->textBox_rotatez1->Location = System::Drawing::Point(117, 35);
			this->textBox_rotatez1->Name = L"textBox_rotatez1";
			this->textBox_rotatez1->ReadOnly = true;
			this->textBox_rotatez1->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatez1->TabIndex = 0;
			this->textBox_rotatez1->Text = L"0";
			// 
			// textBox_rotatey1
			// 
			this->textBox_rotatey1->Location = System::Drawing::Point(64, 35);
			this->textBox_rotatey1->Name = L"textBox_rotatey1";
			this->textBox_rotatey1->ReadOnly = true;
			this->textBox_rotatey1->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatey1->TabIndex = 0;
			// 
			// textBox_rotatex3
			// 
			this->textBox_rotatex3->Location = System::Drawing::Point(11, 87);
			this->textBox_rotatex3->Name = L"textBox_rotatex3";
			this->textBox_rotatex3->ReadOnly = true;
			this->textBox_rotatex3->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatex3->TabIndex = 0;
			this->textBox_rotatex3->Text = L"0";
			// 
			// textBox_rotatex2
			// 
			this->textBox_rotatex2->Location = System::Drawing::Point(11, 61);
			this->textBox_rotatex2->Name = L"textBox_rotatex2";
			this->textBox_rotatex2->ReadOnly = true;
			this->textBox_rotatex2->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatex2->TabIndex = 0;
			// 
			// textBox_rotatex1
			// 
			this->textBox_rotatex1->Location = System::Drawing::Point(11, 35);
			this->textBox_rotatex1->Name = L"textBox_rotatex1";
			this->textBox_rotatex1->ReadOnly = true;
			this->textBox_rotatex1->Size = System::Drawing::Size(47, 20);
			this->textBox_rotatex1->TabIndex = 0;
			// 
			// button_rotate
			// 
			this->button_rotate->Location = System::Drawing::Point(1015, 159);
			this->button_rotate->Name = L"button_rotate";
			this->button_rotate->Size = System::Drawing::Size(58, 41);
			this->button_rotate->TabIndex = 2;
			this->button_rotate->Text = L"Rotate";
			this->button_rotate->UseVisualStyleBackColor = true;
			this->button_rotate->Click += gcnew System::EventHandler(this, &Form1::button_rotate_Click);
			// 
			// button_mirror
			// 
			this->button_mirror->Location = System::Drawing::Point(657, 254);
			this->button_mirror->Name = L"button_mirror";
			this->button_mirror->Size = System::Drawing::Size(58, 41);
			this->button_mirror->TabIndex = 2;
			this->button_mirror->Text = L"Mirror";
			this->button_mirror->UseVisualStyleBackColor = true;
			this->button_mirror->Click += gcnew System::EventHandler(this, &Form1::button_mirror_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(765, 266);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(31, 20);
			this->numericUpDown1->TabIndex = 3;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(722, 268);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(37, 13);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Vertex";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1197, 349);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button_mirror);
			this->Controls->Add(this->button_rotate);
			this->Controls->Add(this->button_scale);
			this->Controls->Add(this->button_transfer);
			this->Controls->Add(this->btn_draw);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox_scaley);
			this->Controls->Add(this->textBox_rotatealpha);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox_scalex);
			this->Controls->Add(this->textBox_transy);
			this->Controls->Add(this->textBox_transx);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btn_draw_Click(System::Object^ sender, System::EventArgs^ e) {
		// считывание введенных пользователем координат в матрицу. Использует //-ся функция Convert::ToInt32 для преобразования типов данных

		hmg_p[0][0] = Convert::ToInt32(textBox_x1->Text);
		textBox_y1->Text = textBox_x1->Text;
		hmg_p[0][1] = Convert::ToInt32(textBox_y1->Text);
		hmg_p[0][2] = Convert::ToInt32(textBox_z1->Text);

		textBox_x2->Text = textBox_x4->Text;
		hmg_p[1][0] = Convert::ToInt32(textBox_x2->Text);
		textBox_y2->Text = textBox_y1->Text;
		hmg_p[1][1] = Convert::ToInt32(textBox_y2->Text);
		hmg_p[1][2] = Convert::ToInt32(textBox_z2->Text);

		textBox_y4->Text = textBox_x4->Text;
		hmg_p[3][0] = Convert::ToInt32(textBox_x4->Text);
		hmg_p[3][1] = Convert::ToInt32(textBox_y4->Text);
		hmg_p[3][2] = Convert::ToInt32(textBox_z4->Text);

		textBox_x3->Text = textBox_x1->Text;
		hmg_p[2][0] = Convert::ToInt32(textBox_x3->Text);
		textBox_y3->Text = textBox_y4->Text;
		hmg_p[2][1] = Convert::ToInt32(textBox_y3->Text);
		hmg_p[2][2] = Convert::ToInt32(textBox_z3->Text);

		hmg2dek(vert_num, hmg_p, dek_p); // вызов функции перевода координат из однородных в экранные
		pictureBox1->Refresh(); // вызов перерисовки элемента pictureBox.
	}

private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	//int side = x2 - x1;
	// 
	//e->Graphics->DrawRectangle(System::Drawing::Pens::Red, x1, y1, side+10, side);

	int x1 = dek_p[0][0];
	int y1 = dek_p[0][1];
	//int z1 = dek_p[0][2];
	int x2 = dek_p[1][0];
	int y2 = dek_p[1][1];
	//int z2 = dek_p[1][2];
	int x3 = dek_p[2][0];
	int y3 = dek_p[2][1];
	//int z3 = dek_p[2][2];
	int x4 = dek_p[3][0];
	int y4 = dek_p[3][1];
	//int z4 = dek_p[3][2];

	e->Graphics->DrawLine(System::Drawing::Pens::Red, x1, y1, x2, y2);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x1, y1, x3, y3);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x2, y2, x4, y4);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x3, y3, x4, y4);
}

private: System::Void button_transfer_Click(System::Object^ sender, System::EventArgs^ e) {
	double matrix_T_loc1[dimension][dimension] = { 0 };// матрица преобразования

	textBox_transx3->Text = textBox_transx->Text;
	textBox_transy3->Text = textBox_transy->Text;

	int cx = Convert::ToDouble(textBox_transx3->Text);
	int cy = Convert::ToDouble(textBox_transy3->Text);
	make_trans_mat(cx, cy, matrix_T_loc1);

	double result_mat1[vert_num][dimension] = { 0 };
	matrix_mult(vert_num, hmg_p, matrix_T_loc1, result_mat1);

	hmg2dek(vert_num, result_mat1, dek_p); // вызов функции перевода координат из однородных в экранные

	for (int i = 0; i < vert_num; i++)
		for (int j = 0; j < dimension; j++)
			hmg_p[i][j] = result_mat1[i][j];

	pictureBox1->Refresh(); // вызов перерисовки элемента pictureBox.
}
private: System::Void button_scale_Click(System::Object^ sender, System::EventArgs^ e) {
	double matrix_T_loc1[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc2[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc3[dimension][dimension] = { 0 };// матрица преобразования

	int cx = (dek_p[0][0] + dek_p[1][0] + dek_p[2][0] + dek_p[3][0]) / 4;
	int cy = (dek_p[0][1] + dek_p[1][1] + dek_p[2][1] + dek_p[3][1]) / 4;

	make_trans_mat(-cx, -cy, matrix_T_loc1);
	make_trans_mat(cx, cy, matrix_T_loc3);

	textBox_scalex1->Text = textBox_scalex->Text;
	matrix_T_loc2[0][0] = Convert::ToDouble(textBox_scalex1->Text);
	matrix_T_loc2[0][1] = Convert::ToDouble(textBox_scaley1->Text);
	matrix_T_loc2[0][2] = Convert::ToDouble(textBox_scalez1->Text);

	matrix_T_loc2[1][0] = Convert::ToDouble(textBox_scalex2->Text);
	textBox_scaley2->Text = textBox_scaley->Text;
	matrix_T_loc2[1][1] = Convert::ToDouble(textBox_scaley2->Text);
	matrix_T_loc2[1][2] = Convert::ToDouble(textBox_scalez2->Text);

	matrix_T_loc2[2][0] = Convert::ToDouble(textBox_scalex3->Text);
	matrix_T_loc2[2][1] = Convert::ToDouble(textBox_scaley3->Text);
	matrix_T_loc2[2][2] = Convert::ToDouble(textBox_scalez3->Text);

	double result_mat1[vert_num][dimension] = { 0 };
	double result_mat2[vert_num][dimension] = { 0 };

	matrix_mult(vert_num, hmg_p, matrix_T_loc1, result_mat1);
	matrix_mult(vert_num, result_mat1, matrix_T_loc2, result_mat2);
	matrix_mult(vert_num, result_mat2, matrix_T_loc3, result_mat1);

	hmg2dek(vert_num, result_mat1, dek_p); // вызов функции перевода координат из однородных в экранные

	for (int i = 0; i < vert_num; i++)
		for (int j = 0; j < dimension; j++)
			hmg_p[i][j] = result_mat1[i][j];

	pictureBox1->Refresh(); // вызов перерисовки элемента pictureBox.
}
private: System::Void button_rotate_Click(System::Object^ sender, System::EventArgs^ e) {
	double matrix_T_loc1[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc2[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc3[dimension][dimension] = { 0 };// матрица преобразования

	int cx = (dek_p[0][0] + dek_p[1][0] + dek_p[2][0] + dek_p[3][0]) / 4;
	int cy = (dek_p[0][1] + dek_p[1][1] + dek_p[2][1] + dek_p[3][1]) / 4;

	make_trans_mat(-cx, -cy, matrix_T_loc1);
	make_trans_mat(cx, cy, matrix_T_loc3);

	double alpha = (Convert::ToDouble(textBox_rotatealpha->Text) * (acos(-1))) / 180;

	textBox_rotatex1->Text = (cos(alpha)).ToString();
	matrix_T_loc2[0][0] = Convert::ToDouble(textBox_rotatex1->Text);
	textBox_rotatey1->Text = (-sin(alpha)).ToString();
	matrix_T_loc2[0][1] = Convert::ToDouble(textBox_rotatey1->Text);
	matrix_T_loc2[0][2] = Convert::ToDouble(textBox_rotatez1->Text);

	textBox_rotatex2->Text = (sin(alpha)).ToString();
	matrix_T_loc2[1][0] = Convert::ToDouble(textBox_rotatex2->Text);
	textBox_rotatey2->Text = (cos(alpha)).ToString();
	matrix_T_loc2[1][1] = Convert::ToDouble(textBox_rotatey2->Text);
	matrix_T_loc2[1][2] = Convert::ToDouble(textBox_rotatez2->Text);

	matrix_T_loc2[2][0] = Convert::ToDouble(textBox_rotatex3->Text);
	matrix_T_loc2[2][1] = Convert::ToDouble(textBox_rotatey3->Text);
	matrix_T_loc2[2][2] = Convert::ToDouble(textBox_rotatez3->Text);

	double result_mat1[vert_num][dimension] = { 0 };
	double result_mat2[vert_num][dimension] = { 0 };

	matrix_mult(vert_num, hmg_p, matrix_T_loc1, result_mat1);
	matrix_mult(vert_num, result_mat1, matrix_T_loc2, result_mat2);
	matrix_mult(vert_num, result_mat2, matrix_T_loc3, result_mat1);

	hmg2dek(vert_num, result_mat1, dek_p); // вызов функции перевода координат из однородных в экранные

	for (int i = 0; i < vert_num; i++)
		for (int j = 0; j < dimension; j++)
			hmg_p[i][j] = result_mat1[i][j];

	pictureBox1->Refresh(); // вызов перерисовки элемента pictureBox.
}
private: System::Void button_mirror_Click(System::Object^ sender, System::EventArgs^ e) {
	double matrix_T_loc1[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc2[dimension][dimension] = { 0 };// матрица преобразования
	double matrix_T_loc3[dimension][dimension] = { 0 };// матрица преобразования

	int vertex = Convert::ToInt32(numericUpDown1->Value);

	int cx = dek_p[vertex - 1][0];
	int cy = dek_p[vertex - 1][1];

	make_trans_mat(-cx, -cy, matrix_T_loc1);
	make_trans_mat(cx, cy, matrix_T_loc3);

	double alpha = acos(-1);

	// Set up the rotation matrix
	matrix_T_loc2[0][0] = cos(alpha);
	matrix_T_loc2[0][1] = -sin(alpha);
	matrix_T_loc2[0][2] = 0;

	matrix_T_loc2[1][0] = sin(alpha);
	matrix_T_loc2[1][1] = cos(alpha);
	matrix_T_loc2[1][2] = 0;

	matrix_T_loc2[2][0] = 0;
	matrix_T_loc2[2][1] = 0;
	matrix_T_loc2[2][2] = 1;

	double result_mat1[vert_num][dimension] = { 0 };
	double result_mat2[vert_num][dimension] = { 0 };

	matrix_mult(vert_num, hmg_p, matrix_T_loc1, result_mat1);
	matrix_mult(vert_num, result_mat1, matrix_T_loc2, result_mat2);
	matrix_mult(vert_num, result_mat2, matrix_T_loc3, result_mat1);

	hmg2dek(vert_num, result_mat1, dek_p); // вызов функции перевода координат из однородных в экранные

	for (int i = 0; i < vert_num; i++)
		for (int j = 0; j < dimension; j++)
			hmg_p[i][j] = result_mat1[i][j];

	pictureBox1->Refresh(); // вызов перерисовки элемента pictureBox.
}
};
}
#pragma once

#include <math.h>

#define deg2rad (acos(-1))/180


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// углы в радианах для проекций
	const double phi = 35.26 * deg2rad; // для димметрии
	const double psy = 45.0 * deg2rad; // для изометрии
	const double alpha = 30.0 * deg2rad; // для Кавалье и Кабине

	// координата для центральной проекции
	const double d = 300; 

	const int vert_num = 12; // количество вершин фигуры
	const int dimension = 4; // число столбцов матрицы однородных координат      //3-для двумерной графики, 4 для трехмерной

	//матрицы общие
	double hmg_p[vert_num][dimension]			  = { 0 }; // матрица однородных координат фигуры
	int	   dek_p[vert_num][dimension - 1]		  = { 0 }; // матрица экранных координат фигуры
	//double compose_matrix[dimension][dimension]	  = { 0 }; // матрица преобразования

	//матрицы проекций
	double matrix_Front[dimension][dimension] = // матрица вида спереди
	{ 1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 0,
	0, 0, 0, 1 };

	double matrix_Center[dimension][dimension] = //центральная
	{ 1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 0, 1 / d,
	0, 0, 0, 1 };

	double matrix_Dimetry[dimension][dimension] = { 1, 0, 0, 0, 
	0,	cos(phi),	sin(phi),	0, 
	0,	-sin(phi),	cos(phi),	0, 
	0,	0,			0,			1 };

	double matrix_Cabinet[dimension][dimension] = { 1, 0, 0, 0,
	0,					1,					0,	0,
	-0.5*cos(alpha),	-0.5*sin(alpha),	0,	0,
	0,					0,					0,	1 };

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

	private: System::Void update_textBoxes(){
		textBox_x1->Text = Convert::ToString(hmg_p[0][0]);
		textBox_y1->Text = Convert::ToString(hmg_p[0][1]);
		textBox_z1->Text = Convert::ToString(hmg_p[0][2]);
		textBox_w1->Text = Convert::ToString(hmg_p[0][3]);

		textBox_x2->Text = Convert::ToString(hmg_p[1][0]);
		textBox_y2->Text = Convert::ToString(hmg_p[1][1]);
		textBox_z2->Text = Convert::ToString(hmg_p[1][2]);
		textBox_w2->Text = Convert::ToString(hmg_p[1][3]);

		textBox_x3->Text = Convert::ToString(hmg_p[2][0]);
		textBox_y3->Text = Convert::ToString(hmg_p[2][1]);
		textBox_z3->Text = Convert::ToString(hmg_p[2][2]);
		textBox_w3->Text = Convert::ToString(hmg_p[2][3]);

		textBox_x4->Text = Convert::ToString(hmg_p[3][0]);
		textBox_y4->Text = Convert::ToString(hmg_p[3][1]);
		textBox_z4->Text = Convert::ToString(hmg_p[3][2]);
		textBox_w4->Text = Convert::ToString(hmg_p[3][3]);

		textBox_x5->Text = Convert::ToString(hmg_p[4][0]);
		textBox_y5->Text = Convert::ToString(hmg_p[4][1]);
		textBox_z5->Text = Convert::ToString(hmg_p[4][2]);
		textBox_w5->Text = Convert::ToString(hmg_p[4][3]);

		textBox_x6->Text = Convert::ToString(hmg_p[5][0]);
		textBox_y6->Text = Convert::ToString(hmg_p[5][1]);
		textBox_z6->Text = Convert::ToString(hmg_p[5][2]);
		textBox_w6->Text = Convert::ToString(hmg_p[5][3]);

		textBox_x7->Text = Convert::ToString(hmg_p[6][0]);
		textBox_y7->Text = Convert::ToString(hmg_p[6][1]);
		textBox_z7->Text = Convert::ToString(hmg_p[6][2]);
		textBox_w7->Text = Convert::ToString(hmg_p[6][3]);

		textBox_x8->Text = Convert::ToString(hmg_p[7][0]);
		textBox_y8->Text = Convert::ToString(hmg_p[7][1]);
		textBox_z8->Text = Convert::ToString(hmg_p[7][2]);
		textBox_w8->Text = Convert::ToString(hmg_p[7][3]);

		textBox_x9->Text = Convert::ToString(hmg_p[8][0]);
		textBox_y9->Text = Convert::ToString(hmg_p[8][1]);
		textBox_z9->Text = Convert::ToString(hmg_p[8][2]);
		textBox_w9->Text = Convert::ToString(hmg_p[8][3]);

		textBox_x10->Text = Convert::ToString(hmg_p[9][0]);
		textBox_y10->Text = Convert::ToString(hmg_p[9][1]);
		textBox_z10->Text = Convert::ToString(hmg_p[9][2]);
		textBox_w10->Text = Convert::ToString(hmg_p[9][3]);

		textBox_x11->Text = Convert::ToString(hmg_p[10][0]);
		textBox_y11->Text = Convert::ToString(hmg_p[10][1]);
		textBox_z11->Text = Convert::ToString(hmg_p[10][2]);
		textBox_w11->Text = Convert::ToString(hmg_p[10][3]);

		textBox_x12->Text = Convert::ToString(hmg_p[11][0]);
		textBox_y12->Text = Convert::ToString(hmg_p[11][1]);
		textBox_z12->Text = Convert::ToString(hmg_p[11][2]);
		textBox_w12->Text = Convert::ToString(hmg_p[11][3]);
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
				System::Windows::Forms::MessageBox::Show("Division by zero is impossible! Check the coordinates of the shape and the transformation matrix");
				break;
			}
		}
	}

//------------------------------------------------------------------------------------------------------------
	private: System::Windows::Forms::PictureBox^ pictureBox_central;
	private: System::Windows::Forms::PictureBox^ pictureBox_front;
	private: System::Windows::Forms::PictureBox^ pictureBox_dimetric;

	private: System::Windows::Forms::PictureBox^ pictureBox_cabinet;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox_z2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_y3;
	private: System::Windows::Forms::TextBox^ textBox_y2;
	private: System::Windows::Forms::TextBox^ textBox_z3;
	private: System::Windows::Forms::TextBox^ textBox_z4;
	private: System::Windows::Forms::TextBox^ textBox_y4;
	private: System::Windows::Forms::TextBox^ textBox_x4;
	private: System::Windows::Forms::TextBox^ textBox_z1;
	private: System::Windows::Forms::TextBox^ textBox_y1;
	private: System::Windows::Forms::TextBox^ textBox_x3;
	private: System::Windows::Forms::TextBox^ textBox_x2;

	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox_w10;

	private: System::Windows::Forms::TextBox^ textBox_w6;

	private: System::Windows::Forms::TextBox^ textBox_w2;

	private: System::Windows::Forms::TextBox^ textBox_z10;

	private: System::Windows::Forms::TextBox^ textBox_z6;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox_y11;

	private: System::Windows::Forms::TextBox^ textBox_y7;
	private: System::Windows::Forms::TextBox^ textBox_y10;


	private: System::Windows::Forms::TextBox^ textBox_y6;
	private: System::Windows::Forms::TextBox^ textBox_w11;


	private: System::Windows::Forms::TextBox^ textBox_w7;

	private: System::Windows::Forms::TextBox^ textBox_w3;

	private: System::Windows::Forms::TextBox^ textBox_z11;

	private: System::Windows::Forms::TextBox^ textBox_z7;
	private: System::Windows::Forms::TextBox^ textBox_w12;


	private: System::Windows::Forms::TextBox^ textBox_w8;

	private: System::Windows::Forms::TextBox^ textBox_z12;
	private: System::Windows::Forms::TextBox^ textBox_w4;


	private: System::Windows::Forms::TextBox^ textBox_y12;
	private: System::Windows::Forms::TextBox^ textBox_z8;


	private: System::Windows::Forms::TextBox^ textBox_y8;
	private: System::Windows::Forms::TextBox^ textBox_w9;


	private: System::Windows::Forms::TextBox^ textBox_w5;

	private: System::Windows::Forms::TextBox^ textBox_x12;


	private: System::Windows::Forms::TextBox^ textBox_x8;
	private: System::Windows::Forms::TextBox^ textBox_z9;
	private: System::Windows::Forms::TextBox^ textBox_w1;




	private: System::Windows::Forms::TextBox^ textBox_z5;


	private: System::Windows::Forms::TextBox^ textBox_y9;

	private: System::Windows::Forms::TextBox^ textBox_y5;


	private: System::Windows::Forms::TextBox^ textBox_x11;

	private: System::Windows::Forms::TextBox^ textBox_x7;
	private: System::Windows::Forms::TextBox^ textBox_x10;


	private: System::Windows::Forms::TextBox^ textBox_x6;
	private: System::Windows::Forms::TextBox^ textBox_x9;




	private: System::Windows::Forms::TextBox^ textBox_x5;

	private: System::Windows::Forms::Button^ btn_draw;
	private: System::Windows::Forms::Button^ btn_rotate;
private: System::Windows::Forms::TextBox^ textBox_rotx1;


	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::TextBox^ textBox_roty1;
private: System::Windows::Forms::TextBox^ textBox_rotz1;




	private: System::Windows::Forms::Label^ label19;
	private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::TextBox^ textBox_degree;

private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::TextBox^ textBox_x1;
private: System::Windows::Forms::GroupBox^ groupBox2;
private: System::Windows::Forms::GroupBox^ groupBox3;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::TextBox^ textBox_height;

private: System::Windows::Forms::TextBox^ textBox_edge;

private: System::Windows::Forms::TextBox^ textBox_centroidy;

private: System::Windows::Forms::TextBox^ textBox_centroidx;
private: System::Windows::Forms::TextBox^ textBox_centroidz;


private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::Button^ btn_init;
private: System::Windows::Forms::TextBox^ textBox_roty2;
private: System::Windows::Forms::TextBox^ textBox_rotz2;


private: System::Windows::Forms::TextBox^ textBox_rotx2;





	protected:

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
			this->pictureBox_central = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_front = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_dimetric = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_cabinet = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->btn_draw = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox_w10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox_y11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_w1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_z1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_y1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_x1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_rotate = (gcnew System::Windows::Forms::Button());
			this->textBox_rotx1 = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox_roty1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotz1 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->textBox_degree = (gcnew System::Windows::Forms::TextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_roty2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotz2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_rotx2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->textBox_height = (gcnew System::Windows::Forms::TextBox());
			this->textBox_centroidy = (gcnew System::Windows::Forms::TextBox());
			this->textBox_centroidx = (gcnew System::Windows::Forms::TextBox());
			this->textBox_edge = (gcnew System::Windows::Forms::TextBox());
			this->btn_init = (gcnew System::Windows::Forms::Button());
			this->textBox_centroidz = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_central))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_front))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_dimetric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_cabinet))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox_central
			// 
			this->pictureBox_central->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox_central->Location = System::Drawing::Point(12, 25);
			this->pictureBox_central->Name = L"pictureBox_central";
			this->pictureBox_central->Size = System::Drawing::Size(450, 400);
			this->pictureBox_central->TabIndex = 1;
			this->pictureBox_central->TabStop = false;
			this->pictureBox_central->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_central_Paint);
			// 
			// pictureBox_front
			// 
			this->pictureBox_front->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox_front->Location = System::Drawing::Point(468, 25);
			this->pictureBox_front->Name = L"pictureBox_front";
			this->pictureBox_front->Size = System::Drawing::Size(450, 400);
			this->pictureBox_front->TabIndex = 1;
			this->pictureBox_front->TabStop = false;
			this->pictureBox_front->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_front_Paint);
			// 
			// pictureBox_dimetric
			// 
			this->pictureBox_dimetric->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox_dimetric->Location = System::Drawing::Point(12, 454);
			this->pictureBox_dimetric->Name = L"pictureBox_dimetric";
			this->pictureBox_dimetric->Size = System::Drawing::Size(450, 400);
			this->pictureBox_dimetric->TabIndex = 1;
			this->pictureBox_dimetric->TabStop = false;
			this->pictureBox_dimetric->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_dimetric_Paint);
			// 
			// pictureBox_cabinet
			// 
			this->pictureBox_cabinet->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pictureBox_cabinet->Location = System::Drawing::Point(468, 454);
			this->pictureBox_cabinet->Name = L"pictureBox_cabinet";
			this->pictureBox_cabinet->Size = System::Drawing::Size(450, 400);
			this->pictureBox_cabinet->TabIndex = 1;
			this->pictureBox_cabinet->TabStop = false;
			this->pictureBox_cabinet->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox_cabinet_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->btn_draw);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label26);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label32);
			this->groupBox1->Controls->Add(this->textBox_w10);
			this->groupBox1->Controls->Add(this->textBox_w6);
			this->groupBox1->Controls->Add(this->textBox_w2);
			this->groupBox1->Controls->Add(this->textBox_z10);
			this->groupBox1->Controls->Add(this->textBox_z6);
			this->groupBox1->Controls->Add(this->textBox_z2);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->textBox_y11);
			this->groupBox1->Controls->Add(this->textBox_y7);
			this->groupBox1->Controls->Add(this->textBox_y3);
			this->groupBox1->Controls->Add(this->textBox_y10);
			this->groupBox1->Controls->Add(this->textBox_y6);
			this->groupBox1->Controls->Add(this->textBox_y2);
			this->groupBox1->Controls->Add(this->textBox_w11);
			this->groupBox1->Controls->Add(this->textBox_w7);
			this->groupBox1->Controls->Add(this->textBox_w3);
			this->groupBox1->Controls->Add(this->textBox_z11);
			this->groupBox1->Controls->Add(this->textBox_z7);
			this->groupBox1->Controls->Add(this->textBox_z3);
			this->groupBox1->Controls->Add(this->textBox_w12);
			this->groupBox1->Controls->Add(this->textBox_w8);
			this->groupBox1->Controls->Add(this->textBox_z12);
			this->groupBox1->Controls->Add(this->textBox_w4);
			this->groupBox1->Controls->Add(this->textBox_y12);
			this->groupBox1->Controls->Add(this->textBox_z8);
			this->groupBox1->Controls->Add(this->textBox_y8);
			this->groupBox1->Controls->Add(this->textBox_w9);
			this->groupBox1->Controls->Add(this->textBox_z4);
			this->groupBox1->Controls->Add(this->textBox_w5);
			this->groupBox1->Controls->Add(this->textBox_x12);
			this->groupBox1->Controls->Add(this->textBox_y4);
			this->groupBox1->Controls->Add(this->textBox_x8);
			this->groupBox1->Controls->Add(this->textBox_z9);
			this->groupBox1->Controls->Add(this->textBox_w1);
			this->groupBox1->Controls->Add(this->textBox_z5);
			this->groupBox1->Controls->Add(this->textBox_y9);
			this->groupBox1->Controls->Add(this->textBox_x4);
			this->groupBox1->Controls->Add(this->textBox_y5);
			this->groupBox1->Controls->Add(this->textBox_x11);
			this->groupBox1->Controls->Add(this->textBox_z1);
			this->groupBox1->Controls->Add(this->textBox_x7);
			this->groupBox1->Controls->Add(this->textBox_x10);
			this->groupBox1->Controls->Add(this->textBox_y1);
			this->groupBox1->Controls->Add(this->textBox_x6);
			this->groupBox1->Controls->Add(this->textBox_x9);
			this->groupBox1->Controls->Add(this->textBox_x3);
			this->groupBox1->Controls->Add(this->textBox_x5);
			this->groupBox1->Controls->Add(this->textBox_x2);
			this->groupBox1->Controls->Add(this->textBox_x1);
			this->groupBox1->Location = System::Drawing::Point(924, 145);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(288, 394);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Prism matrix";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(10, 319);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(52, 13);
			this->label16->TabIndex = 1;
			this->label16->Text = L"Vertex 12";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(10, 217);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(46, 13);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Vertex 8";
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
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(10, 294);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(52, 13);
			this->label15->TabIndex = 1;
			this->label15->Text = L"Vertex 11";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(10, 192);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(46, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Vertex 7";
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
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(10, 268);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(52, 13);
			this->label14->TabIndex = 1;
			this->label14->Text = L"Vertex 10";
			// 
			// btn_draw
			// 
			this->btn_draw->Location = System::Drawing::Point(6, 347);
			this->btn_draw->Name = L"btn_draw";
			this->btn_draw->Size = System::Drawing::Size(81, 41);
			this->btn_draw->TabIndex = 3;
			this->btn_draw->Text = L"Draw";
			this->btn_draw->UseVisualStyleBackColor = true;
			this->btn_draw->Click += gcnew System::EventHandler(this, &Form1::btn_draw_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(10, 166);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(46, 13);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Vertex 6";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(10, 38);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(46, 13);
			this->label26->TabIndex = 1;
			this->label26->Text = L"Vertex 1";
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
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(80, 19);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(14, 13);
			this->label32->TabIndex = 1;
			this->label32->Text = L"X";
			// 
			// textBox_w10
			// 
			this->textBox_w10->Location = System::Drawing::Point(223, 265);
			this->textBox_w10->Name = L"textBox_w10";
			this->textBox_w10->ReadOnly = true;
			this->textBox_w10->Size = System::Drawing::Size(47, 20);
			this->textBox_w10->TabIndex = 0;
			this->textBox_w10->Text = L"1";
			// 
			// textBox_w6
			// 
			this->textBox_w6->Location = System::Drawing::Point(223, 163);
			this->textBox_w6->Name = L"textBox_w6";
			this->textBox_w6->ReadOnly = true;
			this->textBox_w6->Size = System::Drawing::Size(47, 20);
			this->textBox_w6->TabIndex = 0;
			this->textBox_w6->Text = L"1";
			// 
			// textBox_w2
			// 
			this->textBox_w2->Location = System::Drawing::Point(223, 61);
			this->textBox_w2->Name = L"textBox_w2";
			this->textBox_w2->ReadOnly = true;
			this->textBox_w2->Size = System::Drawing::Size(47, 20);
			this->textBox_w2->TabIndex = 0;
			this->textBox_w2->Text = L"1";
			// 
			// textBox_z10
			// 
			this->textBox_z10->Location = System::Drawing::Point(170, 265);
			this->textBox_z10->Name = L"textBox_z10";
			this->textBox_z10->Size = System::Drawing::Size(47, 20);
			this->textBox_z10->TabIndex = 0;
			// 
			// textBox_z6
			// 
			this->textBox_z6->Location = System::Drawing::Point(170, 163);
			this->textBox_z6->Name = L"textBox_z6";
			this->textBox_z6->Size = System::Drawing::Size(47, 20);
			this->textBox_z6->TabIndex = 0;
			// 
			// textBox_z2
			// 
			this->textBox_z2->Location = System::Drawing::Point(170, 61);
			this->textBox_z2->Name = L"textBox_z2";
			this->textBox_z2->Size = System::Drawing::Size(47, 20);
			this->textBox_z2->TabIndex = 0;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(241, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(13, 13);
			this->label8->TabIndex = 1;
			this->label8->Text = L"1";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(187, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 1;
			this->label7->Text = L"Z";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(134, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(10, 242);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(46, 13);
			this->label13->TabIndex = 1;
			this->label13->Text = L"Vertex 9";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(10, 140);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(46, 13);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Vertex 5";
			// 
			// textBox_y11
			// 
			this->textBox_y11->Location = System::Drawing::Point(117, 291);
			this->textBox_y11->Name = L"textBox_y11";
			this->textBox_y11->Size = System::Drawing::Size(47, 20);
			this->textBox_y11->TabIndex = 0;
			// 
			// textBox_y7
			// 
			this->textBox_y7->Location = System::Drawing::Point(117, 189);
			this->textBox_y7->Name = L"textBox_y7";
			this->textBox_y7->Size = System::Drawing::Size(47, 20);
			this->textBox_y7->TabIndex = 0;
			// 
			// textBox_y3
			// 
			this->textBox_y3->Location = System::Drawing::Point(117, 87);
			this->textBox_y3->Name = L"textBox_y3";
			this->textBox_y3->Size = System::Drawing::Size(47, 20);
			this->textBox_y3->TabIndex = 0;
			// 
			// textBox_y10
			// 
			this->textBox_y10->Location = System::Drawing::Point(117, 265);
			this->textBox_y10->Name = L"textBox_y10";
			this->textBox_y10->Size = System::Drawing::Size(47, 20);
			this->textBox_y10->TabIndex = 0;
			// 
			// textBox_y6
			// 
			this->textBox_y6->Location = System::Drawing::Point(117, 163);
			this->textBox_y6->Name = L"textBox_y6";
			this->textBox_y6->Size = System::Drawing::Size(47, 20);
			this->textBox_y6->TabIndex = 0;
			// 
			// textBox_y2
			// 
			this->textBox_y2->Location = System::Drawing::Point(117, 61);
			this->textBox_y2->Name = L"textBox_y2";
			this->textBox_y2->Size = System::Drawing::Size(47, 20);
			this->textBox_y2->TabIndex = 0;
			// 
			// textBox_w11
			// 
			this->textBox_w11->Location = System::Drawing::Point(223, 291);
			this->textBox_w11->Name = L"textBox_w11";
			this->textBox_w11->ReadOnly = true;
			this->textBox_w11->Size = System::Drawing::Size(47, 20);
			this->textBox_w11->TabIndex = 0;
			this->textBox_w11->Text = L"1";
			// 
			// textBox_w7
			// 
			this->textBox_w7->Location = System::Drawing::Point(223, 189);
			this->textBox_w7->Name = L"textBox_w7";
			this->textBox_w7->ReadOnly = true;
			this->textBox_w7->Size = System::Drawing::Size(47, 20);
			this->textBox_w7->TabIndex = 0;
			this->textBox_w7->Text = L"1";
			// 
			// textBox_w3
			// 
			this->textBox_w3->Location = System::Drawing::Point(223, 87);
			this->textBox_w3->Name = L"textBox_w3";
			this->textBox_w3->ReadOnly = true;
			this->textBox_w3->Size = System::Drawing::Size(47, 20);
			this->textBox_w3->TabIndex = 0;
			this->textBox_w3->Text = L"1";
			// 
			// textBox_z11
			// 
			this->textBox_z11->Location = System::Drawing::Point(170, 291);
			this->textBox_z11->Name = L"textBox_z11";
			this->textBox_z11->Size = System::Drawing::Size(47, 20);
			this->textBox_z11->TabIndex = 0;
			// 
			// textBox_z7
			// 
			this->textBox_z7->Location = System::Drawing::Point(170, 189);
			this->textBox_z7->Name = L"textBox_z7";
			this->textBox_z7->Size = System::Drawing::Size(47, 20);
			this->textBox_z7->TabIndex = 0;
			// 
			// textBox_z3
			// 
			this->textBox_z3->Location = System::Drawing::Point(170, 87);
			this->textBox_z3->Name = L"textBox_z3";
			this->textBox_z3->Size = System::Drawing::Size(47, 20);
			this->textBox_z3->TabIndex = 0;
			// 
			// textBox_w12
			// 
			this->textBox_w12->Location = System::Drawing::Point(223, 316);
			this->textBox_w12->Name = L"textBox_w12";
			this->textBox_w12->ReadOnly = true;
			this->textBox_w12->Size = System::Drawing::Size(47, 20);
			this->textBox_w12->TabIndex = 0;
			this->textBox_w12->Text = L"1";
			// 
			// textBox_w8
			// 
			this->textBox_w8->Location = System::Drawing::Point(223, 214);
			this->textBox_w8->Name = L"textBox_w8";
			this->textBox_w8->ReadOnly = true;
			this->textBox_w8->Size = System::Drawing::Size(47, 20);
			this->textBox_w8->TabIndex = 0;
			this->textBox_w8->Text = L"1";
			// 
			// textBox_z12
			// 
			this->textBox_z12->Location = System::Drawing::Point(170, 316);
			this->textBox_z12->Name = L"textBox_z12";
			this->textBox_z12->Size = System::Drawing::Size(47, 20);
			this->textBox_z12->TabIndex = 0;
			// 
			// textBox_w4
			// 
			this->textBox_w4->Location = System::Drawing::Point(223, 112);
			this->textBox_w4->Name = L"textBox_w4";
			this->textBox_w4->ReadOnly = true;
			this->textBox_w4->Size = System::Drawing::Size(47, 20);
			this->textBox_w4->TabIndex = 0;
			this->textBox_w4->Text = L"1";
			// 
			// textBox_y12
			// 
			this->textBox_y12->Location = System::Drawing::Point(117, 316);
			this->textBox_y12->Name = L"textBox_y12";
			this->textBox_y12->Size = System::Drawing::Size(47, 20);
			this->textBox_y12->TabIndex = 0;
			// 
			// textBox_z8
			// 
			this->textBox_z8->Location = System::Drawing::Point(170, 214);
			this->textBox_z8->Name = L"textBox_z8";
			this->textBox_z8->Size = System::Drawing::Size(47, 20);
			this->textBox_z8->TabIndex = 0;
			// 
			// textBox_y8
			// 
			this->textBox_y8->Location = System::Drawing::Point(117, 214);
			this->textBox_y8->Name = L"textBox_y8";
			this->textBox_y8->Size = System::Drawing::Size(47, 20);
			this->textBox_y8->TabIndex = 0;
			// 
			// textBox_w9
			// 
			this->textBox_w9->Location = System::Drawing::Point(223, 239);
			this->textBox_w9->Name = L"textBox_w9";
			this->textBox_w9->ReadOnly = true;
			this->textBox_w9->Size = System::Drawing::Size(47, 20);
			this->textBox_w9->TabIndex = 0;
			this->textBox_w9->Text = L"1";
			// 
			// textBox_z4
			// 
			this->textBox_z4->Location = System::Drawing::Point(170, 112);
			this->textBox_z4->Name = L"textBox_z4";
			this->textBox_z4->Size = System::Drawing::Size(47, 20);
			this->textBox_z4->TabIndex = 0;
			// 
			// textBox_w5
			// 
			this->textBox_w5->Location = System::Drawing::Point(223, 137);
			this->textBox_w5->Name = L"textBox_w5";
			this->textBox_w5->ReadOnly = true;
			this->textBox_w5->Size = System::Drawing::Size(47, 20);
			this->textBox_w5->TabIndex = 0;
			this->textBox_w5->Text = L"1";
			// 
			// textBox_x12
			// 
			this->textBox_x12->Location = System::Drawing::Point(64, 316);
			this->textBox_x12->Name = L"textBox_x12";
			this->textBox_x12->Size = System::Drawing::Size(47, 20);
			this->textBox_x12->TabIndex = 0;
			// 
			// textBox_y4
			// 
			this->textBox_y4->Location = System::Drawing::Point(117, 112);
			this->textBox_y4->Name = L"textBox_y4";
			this->textBox_y4->Size = System::Drawing::Size(47, 20);
			this->textBox_y4->TabIndex = 0;
			// 
			// textBox_x8
			// 
			this->textBox_x8->Location = System::Drawing::Point(64, 214);
			this->textBox_x8->Name = L"textBox_x8";
			this->textBox_x8->Size = System::Drawing::Size(47, 20);
			this->textBox_x8->TabIndex = 0;
			// 
			// textBox_z9
			// 
			this->textBox_z9->Location = System::Drawing::Point(170, 239);
			this->textBox_z9->Name = L"textBox_z9";
			this->textBox_z9->Size = System::Drawing::Size(47, 20);
			this->textBox_z9->TabIndex = 0;
			// 
			// textBox_w1
			// 
			this->textBox_w1->Location = System::Drawing::Point(223, 35);
			this->textBox_w1->Name = L"textBox_w1";
			this->textBox_w1->ReadOnly = true;
			this->textBox_w1->Size = System::Drawing::Size(47, 20);
			this->textBox_w1->TabIndex = 0;
			this->textBox_w1->Text = L"1";
			// 
			// textBox_z5
			// 
			this->textBox_z5->Location = System::Drawing::Point(170, 137);
			this->textBox_z5->Name = L"textBox_z5";
			this->textBox_z5->Size = System::Drawing::Size(47, 20);
			this->textBox_z5->TabIndex = 0;
			// 
			// textBox_y9
			// 
			this->textBox_y9->Location = System::Drawing::Point(117, 239);
			this->textBox_y9->Name = L"textBox_y9";
			this->textBox_y9->Size = System::Drawing::Size(47, 20);
			this->textBox_y9->TabIndex = 0;
			// 
			// textBox_x4
			// 
			this->textBox_x4->Location = System::Drawing::Point(64, 112);
			this->textBox_x4->Name = L"textBox_x4";
			this->textBox_x4->Size = System::Drawing::Size(47, 20);
			this->textBox_x4->TabIndex = 0;
			// 
			// textBox_y5
			// 
			this->textBox_y5->Location = System::Drawing::Point(117, 137);
			this->textBox_y5->Name = L"textBox_y5";
			this->textBox_y5->Size = System::Drawing::Size(47, 20);
			this->textBox_y5->TabIndex = 0;
			// 
			// textBox_x11
			// 
			this->textBox_x11->Location = System::Drawing::Point(64, 291);
			this->textBox_x11->Name = L"textBox_x11";
			this->textBox_x11->Size = System::Drawing::Size(47, 20);
			this->textBox_x11->TabIndex = 0;
			// 
			// textBox_z1
			// 
			this->textBox_z1->Location = System::Drawing::Point(170, 35);
			this->textBox_z1->Name = L"textBox_z1";
			this->textBox_z1->Size = System::Drawing::Size(47, 20);
			this->textBox_z1->TabIndex = 0;
			// 
			// textBox_x7
			// 
			this->textBox_x7->Location = System::Drawing::Point(64, 189);
			this->textBox_x7->Name = L"textBox_x7";
			this->textBox_x7->Size = System::Drawing::Size(47, 20);
			this->textBox_x7->TabIndex = 0;
			// 
			// textBox_x10
			// 
			this->textBox_x10->Location = System::Drawing::Point(64, 265);
			this->textBox_x10->Name = L"textBox_x10";
			this->textBox_x10->Size = System::Drawing::Size(47, 20);
			this->textBox_x10->TabIndex = 0;
			// 
			// textBox_y1
			// 
			this->textBox_y1->Location = System::Drawing::Point(117, 35);
			this->textBox_y1->Name = L"textBox_y1";
			this->textBox_y1->Size = System::Drawing::Size(47, 20);
			this->textBox_y1->TabIndex = 0;
			// 
			// textBox_x6
			// 
			this->textBox_x6->Location = System::Drawing::Point(64, 163);
			this->textBox_x6->Name = L"textBox_x6";
			this->textBox_x6->Size = System::Drawing::Size(47, 20);
			this->textBox_x6->TabIndex = 0;
			// 
			// textBox_x9
			// 
			this->textBox_x9->Location = System::Drawing::Point(64, 239);
			this->textBox_x9->Name = L"textBox_x9";
			this->textBox_x9->Size = System::Drawing::Size(47, 20);
			this->textBox_x9->TabIndex = 0;
			// 
			// textBox_x3
			// 
			this->textBox_x3->Location = System::Drawing::Point(64, 87);
			this->textBox_x3->Name = L"textBox_x3";
			this->textBox_x3->Size = System::Drawing::Size(47, 20);
			this->textBox_x3->TabIndex = 0;
			// 
			// textBox_x5
			// 
			this->textBox_x5->Location = System::Drawing::Point(64, 137);
			this->textBox_x5->Name = L"textBox_x5";
			this->textBox_x5->Size = System::Drawing::Size(47, 20);
			this->textBox_x5->TabIndex = 0;
			// 
			// textBox_x2
			// 
			this->textBox_x2->Location = System::Drawing::Point(64, 61);
			this->textBox_x2->Name = L"textBox_x2";
			this->textBox_x2->Size = System::Drawing::Size(47, 20);
			this->textBox_x2->TabIndex = 0;
			// 
			// textBox_x1
			// 
			this->textBox_x1->Location = System::Drawing::Point(64, 35);
			this->textBox_x1->Name = L"textBox_x1";
			this->textBox_x1->Size = System::Drawing::Size(47, 20);
			this->textBox_x1->TabIndex = 0;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(124, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"X";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Central";
			// 
			// btn_rotate
			// 
			this->btn_rotate->Location = System::Drawing::Point(6, 24);
			this->btn_rotate->Name = L"btn_rotate";
			this->btn_rotate->Size = System::Drawing::Size(81, 57);
			this->btn_rotate->TabIndex = 3;
			this->btn_rotate->Text = L"Rotate";
			this->btn_rotate->UseVisualStyleBackColor = true;
			this->btn_rotate->Click += gcnew System::EventHandler(this, &Form1::btn_rotate_Click);
			// 
			// textBox_rotx1
			// 
			this->textBox_rotx1->Location = System::Drawing::Point(139, 30);
			this->textBox_rotx1->Name = L"textBox_rotx1";
			this->textBox_rotx1->Size = System::Drawing::Size(47, 20);
			this->textBox_rotx1->TabIndex = 0;
			this->textBox_rotx1->Text = L"0";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(93, 46);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(40, 13);
			this->label17->TabIndex = 1;
			this->label17->Text = L"around";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(156, 14);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(14, 13);
			this->label18->TabIndex = 1;
			this->label18->Text = L"X";
			// 
			// textBox_roty1
			// 
			this->textBox_roty1->Location = System::Drawing::Point(194, 30);
			this->textBox_roty1->Name = L"textBox_roty1";
			this->textBox_roty1->Size = System::Drawing::Size(47, 20);
			this->textBox_roty1->TabIndex = 0;
			this->textBox_roty1->Text = L"0";
			// 
			// textBox_rotz1
			// 
			this->textBox_rotz1->Location = System::Drawing::Point(247, 30);
			this->textBox_rotz1->Name = L"textBox_rotz1";
			this->textBox_rotz1->Size = System::Drawing::Size(47, 20);
			this->textBox_rotz1->TabIndex = 0;
			this->textBox_rotz1->Text = L"0";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(210, 14);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(14, 13);
			this->label19->TabIndex = 1;
			this->label19->Text = L"Y";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(264, 14);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(14, 13);
			this->label20->TabIndex = 1;
			this->label20->Text = L"Z";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(300, 45);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(16, 13);
			this->label21->TabIndex = 1;
			this->label21->Text = L"at";
			// 
			// textBox_degree
			// 
			this->textBox_degree->Location = System::Drawing::Point(322, 42);
			this->textBox_degree->Name = L"textBox_degree";
			this->textBox_degree->Size = System::Drawing::Size(30, 20);
			this->textBox_degree->TabIndex = 0;
			this->textBox_degree->Text = L"45";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(353, 45);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(11, 13);
			this->label22->TabIndex = 1;
			this->label22->Text = L"°";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(468, 9);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(31, 13);
			this->label23->TabIndex = 1;
			this->label23->Text = L"Front";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(12, 438);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(45, 13);
			this->label24->TabIndex = 1;
			this->label24->Text = L"Dimetric";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(468, 438);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(43, 13);
			this->label25->TabIndex = 1;
			this->label25->Text = L"Cabinet";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btn_rotate);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->label20);
			this->groupBox2->Controls->Add(this->textBox_roty2);
			this->groupBox2->Controls->Add(this->textBox_roty1);
			this->groupBox2->Controls->Add(this->textBox_rotz2);
			this->groupBox2->Controls->Add(this->textBox_rotz1);
			this->groupBox2->Controls->Add(this->textBox_degree);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label21);
			this->groupBox2->Controls->Add(this->label22);
			this->groupBox2->Controls->Add(this->textBox_rotx2);
			this->groupBox2->Controls->Add(this->textBox_rotx1);
			this->groupBox2->Location = System::Drawing::Point(924, 545);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(367, 89);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Rotate";
			// 
			// textBox_roty2
			// 
			this->textBox_roty2->Location = System::Drawing::Point(194, 56);
			this->textBox_roty2->Name = L"textBox_roty2";
			this->textBox_roty2->Size = System::Drawing::Size(47, 20);
			this->textBox_roty2->TabIndex = 0;
			this->textBox_roty2->Text = L"200";
			// 
			// textBox_rotz2
			// 
			this->textBox_rotz2->Location = System::Drawing::Point(247, 56);
			this->textBox_rotz2->Name = L"textBox_rotz2";
			this->textBox_rotz2->Size = System::Drawing::Size(47, 20);
			this->textBox_rotz2->TabIndex = 0;
			this->textBox_rotz2->Text = L"0";
			// 
			// textBox_rotx2
			// 
			this->textBox_rotx2->Location = System::Drawing::Point(139, 56);
			this->textBox_rotx2->Name = L"textBox_rotx2";
			this->textBox_rotx2->Size = System::Drawing::Size(47, 20);
			this->textBox_rotx2->TabIndex = 0;
			this->textBox_rotx2->Text = L"225";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label29);
			this->groupBox3->Controls->Add(this->label28);
			this->groupBox3->Controls->Add(this->label27);
			this->groupBox3->Controls->Add(this->textBox_height);
			this->groupBox3->Controls->Add(this->textBox_centroidy);
			this->groupBox3->Controls->Add(this->textBox_centroidx);
			this->groupBox3->Controls->Add(this->textBox_edge);
			this->groupBox3->Controls->Add(this->btn_init);
			this->groupBox3->Controls->Add(this->textBox_centroidz);
			this->groupBox3->Controls->Add(this->label31);
			this->groupBox3->Controls->Add(this->label30);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Location = System::Drawing::Point(924, 25);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(287, 114);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Prism params";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(11, 36);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(91, 13);
			this->label29->TabIndex = 1;
			this->label29->Text = L"Prism base center";
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(11, 88);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(38, 13);
			this->label28->TabIndex = 1;
			this->label28->Text = L"Height";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(11, 62);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(79, 13);
			this->label27->TabIndex = 1;
			this->label27->Text = L"Edge base size";
			// 
			// textBox_height
			// 
			this->textBox_height->Location = System::Drawing::Point(108, 85);
			this->textBox_height->Name = L"textBox_height";
			this->textBox_height->Size = System::Drawing::Size(47, 20);
			this->textBox_height->TabIndex = 0;
			this->textBox_height->Text = L"100";
			// 
			// textBox_centroidy
			// 
			this->textBox_centroidy->Location = System::Drawing::Point(161, 33);
			this->textBox_centroidy->Name = L"textBox_centroidy";
			this->textBox_centroidy->Size = System::Drawing::Size(47, 20);
			this->textBox_centroidy->TabIndex = 0;
			this->textBox_centroidy->Text = L"200";
			// 
			// textBox_centroidx
			// 
			this->textBox_centroidx->Location = System::Drawing::Point(108, 33);
			this->textBox_centroidx->Name = L"textBox_centroidx";
			this->textBox_centroidx->Size = System::Drawing::Size(47, 20);
			this->textBox_centroidx->TabIndex = 0;
			this->textBox_centroidx->Text = L"225";
			// 
			// textBox_edge
			// 
			this->textBox_edge->Location = System::Drawing::Point(108, 59);
			this->textBox_edge->Name = L"textBox_edge";
			this->textBox_edge->Size = System::Drawing::Size(47, 20);
			this->textBox_edge->TabIndex = 0;
			this->textBox_edge->Text = L"100";
			// 
			// btn_init
			// 
			this->btn_init->Location = System::Drawing::Point(161, 59);
			this->btn_init->Name = L"btn_init";
			this->btn_init->Size = System::Drawing::Size(100, 46);
			this->btn_init->TabIndex = 3;
			this->btn_init->Text = L"Init";
			this->btn_init->UseVisualStyleBackColor = true;
			this->btn_init->Click += gcnew System::EventHandler(this, &Form1::btn_init_Click);
			// 
			// textBox_centroidz
			// 
			this->textBox_centroidz->Location = System::Drawing::Point(214, 33);
			this->textBox_centroidz->Name = L"textBox_centroidz";
			this->textBox_centroidz->Size = System::Drawing::Size(47, 20);
			this->textBox_centroidz->TabIndex = 0;
			this->textBox_centroidz->Text = L"20";
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(230, 18);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(14, 13);
			this->label31->TabIndex = 1;
			this->label31->Text = L"Z";
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(178, 18);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(14, 13);
			this->label30->TabIndex = 1;
			this->label30->Text = L"Y";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 866);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox_cabinet);
			this->Controls->Add(this->pictureBox_dimetric);
			this->Controls->Add(this->pictureBox_front);
			this->Controls->Add(this->pictureBox_central);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_central))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_front))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_dimetric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_cabinet))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void pictureBox_front_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	int x1 = dek_p[0][0];
	int y1 = dek_p[0][1];
	int z1 = dek_p[0][2];

	int x2 = dek_p[1][0];
	int y2 = dek_p[1][1];
	int z2 = dek_p[1][2];

	int x3 = dek_p[2][0];
	int y3 = dek_p[2][1];
	int z3 = dek_p[2][2];

	int x4 = dek_p[3][0];
	int y4 = dek_p[3][1];
	int z4 = dek_p[3][2];

	int x5 = dek_p[4][0];
	int y5 = dek_p[4][1];
	int z5 = dek_p[4][2];

	int x6 = dek_p[5][0];
	int y6 = dek_p[5][1];
	int z6 = dek_p[5][2];

	int x7 = dek_p[6][0];
	int y7 = dek_p[6][1];
	int z7 = dek_p[6][2];

	int x8 = dek_p[7][0];
	int y8 = dek_p[7][1];
	int z8 = dek_p[7][2];

	int x9 = dek_p[8][0];
	int y9 = dek_p[8][1];
	int z9 = dek_p[8][2];

	int x10 = dek_p[9][0];
	int y10 = dek_p[9][1];
	int z10 = dek_p[9][2];

	int x11 = dek_p[10][0];
	int y11 = dek_p[10][1];
	int z11 = dek_p[10][2];

	int x12 = dek_p[11][0];
	int y12 = dek_p[11][1];
	int z12 = dek_p[11][2];

	//верхнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x1, y1, x2, y2);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x2, y2, x3, y3);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x3, y3, x4, y4);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x4, y4, x5, y5);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x5, y5, x6, y6);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x6, y6, x1, y1);

	//нижнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x7, y7, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x8, y8, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x9, y9, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x10, y10, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x11, y11, x12, y12);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x12, y12, x7, y7);

	//рёбры между основаниями (высоты)
	e->Graphics->DrawLine(System::Drawing::Pens::Black, x1, y1, x7, y7);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x2, y2, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x3, y3, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x4, y4, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x5, y5, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x6, y6, x12, y12);
}
private: System::Void pictureBox_central_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	int x1 = dek_p[0][0];
	int y1 = dek_p[0][1];
	int z1 = dek_p[0][2];

	int x2 = dek_p[1][0];
	int y2 = dek_p[1][1];
	int z2 = dek_p[1][2];

	int x3 = dek_p[2][0];
	int y3 = dek_p[2][1];
	int z3 = dek_p[2][2];

	int x4 = dek_p[3][0];
	int y4 = dek_p[3][1];
	int z4 = dek_p[3][2];

	int x5 = dek_p[4][0];
	int y5 = dek_p[4][1];
	int z5 = dek_p[4][2];

	int x6 = dek_p[5][0];
	int y6 = dek_p[5][1];
	int z6 = dek_p[5][2];

	int x7 = dek_p[6][0];
	int y7 = dek_p[6][1];
	int z7 = dek_p[6][2];

	int x8 = dek_p[7][0];
	int y8 = dek_p[7][1];
	int z8 = dek_p[7][2];

	int x9 = dek_p[8][0];
	int y9 = dek_p[8][1];
	int z9 = dek_p[8][2];

	int x10 = dek_p[9][0];
	int y10 = dek_p[9][1];
	int z10 = dek_p[9][2];

	int x11 = dek_p[10][0];
	int y11 = dek_p[10][1];
	int z11 = dek_p[10][2];

	int x12 = dek_p[11][0];
	int y12 = dek_p[11][1];
	int z12 = dek_p[11][2];

	//верхнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x1, y1, x2, y2);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x2, y2, x3, y3);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x3, y3, x4, y4);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x4, y4, x5, y5);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x5, y5, x6, y6);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x6, y6, x1, y1);

	//нижнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x7, y7, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x8, y8, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x9, y9, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x10, y10, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x11, y11, x12, y12);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x12, y12, x7, y7);

	//рёбры между основаниями (высоты)
	e->Graphics->DrawLine(System::Drawing::Pens::Black, x1, y1, x7, y7);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x2, y2, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x3, y3, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x4, y4, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x5, y5, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x6, y6, x12, y12);
}
private: System::Void pictureBox_dimetric_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	int x1 = dek_p[0][0];
	int y1 = dek_p[0][1];
	int z1 = dek_p[0][2];

	int x2 = dek_p[1][0];
	int y2 = dek_p[1][1];
	int z2 = dek_p[1][2];

	int x3 = dek_p[2][0];
	int y3 = dek_p[2][1];
	int z3 = dek_p[2][2];

	int x4 = dek_p[3][0];
	int y4 = dek_p[3][1];
	int z4 = dek_p[3][2];

	int x5 = dek_p[4][0];
	int y5 = dek_p[4][1];
	int z5 = dek_p[4][2];

	int x6 = dek_p[5][0];
	int y6 = dek_p[5][1];
	int z6 = dek_p[5][2];

	int x7 = dek_p[6][0];
	int y7 = dek_p[6][1];
	int z7 = dek_p[6][2];

	int x8 = dek_p[7][0];
	int y8 = dek_p[7][1];
	int z8 = dek_p[7][2];

	int x9 = dek_p[8][0];
	int y9 = dek_p[8][1];
	int z9 = dek_p[8][2];

	int x10 = dek_p[9][0];
	int y10 = dek_p[9][1];
	int z10 = dek_p[9][2];

	int x11 = dek_p[10][0];
	int y11 = dek_p[10][1];
	int z11 = dek_p[10][2];

	int x12 = dek_p[11][0];
	int y12 = dek_p[11][1];
	int z12 = dek_p[11][2];

	//верхнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x1, y1, x2, y2);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x2, y2, x3, y3);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x3, y3, x4, y4);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x4, y4, x5, y5);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x5, y5, x6, y6);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x6, y6, x1, y1);

	//нижнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x7, y7, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x8, y8, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x9, y9, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x10, y10, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x11, y11, x12, y12);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x12, y12, x7, y7);

	//рёбры между основаниями (высоты)
	e->Graphics->DrawLine(System::Drawing::Pens::Black, x1, y1, x7, y7);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x2, y2, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x3, y3, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x4, y4, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x5, y5, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x6, y6, x12, y12);
}
private: System::Void pictureBox_cabinet_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	int x1 = dek_p[0][0];
	int y1 = dek_p[0][1];
	int z1 = dek_p[0][2];

	int x2 = dek_p[1][0];
	int y2 = dek_p[1][1];
	int z2 = dek_p[1][2];

	int x3 = dek_p[2][0];
	int y3 = dek_p[2][1];
	int z3 = dek_p[2][2];

	int x4 = dek_p[3][0];
	int y4 = dek_p[3][1];
	int z4 = dek_p[3][2];

	int x5 = dek_p[4][0];
	int y5 = dek_p[4][1];
	int z5 = dek_p[4][2];

	int x6 = dek_p[5][0];
	int y6 = dek_p[5][1];
	int z6 = dek_p[5][2];

	int x7 = dek_p[6][0];
	int y7 = dek_p[6][1];
	int z7 = dek_p[6][2];

	int x8 = dek_p[7][0];
	int y8 = dek_p[7][1];
	int z8 = dek_p[7][2];

	int x9 = dek_p[8][0];
	int y9 = dek_p[8][1];
	int z9 = dek_p[8][2];

	int x10 = dek_p[9][0];
	int y10 = dek_p[9][1];
	int z10 = dek_p[9][2];

	int x11 = dek_p[10][0];
	int y11 = dek_p[10][1];
	int z11 = dek_p[10][2];

	int x12 = dek_p[11][0];
	int y12 = dek_p[11][1];
	int z12 = dek_p[11][2];

	//верхнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x1, y1, x2, y2);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x2, y2, x3, y3);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x3, y3, x4, y4);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x4, y4, x5, y5);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x5, y5, x6, y6);
	e->Graphics->DrawLine(System::Drawing::Pens::Green, x6, y6, x1, y1);

	//нижнее основание
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x7, y7, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x8, y8, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x9, y9, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x10, y10, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x11, y11, x12, y12);
	e->Graphics->DrawLine(System::Drawing::Pens::Blue, x12, y12, x7, y7);

	//рёбры между основаниями (высоты)
	e->Graphics->DrawLine(System::Drawing::Pens::Black, x1, y1, x7, y7);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x2, y2, x8, y8);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x3, y3, x9, y9);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x4, y4, x10, y10);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x5, y5, x11, y11);
	e->Graphics->DrawLine(System::Drawing::Pens::Red, x6, y6, x12, y12);
}
private: System::Void btn_draw_Click(System::Object^ sender, System::EventArgs^ e) {
	hmg_p[0][0] = Convert::ToDouble(textBox_x1->Text);
	hmg_p[0][1] = Convert::ToDouble(textBox_y1->Text);
	hmg_p[0][2] = Convert::ToDouble(textBox_z1->Text);
	hmg_p[0][3] = Convert::ToDouble(textBox_w1->Text);

	hmg_p[1][0] = Convert::ToDouble(textBox_x2->Text);
	hmg_p[1][1] = Convert::ToDouble(textBox_y2->Text);
	hmg_p[1][2] = Convert::ToDouble(textBox_z2->Text);
	hmg_p[1][3] = Convert::ToDouble(textBox_w2->Text);

	hmg_p[2][0] = Convert::ToDouble(textBox_x3->Text);
	hmg_p[2][1] = Convert::ToDouble(textBox_y3->Text);
	hmg_p[2][2] = Convert::ToDouble(textBox_z3->Text);
	hmg_p[2][3] = Convert::ToDouble(textBox_w3->Text);

	hmg_p[3][0] = Convert::ToDouble(textBox_x4->Text);
	hmg_p[3][1] = Convert::ToDouble(textBox_y4->Text);
	hmg_p[3][2] = Convert::ToDouble(textBox_z4->Text);
	hmg_p[3][3] = Convert::ToDouble(textBox_w4->Text);

	hmg_p[4][0] = Convert::ToDouble(textBox_x5->Text);
	hmg_p[4][1] = Convert::ToDouble(textBox_y5->Text);
	hmg_p[4][2] = Convert::ToDouble(textBox_z5->Text);
	hmg_p[4][3] = Convert::ToDouble(textBox_w5->Text);

	hmg_p[5][0] = Convert::ToDouble(textBox_x6->Text);
	hmg_p[5][1] = Convert::ToDouble(textBox_y6->Text);
	hmg_p[5][2] = Convert::ToDouble(textBox_z6->Text);
	hmg_p[5][3] = Convert::ToDouble(textBox_w6->Text);

	hmg_p[6][0] = Convert::ToDouble(textBox_x7->Text);
	hmg_p[6][1] = Convert::ToDouble(textBox_y7->Text);
	hmg_p[6][2] = Convert::ToDouble(textBox_z7->Text);
	hmg_p[6][3] = Convert::ToDouble(textBox_w7->Text);

	hmg_p[7][0] = Convert::ToDouble(textBox_x8->Text);
	hmg_p[7][1] = Convert::ToDouble(textBox_y8->Text);
	hmg_p[7][2] = Convert::ToDouble(textBox_z8->Text);
	hmg_p[7][3] = Convert::ToDouble(textBox_w8->Text);

	hmg_p[8][0] = Convert::ToDouble(textBox_x9->Text);
	hmg_p[8][1] = Convert::ToDouble(textBox_y9->Text);
	hmg_p[8][2] = Convert::ToDouble(textBox_z9->Text);
	hmg_p[8][3] = Convert::ToDouble(textBox_w9->Text);

	hmg_p[9][0] = Convert::ToDouble(textBox_x10->Text);
	hmg_p[9][1] = Convert::ToDouble(textBox_y10->Text);
	hmg_p[9][2] = Convert::ToDouble(textBox_z10->Text);
	hmg_p[9][3] = Convert::ToDouble(textBox_w10->Text);

	hmg_p[10][0] = Convert::ToDouble(textBox_x11->Text);
	hmg_p[10][1] = Convert::ToDouble(textBox_y11->Text);
	hmg_p[10][2] = Convert::ToDouble(textBox_z11->Text);
	hmg_p[10][3] = Convert::ToDouble(textBox_w11->Text);

	hmg_p[11][0] = Convert::ToDouble(textBox_x12->Text);
	hmg_p[11][1] = Convert::ToDouble(textBox_y12->Text);
	hmg_p[11][2] = Convert::ToDouble(textBox_z12->Text);
	hmg_p[11][3] = Convert::ToDouble(textBox_w12->Text);

	double Result[vert_num][dimension] = { 0 };
	matrix_mult(vert_num, hmg_p, matrix_Center, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_central->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Front, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_front->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Dimetry, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_dimetric->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Cabinet, Result);
	hmg2dek(vert_num, Result, dek_p);
	update_textBoxes();
	pictureBox_cabinet->Refresh();

}
private: System::Void btn_init_Click(System::Object^ sender, System::EventArgs^ e) {
	double centerX = Convert::ToDouble(textBox_centroidx->Text);
	double centerY = Convert::ToDouble(textBox_centroidy->Text);
	double centerZ = Convert::ToDouble(textBox_centroidz->Text);

	double edge = Convert::ToDouble(textBox_edge->Text);

	double height = Convert::ToDouble(textBox_height->Text);

	double angle_rad = 60 * deg2rad;

	hmg_p[0][0] = centerX + edge;
	hmg_p[0][1] = centerY;
	hmg_p[0][2] = centerZ + height;
	hmg_p[0][3] = 1;

	for (int i = 1; i < vert_num / 2; i++) {
		hmg_p[i][0] = centerX + edge * cos(angle_rad * i);
		hmg_p[i][1] = centerY + edge * sin(angle_rad * i);
		hmg_p[i][2] = centerZ + height;
		hmg_p[i][3] = 1;
	}

	hmg_p[6][0] = centerX + edge;
	hmg_p[6][1] = centerY;
	hmg_p[6][2] = centerZ;
	hmg_p[6][3] = 1;

	for (int i = vert_num / 2; i < vert_num; i++) {
		hmg_p[i][0] = centerX + edge * cos(angle_rad * i);
		hmg_p[i][1] = centerY + edge * sin(angle_rad * i);
		hmg_p[i][2] = centerZ;
		hmg_p[i][3] = 1;
	}

	double Result[vert_num][dimension] = { 0 };
	matrix_mult(vert_num, hmg_p, matrix_Center, Result);
	hmg2dek(vert_num, Result, dek_p); 
	pictureBox_central->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Front, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_front->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Dimetry, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_dimetric->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Cabinet, Result);
	hmg2dek(vert_num, Result, dek_p);
	update_textBoxes();
	pictureBox_cabinet->Refresh();
}

private: System::Void btn_rotate_Click(System::Object^ sender, System::EventArgs^ e) {
	double matrix_buf_1[vert_num][dimension] = { 0 };// буфферная матрица преобразования
	double matrix_buf_2[vert_num][dimension] = { 0 };// буфферная матрица преобразования

	double px = Convert::ToDouble(textBox_rotx1->Text);
	double py = Convert::ToDouble(textBox_roty1->Text);
	double pz = Convert::ToDouble(textBox_rotz1->Text);

	double qx = Convert::ToDouble(textBox_rotx2->Text);
	double qy = Convert::ToDouble(textBox_roty2->Text);
	double qz = Convert::ToDouble(textBox_rotz2->Text);

	double cx = hmg_p[0][0];
	double cy = hmg_p[0][1];
	double cz = hmg_p[0][2];

	double alpha = Convert::ToDouble(textBox_degree->Text) * deg2rad;

	// Шаг 1: Перенос P в начало координат-------------------------------------------------------------
	double T[dimension][dimension] = {
	{1, 0, 0, -px},
	{0, 1, 0, -py},
	{0, 0, 1, -pz},
	{0, 0, 0, 1}
	};

	// Шаг 2: Выравнивание вектора PQ с плоскостью XZ-------------------------------------------------------------
	// Рассчитываем угол φ
	double dx = qx - px;
	double dy = qy - py;
	double dz = qz - pz;
	double phi = atan2(dy, dx);

	// Матрица поворота вокруг Z для выравнивания с XZ
	double Rz[dimension][dimension] = {
		{cos(-phi), -sin(-phi), 0, 0},
		{sin(-phi), cos(-phi), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	// Шаг 3: Выравнивание вектора PQ с осью Z-------------------------------------------------------------
	// Рассчитываем угол θ
	double theta = atan2(sqrt(dx * dx + dy * dy), dz);

	// Матрица поворота вокруг Y для выравнивания с Z
	double Ry[dimension][dimension] = {
		{cos(theta), 0, sin(theta), 0},
		{0, 1, 0, 0},
		{-sin(theta), 0, cos(theta), 0},
		{0, 0, 0, 1}
	};

	// Шаг 4: ВПоворот вокруг оси Z-------------------------------------------------------------
	// Матрица поворота вокруг Z на угол alpha
	double Rz_alpha[dimension][dimension] = {
		{cos(alpha), -sin(alpha), 0, 0},
		{sin(alpha), cos(alpha), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	// Шаг 5: Обратные преобразования-------------------------------------------------------------
	// Обратный поворот вокруг Y
	double Ry_inv[dimension][dimension] = {
		{cos(-theta), 0, -sin(-theta), 0},
		{0, 1, 0, 0},
		{sin(-theta), 0, cos(-theta), 0},
		{0, 0, 0, 1}
	};

	// Обратный поворот вокруг Z
	double Rz_inv[dimension][dimension] = {
		{cos(-phi), sin(-phi), 0, 0},
		{-sin(-phi), cos(-phi), 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};

	// Обратный перенос
	double T_inv[dimension][dimension] = {
		{1, 0, 0, px},
		{0, 1, 0, py},
		{0, 0, 1, pz},
		{0, 0, 0, 1}
	};

	matrix_mult(vert_num, hmg_p, T, matrix_buf_1);
	matrix_mult(vert_num, matrix_buf_1, Rz, matrix_buf_2);
	matrix_mult(vert_num, matrix_buf_2, Ry, matrix_buf_1);
	matrix_mult(vert_num, matrix_buf_1, Rz_alpha, matrix_buf_2);
	matrix_mult(vert_num, matrix_buf_2, Ry_inv, matrix_buf_1);
	matrix_mult(vert_num, matrix_buf_1, Rz_inv, matrix_buf_2);
	matrix_mult(vert_num, matrix_buf_2, T_inv, hmg_p);
	//hmg2dek(vert_num, hmg_p, dek_p);

	double Result[vert_num][dimension] = { 0 };
	matrix_mult(vert_num, hmg_p, matrix_Center, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_central->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Front, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_front->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Dimetry, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_dimetric->Refresh();

	matrix_mult(vert_num, hmg_p, matrix_Cabinet, Result);
	hmg2dek(vert_num, Result, dek_p);
	pictureBox_cabinet->Refresh();

	update_textBoxes();
}
};
}

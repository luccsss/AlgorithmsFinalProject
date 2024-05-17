#pragma once
#include "iostream"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Matematica
	/// </summary>
	public ref class Matematica : public System::Windows::Forms::Form
	{
	  int respuesta_jugador;
	  int respuesta_correcta;
	  bool respuesta;
	private:
		SoundPlayer^ boton;
	public:
		Matematica(int nivel)
		{
			InitializeComponent();
			boton= gcnew SoundPlayer("Sonidos//Boton1.wav");

			respuesta = false;
			switch (nivel)
			{
			
			case 2:
				switch (rand()%18)
				{
				case 0: IEjercicioSMayorMenor->Visible = true; respuesta_correcta = 67; break;
				case 1: IIEjercicioNhumanos->Visible = true;  respuesta_correcta = 21; break;
				case 2: IIIEjercicioNcuadro->Visible = true;  respuesta_correcta = 1; break;
				case 3: IVEjercicioNesquema->Visible = true;  respuesta_correcta = 12; break;
				case 4: IXEjercicioNcasa->Visible = true;  respuesta_correcta = 7; break;
				case 5: VIIIEjercicioNEsferas->Visible = true;  respuesta_correcta = 3; break;
				case 6: XEjercicioNpiramideX->Visible = true; respuesta_correcta = 2; break;
				case 7: XIEjercicioNpiramide->Visible = true;  respuesta_correcta = 9; break;
				case 8: XIIEjercicioNdados->Visible = true;  respuesta_correcta = 51; break;
				case 9: XIIIEjercicioNecuacionedad->Visible = true;  respuesta_correcta = 8; break;
				case 10: X1EJERCICIO->Visible = true;  respuesta_correcta = 2; break;
				case 11: X2EJERCICIO2->Visible = true;  respuesta_correcta = 5; break;
				case 12: X3EJERCICIO->Visible = true;  respuesta_correcta = 60; break;
				case 13: X4EJERCICIO->Visible = true;  respuesta_correcta = 106; break;
				case 14: X5EJERCICIO->Visible = true;  respuesta_correcta = 125; break;
				case 15: X6EJERCICIO->Visible = true;  respuesta_correcta = 20; break;
				case 16: X7EJERCICIO->Visible = true;  respuesta_correcta = 70; break;
				case 17: X8EJERCICIO->Visible = true;  respuesta_correcta = 9; break;
				}
				break;
			default:
				break;
			}


			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
	private: System::Windows::Forms::PictureBox^ IEjercicioSMayorMenor;
	private: System::Windows::Forms::PictureBox^ IIEjercicioNhumanos;
	private: System::Windows::Forms::PictureBox^ IIIEjercicioNcuadro;
	private: System::Windows::Forms::PictureBox^ IVEjercicioNesquema;
	private: System::Windows::Forms::PictureBox^ IXEjercicioNcasa;
	private: System::Windows::Forms::PictureBox^ VIIIEjercicioNEsferas;
	private: System::Windows::Forms::PictureBox^ XEjercicioNpiramideX;
	private: System::Windows::Forms::PictureBox^ XIEjercicioNpiramide;
	private: System::Windows::Forms::PictureBox^ XIIEjercicioNdados;
	private: System::Windows::Forms::PictureBox^ XIIIEjercicioNecuacionedad;
	private: System::Windows::Forms::PictureBox^ X1EJERCICIO;
	private: System::Windows::Forms::PictureBox^ X2EJERCICIO2;
	private: System::Windows::Forms::PictureBox^ X3EJERCICIO;
	private: System::Windows::Forms::PictureBox^ X4EJERCICIO;
	private: System::Windows::Forms::PictureBox^ X5EJERCICIO;
	private: System::Windows::Forms::PictureBox^ X6EJERCICIO;
	private: System::Windows::Forms::PictureBox^ X7EJERCICIO;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::NumericUpDown^ darrespuesta;

	private: System::Windows::Forms::PictureBox^ X8EJERCICIO;
		   /// </summary>
		~Matematica()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Matematica::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->IEjercicioSMayorMenor = (gcnew System::Windows::Forms::PictureBox());
			this->IIEjercicioNhumanos = (gcnew System::Windows::Forms::PictureBox());
			this->IIIEjercicioNcuadro = (gcnew System::Windows::Forms::PictureBox());
			this->IVEjercicioNesquema = (gcnew System::Windows::Forms::PictureBox());
			this->IXEjercicioNcasa = (gcnew System::Windows::Forms::PictureBox());
			this->VIIIEjercicioNEsferas = (gcnew System::Windows::Forms::PictureBox());
			this->XEjercicioNpiramideX = (gcnew System::Windows::Forms::PictureBox());
			this->XIEjercicioNpiramide = (gcnew System::Windows::Forms::PictureBox());
			this->XIIEjercicioNdados = (gcnew System::Windows::Forms::PictureBox());
			this->XIIIEjercicioNecuacionedad = (gcnew System::Windows::Forms::PictureBox());
			this->X1EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X2EJERCICIO2 = (gcnew System::Windows::Forms::PictureBox());
			this->X3EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X4EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X5EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X6EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X7EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->X8EJERCICIO = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->darrespuesta = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IEjercicioSMayorMenor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IIEjercicioNhumanos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IIIEjercicioNcuadro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IVEjercicioNesquema))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IXEjercicioNcasa))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VIIIEjercicioNEsferas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XEjercicioNpiramideX))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIEjercicioNpiramide))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIIEjercicioNdados))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIIIEjercicioNecuacionedad))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X1EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X2EJERCICIO2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X3EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X4EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X5EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X6EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X7EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X8EJERCICIO))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darrespuesta))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-16, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(825, 603);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// IEjercicioSMayorMenor
			// 
			this->IEjercicioSMayorMenor->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IEjercicioSMayorMenor.Image")));
			this->IEjercicioSMayorMenor->Location = System::Drawing::Point(123, 96);
			this->IEjercicioSMayorMenor->Name = L"IEjercicioSMayorMenor";
			this->IEjercicioSMayorMenor->Size = System::Drawing::Size(566, 254);
			this->IEjercicioSMayorMenor->TabIndex = 1;
			this->IEjercicioSMayorMenor->TabStop = false;
			this->IEjercicioSMayorMenor->Visible = false;
			// 
			// IIEjercicioNhumanos
			// 
			this->IIEjercicioNhumanos->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IIEjercicioNhumanos.Image")));
			this->IIEjercicioNhumanos->Location = System::Drawing::Point(279, 148);
			this->IIEjercicioNhumanos->Name = L"IIEjercicioNhumanos";
			this->IIEjercicioNhumanos->Size = System::Drawing::Size(247, 155);
			this->IIEjercicioNhumanos->TabIndex = 2;
			this->IIEjercicioNhumanos->TabStop = false;
			this->IIEjercicioNhumanos->Visible = false;
			// 
			// IIIEjercicioNcuadro
			// 
			this->IIIEjercicioNcuadro->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IIIEjercicioNcuadro.Image")));
			this->IIIEjercicioNcuadro->Location = System::Drawing::Point(258, 168);
			this->IIIEjercicioNcuadro->Name = L"IIIEjercicioNcuadro";
			this->IIIEjercicioNcuadro->Size = System::Drawing::Size(292, 125);
			this->IIIEjercicioNcuadro->TabIndex = 3;
			this->IIIEjercicioNcuadro->TabStop = false;
			this->IIIEjercicioNcuadro->Visible = false;
			// 
			// IVEjercicioNesquema
			// 
			this->IVEjercicioNesquema->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IVEjercicioNesquema.Image")));
			this->IVEjercicioNesquema->Location = System::Drawing::Point(279, 168);
			this->IVEjercicioNesquema->Name = L"IVEjercicioNesquema";
			this->IVEjercicioNesquema->Size = System::Drawing::Size(247, 115);
			this->IVEjercicioNesquema->TabIndex = 4;
			this->IVEjercicioNesquema->TabStop = false;
			this->IVEjercicioNesquema->Visible = false;
			// 
			// IXEjercicioNcasa
			// 
			this->IXEjercicioNcasa->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"IXEjercicioNcasa.Image")));
			this->IXEjercicioNcasa->Location = System::Drawing::Point(244, 96);
			this->IXEjercicioNcasa->Name = L"IXEjercicioNcasa";
			this->IXEjercicioNcasa->Size = System::Drawing::Size(306, 298);
			this->IXEjercicioNcasa->TabIndex = 5;
			this->IXEjercicioNcasa->TabStop = false;
			this->IXEjercicioNcasa->Visible = false;
			// 

			// 
			// VIIIEjercicioNEsferas
			// 
			this->VIIIEjercicioNEsferas->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"VIIIEjercicioNEsferas.Image")));
			this->VIIIEjercicioNEsferas->Location = System::Drawing::Point(110, 148);
			this->VIIIEjercicioNEsferas->Name = L"VIIIEjercicioNEsferas";
			this->VIIIEjercicioNEsferas->Size = System::Drawing::Size(590, 183);
			this->VIIIEjercicioNEsferas->TabIndex = 7;
			this->VIIIEjercicioNEsferas->TabStop = false;
			this->VIIIEjercicioNEsferas->Visible = false;
			// 
			// XEjercicioNpiramideX
			// 
			this->XEjercicioNpiramideX->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"XEjercicioNpiramideX.Image")));
			this->XEjercicioNpiramideX->Location = System::Drawing::Point(184, 178);
			this->XEjercicioNpiramideX->Name = L"XEjercicioNpiramideX";
			this->XEjercicioNpiramideX->Size = System::Drawing::Size(437, 153);
			this->XEjercicioNpiramideX->TabIndex = 8;
			this->XEjercicioNpiramideX->TabStop = false;
			this->XEjercicioNpiramideX->Visible = false;
			// 
			// XIEjercicioNpiramide
			// 
			this->XIEjercicioNpiramide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"XIEjercicioNpiramide.Image")));
			this->XIEjercicioNpiramide->Location = System::Drawing::Point(207, 79);
			this->XIEjercicioNpiramide->Name = L"XIEjercicioNpiramide";
			this->XIEjercicioNpiramide->Size = System::Drawing::Size(401, 315);
			this->XIEjercicioNpiramide->TabIndex = 9;
			this->XIEjercicioNpiramide->TabStop = false;
			this->XIEjercicioNpiramide->Visible = false;
			// 
			// XIIEjercicioNdados
			// 
			this->XIIEjercicioNdados->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"XIIEjercicioNdados.Image")));
			this->XIIEjercicioNdados->Location = System::Drawing::Point(207, 96);
			this->XIIEjercicioNdados->Name = L"XIIEjercicioNdados";
			this->XIIEjercicioNdados->Size = System::Drawing::Size(401, 291);
			this->XIIEjercicioNdados->TabIndex = 10;
			this->XIIEjercicioNdados->TabStop = false;
			this->XIIEjercicioNdados->Visible = false;
			// 
			// XIIIEjercicioNecuacionedad
			// 
			this->XIIIEjercicioNecuacionedad->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"XIIIEjercicioNecuacionedad.Image")));
			this->XIIIEjercicioNecuacionedad->Location = System::Drawing::Point(231, 148);
			this->XIIIEjercicioNecuacionedad->Name = L"XIIIEjercicioNecuacionedad";
			this->XIIIEjercicioNecuacionedad->Size = System::Drawing::Size(354, 180);
			this->XIIIEjercicioNecuacionedad->TabIndex = 11;
			this->XIIIEjercicioNecuacionedad->TabStop = false;
			this->XIIIEjercicioNecuacionedad->Visible = false;
			// 
			// X1EJERCICIO
			// 
			this->X1EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X1EJERCICIO.Image")));
			this->X1EJERCICIO->Location = System::Drawing::Point(242, 166);
			this->X1EJERCICIO->Name = L"X1EJERCICIO";
			this->X1EJERCICIO->Size = System::Drawing::Size(343, 162);
			this->X1EJERCICIO->TabIndex = 12;
			this->X1EJERCICIO->TabStop = false;
			this->X1EJERCICIO->Visible = false;
			// 
			// X2EJERCICIO2
			// 
			this->X2EJERCICIO2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X2EJERCICIO2.Image")));
			this->X2EJERCICIO2->Location = System::Drawing::Point(242, 157);
			this->X2EJERCICIO2->Name = L"X2EJERCICIO2";
			this->X2EJERCICIO2->Size = System::Drawing::Size(342, 193);
			this->X2EJERCICIO2->TabIndex = 13;
			this->X2EJERCICIO2->TabStop = false;
			this->X2EJERCICIO2->Visible = false;
			// 
			// X3EJERCICIO
			// 
			this->X3EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X3EJERCICIO.Image")));
			this->X3EJERCICIO->Location = System::Drawing::Point(244, 157);
			this->X3EJERCICIO->Name = L"X3EJERCICIO";
			this->X3EJERCICIO->Size = System::Drawing::Size(342, 202);
			this->X3EJERCICIO->TabIndex = 14;
			this->X3EJERCICIO->TabStop = false;
			this->X3EJERCICIO->Visible = false;
			// 
			// X4EJERCICIO
			// 
			this->X4EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X4EJERCICIO.Image")));
			this->X4EJERCICIO->Location = System::Drawing::Point(233, 183);
			this->X4EJERCICIO->Name = L"X4EJERCICIO";
			this->X4EJERCICIO->Size = System::Drawing::Size(351, 145);
			this->X4EJERCICIO->TabIndex = 15;
			this->X4EJERCICIO->TabStop = false;
			this->X4EJERCICIO->Visible = false;
			// 
			// X5EJERCICIO
			// 
			this->X5EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X5EJERCICIO.Image")));
			this->X5EJERCICIO->Location = System::Drawing::Point(239, 176);
			this->X5EJERCICIO->Name = L"X5EJERCICIO";
			this->X5EJERCICIO->Size = System::Drawing::Size(345, 155);
			this->X5EJERCICIO->TabIndex = 16;
			this->X5EJERCICIO->TabStop = false;
			this->X5EJERCICIO->Visible = false;
			// 
			// X6EJERCICIO
			// 
			this->X6EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X6EJERCICIO.Image")));
			this->X6EJERCICIO->Location = System::Drawing::Point(244, 140);
			this->X6EJERCICIO->Name = L"X6EJERCICIO";
			this->X6EJERCICIO->Size = System::Drawing::Size(335, 254);
			this->X6EJERCICIO->TabIndex = 17;
			this->X6EJERCICIO->TabStop = false;
			this->X6EJERCICIO->Visible = false;
			// 
			// X7EJERCICIO
			// 
			this->X7EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X7EJERCICIO.Image")));
			this->X7EJERCICIO->Location = System::Drawing::Point(233, 182);
			this->X7EJERCICIO->Name = L"X7EJERCICIO";
			this->X7EJERCICIO->Size = System::Drawing::Size(346, 146);
			this->X7EJERCICIO->TabIndex = 18;
			this->X7EJERCICIO->TabStop = false;
			this->X7EJERCICIO->Visible = false;
			// 
			// X8EJERCICIO
			// 
			this->X8EJERCICIO->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"X8EJERCICIO.Image")));
			this->X8EJERCICIO->Location = System::Drawing::Point(239, 189);
			this->X8EJERCICIO->Name = L"X8EJERCICIO";
			this->X8EJERCICIO->Size = System::Drawing::Size(341, 132);
			this->X8EJERCICIO->TabIndex = 19;
			this->X8EJERCICIO->TabStop = false;
			this->X8EJERCICIO->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(487, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 73);
			this->button1->TabIndex = 20;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Matematica::button1_Click);
			// 
			// darrespuesta
			// 
			this->darrespuesta->BackColor = System::Drawing::Color::Lime;
			this->darrespuesta->Location = System::Drawing::Point(159, 446);
			this->darrespuesta->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			this->darrespuesta->Name = L"darrespuesta";
			this->darrespuesta->Size = System::Drawing::Size(120, 20);
			this->darrespuesta->TabIndex = 21;
			// 
			// Matematica
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 566);
			this->Controls->Add(this->darrespuesta);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->X8EJERCICIO);
			this->Controls->Add(this->X7EJERCICIO);
			this->Controls->Add(this->X6EJERCICIO);
			this->Controls->Add(this->X5EJERCICIO);
			this->Controls->Add(this->X4EJERCICIO);
			this->Controls->Add(this->X3EJERCICIO);
			this->Controls->Add(this->X2EJERCICIO2);
			this->Controls->Add(this->X1EJERCICIO);
			this->Controls->Add(this->XIIIEjercicioNecuacionedad);
			this->Controls->Add(this->XIIEjercicioNdados);
			this->Controls->Add(this->XIEjercicioNpiramide);
			this->Controls->Add(this->XEjercicioNpiramideX);
			this->Controls->Add(this->VIIIEjercicioNEsferas);
			this->Controls->Add(this->IXEjercicioNcasa);
			this->Controls->Add(this->IVEjercicioNesquema);
			this->Controls->Add(this->IIIEjercicioNcuadro);
			this->Controls->Add(this->IIEjercicioNhumanos);
			this->Controls->Add(this->IEjercicioSMayorMenor);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Matematica";
			this->Text = L"Matematica";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IEjercicioSMayorMenor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IIEjercicioNhumanos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IIIEjercicioNcuadro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IVEjercicioNesquema))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->IXEjercicioNcasa))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VIIIEjercicioNEsferas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XEjercicioNpiramideX))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIEjercicioNpiramide))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIIEjercicioNdados))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XIIIEjercicioNecuacionedad))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X1EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X2EJERCICIO2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X3EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X4EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X5EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X6EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X7EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->X8EJERCICIO))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darrespuesta))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:
			bool get_respuesta()
			{
				return respuesta;
			}
			void set_respuesta(bool v)
			{
				respuesta = v;
			}
	
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	boton->Play();
	respuesta_jugador = Convert::ToInt32(darrespuesta->Value);
	if (respuesta_correcta == respuesta_jugador) {
		set_respuesta(true);
	} 
	else {
		set_respuesta(false);
	}
	this->Close();
}
};
}

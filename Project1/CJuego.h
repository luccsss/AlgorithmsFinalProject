#pragma once
#include "Matematica.h"
#include "CControladora.h"
#include "Ganar_Perder.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de CJuego
	/// </summary>
	public ref class CJuego : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ Intro;
		SoundPlayer^ SMundo1;
		SoundPlayer^ SMundo2;
		SoundPlayer^ Dispara;
		SoundPlayer^ MenorVida;
		SoundPlayer^ SuperPower;
		SoundPlayer^ Moneda;
	private:
		Bitmap^ img;
	private:
		Graphics^ g;
	private:
		bool aliadoactivador;
		int cuantoasveces;
		int preguntamatematicas;
		int matematica;
		int monedasmaxima;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labeltemp;

	private: System::Windows::Forms::Timer^ timertemporizador;

	private:
		CControladora* obj;
		int temp;
		int min;
	public:
		CJuego(int nivel)
		{
			InitializeComponent();
			srand(time(NULL));
			Intro = gcnew SoundPlayer("Sonidos//Intro.wav");
			SMundo1 = gcnew SoundPlayer("Sonidos//Juego1.wav");
			SMundo2 = gcnew SoundPlayer("Sonidos//Juego2.wav");
			Dispara = gcnew SoundPlayer("Sonidos//Dispara.wav");
			MenorVida = gcnew SoundPlayer("Sonidos//Colision.wav");
			SuperPower = gcnew SoundPlayer("Sonidos//SuperPower.wav");
			Moneda = gcnew SoundPlayer("Sonidos//RecogerMoneda.wav");

			g = this->CreateGraphics();
			matematica = nivel;
			switch (nivel)
			{
			case 1:
				SMundo1->Play();
				img = gcnew Bitmap("Imagenes//Fondito 1.png"); break;
			case 2:
				SMundo2->Play();
			    img = gcnew Bitmap("Imagenes//Fondito 2.png"); break;			
			default:
				break;
			}
			obj = new CControladora(ClientRectangle.Width, ClientRectangle.Height,1);
			temp = 30;
			min = 5;
			aliadoactivador = true;
			cuantoasveces = 0;

			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CJuego()
		{
			if (components)
			{
				delete g;
				delete components;
				delete obj;
				delete img;
				delete Intro;
				delete SMundo1;
				delete SMundo2;
				delete Dispara;
				delete MenorVida; 
				delete SuperPower;
				delete Moneda; 
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labeltemp = (gcnew System::Windows::Forms::Label());
			this->timertemporizador = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &CJuego::timer1_Tick);
			// 
			// labeltemp
			// 
			this->labeltemp->AutoSize = true;
			this->labeltemp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->labeltemp->Location = System::Drawing::Point(844, 33);
			this->labeltemp->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labeltemp->Name = L"labeltemp";
			this->labeltemp->Size = System::Drawing::Size(0, 18);
			this->labeltemp->TabIndex = 0;
			// 
			// timertemporizador
			// 
			this->timertemporizador->Enabled = true;
			this->timertemporizador->Tick += gcnew System::EventHandler(this, &CJuego::timertemporizador_Tick);
			// 
			// CJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(964, 841);
			this->Controls->Add(this->labeltemp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Location = System::Drawing::Point(-4, -2);
			this->Name = L"CJuego";
			this->Text = L"CJuego";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CJuego::CJuego_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CJuego::CJuego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CJuego::CJuego_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void tiempo() {
			if (temp == 0) {
				Ganar_Perder^ pantalla1 = gcnew Ganar_Perder();

				timer1->Enabled = false;
				timertemporizador->Stop();
				pantalla1->perder();
				pantalla1->ShowDialog();
				this->Close();
			}
		}



	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e)
	 {
		 BufferedGraphics^ buffi = BufferedGraphicsManager::Current->Allocate(g, this->ClientRectangle);
		 buffi->Graphics->DrawImage(img, this->ClientRectangle, this->ClientRectangle, GraphicsUnit::Pixel);
		 tiempo();
		 //dibujados
		 obj->dibujardoctor(buffi->Graphics);
		 obj->dibujarmonedas(buffi->Graphics);
		 //animaciones
		 obj->animacinyeciones(buffi->Graphics);
		 obj->animacion_virus(buffi->Graphics);
		 obj->animacionAliado(buffi->Graphics);
		 obj->animaciondisminuirvidas(buffi->Graphics);
		 // colisones
		 obj->colisiones_virus_doctor(buffi->Graphics);
		 obj->colisiones_inyecciones_virus(buffi->Graphics);
		 obj->colision_monedad_doctor(buffi->Graphics);
		 obj->colision_aliado_virus(buffi->Graphics);
		 //Sonidos recoger moneda Y colision
		 if (obj->menosVida())
		 {
			 MenorVida->Play();
		 }
		 if ((obj->monedasRecogidas()==true) && (matematica==1))
		 {
			 Moneda->Play();
		 }
		 // mate
		 if (obj->get_matematicas()) {
			 if (matematica == 2) {
				 timer1->Enabled = false;
				 Matematica^ frmmate = gcnew Matematica(matematica);
				 timertemporizador->Stop();
				 frmmate->ShowDialog();
				 if (frmmate->get_respuesta()) {
					 obj->recoger_monedas(0);
					 timertemporizador->Start();
					 Moneda->Play();
				 }
				 else {
					 obj->recoger_monedas(-11);
					 timertemporizador->Stop();

				 }
			 }
			
			 obj->set_matematicas(false);
			 timer1->Enabled = true;

		 }
		 // eliminar
		 obj->eliminar(buffi->Graphics);
		 // perder
		 if (obj->terminar() || obj->getmonedas()<0) {
			 timer1->Enabled = false;
			 Ganar_Perder^ pantalla2 = gcnew Ganar_Perder();
			 timertemporizador->Stop();
			 pantalla2->perder();
			 pantalla2->ShowDialog();
			 this->Close();
		 }
		 // ganar
		 if (obj->ganar()) {
			 timer1->Enabled = false;
			 Ganar_Perder^ pantalla1 = gcnew Ganar_Perder();
			 timertemporizador->Stop();
			 pantalla1->ganar();
			 pantalla1->ShowDialog();
			 this->Close();
		 }

	
		 buffi->Render(g);
		 delete buffi;
	}
	private: System::Void CJuego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		 switch (e->KeyCode)
		 {
		 case Keys::W:
			 obj->moverdoctor(g, 'W'); break;
		 case Keys::S:
			 obj->moverdoctor(g, 'S'); break;
		 case Keys::A:
			 obj->moverdoctor(g, 'A'); break;
		 case Keys::D:
			 obj->moverdoctor(g, 'D'); break;
		 case Keys::Space:
			 Dispara->Play();
			 obj->agregarinyeciones(); break;
		 case Keys::E:
			 SuperPower->Play();
			 cuantoasveces++;
			 if (aliadoactivador)
			 {
				 obj->agregarAliado('E'); 
			 }
			 if (obj->getNivel() == 1 && cuantoasveces == 2)aliadoactivador = false;
			 break;
		 case Keys::Escape:
			 this->Close();
			 Intro->PlayLooping();
			 break;
		 default:
			 break;
		 }
	}
    private: System::Void CJuego_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	timer1->Enabled = false;
    }
    private: System::Void CJuego_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void timertemporizador_Tick(System::Object^ sender, System::EventArgs^ e) {
		labeltemp->Text = Convert::ToString(min) + ":" + Convert::ToString(temp);
		temp -= 1;
		if (temp == 0 && min != 0)
		{
			min -= 1;
			temp = 59;
		}
		if (temp < 10)
		{
			labeltemp->Text = Convert::ToString(min) + ": 0" + Convert::ToString(temp);
		}
	}
};
}

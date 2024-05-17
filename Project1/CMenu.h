#pragma once
int nivelprincipal;
#include "Creditos.h"
#include "Instruciones.h"
#include "CJuego.h"
#include "Configuracion.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Uso de audios
	using namespace System::Media;

	/// <summary>
	/// Resumen de CMenu
	/// </summary>
	public ref class CMenu : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ intro;
		SoundPlayer^ boton;
		SoundPlayer^ boton2;
	public:
		int nivel;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public:
		bool activador_nivel;

		CMenu(void)
		{
			InitializeComponent();
			//
			intro= gcnew SoundPlayer("Sonidos//Intro.wav");
			boton= gcnew SoundPlayer("Sonidos//Boton1.wav");
			boton2= gcnew SoundPlayer("Sonidos//BotonJugar.wav");

			nivelprincipal = 1;
			activador_nivel = true;
			nivel = 1;
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CMenu()
		{
			if (components)
			{
				delete components;
				delete boton;
				delete boton2;
				delete intro;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ BPlay;
	private: System::Windows::Forms::Button^ button1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CMenu::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->BPlay = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-3, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1304, 751);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &CMenu::pictureBox1_Click);
			// 
			// BPlay
			// 
			this->BPlay->BackColor = System::Drawing::Color::Transparent;
			this->BPlay->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BPlay->ForeColor = System::Drawing::Color::Black;
			this->BPlay->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BPlay.Image")));
			this->BPlay->Location = System::Drawing::Point(867, 225);
			this->BPlay->Name = L"BPlay";
			this->BPlay->Size = System::Drawing::Size(205, 84);
			this->BPlay->TabIndex = 1;
			this->BPlay->UseVisualStyleBackColor = false;
			this->BPlay->Click += gcnew System::EventHandler(this, &CMenu::BPlay_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(878, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(181, 73);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &CMenu::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(329, 557);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(181, 73);
			this->button2->TabIndex = 3;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &CMenu::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(878, 557);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(181, 73);
			this->button3->TabIndex = 4;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &CMenu::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::Black;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(329, 391);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(181, 73);
			this->button4->TabIndex = 5;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &CMenu::button4_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(12, 76);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(656, 108);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// CMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1300, 750);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->BPlay);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CMenu";
			this->Text = L"CMenu";
			this->Load += gcnew System::EventHandler(this, &CMenu::CMenu_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		boton2->Play();
		if (!activador_nivel) {
			CJuego^ juego = gcnew CJuego(nivelprincipal);
			juego->ShowDialog();
		}
		else {
			CJuego^ juego = gcnew CJuego(nivel);
			juego->ShowDialog();
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		boton->Play();
		Configuracion^ confi = gcnew Configuracion();
		confi->ShowDialog();
		nivel = confi->get_nivel();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		boton->Play();
		Application::Exit();
	}

    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		boton->Play();
	Instruciones^ inst = gcnew Instruciones();
	inst->ShowDialog();
    }

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		boton->Play();
		Creditos^ cred = gcnew Creditos();
		cred->ShowDialog();
	}

	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void CMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		intro->PlayLooping();
	}
};
}

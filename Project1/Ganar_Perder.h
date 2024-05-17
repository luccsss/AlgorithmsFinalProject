#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Ganar_Perder
	/// </summary>
	public ref class Ganar_Perder : public System::Windows::Forms::Form
	{
	private:
		SoundPlayer^ SWin;
		SoundPlayer^ Slose;
	public:
		Ganar_Perder(void)
		{
			InitializeComponent();
			SWin = gcnew SoundPlayer("Sonidos//Win.wav");
			Slose = gcnew SoundPlayer("Sonidos//GameOver1.wav");
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Ganar_Perder()
		{
			if (components)
			{
				delete components;
				delete SWin;
				delete Slose;
			}
		}
	private: System::Windows::Forms::PictureBox^ picturePerder;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureGanar;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Ganar_Perder::typeid));
			this->picturePerder = (gcnew System::Windows::Forms::PictureBox());
			this->pictureGanar = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePerder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureGanar))->BeginInit();
			this->SuspendLayout();
			// 
			// picturePerder
			// 
			this->picturePerder->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picturePerder->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picturePerder.Image")));
			this->picturePerder->Location = System::Drawing::Point(0, 0);
			this->picturePerder->Name = L"picturePerder";
			this->picturePerder->Size = System::Drawing::Size(977, 626);
			this->picturePerder->TabIndex = 0;
			this->picturePerder->TabStop = false;
			this->picturePerder->Visible = false;
			// 
			// pictureGanar
			// 
			this->pictureGanar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureGanar.Image")));
			this->pictureGanar->Location = System::Drawing::Point(0, 0);
			this->pictureGanar->Name = L"pictureGanar";
			this->pictureGanar->Size = System::Drawing::Size(977, 626);
			this->pictureGanar->TabIndex = 1;
			this->pictureGanar->TabStop = false;
			this->pictureGanar->Visible = false;
			// 
			// Ganar_Perder
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(977, 626);
			this->Controls->Add(this->pictureGanar);
			this->Controls->Add(this->picturePerder);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Ganar_Perder";
			this->Text = L"Ganar_Perder";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Ganar_Perder::Ganar_Perder_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picturePerder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureGanar))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		void ganar() {
			SWin->Play();
			pictureGanar->Visible = true;
	    }
		void perder() {
			Slose->Play();
			picturePerder->Visible = true;
		}
	private: System::Void Ganar_Perder_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Escape:
			this->Close(); break;
		default:
			break;
		}
	}
	};
}

#pragma once
#include "CMovil.h"

class CMoneda:public CMovil {
public:
	CMoneda() : CMovil(1) {
		Bitmap^ img = gcnew Bitmap("Imagenes//moneda.png");
		x = rand() % 900;
		y = 495 + rand() % ((200 - 1) - 500);
		ancho = img->Width/1;
		alto = img->Height/1;
		iteraXMax = 1;
	}

	void dibujarmoneda(Graphics^ g) {
		Bitmap^ img = gcnew Bitmap("Imagenes//moneda.png");
		Rectangle areamonedaADibujar = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		g->DrawImage(img,getRectangle(), areamonedaADibujar,GraphicsUnit::Pixel);

	}

};
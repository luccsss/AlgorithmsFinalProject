#pragma once
#include "CMovil.h"
class CAliado : public CMovil {
public:
	CAliado() : CMovil(0.3) {
		Bitmap^ img1 = gcnew Bitmap("Imagenes//Inyeccion.png");
		x = 0;
		y = 485 + rand() % ((200 - 1) - 500);
		ancho = img1->Width;
		alto = img1->Height;
		iteraXMax = 0;
		dx = rand() % 3 + 5 ;
	}
	void dibujar(Graphics^ g) {
		Bitmap^ img1 = gcnew Bitmap("Imagenes//Inyeccion.png");
		Rectangle areaSpriteADibujar = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		g->DrawImage(img1, getRectangle(), areaSpriteADibujar, GraphicsUnit::Pixel);
	}
	void mover(Graphics^ g)
	{
		x += dx;
	}
	bool pasoElLimite(Graphics^ g)
	{
		return (x + dx + ancho * zoom > g->VisibleClipBounds.Width);
	}
};
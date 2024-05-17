#pragma once
#include "CMovil.h"
#include "CDoctor.h"
class CInyecciones :public CMovil {
private:

public:

	CInyecciones(Jugador* soldado) : CMovil(0.2) {
		Bitmap^ img = gcnew Bitmap("Imagenes//Inyeccion.png");
		ancho = img->Width;
		alto = img->Height;
		x = soldado->getx() + (soldado->getancho() / 2);
		y = soldado->gety() + (soldado->getalto() / 4);
		dx = 5;
		visible = true;
		delete img;
	};
	~CInyecciones() {};
	void dibujar(Graphics^ g) {
		Bitmap^ img = gcnew Bitmap("Imagenes//Inyeccion.png");
		Rectangle porcion = Rectangle(0, 0, ancho, alto);
		Rectangle zoomSection = Rectangle(x, y, ancho * zoom, alto * zoom);
		g->DrawImage(img, zoomSection, porcion, GraphicsUnit::Pixel);
		g->DrawRectangle(gcnew Pen(Color::Brown, 3.0f), getRectangle());
		delete img;
	}
	void mover(Graphics^ g) {
		x += dx;
	}
	bool pasoElLimite(Graphics^ g)
	{
		return (x + dx + ancho * zoom > g->VisibleClipBounds.Width);
	}
};
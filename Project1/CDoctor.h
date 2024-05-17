#pragma once
#include "CMovil.h"
class Jugador : public CMovil {
public:
	~Jugador() {};
	Jugador() : CMovil(0.5) {
		Bitmap^ img = gcnew Bitmap("Imagenes//Doctor.png"); // llama la imagen
		x = 12;
		y = 500;
		dx = dy = 5;
		ancho = img->Width / 3;
		alto = img->Height / 4;
		iteraX = 2;
		iteraY = 2;
	};
	// metodos 
	void dibujar(Graphics^ g) {
		Bitmap^ img = gcnew Bitmap("Imagenes//Doctor.png");
		Rectangle areaSpriteADibujar = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		g->DrawImage(img, getRectangle(), areaSpriteADibujar, GraphicsUnit::Pixel);
	}
	void moverdoctor(Graphics^ g, char tecla) {
		switch (tecla)
		{
		case 'W':
			if (y - dy >= 500) {
				iteraY = 3;
				iteraX++;
				y -= dy;
			} break;
		case 'A':
			if (x - dx >= 0) {
				iteraY = 1;
				iteraX++;
				x -= dx;
			}break;
		case 'S':
			if (y + dy + alto <= g->VisibleClipBounds.Height+90) {
				iteraY = 0;
				iteraX++;
				y += dy;
			}break;
		case 'D':
			if (x + dy + ancho <= g->VisibleClipBounds.Width+90) {
				iteraY = 2;
				iteraX++;
				x += dx;
			}break;
		default:
			break;
		}
		if (iteraX >= 3) iteraX = 0; // bucle
	}
};
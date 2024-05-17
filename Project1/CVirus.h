#pragma once
#pragma once
#include "CMovil.h"
#define LIMITE_INFERIOR 850
class CVirus :public CMovil
{
private:
	char tipo_virus;
	int nivel;
public:
	~CVirus() {};
	CVirus(int _nivel) :CMovil(3)
	{
		nivel = _nivel;
		int random = rand() % 3;
		if (random == 0) tipo_virus = 'A';
		if (random == 1) tipo_virus = 'R';
		if (random == 2) tipo_virus = 'V';
		Bitmap^ img;
		switch (tipo_virus)
		{
		case 'A':
			img = gcnew Bitmap("Imagenes//Virus 1.png");
			ancho = img->Width;
			alto = img->Height;
			iteraXMax = 1;
			delete img;
			break;
		case 'R':
			img = gcnew Bitmap("Imagenes//Virus2.png");
			ancho = img->Width/6;
			alto = img->Height/1;
			iteraXMax = 5;
			delete img;
			break;
		case 'V':
			img = gcnew Bitmap("Imagenes//virus 3.png");
			ancho = img->Width/8;
			alto = img->Height/1;
			iteraXMax = 7;
			delete img;
			break;
		}
		dx = 3 + rand() % ((7 + 1) - 3);
		dy = 3 + rand() % ((7 + 1) - 3);
		velocidad = 3 + rand() % ((5 + 1) - 3);
		visible = true;
		x = 980;
		y = 440 + rand() % ((200 - 1) - 500);
	}
	void dibujar(Graphics^ g)
	{
		Bitmap^ img;
		switch (tipo_virus)
		{
		case 'A':img = gcnew Bitmap("Imagenes//Virus 1.png"); break;
		case 'R':img = gcnew Bitmap("Imagenes//Virus2.png"); break;
		case 'V':img = gcnew Bitmap("Imagenes//virus 3.png"); break;
		}
		//parte del sprite que se va a dibujar
		Rectangle areaSpriteADibujar = Rectangle(iteraX * ancho, iteraY * alto, ancho, alto);
		//area del personaje en la pantalla
		//getRectangle() es un metodo de la clase Personaje
		g->DrawImage(img, getRectangle(), areaSpriteADibujar, GraphicsUnit::Pixel);
		//retangulo colisionador
		g->DrawRectangle(gcnew Pen(Color::BlueViolet, 3.0f), getRectangle());
		delete img;

	}
	void movervirus(Graphics^ g, int xP, int yP) {
		switch (nivel)
		{
		case 1:
			//horizontal
			dy = 0;
			x -= dx * velocidad;
			iteraX++;
			break;
		case 2:
			//diagonal
			if (x + dx<0 || x + dx + ancho>g->VisibleClipBounds.Width)dx *= -1;
			if (y + dy<260 || y + dy + alto >g->VisibleClipBounds.Height)dy *= -1;
			x += dx;
			y += dy;
			iteraX++;
			break;
		case 3:
			//persecusion
			if (x == xP)
			{
				x += 0;
			}
			else if (x > xP)
			{

				x -= dx;
				iteraX++;
			}
			else if (x < xP)
			{
				x += dx;
				iteraX++;
			}

			if (y == yP)
			{
				y += 0;
				iteraX++;
			}
			else if (y > yP)
			{
				y -= dy;
				iteraX++;
			}
			else if (y < yP)
			{
				y += dy;
				iteraX++;
			}
			break;
		    default:
			break;
		}

		if (iteraX >= iteraXMax) iteraX = 0;
	}
};
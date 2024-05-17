#pragma once
#include "CDoctor.h"
#include "vector"
#include "CInyecciones.h"
#include "CVirus.h"
#include "CMoneda.h"
#include "CCorazon.h"
#include "Aliado.h"

class CControladora {
private:
	int nivel;
	bool SContVida;
	bool SMoneReco;
	int windowWidth;
	int windowHeight;
	int maximodemonedasrecogidas;
	bool activador_mates;
	Jugador* objdoctor;
	CCorazon* objvida; int vidas;
	vector<CInyecciones*> vectorinyeciones;
	vector<CVirus*>vecvirus;
	vector<CMoneda*>vecmoneda; int monedasrecogidas;
	vector<CAliado*>vecaliado;
public:
	~CControladora() {
		for (CInyecciones* inyecion : vectorinyeciones)
		{
			delete inyecion;
		}
		
		vectorinyeciones.clear();
	};

	CControladora(int windowWidth, int windowHeight,int nivel) {
		
		srand(time(NULL));
		SContVida = false;
		SMoneReco = false;
		this->nivel = nivel;
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;
		objdoctor = new Jugador();
		activador_mates = false;
		objvida = new CCorazon(); vidas = 0;
		for (int i = 0; i < 3; i++) { vecvirus.push_back(new CVirus(nivel)); }
		for (int i = 0; i < 10; i++) { vecmoneda.push_back(new CMoneda()); } monedasrecogidas = 0;
		 maximodemonedasrecogidas = 10;
	}
	// agregar aliado
	void agregarAliado(char tecla) {
		switch (tecla)
		{
		case 'E':
			for(int i=0;i<10;i++)
			vecaliado.push_back(new CAliado());
		default:
			break;
		}
	}

	void agregarinyeciones() {
		vectorinyeciones.push_back(new CInyecciones(objdoctor));
	}
	void agregar_inyeciones_aliados() {
		for (int i = 0; i < vecaliado.size(); i++) {
			vecaliado.push_back(new CAliado);
		}
	}
	// dibujar
	void dibujarmonedas(Graphics^ g) {
		for (int i = 0; i < vecmoneda.size(); i++) {
			vecmoneda.at(i)->dibujarmoneda(g);
		}
	}
	void dibujardoctor(Graphics^ g) {
		objdoctor->dibujar(g);
	}
	//movimiento de los personajes
	void moverdoctor(Graphics^ g, char tecla) {
		objdoctor->moverdoctor(g, tecla);
	} 
	//animacion de virus
	void animacinyeciones(Graphics^ g) {
		for (int i = 0; i < vectorinyeciones.size(); i++) {
			vectorinyeciones[i]->mover(g);
			vectorinyeciones[i]->dibujar(g);
			if (vectorinyeciones[i]->pasoElLimite(g))
			{
				vectorinyeciones[i]->setdx(0);
				vectorinyeciones.erase(vectorinyeciones.begin() + i);
			}
		}
	}
	void animacionAliado(Graphics^ g) {
		for (int i = 0; i < vecaliado.size(); i++) {
			vecaliado.at(i)->dibujar(g);
			vecaliado.at(i)->mover(g);
			if (vecaliado.at(i)->pasoElLimite(g)) {
				vecaliado.at(i)->setdx(0);
				vecaliado.erase(vecaliado.begin() + i);
			}
		}
	}
	void animaciondisminuirvidas(Graphics^ g) {
		objvida->setvidas(vidas);
		objvida->dibujar(g);
		objvida->mover(g);
	}
	void animacion_virus(Graphics^ g)
	{
		for (int i = 0; i < vecvirus.size(); i++)
		{
		
			vecvirus.at(i)->dibujar(g);
			vecvirus.at(i)->movervirus(g, objdoctor->getx(), objdoctor->gety());
		}

		for (int i = 0; i < vecvirus.size(); i++)
		{
			if (vecvirus.at(i)->getx() + vecvirus.at(i)->getancho() < 0)
				vecvirus.at(i)->setvisible(false);
	    }
	}
	// colisiones
	void colisiones_virus_doctor(Graphics^ g)
	{
		//crear si son menor a 3 los virus
		if (vecvirus.size() < 3)
			vecvirus.push_back(new CVirus(nivel));

		for (int i = 0; i < vecvirus.size(); i++) {
			if (vecvirus.at(i)->getRectangle().IntersectsWith(objdoctor->getRectangle()))
			{
				vidas++;
				vecvirus.at(i)->setvisible(false);
				SContVida = true;

			}
		}

		
	}
	void colisiones_inyecciones_virus(Graphics^ g)
	{
		for (int i = 0; i < vectorinyeciones.size(); i++) {
			for (int j = 0; j < vecvirus.size(); j++) {
				if (vectorinyeciones.at(i)->determinarcolision(vecvirus.at(j)->getRectangle()))
				{
					vectorinyeciones.at(i)->setvisible(false);
					vecvirus.at(j)->setvisible(false);
				}
			}
		}
	}
	void colision_monedad_doctor(Graphics^ g) {
		for (int i = 0; i < vecmoneda.size(); i++) {
			if (vecmoneda.at(i)->getRectangle().IntersectsWith(objdoctor->getRectangle())) {
				SMoneReco = true;
				monedasrecogidas += 1;
				vecmoneda.at(i)->setvisible(false);
				set_matematicas(true);
			}
		}
	}
	void colision_aliado_virus(Graphics^ g){
	
		for (int i = 0; i < vecaliado.size(); i++) {
			for (int j = 0; j < vecvirus.size(); j++) {
				if (vecaliado.at(i)->determinarcolision(vecvirus.at(j)->getRectangle())) {
					vecaliado.at(i)->setvisible(false);
					vecvirus.at(j)->setvisible(false);
				}
			}
	    }
	}
	// eliminar
	void eliminar(Graphics^ g) {
		for (int j = 0; j < vecvirus.size(); j++)
			if (!vecvirus.at(j)->getvisible())
				vecvirus.erase(vecvirus.begin() + j);

		for (int i = 0; i < vectorinyeciones.size(); i++)
			if (!vectorinyeciones.at(i)->getvisible())
				vectorinyeciones.erase(vectorinyeciones.begin() + i);
		
		for (int i = 0; i < vectorinyeciones.size(); i++)
		{
			if (vectorinyeciones.at(i)->gety() > g->VisibleClipBounds.Width)
				vectorinyeciones.erase(vectorinyeciones.begin() + i);
		}

		for (int i = 0; i < vecmoneda.size(); i++) {
			if (!vecmoneda.at(i)->getvisible()) {
				vecmoneda.erase(vecmoneda.begin() + i);
			}
		}

		for (int i = 0; i < vecaliado.size(); i++) {
			if (!vecaliado.at(i)->getvisible()) {
				vecaliado.erase(vecaliado.begin() + i);
			}
		}
	}
	// OTRO
	int getNivel() { return nivel; }
	// Otros 2
	int getmonedas() {
		return monedasrecogidas;
	}
	bool terminar()
	{
		if (vidas >= 10) {
			return true;
		}
		return false;
	}
	bool ganar() {
		
			if (monedasrecogidas >= maximodemonedasrecogidas) {
				return true;
			}
		
			return false;
	}
	bool get_matematicas()
	{
		return activador_mates;
	}
	void set_matematicas(bool mate)
	{
		activador_mates = mate;
	}
	void recoger_monedas(int p) {
		monedasrecogidas += p;
	}
	
	bool menosVida() {
		if (SContVida)
		{
			SContVida = false;
				return true;
		}
		else false;
	}

	bool monedasRecogidas() {
		if (SMoneReco)
		{
			SMoneReco = false;
				return true;
		}
		else false;
	}
};

#ifndef LNear_h 

#define LNear_h

#include <iostream>
#include <string>
#include <vector>
#include "Localidad.h"


using namespace std;

class LNear{
	friend ostream & operator<<(ostream &, const LNear &);

private:
class NodoL;
NodoL *pr;
NodoL *ul;
Localidad error;
public:
	LNear();

	LNear(const Coleccion &);

	~LNear();

	LNear & operator=(const LNear &);

	bool esVacia();

	int rango();

	void insertaLocalidad(Localidad p, int d);

	int borraLocalidad(string s);

	void borraLocalidades(int k);

	int distLista();

	Localidad & getLocalidad(int i): 
 	
};

class NodoL{
private:
	Localidad localidad;
	int distancia;
	NodoL *next;
	NodoL *prev;

public:
	NodoL(Localidad n){
		distancia=-1;
		next=NULL;
		prev=NULL;
		localidad=Localidad();

	}

	ostream & operator<<(ostream &os, const NodoL &n){
		while(n!=NULL){
			os << n.localidad << " " << "(" << n.distancia << ")" <<endl;
		}
		return os;
	}
}
#endif
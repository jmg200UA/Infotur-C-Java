
#ifndef NODOL_h 

#define NODOL_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NodoL{
	friend ostream & operator<<(ostream &, const NodoL &);

private:
Localidad localidad;
int distancia;
NodoL *next;
NodoL *prev;
public:
	NodoL();

	NodoL(Localidad n);

	NodoL(const Coleccion &);

	~NodoL();

	NodoL & operator=(const Coleccion &);

	NodoL & operator<<(const Coleccion &);
 	
};
#endif
#ifndef Provincia_h 

#define Provincia_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LNear{
	friend ostream & operator<<(ostream &, const Provincia &);

private:
	Localidad lc;
	LNear locprox; //objeto de tipo lista
public:
	Provincia(Localidad l);

	Provincia(const Provincia &);

	~Provincia();

	Provincia & operator=(const LNear &);

	public void calculaCercanas(Coleccion &, int rango);

	public int borraLocalidad(string loc);

	public LNear & getCercanas();

	public string getCostera(Coleccion &);

	public LNear getCosteras(Coleccion &);

	public string getConAeropuerto( );

	
 
 	
};
#endif
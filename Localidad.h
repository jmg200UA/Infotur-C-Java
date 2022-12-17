#ifndef LOCALIDAD_h 

#define LOCALIDAD_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Localidad{
	friend ostream & operator<<(ostream &, const Localidad &);

private:
	string nombre;
	Coordenadas coor;
	InfoTur info;
	int id;

public:
	Localidad();

	Localidad(const Localidad &);

	~Localidad();

	Localidad & operator=(const Localidad &);

	int setCoor();

	void setInfo();

	string getNombre();

	Coordenadas getCoor();

	InfoTur getInfo();

	int getId();
};
#endif




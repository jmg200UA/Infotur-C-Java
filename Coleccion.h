#ifndef COLECCION_h 

#define COLECCION_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Coleccion{
	friend ostream & operator<<(ostream &, const Coleccion &);

private:
vector<vector<char>> mapa;
vector<vector<Localidad>> localidades;
public:
	Coleccion();

	Coleccion(const Coleccion &);

	~Coleccion();

	Coleccion & operator=(const Coleccion &);

	void lectura(string nomfichero);

	vector<vector<char>> getMapa();

	vector<vector<Localidad>> getLocalidades();

	char getCoorMapa(Coordenadas coord);  

	
};
#endif
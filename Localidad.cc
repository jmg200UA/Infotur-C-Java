#include "Localidad.h"

//PArte publica
Localidad::Localidad(string cadena){
	nombre=cadena;
 	id=-1;
 }

 Localidad::Localidad(const Localidad &l){
 	nombre=l.nombre;
 	coor=l.coor;
 	info=l.info;
 	id=l.id;
 }

 Localidad::~Localidad(){
 	nombre=0;
 	coor=0;
 	info=0;
 	id=0;
 }

Localidad::Localidad & operator=(const Localidad &l){
	if(this!=&l){
	 	nombre=l.nombre;
	 	coor=l.coor;
	 	info=l.info;
	 	id=l.id;
	 }
	 return *this;
}

int Localidad::setCoor(int ent1, int ent2, vector<vector<char>> mapa){
//FALTA HACER
}

void Localidad::setInfo(InfoTur inf){
	info=inf;
}

string Localidad::getNombre(){
	return nombre;
}

Coordenadas Localidad::getCoor(){
	return coor;
}

InfoTur Localidad::getInfo(){
	return info;
}

int Localidad::getId(){
	return id;
}

ostream & operator<<(ostream &os, const Localidad &l){
os c.id << "-" << c.nombre << "-" << c.coor.toString() << "\n" << c.info.toString() << endl;
return os;
}






#include "Coordenadas.h"

//PArte publica
Coordenadas::Coordenadas(){
	fila=-1;
	columna=-1;

}

Coordenadas::Coordenadas(int fil, int col){
	if(fil>=0) fila=fil;
	else fila=-1;
	if(col>=0) columna=col;
	else columna=-1;
}

Coordenadas::Coordenadas(const Coordenadas &c){
	fila=c.fila;
	columna=c.columna;
}

Coordenadas::~Coordenadas(){
	fila=0;
	columna=0;
}

Coordenadas & Coordenadas::operator=(const InfoTur &c){ 
	 if(this!=&t){
	 	fila=c.fila;
	 	columna=c.columna;
	 }
	 return *this;
} 

int Coordenadas::getFila(){
	return fila;
}

int Coordenadas::getColumna(){
	return columna;
}

ostream & operator<<(ostream &os, const Coordenadas &c){
os << "(" << c.fila << "," << c.columna << ")";
return os;
}






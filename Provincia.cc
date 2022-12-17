#include "Provincia.h"

//PArte publica
Provincia::Provincia(Localidad l){ // inicializa las demas variables a su valor por defecto
	lc=l;
	locprox=LNear();
 }

 Provincia::Provincia(const Provincia &p){
 	lc=p.lc;
 	locprox=p.locprox;
 }

 Provincia::~Provincia(){
 	lc=NULL;
 	locprox=NULL;
 }

Provincia::Provincia & operator=(const Provincia &l){
	if(this!=&l){
		lc=l.lc;
		locprox=l.locprox;		 
	}
	 return *this;
}

public void Provincia::calculaCercanas(Coleccion &c, int rango){//anade a su lista las localidades del mapa que esten dentro del rango
																//indicado por el 2o parametro segun la distancia, si la lista ya tenia 
																//almacenadas previamente habra que eliminarlas
	//para recorrer hacerlo con getLocalidad
	//c.getLocalidades[i].getCoor() y calcular distancia de Manhattan (distancia entre esta localidad y lc -lc.getCoor- (localidad de Provincia) ) 
	//si la distancia de Manhattan calculada es menor o igual al rango se inserta
	//d(l1,l2) = |x1 −x2|+|y1 −y2|
	int distancia=0;

	if(locprox.esVacia()==false){
		locprox.borraLocalidades(-1);
	}
	for(int i=0;i<c.getLocalidades.size();i++){
			distancia= abs(c.getLocalidades[i].getCoor().getFila() - lc.getCoor().getFila()) + abs(c.getLocalidades[i].getCoor().getColumna() - lc.getCoor().getColumna());
			if(distancia<=rango){
				if(lc.getCoor.getFila()!=c.getLocalidades[i].getFila() || lc.getCoor.getColumna()!=c.getLocalidades[i].getColumna()){
					locprox.insertaLocalidad(c.getLocalidades[i],distancia);
				}
			}
	}

}

public int Provincia::borraLocalidad(string s){ // elimina de su lista de localidades cercanas la localidad cuyo nombre se pasa por
 													// par´ametro, de manera que devuelve la distancia a la que esta´ dicha localidad 
 													//eliminada si la encuentra, y -1 en cualquier otro caso. 	
	return locprox.borraLocalidad(s);
}

public LNear & Provincia::getCercanas(){// devuelve la lista de las localidades ma´s cercanas; si no hay ninguna devuelve una lista vac´ıa; 
	return locprox;
}

public string Provincia::getCostera(Coleccion &c){ // devuelve el nombre de la localidad costera ma´s cercana almacenada en la lista;
													// si no hay ninguna devuelve la cadena “no hay ninguna localidad costera”
string nom="no hay ninguna localidad costera";
	
	if(c.getMapa[lc.getCoor().getFila()][lc.getCoor().getColumna()]=="L"){
		for(int i=0;i<locprox.distLista();i++){
			if(c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+-1][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getFila()][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()-1][locprox.getLocalidad[i].getCoor().getColumna()]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()-1][locprox.getLocalidad[i].getCoor().getColumna()-1] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()][locprox.getLocalidad[i].getCoor().getColumna()-1] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()-1]){
					nom=locprox.getLocalidad[i].getNombre();
			}
		}
	}
	return nom;

//c.getLocalidades[i].getNombre()

}


public LNear Provincia::getCosteras(Coleccion &c){ // devuelve la lista de todas las localidades costeras almacenadas en la lista
													// empezando en la ma´s cercana; si no hay ninguna devuelve una lista vac´ıa

//crear una lista nueva e insertaLocalidad() para las que sean costera
//se utiliza c.getMapa() para comprobar si está en mar y tierra
//si está en tierra (T) y arriba, abajo, izda o dcha tiene mar (M)
Lnear lista=Lnear();
int distancia=0;


	if(c.getMapa[lc.getCoor().getFila()][lc.getCoor().getColumna()]=="L"){
		for(int i=0;i<locprox.distLista();i++){
			if(c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+-1][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getFila()][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()+1]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()-1][locprox.getLocalidad[i].getCoor().getColumna()]=="M" || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()-1][locprox.getLocalidad[i].getCoor().getColumna()-1] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()][locprox.getLocalidad[i].getCoor().getColumna()-1] || c.getMapa[locprox.getLocalidad[i].getCoor().getFila()+1][locprox.getLocalidad[i].getCoor().getColumna()-1]){
					distancia= abs(locprox.getLocalidad[i].getCoor().getFila() - lc.getCoor().getFila()) + abs(locprox.getLocalidad[i].getCoor().getColumna() - lc.getCoor().getColumna());
					lista.insertaLocalidad(locprox.getLocalidad[i],distancia);
			}
		}
	}
	return lista;


}


public string Provincia::getConAeropuerto(){ //si la localidad no tiene aeropuerto devuelve el nombre de la localidad m´as cercana
												// que tenga aeropuerto almacenada en la lista; si ya tiene aeropuerto devuelve la
												// cadena “propio” y si no tiene y no encuentra ninguna devuelve la cadena “sin aeropuerto”
//Tendria que crear un metodo en InfoTur getAeropuerto()?

	string loccerc=" ";
	if(locprox.getLocalidad().getInfo().getAeropuerto()==false){
		loccerc=locprox.getNombre();
	}
	else if(locprox.getLocalidad().getInfo().getAeropuerto()==true){
		loccerc="propio";
	}
	else loccerc="sin aeropuerto";

	return loccerc;

}

ostream & operator<<(ostream &os, const Provincia &p){
os << /*lo q sea*/ << endl;
return os;
}
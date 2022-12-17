#include "Coleccion.h"
#include <fstream>



Coleccion::Coleccion(){}

Coleccion::Coleccion(const Coleccion &c){
	mapa=c.mapa;
	localidades=c.localidades;
}

Coleccion::~Coleccion(){
	mapa=0;
	localidades=0;
}

Coleccion::Coleccion & operator(const Coleccion &c){
	if(this!=&c){
	 	mapa=c.mapa;
	 	localidades=c.localidades;
	 }
	 return *this;
}

void Coleccion::lectura(string nomfichero){
	ifstream archivo;
	string texto;

	archivo.open(nomfichero,ios::in); //abrimos el archivo en modo lectura

	if(archivo.fail()){
		exit(1);
	}

	while(!archivo.eof()){ //mientras no sea el final del archivo
		getline(archivo,texto);
		while(texto!=("<LOCALIDAD>")){
			char [] mapita=linea.c_str());
			vector<mapeta> mapeta();
			for(int i=0;i<mapita.length;i++){
 				mapeta.push_back(mapita[i]);
 			}
 			mapa.push_back(mapeta);
 			getline(archivo,texto);
 		}

 		while(linea!=null){
 					if(texto==("<LOCALIDAD>")){
 						getline(archivo,texto);
	 					String ciudad=texto;
	 					getline(archivo,texto);
	 					vector <string> tokens;
	 					stringstream tokenizar(texto); 
      					string coordenaditas;
      					while(getline(texto, coordenaditas, ' ')){ 
        					tokens.push_back(coordenaditas); 
        				}  
	 					int coord1=atoi(tokens[0].c_str());
	 					int coord2=atoi(tokens[1].c_str());
	 					getline(archivo,texto);

 					}
 					while(linea!=("<LOCALIDAD>")){
 						string top="";
 						boolean aeropuerto=false;
 	 					int museo=0;
 	 					int monumento=0;
 	 					int hotel=0;
 	 					int restaurante=0;
 	 					while(linea==("<LOCALIDAD>")){
 	 						String[] elements=linea.split(" ");
 	 						vector <string> tok;
	 						stringstream toke(texto); 
      						string palabras;
      						while(getline(texto, palabras, ' ')){ 
        						tokens.push_back(palabras); 
        					}  
 	 						if(tok[0].equals("museo")) museo=atoi(tok[1].c_str());
 	 						if(tok[0].equals("monumento")) monumento=atoi(tok[1].c_str());
 	 						if(tok[0].equals("hotel")) hotel=atoi(tok[1].c_str());
 	 						if(tok[0].equals("restaurante")) restaurante=atoi(tok[1].c_str());
 	 						if(tok[0].equals("aeropuerto")) aeropuerto=true;
 	 						if(linea[0]=='*'){
 	 							for(int i=1;i<tok.length;i++){
 	 								top=top+tok[i];
 	 							}
 	 						}
 	 						getline(archivo,texto);
 	 					}
 	 					InfoTur a= InfoTur(museo,monumento,hotel,restaurante,aeropuerto);
 	 					a.setTop(top);
 	 					
 	 					Localidad l=Localidad(ciudad);
 	 					l.setInfo(a);
 	 					l.setCoor(coord1,coord2,mapa);	
 	 					localidades.push_back(l);					
 					}
 				}	
 		}	
	}
}

vector<vector<char>> Coleccion::getMapa(){
	return mapa;
}

vector<vector<Localidad>> Coleccion::getLocalidades(){
	return localidades;
}

char Coleccion::getCoorMapa(Coordenadas coord){
	char caracter; 

 		if(coord.getFila()==-1 || coord.getColumna()==-1) caracter='X';
 		else caracter=mapa.get(coord.getFila()).get(coord.getColumna());

 		return caracter;
}







ostream & operator<<(ostream &os, const Coleccion &c){
	for(int i=0;i<sizeof(c.mapa)/sizeof(c.mapa[0]);i++){
		for(int j=0;j<sizeof(c.mapa[0])/sizeof(c.mapa[0][0]);j++){
			os<<c.mapa[i][j];
		}
	}
}
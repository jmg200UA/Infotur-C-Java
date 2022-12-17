#include "LNear.h"

//PArte publica
LNear::LNear(){
	pr=NULL;
	ul=NULL;
	error=Localidad();
 }

 LNear::LNear(const LNear &l){
 	Nodo *aux, *aux2;
	aux=l.pr;
	pr=ul=NULL;
	while(aux){
		aux2=new NodoL(aux->valor);
		if (first==NULL){
		pr=ul=aux2;
		}
		else{
		ul->next=aux2;
		last=aux2;
		} 
		aux=aux->next;
	}
 }

 LNear::~LNear(){
 	NodoL *aux;
 	while(pr){
 	  aux=pr;
 	  pr=pr->next;
 	  delete aux;
 	} 
 	ul=NULL;

 }

LNear::LNear & operator=(const LNear &l){
	NodoL *aux=l.pr;
	int a=0;
	Localidad loca;
	if(this!=&l){
		while(esVacia()!=false){
		 	while(pr){
		 	  aux=pr;
		 	  pr=pr->next;
		 	  delete aux;
		 	} 
		 	ul=NULL;
		}

		while(aux!=NULL){
			a=aux->distancia;
			loca=aux->localidad;
			insertaLocalidad(loca,a);
			aux=aux->next;
		}



	}
	return *this;
}

bool LNear::esVacia(){ //true o false si la lista esta vacia
	bool vacia=false;
	if(pr==NULL && ul==NULL) vacia=true;

	return vacia;
}

int LNear::rango(){//distancia localidad mas alejada si no hay -1
	int rango=-1;
	if(ul!=NULL){
		rango=ul->distancia;
	}
	//falta hacer

	return rango;
}

void LNear::insertaLocalidad(Localidad p, int d){// crea un nodo con la info pasada por param ordenado, si hay L con = nombre y dist se ignora
	NodoL *nodo= new NodoL(p,d);
	NodoL *aux=pr;
	bool insertado=false;

	if(esVacia()==true){
	pr=nodo;
	ul=nodo;
	}
	else{
		while(aux!=NULL && insertado==false){
			if((aux->distancia)>d){
				if(aux->prev==NULL){
					aux->prev=nodo;
					nodo->next=aux;
					pr=nodo;
					insertado==true;
				}
				else if(aux->prev!=NULL && aux->next!=NULL){
					nodo->next=aux;
					nodo->prev=aux->prev;
					nodo->prev->next=nodo;
					nodo->next->prev=nodo;
					insertado==true;
				}
			}
			else if(strcmp(aux->localidad.getNombre(),p.getNombre())<0){
				if(aux->prev==NULL){
					aux->prev=nodo;
					nodo->next=aux;
					pr=nodo;
					insertado==true;
				}
				else if(aux->prev!=NULL && aux->next!=NULL){
					nodo->next=aux;
					nodo->prev=aux->prev;
					nodo->prev->next=nodo;
					nodo->next->prev=nodo;
					insertado==true;
				}
			}

			else if(aux->next==NULL){
				ul=nodo;
				aux->next=nodo;
				nodo->prev=aux;
				insertado==true;
			}
			aux=aux->next;
		}

	}

	





}

int LNear::borraLocalidad(string s){//elimina de la lista y devuelve la distancia
	int distancia=0;
	NodoL *aux=pr;
	NodoL *aux2=NULL;

	if(aux!=NULL){
		while(aux!=NULL && strcmp((pr.getNombre()),s)){
			aux2=aux;
			aux=aux->next;
			distancia++;
		}
		if(aux==NULL){
			distancia=-1;
		}
		if(aux2==NULL){
			pr=pr->next;
			delete aux;
		}
		else{
			aux2->next=aux->next;
			delete aux;
		}
		
	}

	return distancia;
}

void LNear::borraLocalidades(int k){// elimina de la lista todas las localidades cuya distancia sea superior a k
	NodoL *aux=pr;
	NodoL *aux2=NULL;
	if(aux!=NULL){
		while(aux!=NULL && (aux->distancia)<k){
			aux2=aux;
			aux=aux->next;
		}
		if((aux->distancia)>k){
			aux2=aux->next;
			delete aux;
			aux=aux2;
		}
	}

}

Localidad & LNear::getLocalidad(int i){//devuelve la referencia a la localidad que ocupa la posici´on indicada por el para´metro i en la lista
										//si es vacia se devuelve la Localidad error
	int cont=0;
	NodoL *aux=pr;
	NodoL *aux2=NULL;
	Localidad local();
	while(cont!=i && aux!=NULL){
		aux2=aux;
		aux=aux->next;
		cont++;
	}
	if(aux==NULL){
		return error;
	}
	else return (*aux).localidad;


}

ostream & operator<<(ostream &os, const LNear &l){
	NodoL *aux=pr;
	while(aux!=NULL){
		os << aux << endl;
		aux=aux->next;
	}
return os;
}
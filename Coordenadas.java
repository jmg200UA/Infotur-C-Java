 import java.util.*

 public class Coordenadas{

 	private int fila, columna;

 	public Coordenadas(){
 		fila=-1;
 		columna=-1;
 	}

 	public Coordenadas(int f, int c){
 		if(f>=0) fila=f;
 		else fila=-1;
 		if(c>=0) columna=c;
 		else columna=-1;
 	}

 	public int getFila(){
 		return fila;
 	}

 	public int getColumna(){
 		return columna;
 	}

 	public String toString(){
 		String dev= "(" + fila + "," + columna + ")";
 		return dev;
 	}




 	
 }
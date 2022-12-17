import java.util.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

 public class Coleccion{

 	private ArrayList<ArrayList<Character>> mapa;
 	private ArrayList<Localidad> localidades;


 	public Coleccion(){
		mapa= new ArrayList<ArrayList<Character>>();
		localidades= new ArrayList<Localidad>();
	}


 	public void lectura(String nomfichero){

 		FileReader fr=null;
 		BufferedReader br=null;
 		String linea=null;

 		try{
 			fr=new FileReader(nomfichero);
 			br=new BufferedReader(fr);

 			linea=br.readLine();

 				while(linea.equalsIgnoreCase("<LOCALIDAD>")==false){
 					char[] mapita=linea.toCharArray();
 					ArrayList<Character> mapeta= new ArrayList<Character>();
 					for(int i=0;i<mapita.length;i++){
 						mapeta.add(mapita[i]);
 					}
					
					mapa.add(mapeta);
 					linea=br.readLine();
 				}
 					
 				


 				while(linea!=null){
					String ciudad="";
					int coord1=0;
					int coord2=0;
 					if(linea.equalsIgnoreCase("<LOCALIDAD>")==true){
 						linea=br.readLine();
	 					ciudad=linea;
	 					linea=br.readLine();
	 					String[] elems = linea.split(" ");
	 					coord1=Integer.parseInt(elems[0]);
	 					coord2=Integer.parseInt(elems[1]);
	 					linea=br.readLine();

 					}
 					if(linea.equalsIgnoreCase("<LOCALIDAD>")==false){
 						String top="";
 						boolean aeropuerto=false;
 	 					int museo=0;
 	 					int monumento=0;
 	 					int hotel=0;
 	 					int restaurante=0;
 	 					while(linea!=null && linea.equalsIgnoreCase("<LOCALIDAD>")==false){
 	 						String[] elements=linea.split(" ");
 	 						if(elements[0].equals("museo")) museo=Integer.parseInt(elements[1]);
 	 						if(elements[0].equals("monumento")) monumento=Integer.parseInt(elements[1]);
 	 						if(elements[0].equals("hotel")) hotel=Integer.parseInt(elements[1]);
 	 						if(elements[0].equals("restaurante")) restaurante=Integer.parseInt(elements[1]);
 	 						if(elements[0].equals("aeropuerto")) aeropuerto=true;
 	 						if(linea.charAt(0)=='*'){
 	 							top=linea;
 	 						}
 	 						linea=br.readLine(); 
 	 					}
 	 					InfoTur a= new InfoTur(museo,monumento,hotel,restaurante,aeropuerto);
 	 					a.setTop(top);
 	 					
 	 					Localidad l= new Localidad(ciudad);
 	 					l.setInfo(a);
 	 						
						if(l.setCoor(coord1,coord2,mapa)!=-1){
 	 						localidades.add(l);
						}					
 					}
 				}		
 		} catch(IOException e){}








 	}

 	public ArrayList<ArrayList<Character>> getMapa(){
 		return mapa;
 	}

 	public ArrayList<Localidad> getLocalidades(){
 		return localidades;
 	}

 	public char getCoorMapa(Coordenadas coord){

 		char caracter; 

 		if(coord.getFila()==-1 || coord.getColumna()==-1) caracter='X';
 		else caracter=mapa.get(coord.getFila()).get(coord.getColumna());

 		return caracter;
 	}

 	public String toString(){
 		String dev="";
		if(mapa!=null){
	 		 for(int i=0;i<mapa.size();i++){
	 		 	for(int j=0;j<mapa.get(0).size();j++){
	 		 		dev=dev + mapa.get(i).get(j);
	 		 	}
	 		 	dev=dev+ "\n";
	 		 }
		}
		if(localidades!=null){
	 		 for(int x=0;x<localidades.size();x++){
	 		 	dev=dev + localidades.get(x).toString(); //localidades.get(x)??
	 		 }
		}
		return dev;


 		
 	}
 }



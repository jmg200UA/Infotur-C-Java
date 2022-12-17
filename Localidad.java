 import java.util.*

 public class Localidad{

 	private String nombre;
 	private Coordenadas coor;
 	private InfoTur info;
 	private int id;

 	public Localidad(String cadena){
 		nombre=cadena;
 		id=-1;
 	}

 	public int setCoor(int ent1, int ent2, ArrayList<ArrayList<Character>> mapa){

 		Coordenadas coord= new Coordenadas(ent1,ent2);
 		int n=0,id2=0 ;

 		n=mapa.get(0).size();
 		id2=n*(ent1+ent2);

 		if(coor==null || coor.get(ent1)==-1 || coor.get(ent2)==-1){
 			coor=coord;
 			if(mapa.get(ent1).get(ent2)=="T") {
 				mapa.get(ent1).get(ent2)=="L";
 				id=id2;
 				return id;
 			}
 			else return -1;
 		}

 	}

 	public void setInfo(InfoTur inf){
 		info=inf;
 	}
 	
 	public void setCoordenadas(Coordenadas coord) {
 		coor=coord;
 	}
 	
 	public void setId(int ide) {
 		id=ide;
 	}

 	public String getNombre(){
 		return nombre;
 	}

 	public Coordenadas getCoor(){
 		return coor;
 	}

 	public InfoTur getInfo(){ 
 		return info;
 	}

 	public int getId(){
 		return id;
 	}

 	public String toString(){
 		String dev= id + "-" + nombre + "-" + coor.toString() + "\n" + info.toString();
 		return dev;
 	}


 }
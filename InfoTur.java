 import java.util.*;


 public class InfoTur{

 	private String top;
 	private boolean aeropuerto;
 	private int museo, monumento, hotel, restaurante;

	public InfoTur(){
		top="";
		aeropuerto=false;
		museo=0;
		monumento=0;
		hotel=0;
		restaurante=0;
	}

	public InfoTur(int i, int j, int k, int l, boolean b ){
		if(i<0) i=0;
		if(j<0) j=0;
		if(k<0) k=0;
		if(l<0) l=0;
		top="";
		museo=i;
		aeropuerto=b;
		monumento=j;
		hotel=k;
		restaurante=l;

	}

	public ArrayList<Integer> getInfoTur(){
		ArrayList<Integer> vect= new ArrayList<Integer>();
		vect.add(museo);
		vect.add(monumento);
		vect.add(hotel);
		vect.add(restaurante);
		if (aeropuerto==false) vect.add(0);
		else vect.add(1);
		return vect;
	}


	public String getMasFrecuente(){
		String frecuente="";
		int tope=-1;
		ArrayList<Integer> vect= new ArrayList<Integer>();
		vect=getInfoTur();
		ArrayList<String> vecto= new ArrayList<String>();
		vecto.add("aeropuerto");
		vecto.add("hotel");
		vecto.add("monumento");
		vecto.add("museo");
		vecto.add("restaurante");

		ArrayList<Integer> vecta= new ArrayList<Integer>();
		vecta.add(vect.get(4));
		vecta.add(vect.get(2));
		vecta.add(vect.get(1));
		vecta.add(vect.get(0));
		vecta.add(vect.get(3));

		for(int i=0;i<vect.size();i++){
			if(vecta.get(i)>tope){
				tope=vecta.get(i);
				frecuente=vecto.get(i);
			} 
		} 
		return frecuente;
		

	}

	public void setTop( String n ){
		top=n;
	}

	public String getTop(){
		return top;

	}

	public String toString(){
		int ae=0;
		if(aeropuerto==true) ae=1;
		else ae=0;
		String dev=museo + " " + monumento + " " + hotel + " " + restaurante + " " + ae + " " + top + "\n";
		return dev;
	}

	
		
}

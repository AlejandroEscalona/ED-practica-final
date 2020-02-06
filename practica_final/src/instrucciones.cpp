#include <instrucciones.h>

istream & operator>>(istream & is, instrucciones &instructions){
	string linea;
	stack <ArbolBinario<string> > pila;
	while(getline(is,linea)){
		if (linea.size()==0) {
			return is;
		}
		int i = 0;
		string accion;
		while(linea[i]!=' '&&linea.size()!=i){
			accion+=linea[i];
			i++;
		}
		i+=1;
		int ariedad = instructions.acc.getAriedad(accion);
		ArbolBinario <string> arbol(accion);
		if(accion.size()==linea.size()){
			ArbolBinario <string> aux1 = pila.top();
			pila.pop();
			if(ariedad==1)
				arbol.Insertar_Hi(arbol.getRaiz(),aux1);
			else
				arbol.Insertar_Hd(arbol.getRaiz(),aux1);
			if(ariedad==2){
				ArbolBinario <string> aux2 = pila.top();
				pila.pop();
				arbol.Insertar_Hi(arbol.getRaiz(),aux2);
			}
		}else{
			ingredientes ingredients;
			ingrediente ingredient;
			bool esta = false;
			string nombre;
			do{
				if(linea[i]==' '){
					nombre+=' ';
					i++;
				}
				while(linea.size()!=i&&linea[i]!=' '){
					nombre+=linea[i];
					i++;
				}
				ingredient.setNombre(nombre);
				instructions.ings.EstaDatos(ingredient,esta);
				if(accion=="Add"&&nombre=="Tomate"&&i!=linea.size()){
					
						esta=false;
					
				}
			} while(!esta);
			if(ariedad == 1)
				arbol.Insertar_Hi(arbol.getRaiz(),nombre);
			else
				arbol.Insertar_Hd(arbol.getRaiz(),nombre);
			i++;
			if(ariedad==2&&linea.size()!=i-1){
				ingrediente ingredient;
				bool esta = false;
				string nombre;
				do{
					if(linea[i]==' '){
						nombre+=' ';
						i++;
					}
					while(linea.size()!=i){ //linea[i]!=' '&&
						nombre+=linea[i];
						i++;
					}
					ingredient.setNombre(nombre);
					instructions.ings.EstaDatos(ingredient,esta);
				} while(!esta);
				arbol.Insertar_Hi(arbol.getRaiz(),nombre);
			} else if(ariedad==2){
				ArbolBinario <string> aux2 = pila.top();
				pila.pop();
				arbol.Insertar_Hi(arbol.getRaiz(),aux2);
			}
		}
		pila.push(arbol);
		linea.clear();
		instructions.datos = arbol;
		
	}
	
}

ostream & operator<<(ostream &os, const instrucciones &instructions){
	

	stack<string> pila;
	
for(ArbolBinario<string>:: postorden_iterador it=instructions.datos.beginpostorden();it!=instructions.datos.endpostorden();++it){

	if( it.hd().nulo() && it.hi().nulo() ){
		cout << *it.padre() <<" "<< (*it);
		++it;
		if(it.hd().nulo() && it.hi().nulo() )
		cout <<" "<< (*it);

		cout <<endl;
	} 
	else {
		if( !(it.hi().hi().nulo() && it.hi().hd().nulo()) )
		cout << *it << endl;
	}
}
	return os;
}

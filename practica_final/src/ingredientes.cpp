#include <iostream>
#include "ingredientes.h"



int ingredientes::EstaDatos(const ingrediente &ingrediente, bool &encontrado) const{
	encontrado=false;
	int mitad, izda=0, dcha=datos.size()-1;
	while(!encontrado&&izda<=dcha){
		mitad=(izda+dcha)/2;
		if(datos[mitad].getNombre()==ingrediente.getNombre()){
			encontrado=true;
			return mitad;
		} else if(datos[mitad].getNombre()>ingrediente.getNombre()){
			dcha=mitad-1;
		} else if(datos[mitad].getNombre()<ingrediente.getNombre()){
			izda=mitad+1;
		}
	}

	return izda;
}

pair<bool,int> ingredientes::EstaIndice(const ingrediente& ingrediente) const{

  	int izda = 0, dcha = indice.size();
  	pair<bool,int> result(false, izda);

  	while(izda < dcha){
  		int mitad = (izda + dcha) / 2;
    	if(datos[indice[mitad]].getTipo() == ingrediente.getTipo()){
      		if (ingrediente.getNombre()>datos[indice[mitad]].getNombre())
        		izda = mitad + 1;
      		else if (ingrediente.getNombre()<datos[indice[mitad]].getNombre())
        		dcha = mitad;
      		else{
        		result=make_pair(true,mitad);
        		return result;
      		}
    	}else{
      		if (ingrediente.getTipo()>datos[indice[mitad]].getTipo())
        		izda = mitad + 1;
      		else if (ingrediente.getTipo()<datos[indice[mitad]].getTipo())
          		dcha = mitad;
    		}
    	result=make_pair(false,izda);
  	}
  	return result;
}

void ingredientes::Insertar(const ingrediente& ing){

	bool esta;
	int pos = EstaDatos(ing,esta);

    pair<bool, int> pIndice = EstaIndice(ing);

    if (!pIndice.first){

        vector<int>::iterator it;
        vector<ingrediente>::iterator itIng;

        itIng=datos.begin()+pos;

    	for(it=indice.begin(); it < indice.end();it++){
        	if((*it) >= pos)
                (*it)++;
    	}

        it=indice.begin()+pIndice.second;

    	datos.insert(itIng,ing);
    	indice.insert(it,pos);
  	}
}


void ingredientes::borrar(const string nombre){

	bool encontrado=false;
	int mitad, izda=0, dcha=datos.size()-1;
	while(!encontrado&&izda<=dcha){
		mitad=(izda+dcha)/2;
		if(datos[mitad].getNombre()==nombre){
			encontrado=true;
		} else if(datos[mitad].getNombre()>nombre){
			dcha=mitad-1;
		} else if(datos[mitad].getNombre()<nombre){
			izda=mitad+1;
		}
	}

	int mitad1=mitad;
	encontrado=false;
	izda=0, dcha=indice.size()-1;
	while(!encontrado&&izda<=dcha){
		mitad=(izda+dcha)/2;
		if(datos[indice[mitad]].getNombre()==nombre){
			encontrado=true;
		} else if(datos[indice[mitad]].getNombre()>nombre){
			dcha=mitad-1;
		} else if(datos[indice[mitad]].getNombre()<nombre){
			izda=mitad+1;
		}
	}

	for(int i=0; i < indice.size();i++){
        if(indice[i] >= mitad1)
          	indice[i]--;
    }

    vector<ingrediente>::iterator itIng;
    vector<int>::iterator itPos;
    itIng=datos.begin()+mitad1;
    itPos=indice.begin()+mitad;

    datos.erase(itIng);
	indice.erase(itPos);
}

void ingredientes::clear(){
    datos.clear();
    indice.clear();
}

int ingredientes::size() const{
	return datos.size();
}

vector<string> ingredientes::getTipos() const{
	vector<string> result;
	string tipo;
	if(indice.size()>0){
		tipo=datos[indice[0]].getTipo();
	}

	for(int i=0;i<indice.size();i++){
		if(tipo!=datos[indice[i]].getTipo()){
			tipo=datos[indice[i]].getTipo();
			result.insert(result.end(),tipo);
		}
	}
	return result;
}



ingrediente ingredientes::get(const string nombre) const{

	ingrediente ing;
	ing.setNombre(nombre);
	bool esta;
	int pos=EstaDatos(ing,esta);

	ing.setNombre("Undefined");
	if(esta){
		ing = datos[pos];
	}

	return ing;
}

void ingredientes::ImprimirPorTipo(ostream &os) const{

	for(int i=0;i<indice.size();i++){
		os << datos[indice[i]];
	}
}


ingredientes ingredientes::getIngredienteTipo(const string tipo) const{
	unsigned i=0;
	int k=0;
	ingredientes ing;
	bool encontrado = false;
	while(k < datos.size() ){
	 	while(i <( datos[k].getTipo().length() ) && !encontrado ){
			if(  tipo[i] == datos[k].getTipo()[i] ){
				i++;
				if(i == tipo.length() ){
					encontrado = true;
				}
			}else{
				k++;
				i=0;
			}
		}
		if(encontrado){
			ing.Insertar(datos[k]);
			encontrado = false;
		}
	}
	return ing;
}

const ingrediente & ingredientes::operator[](const int pos) const{
	return datos[pos];
}

ingrediente & ingredientes::operator[](const int pos){
	return datos[pos];
}

ostream & operator<<(ostream &os, const ingredientes &aux){
	for(ingredientes::const_iterator it=aux.cbegin();it!=aux.cend();++it){
		os << *(it);
	}
	return os;
}

istream & operator>>(istream &is, ingredientes &aux){

	string linea;
	ingrediente ing;
	getline(is,linea);

	while(is >> ing){
		aux.Insertar(ing);
	}

	return is;
}


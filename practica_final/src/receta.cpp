#include "receta.h"


void receta::Fusion(const receta parte2)
{

    for(list<pair<string,unsigned int> >::const_iterator it2=parte2.ings.cbegin();it2!=parte2.ings.cend();++it2){
      bool encontrado=false;
      
      for (list<pair<string,unsigned int> >::iterator it=ings.begin();it!=ings.end() && !encontrado;++it){

        if( (*it).first == (*it2).first ){
              (*it).second+=(*it2).second;
              encontrado=true;
        }
       
      }
       if(!encontrado){
          ings.push_back(*it2);
        }

  }
    
    
   // ArbolBinario<string> aux(inst.getArbol());
    ArbolBinario<string> aux2(parte2.inst.getArbol() );
  
    if(inst.empty() ){
      ArbolBinario<string> nuevo(aux2);
      //nuevo.Insertar_Hi(nuevo.getRaiz() ,aux2 );
       inst.setInst(nuevo);
  
    }
    else{
          string nombre = "Acompañar";
          ArbolBinario<string> nuevo(nombre);
          ArbolBinario<string> aux(inst.getArbol());
         nuevo.Insertar_Hi(nuevo.getRaiz() ,aux );
         nuevo.Insertar_Hd(nuevo.getRaiz() , aux2 );
          inst.setInst(nuevo);
       
    }

}


float receta::getCalorias()const{

  return calorias;
}

float receta::getHc()const{

  return hc;
}

float receta::getProteinas()const{

  return proteinas;
}

float receta::getGrasas()const{

  return grasas;
}

float receta::getFibra()const{

  return fibra;
}


void receta::setCalorias(const float new_calorias){

  calorias = new_calorias;
}

void receta::setHc(const float new_hc){

  hc = new_hc;
}

void receta::setProteinas(const float new_proteinas){

  proteinas = new_proteinas;
}

void receta::setGrasas(const float new_grasas){

  grasas = new_grasas;
}

void receta::setFibra(const float new_fibra){

  fibra = new_fibra;
}

string receta::getNombre()const{

  return nombre;
}


void receta::setNombre(const string S){

    nombre = S;
  }
string receta::getCode()const{

  return code;
  }

void receta::setCode(const string S){

    code = S;
  }

  void receta::setPlato(const unsigned int i){

      plato = i;
    }

unsigned int receta::getPlato()const{

  return plato;
}

void receta::setIngs(pair<string,unsigned int> ingre){
    ings.push_back(ingre);
}

int receta::ningredientes() const{
        int contador=0;
        for(list<pair<string,unsigned int> >::const_iterator it=ings.cbegin();it!=ings.cend();++it){
            contador++;
        }
        return contador;
    }

std::istream& operator>>(std::istream &is, receta &recipe )
{
    string linea;
    recipe.clear();
    if(getline(is,linea)){
        linea+=";";
        int i=0;
        string variable;
        while(linea[i]!=';'){
            variable+=linea[i];
            i++;
        }
        recipe.setCode(variable);
        i++;
        string variable2;
        while(linea[i]!=';') {
            variable2 += linea[i];
            i++;
        }
        string variable3;
        i++;
        while(linea[i]!=';'){
            variable3+=linea[i];
            i++;
        }
        i++;
        recipe.setNombre(variable3);
        recipe.setPlato(stoi(variable2));
        while(i<linea.length()){
            string cantidad;
            string variable4;
            while(linea[i]!=';'){
                if(isdigit(linea[i])){
                    cantidad+=linea[i];
                    i++;
                } else {
                    variable4+=linea[i];
                    i++;
                }
            }
            i++;
            variable4.erase( variable4.end()-1 );
            pair<string,unsigned int>  ingre;
            ingre.first=variable4;
            ingre.second=stoi(cantidad);
            recipe.ings.push_back(ingre);
        }
    }
    return is;
}

ostream & operator<<(ostream &os, const receta &aux){
   /*  os<<aux.getCode()<<";";
    os<<aux.getPlato()<<";";
    os<<aux.getNombre()<<";";
    cout << endl; */
    for(receta::const_iterator it=aux.cbegin();it!=aux.cend();++it){
      cout<<(*it).first<<" "<<(*it).second<<endl;
    }
   
    return os;
}
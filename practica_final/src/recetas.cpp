#include "recetas.h"


istream& operator>>(istream &is, recetas &recipes){
	receta recipe;

	while(is >> recipe){
		recipes.insertar(recipe.getCode(),recipe);
	}
	return is;
}

ostream & operator<<(ostream &os, const recetas & aux){
	for(recetas::const_iterator it=aux.cbegin();it!=aux.cend();++it){
		os << *it;
	}
	return os;
}

pair<map<string,receta>::iterator,bool> recetas::insertar(string clave, receta recipe){
	pair<string,receta> p(clave,recipe);
	pair< map<string,receta> ::iterator,bool> ret;
	ret=datos.insert(p);
	return ret; 
}

bool recetas::borrar(string code){
	bool ret=false;
	for(map<string,receta>::iterator it=datos.begin();it!=datos.end();++it){
        if((*it).first==code){
            datos.erase(it);
            ret=true;
        }
    }
    return ret;
}

int recetas::size() const{
	return datos.size();
}

void recetas::setNutricion(ingredientes &ings){
	for(recetas::iterator it=this->begin();it!=this->end();++it){
		float c=0,hc=0,p=0,g=0,f=0;
		/* cout << endl << "Valores nutricionales de la receta: ";
		cout << (*it); */
		for(receta::iterator it2=(*it).begin();it2!=(*it).end();++it2){
			for(int j=0;j<ings.size();j++){
				if((*it2).first==ings[j].getNombre()){
					c+=ings[j].getCalorias()*(*it2).second*0.01;
					hc+=ings[j].getHc()*(*it2).second*0.01;
					p+=ings[j].getProteinas()*(*it2).second*0.01;
					g+=ings[j].getGrasas()*(*it2).second*0.01;
					f+=ings[j].getFibra()*(*it2).second*0.01;
				}
			}
		}
		(*it).setCalorias(c);
		(*it).setHc(hc);
		(*it).setProteinas(p);
		(*it).setGrasas(g);
		(*it).setFibra(f);
		/* cout << "Calorias\t" << (*it).getCalorias() << "\t" << "Hidratos de Carb.\t" << (*it).getHc() << "\t" << "Proteinas\t" << (*it).getProteinas() << "\t";
		cout << "Grasas\t" << (*it).getGrasas() << "\t" << "Fibra\t" << (*it).getFibra() << endl; */
	}
}

bool recetas::CargarRecetas(const string &nombre, const string &path_ins){
	string ruta = path_ins;
	ruta+=nombre;
	ruta+="m.txt";
	bool stop = false;
	for(recetas::iterator it=this->begin();it!=this->end()&&!stop;++it){
		instrucciones instruc;

		if((*it).getCode()==nombre){
			stop = true;
			fstream f(ruta);
			f >> instruc; 
			(*it).setInstrucciones(instruc);
		}
	}

	/*ifstream finstrucciones(ruta);
	finstrucciones >> inst;*/
}

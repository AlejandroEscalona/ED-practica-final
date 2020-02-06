#include<iostream>
#include<vector>
#include<fstream>
#include"ingredientes.h"
#include"receta.h"
#include"recetas.h"

using namespace std;

int main(int argc, char *argv[]){
	cout << "Hola" << endl;
	string d_recetas=argv[1];
	string d_ingredientes=argv[2];
	//int max_calorias=stoi(argv[3]);

	ifstream f_r(argv[1]);
	ifstream f_i(argv[2]);

	recetas recipes;
	ingredientes ingredients;

	f_r>>recipes;
	f_i>>ingredients;

	recipes.setNutricion(ingredients);
	
	/*for(recetas::iterator it=recipes.begin();it!=recipes.end();++it){
		float c=0,hc=0,p=0,g=0,f=0;
		cout << endl << "Valores nutricionales de la receta: ";
		cout << (*it);
		for(receta::iterator it2=(*it).begin();it2!=(*it).end();++it2){
			for(int j=0;j<ingredients.size();j++){
				if((*it2).first==ingredients[j].getNombre()){
					c+=ingredients[j].getCalorias()*(*it2).second*0.01;
					hc+=ingredients[j].getHc()*(*it2).second*0.01;
					p+=ingredients[j].getProteinas()*(*it2).second*0.01;
					g+=ingredients[j].getGrasas()*(*it2).second*0.01;
					f+=ingredients[j].getFibra()*(*it2).second*0.01;
				}
			}
		}
		(*it).setCalorias(c);
		(*it).setHc(hc);
		(*it).setProteinas(p);
		(*it).setGrasas(g);
		(*it).setFibra(f);
		cout << "Calorias\t" << (*it).getCalorias() << "\t" << "Hidratos de Carb.\t" << (*it).getHc() << "\t" << "Proteinas\t" << (*it).getProteinas() << "\t";
		cout << "Grasas\t" << (*it).getGrasas() << "\t" << "Fibra\t" << (*it).getFibra() << endl;
	}*/
	
	/*float **matriz;
	matriz=new float*[recipes.size()+1];
	for(int i=0;i<recipes.size()+1;i++){
		matriz[i]=new float[max_calorias+1];
	}

	for(int j=0;j<max_calorias+1;j++){
		matriz[0][j]=0;
	}

	for(int i=1;i<recipes.size()+1;i++){
		//cout << i << endl;

		for(int j=0;j<max_calorias+1;j++){
			if(j==0){
				matriz[i][j]=0;
			} else {
				float caso_a=matriz[i-1][j];
				float caso_b;
				if(j-((int)recipes[i-1].getCalorias())<0){
					caso_b=caso_a;
				} else{
					caso_b=recipes[i-1].getProteinas()/recipes[i-1].getHc()+matriz[i-1][j-((int)recipes[i-1].getCalorias())];
				}
				if(caso_a>caso_b){
					matriz[i][j]=caso_a;
				}
				else{
					matriz[i][j]=caso_b;
				}
			}
		}
	}

	int i=recipes.size();
	int j=max_calorias;

	vector<receta> v;

	while(i!=0&&j!=0){
		if(matriz[i][j]!=matriz[i-1][j]){
			v.push_back(recipes[i-1]);
			i--;
			j-=(int) recipes[i].getCalorias();
		} else {
			i--;
		}
	}

	for(int i=0;i<recipes.size()+1;i++){
		cout << endl;
		for(int j=0;j<=max_calorias;j++){
			cout << matriz[i][j] << "\t";
		}
	}

	cout << endl << "Las recetas escogidas son:" << endl;

	float cal_totales=0, prot_totales=0;
	for(vector<receta>::reverse_iterator it=v.rbegin();it!=v.rend();++it){
		cout << (*it);
		cal_totales+=(*it).getCalorias();
		prot_totales+=(*it).getProteinas();
	}

	cout << endl << "Calorias Totales: " << cal_totales << " Proteinas Totales: " << prot_totales << endl;

	for(int i=0;i<recipes.size()+1;i++){
		delete [] matriz[i];
	}
	delete [] matriz;*/
}
#include "recetas.h"
#include "instrucciones.h"
#include "color.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]){
	ifstream facciones(argv[1]);
	ifstream frecetas(argv[2]);
	ifstream fingredientes(argv[3]);

	acciones acc;
	recetas recs;
	ingredientes ings;
	instrucciones inst;
	string nombre;

	facciones >> acc;
	frecetas >> recs;
	fingredientes >> ings;

	inst.setAcc(acc);
	inst.setIngs(ings);

	for(recetas::const_iterator it=recs.cbegin();it!=recs.cend();++it){
		cout << FGRN(BOLD("CODE:")) << (*it).getCode() << FGRN(BOLD("  \tNOMBRE:")) << (*it).getNombre() << FGRN(BOLD("\t\t\tPLATO:")) << (*it).getPlato() << endl;
	}


	cout << endl << "Introduce un código de receta: " << endl;
	string string_receta;
	string codigo;
	cin >> string_receta;
	codigo = string_receta;
	string ruta = argv[4];
	string_receta+="m.txt";
	ruta+=string_receta;

	ifstream finstrucciones(ruta);
	finstrucciones >> inst;

	bool encontrado=false;
	for(recetas::iterator it=recs.begin();it!=recs.end()&&!encontrado;++it){
		if((*it).getCode()==codigo){
			encontrado=true;
			(*it).setInstrucciones(inst);

		}
	}

	recs.setNutricion(ings);

	cout << endl << FGRN(BOLD("CODE:"))<<codigo<<FGRN(BOLD(" RECETA:"))<< recs[codigo].getNombre()<< FGRN(BOLD(" PLATO:")) <<recs[codigo].getPlato()<< endl<<endl;

	cout << FGRN(BOLD("INGREDIENTES:"))<< endl<<recs[codigo]<<endl<<endl;
	cout << FGRN(BOLD("INFORMACIÓN NUTRICIONAL:"))<< endl;
	cout << "Calorias: " << recs[codigo].getCalorias() << endl << "Hidratos de Carb: " << recs[codigo].getHc() << endl << "Proteinas: " << recs[codigo].getProteinas() << endl;
		cout << "Grasas: " << recs[codigo].getGrasas() << endl << "Fibra: " << recs[codigo].getFibra() << endl;
	cout  <<endl<<FGRN(BOLD("INSTRUCIONES:"))<< endl << recs[codigo].getInstruciones() << endl;

	cout << endl << "Introduce un código de receta: " << endl;

	cin >> string_receta;
	codigo = string_receta;
	ruta = argv[4];
	string_receta+="m.txt";
	ruta+=string_receta;
	receta receta1;
	recetas fusion;
	receta receta_final;

	instrucciones inst1;

	inst1.setAcc(acc);
	inst1.setIngs(ings);

	ifstream finstrucciones1(ruta);
	finstrucciones1 >> inst1;
	
	cout << endl << "Introduce un segundo código de receta: " << endl;
	string string_receta1;
	string codigo1;
	cin >> string_receta1;
	codigo1 = string_receta1;
	string ruta1 = argv[4];
	string_receta1+="m.txt";
	ruta1+=string_receta1;
	receta receta2;

	instrucciones inst2;

	inst2.setAcc(acc);
	inst2.setIngs(ings);

	ifstream finstrucciones2(ruta1);
	finstrucciones2 >> inst2;

	receta1=recs[codigo];
	receta2=recs[codigo1];

	receta1.setInstrucciones(inst1);
	receta2.setInstrucciones(inst2);

	string codigo_fusion = "F_"+codigo+"_"+codigo1;

	receta_final.Fusion(receta1);
	receta_final.Fusion(receta2);
	
	string nombre_fusion = "Fusion "+receta1.getNombre() + " y "+receta2.getNombre();
	receta_final.setNombre(nombre_fusion);
	receta_final.setCode(codigo_fusion);
	int numero_fusion = receta1.getPlato() > receta2.getPlato() ?  receta2.getPlato() : receta1.getPlato();
	receta_final.setPlato(numero_fusion);
	fusion.insertar(codigo_fusion,receta_final);
	fusion.setNutricion(ings);

	
	
	cout << endl << FGRN(BOLD("CODE:"))<<receta_final.getCode()<<FGRN(BOLD(" RECETA:"))<< receta_final.getNombre()<< FGRN(BOLD(" PLATO:")) <<receta_final.getPlato()<< endl<<endl;
	cout << FGRN(BOLD("INGREDIENTES:"))<< endl<<receta_final<<endl<<endl;
	cout << FGRN(BOLD("INFORMACIÓN NUTRICIONAL:"))<< endl;
	cout << "Calorias: " << fusion[codigo_fusion].getCalorias() << endl << "Hidratos de Carb: " << fusion[codigo_fusion].getHc() << endl << "Proteinas: " << fusion[codigo_fusion].getProteinas() << endl;
	cout << "Grasas: " << fusion[codigo_fusion].getGrasas() << endl << "Fibra: " << fusion[codigo_fusion].getFibra() << endl;
	cout  <<endl<<FGRN(BOLD("INSTRUCIONES:"))<< endl << fusion[codigo_fusion].getInstruciones() << endl;

		


}
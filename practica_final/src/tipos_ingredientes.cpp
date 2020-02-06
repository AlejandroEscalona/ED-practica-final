#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include <fstream>
#include <math.h>
using namespace std;
void MuestraParametros(){
  
  cout<<"1.- Dime el nombre del fichero con los ingredientes"<<endl;
}

int main(int argc, char *argv[])
{
  if (argc!=3){
    MuestraParametros();
    return 0;
 }  
 /******************************************************************************************/ 
 //SECTION 1: Test sobre la lectura de un ingrediente
 //Ingrediente debe tener operadores de consulta y de modificacion por cada parametros
 //ademas de sobrecarga de lectura y escritura
 string nf = argv[1];
 string tipo = argv[2];
 ifstream f(nf);
 if (!f){
    cout<<"No puedo abrir "<<nf<<endl;
    return 0;
 }
 //Quitamos la primera linea
 string linea;
 getline(f,linea);

 f.seekg(0);
 ingredientes all_ingre;
 cout<<"Lectura de todos los ingredientes"<<endl;
 f>>all_ingre;

 VD<string> tipos=all_ingre.getTipos();
 cout<<"Los tipos de alimentos son:"<<endl;
 for (int i=0;i<tipos.size(); ++i){
  cout<<tipos[i]<<endl;
 }
  
 ingredientes ingre_tipo=all_ingre.getIngredienteTipo(tipo);
 cout<< endl << "Los ingredientes del tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;

 float sumatoria[]={0,0,0,0,0};
 float max[]={0,0,0,0,0};
 float min[]={0,0,0,0,0};

 for(int i=0; i < ingre_tipo.size();i++){
  sumatoria[0]+=ingre_tipo[i].getCalorias();
  sumatoria[1]+=ingre_tipo[i].getHc();
  sumatoria[2]+=ingre_tipo[i].getProteinas();
  sumatoria[3]+=ingre_tipo[i].getGrasas();
  sumatoria[4]+=ingre_tipo[i].getFibra();
  if(ingre_tipo[max[0]].getCalorias()<ingre_tipo[i].getCalorias()){
    max[0]=i;
  }
  if(ingre_tipo[max[1]].getHc()<ingre_tipo[i].getHc()){
    max[1]=i;
  }
  if(ingre_tipo[max[2]].getProteinas()<ingre_tipo[i].getProteinas()){
    max[2]=i;
  }
  if(ingre_tipo[max[3]].getGrasas()<ingre_tipo[i].getGrasas()){
    max[3]=i;
  }
  if(ingre_tipo[max[4]].getFibra()<ingre_tipo[i].getFibra()){
    max[4]=i;
  }
  if(ingre_tipo[min[0]].getCalorias()>ingre_tipo[i].getCalorias()){
    min[0]=i;
  }
  if(ingre_tipo[min[1]].getHc()>ingre_tipo[i].getHc()){
    min[1]=i;
  }
  if(ingre_tipo[min[2]].getProteinas()>ingre_tipo[i].getProteinas()){
    min[2]=i;
  }
  if(ingre_tipo[min[3]].getGrasas()>ingre_tipo[i].getGrasas()){
    min[3]=i;
  }
  if(ingre_tipo[min[4]].getFibra()>ingre_tipo[i].getFibra()){
    min[4]=i;
  }
 }

 float total = ingre_tipo.size();
 float  mediaCalorias=sumatoria[0]/total,
        mediaHc=sumatoria[1]/total,
        mediaProteinas=sumatoria[2]/total,
        mediaGrasas=sumatoria[3]/total,
        mediaFibra=sumatoria[4]/total;
 float desvCalorias=0,
       desvHc=0,
       desvProteinas=0,
       desvGrasas=0,
       desvFibra=0;

 float varianzaCalorias=0;
 for(int i = 0 ; i<ingre_tipo.size(); i++){
  float rango;
  rango = pow(ingre_tipo[i].getCalorias() - mediaCalorias,2);
  varianzaCalorias +=rango;
 }
 varianzaCalorias = varianzaCalorias / ingre_tipo.size();

 desvCalorias=sqrt(varianzaCalorias);

 float varianzaHc=0;
 for(int i = 0 ; i<ingre_tipo.size(); i++){
  float rango;
  rango = pow(ingre_tipo[i].getHc() - mediaHc,2);
  varianzaHc +=rango;
 }
 varianzaHc = varianzaHc / ingre_tipo.size();

 desvHc=sqrt(varianzaHc);

 float varianzaProteinas=0;
 for(int i = 0 ; i<ingre_tipo.size(); i++){
  float rango;
  rango = pow(ingre_tipo[i].getProteinas() - mediaProteinas,2);
  varianzaProteinas +=rango;
 }
 varianzaProteinas = varianzaProteinas / ingre_tipo.size();

 desvProteinas=sqrt(varianzaProteinas);

 float varianzaGrasas=0;
 for(int i = 0 ; i<ingre_tipo.size(); i++){
  float rango;
  rango = pow(ingre_tipo[i].getGrasas() - mediaGrasas,2);
  varianzaGrasas +=rango;
 }
 varianzaGrasas = varianzaGrasas / ingre_tipo.size();

 desvGrasas=sqrt(varianzaGrasas);

 float varianzaFibra=0;
 for(int i = 0 ; i<ingre_tipo.size(); i++){
  float rango;
  rango = pow(ingre_tipo[i].getFibra() - mediaFibra,2);
  varianzaFibra +=rango;
 }
 varianzaFibra = varianzaFibra / ingre_tipo.size();

 desvFibra=sqrt(varianzaFibra);

 cout << endl << "Estadistica_____________________________" << endl;
 cout << "Tipo de Alimento " << tipo << endl;
 cout << "Promedio+-Desviacion" << endl;
 cout << "Calorias\tHidratos de carb\tProteinas\t\tGrasas\t\t\tFibra\t" << endl;
 cout << mediaCalorias << "+-" << desvCalorias << "\t" << mediaHc << "+-" << desvHc << "\t" << mediaProteinas << "+-" << desvProteinas << "\t" << mediaGrasas << "+-" << desvGrasas << "\t\t" << mediaFibra << "+-" << desvFibra << endl;
 cout << endl << "Maximos Valores" << endl;
 cout << "Calorias (Alimento)\tHidratos de carb (Alimento)\tProteinas (Alimento)\tGrasas (Alimento)\tFibra (Alimento)\t" << endl;
 cout << ingre_tipo[max[0]].getCalorias() << " " << ingre_tipo[max[0]].getNombre() << "\t\t\t" << ingre_tipo[max[1]].getHc() << " " << ingre_tipo[max[1]].getNombre() << "\t\t\t" << ingre_tipo[max[2]].getProteinas() << " " << ingre_tipo[max[2]].getNombre() << "\t\t" << ingre_tipo[max[3]].getGrasas() << " " << ingre_tipo[max[3]].getNombre() << "\t\t" << ingre_tipo[max[4]].getFibra() << " " << ingre_tipo[max[4]].getNombre() << endl;
 cout << endl << "Minimos Valores" << endl;
 cout << "Calorias (Alimento)\tHidratos de carb (Alimento)\tProteinas (Alimento)\tGrasas (Alimento)\tFibra (Alimento)\t" << endl;
 cout << ingre_tipo[min[0]].getCalorias() << " " << ingre_tipo[min[0]].getNombre() << "\t\t\t" << ingre_tipo[min[1]].getHc() << " " << ingre_tipo[min[1]].getNombre() << "\t\t\t" << ingre_tipo[min[2]].getProteinas() << " " << ingre_tipo[min[2]].getNombre() << "\t\t" << ingre_tipo[min[3]].getGrasas() << " " << ingre_tipo[min[3]].getNombre() << "\t\t" << ingre_tipo[min[4]].getFibra() << " " << ingre_tipo[min[4]].getNombre() << endl;

}
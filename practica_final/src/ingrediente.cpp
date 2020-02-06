#include "ingrediente.h"

using namespace std;

  string ingrediente::getNombre()const{

    return Nombre;
  }

  float ingrediente::getCalorias()const{

    return Calorias;
  }

  float ingrediente::getHc()const{

    return Hc;
  }

  float ingrediente::getProteinas()const{

    return Proteinas;
  }

  float ingrediente::getGrasas()const{

    return Grasas;
  }

  float ingrediente::getFibra()const{

    return Fibra;
  }

  string ingrediente::getTipo()const{

    return Tipo;
  }


  void ingrediente::setNombre(const string S){

    Nombre = S;
  }

  void ingrediente::setCalorias(const float new_calorias){

    Calorias = new_calorias;
  }

  void ingrediente::setHc(const float new_hc){

    Hc = new_hc;
  }

  void ingrediente::setProteinas(const float new_proteinas){

    Proteinas = new_proteinas;
  }

  void ingrediente::setGrasas(const float new_grasas){

    Grasas = new_grasas;
  }

  void ingrediente::setFibra(const float new_fibra){

    Fibra = new_fibra;
  }

  void ingrediente::setTipo(const string S){

    Tipo = S;
  }

  std::ostream& operator<<(std::ostream &os,const ingrediente &ingr )
  {

      os << ingr.getNombre()<<";";
      os << ingr.getCalorias()<<";";
      os << ingr.getHc()<<";";
      os << ingr.getProteinas()<<";" ;
      os << ingr.getGrasas()<<";" ;
      os << ingr.getFibra()<<";";
      os << ingr.getTipo();
      os << endl;
      return os;

  }


   istream & operator>>(std::istream & is, ingrediente & ingr)
  {

      string auxiliar;
    
      if (getline(is,auxiliar,';')) {
      ingr.setNombre(auxiliar);

      getline(is,auxiliar,';');
      ingr.setCalorias(stof(auxiliar));

      getline(is,auxiliar,';');
      ingr.setHc(stof(auxiliar));

      getline(is,auxiliar,';');
      ingr.setProteinas(stof(auxiliar));

      getline(is,auxiliar,';');
      ingr.setGrasas(stof(auxiliar));

      getline(is,auxiliar,';');
      ingr.setFibra(stof(auxiliar));

      getline(is,auxiliar,'\n');
      ingr.setTipo(auxiliar);
   }

      return is;
  }

  bool operator==(const ingrediente & izq, const ingrediente & ing) {
    bool result=false;
    if(
        izq.getNombre()==ing.getNombre()&&
        izq.getCalorias()==ing.getCalorias()&&
        izq.getHc()==ing.getHc()&&
        izq.getProteinas()==ing.getProteinas()&&
        izq.getGrasas()==ing.getGrasas()&&
        izq.getFibra()==ing.getFibra()&&
        izq.getTipo()==ing.getTipo()
      ){ result = true; }
      return result;
  }



/**
  * @file recetas.h
  * @brief Fichero cabecera del TDA recetas
  *
  */
#ifndef RECETAS
#define RECETAS
#include "receta.h"
#include <fstream>
#include <map>

using namespace std;

/**
    *  @brief T.D.A. recetas
    *
    * Una instancia @e c del tipo de datos abstracto @c ingredientes es un objeto
    * que contiene varios atributos como
    *
    * datos
    *
    * Un ejemplo de su uso:
    * @include recetas.cpp
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */
class recetas{

private:
    /**
  * @page repConjunto Rep del TDA recetas
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA recetas representa a un conjunto de objetos receta en un pair<string,receta>, donde el string contiene el código de la receta
  *
  * {rep.datos[0]...rep.datos[n]}
  *
  */
	map<string,receta> datos; /**< map para almacenar una receta y el código que la representa */
public:

/**
 * @brief Método que inserta en el atributo datos una receta
 * @param clave, clave que identifica a la receta
 * @param receta, receta a insertar en datos
 * @return Devuelve un pair con el atributo map y un bool que indica si la inserción se ha producido correctamente
 */
	pair<map<string,receta>::iterator,bool> insertar(string clave, receta recipe);

  void setNutricion(ingredientes &ings);

/**
 * @brief Método que borra una receta de datos dada una clave
 * @param code, clave que identifica a la receta a borrar
 * @return Devuelve un bool que indica si se ha borrado correctamente. Si no se encuentra una receta con la clave pasada por parámetro, se devuelve false
 */
  bool borrar(string code);
/**
 * @brief Método que devuelve el número de objetos receta que guarda el objeto recetas
 * @return Devuelve un entero con el número de objetos receta
 */
	int size() const;

/**
    * @brief T.D.A. iterator de recetas
    *
    * Una instancia @e c del tipo de datos abstracto @c iterator de recetas es un objeto
    * que contiene un atributo iterador que apunta a un elemento de un map<string,receta>. Se representa con
    *
    * it
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */
	class iterator{
    
    private:
        /**
  * @page repConjunto Rep del TDA iterator de recetas
  *
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA iterator de recetas representa un objeto que apunta a un elemento de recetas
  *
  * (rep.it)
  *
  */
        map<string,receta>::iterator it; 
    public:
        /**
        * @brief Constructor por defecto de la clase. Crea un iterador que apunta a una dirección inválida
        */
        iterator(){}
        /**
        * @brief Sobrecarga del operador ==
        * @param i iterador a comparar con el objeto implícito
        * @return Devuelve 0 si este objeto es igual a i
        */ 
         bool operator==(const iterator &i)const{
             return i.it==it;
         }
         /**
        * @brief Sobrecarga del operador !=
        * @param i iterador a comparar con el objeto implícito
        * @return Devuelve 0 si este objeto es distinto a i
        */ 
         bool operator!=(const iterator &i)const{
             return i.it!=it;
         }
         /**
        * @brief Sobrecarga del operador *
        * @return Devuelve el objeto apuntado por el iterador
        */ 
         receta & operator*(){
             return (*it).second;
         }
         /**
        * @brief Sobrecarga del operador ++
        * @return Devuelve el iterador aumentando en 1 la dirección donde apunta
        */ 
         iterator & operator++(){
             ++it;
             return *this;
         }
         /**
        * @brief Sobrecarga del operador --
        * @return Devuelve el iterador disminuyendo en 1 la dirección donde apunta
        */ 
         iterator & operator--(){
             --it;
             return *this;
         }

         friend class recetas;
         friend class const_iterator;
    };

    /**
    * @brief T.D.A. const_iterator de recetas
    *
    * Una instancia @e c del tipo de datos abstracto @c const_iterator de recetas es un objeto
    * que contiene un atributo iterador que apunta a un elemento de un map<string,receta>. Se representa con
    *
    * it
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */
    class const_iterator{
    private:
      /**
      * @page repConjunto Rep del TDA const_iterator de recetas
      *
      *
      * @section faConjunto Función de abstracción
      *
      * Un objeto válido @e rep del TDA const_iterator de recetas representa un objeto que apunta a un elemento de recetas
      *
      * (rep.it)
      *
      */
        map<string,receta>::const_iterator it;
    public:
        /**
        * @brief Constructor por defecto de la clase. Crea un iterador que apunta a una dirección inválida
        */
         const_iterator(){}
         /**
        * @brief Sobrecarga del operador ==
        * @param i iterador a comparar con el objeto implícito
        * @return Devuelve 0 si este objeto es igual a i
        */ 
         const bool operator==(const const_iterator &i)const{
             return i.it==it;
         }
         /**
        * @brief Sobrecarga del operador !=
        * @param i iterador a comparar con el objeto implícito
        * @return Devuelve 0 si este objeto es distinto a i
        */ 
         const bool operator!=(const const_iterator &i)const{
             return i.it!=it;
         }
         /**
        * @brief Sobrecarga del operador *
        * @return Devuelve el objeto apuntado por el iterador
        */ 
         const receta & operator*(){
             return (*it).second;
         }
         /**
        * @brief Sobrecarga del operador ++
        * @return Devuelve el iterador aumentando en 1 la dirección donde apunta
        */ 
         const_iterator & operator++(){
             ++it;
             return *this;
         }
         /**
        * @brief Sobrecarga del operador --
        * @return Devuelve el iterador disminuyendo en 1 la dirección donde apunta
        */ 
         const_iterator & operator--(){
             --it;
             return *this;
         }

         friend class recetas;
    };
    /**
    * @brief Dirección de inicio del objeto recetas
    * @return Devuelve un iterator que apunta a la dirección de inicio del objeto recetas
    */
    iterator begin(){
        recetas::iterator i;
        i.it=datos.begin();
        return i;
    }
    /**
  * @brief Dirección de fin del objeto recetas
  * @return Devuelve un iterator que apunta a la dirección donde termina el objeto recetas
  */
    iterator end(){
        recetas::iterator i;
        i.it=datos.end();
        return i;
    }
    /**
    * @brief Dirección de inicio constante del objeto recetas
    * @return Devuelve un const_iterator que apunta a la dirección de inicio del objeto recetas
    */
    const_iterator cbegin()const{
        recetas::const_iterator i;
        i.it=datos.cbegin();
        return i;
    }
    /**
  * @brief Dirección de fin constante del objeto recetas
  * @return Devuelve un const_iterator que apunta a la dirección donde termina el objeto recetas
  */
    const_iterator cend()const{
        recetas::const_iterator i;
        i.it=datos.cend();
        return i;
    }
    /**
  * @brief Sobrecarga del operador []
  * @param code, código de la receta a devolver
  * @return Devuelve la receta con código code
  */
    receta operator[](string code){
        for(map<string,receta>::iterator it=datos.begin();it!=datos.end();++it){
            if((*it).first==code){
                return (*it).second;
            }
        }
        receta ret;
        ret.setNombre("Undefined");
        return ret;
    }
    /**
  * @brief Sobrecarga del operador []
  * @param i, índice de la receta a devolver
  * @return Devuelve la receta con índice i
  */
    receta operator[](int i){
        int contador=0;
        map<string,receta>::iterator it=datos.begin();
        while(contador!=i&&it!=datos.end()){
            contador++;
            ++it;
        }
        return (*it).second;
    }

    bool CargarRecetas(const string &nombre, const string &path_ins);

    friend istream& operator>>(istream &is, recetas &recipes);
    friend ostream & operator<<(ostream &os, const recetas & aux);
};


#endif
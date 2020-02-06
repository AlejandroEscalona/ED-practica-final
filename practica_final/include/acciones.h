#ifndef ACCIONES
#define ACCIONES
#include<iostream>
#include<map>

using namespace std;

class acciones{
private:

	map<string,unsigned char> datos;

public:
    //DUDA: Pq no puedo quitar este constructor y dejar los otros dos?
	//acciones();

	//acciones(const map<string,unsigned char>);

	//acciones(const string s, const unsigned char n);

    //Operador [] de map no esta acreditado para const
	int getAriedad(const string s) const;

	class iterator{
	private:
		map<string,unsigned char>::iterator it;
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
         pair<const string,unsigned char>  & operator*(){
             return *it;
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

         friend class acciones;
         friend class const_iterator;
    };

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
        map<string,unsigned char>::const_iterator it;
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

        //Pq hace falta poner const en el string???
        const pair<const string,unsigned char> & operator*(){
             return *it;
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

         friend class acciones;
    };
    /**
    * @brief Dirección de inicio del objeto recetas
    * @return Devuelve un iterator que apunta a la dirección de inicio del objeto recetas
    */
    iterator begin(){
        acciones::iterator i;
        i.it=datos.begin();
        return i;
    }
    /**
  * @brief Dirección de fin del objeto recetas
  * @return Devuelve un iterator que apunta a la dirección donde termina el objeto recetas
  */
    iterator end(){
        acciones::iterator i;
        i.it=datos.end();
        return i;
    }
    /**
    * @brief Dirección de inicio constante del objeto recetas
    * @return Devuelve un const_iterator que apunta a la dirección de inicio del objeto recetas
    */
    const_iterator cbegin()const{
        acciones::const_iterator i;
        i.it=datos.cbegin();
        return i;
    }
    /**
  * @brief Dirección de fin constante del objeto recetas
  * @return Devuelve un const_iterator que apunta a la dirección donde termina el objeto recetas
  */
    const_iterator cend()const{
        acciones::const_iterator i;
        i.it=datos.cend();
        return i;
    }
    /**
  * @brief Sobrecarga del operador []
  * @param code, código de la receta a devolver
  * @return Devuelve la receta con código code
  */

  friend istream& operator>>(istream &is, acciones &actions);
  friend ostream & operator<<(ostream &os, const acciones & aux);
};

#endif
/**
  * @file ingredientes.h
  * @brief Fichero cabecera del TDA ingredientes
  *
*/
#ifndef INGREDIENTES
#define INGREDIENTES
#include <iostream>
#include "ingrediente.h"
#include <vector>

using namespace std;

/**
    * @brief T.D.A. ingredientes
    *
    * Una instancia @e c del tipo de datos abstracto @c ingredientes es un objeto
    * que contiene varios atributos como
    *
    * datos e indice
    *
    * Un ejemplo de su uso:
    * @include ingredientes.cpp
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Octubre 2019
    */
class ingredientes{
private:
	/**
  	* @page repConjunto Rep del TDA ingredientes
  	*
  	* @section faConjunto Función de abstracción
  	*
  	* Un objeto válido @e rep del TDA ingredientes representa a un conjunto de objetos ingrediente
  	*
  	* {(rep.datos[0],rep.indice[0])...(rep.datos[n],rep.indice[n])}
  	* 
  	*/
	vector<ingrediente> datos; /**< zona de memoria para almacenar los datos tipo ingrediente, ordenados por nombre */
	vector<int> indice;/**< zona de memoria para almacenar los datos de tipo int para guardar las posiciones*/

public:

    /**
 * @brief Metodo que comprueba que un ingrediente está en el atributo datos.
 * @param ingrediente, que es el ingrediente a comprobar.
 * @param bool encontrado, que muestra si se ha encontrado o no.
 * @return devuelve la posición en la que está si se ha encontrado, y si no está, devuelve la posición en la que debería ir.
 */
	int EstaDatos(const ingrediente &ingrediente, bool & encontrado) const;
/**
 * @brief metodo que inserta en el atributo datos e indice un ingrediente
 * @param ingrediente, ingrediente a insertar en datos e indice
 */
	void Insertar(const ingrediente& ingrediente);
/**
 * @brief Metodo que  muestra si un ingrediente está en el atributo indice
 * @param ingrediente, el ingrediente a comprobar en indice
 * @return Devuelve un pair con la posicion y un bool que muestra si está o no. Si está muestra su posición y si no, muestra donde debería ir
 */
	pair<bool,int> EstaIndice(const ingrediente& ingrediente) const;
/**
 * @brief Metodo que borra un ingrediente en los atributos datos e indice a traves de saber su nombre
 * @param nombre, nombre del ingrediente a borrar
 */
	void borrar(const string nombre);
/**
 * @brief Metodo que pone a cero los vectores de datos e indice.
 */
	void clear();
/**
 * @brief Metodo que muestra el tamaño del vector de datos, que debe ser el mismo que de indice
 */
	int size() const;
/**
 * @brief Metodo para saber los tipos de ingredientes
 * @return Devuelve un vector dinamico con los tipos de ingrediente
 */
	vector<string> getTipos() const;
/**
 * @brief Metodo que devuelve un ingrediente solicitado
 * @param nombre, nombre del ingrediente solicitado
 * @return Devuelve un ingrediente sabiendo su nombre
 */
	ingrediente get(const string nombre) const;
/**
 * @brief Metodo que imprime los ingredientes por tipo
 * @param os, flujo de salida para imprimir los ingredientes según tipo
 */
	void ImprimirPorTipo(ostream &os) const;
/**
 * @brief Metodo que devuelve ingredientes según un tipo
 * @param tipo, tipo por el que se seleccionan los ingredientes a mostrar
 * @return conjunto de ingredientes de u determinado tipo
 */
	ingredientes getIngredienteTipo(const string tipo) const;
/**
 * @brief Metodo que sobrecarga el operador [ ]
 * @param pos, posicion seleccionada para mostrar
 * @return ingrediente solicitado por una posicion, constante que impide la modificacion
 */
	const ingrediente & operator[](const int pos) const;
/**
 * @brief Metodo que sobrecarga el operador [ ]
 * @param i, posicion seleccionada para mostrar
 * @return ingrediente solicitado por una posicion
 */
	ingrediente & operator[](const int i);
/**
 * @brief Metodo que sobrecarga el operador << de salida
 * @param os, flujo de salida
 * @param aux, ingrediente const a mostrar
 * @return ingrediente solicitado
 */
	friend ostream & operator<<(ostream &os, const ingredientes & aux);
/**
 * @brief Metodo que sobrecarga el operador >> de entrada
 * @param is, flujo de entrada
 * @param aux, ingrediente a modificar
 * @return ingrediente modificado
 */
	friend istream & operator>>(istream &is, ingredientes & aux);

	/**
    * @brief T.D.A. iterator de ingredientes
    *
    * Una instancia @e c del tipo de datos abstracto @c iterador de ingredientes es un objeto
    * que contiene un atributo iterador que apunta a un elemento de un vector<ingrediente>::datos. Se representa con
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
	  * @page repConjunto Rep del TDA iterator de ingredientes
	  *
	  *
	  * @section faConjunto Función de abstracción
	  *
	  * Un objeto válido @e rep del TDA iterator de ingredientes representa un objeto que apunta a un elemento de ingredientes
	  *
	  * (rep.it)
	  *
	  */
			vector<ingrediente>::iterator it;
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
		 ingrediente & operator*(){
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

		 friend class ingredientes;
		 friend class const_iterator;
	};
	/**
    * @brief T.D.A. iterator de ingredientes
    *
    * Una instancia @e c del tipo de datos abstracto @c const_iterator de ingredientes es un objeto
    * que contiene un atributo iterador que apunta a un elemento de un vector<ingrediente>::datos. Se representa con
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
	      * @page repConjunto Rep del TDA const_iterator de ingredientes
	      *
	      *
	      * @section faConjunto Función de abstracción
	      *
	      * Un objeto válido @e rep del TDA const_iterator de ingredientes representa un objeto que apunta a un elemento de ingredientes
	      *
	      * (rep.it)
	      *
	      */
			vector<ingrediente>::const_iterator it;
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
		 const ingrediente & operator*(){
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

		 const_iterator & operator--(){
			 --it;
			 return *this;
		 }
		 /**
        * @brief Sobrecarga del operador --
        * @return Devuelve el iterador disminuyendo en 1 la dirección donde apunta
        */ 
		 friend class ingredientes;
	};
	/**
    * @brief Dirección de inicio del objeto ingredientes
    * @return Devuelve un iterator que apunta a la dirección de inicio del objeto ingredientes
    */
	iterator begin(){
		ingredientes::iterator i;
		i.it=datos.begin();
		return i;
	}
	/**
 	 * @brief Dirección de fin del objeto ingredientes
  	* @return Devuelve un iterator que apunta a la dirección donde termina el objeto ingredientes
 	 */
    iterator end(){
    	ingredientes::iterator i;
    	i.it=datos.end();
    	return i;
    }
    /**
    * @brief Dirección de inicio constante del objeto ingredientes
    * @return Devuelve un const_iterator que apunta a la dirección de inicio del objeto ingredientes
    */
    const_iterator cbegin() const{
    	const_iterator i;
    	i.it=datos.cbegin();
    	return i;
    }
    /**
  * @brief Dirección de fin constante del objeto ingredientes
  * @return Devuelve un const_iterator que apunta a la dirección donde termina el objeto ingredientes
  */
    const_iterator cend() const{
    	const_iterator i;
    	i.it=datos.cend();
    	return i;
    }

};

#endif

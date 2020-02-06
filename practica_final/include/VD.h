//file VECTOR_H
#ifndef VECTOR_H
#define VECTOR_H

template <class T>
class VD{
/**
  *  @brief T.D.A. vector
  *
  * Una instancia @e c del tipo de datos abstracto @c vector es un objeto
  * que continene un VD Dinamico de un tipo de dato abstracto, compuesto
  * por *datos,n y reservados una poblacion que representan, respectivamente,
  * un puntero al vector, el tamaño del vector y las posiciones que tiene ocupadas
  * Lo representamos
  *
  * datos/n/reservados
  *
  * Un ejemplo de su uso:
  * @include vector.cpp
  *
  * @author Alejandro Escalona Garcia
  * @author Pedro Bedmar Lopez
  * @date Octubre 2019
  */
    private:

    T*datos;/**< zona de memoria para almacenar los datos de tipo T */
    int n;/**<  numero de datos almacenados*/
    int reservados;/**<  *espacio asignado a datos/

 *@brief metodo que copia el un vector en otro
 * @param &original vector al que sera copiara el vector sobre el que se aplica el metodo
 */
    void Copiar(const VD<T> &v);
/**
 * @brief metodo que libera la memoria dinamica que ha sido utilizada
 */
    void Liberar();
/**
 * @brief funcion que redimensiona el vector cuando necesitamos espacio
 * @param n_tam tamaño que nuestro vector posee antes de ser redimensionado
 */
    void resize(int n_tam);
/**
 * @brief funcion que redimensiona el vector cuando necesitamos espacio
 * @param n_tam tamaño que nuestro vector posee antes de ser redimensionado
 */
    public:
        VD(int vector=10);
 /**
  * @brief constructor de la clase sin parametros
  * @param vector=10 inicializa el tamaño del vector
  */
    VD(const VD<T> &original);
/**
 * @brief constructor de copia de la clase vector
 * @param &original vector que procederemos a copiar
 * @return devuelve el vector copiado
 */
    VD<T> &operator=(const VD<T> &original);
/**
 * @brief sobrecarga del operador igual que asigna a un vector sobre el que trabajamos a otro
 * dado si no es el mismo
 * @param &original vector al que sera asignado el vector sobre el que se aplica el metodo
 * @return devuelve el objeto al que ha sido asignado el nuestro
 */
    ~VD();
/**
 * @brief destructor de la clase vector. Destruye la memoria dinamica utilizada or la clase vector
 */
    int size()const;
/**
 * @brief metodo que devuelve el tamaño del vector
 */
    T &operator[](int i);
/**
 * @brief funcion que retorna la posicion que se pasa como parametro
 * @param pos posicion en cuestion
 * @return devuelve el contenido de la posicion
 */
    const T &operator[](int i) const;
/**
 * @brief funcion que retorna la posicion que se pasa como parametro
 * @param pos posicion en cuestion
 * @return devuelve el contenido de la posicion constante
 */
    void insertar(const T &dato,int pos);
/**
 * @brief funcion que inserta el dato que se pasa como parametro en su posicion correspondiente
 * @param &dato dato que se va a insertar
 * @param pos posicion en la que se va a insertar
 */
    void borrar(int pos);
/**
 * @brief funcion que borra el elemento en la posicion que se pasa como parametro
 * @param pos posicion del elemento que vamos a borrar
 */

};
#include "VD.cpp"

#endif

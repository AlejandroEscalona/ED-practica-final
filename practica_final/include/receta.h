/**
  * @file receta.h
  * @brief Fichero cabecera del TDA receta
  *
  */

#ifndef RECETA
#define RECETA
#include <string>
#include <list>
#include <iostream>
#include"ingredientes.h"
#include"instrucciones.h"
using namespace std;

  /**
    *  @brief T.D.A. receta
    *
    * Una instancia @e c del tipo de datos abstracto @c receta es un objeto
    * que contiene varios atributos como
    *
    * code, plato, nombre e ingredientes
    *
    * Un ejemplo de su uso:
    * @include receta.cpp
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */


class receta{

/**
  * @page repConjunto Rep del TDA receta
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e que debe haber minimo un ingrediente en la receta, un nombre, un código y un plato.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA receta
  *
  * (code, plato, nombre, ings, calorias, hc, grasas, proteinas, fibra)
  *
  */


private:
 string code; /**< zona de memoria para almacenar el codigo de la receta*/
 unsigned int plato; /**< zona de memoria para almacenar el indice del plato*/
 string nombre; /**< zona de memoria para almacenar el nombre del plato*/
 list<pair<string,unsigned int> > ings; /**< zona de memoria para almacenar todos los ingredientes de la receta */
 float calorias,hc,grasas,proteinas,fibra; /**< zona de memoria para almacenar los datos nutricionales de la receta */
 instrucciones inst;



public:

    instrucciones getInstruciones(){

        return inst;

    }


    void Fusion(const receta parte2);

    /**
 * @brief Metodo que devuelve las calorias.
 * @return devuelve las calorias.
 */
    float getCalorias()const;

    /**
 * @brief Metodo que devuelve los carbohidratos.
 * @return devuelve los carbohidratos.
 */
    float getHc()const;

    /**
 * @brief Metodo que devuelve las proteinas.
 * @return devuelve las proteinas.
 */
    float getProteinas()const;


    /**
 * @brief Metodo que devuelve las grasas.
 * @return devuelve las grasas.
 */
    float getGrasas()const;


    /**
 * @brief Metodo que devuelve la fibra.
 * @return devuelve la fibra.
 */
    float getFibra()const;

/**
 * @brief Metodo que modifica las calorias
 * @param new_calorias, las nuevas calorias
 * @return receta modificada
 */
    void setCalorias(const float new_calorias);


/**
 * @brief Metodo que modifica los hidratos de carbono
 * @param new_hc, los nuevos carbohidratos
 * @return receta modificada
 */
    void setHc(const float new_hc);

/**
 * @brief Metodo que modifica un ingediente
 * @param ingre, nuevo ingrediente
 * @return receta modificada
 */
    void setIngs(pair<string,unsigned int> ingre);

/**
 * @brief Metodo que modifica las proteinas
 * @param new_proteinas, las nuevas calorias
 * @return receta modificada
 */
    void setProteinas(const float new_proteinas);


/**
 * @brief Metodo que modifica las grasas
 * @param new_grasas, las nuevas grasas
 * @return receta modificada
 */
    void setGrasas(const float new_grasas);

/**
 * @brief Metodo que modifica la fibra
 * @param new_fibra, la nueva fibra
 * @return receta modificada
 */
    void setFibra(const float new_fibra);

    /**
 * @brief Metodo que devuelve el nombre.
 * @return devuelve el nombre.
 */
    string getNombre()const;

/**
 * @brief Metodo que modifica el nombre
 * @param S, el nuevo nombre
 * @return receta modificada
 */
    void setNombre(const string S);

    /**
 * @brief Metodo que devuelve el code.
 * @return devuelve el code.
 */
    string getCode()const;

/**
 * @brief Metodo que modifica el codigo
 * @param S, el nuevo codigo
 * @return receta modificada
 */
    void setCode(const string S);

/**
 * @brief Metodo que modifica el plato
 * @param i, el nuevo plato
 * @return receta modificada
 */

    void setPlato(const unsigned int i);


    /**
 * @brief Metodo que devuelve el numero de plato
 * @return devuelve el plato
 */
    unsigned int getPlato()const;


    /**
 * @brief Metodo que devuelve el numero de ingredientes
 * @return devuelve el numero de ingredientes
 */



    void setInstrucciones(const instrucciones ins){inst=ins;};





    int ningredientes() const;


    /**
 * @brief Metodo que pone a 0 la receta
 */
    void clear(){
        ings.clear();
    }

  /**
    *  @brief T.D.A. iterador de receta
    *
    * Una instancia @e c del tipo de datos abstracto @c receta es un objeto que apunta a un list de pares denominado it
    *
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */


    class iterator{

/**
  * @page repConjunto Rep del TDA iterator de la clase receta
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e que debe apuntar a un elemento de la lista de pares de ingredientes.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA iterator de la clase receta
  *
  * (it)
  *
  */

    private:
        list<pair<string,unsigned int> >::iterator it;
    public:
        iterator(){}

        /**
         * @brief Metodo que sobrecarga el operador ==
         * @param i, iterator con el que se compara
         * @return devuelve si son iguales o no
         */
         bool operator==(const iterator &i)const{
             return i.it==it;
         }

         /**
         * @brief Metodo que sobrecarga el operador !=
         * @param i, iterator con el que se compara
         * @return devuelve si son diferentes o no
         */
         bool operator!=(const iterator &i)const{
             return i.it!=it;
         }
         /**
         * @brief Metodo que sobrecarga el operador *
         * @return devuelve lo apuntado por el iterador
         */
         pair<string, unsigned int> & operator*(){
             return *it;
         }

         /**
         * @brief Metodo que sobrecarga el operador ++
         * @return devuelve el propio iterador
         */
         iterator & operator++(){
             ++it;
             return *this;
         }

         
         /**
         * @brief Metodo que sobrecarga el operador --
         * @return devuelve el propio iterador
         */
         iterator & operator--(){
             --it;
             return *this;
         }

         friend class receta;
         friend class const_iterator;
    };


 /**
    *  @brief T.D.A. const iterador de receta
    *
    * Una instancia @e c del tipo de datos abstracto @c receta es un objeto constante que apunta a un list de pares denominado it
    *
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Diciembre 2019
    */
    class const_iterator{

/**
  * @page repConjunto Rep del TDA iterator de la clase receta
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e que debe apuntar a un elemento de la lista de pares de ingredientes.
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA const iterator de la clase receta
  *
  * (it)
  *
  */

    private:
        list<pair<string,unsigned int> >::const_iterator it;
    public:
         const_iterator(){}
        
        /**
         * @brief Metodo que sobrecarga el operador ==
         * @param i, const iterator con el que se compara
         * @return devuelve si son iguales o no
         */
         const bool operator==(const const_iterator &i)const{
             return i.it==it;
         }

         /**
         * @brief Metodo que sobrecarga el operador !=
         * @param i, const iterator con el que se compara
         * @return devuelve si son diferentes o no
         */
         const bool operator!=(const const_iterator &i)const{
             return i.it!=it;
         }
          /**
         * @brief Metodo que sobrecarga el operador *
         * @return devuelve lo apuntado por el const iterador
         */
         const pair<string, unsigned int> & operator*(){
             return *it;
         }
         /**
         * @brief Metodo que sobrecarga el operador ++
         * @return devuelve el propio const iterador
         */
         const_iterator & operator++(){
             ++it;
             return *this;
         }
         /**
         * @brief Metodo que sobrecarga el operador --
         * @return devuelve el propio const iterador
         */
         const_iterator & operator--(){
             --it;
             return *this;
         }

         friend class receta;
    };

    iterator begin(){
        receta::iterator i;
        i.it=ings.begin();
        return i;
    }

    iterator end(){
        receta::iterator i;
        i.it=ings.end();
        return i;
    }

    const_iterator cbegin()const{
        receta::const_iterator i;
        i.it=ings.cbegin();
        return i;
    }

    const_iterator cend()const{
        receta::const_iterator i;
        i.it=ings.cend();
        return i;
    }

    friend istream& operator>>(istream &is, receta &recipe);
    friend ostream & operator<<(ostream &os,const receta & aux);

};//end receta

#endif

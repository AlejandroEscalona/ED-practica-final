/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA ingrediente
  *
  */

#ifndef INGREDIENTE
#define INGREDIENTE
#include <iostream>
#include <string>

using namespace std;
 /**
    *  @brief T.D.A. ingrediente
    *
    * Una instancia @e c del tipo de datos abstracto @c ingrediente es un objeto
    * que contiene varios atributos por ejemplo
    *
    * Nombre,Calorias,Hc, Proteinas...
    *
    * Un ejemplo de su uso:
    * @include ingrediente.cpp
    *
    * @author Alejandro Escalona Garcia
    * @author Pedro Bedmar Lopez
    * @date Octubre 2019
    */
class ingrediente{
 /**
  * @page repConjunto Rep del TDA ingrediente
  *
  * @section invConjunto Invariante de la representación
  *
  * Los invariantes son: \e Nombre, calorias, hc, proteinas, grasas, fibra y tipo
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Racional representa al valor
  *
  * (Nombre, calorias, hc, proteinas, grasas, fibra y tipo)
  *
  */


private:

  string Nombre; /**< Nombre del ingrediente */
  float Calorias;  /**< Calorias que tiene el ingrediente */
  float Hc; /**< Hidratos de carbono que tiene el ingrediente*/
  float Proteinas;  /**< Proteinas que tiene el ingrediente */
  float Grasas;  /**< Grasas que tiene el ingrediente e */
  float Fibra;  /**< Fibra que tiene el ingrediente  */
  string Tipo;  /**< Tipo del ingrediente */

public:
/**
  * @brief Metodo para obtener el nombre del ingrediente
   * @return devuelve el nombre como un string
  */
  string getNombre()const;
  /**
  * @brief Metodo para obtener las calorias del ingrediente
   * @return devuelve las calorias como un float
  */
  float getCalorias()const;
   /**
  * @brief Metodo para obtener los hidratos de carbono del ingrediente
   * @return devuelve los hidrados de carbono como un float
  */
  float getHc()const;
   /**
  * @brief Metodo para obtener las proteinas del ingrediente
   * @return devuelve las proteinas como un float
  */
  float getProteinas()const;
   /**
  * @brief Metodo para obtener las grasas
   * @return devuelve las grasas como un float
  */
  float getGrasas()const;
   /**
  * @brief Metodo para obtener la fibra del ingrediente
   * @return devuelve la fibra como un float
  */
  float getFibra()const;
   /**
  * @brief Metodo para obtener el tipo del ingrediente
   * @return devuelve el tipo como un string
  */
  string getTipo()const;
/**
 * @brief Metodo para sobrecargar el operador de entrada
 * @param is: flujo de entrada, ingrediente: ingrediente sobre el que se guarda la información
 */
  friend istream & operator>>(istream &is, ingrediente &ingr);
  /**
 * @brief Metodo para sobrecargar el operador de salida
 * @param os: flujo de  salida, ingrediente: ingrediente que se muestra
 */
  friend ostream & operator<<(ostream &os,const ingrediente &ingr);

/**
 * @brief Metodo que modifica el nombre
 * @param S, string que se pone en lugar del nombre
 */
  void setNombre(const string S);
  /**
 * @brief Metodo que modifica las calorias
 * @param new_calorias, son las nuevas calorias del ingrediente
 */
  void setCalorias(const float new_calorias);
  /**
 * @brief Metodo que modifica los hidratos de carbono
 * @param new_hc, son los nuevos hidratos de carbono del ingrediente
 */
  void setHc(const float new_hc);
  /**
 * @brief Metodo que modifica las proteinas
 * @param new_proteinas, son las nuevas proteinas del ingrediente
 */
  void setProteinas(const float new_proteinas);
  /**
 * @brief Metodo que modifica las grasas
 * @param new_grasas, son las nuevas grasas del ingrediente
 */
  void setGrasas(const float new_grasas);
  /**
 * @brief Metodo que modifica la fibra del ingrediente
 * @param new_fibra, es la nueva fibra del ingrediente
 */
  void setFibra(const float new_fibra);
  /**
 * @brief Metodo que modifica el tipo del ingrediente
 * @param S, string que se pone en lugar del tipo
 */
  void setTipo(const string S);

  
};
  /**
 * @brief Metodo para sobrecargar el operador ==, compara todos los atributos entre dos ingredientes
 * @param ingrediente izq, ingrediente a comparar
 * @param ingrediente ing, ingrediente a comparar
 */
bool operator==(const ingrediente & izq, const ingrediente & ing);

#endif

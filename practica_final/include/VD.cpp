#include "VD.h"

template <class T>
VD<T>::VD(int tam){
    if(tam==0){
        datos=0;
        reservados=0;
        n=0;
    }
    else{
        reservados=tam;
        n=0;
        datos=new T[reservados];
    }
}

template <class T>
void VD <T>::Copiar(const VD<T> &v){
    reservados = v.reservados;
    n = v.n;
    datos = new T [reservados];
    for(int i = 0; i < n; i++){
        datos[i] = v.datos[i];
    }
}

template <class T>
void VD<T>::Liberar(){
    delete [] datos;
}

template <class T>
VD <T> & VD<T>::operator=(const VD<T> &original){

    if(this!=&original){
        if(datos!=0){
            Liberar();
            Copiar(original);
        }
    }

    return *this;
}

template <class T>
VD <T>::VD(const VD<T> &original){
    reservados=original.reservados;
    n=original.n;

    if(reservados>0)
        datos=new T[reservados];
    else
        datos=0;

    for(int i=0;i<n;i++)
        datos[i]=original.datos[i];
}

template <class T>
void VD<T>::resize(int n_tam){
    T *aux=new T[n_tam];
    int n_copiar = (n<n_tam)?n:n_tam;

    for(int i=0;i<n_copiar;i++)
        aux[i]=datos[i];

    reservados=n_tam;
    n=n_copiar;
    delete[]datos;
    datos=aux;
}

template <class T>
void VD<T> :: insertar(const T &dato,int pos){
    if(n>=reservados)
        resize(2*reservados);

    for(int i=n;i>pos;i--){
        datos[i]=datos[i-1];
    }
    datos[pos]=dato;
    n++;
}

template <class T>
void VD<T> :: borrar(int pos){
    for(int i=pos;i<n-1;i++)
        datos[i]=datos[i+1];

    n--;

    if(n<(reservados/4))
        resize (reservados/2);
}

template <class T>
VD<T>::~VD(){
    if(datos!=0)
        Liberar();
}

template <class T>
int VD<T>::size()const{
    return n;
}

template <class T>
const T& VD<T>::operator[] (int i)const{
    return datos[i];
}

template <class T>
T & VD<T>::operator[] (int i){
    return datos[i];
}

#ifndef INSTRUCCIONES
#define INSTRUCCIONES

#include <iostream>
#include "arbolbinario.h"
#include "ingredientes.h"
#include "acciones.h"
#include <stack>
#include <string>



class instrucciones{
private:
	ArbolBinario<string> datos;
	acciones acc;
	ingredientes ings;
public:

	friend istream & operator>>(istream &is, instrucciones &instructions);

	friend ostream & operator<<(ostream &os, const instrucciones &instructions);

	void setAcc(const acciones &ac){
		acc=ac;
	}

	void setIngs(const ingredientes &ing){
		ings=ing;
	}

    ArbolBinario<string> getArbol() const {
		return datos;
	}

	void setInst(const ArbolBinario<string> datos2){
		datos = datos2;

	}

	bool empty()const {
		return datos.empty();
	}

};

#endif

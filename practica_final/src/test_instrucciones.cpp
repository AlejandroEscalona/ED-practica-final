#include <iostream>
#include <fstream>
#include "instrucciones.h"
#include "ingredientes.h"
#include "acciones.h"
using namespace std;

int main (int argc, char *argv[]) {
	acciones actions;
	ifstream fentrada1(argv[1]);
	fentrada1 >> actions;

	instrucciones inst;
	inst.setAcc(actions);

	ifstream fentrada2(argv[2]);
	ingredientes ings;
	fentrada2 >> ings;

	inst.setIngs(ings);

	ifstream fentrada3(argv[3]);
	fentrada3 >> inst;

	cout << inst << endl;
}
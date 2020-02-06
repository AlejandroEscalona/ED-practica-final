#include <acciones.h>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]){
	acciones actions;
	
	ifstream f(argv[1]);

	f >> actions;

	//cout << actions;

	cout << "----" <<actions.getAriedad("Mezclar") << "----\n" ;

	return 0;
}
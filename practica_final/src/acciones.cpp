#include "acciones.h"

istream& operator>>(istream &is, acciones &actions){
	string accion;
	while(getline(is,accion)){
		if (accion.size()==0) return is;
		int i=0;
		string tag_accion;
		unsigned char tag_ariedad;
		while(accion[i]!=' '){
			tag_accion+=accion[i];
			i++;
		}
		
		i++;
		tag_ariedad=accion[i];

		pair<string,unsigned char> insertar;
		insertar.first=tag_accion;
		insertar.second=tag_ariedad;
		actions.datos.insert(insertar);
	}

	return is;
}

ostream& operator<<(ostream &os, const acciones &actions){
	for(acciones::const_iterator it=actions.cbegin();it!=actions.cend();++it){
		cout << (*it).first << " " << (*it).second << endl;
	}
	return os;
}

int acciones::getAriedad(const string s) const{
	unsigned char devolver = datos.at(s);
	char buf[5];
	sprintf(buf,"%c",devolver);
	int num = atoi(buf);
	return num;
}
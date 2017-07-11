#include "diccionario.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;
 

void load(diccionario & d, const string & s){
 // lectura del fichero en el diccionario
	ifstream f(s.c_str());
	
	while(!f.eof()){
		string clave="",tipo="",masa="",caido="",year="",latitud="",longitud="";
		char c = f.get();
		if(c!='\0' && !(f.eof())){
			while(c!=';'){
				clave+=c;
				c = f.get();
			}
			c=' ';
			while(c!=';'){
				tipo+=c;
				c = f.get();
			}
			c=' ';
			while(c!=';'){
				masa+=c;
				c = f.get();
			}
			c=' ';
			while(c!=';'){
				caido+=c;
				c = f.get();
			}
			c=' ';
			while(c!=';'){
				year+=c;
				c = f.get();
			}
			c=' ';
			while(c!=';'){
				latitud+=c;
				c = f.get();
			}
			c=' ';
			while(c!='\n'){
				longitud+=c;
				c = f.get();
			}
			pair<string, defM> entr;
			entr.first = clave;
			defM definicion;
			definicion.setCode(tipo);
			definicion.setMas(atof(masa.c_str()));
			if(caido.compare("fall")==0 || caido.compare("fell")==0)
				definicion.setFall(true);
			else
				definicion.setFall(false);

			definicion.setYear(year);
			definicion.setLat(atof(latitud.c_str()));
			definicion.setLong(atof(longitud.c_str()));
			entr.second=definicion;
			d.insert(entr);
		}
	}
}
ostream &  operator << ( ostream & sal, const  pair<string, defM> & e){
	sal <<"Clave:"<< e.first <<"Valor:" << e.second <<endl;
	return sal;
}
int main()
{
    diccionario D;
    meteorito m;
    defM x;
 
    

    D.insert(m);
    pair<diccionario::entrada,bool> p;
    p = D.find("aaaa");
    if (p.second==true) cout << p.first << endl;
    else cout << "No existe aaaa" << endl;
    cout<< D["Barcelona"] << endl;
    D["Valencia"] = x;
    cout<< D["Valencia"] << endl;

    diccionario meteoritos;
    load(meteoritos, "meteorites_all.csv");
	cout<< meteoritos["Abee"] << endl;
   return 0;
}

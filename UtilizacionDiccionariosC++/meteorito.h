/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __METEORITO_H
#define __METEORITO_H

#include <string>
#include <iostream> 
#include <vector>

using namespace std;

//! Clase defM, asociada a la definición de un meteorito 
/*! defM::defM .....
 * Descripción contiene toda la información asociada a un meteorito.
 
 @todo Implementa esta clase, junto con su documentación asociada

*/

typedef string nombreM;



class defM {
 public:
  defM();
  defM(const defM & x);
  bool setCode(const string & s);
  void setMas(const double &  m);
  void setFall(bool f);
  void setYear(const string & y);
  void setLat(const double & lat);
  void setLong(const double & longi);
  vector<string> getCodes( ) const;
  double getMas( ) const;
  bool getFall( ) const;
  string getYear( ) const;
  double getLat( ) const;
  double getLong( ) const;
 private:
    	friend  ostream& operator<< ( ostream& , const defM & );
  	nombreM nombreMeteo;
	vector<string> tipo;
	double masa;
	bool caidoEncontrado;
	string year;
	double latitud;
	double longitud;
	
};

typedef pair<nombreM,defM> meteorito;


ostream & operator<< ( ostream& , const meteorito & );

#include "meteorito.hxx"
#endif

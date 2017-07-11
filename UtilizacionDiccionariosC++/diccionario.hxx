/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
 * 
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 * 
 *
===================================================================================
Funcion de Abstraccion:
  @todo incluir funcion de abstracción 
=====================================================================================
Invariante de la Representación:

  @todo incluir invariante dela representación 
=====================================================================================
*/
#include <assert.h>


/**
 @todo implementa esta función
*/
diccionario::diccionario(){ 

}

/**
 @todo implementa esta función
*/
diccionario::diccionario (const diccionario & d){

}


/**
 @todo implementa esta función
*/
pair<diccionario::entrada,bool> & diccionario::find( const defM & s) const{

}

/**
 @todo implementa esta función
*/
defM & diccionario::operator[](const nombreM & s) {

}
	

/**
 @todo implementa esta función
*/
const defM & diccionario::operator[](const nombreM & s) const{

}


/**
 @todo implementa esta función
*/
bool diccionario::insert(const diccionario::entrada & e) const{

}

/**
 @todo implementa esta función
*/
diccionario & diccionario::operator=( const diccionario & org){

}

/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/

diccionario::size_type diccionario::size() const {

}

/**
 @todo implementa esta función
*/
bool diccionario::empty() const{

}
   
	 
/**
 @todo implementa esta función
*/
bool diccionario::cheq_rep( ) const {

}
  
/**
 @todo implementa esta función
*/
ostream &  operator << ( ostream & sal, const diccionario & D){
  
}



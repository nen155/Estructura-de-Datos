#ifndef __DICCIONARIOV1_HXX
#define __DICCIONARIOV1_HXX
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


/** @brief constructor primitivo. 
@post define la entrada nula como el par ("",-1)
*/
diccionario::diccionario(){
	defM defi;
	entrada entra("",defi);
	dic.push_back(entra);
}

/** @brief constructor de copia
@param[in] d diccionario a copiar
*/
diccionario::diccionario (const diccionario & d){
	this->dic.clear();
	this->dic = vector<entrada>(d.dic.begin(),d.dic.end());
}


/** @brief busca una meteorito en el diccionario
@param s cadena a buscar
@return una copia de la entrada en el diccionario. Si  no se encuentra devuelve la entrada con la definicion por defecto
@post no modifica el diccionario.
\verbatim Uso
       

if (D.find("aaa").second ==true) cout << "Esta" ;
else cout << "No esta";
\endverbatim
*/
pair<diccionario::entrada,bool>  diccionario::find( const nombreM & s) const{
	int i=0;	
	bool flag=true; 
	pair<diccionario::entrada,bool> par;
	
	for(i = 0; i < dic.size() && dic[i].first.compare(s) != 0;i++);

	if(i==dic.size()){
		flag=false;
		entrada aux;
		par = pair<diccionario::entrada,bool>(aux,flag);
	}
	else{
		flag = true;
		entrada aux(dic[i].first,dic[i].second);
		par = pair<diccionario::entrada,bool>(aux,flag);
	}
	return par;

}

/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia a la definición de la misma
en caso contrario la inserta, con una definición por defecto, devolviendo una referencia a este valor.
 
@param[in] s cadena a insertar
@param[out] defM & referencia a la definicion asociada  a la entrada, nos permite modificar la definición
@post  Si s no esta en el diccionario, el size() sera incrementado en 1.
*/
defM & diccionario::operator[](const nombreM & s) {
	int i=0;	
	static defM aux;

	for(i = 0; i < dic.size() && dic[i].first.compare(s) != 0;i++);

	if(i==dic.size()){
		entrada aux2(s,aux);
		dic.push_back(aux2);
	}
	else{
		aux = dic[i].second;
	}
	return aux;
}
	

/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante aa la definición de la misma, si no la encuentra da un mensaje de error.
 
@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
const defM & diccionario::operator[](const nombreM & s) const{
	int i=0;	
	static defM aux;

	for(i = 0; i < dic.size() && dic[i].first.compare(s) != 0;i++);

	if(i==dic.size()){
		cout<<"error"<<endl;
	}
	else{
		aux = dic[i].second;
	}
	return aux;
}


/** @brief Inserta una entrada en el diccionario
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un meteorito con igual nombre en el diccionario. False en caso contrario
@post 	 Si e no esta en el diccionario, el size() sera incrementado en 1.
*/
bool diccionario::insert(const diccionario::entrada & e){
	bool flag=true;
	int i;
	for(i = 0; i < dic.size() && (dic[i].first.compare(e.first)!=0);i++);

	if(i==dic.size()){
		flag=false;
		dic.push_back(e);
	}
	else{
		flag=true;
	}
	return flag;
}

/** @brief operador de asignación
@param[in] org diccionario  a copiar.
 Crea un diccionario duplicado exacto de org.
*/
diccionario & diccionario::operator=( const diccionario & org){
	this->dic.clear();
	this->dic = org.dic;
	
	return *this;
}

/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/

diccionario::size_type diccionario::size() const {
	return (size_type)this->dic.size();
}

/** @brief vacia
   Chequea si el diccionario esta vacio (size()==0)
*/
bool diccionario::empty() const{
	return this->dic.empty();
}
   
	 
  /** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/
bool diccionario::cheq_rep( ) const {
	bool flag=false;
	int k,i,j;
	unsigned int tama= this->dic.size();	
	for(k=0; k < tama  && this->dic[k].first != "";k++);

	for(i=0; i < tama;i++)
		for(j=0; j < tama && this->dic[i].first != this->dic[j].first;j++);

	flag= (k==tama && i==tama && j==tama  && tama == this->size());
	return flag;
}
  
/** @brief imprime todas las entradas del diccionario 
@post  No se modifica el diccionario.
@todo implementar esta funcion
	*/
ostream &  operator << ( ostream & sal, const diccionario & D){
	for(int i=0;i<D.dic.size();i++)
		sal <<"Clave:"<< D.dic[i].first <<"Valor:" << D.dic[i].second <<endl;
	return sal;
}

#endif

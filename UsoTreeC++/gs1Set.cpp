#include "gs1Set.h"
/*
*
Emilio Chica Jiménez y Julián Torices Hernández
*
*/

using namespace std;


gs1Set ::gs1Set (){
  pair<string,int> aux("-",0);
  arbol = tree<pair<string,int> >(aux);
  tama = 0;
}

gs1Set ::gs1Set (const gs1Set  & x){
  arbol = x.arbol;
  tama = x.tama;
}

gs1Set & operator= (const gs1Set &org){
	arbol = org.arbol;
	tama = org.tama;
}

bool gs1Set ::insert(const string& s){
tree<pair<string,int> >::node n, aux;
string::const_iterator it;
pair<string,int> par;
bool enc;

  n = arbol.root();
  for (it = s.begin(); it!=s.end(); ++it) { // Para cada caracter del string
   aux = n.left(); // aux es el primer hijo
   enc = false;
   while ( (!aux.null()) && !enc ){ // buscamos el caracter dentro de la lista de hijos
     if ( (*aux).first[0] == (*it) ) {
       enc = true;
       n = aux; // si lo encuentra, desciende al siguiente nivel
     } else aux = aux.next_sibling();
   }
   if (aux.null()) { // Si no lo ha encontrado, lo inserta
     par.first = string(1,*it);
     par.second = 0;
     n= arbol.insert_left(n,par); // y desciende al siguiente nivel
   }
  }
}


void gs1Set ::print( ) const {
  tree<pair<string,int> >::const_preorderiterator it;
  tree<pair<string,int> >::const_leveliterator itn;
   cout << "preorden " << endl;

  for (it= arbol.beginPreorder(); it!= arbol.endPreorder();++it)
    cout << (*it).first << endl;

   cout << "Nivel " << endl;
  for (itn= arbol.beginlevel(); itn!= arbol.endlevel();++itn)
    cout << (*itn).first << endl;

}


void gs1Set::reading_gs1Set ( ) {

  tree<pair<string,int> >::node n, h;
  queue< tree<pair<string,int> >::node > Q;

  pair<string,int> aux;

  n = arbol.root();
  Q.push(n);
  while (!Q.empty() ){
    n = Q.front();
    Q.pop();
    cout << "Hijo Izq de " << (*n).first << "/ si no tiene hijos "<< endl;
    cin >> aux.first;
	if(aux.first[0] == '(')
		aux.second == - 1;

    if (aux.first != "/") {
		while()
      h= arbol.insert_left(n,aux);
      Q.push(h);
      cout << "Hermano Dch de " << (*h).first<< "/ si no tiene hermano "<< endl;
      cin >> aux.first;
      while (aux.first != "/") {
		h= arbol.insert_right_sibling(h,aux);
		Q.push(h);
		cout << "Hermano Dch de " << (*h).first<< "/ si no tiene hermano"<< endl;
		cin >> aux.first;
      }
    }

  }
}
//BUSCAR
gs1Set::const_iterator gs1Set::find( const string & cad)
{
	string aux;
	bool fin = true;
    tree<pair<string,int> >::node n = (*this).arbol.root().left();
	const_iterator itAux;
	int index = 0;

	do
	{
	    if(cad[index] != '(')
        {
            while((((*n).first)!= cads[index])&&(!n.next_sibling().null()))
                n = n.next_sibling();


            if((*n).first)== cad[index])
            {
                n = n.left();
                index++;
            }
            if((((n.next_sibling().null())&& ((*n).first)!= cad[index]))||(index == cad.size() - 1))
                fin = false;
            
        }
		else if (cad[indice] == '(')
        {
            while(cad[index] != ')')
                aux.push_back(cad[index++]);
            
            aux.push_back(cad[index++]);

             while((!n.next_sibling().null())&&(((*n).first)!= aux))
                n = n.next_sibling();


            if((*n).first)== aux)
            {
                n = n.left();
                index++;
            }
            if(((((*n).first)!= aux)&&(n.next_sibling().null()))||(index == cad.size() - 1))
                fin = false;
            
            aux.clear();

        }
	}while(fin);

	if((((*n).second > 1)||(n.left().null()))&&(index == cad.size() - 1))
    {
        itAux.act = n;
        itAux.ptr = this;
    }

    return itAux;

}
//LISTA DE CODIGOS
list<string> gs1Set::codesWithPrefix(const string & cad)
{
	string aux;
	bool fin = true;
	int indice = 0;
	list<string> res;
	tree<pair<string, int> >::node n = (*this).arbol.root().left();
	tree<pair<string, int> >::node max;
	const_iterator itAux;
	bool maxpre = true;
	

	do
	{
		if (cad[indice] != '(')
		{
			while ((((*n).first) != cad[indice]) && (!n.next_sibling().null()))
				n = n.next_sibling();

			if ((*n).first) == cad[indice])
			{
				n = n.left();
				indice++;
			}
			if (((((*n).first) != cad[indice]) && (n.next_sibling().null())) || (indice == cad.size() - 1))
				fin = false;
		}
		else if (cad[indice] == '(')
		{
			while (cad[indice] != ')')
				aux.push_back(cad[indice++]);
	
			aux.push_back(cad[indice++]);

			while ((((*n).first) != aux) && (!n.next_sibling().null()))
				n = n.next_sibling();
			if ((*n).first) == aux)
			{
				n = n.left();
				indice++;
			}
			if (((((*n).first) != aux) && (n.next_sibling().null())) || (indice == cad.size() - 1))
				fin = false;

			aux.clear();

		}
	} while (fin);

	if ((indice == cad.size() - 1) && (!n.null()))
	{
		max = n;

		do
		{
			if (n.left().null())
			{
				while ((n.next_sibling().null()) && (max != n))
					n = n.parent();

				if (max == n)
					maxpre = false;

				n = n.next_sibling();

				while ((!n.null()) && (!n.left().null()) && ((*n).second < 2))
					n = n.left();

			}
			else
			while ((!n.left().null()) && ((*n).second < 2))
				n = n.left();

			itAux.act = n;
			itAux.ptr = this;

			res.push_back(*itAux);
		} while (maxpre);

	}

	return res;

}
//BORRAR
bool gs1Set::erase(const string &s){
	tree<pair<string, int> >::node n;
	if ((*this).arbol.find(s) != n)
	{
		(*(*this).arbol.find(s)) = pair<string, int> aux("-", 0);
		return true;
	}
	else
		return false;
}
//TEST VACIO
bool gs1Set::empty() const{

	return (*this).empty();
}
//TAMAÑO
size_type gs1Set::size() const{
	return (*this).size();
}
////////////ITERADORES////////////////
gs1Set::const_iterator gs1Set::begin() const
{
	tree<pair<string,int> >::node n = (*this).arbol.root();
	const_iterator itAux;

	while((!n.left().null())&&((*n).second < 2))
		n = n.left();

	itAux.ptr = this;
	itAux.act = n;
	

	return itAux;

}

 gs1Set::const_iterator gs1Set::end() const
{
	const_iterator itAux;
	return itAux;

}

 gs1Set::cont_iterator::const_iterator( const const_iterator & it)
 {
	 (*this).ptr = it.ptr;
	 (*this).act = it.act;
	
 }

 const_iterator & gs1Set::const_iterator::operator=(const const_iterator & it)
 {
	 (*this).ptr = it.prt;
	 (*this).act = it.act;
	 

	 return *this;
 }

 const_iterator gs1Set::const_iterator::operator++(int)
 {
	 const_iterator res(*this);

	 tree<pair<string, int> >::node n = (*this).act;

	 if (n.left().null())
	 {
		 while ((n.next_sibling().null()) && ((*ptr).arbol.root() != n))
			 n = n.parent();


		 n = n.next_sibling();

		 while ((!n.null()) && (!n.left().null()) && ((*n).second < 2))
			 n = n.left();

	 }
	 else
	 while ((!n.left().null()) && ((*n).second < 2))
		 n = n.left();

	 (*this).act = n;

	 n = tree<pair<string, int> >::node;

	 return res;

 }

 const_iterator & gs1Set::const_iterator::operator++()
 {
	tree<pair<string,int> >::node n = (*this).act;

    if(n.left().null())
    {
        while((n.next_sibling().null())&&((*ptr).arbol.root() != n))
            n = n.parent();
        
        n = n.next_sibling();

        while((!n.null())&&(!n.left().null())&&((*n).second < 2))
            n = n.left();
        
    }
    else
        while((!n.left().null())&&((*n).second < 2))
            n = n.left();
        

        (*this).act = n;

		n = tree<pair<string, int> >::node;


	return *this;

 }



 gs1Set::const_iterator gs1Set::const_iterator::upper_IA()
 {

	tree<pair<string,int> >::node n = (*this).act;
	const_iterator itAux;

	while(((*n).second != -1)&&(!n.null()))
		n = n.parent();
	
	itAux.ptr = (*this).ptr;
	itAux.act = n;
	

	return (*itAux);



 }

 string  gs1Set::const_iterator::operator*()
 {
	 tree<pair<string, int> >::node n = (*this).act;
	 string aux;
	 stack<string> pila;

	 while (!n.null())
	 {
		 pila.push((*n).first);
		 n = n.parent();
	 }

	 while (!pila.empty())
	 {
		 aux.push_back(pila.top());
		 pila.pop();
	 }

	 return aux;
 }

 bool gs1Set::const_iterator::operator==(const const_iterator & it) const
 {
	return (*this).act == it.act;
 }

 bool gs1Set::const_iterator::operator!=(const const_iterator & it) const
 {
	return (*this).act != it.act;
 }

#ifndef __POLINOMIO_H
#define __POLINOMIO_H

#include "vectorD.h"
#include <iostream>

using namespace std;

template <typename T>
class polinomio{
	private:
		vectorD<T> vectD;
	public:
		polinomio();
		polinomio(const polinomio &p);
		polinomio( int numcomp, const  T  & t = T() );
		int grado();
		T coeficiente(int i);
		void asignar_coeficiente(int i, const T &x);
		void operator=(const polinomio &p);
		polinomio operator+(const polinomio &p);
		polinomio operator-(const polinomio &p);
		class iterator;
		iterator begin();
		iterator end();

		class iterator{
			  public:
			    friend class polinomio;			    		    
			    iterator() ;
			    iterator(const iterator & d);
			    const  T  & operator *(  ) ;
			    iterator & operator++( );
			    iterator operator++(int ) ; 
			    bool operator == (const iterator & d) ;
			    bool operator != (const iterator & d);
			    iterator & operator=(const iterator & d);
			  private:
			    typename vectorD<T>::iterator it; //iterador a la representacion
			       
		};
	
};

#include "polinomio.hxx"
#endif

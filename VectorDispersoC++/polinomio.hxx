
template <typename T>
polinomio<T>::polinomio(){
	
}
template <typename T>
polinomio<T>::polinomio(const polinomio &p){
	typename vectorD<T>::iterator it= p.vectD.cbegin();
	vectD.clear();
	for(;it!=p.vectD.cend();++it){
		vectD.push_back(*it);
	}
	
}
template <typename  T >
polinomio<T>::polinomio( int numcomp, const T  & t ){
	vectorD<T> k(numcomp,t);
	//vectD(numcomp,t);//HACER EL CONST_ITERATOR DE VECTORD PARA SOLUCIONAR EL PROBLEMA
	vectD = k;
	//vectD(numcomp,t);
}
template <typename T>
int polinomio<T>::grado(){
	if(vectD[vectD.size()-1]!=0)
		return vectD.size()-1;
	else
	{
		int cont= vectD.size()-1;
		typename vectorD<T>::iterator it;
		for (it = --vectD.end(); it != vectD.begin(); --it, cont--){
			if(*it!=0)
				return cont;
		}
	}
	return 0;
}
template <typename T>
T polinomio<T>::coeficiente(int i){
	return vectD[i];
}
template <typename T>
void polinomio<T>::asignar_coeficiente(int i, const T &x){
	vectD.assign(i,x);
}
template <typename T>
void polinomio<T>::operator=(const polinomio<T> &p){
	typename vectorD<T>::iterator it= p.vectD.cbegin();
	vectD.clear();
	for(;it!=p.vectD.cend();++it){
		vectD.push_back(*it);
	}
}
template <typename T>
polinomio<T> polinomio<T>::operator+(const polinomio<T> &p){
	polinomio<T> aux;

	typename vectorD<T>::const_iterator it1 = p.vectD.cbegin();
	typename vectorD<T>::iterator it2= vectD.begin();

	
	if (p.vectD.size() > vectD.size()){
		for (; it1 != p.vectD.cend(); ++it2){
			if (it2 != vectD.end()){
				if (*it1 != 0)
					aux.vectD.push_back((*it2) + *it1);
				++it1;
			}
		}
	}
	else{
		for (; it2 != vectD.end(); ++it1){
			if (it1 != p.vectD.cend()){
				if (*it2 != 0)
					aux.vectD.push_back((*it2) + *it1);
				it2++;
			}
		}
	}

	return aux;
}
template <typename T>
polinomio<T> polinomio<T>::operator-(const polinomio<T> &p){
	polinomio<T> aux;

	typename vectorD<T>::const_iterator it1 = p.vectD.cbegin();
	typename vectorD<T>::iterator it2 = vectD.begin();


	if (p.vectD.size() > vectD.size()){
		for (; it1 != p.vectD.cend(); ++it2){
			if (it2 != vectD.end()){
				if (*it1 != 0)
					aux.vectD.push_back((*it2) - *it1);
				++it1;
			}
		}
	}
	else{
		for (; it2 != vectD.end(); ++it1){
			if (it1 != p.vectD.cend()){
				if (*it2 != 0)
					aux.vectD.push_back((*it2) - *it1);
				it2++;
			}
		}
	}

	return aux;

}
template <typename T>
typename polinomio<T>::iterator polinomio<T>::begin(){
	typename polinomio<T>::iterator itPoli;
	itPoli.it = vectD.begin();
	return itPoli;
}
template <typename T>
typename polinomio<T>::iterator polinomio<T>::end(){
	typename polinomio<T>::iterator itPoli;
	itPoli.it = vectD.end();
	return itPoli;
}
template <typename T>			    
polinomio<T>::iterator::iterator() {
}
template <typename T>
polinomio<T>::iterator::iterator(const iterator & d){
	it =d.it;
}
template <typename T>
const  T  & polinomio<T>::iterator::operator *(  ){
	return *it;
}
template <typename T>
typename polinomio<T>::iterator & polinomio<T>::iterator::operator++( ){
	++it; 
	return *this;

}
template <typename T>
typename polinomio<T>::iterator polinomio<T>::iterator::operator++(int ){
	iterator tmp(*this); 
	++it; 
	return tmp;
}
template <typename T>
bool polinomio<T>::iterator::operator == (const iterator & d){
	return it == d.it;
}
template <typename T>
bool polinomio<T>::iterator::operator != (const iterator & d){
	return it != d.it;
}
template <typename T>
typename polinomio<T>::iterator & polinomio<T>::iterator::operator=(const iterator & d){
	it = d.it;
	return *this;
}


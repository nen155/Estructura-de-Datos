template <typename  T >
vectorD<T>::vectorD( const  T  & t ){
	v_nulo=t;
	n_ele=0;
}
// constructor por defecto. t hace referencia al valor por defecto del vector
template <typename  T >      	
vectorD<T>::vectorD(  const vectorD< T > & b){
	n_ele = b.n_ele;
	v_nulo = b.v_nulo;
	vd(b.vd.begin(),b.vd.end());
}    	
/** constructor primitivo que hace una copia del vector disperso b. */
template <typename  T >
vectorD<T>::vectorD( int numcomp, const  T  & t ){
	if(numcomp>0){
		n_ele=numcomp;
		v_nulo=t;
	}
}
/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp debe ser mayor que cero.
t hace referencia al valor por defecto
 */


////////////// destructor ////////////  	
template <typename T>
vectorD<T>::~vectorD(){
	n_ele=0;
	
}


/////////// Consultores ////////////
template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{
	return n_ele;
}
// Devuelve el tamaño del vectorD
template <typename  T >
T  vectorD<T>::default_value( ) const{
	return v_nulo;
}
template <typename T>
bool vectorD<T>::empty(){
	return (vd.size()==0);
}
// el vectorD esta vacio

////////  MODIFICADORES //////////////////////
template <typename  T >
void vectorD<T>::assign(int p, const  T  & t){
	bool encontrado=false;
	bool insertado=false;	
	typename list<pair<int, T> >::iterator it;
	if (vd.size() > 0){
		for (it = vd.begin(); it != vd.end(); ++it){
			if ((*it).first == p)
			{
				(*it).second = t;
				encontrado = true;
			}
		}
		if (!encontrado && n_ele > vd.size()){
			for (it = --vd.end(); it != vd.begin() && !insertado; --it){
					if ((*it).first < p){
						vd.insert(++it, pair<int, T>(p, t));
						insertado = true;
					}
			}
			if (it == vd.begin())
			{
				if ((*it).first < p){
					vd.insert(++it, pair<int, T>(p, t));
				}else
				{
					vd.insert(it, pair<int, T>(p, t));
				}
				insertado = true;
			}

		}
	}
	else if(n_ele>0){
		vd.push_back(pair<int, T>(p, t));
	}
	
}
// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector
template <typename  T >
void vectorD<T>::push_back( const  T  & t){
	n_ele++;
	vd.push_back(pair<int,T>(n_ele-1,t));

}
// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio
template <typename T>
void vectorD<T>::pop_back(){
	n_ele--;
	typename list<pair<int, T> >::iterator it= --vd.end();
	if((*it).first == n_ele-1)
		vd.pop_back();

		
}
// elimina un elemento del vectorD. Disminuye en 1 el tamanio
template <typename T>
void vectorD<T>::clear(){
	n_ele=0;
	vd.clear();
} 
// elimina todos los elementos del vectorD. Tamanio es 0
template <typename T>
void vectorD<T>::resize(int s){
	if(s>n_ele){
		n_ele = s;
	}else if(s<n_ele)
	{
		typename list<pair<int, T> >::iterator it= --vd.end();
		for(int i=0;i<s;i++){
			
			if((*it).first == n_ele-1){
				vd.pop_back();
				--it;
			}
		}
		n_ele-=s;
	}
		
}
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 

/////////////// operadores ///////////////////

template <typename T>
vectorD<T> & vectorD<T>::operator= (const vectorD<T> & x){
	n_ele = x.n_ele;
	list< pair<int, T > > aux(x.vd.begin(), x.vd.end());
	vd = aux;
	v_nulo = x.v_nulo;
	return *this;
}
// operador de asignacion

template <typename  T >
const  T  & vectorD<T>::operator[](int c) const{
	if(c>=0 && c<n_ele){
		typename list<pair<int, T> >::const_iterator it;
		for(it= vd.begin();it!=vd.end();++it){
			if((*it).first == c){
				return (*it).second;
			}
		}
		return v_nulo;
	}
	return v_nulo;
}
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/
template <typename  T >
const  T  & vectorD<T>::at(int c) const{
	if(c>=0 && c<n_ele){
		typename list<pair<int, T> >::iterator it;
		for(it= vd.begin();it!=vd.end();++it){
			if((*it).first == c){
				return (*it).second;
			}
		}
		return v_nulo;
	}
	return v_nulo;
}
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */
template <typename T>
bool vectorD<T>::operator==( const vectorD<T> & x){
	if(n_ele != x.n_ele)
		return false;
	if(vd.size() != x.vd.size())
		return false;
	typename list<pair<int, T> >::iterator it;
	typename list<pair<int, T> >::iterator it2;
	for(it= vd.begin(),it2 = x.vd.begin();it!=vd.end() && (*it2)==(*it);++it,++it2);
	if(it!=vd.end())
		return false;
	return true;
		
}
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */
template <typename T>
bool vectorD<T>::operator!=( const vectorD<T> & x){
	if(n_ele != x.n_ele)
		return true;
	if(vd.size() != x.vd.size())
		return true;
	typename list<pair<int, T> >::iterator it;
	typename list<pair<int, T> >::iterator it2;
	for(it= vd.begin(),it2 = x.vd.begin();it!=vd.end() && (*it2)==(*it);++it,++it2);
	if(it!=vd.end())
		return true;
	return false;
}
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */
////////////////////////////////////////


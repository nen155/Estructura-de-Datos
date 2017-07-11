template <typename T>
vectorD::vectorD( const  T  & t=  T () )// constructor por defecto. t hace referencia al valor por defecto del vector
{
	v_nulo = t;
}

template <typename T>
vectorD::vectorD(  const vectorD< T > & b)/** constructor primitivo que hace una copia del vector disperso b. */
{
	n_ele = b.n_ele;
	v_nulo = b.v_nulo;
	vd (b.vd.begin(), b.vd.end());
}

template <typename T>
vectorD::vectorD( int numcomp, const  T  & t =  T () )/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp debe ser mayor que cero.
t hace referencia al valor por defecto
 */
{
	if(numcomp > 0)
	{
		n_ele = numcomp;
		v_nulo = t;
	}
}

////////////// destructor ////////////  	
vectorD::~vectorD()
{
	n_ele =0;
}

/////////// Consultores ////////////
vectorD::size_type size() const// Devuelve el tamaño del vectorD
{
	return n_ele;
}

template <typename T>
T  vectorD::default_value( ) const
{
	return v_nulo;
}

bool vectorD::empty()// el vectorD esta vacio
{
	return (vd.size() == 0);
}

////////  MODIFICADORES //////////////////////
template <typename T>
void vectorD::assign(int p, const  T  & t)// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector
{
	bool encontrado =false;
	bool insertado = false;
	map<int, T>::iterator it;
	for (it = vd.begin(); it != vd.end(); it++)
		if(*it.key == p )
		{
			encontrado = true;
			*it.value = t;
		}
	
	if( !encontrado && n_ele > vd.size() )
	{
		for(it = vd.end()--; it != vd.begin() && !insertado; it--)
		{
			if(*it.key < p )
			{
				encontrado = true;
				vd.insert(++it,pair<p,t>);
			}
		}
		if (it == vd.begin())
			vd.insert(it,pair<p,t>);
	}	
		
}

template <typename T>
void vectorD::push_back( const  T  & t)// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio
{
	n_ele ++;
	vd.insert(pair<n_ele-1,t>);
}


void vectorD::pop_back(  )// elimina un elemento del vectorD. Disminuye en 1 el tamanio
{
	map<int, T>::iterator it = -- vd.end();
	if(n_ele-1 == *it.key)
		vd.erase(it);
	n_ele --;
}

void vectorD::clear()// elimina todos los elementos del vectorD. Tamanio es 0
{
	n_ele =0;
	vd.clear();
}

void vectorD::resize(int s)// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 
{
	if(s > n_ele)
		n_ele = s;
		else if(s < n_ele)
			{
				map<int, T>::iterator it = -- vd.end();
				for(int i =0 ; i<s ; i++)
				{
					if(n_ele-1 == *it.key)
					{
						vd.erase(it);
						it --;
					}
					n_ele--;	
				}
				
			}
}

/////////////// operadores ///////////////////


vectorD & vectorD::operator= (const vectorD & x)// operador de asignacion
{

	n_ele= x.n_ele;
	vd(x.vd.begin(), x.vd.end());
	v_nulo= x.v_nulo;
	return *this;
}

template <typename T>
const  T  & vectorD::operator[](int c) const /** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/
{
	if(c >= 0 && c < n_ele)
	{
		map<int, T>::iterator it;
		for(it = vd.begin() ; it != vd.end() ; it++)
			if( *it.key == c  )
				return *it.value;
		
		return v_nulo;
	}
	return NULL;
}

template <typename T>
const  T  & vectorD::at(int c) const /** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */
{

	if(c >= 0 && c < n_ele)
	{
	map<int, T>::iterator it;
		for(it = vd.begin() ; it != vd.end() ; it++)
			if( *it.key == c  )
				return *it.value;
		
		return v_nulo;
	}
	return NULL;
}

bool vectorD::operator==( const vectorD & x)/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */
{
	if( n_ele == x.n_ele )
	{
		if( vd.size() == x.vd.size())
		{
			map<int, T>::iterator it, it2;
			for(it = vd.begin(), it2= x.vd.begin() ; it != vd.end() && (*it)==(*it2) ; it++, it2++ );
			if(it == vd.end())
				return true;
		}
	}
	return false;
}

bool vectorD::operator!=( const vectorD & x)
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */

{
	if( n_ele == x.n_ele )
	{
		if( vd.size() == x.vd.size())
		{
			map<int, T>::iterator it, it2;
			for(it = vd.begin(), it2= x.vd.begin() ; it != vd.end() && (*it)==(*it2) ; it++, it2++ );
			if(it == vd.end())
				return false;
		}
	}
	return true;
}

////////////////////////////////////////


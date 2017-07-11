#include "polinomio.h"
#include <iostream>

using namespace std;

int main(){
	polinomio<int> p(11,0);
	p.asignar_coeficiente(10, 9);
	p.asignar_coeficiente(1, 4);
	p.asignar_coeficiente(2, 5);
	polinomio<int> p2(1, 0);
	p2.asignar_coeficiente(1, 9);
	p2.asignar_coeficiente(1, 4);
	p2.asignar_coeficiente(2, 5);
	polinomio<int> p3;
	p + p2;
	polinomio<int>::iterator it;
	cout<<p.coeficiente(6)<<endl;
	cout<<p.grado()<<endl;

	for(it=p.begin();it!=p.end();++it)
		cout<<*it<<endl;
	system("pause");
}

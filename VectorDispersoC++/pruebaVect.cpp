#include "vectorD.h"
#include <iostream>

using namespace std;

int main(){
	vectorD<int> vec(10,0);
	vec.push_back(2);
	//vec.push_back(3);
	vec.assign(2,3);
	vectorD<int>::iterator it;
	for(it=vec.begin();it!=vec.end();++it)
		cout<<*it<<endl;
	//vec.pop_back();
	//for(it=vec.begin();it!=vec.end();++it)
	//	cout<<*it<<endl;
	system("pause");
}

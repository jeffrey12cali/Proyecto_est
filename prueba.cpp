#include <iostream>
#include <vector>
#include "grafo.h"

using namespace std;

int main(){
	int arr[] = {1,2,3,4};
	Grafo<int> g(arr, 4);
	g.AgregarArista(1,2);
	vector<int> pond(g.ObtenerPonderaciones(1));
	for (int i = 0; i < pond.size(); i++)
		cout << pond[i] << " ";
	cout << endl;
	g.AgregarArista(3,4,8);
	g.ModificarArista(1,2,2);
	vector<int> pond2(g.ObtenerPonderaciones(1));
	for (int i = 0; i < pond2.size(); i++)
		cout << pond2[i] << " ";
	cout << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include "ClaseGrafo1.h"

using namespace std;

int main(){
	int arr[] = {1,2,3,4};
	Grafo<int> g(arr, 4);
	g.AgregarArista(1,2);
	vector<int> pond(g.ObtenerPonderaciones(1));
	g.AgregarArista(3,4,8);
	g.ModificarArista(1,2,2);
	vector<int> pond2(g.ObtenerPonderaciones(1));
	cout << g.ObtenerNumVertices() << endl;
	g.EliminarNodo(2);
	cout << g.ObtenerNumVertices() << endl;
	return 0;
}
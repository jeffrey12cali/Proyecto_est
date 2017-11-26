#include "ClaseGrafo.h"
#include "ClaseGrafoDireccion.h"
#include "ClaseOperacionesGrafo.h"
#include <vector>
#include <iostream>
using namespace std;
int main(){
	int i, j;
	int myints[] = {1,2,3,4};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	GrafoDireccion<int> g(fifth);
	g.AgregarArista(1,2,1);
	g.AgregarArista(1,3,2);
	g.AgregarArista(2,4,4);
	g.AgregarArista(3,4,5);
	OperacionesGrafo<int> op;
	op.Dijkstra(g, 1);
/*	int myints[] = {1,2,3,4,5,6};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	Grafo<int> g(fifth);
	g.AgregarArista(1,2);
	g.AgregarArista(1,5);
	g.AgregarArista(5,2);
	g.AgregarArista(5,4);
	g.AgregarArista(2,3);
	g.AgregarArista(3,4);
	g.AgregarArista(4,6);
	cout << g.ObtenerNumAristas() << endl;
	OperacionesGrafo<int> op;
	vector<int> path(op.BreadthFirstSearch(g, 4));
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";*/
/*	g.AgregarArista(3,2);
	g.AgregarArista(4,2);
	g.EliminarArista(1,2);
	g.AgregarNodo(5);
	vector<int> pond(g.ObtenerPonderaciones(1));
	for (int i = 0; i < pond.size(); i++)
		cout << pond[i] << " ";
	cout << endl;
	vector<int> pond1(g.ObtenerListaAdy(1));
	for (int l=0; l< pond1.size();l++)
		cout<<pond1[l]<<" ";
		cout<<endl;
	cout<<g.ObtenerNumVertices()<<endl;
	cout<<g.ObtenerNumAristas()<<endl;*/
	return 0;

	
}

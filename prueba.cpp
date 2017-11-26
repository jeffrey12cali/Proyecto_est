#include "ClaseGrafo.h"
#include "ClaseGrafoDireccion.h"
#include "ClaseOperacionesGrafo.h"
#include <vector>
#include <iostream>
using namespace std;
int main(){
/*	int i, j;
	int myints[] = {1,2,3,4};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	GrafoDireccion<int> g(fifth);
	g.AgregarArista(1,2,1);
	g.AgregarArista(1,3,2);
	g.AgregarArista(2,4,4);
	g.AgregarArista(3,4,5);
	OperacionesGrafo<int> op;
	op.Dijkstra(g, 1);*/
	char myints[] = {'A','B','C','D','E'};
	vector<char> fifth (myints, myints + sizeof(myints) / sizeof(char) );
	GrafoDireccion<char> g(fifth);
	g.AgregarArista('A','B',5);
	g.AgregarArista('B','C',3);
	g.AgregarArista('B','D',1);
	g.AgregarArista('C','A',3);
	g.AgregarArista('C','E',4);
	g.AgregarArista('E','D',2);
	g.AgregarArista('D','E',4);
	cout << g.ObtenerNumAristas() << endl;
	OperacionesGrafo<char> op;
	op.Dijkstra(g,'A');
	/*vector<char> path(op.DepthFirstSearch(g, 'A'));
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

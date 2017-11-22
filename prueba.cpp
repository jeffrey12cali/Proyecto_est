#include "ClaseGrafo.cpp"
//#include <vector>
//#include <iostream>
using namespace std;
int main(){
	int myints[] = {1,2,3,4};
	vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
	
	Grafo<int> g(fifth);
	

	g.AgregarArista(1,2);
	g.AgregarArista(3,2);
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
	cout<<g.ObtenerNumAristas()<<endl;
	//g.AgregarArista(3,4,8);
	//g.ModificarArista(1,2,2);
	//vector<int> pond2(g.ObtenerPonderaciones(1));
	//for (int i = 0; i < pond2.size(); i++)
	//	cout << pond2[i] << " ";
	//cout << endl;
	
	return 0;

	
}

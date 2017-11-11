#ifndef __GRAFO_H
#define __GRAFO_H

#include <vector>

template <class T>
class Nodo{
public:
	T dato;
	Nodo(T elem);
	~Nodo();
};

template <class T>
class Grafo{
private:
	vector<Nodo> V; //Vertices
	vector<vector<Nodo>> E; //Aristas
	vector<int> P; //Ponderaciones
	int nAri;
	int nVert;
public:
	Grafo(); //CrearGrafoVacio
	Grafo(int nV); //CrearGrafoNoVacio 
	void AgregarArista(Nodo n1, Nodo n2);
	void AgregarNodo(Nodo n1);
	void ModificarArista(Nodo n1, Nodo n2, int valor);
	void EliminarArista(Nodo n1, Nodo n2);
	void EliminarNodo(Nodo n1);
	vector<Nodo> ObtenerListaAdy(Nodo n1);
	int ObtenerNumVertices();
	int ObtenerNumAristas();
	~Grafo();
};
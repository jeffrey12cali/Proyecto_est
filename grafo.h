/*
 *Autores : Jeffrey Garcia, Mauricio Cortés
 *fecha de creacion : 9 de noviembre del 2017
 *fecha última modificacion : 22 de noviembre del 2017
 *vesion : 0.3
 *Archivo: grafo.h
*/

#ifndef __GRAFO_H
#define __GRAFO_H

#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Nodo{
public:
	T dato;
	Nodo();
	Nodo(T elem);
	~Nodo();
};

template<class T>
Nodo<T>::Nodo(){
}

template<class T>
Nodo<T>::Nodo(T elem){
	dato = elem;
}

template<class T>
Nodo<T>::~Nodo(){
}

template <class T>
class Grafo{
protected:
	vector<T> V; //Vertices
	vector<vector<T>> E; //Aristas
	vector<vector<int>> P; //Ponderaciones
	int nAri;
	int nVert;
public:
	Grafo(); //CrearGrafoVacio
	Grafo(T* arr, int n); //CrearGrafoNoVacio
	void AgregarArista(T dato1, T dato2);
	void AgregarArista(T dato1, T dato2, int valor);
	void AgregarNodo(Nodo<T> n1);
	void ModificarArista(T n1, T n2, int valor);
	void EliminarArista(Nodo<T> n1, Nodo<T> n2);
	void EliminarNodo(Nodo<T> n1);
	vector<Nodo<T>> ObtenerListaAdy(Nodo<T> n1);
	int ObtenerNumVertices();
	int ObtenerNumAristas();
	vector<int> ObtenerPonderaciones(T n1);
	~Grafo();
};

template <class T>
Grafo<T>::Grafo(){
	nVert = 0;
	nAri = 0;
}

template <class T>
Grafo<T>::Grafo(T* arr, int n){
	nVert = 0;
	nAri = 0;
	int k = 0;
	vector<int> vec;
	while (n != 0){
		V.push_back(arr[k++]);
		E.push_back(vec);
		P.push_back(vec);
		nVert++;
		n--;
	}
}

template <class T>
void Grafo<T>::AgregarArista(T dato1, T dato2){
	int i = 0, pos1 = 1, pos2 = 1;
	for (i = 0; i < V.size() && (pos1 != 0 || pos2 != 0); i++){
		if (V[i] == dato1){
			E[i].push_back(dato2);
			P[i].push_back(0);
			pos1 = 0;
		}
		else if (V[i] == dato2){
			E[i].push_back(dato1);
			P[i].push_back(0);
			pos2 = 0;
		}
	}
	if (pos1 == 0 && pos2 == 0)
		nAri += 1;
}

template <class T>
void Grafo<T>::AgregarArista(T dato1, T dato2, int valor){
	int i = 0, ver1 = 1, ver2 = 1;
	for (i = 0; i < nVert && (ver1 != 0 || ver2 != 0); i++){
		if (V[i] == dato1){
			E[i].push_back(dato2);
			P[i].push_back(valor);
			ver1 = 0;
		}
		else if (V[i] == dato2){
			E[i].push_back(dato1);
			P[i].push_back(valor);
			ver2 = 0;
		}
	}
	if (ver1 == 0 && ver2 == 0)
		nAri += 1;
}

template <class T>
void Grafo<T>::ModificarArista(T n1, T n2, int valor){
	int i, pos1, pos2, pos1_2, pos2_2;
	pos1 = pos2 = pos2_2 = pos2_2 = -1;
	for (i = 0; i < nVert && (pos1 == -1 || pos2 == -1); i++){
		if (V[i] == n1)
			pos1 = i;
		else if (V[i] == n2)
			pos2 = i;
	}
	for (i = 0; i < E[pos1].size(); i++){
		if (E[pos1][i] == n2){
			pos1_2 = i;
			break;
		}
	}
	for (i = 0; i < E[pos2].size(); i++){
		if (E[pos2][i] == n1){
			pos2_2 = i;
			break;
		}
	}
	if (pos1 != -1 && pos2 != -1 && pos1_2 != -1 && pos2_2 !=-1){
		P[pos1][pos1_2] = valor;
		P[pos2][pos2_2] = valor;
	}
}

template <class T>
int Grafo<T>::ObtenerNumVertices(){
	return nVert;
}

template <class T>
int Grafo<T>::ObtenerNumAristas(){
	return nAri;
}

template <class T>
vector<int> Grafo<T>::ObtenerPonderaciones(T n1){
	int i, pos;
	for (i = 0; i < nVert; i++){
		if (V[i] == n1){
			pos = i;
			break;
		}
	}
	return P[pos];
}

template <class T>
Grafo<T>::~Grafo(){
}

#endif // __GRAFO_H


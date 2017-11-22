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
	vector<vector<T> > E; //Aristas
	vector<vector<int> > P; //Ponderaciones
	int nAri;
	int nVert;
public:
	Grafo(); //CrearGrafoVacio
	Grafo(vector<T>); //CrearGrafoNoVacio
	void AgregarArista(T dato1, T dato2);
	void AgregarArista(T dato1, T dato2, int valor);
	void AgregarNodo(T n1);
	void ModificarArista(T n1, T n2, int valor);
	void EliminarArista(T n1,T n2);
	void EliminarNodo(T n1);
	vector<T> ObtenerListaAdy(T n1);
	int ObtenerNumVertices();
	int ObtenerNumAristas();
	vector<int> ObtenerPonderaciones(T n1);
	~Grafo();
};


/******************************************************************************************************************/
template <class T>
Grafo<T>::Grafo(){
	nVert = 0;
	nAri = 0;
}

/******************************************************************************************************************/
template <class T>
Grafo<T>::Grafo(vector<T> nodos){
	nVert = 0;
	nAri = 0;
	int nV=0;
	vector<T> lisAdy;
	vector<int> lisPond;
	while (nV < nodos.size()){
	
		V.push_back(nodos[nV]);
		E.push_back(lisAdy);
		P.push_back(lisPond);
		nVert++;
		nV++;
	}
}

/******************************************************************************************************************/

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
/******************************************************************************************************************/
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
/********************************************************************************************************************/
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
/******************************************************************************************************************/
template <class T>
int Grafo<T>::ObtenerNumVertices(){
	return nVert;
}
/*******************************************************************************************************************/
template <class T>
int Grafo<T>::ObtenerNumAristas(){
	return nAri;
}
/********************************************************************************************************************/
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
/**********************************************************************************************************************/
template <class T>
void Grafo<T>::EliminarArista(T n1,T n2){
	int BusGrafoN1=0;
	int BusGrafoN2=0;
	bool nk= false;
	bool nk1= false;
	for(BusGrafoN1;BusGrafoN1 < V.size();BusGrafoN1++){
		if(V[BusGrafoN1]== n1){
			for(int i=0; i < E[BusGrafoN1].size();i++){
				if( E[BusGrafoN1][i]== n2){
					E[BusGrafoN1].erase(E[BusGrafoN1].begin()+i);
					P[BusGrafoN1].erase(P[BusGrafoN1].begin()+i);
					nk=true;
					
				}
			}
		}
		break;
	}
	
	for(BusGrafoN2;BusGrafoN2 < V.size();BusGrafoN2++){
		if(V[BusGrafoN2]== n2){
			
			for(int i=0; i < E[BusGrafoN2].size();i++){
				if( E[BusGrafoN2][i]== n1){
					
					E[BusGrafoN2].erase(E[BusGrafoN2].begin()+i);
					P[BusGrafoN2].erase(P[BusGrafoN2].begin()+i);
					nk1=true;
				}
		}
		break;
	}
	
}
	if(nk and nk1)
		nAri--;
}

/********************************************************************************************************************/
template <class T>
vector<T> Grafo<T>::ObtenerListaAdy(T n1){
	int k;
	for(int h=0; h < V.size();h++){
		if(V[h]== n1){
			k=h;
			break;
		}
	}
	return E[k];
}
/*********************************************************************************************************************/

template<class T>
void Grafo<T>::AgregarNodo(T n1){
	vector<T> nodoNew;
	vector<int> nodoNewPonds;
	V.push_back(n1);
	E.push_back(nodoNew);
	P.push_back(nodoNewPonds);
	nVert++;
}

/*********************************************************************************************************************/

template <class T>
Grafo<T>::~Grafo(){
}

#endif // __GRAFO_H

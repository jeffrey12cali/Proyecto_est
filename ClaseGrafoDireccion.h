/*
 *Autores : Jeffrey Garcia, Mauricio Cortés
 *fecha de creacion : 9 de noviembre del 2017
 *fecha última modificacion : 25 de noviembre del 2017
 *vesion : 1.0
 *Archivo: ClaseGrafoDireccion.h
*/

#ifndef __GRAFO_DIRECCION_H
#define __GRAFO_DIRECCION_H

#include <vector>

using namespace std;

template <class T>
class GrafoDireccion{
protected:
	vector<T> V; //Vertices
	vector<vector<T> > E; //Aristas
	vector<vector<int> > P; //Ponderaciones
	int nAri;
	int nVert;
public:
	/* Constructoras */
	GrafoDireccion(); //CrearGrafoDireccionVacio
	GrafoDireccion(vector<T>); //CrearGrafoDireccionNoVacio

	/* Modificadoras */
	void AgregarArista(T dato1, T dato2);
	void AgregarArista(T dato1, T dato2, int valor);
	void AgregarNodo(T n1);
	void ModificarArista(T n1, T n2, int valor);
	void EliminarArista(T n1,T n2);
	void EliminarNodo(T n1);

	/* Analizadoras */
	vector<T> ObtenerListaAdy(T n1);
	int ObtenerNumVertices();
	int ObtenerNumAristas();
	vector<T> ObtenerVertices();
	vector<int> ObtenerPonderaciones(T n1);

};
/******************************************************************************************************************/
template <class T>
GrafoDireccion<T>::GrafoDireccion(){
	nVert = 0;
	nAri = 0;
}
/******************************************************************************************************************/
template <class T>
GrafoDireccion<T>::GrafoDireccion(vector<T> nodos){
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
void GrafoDireccion<T>::AgregarArista(T dato1, T dato2){
	if (dato1 != dato2){
		int i = 0, ver1 = 1, ver2 = 1, pos1, pos2;
		for (i = 0; i < nVert && (ver1 != 0 || ver2 != 0); i++){
			if (V[i] == dato1){
				pos1 = i;
				ver1 = 0;
			}
			else if (V[i] == dato2){
				pos2 = i;
				ver2 = 0;
			}
		}
		if (ver1 == 0 && ver2 == 0){
			for (i = 0; i < E[pos1].size(); i++){
				if (E[pos1][i] == dato2)
					ver1 = 1;
			}
			if (ver1 == 0 && ver2 == 0){
				E[pos1].push_back(dato2);
				P[pos1].push_back(0);
				nAri += 1;
			}
		}
	}
}
/******************************************************************************************************************/
template <class T>
void GrafoDireccion<T>::AgregarArista(T dato1, T dato2, int valor){
	if (dato1 != dato2){
		int i = 0, ver1 = 1, ver2 = 1, pos1, pos2;
		for (i = 0; i < nVert && (ver1 != 0 || ver2 != 0); i++){
			if (V[i] == dato1){
				pos1 = i;
				ver1 = 0;
			}
			else if (V[i] == dato2){
				pos2 = i;
				ver2 = 0;
			}
		}
		if (ver1 == 0 && ver2 == 0){
			for (i = 0; i < E[pos1].size(); i++){
				if (E[pos1][i] == dato2)
					ver1 = 1;
			}
			if (ver1 == 0 && ver2 == 0){
				E[pos1].push_back(dato2);
				P[pos1].push_back(valor);
				nAri += 1;
			}
		}
	}
}
/*********************************************************************************************************************/
template<class T>
void GrafoDireccion<T>::AgregarNodo(T n1){
	vector<T> nodoNew;
	vector<int> nodoNewPonds;
	V.push_back(n1);
	E.push_back(nodoNew);
	P.push_back(nodoNewPonds);
	nVert++;
}
/********************************************************************************************************************/
template <class T>
void GrafoDireccion<T>::ModificarArista(T n1, T n2, int valor){
	int i, pos1, pos2, pos1_2, pos2_2;
	pos1 = pos2 = pos2_2 = pos2_2 = -1;
	for (i = 0; i < nVert && (pos1 == -1 || pos2 == -1); i++){
		if (V[i] == n1)
			pos1 = i;
		else if (V[i] == n2)
			pos2 = 0;
	}
	for (i = 0; i < E[pos1].size(); i++){
		if (E[pos1][i] == n2){
			pos1_2 = i;
			break;
		}
	}
	if (pos1 != -1 && pos2 != -1 && pos1_2 != -1){
		P[pos1][pos1_2] = valor;
	}
}
/**********************************************************************************************************************/
template <class T>
void GrafoDireccion<T>::EliminarArista(T n1,T n2){
	int pos1, pos2;
	bool nk=false, nk1=false;
	for (int i=0; i< nVert;i++){
		if(V[i]== n1)
			pos1=i;
		if (V[i]==n2)
			nk1=true;
	}
	for (int i=0; i <E[pos1].size();i++){
		if(E[pos1][i]==n2){
			E[pos1].erase(E[pos1].begin()+i);
			P[pos1].erase(P[pos1].begin()+i);
			nk=true;
			break;
		}
	}
	if(nk && nk1)
		nAri--;
}
/********************************************************************************************************************/
template <class T>
void GrafoDireccion<T>::EliminarNodo(T n1){
	int i;
	for (i = 0; i < nVert; i++){
		if (V[i] == n1){
			if (E[i].empty() && P[i].empty()){
				V.erase(V.begin()+i);
				E.erase(E.begin()+i);
				P.erase(P.begin()+i);
				nVert--;
			}
		}
	}
}
/********************************************************************************************************************/
template <class T>
vector<T> GrafoDireccion<T>::ObtenerListaAdy(T n1){
	int k;
	for(int h=0; h < V.size();h++){
		if(V[h]== n1){
			k=h;
			break;
		}
	}
	return E[k];
}
/******************************************************************************************************************/
template <class T>
int GrafoDireccion<T>::ObtenerNumVertices(){
	return nVert;
}
/*******************************************************************************************************************/
template <class T>
int GrafoDireccion<T>::ObtenerNumAristas(){
	return nAri;
}
/*******************************************************************************************************************/
template <class T>
vector<T> GrafoDireccion<T>::ObtenerVertices(){
	return V;
}
/********************************************************************************************************************/
template <class T>
vector<int> GrafoDireccion<T>::ObtenerPonderaciones(T n1){
	int i, pos;
	for (i = 0; i < nVert; i++){
		if (V[i] == n1){
			pos = i;
			break;
		}
	}
	return P[pos];
}
/*********************************************************************************************************************/

#endif // __GRAFO_DIRECCION_H

/*
 *Autores : Jeffrey Garcia, Mauricio Cortés
 *fecha de creacion : 9 de noviembre del 2017
 *fecha última modificacion : 24 de noviembre del 2017
 *vesion : 0.5
 *Archivo: OperacionesGrafo.h
*/

#ifndef __OPERACIONES_GRAFO_H
#define __OPERACIONES_GRAFO_H

#include <queue>
#include "ClaseGrafo1.h"

using namespace std;

template <class T>
class OperacionesGrafo{
public:
	OperacionesGrafo();
	vector<T> BreadthFirstSearch(Grafo<T> grafo, T raiz);
	vector<T> DepthFirstSearch(Grafo<T> grafo, T raiz);
	~OperacionesGrafo();
};

template <class T>
OperacionesGrafo<T>::OperacionesGrafo(){
}

template <class T>
vector<T> OperacionesGrafo<T>::BreadthFirstSearch(Grafo<T> grafo, T raiz){
	int i, j, pos;
	T nodo;
	vector<T> nodos(grafo.ObtenerVertices());
	vector<T> vis(grafo.ObtenerNumVertices(), 0);
	vector<T> out;
	vector<T> ady;
	queue<T> Q;
	for (i = 0; i < nodos.size(); i++){
		if (nodos[i] == raiz){
			pos = i;
			break;
		}
	}
	vis[pos] = 1;
	Q.push(raiz);
	while (!Q.empty()){
		nodo = Q.front();
		ady = grafo.ObtenerListaAdy(nodo);
		for (i = 0; i < ady.size(); i++){
			for (j = 0; j < nodos.size(); j++){
				if (ady[i] == nodos[j] && vis[j] == 0){
					vis[j] = 1;
					Q.push(ady[i]);
				}
			}
		}
		out.push_back(nodo);
		Q.pop();
	}
	return out;
}

template <class T>
vector<T> OperacionesGrafo<T>::DepthFirstSearch(Grafo<T> grafo, T raiz){
}

template <class T>
OperacionesGrafo<T>::~OperacionesGrafo(){
}

#endif
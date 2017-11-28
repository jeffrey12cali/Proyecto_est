/*
 *Autores : Jeffrey Garcia, Mauricio Cort�s
 *fecha de creacion : 9 de noviembre del 2017
 *fecha �ltima modificacion : 28 de noviembre del 2017
 *vesion : 1.0
 *Archivo: ClaseOperacionesGrafo.h
*/

#ifndef __OPERACIONES_GRAFO_H
#define __OPERACIONES_GRAFO_H
#define INF 2147483647

#include <iostream>
#include <queue>
#include <stack>
#include "ClaseGrafo.h"
#include "ClaseGrafoDireccion.h"

using namespace std;

template <class T>
class NodoDist{
public:
	T nodo;
	int distancia;
};

template <class T>
class Comparacion{
public:
	Comparacion(){}
	bool operator()(NodoDist<T> inf1, NodoDist<T>& inf2){
		return inf1.distancia > inf2.distancia;
	}
};

template <class T>
class OperacionesGrafo{
public:
	/* BreadthFirstSearch(Grafo<T> grafo, T raiz);
	 * Entradas: grafo, ra�z (nodo); 
	 * Salidas: vector de recorrido;
	 * Procedimiento: Primero se inicia el nodo raiz como visitado y se inserta
	 * a la cola. Mientras la cola no est� vac�a va a verificar cada nodo en el 
	 * frente de la cola, al que se le va a sacar su lista de adyacencia y se va
	 * a proceder a poner cada nodo adyacente al que se est� examinando actulamente
	 * como visitado y se ingresa a la cola, por �litmo, se env�a el nodo que se
	 * proceso al vector de salida y se saca de la cola.
	 */
	vector<T> BreadthFirstSearch(Grafo<T> grafo, T raiz);
	vector<T> BreadthFirstSearch(GrafoDireccion<T> grafo, T raiz);


	vector<T> DepthFirstSearch(Grafo<T> grafo, T raiz);
	vector<T> DepthFirstSearch(GrafoDireccion<T> grafo, T raiz);

	/* Dijkstra(Grafo<T> grafo, T raiz);
	 * Entradas: grafo, ra�z (nodo); 
	 * Salidas: impresi�n;
	 * Procedimiento: Se establece la distancia y el padre de la ra�z como 0 y �l mismo respectivamente,
	 * se ingresa a la cola de prioridad el nodo con su respectiva distancia a el nodo ra�z. Mientras la
	 * cola de prioridad est� vac�a se toma el primer elemento de la cola, es decir, el de menor distancia
	 * y se procesa. Primero se marca ese nodo como visitado. Y posteriormente a sus nodos adyacentes se les
	 * hace la comprobaci�n de que si su distancia es mayor a la ponderaci�n mas la distancia actual de ese nodo. 
	 * S�, esto es verdad, entonces se procede a cambiar la distancia del nodo adyacente por la distancia m�s la
	 * ponderaci�n y se colocoa como padre el nodo que se est� analizando actualmente. 
	 * Por �ltimo se agrega cada nodo adyacente a la cola de prioridad con su respectivo identificador y distancia.
	 * Al terminar el proceso con cada nodo se saca de la cola y se imprimen los valores necesarios para encontrar 
	 * los caminos m�s cortos desde la ra�z hacia cualquier nodo. 
	 */
	void Dijkstra(Grafo<T> grafo, T raiz);
	void Dijkstra(GrafoDireccion<T> grafo, T raiz);
};

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
	vector<T> nodos;
	vector<T> nodosVertices(grafo.ObtenerVertices());
	vector<T> vis(grafo.ObtenerNumVertices(), 0);
	vector<T> cabezaPila;
	T nodo;
	int pos;
	stack<int> pila;
	pila.push(raiz);
	while(!pila.empty()){
		nodo=pila.top();
		nodos.push_back(nodo);
		pila.pop();
		cabezaPila= grafo.ObtenerListaAdy(nodo);
		for(int i=0;i < grafo.ObtenerNumVertices();i++){
			if( nodo == nodosVertices[i]){
			      pos=i;
			      break;
			 }	
		}
		vis[pos]=1;
		for(int i=0; i < cabezaPila.size();i++){
			for(int k=0; k < nodosVertices.size();k++){
				if(cabezaPila[i]== nodosVertices[k] and vis[k]==0){
					pila.push(cabezaPila[i]);
					vis[k]=1;
				}
			}
		}
	}
	return nodos;
}

template <class T>
void OperacionesGrafo<T>::Dijkstra(Grafo<T> grafo, T raiz){
	int i, j, k;
	int nVert = grafo.ObtenerNumVertices();
	NodoDist<T> info, info2;
	T nodo;
	priority_queue<NodoDist<T>, vector<NodoDist<T>>, Comparacion<T>> cola;
	vector<int> distancia(nVert, INF);
	vector<int> pond;
	vector<T> padre(nVert, nodo);
	vector<int> visitado(nVert, 0);
	vector<T> nodos = grafo.ObtenerVertices();
	vector<T> ady;
	for (i = 0; i < nVert; i++){
		if (nodos[i] == raiz){
			distancia[i] = 0;
			padre[i] = raiz;
		}
	}
	info.nodo = raiz;
	info.distancia = 0;
	cola.push(info);
	while (!(cola.empty())){
		info = cola.top();
		for (i = 0; i < nVert; i++){
			if (nodos[i] == info.nodo){
				visitado[i] = 1;
				break;
			}
		}
		ady = grafo.ObtenerListaAdy(info.nodo);
		pond = grafo.ObtenerPonderaciones(info.nodo);
		for (j = 0; j < ady.size(); j++){
			for (k = 0; k < nVert; k++){
				if (ady[j] == nodos[k] && visitado[k] == 0 && 
					distancia[k] > distancia[i] + pond[j]){
					distancia[k] = distancia[i] + pond[j];
					padre[k] = info.nodo;
					info2.nodo = nodos[k];
					info2.distancia = distancia[k];
					cola.push(info2);
				}
			}
		}
		cola.pop();
	}
	for (i = 0; i < nVert; i++){
		cout << nodos[i] << " ";
	}
	cout << endl;
	for (i = 0; i < nVert; i++){
		cout << distancia[i] << " ";
	}
	cout << endl;
	for (i = 0; i < nVert; i++){
		cout << padre[i] << " ";
	}
}

template <class T>
vector<T> OperacionesGrafo<T>::BreadthFirstSearch(GrafoDireccion<T> grafo, T raiz){
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
vector<T> OperacionesGrafo<T>::DepthFirstSearch(GrafoDireccion<T> grafo, T raiz){
	vector<T> nodos;
	vector<T> nodosVertices(grafo.ObtenerVertices());
	vector<T> vis(grafo.ObtenerNumVertices(), 0);
	vector<T> cabezaPila;
	T nodo;
	int pos;
	stack<int> pila;
	pila.push(raiz);
	while(!pila.empty()){
		nodo=pila.top();
		nodos.push_back(nodo);
		pila.pop();
		cabezaPila= grafo.ObtenerListaAdy(nodo);
		for(int i=0;i < grafo.ObtenerNumVertices();i++){
			if( nodo == nodosVertices[i]){
			      pos=i;
			      break;
			 }	
		}
		vis[pos]=1;
		for(int i=0; i < cabezaPila.size();i++){
			for(int k=0; k < nodosVertices.size();k++){
				if(cabezaPila[i]== nodosVertices[k] and vis[k]==0){
					pila.push(cabezaPila[i]);
					vis[k]=1;
				}
			}
		}
	}
	return nodos;
}

template <class T>
void OperacionesGrafo<T>::Dijkstra(GrafoDireccion<T> grafo, T raiz){
	int i, j, k;
	int nVert = grafo.ObtenerNumVertices();
	NodoDist<T> info, info2;
	T nodo;
	priority_queue<NodoDist<T>, vector<NodoDist<T>>, Comparacion<T>> cola;
	vector<int> distancia(nVert, INF);
	vector<int> pond;
	vector<T> padre(nVert, nodo);
	vector<int> visitado(nVert, 0);
	vector<T> nodos = grafo.ObtenerVertices();
	vector<T> ady;
	for (i = 0; i < nVert; i++){
		if (nodos[i] == raiz){
			distancia[i] = 0;
			padre[i] = raiz;
		}
	}
	info.nodo = raiz;
	info.distancia = 0;
	cola.push(info);
	while (!(cola.empty())){
		info = cola.top();
		for (i = 0; i < nVert; i++){
			if (nodos[i] == info.nodo){
				visitado[i] = 1;
				break;
			}
		}
		ady = grafo.ObtenerListaAdy(info.nodo);
		pond = grafo.ObtenerPonderaciones(info.nodo);
		for (j = 0; j < ady.size(); j++){
			for (k = 0; k < nVert; k++){
				if (ady[j] == nodos[k] && visitado[k] == 0 && 
					distancia[k] > distancia[i] + pond[j]){
					distancia[k] = distancia[i] + pond[j];
					padre[k] = info.nodo;
					info2.nodo = nodos[k];
					info2.distancia = distancia[k];
					cola.push(info2);
				}
			}
		}
		cola.pop();
	}
	for (i = 0; i < nVert; i++){
		cout << nodos[i] << " ";
	}
	cout << endl;
	for (i = 0; i < nVert; i++){
		cout << distancia[i] << " ";
	}
	cout << endl;
	for (i = 0; i < nVert; i++){
		cout << padre[i] << " ";
	}
}

#endif

/*
 *Autores : Jeffrey Garcia, Mauricio Cortés
 *fecha de creacion : 9 de noviembre del 2017
 *fecha última modificacion : 25 de noviembre del 2017
 *vesion : 1.0
 *Archivo: ClaseGrafo.h
*/

#ifndef __GRAFO_H
#define __GRAFO_H

#include <vector>

using namespace std;

template <class T>
class Grafo{
protected:
	vector<T> V; //Vertices
	vector<vector<T> > E; //Aristas
	vector<vector<int> > P; //Ponderaciones
	int nAri;
	int nVert;

public:
	/* CONSTRUCTORAS */

	/* Grafo()
	 * Entradas: NULL; 
	 * Salidas: NULL;
	 * Procedimiento: Se inicializan los atributos de la clase grafo como vacíos, excepto los contadores nVert empty
	 * nAri.
	 */
	Grafo(); //CrearGrafoVacio

	/* Grafo(vector<T>)
	 * Entradas: NULL
	 * vector<T> nodos. Donde el tamaño de nodos es mayor a cero.
	 * Salidas: NULL
	 * Ninguna (void).
	 * Procedimiento:
	 * -Crea  N nodos en el vector V (vertices).Crea N vectores vacios en el vector de aristas.
	 * -Crea N vectores vacios en el vector de ponderaciones.Inicializa (0) contador de aristas y vertices.
	 */
	Grafo(vector<T>); //CrearGrafoNoVacio

	/* MODIFICADORAS */

	/* AgregarArista(T dato1, T dato2);
	 * Entradas: tipo T dato1, dato2; 
	 * Salidas: NULL;
	 * Procedimiento: Se procede a buscar los nodos en el vector de nodos para determinar su posición, una vez
	 * encontradas las posiciones se anexa en la última posición la nueva arista en las "listas de adyacencia" de
	 * cada nodo. En el vector de ponderaciones relacionado con cada nodo se anexa un 0 como ponderación de esa
	 * arista.
	 */
	void AgregarArista(T dato1, T dato2);

	/* AgregarArista(T dato1, T dato2, int valor);
	 * Entradas: tipo T dato1, dato2, int valor; 
	 * Salidas: NULL;
	 * Procedimiento: Se procede a buscar los nodos en el vector de nodos para determinar su posición, una vez
	 * encontradas las posiciones se anexa en la última posición la nueva arista en las "listas de adyacencia" de
	 * cada nodo. En el vector de ponderaciones relacionado con cada nodo se anexa el valor como ponderación de esa
	 * arista.
	 */
	void AgregarArista(T dato1, T dato2, int valor);
	
	/* AgregarNodo(T n1)
	 * Entradas: T n1.
	 * Salidas: NULL.
	 * Procedimiento:
	 * -Anexa el nodo n1 al vector V (vertices)
	 * -Anexa un vector vacio en el vector de aristas,	-Anexa un vector vacio en el vector ponderaciones
	*/
	void AgregarNodo(T n1);

	/* ModificarArista(T n1, T n2, int valor); 
	 * Entradas: tipo T n1, n2, int valor; 
	 * Salidas: NULL;
	 * Procedimiento: Se procede a buscar los nodos en el vector de nodos para determinar su posición, una vez
	 * encontradas las posiciones se busca cada nodo en la lista de adyacencia del otro para determinar su posición 
	 * en la lista de adyacencia. Posteriormente en esa posición se procede a sustuir el valor en esa posición por 
	 * el nuevo valor ingresado como parámetro. 
	 */
	void ModificarArista(T n1, T n2, int valor);

	/*EliminarArista(T n1, T n2)
	 * Entradas: T n1, T n2
	 * Salidas: NULL
	 * Procedimiento: Dado dos nodos busca en el vector de aristas de cada nodo y elimina el nodo que se ingreso en la entrada, a su vez
	 * tambien busca la posicion en el vector de pondoraciones  correspondientes a cada arista y elimina esa posicion en 
	 * el vector de ponderacion y por ultimo resta en 1 la cantidad de aristas.
	*/
	void EliminarArista(T n1,T n2);

	/* EliminarNodo(T n1); 
	 * Entradas: tipo T n1; 
	 * Salidas: NULL;
	 * Procedimiento: Para el nodo ingresado como parámetro se verifica que está en el vector de nodos, al encontrar
	 * la posición del nodo se procede a comprobar que no tiene ninguna arista ni ninguna ponderación. Por último
	 * se elimina el nodo, su "lista de adyacencia" y sus ponderaciones. 
	 */
	void EliminarNodo(T n1);

	/* ANALIZADORAS */

	/* ObtenerListaAdy(T n1).
	 * Entradas: nodo n1
	 * Salidas: vector<T>
	 * vector<T> con N nodos adyacentes al nodo n1
	 * Procedimiento:
	 * Dado un nodo busca en el vector de vertices,  cuando lo encuentra, segun la posicion en la cual esta en el vector de vertices
	 * entonces retorna la posicion X en E correspondiente a un vector de aristas del nodo n1.
	*/
	vector<T> ObtenerListaAdy(T n1);

	/* ObtenerNumVercies();
	 * Entradas: NULL; 
	 * Salidas: Número de vertices en el grafo;
	 * Procedimiento: Retorna el atributo nVert de la clase grafo. 
	 */
	int ObtenerNumVertices();

	/* ObtenerNumAristas();
	 * Entradas: NULL
	 * Salidas: int numero.
	 * Procedimento: Retorna el valor de la variable nVert.
	 */
	int ObtenerNumAristas();

	/* ObtenerVertices();
	 * Entradas: NULL; 
	 * Salidas: vector<T> V;
	 * Procedimiento: Retorna el vector de nodos de la clase grafo.
	 */
	vector<T> ObtenerVertices();

	/* ObtenerPonderaciones(T n1);
	 * Entradas: tipo T n1; 
	 * Salidas: vector<int>;
	 * Procedimiento: Busca la posición del nodo en el vector de nodos, y devuelve esa misma posición en el vector de 
	 * ponderaciones.
	 */
	vector<int> ObtenerPonderaciones(T n1);

	/* DESTRUCTORAS */
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
			for (i = 0; i < E[pos2].size(); i++){
				if (E[pos2][i] == dato1)
					ver2 = 1;
			}
			if (ver1 == 0 && ver2 == 0){
				E[pos1].push_back(dato2);
				P[pos1].push_back(0);
				E[pos2].push_back(dato1);
				P[pos2].push_back(0);
				nAri += 1;
			}
		}
	}
}
/******************************************************************************************************************/
template <class T>
void Grafo<T>::AgregarArista(T dato1, T dato2, int valor){
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
			for (i = 0; i < E[pos2].size(); i++){
				if (E[pos2][i] == dato1)
					ver2 = 1;
			}
			if (ver1 == 0 && ver2 == 0){
				E[pos1].push_back(dato2);
				P[pos1].push_back(valor);
				E[pos2].push_back(dato1);
				P[pos2].push_back(valor);
				nAri += 1;
			}
		}
	}
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
/**********************************************************************************************************************/
template <class T>
void Grafo<T>::EliminarArista(T n1,T n2){
	int pos1, pos2;
	bool nk=false,nk1=false;
	for (int i=0; i< nVert;i++){
		if(V[i]== n1)
			pos1=i;
		if (V[i]==n2)
			pos2=i;
	}
	for (int i=0; i <E[pos1].size();i++){
		if(E[pos1][i]==n2){
			E[pos1].erase(E[pos1].begin()+i);
			P[pos1].erase(P[pos1].begin()+i);
			nk=true;
			break;
		}
	}
	for(int i=0;i < E[pos2].size();i++){
		if(E[pos2][i]==n1){
			E[pos2].erase(E[pos2].begin()+i);
			P[pos2].erase(P[pos2].begin()+i);
			nk1=true;
			break;
		}
	}
	if(nk && nk1)
		nAri--;
}
/********************************************************************************************************************/
template <class T>
void Grafo<T>::EliminarNodo(T n1){
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
vector<T> Grafo<T>::ObtenerListaAdy(T n1){
	int k;
	for(int h=0; h < nVert;h++){
		if(V[h]== n1){
			k=h;
			break;
		}
	}
	return E[k];
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
/*******************************************************************************************************************/
template <class T>
vector<T> Grafo<T>::ObtenerVertices(){
	return V;
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
/*********************************************************************************************************************/
template <class T>
Grafo<T>::~Grafo(){
}

#endif // __GRAFO_H

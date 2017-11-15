#include <iostream>
#include <vector>
#include "grafo.h"

using namespace std;

int main(){
	Grafo<int> g(4);
	cout << g.ObtenerNumVertices();
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct nodo
{
	int numero;
	struct nodo* siguiente;
};
struct pila
{
	struct nodo* cabeza;
};
typedef struct nodo Nodo;
typedef struct pila Pila;
Nodo* CrearNodo(int numero);
Pila* inicializarPila();
void RecorrerPila(Pila* pila);
void InsertarNodo(Pila *p, Nodo *n);//push
void SacarNodo(Pila *p);//pop
int main(int argc, char *argv[]) {
	Nodo* n1=CrearNodo(4);
	Nodo *n2=CrearNodo(40);
	Nodo *n3=CrearNodo(400);
	Pila* p=inicializarPila();
	InsertarNodo(p, n1);
	InsertarNodo(p, n2);
	InsertarNodo(p, n3);
	//RecorrerPila(p);
	SacarNodo(p);
	SacarNodo(p);
	SacarNodo(p);
	SacarNodo(p);
	return 0;
}
Nodo* CrearNodo(int numero)
{
	Nodo *nodo=(Nodo*)malloc(sizeof(nodo));;
	nodo->siguiente=NULL;
	nodo->numero=numero;
	return nodo;	
}
Pila* inicializarPila()
{
	Pila* p=(Pila*)malloc(sizeof(Pila));
	p->cabeza=NULL;
	return p;
}
void InsertarNodo(Pila* p, Nodo* n)
{
	n->siguiente=p->cabeza;
	p->cabeza=n;
	
}
void RecorrerPila(Pila* pila)
{
	Nodo *n=pila->cabeza;
	while(n)
	{
		printf("NODO: %d", n->numero);
		n=n->siguiente;
	}
}
void SacarNodo(Pila *p)
{
	Nodo *n=p->cabeza;
	if (n)
	{
		printf("NODO: %d", n->numero);
		p->cabeza=n->siguiente;
		free(n);
	}
	else
	{
		printf("NO HAY ELEMENTOS EN LA PILA");
	}
}

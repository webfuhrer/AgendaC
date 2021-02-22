#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct coche
{
	char* nombre;
	int potencia;
};
typedef struct coche Coche;
void imprimirCoches(Coche* punteroCoches)
{
	while(punteroCoches!=NULL)
	{
		printf("COCHE: %s", punteroCoches->nombre);
		punteroCoches++;
	}
}
int main(int argc, char *argv[]) {
	
	Coche *cochePtr=(Coche*)malloc(sizeof(Coche));
	cochePtr->nombre=(char*)malloc(sizeof(Coche));
	strcpy(cochePtr->nombre, "FORD");
	Coche *cochePtr2=(Coche*)malloc(sizeof(Coche));
	cochePtr2->nombre=(char*)malloc(sizeof(Coche));
	strcpy(cochePtr2->nombre, "RENAULT");
	Coche *punteroCochesIni=(Coche*)malloc(sizeof(Coche));
	Coche *punteroCoches=(Coche*)malloc(2*sizeof(Coche));
	punteroCoches=cochePtr;
	punteroCochesIni=punteroCoches;
	punteroCoches++;
	punteroCoches=cochePtr2;
	punteroCoches++;
	punteroCoches=NULL;
	imprimirCoches(punteroCochesIni);
	return 0;
}

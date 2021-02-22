#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define RUTA "T:\\agenda\\agenda.csv"
#define SEPARADOR ","
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct contacto
{
	char* nombre;
	char* telefono;
};
typedef struct contacto Contacto;
Contacto pedirDatosContacto()
{
	char* nombre=(char*)malloc(sizeof(char));
	char* telefono=(char*)malloc(sizeof(char));
	printf("Nombre del contacto: ");
	scanf("%s", nombre);
	printf("Teléfono del contacto: ");
	scanf("%s", telefono);
	Contacto c;
	c.nombre=(char*)malloc(sizeof(char));
	c.telefono=(char*)malloc(sizeof(char));
	strcpy(c.nombre, nombre);
	strcpy(c.telefono, telefono);
	return c;
}
void imprimirContacto(Contacto c)
{
	printf("NOMBRE: %s ****** TELÉFONO: %s", c.nombre, c.telefono);
}
void grabarContacto (Contacto c)
{
	FILE *filePtr=fopen(RUTA, "a");
	strcat(c.nombre, SEPARADOR);
	strcat(c.nombre, c.telefono);
	strcat(c.nombre,"\n");
	fputs(c.nombre, filePtr);
	fclose(filePtr);
}
int main(int argc, char *argv[]) {

//FILE *filePtr=fopen(RUTA, "w");
/*Contacto c=pedirDatosContacto();
grabarContacto(c);
imprimirContacto(c);*/
leerContactos();
}
void leerContactos()
{
	FILE *filePtr=fopen(RUTA, "r");
	//1-Un while que busque el EOF
	//2-Dentro, uno que busque la coma y el segundo, un salto de línea.
	//Usa strtok coño!!
	
	char* linea=(char*)malloc(sizeof(char));
	while (linea!=NULL)
	{
	linea=fgets(linea, 20, filePtr);	
	printf("LINEA LEIDA: %s", linea);
	}
	
	
	fclose(filePtr);
}


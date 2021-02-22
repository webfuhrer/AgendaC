#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define RUTA "T:\\agenda\\agenda.csv"
#define SEPARADOR ","
#define GRABAR 1
#define LISTAR 2
#define SALIR 3
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
	//printf("NOMBRE: %s ****** TELÉFONO: %s", c.nombre, c.telefono);
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

void leerContactos()
{
	Contacto* c=(Contacto*)malloc(sizeof(Contacto));
	
	c->nombre=(char*)malloc(sizeof(char));
	c->telefono=(char*)malloc(sizeof(char));
	FILE *filePtr=fopen(RUTA, "r");
	//1-Un while que busque el EOF
	//2-Dentro, uno que busque la coma y el segundo, un salto de línea.
	//Usa strtok coño!!
	
	char* linea=(char*)malloc(sizeof(char));
	char* token=(char*)malloc(sizeof(char));
	linea=fgets(linea, 20, filePtr);
	while(linea!=NULL)
	{
		
		token = strtok(linea, SEPARADOR);//saco el nombre
		strcpy(c->nombre,token);
		token=strtok(NULL, SEPARADOR);
		strcpy(c->telefono, token);
		printf("NOMBRE: %s TELEFONO: %s\n", c->nombre, c->telefono);
		linea=fgets(linea, 20, filePtr);
		
	}
	
	
	fclose(filePtr);
	free(c);

}
int mostrarMenu()
{
	printf("INTRODUZCA LA OPCIÓN: \n");
	printf("%d Grabar nuevo contacto \n", GRABAR)	;
	printf("%d Listar contactos \n", LISTAR)	;
	printf("%d SALIR \n", SALIR)	;
	int opcion=0;
	scanf("%d", &opcion);
	return opcion;
}
int main(int argc, char *argv[]) {
int opcion=mostrarMenu();
while(opcion!=SALIR)
{
	switch(opcion)
	{
		case GRABAR: ;
		Contacto c=pedirDatosContacto();
			grabarContacto(c);
		break;
		case LISTAR:
			leerContactos();
			break;
			
				
	}
	opcion=mostrarMenu();
}


}

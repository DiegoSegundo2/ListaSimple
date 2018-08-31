#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Libro{
	char titulo[64];
	int anioPublicacion;
	struct Libro *next;
};

Libro * obtenerNodo(){
	Libro * temp;
	temp=(struct Libro *)malloc(sizeof(struct Libro));
	temp->next=NULL;
	return temp;
}

void insertar(Libro **cabecera){
	Libro *nuevo, *temp;
	nuevo=obtenerNodo();
	
	printf("\nTitulo: ");
	scanf("%s",&nuevo->titulo);
	printf("\nAnio de publicacion: ");
	scanf("%d",&nuevo->anioPublicacion);
	
	if(*cabecera==NULL){
		*cabecera=nuevo;
	}else{
		temp=*cabecera;
		nuevo->next=temp;
		*cabecera=nuevo;
	}
}

void imprimir(Libro *cabecera){
	Libro * temp;
	temp=cabecera;
	
	if(temp==NULL){
		printf("\nLista vacia. Presione una tecla para regresar ");
		getchar();
		return;
	}else{
		temp=cabecera;
		printf("\n");
		while(temp!=NULL){
			printf("\nTitulo: %s",temp->titulo);
			printf("\nAnio de Publicacion: %d",temp->anioPublicacion);
			temp=temp->next;
		}
		printf("\nNULL\n");
	}
	system("pause");
}



Libro buscar(Libro *cabecera){
	Libro * temp;
	Libro *aux;
	temp=cabecera;
	printf("\nIngrese el nombre del libro a buscar: ");
	scanf("%s",&aux->titulo);
	
	if((strncmp(temp->titulo, aux->titulo, 15)) == 0){
		printf("\nTitulo encontrado");
		printf("\nTitulo: %s",aux->titulo);
		printf("\nAnio de Publicacion: %d",aux->anioPublicacion);
	}else{
		temp=cabecera;
		printf("\n");
		while(strncmp(temp->titulo, aux->titulo, 15)!=0){
			printf("\nTitulo encontrado");
			printf("\nTitulo: %s",temp->titulo);
			printf("\nAnio de Publicacion: %d",temp->anioPublicacion);
			temp=temp->next;
		}
		
	}
	system("pause");
	
	/*if((strncmp(cabecera->titulo, aux->titulo, 15))!=0){
		printf("\nElemento no encontrado. ");
		getchar();
	}else{
		temp=cabecera;
		printf("\n");
		while(strncmp(temp->titulo, aux->titulo, 15)==0){
			printf("\nTitulo: %s",temp->titulo);
			printf("\nAnio de Publicacion: %d",temp->anioPublicacion);
			temp=temp->next;
		}
	}
	system("pause");*/
	
}


int main(int argc, char *argv[]){
	struct Libro *lista;
	lista=NULL;
	int opcion;
	do{
		system("cls");
		printf("\n[1] Insertar Datos");
		printf("\n[2] Imprimir Datos");
		printf("\n[3] Buscar Dato");
		printf("\n[4] Salir");
		printf("\nIngrese su opcion: ");
		scanf("%d",&opcion);
		switch(opcion){
			case 1: insertar(&lista);
					break;
			case 2: imprimir(lista);
					break;
			case 3: buscar(lista);
					break;
			case 4: exit(0);
			default: printf("\nOpcion invalida, intente de nuevo");						
		}
	}while(opcion!=4);
	getchar();
	
	
}

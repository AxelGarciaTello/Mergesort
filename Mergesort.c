/*
	Institulo Politecnico Nacional
	Escuela Superior de Cómputo
	Estructura de datos
	Grupo: 1CV8
	Alumno: De la Cruz Sierra Diana Paola
			García Tello Axel
	Profesor: Benjamín Luna Benoso
	@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	Ordenamiento por MergeSort
	
	Fecha: 22 de mayo de 2019
*/

#include <stdio.h>
#include <stdlib.h>

//Función para juntar y ordenar los arreglos
/*Indicar desde donde inicia, el principio de la segunda parte y el tamaño del 
  arreglo*/
void Merge(int lista[8], int p, int q, int r){
	int izquierda[8], derecha[8];
	int n1, n2, i, j, k;
	//Indicar el tamaño de los arreglos
	n1=q-p;
	n2=r-q;
	//Separar los datos del arreglo original
	for(i=0; i<n1; i++){
		izquierda[i]=lista[p+i];
	}
	for(j=0; j<n2; j++){
		derecha[j]=lista[q+j];
	}
	i=0;
	j=0;
	//Mientras no se analice toda el arreglo original
	for(k=p; k<r; k++){
		//Analizar los datos de los arreglos
		while(i<n1 && j<n2){
			//Agregar el datos correspondiente al arreglo original
			if(izquierda[i]<derecha[j]){
				lista[k]=izquierda[i];
				i++;
			}
			else{
				lista[k]=derecha[j];
				j++;
			}
			k++;
		}
		//Agregar los sobrantes de los arreglos
		if(i<n1){
			lista[k]=izquierda[i];
			i++;
		}
		if(j<n2){
			lista[k]=derecha[j];
			j++;
		}
	}
}

//Función para partir el arreglo en mitades
//Ingresar desde donde inicia y el tamaño del arreglo
void Mergesort(int lista[8], int p, int r){
	if(p<(r-1)){
		int q=(r+p)/2;
		Mergesort(lista, p, q);
		Mergesort(lista, q, r);
		Merge(lista, p, q, r);
	}
}

//Función de inicio para pedir los datos
void menu(void){
	int lista[8];
	int r=0,i=0;
	printf("Cuantos numeros desea ingresar\n");
	scanf("%d\n",&r);
	for(i=0;i<r;i++){
		printf("Ingresar numero\n");
		scanf("%d\n",&lista[i]);
	}
	Mergesort(lista,0,r);
	for(i=0; i<r; i++){
		printf("%d\t", lista[i]);
	}
	printf("\n");
	system("pause");
}

//Función main para ejecutar el programa
int main(void){
	menu();
	return 0;
}

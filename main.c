#include <stdio.h>
#include <time.h>
#include <stdlib.h>
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void insert(int*,int);
void seleccion(int*,int);
void burbuja(int*,int);

int main() {
	FILE* baseD = fopen("setdatosedades.txt", "r"); //Abre y lee el archivo
	clock_t start, end;
	double execTime;
    if (baseD == NULL) {//Revisa que el archivo no sea nulo
        printf("No existe el archivo.");
        return 0;
    }

    int buff,size=0,aux=0;//Inicializo la variable buff como buffer para los numeros size para el tamaño del array y aux como contador

	int *Num = malloc(4*sizeof(int));//Creo el array
  	if (Num == NULL) {
    	printf("No se pudo reservar la memoria\n");
  	}
    
	while (fscanf(baseD,"%d",&buff)==1)//Lee todos los int en el archivo
	{
		size++;
		//printf("%d\n",buff);
	}
	Num = realloc(Num, size * sizeof(int));//Cambia el tamaño del array para acomadar al archivo

	baseD = fopen("setdatosedades.txt", "r");//Recarga el archivo

	while (fscanf(baseD,"%d",&buff)==1)//Introduce los numeros al array
	{
		Num[aux] = buff;
		aux++;
		//printf("%d\n",buff);
	}

/*
	printf("%d\n",size);

	
	printf("Arreglo a ordenar: \n");
	for(aux=0;aux<size;aux++){
		printf("%d ",Num[aux]);
	}
	printf("\n");
*/


	int selector=0;
	printf("Bienvenido seleccione el metodo de ordenamiento que desea usar: \n");
	printf("	1.-Burbuja\n");
	printf("	2.-Insercion\n");
	printf("	3.-Seleccion\n");
	printf("	4.-Comparar Tiempos de Ejecucion\n");
	scanf("%i", &selector);
	switch(selector){
		case 1:
			printf("Selecciono Burbuja.\n");
			start = clock();//Inicia el reloj para contar el tiempo de ejecicion
			burbuja(Num,size);//ejecuta la funcion de ordenamiento burbuja
			end = clock();//Termina el reloj para contar el tiempo de ejecicion
			execTime = ((double)(end - start))/CLOCKS_PER_SEC;  //tradice a milisegundos el tiempo de los relojes
			printf("Tiempo de ejecucion: %f s.\n",execTime);
			break;
		case 2:
			printf("Selecciono Insercion.\n");
			start = clock();//Inicia el reloj para contar el tiempo de ejecicion
			insert(Num,size);//ejecuta la funcion de ordenamiento de insercion
			end = clock();//Termina el reloj para contar el tiempo de ejecicion
			execTime = ((double)(end - start))/CLOCKS_PER_SEC;  //tradice a milisegundos el tiempo de los relojes
			printf("Tiempo de ejecucion: %f s.\n",execTime);
			break;
		case 3:
			printf("Seleciono Seleccion.\n");
			start = clock();//Inicia el reloj para contar el tiempo de ejecicion
			seleccion(Num,size);//ejecuta la funcion de ordenamiento de seleccion
			end = clock();//Termina el reloj para contar el tiempo de ejecicion
			execTime = ((double)(end - start))/CLOCKS_PER_SEC;  //tradice a milisegundos el tiempo de los relojes
			printf("Tiempo de ejecucion: %f s.\n",execTime);
			break;
		case 4:
			printf("Burbuja.\n");//calculo de tiempo metodo burbuja
			start = clock();
			burbuja(Num,size);
			end = clock();
			execTime = ((double)(end - start))/CLOCKS_PER_SEC;  
			printf("Tiempo de ejecicion: %f s.\n\n\n",execTime);


			printf("Insercion.\n"); //calculo de tiempo metodo insercion
			start = clock();
			insert(Num,size);
			end = clock();
			execTime = ((double)(end - start))/CLOCKS_PER_SEC; 
			printf("Tiempo de ejecucion: %f s.\n\n\n",execTime);


			printf("Seleccion.\n"); //calculo de tiempo metodo seleccion
			start = clock();
			seleccion(Num,size);
			end = clock();
			execTime = ((double)(end - start))/CLOCKS_PER_SEC;  
			printf("Tiempo de ejecucion: %f s.\n\n\n",execTime);
			break;
		default:
			printf("Escoja una opcion valida.\n");
			break;
	}
	system("pause");
	free(Num);
}

void insert (int *Array, int tam){
	int i=0;
	int j=0;
	int k=0;
	int Num[tam];
	int l=0;
	int min;
	int size =tam;
	for(j=0;j<size;j++){
			Num[j]=Array[j];
	}
	
	/*printf("-----------------------------------------------------------\n");
	printf("Arreglo a ordenar: \n");
	for(l=0;l<size;l++){
		printf("%d ",Num[l]);
	}
	printf("\n-----------------------------------------------------------\n");*/
	
	for(i=0; i<size; i++){
		min=Num[i];
		/*printf("Proceso\n");
		for(l=0;l<size;l++){
			printf("Numero: %d Posicion %d\n",Num[l],l);
		}
		printf("-----------------------------------------------------------\n");*/
		for(j=i+1; j<size; j++){
			if(Num[j]<min){
				min=Num[j];
				for(k=j-1;k>=i;k--){
					Num[k+1]=Num[k];
				}
				Num[i]=min;
			}
		}
	}
	printf("-----------------------------------------------------------\n");
	printf("Resultado: \n");//Imprimir resultados
	for(l=0;l<size;l++){
		printf("%d ",Num[l]);
	
	}
	printf("\n-----------------------------------------------------------\n");
}

void seleccion (int *Array, int tam){
	int i=0;
	int j=0;
	int Num[tam];
	int posBuffer = 0;
	int numBuffer = 0;
	int size =tam;
	for(j=0;j<size;j++){
			Num[j]=Array[j];
	}
	for(i=0;i<size;i++){
		/*for(j=0;j<size;j++){
			printf("Number: %d Position %d\n",Num[j],j);
		}
		printf("-----------------------------------------------------------\n");*/
		posBuffer=i;
		numBuffer=Num[i];
		for(j=0;j+i<=size-1;j++){
			if(Num[j+i]<=numBuffer){
				posBuffer=j+i;
				numBuffer=Num[i+j];
			}
		}
		Num[posBuffer]=Num[i];
		Num[i]=numBuffer;
	}
	printf("-----------------------------------------------------------\n");
	printf("Resultado: \n");//Imprimir resultados
	for(i=0;i<size;i++){
		printf("%d ",Num[i]);
	
	}
	printf("\n-----------------------------------------------------------\n");
}

void burbuja (int *Array, int tam){
	int i=2;
	int j=0;
	int Num[tam];
	int aux = 0;
	//int Num[10] = {20,10,2,0,15,1,8,69,9,2};
	int size =tam;
	for(j=0;j<size;j++){
			Num[j]=Array[j];
	}
	while (i!=size-1){
		/*for(j=0;j<size;j++){
			printf("Number: %d Position %d\n",Num[j],j);
		}
		printf("-----------------------------------------------------------\n");*/
		for(j=0;j<=size-i;j++){
			//printf("Number: %d Position %d\n",Num[j],j);
			if(Num[j]>=Num[j+1]){
				aux=Num[j];
				Num[j]=Num[j+1];
				Num[j+1]=aux;
			}
		}
		i++;
	}
	printf("-----------------------------------------------------------\n");
	printf("Resultado: \n");//Imprimir resultados
	for(i=0;i<size;i++){
		printf("%d ",Num[i]);
	
	}
	printf("\n-----------------------------------------------------------\n");
}



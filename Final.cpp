#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

#define N 10
#define H 10

void carrega_matriz1(float matriz1[N][H]){
	for( int y = 0; y < N; y++){
		for(int z = 0; z < H; z++){
			matriz1[y][z] =(rand() % 5);
			printf("%.2f\t", matriz1[y][z]);
 		}
 		printf("\n");
	}
} 


void carrega_matriz2(float matriz2[3][3]){
	printf("\n");
	for (int y = 0; y < 3;y++){
		for(int z = 0; z < 3; z++){
			matriz2[y][z] = (rand() % 5);
			printf("%.2f\t", matriz2[y][z]);	
		}
		printf("\n");
	}
}

float soma_matrizMeio(float matrizMeio[3][3]){
	float soma = 0;
	for(int k = 0; k <= 2; k++){
		for(int o = 0; o <= 2; o++){
			soma = soma + matrizMeio[k][o];
		}
	}	
	 
	return soma;
}


void carrega_resultado(float matriz1[N][H], float matriz2[3][3]){
	float matrizResultado[N-2][H-2];
	float matrizMeio[3][3];
	for (int m = 1; m <= N-2; m++){//aumentar o contador para as linhas	
			for(int p = 1; p <= H-2; p++){//aumentar o contador para as colunas
 				for(int t = 0; t <= 2; t++ ){
 					for(int y = 0; y <= 2; y++){
 						matrizMeio[t][y] = matriz1[t+m][y+p] * matriz2[t][y];
					}
 				}
 				
			matriz1[m][p] = soma_matrizMeio(matrizMeio);	
 		  }
	}
}

void escreveMatrizResultado(float matriz1[N][H]){
	for (int m = 1; m <= N-2; m++){//aumentar o contador para as linhas	
		for(int p = 1; p <= H-2; p++){//aumentar o contador para as colunas
			if( m == 0 & p == 0){
			 	printf("\n");
			 	printf("\t MATRIZ RESULTADO\n");
			}
				
	 		printf("%.2f \t",  matriz1[m][p]);
	 	}
 		printf("\n");
 	}
}

int main(){
 	
	srand(time(NULL));
	int resultado1;

 	printf("Filtro matriz 3x3\n");
 	
 	float matriz1[N][H];
 	float matriz2[3][3];
 	
	//Procedimento para carregar a matriz
	carrega_matriz1(matriz1);
 	carrega_matriz2(matriz2);
 	carrega_resultado(matriz1, matriz2);
	escreveMatrizResultado(matriz1);
  }




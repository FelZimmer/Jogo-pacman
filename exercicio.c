#include <stdio.h>
#include <stdlib.h>

int  ** numeros;
int linhas = 5;
int colunas = 10;



int main(){


numeros = malloc(sizeof(int*) * linhas);

for ( int i= 0; i < linhas; i++){ 
    numeros[i] = malloc(sizeof(int) * (colunas + 1 ));
}

printf("Array alocado dinamicamente: %d\n", numeros);

for ( int i= 0; i < linhas; i++){ 
    free(numeros[i]);    
}
free(numeros); 

}

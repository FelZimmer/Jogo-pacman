#include  <stdio.h>
#include <stdlib.h>

char ** mapa;// ponteiro de ponteiro 
int linhas;
int colunas;


void lemapa(){
    FILE *f = fopen("mapa.txt", "r");

    if(f == 0) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    fscanf(f, " %d %d", &linhas, &colunas); // o * é para ler os dois primeiros números do arquivo e ignorar eles, pois não precisamos deles para nada
    
    alocampa(); // alocando a memória para o mapa, onde cada linha é um ponteiro para uma string

    for ( int i = 0; i < 5; i++) {    
    fscanf(f, " %s", mapa[i]); // passando a mascara %s ele vai ser capaz de ler uma string inteira e depois guardar no mapa 
    }

    fclose(f); 
}

void alocampa() { 
    mapa = malloc(sizeof(char*) * linhas); // alocando a memória para o mapa, onde cada linha é um ponteiro para uma string
    for (int i = 0; i < linhas;i ++) { 
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); // alocando a memória para cada linha do mapa, onde cada linha é uma string de caracteres
    }
}

void liberamapa() { 
      for (int i = 0; i < linhas; i++) { 
        free(mapa[i]); // liberando a memória alocada para cada linha do mapa
    }
    free(mapa); // liberando a memória alocada para o vetor de ponteiros
}







int main() { 
    
   
    lemapa();

    for (int i = 0; i < 5; i++) {    
        printf("%s\n", mapa[i]);
    }


    liberamapa();
}
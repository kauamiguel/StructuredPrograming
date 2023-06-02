/*
Nome: Kauã Miguel Costa matos

3. Desenvolva um programa em C que contenha um vetor contendo 5 elementos inteiros. Utilizando apenas notação de ponteiros, 
leia esse vetor do teclado e imprima o endereço das posições contendo valores pares.
*/

#include <stdio.h>


int main(){
    int vet[5] = {6,2,3,4,5};

    int *ptr = NULL;

    for(int i = 0; i<5; i++){
        ptr = &vet[i];
        if(*ptr % 2 == 0){
            printf("%d\n", ptr);
        }
       
    }
}
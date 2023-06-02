#include <stdio.h>

/*
Nome: Kauã Miguel Costa Matos

2. Crie um programa em C que receba três números do usuário depois crie uma função que receba os 3 números como parâmetros: A, B e C. 
Ordene de tal forma que, ao final da função, A contenha o menor número e C o maior.
 Imprima os três números. Obs: Utilize ponteiro para solucionar o problema.
*/


void ordenar(int a, int b, int c){
    int *ptr1 = &a, *ptr2 = &b, *ptr3 = &c;
    int aux1;

    if(*ptr1 > *ptr2 && *ptr1 > *ptr3){
        if(*ptr2 > *ptr3){
            aux1 = *ptr3;
            *ptr3 = *ptr1;
            *ptr1 = aux1;
        }else{
            aux1 = *ptr3;
            *ptr3 = *ptr1;
            *ptr1 = aux1;
            aux1 = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = aux1;
        }
    }else if(*ptr2 > *ptr1 && *ptr2 > *ptr3){
        if(*ptr3 > *ptr1){
            aux1 = *ptr2;
            *ptr2 = *ptr3;
            *ptr3 = aux1;
        }else{
            aux1 = *ptr2;
            *ptr2 = *ptr3;
            *ptr3 = aux1;
            aux1 = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = aux1;
        }
    }else{
        if(*ptr1 > *ptr2){
            aux1 = *ptr1;
            *ptr1 = *ptr2;
            *ptr2 = aux1;
        }
    }

    printf("a: %d b: %d c: %d\n", *ptr1, *ptr2, *ptr3);
    
}

int main(){
   int a,b,c;

   printf("Informe o primeiro valor: \n");
   scanf("%d", &a);
   printf("Informe o segundo valor: \n");
   scanf("%d", &b);
   printf("Informe o terceiro valor: \n");
   scanf("%d", &c);

    ordenar(a,b,c);


}
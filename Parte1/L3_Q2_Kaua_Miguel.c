#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
Nome: Kauã Miguel Costa Matos

2) Crie um programa que armazene 3 nomes numa matriz de strings. Após o
cadastro, você deverá criar um MENU que informe:
1 – Mostra os nomes cadastrados em maiúsculo e na ordem inversa, ou seja,
mostra do último ao primeiro nome cadastrado;
2 – Mostra quantas pessoas com o nome “PAULO” foram cadastradas;
3 - Mostra quantas letras ‘A’ foram cadastradas na matriz de strings;
4 – Mostra quantas letras ‘C’ o segundo nome cadastrado possui.
5 – SAIR
*/

int main(){

    char nomes[3][30];
    int respota_usuario = 0;
    int pessoasComAletraA = 0;
    int quantidadeLetrasC = 0;
    int quantidadeDePessoasComNomePaulo = 0;

    for(int i = 0; i<3; i++){
        printf("\nInforme o %d nome: ", i+1);
        gets(nomes[i]);
    }

    while(respota_usuario != 5){
        printf("\nMenu\n");
        printf("\n1 - Mostra os nomes cadastrados em maiúsculo e na ordem inversa, ou seja, mostra do último ao primeiro nome cadastrado; ");
        printf("\n2 – Mostra quantas pessoas com o nome “PAULO” foram cadastradas;");
        printf("\n3 - Mostra quantas letras ‘A’ foram cadastradas na matriz de strings; ");
        printf("\n4 - Mostra quantas letras ‘C’ o segundo nome cadastrado possui.");
        printf("\n5 – SAIR\n");  
        scanf("%d", &respota_usuario);
        

        switch (respota_usuario)
        {
        case 1:

        for (int i = 2; i >= 0; i--) {
            for (int j = 0; nomes[i][j] != '\0'; j++) {
                putchar(toupper(nomes[i][j]));
            }
            printf("\n");
        }

        break;
        
        case 2:
            for (int i = 0; i < 3; i++) {
                if (strcmp(nomes[i], "paulo") == 0) {
                    quantidadeDePessoasComNomePaulo++;
                }
            }
            printf("\nQuantidade de pessoas com o nome paulo: %d", quantidadeDePessoasComNomePaulo);
            break;

        case 3:
            for(int i = 0; i<3; i++){
                if(nomes[i][0] == 'a' || nomes[i][0] == 'A'){
                    pessoasComAletraA++;
                }
            }
            printf("\nQuantidade de pessoas com a letra A: %d", pessoasComAletraA);
            break;

        case 4:

            for(int j = 0; j < 30; j++){
                if(nomes[1][j] == 'c'){
                    quantidadeLetrasC++;
                }
            }

            printf("\nQuantidade de letras c: %d", quantidadeLetrasC);

            break;
        default:
            break;
        }
    }

}
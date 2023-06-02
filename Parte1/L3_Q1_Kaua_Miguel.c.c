#include <stdio.h>
/*
Nome: Kauã Miguel Costa Matos

1) Crie um programa que carregue (armazene) números numa matriz 3 x 3. Após a leitura dos números, você deverá criar um MENU que ofereça as seguintes opções:
1 – Mostra a quantidade de números pares armazenados; 
2 – Mostra a soma dos números ímpares armazenados;
3 – Mostra o maior e o menor número armazenado;
4 – Mostra a média dos números armazenados;
5 – Mostra a quantidade de números armazenados que são iguais a 10;
6 – Mostra a multiplicação dos números armazenados na diagonal principal (índice da linha igual ao índice da coluna);
7 – Mostra a soma dos números armazenados que são divisíveis por 5.
8 – Armazena num vetor todos os números menores que 8. Mostrar o vetor
resultante.
9 – Consulta um número na matriz. O usuário deverá informar qual o número deseja procurar na matriz, caso encontre, informar o número e qual a posição(índices) na matriz.
10 – SAIR
*/


int main(){
    int respostaUsuario = 0;
    int matriz[3][3];
    int qtd_numeros_pares = 0;
    int qtd_numeros_impar = 0;
    int maior_numero;
    int menor_numero;
    float somaTotal = 0;
    int qtd_numeros_igual_dez = 0;
    int multiplicacao_diagonal = 1;
    int soma_divisiveis_por_cinco = 0;
    int numeros_menores_oito[9];
    int numero_procurar = 0;
    int encontrou_numero = 0;
    int indice_linha;
    int indice_coluna;
    int index = 0;

    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            printf("\nInforme o valor da posicao [%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }


    while (respostaUsuario != 10){
    printf("\n\nMenu:\n");
    printf("\n1 - Mostra a quantidade de números pares armazenados; ");
    printf("\n2 - Mostra a soma dos números ímpares armazenados; ");
    printf("\n3 - Mostra o maior e o menor número armazenado; ");
    printf("\n4 - Mostra a média dos números armazenados; ");
    printf("\n5 - Mostra a quantidade de números armazenados que são iguais a 10; ");
    printf("\n6 - Mostra a multiplicação dos números armazenados na diagonal principal (índice da linha igual ao índice da coluna); ");
    printf("\n7 - Mostra a soma dos números armazenados que são divisíveis por 5. ");
    printf("\n8 - Armazena num vetor todos os números menores que 8. Mostrar o vetor ");
    printf("\n9 -  Consulta um número na matriz. O usuário deverá informar qual o número deseja procurar na matriz, caso encontre, informar o número e qual a posição(índices) na matriz. ");
    printf("\n10 - SAIR\n");
    scanf("%d", &respostaUsuario);

    
    switch (respostaUsuario)
    {
        case 1:
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (matriz[i][j] % 2 == 0){
                        qtd_numeros_pares++;
                    }
                }
            } 
            printf("\nQuantida de numeros pares: %d", qtd_numeros_pares);  
            break;
        
        case 2:
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (matriz[i][j] % 2 != 0){
                        qtd_numeros_impar++;
                    }
                }
            }
            printf("\nQuantida de numeros impares: %d", qtd_numeros_impar);
            break;

        case 3:
            menor_numero = matriz[0][0];
            maior_numero = matriz[0][0];
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if(matriz[i][j] > maior_numero){
                        maior_numero = matriz[i][j];
                    }

                    if(matriz[i][j] < menor_numero){
                        menor_numero = matriz[i][j];
                    }
                }
            }   

            printf("\nMaior numero: %d", maior_numero);
            printf("\nMenor numero: %d", menor_numero);
            break;

        case 4:
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    somaTotal = somaTotal + matriz[i][j];                
                }
            } 

            printf("\nMedia total: %.2f", somaTotal/9);
            break;

        case 5:
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (matriz[i][j] == 10){
                        qtd_numeros_igual_dez++;
                    }
                }
            }

            printf("\nQuantidade de numeros iguais a 10: %d", qtd_numeros_igual_dez);
            break;

        case 6:
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (i == j){
                        multiplicacao_diagonal = multiplicacao_diagonal * matriz[i][j];
                    }
                }
            }

            printf("\nMutiplicacao na diagonal: %d", multiplicacao_diagonal);
            break;

        case 7:
                for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(matriz[i][j] % 5 == 0){
                            soma_divisiveis_por_cinco = soma_divisiveis_por_cinco + matriz[i][j];
                        }
                    }
                }

                printf("\nQuantidade de numeros divisiveis por 5: %d", soma_divisiveis_por_cinco);
            break;

        case 8:
            index = 0;

            for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(matriz[i][j] < 8){
                            numeros_menores_oito[index] = matriz[i][j];
                            index++;
                        }
                    }
                }

                printf("Vetor resultante: \n");
                for(int i = 0; i <= index; i++){
                    printf("%d ", numeros_menores_oito[i]);
                }

            break;

        case 9:
            printf("\nInfotme o numero que deseja procurar: ");
            scanf("%d", &numero_procurar);
            for(int i = 0; i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(matriz[i][j] == numero_procurar){
                            encontrou_numero = 1;
                            indice_linha = i;
                            indice_coluna = j;
                        }
                    }
                }
            if (encontrou_numero == 1){
                printf("\nNumero encontrado: %d", numero_procurar);
                printf("\nLinha: %d Coluna: %d\n", indice_linha + 1, indice_coluna + 1);
            }else{
                printf("\nNumero nao encontrado.");
            }

            break;

            
        default:
            break;
        }
    }
    
}
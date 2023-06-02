/*
Nome: Kauã Miguel Costa Matos

3) Crie um programa em C que cadastre os dados de 5 alunos. Os dados a serem
cadastrados são: nome, matrícula, endereço, sexo, os nomes das 3 disciplinas e as 3
notas de cada disciplina que ele está cursando.
 Os dados devem ser cadastrados em um vetor e/ou matriz.
 Após o cadastro informe:
 a)Os dados dos alunos cadastrados e a sua situação ("aprovado" ou
"reprovado") em cada disciplina.
 b)Os dados do aluno com maior média em "LPI".
 c)A média geral dos alunos na disciplina "Algoritmo".
 d)A quantidade de alunos(as) reprovados em qualquer disciplina.
OBS.:1) Usar uma estrutura switch para mostrar os resultados calculados.
 2) Para o aluno ser aprovado a média das notas deve ser >= 6 

*/

#include <stdio.h>
#include <string.h>


typedef struct{
    char nome[20];
    int matricula;
    char endereco[50];
    char sexo;
    char disciplinas[3][20];
    float notasDisciplinas[3][3];
}aluno;


int main(){
    aluno alunos[5];
    char respostaUser = ' ';
    float temp = 0;
    int quantidadeDeDisciplinasReprovadas = 0;
    int quantidadeDeAlunosReprovados = 0;
    float maiorMedia = 0;
    int alunoComMaiorMdia = 0;

    for(int i = 0; i < 2; i++){
        fflush(stdin);
        printf("\nInforme o nome: ");
        gets(alunos[i].nome);
        printf("\nInforme a matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("\nInforme o endereco: ");
        fflush(stdin);
        gets(alunos[i].endereco);
        printf("\nInforme o sexo: ");
        scanf("%c", &alunos[i].sexo);
        fflush(stdin);

        for(int j = 0; j < 3; j++){
            printf("\nInforme as diciplinas: ");
            gets(alunos[i].disciplinas[j]);
        }

        for(int k = 0; k < 3; k++){
            for(int j = 0; j<3; j++){
                printf("\nInforme a nota da %d disciplina: ", k+1);
                scanf("%f", &alunos[i].notasDisciplinas[k][j]);
            }
            
        }

    }

    while(respostaUser != 'e'){
        printf("\n\nMenu:");
        printf("\na - Os dados dos alunos cadastrados e a sua situação (aprovado ou reprovado) em cada disciplina: \n");
        printf("\nb - Os dados do aluno com maior média em LPI:\n");
        printf("\nc - A - média geral dos alunos na disciplina Algoritmo.");
        printf("\nd - A quantidade de alunos(as) reprovados em qualquer disciplina.");
        printf("\ne - Sair.\n");
        fflush(stdin);
        scanf("%c", &respostaUser);

        switch (respostaUser)
        {
        case 'a':
            for(int i = 0; i < 5; i++){
                temp = 0;
                printf("Aluno %d: ", i+1);
                printf("\nNome: %s", alunos[i].nome);
                printf("\nMatricula: %d", alunos[i].matricula);
                printf("\nEndereco: %s", alunos[i].endereco);
                printf("\nSexo: %c", alunos[i].sexo);

                for(int j = 0; j < 3; j++){
                    for(int k = 0; k<3; k++){
                        temp = temp + alunos[i].notasDisciplinas[j][k];
                    }
                    temp = temp / 3;
                    if(temp >= 6){
                        printf("\nAluno %d foi aprovado em %s.", i+1, alunos[i].disciplinas[j]);
                    }else{
                        printf("\nAluno %d foi reprovado %s. ", i+1, alunos[i].disciplinas[j]);
                    }
                }
            }
            break;
        
        case 'b':

        temp = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                temp = 0;
                    for(int k = 0; k<3; k++){
                        temp = temp + alunos[i].notasDisciplinas[j][k];
                    }
                }
                temp = temp / 9;
                if(temp > maiorMedia){
                    maiorMedia = temp;
                        alunoComMaiorMdia = i;
                }
        }

        printf("\nAluno com maior media: \n");
        printf("\nNome: %s", alunos[alunoComMaiorMdia].nome);
        printf("\nMatricula: %d", alunos[alunoComMaiorMdia].matricula);
        printf("\nEndereco: %s", alunos[alunoComMaiorMdia].endereco);
        printf("\nSexo: %c", alunos[alunoComMaiorMdia].sexo);

            break;

        case 'c':
            temp = 0;
            for(int i = 0; i < 1; i++){
                for(int j = 0; j < 3; j++){
                    if (strcmp(alunos[i].disciplinas[j], "algoritimos") == 0){
                        for(int k = 0 ; k<3; k++){
                            temp = temp + alunos[i].notasDisciplinas[j][k];
                        }
                    }
                }
            }

            printf("\nMedia geral: %.2f", temp/5);
            break;

        case 'd':
            for(int i = 0; i<2; i++){
                for(int j = 0; j < 3; j++){
                    for(int k = 0; k<3; k++){
                        temp = temp + alunos[i].notasDisciplinas[j][k];
                    }
                    temp = temp / 3;
                    if(temp < 6){
                        quantidadeDeDisciplinasReprovadas++;
                    }
                }
                if(quantidadeDeDisciplinasReprovadas != 0){
                    quantidadeDeAlunosReprovados = quantidadeDeAlunosReprovados + 1;
                }
            }

            printf("\nQuantidade de alunos reprovados: %d\n", quantidadeDeAlunosReprovados);

            break;

        default:
            break;
        }
    }   

}



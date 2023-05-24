#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){

    int op;
    Aluno alunos[MAX_ALUNOS];
    int numAlunos;

    carregarDados(alunos, &numAlunos);

    while (1){
        printf("\n");
        printf("Sistema de Gerenciamento de Notas\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("Selecione uma opção (1-7):\n");
        printf("1 - Cadastrar novo aluno\n2 - Registrar notas de alunos\n3 - Calcular média individual\n4 - Calcular media geral da turma\n5 - Ranking de melhor desempenho\n6 - Exportar informações para arquivo externo\n7 - Encerrar programa\n");
        printf("\n");
        scanf("%d", &op);

        if (op == 1){
            printf("\n");
            printf("Cadastrar novo aluno\n");
            printf("--------------------\n");
            printf("\n");

            cadastrarAluno(alunos, &numAlunos);

        } else if (op == 2){
            printf("\n");
            printf("Registrar notas de alunos\n");
            printf("-------------------------\n");
            printf("\n");

            cadastrarNotas(alunos, numAlunos);

        } else if (op == 3){
            printf("\n");
            printf("Calcular média individual\n");
            printf("-------------------------\n");
            printf("\n");

            calcMediaIndiv(alunos, numAlunos);

        } else if (op == 4){
            printf("\n");
            printf("Calcular média geral da turma\n");
            printf("-----------------------------\n");
            printf("\n");

            calcMediaTurma(alunos, numAlunos);

        } else if (op == 5){
            printf("\n");
            printf("Ranking de melhor desempenho\n");
            printf("----------------------------\n");
            printf("\n");

            ranking(alunos, numAlunos);

        } else if (op == 6){
            printf("\n");
            printf("Exportar informações para arquivo externo\n");
            printf("-----------------------------------------\n");
            printf("\n");

        } else if(op == 7){
            printf("Programa encerrado.\n");
            break;
            
        } else {
            printf("\n");
            printf("Opção inválida!\n");
        }

        salvarDados(alunos, numAlunos);
    }
    return 0;
}

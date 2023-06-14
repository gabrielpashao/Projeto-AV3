#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){

    int op, opListar;
    Aluno alunos[MAX_ALUNOS];
    int numAlunos;
    
    
    limparTela();
    carregarAlunosDeBinario(alunos, &numAlunos);

    while (1){

        printf("\n");
        printf("Sistema de Gerenciamento de Notas\n");
        printf("---------------------------------\n");
        printf("\n");
        printf("Selecione uma opção (1-9):\n");
        printf("1 - Cadastrar novo aluno\n2 - Registrar notas de alunos\n3 - Calcular média individual\n4 - Calcular media geral da turma\n5 - Ranking de melhor desempenho\n6 - Exportar informações para arquivo externo\n7 - Listar alunos\n8 - Excluir aluno do sistema\n9 - Editar informações de alunos\n");
        printf("\n");
        printf("0 - Encerrar programa.\n");
        printf("\n");
        scanf("%d", &op);

        limparTela();

        if (op == 1){

            printf("\n");
            printf("Cadastrar novo aluno\n");
            printf("--------------------\n");
            printf("\n");

            cadastrarAluno(alunos, &numAlunos);
            VoltarAoMenu();

        } else if (op == 2){

            printf("\n");
            printf("Registrar notas de alunos\n");
            printf("-------------------------\n");
            printf("\n");

            cadastrarNotas(alunos, numAlunos);
            VoltarAoMenu();

        } else if (op == 3){

            printf("\n");
            printf("Calcular média individual\n");
            printf("-------------------------\n");
            printf("\n");

            calcMediaIndiv(alunos, numAlunos);
            VoltarAoMenu();

        } else if (op == 4){

            printf("\n");
            printf("Calcular média geral da turma\n");
            printf("-----------------------------\n");
            printf("\n");

            calcMediaTurma(alunos, numAlunos);
            VoltarAoMenu();

        } else if (op == 5){

            printf("\n");
            printf("Ranking de melhor desempenho\n");
            printf("----------------------------\n");
            printf("\n");

            ranking(alunos, numAlunos);
            VoltarAoMenu();

        } else if (op == 6){

            printf("\n");
            printf("Exportar informações para arquivo externo\n");
            printf("-----------------------------------------\n");
            printf("\n");

            salvarAlunosEmCSV(alunos, numAlunos);
            VoltarAoMenu();
            
        } else if (op == 7){
            
            printf("\n");
            printf("Listar alunos\n");
            printf("-------------\n");
            printf("\n");

            printf("Selecione uma opção (1-3):\n");
            printf("1 - Ordenar por matrícula\n2 - Ordenar por ordem alfabética\n3 - Ordenar por média\n");
            printf("\n");
            printf("0 - Voltar ao menu principal\n");
            printf("\n");
            scanf("%d", &opListar);

            limparTela();

            if(opListar == 1){

                ordenarPorMatricula(alunos, numAlunos);
                VoltarAoMenu();

            } else if(opListar == 2){

                ordenarPorNome(alunos, numAlunos);
                VoltarAoMenu();

            } else if(opListar == 3){
                
                ordenarPorMedia(alunos, numAlunos);
                VoltarAoMenu();

            } else if(opListar == 0){

                VoltarAoMenu();

            } else {

                printf("\n");
                printf("Opção inválida!\n");
                VoltarAoMenu();

            }

        } else if(op == 8){

            printf("\n");
            printf("Excluir aluno do sistema\n");
            printf("------------------------\n");
            printf("\n");

            excluirAluno(alunos, &numAlunos);
            VoltarAoMenu();

        } else if(op == 9){

            printf("\n");
            printf("Editar informações de alunos\n");
            printf("----------------------------\n");
            printf("\n");

            editarNome(alunos, numAlunos);
            VoltarAoMenu();

        } else if(op == 0){

            printf("Programa encerrado.\n");
            salvarAlunosEmBinario(alunos, numAlunos);
            break;
            
        } else {

            printf("\n");
            printf("Opção inválida!\n");

            VoltarAoMenu();
        }
    }

    return 0;
}

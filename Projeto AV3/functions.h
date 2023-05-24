#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUNOS 100

// Estrutura de Dados

typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
    float notas[3];
    float media;
} Aluno;

// Funções

void salvarDados(Aluno alunos[], int numAlunos) {
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++) {
        fprintf(arquivo, "%s %d %s %.2f %.2f %.2f %.2f\n",
                alunos[i].nome, alunos[i].matricula, alunos[i].curso,
                alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].media);
    }

    fclose(arquivo);
}

void carregarDados(Aluno alunos[], int *numAlunos) {
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de dados não encontrado. Será criado um novo arquivo.\n");
        return;
    }

    *numAlunos = 0;
    while (*numAlunos < MAX_ALUNOS && fscanf(arquivo, "%49s %d %49s %f %f %f %f\n",
                                            alunos[*numAlunos].nome, &alunos[*numAlunos].matricula,
                                            alunos[*numAlunos].curso, &alunos[*numAlunos].notas[0],
                                            &alunos[*numAlunos].notas[1], &alunos[*numAlunos].notas[2],
                                            &alunos[*numAlunos].media) == 7) {
        printf("Alunos carregados: %s\n", alunos[*numAlunos].nome);
        (*numAlunos)++;
    }

    fclose(arquivo);
}

void cadastrarAluno(Aluno alunos[], int *numAlunos){

    int i;

    if (*numAlunos < MAX_ALUNOS) {
        printf("Digite o nome do aluno:\n");
        scanf(" %49[^\n]", alunos[*numAlunos].nome);
        printf("\n");
        printf("Digite a matrícula:\n");
        scanf("%d", &alunos[*numAlunos].matricula);
        printf("\n");
        printf("Digite o curso:\n");
        scanf("%s", alunos[*numAlunos].curso);
        printf("\n");

        for (i = 0; i < *numAlunos; i++){
            if (alunos[i].matricula == alunos[*numAlunos].matricula){
                printf("Matrícula já em uso!\n");
                printf("\n");
                printf("Insira outra matrícula:\n");
                scanf("%d", &alunos[*numAlunos].matricula);
                i = -1;
            }
        }

        (*numAlunos)++;
        printf("Aluno cadastrado com sucesso!\n");
        printf("\n");
        printf("Total de alunos cadastrados: %d \n", *numAlunos);
        printf("\n");
    } else {
        printf("Limite de alunos atingido. Impossível cadastrar.\n");
    }
}

void cadastrarNotas(Aluno alunos[], int numAlunos){

    int matricula, i;

    printf("Digite a matrícula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            printf("Digite a nota AV1:\n");
            scanf("%f", &alunos[i].notas[0]);
            printf("Digite a nota AV2:\n");
            scanf("%f", &alunos[i].notas[1]);
            printf("Digite a nota AV3:\n");
            scanf("%f", &alunos[i].notas[2]);

            alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3; //calcular média do aluno
            printf("Notas cadastradas com sucesso!\n");
            printf("\n");
            printf("As notas do aluno %s são:\n", alunos[i].nome);
            printf("AV1: %.2f\n", alunos[i].notas[0]);
            printf("AV2: %.2f\n", alunos[i].notas[1]);
            printf("AV3: %.2f\n", alunos[i].notas[2]);
            printf("Média: %.2f\n", alunos[i].media);
            return;
        }
    }

    printf("Aluno com a matrícula informada não encontrado.\n");
}

void calcMediaIndiv (Aluno alunos[], int numAlunos){

    int matricula, i;

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++){
        if (alunos[i].matricula == matricula){
            alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;
            printf("A média do aluno %s é: %.2f", alunos[i].nome, alunos[i].media);
        return;
        }
    }

    printf("Aluno com a matrícula informada não encontrado.\n");
}

void calcMediaTurma (Aluno alunos[], int numAlunos){

    float mediaTurma;
    float somaMedia = 0.0;
    int i;

    for (i=0; i < numAlunos; i++){
        somaMedia += alunos[i].media;
    }

    mediaTurma = somaMedia/numAlunos;
    printf("A média da turma é: %.2f \n", mediaTurma);
    return;
}

void ranking (Aluno alunos[], int numAlunos){

    int i, j;

    for (i = 0; i < numAlunos - 1; i++){
        for (j = i; j <numAlunos; j++){
            if (alunos[j].media > alunos[i].media) {
                Aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    printf("Ranking das melhores médias da turma:\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("%d. Aluno: %s | Média: %.2f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
    return;
}

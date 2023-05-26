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

// Carregar os dados do arquivo binário
void carregarAlunosDeBinario(Aluno alunos[], int *numAlunos) {
    
    FILE* arquivo = fopen("alunos.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fread(numAlunos, sizeof(int), 1, arquivo);
    fread(alunos, sizeof(Aluno), *numAlunos, arquivo);
    fclose(arquivo);

    printf("Os dados dos alunos foram carregados do arquivo alunos.bin.\n");
    
    for(int i = 0; i < *numAlunos; i++){
    printf("Aluno: %s | Matrícula: %d\n", alunos[i].nome, alunos[i].matricula);
    }
}

// Salvar os dados no arquivo binário
void salvarAlunosEmBinario(Aluno alunos[], int numAlunos) {
    
    FILE* arquivo = fopen("alunos.bin", "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(&numAlunos, sizeof(int), 1, arquivo);
    fwrite(alunos, sizeof(Aluno), numAlunos, arquivo);
    fclose(arquivo);

    printf("Os dados dos alunos foram salvos no arquivo alunos.bin.\n");
}

// Cadastrar alunos novos
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

    VoltarAoMenu();
}

// Cadastrar notas
void cadastrarNotas(Aluno alunos[], int numAlunos){

    int matricula, i;

    printf("Digite a matrícula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            
            float av1, av2, av3;
            
            do{
                printf("Digite a nota AV1:\n");
                scanf("%f", &av1);
                if (av1 > 10){
                    printf("Nota inválida! Insira uma nota menor ou igual a 10.\n");
                    printf("\n");
                }
            } while (av1 > 10);
            
            do{
                printf("Digite a nota AV2:\n");
                scanf("%f", &av2);
                if (av2 > 10){
                    printf("Nota inválida! Insira uma nota menor ou igual a 10.\n");
                    printf("\n");
                }
            } while (av2 > 10);
        
            do{
                printf("Digite a nota AV3:\n");
                scanf("%f", &av3);
                if (av3 > 10){
                    printf("Nota inválida! Insira uma nota menor ou igual a 10.\n");
                    printf("\n");
                }
            } while (av3 > 10);

            alunos[i].notas[0] = av1;
            alunos[i].notas[1] = av2;
            alunos[i].notas[2] = av3;

            alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;

            printf("Notas cadastradas com sucesso!\n");
            printf("\n");
            printf("As notas do aluno %s são:\n", alunos[i].nome);
            printf("AV1: %.2f\n", alunos[i].notas[0]);
            printf("AV2: %.2f\n", alunos[i].notas[1]);
            printf("AV3: %.2f\n", alunos[i].notas[2]);
            printf("Média: %.2f\n", alunos[i].media);
        } else {
            printf("Aluno com a matrícula informada não encontrado.\n");
        }
    }

    VoltarAoMenu();
}

// Calcular média individual
void calcMediaIndiv (Aluno alunos[], int numAlunos){

    int matricula, i;

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++){
        if (alunos[i].matricula == matricula){
            printf("A média do aluno %s é: %.2f", alunos[i].nome, alunos[i].media);
        } else{
            printf("Aluno com a matrícula informada não encontrado.\n");
        }
    }

    VoltarAoMenu();
}

// Calcular média da turma
void calcMediaTurma (Aluno alunos[], int numAlunos){

    float mediaTurma;
    float somaMedia = 0.0;
    int i;

    for (i=0; i < numAlunos; i++){
        somaMedia += alunos[i].media;
    }

    mediaTurma = somaMedia/numAlunos;
    printf("A média da turma é: %.2f \n", mediaTurma);
    
    VoltarAoMenu();
}

// Exibiri ranking de melhores médias
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
    printf("\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("%d. Aluno: %s | Média: %.2f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
    
    VoltarAoMenu();
}

// Salvar dados em arquivo externo 
void salvarAlunosEmCSV(Aluno alunos[], int numAlunos) {
    
    FILE* arquivo = fopen("alunos.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numAlunos; i++) {
        fprintf(arquivo, "%s;%d;%s;%.2f;%.2f;%.2f;%.2f\n", alunos[i].nome, alunos[i].matricula,
                alunos[i].curso, alunos[i].notas[0], alunos[i].notas[1], alunos[i].notas[2], alunos[i].media);
    }
    fclose(arquivo);

    printf("Os dados dos alunos foram salvos no arquivo alunos.csv.\n");

    VoltarAoMenu();
}

// Retornar ao menu principal 
void VoltarAoMenu(){

 printf("\nPressione ENTER para retornar ao menu principal.");
    getchar();
    while (getchar() != '\n');
    return;
}
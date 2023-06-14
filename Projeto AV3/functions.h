#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ALUNOS 100

#ifdef _WIN32
    #define CLEAR_SCREEN "cls" // Comando para limpar a tela no Windows
#else
    #define CLEAR_SCREEN "clear" // Comando para limpar a tela no Linux
#endif

// Estrutura de Dados
typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
    float notas[3];
    float media;
} Aluno;

// Funções

// Limpar a tela
void limparTela(){
    system(CLEAR_SCREEN);
}

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
    printf("\n");
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

    int i, matricula;

    if (*numAlunos < MAX_ALUNOS) {
        printf("Digite o nome do aluno:\n");
        scanf(" %49[^\n]", alunos[*numAlunos].nome);
        printf("\n");

        do {
            printf("Digite a matrícula:\n");
            scanf("%d", &matricula);

            if (matricula <= 0){
                printf("\n");
                printf("Insira uma matrícula maior que 0.\n");
                printf("\n");
            }else{
                for (i = 0; i < *numAlunos; i++){
                    if (alunos[i].matricula == matricula){
                        printf("\n");
                        printf("Matrícula já em uso! Insira outra matrícula.\n");
                        printf("\n");
                        matricula = -1;
                        break;
                    }
                }
            } 
        } while (matricula <= 0);

        if(matricula > 0 && matricula != alunos[i].matricula){
            alunos[*numAlunos].matricula = matricula;
        }

        printf("\n");
        printf("Digite o curso:\n");
        scanf("%s", alunos[*numAlunos].curso);
        printf("\n");

        (*numAlunos)++;
        printf("Aluno cadastrado com sucesso!\n");
        printf("\n");
        printf("Total de alunos cadastrados: %d \n", *numAlunos);
        printf("\n");
    } else {
        printf("Limite de alunos atingido. Impossível cadastrar.\n");
    }
}

// Cadastrar notas
void cadastrarNotas(Aluno alunos[], int numAlunos){

    int matricula, i;
    bool alunoEncontrado = false;

    printf("Digite a matrícula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula){

        float av1, av2, av3;
            
        do{
            printf("Digite a nota AV1:\n");
            scanf("%f", &av1);
            if (av1 > 10 || av1 < 0){
                printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                printf("\n");
                }
        } while (av1 > 10 || av1 < 0);
            
        do{
            printf("Digite a nota AV2:\n");
            scanf("%f", &av2);
            if (av2 > 10 || av2 < 0){
                printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                printf("\n");
                }
        } while (av2 > 10 || av2 < 0);
        
        do{
            printf("Digite a nota AV3:\n");
            scanf("%f", &av3);
            if (av3 > 10 || av3 < 0){
                printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                printf("\n");
                }
        } while (av3 > 10 || av3 < 0);

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

        alunoEncontrado = true;

        break;
        }
    }
            
    if (!alunoEncontrado){
        printf("Aluno com a matrícula informada não encontrado.\n");
    }
}

// Calcular média individual
void calcMediaIndiv (Aluno alunos[], int numAlunos){

    int matricula, i;
    bool alunoEncontrado = false;

    printf("Digite a matricula do aluno:\n");
    scanf("%d", &matricula);

    for (i = 0; i < numAlunos; i++){
        if (alunos[i].matricula == matricula){

            printf("A média do aluno %s é: %.2f\n", alunos[i].nome, alunos[i].media);
            printf("\n");

            alunoEncontrado = true;
            break;
        }
    }

    if (!alunoEncontrado){
        printf("Aluno com a matrícula informada não encontrado.\n");
        printf("\n");
    }
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
    for (int i = 0; i < 10; i++) {
        printf("%d. Aluno: %s | Média: %.2f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
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
}

// Retornar ao menu principal 
void VoltarAoMenu(){

 printf("\nPressione ENTER para retornar ao menu principal.");
    getchar();
    while (getchar() != '\n');

    limparTela();

    return;
}

// Listar Alunos por matrícula 
void ordenarPorMatricula(Aluno alunos[], int numAlunos) {
    int i, j;
    Aluno tempAluno;

    for (i = 0; i < numAlunos - 1; i++) {
        for (j = 0; j < numAlunos - i - 1; j++) {
            if (alunos[j].matricula > alunos[j + 1].matricula) {
                tempAluno = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = tempAluno;
            }
        }
    }

    printf("Alunos ordenados por matrícula:\n");
    printf("-------------------------------\n");
    printf("\n");

    for (i = 0; i < numAlunos; i++) {
        printf("%d - Aluno: %s | Matrícula: %d\n", i + 1, alunos[i].nome, alunos[i].matricula);
    }
}

// Listar Alunos por média
void ordenarPorMedia(Aluno alunos[], int numAlunos) {
    int i, j;
    Aluno tempAluno;

    for (i = 0; i < numAlunos - 1; i++) {
        for (j = 0; j < numAlunos - i - 1; j++) {
            if (alunos[j].media < alunos[j + 1].media) {
                tempAluno = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = tempAluno;
            }
        }
    }

    printf("Alunos ordenados por média:\n");
    printf("---------------------------\n");
    printf("\n");

    for (i = 0; i < numAlunos; i++) {
        printf("%d - Aluno: %s | Média: %.2f\n", i + 1, alunos[i].nome, alunos[i].media);
    }
}

void ordenarPorNome(Aluno alunos[], int numAlunos) {
    int i, j;
    Aluno tempAluno;

    for (i = 0; i < numAlunos - 1; i++) {
        for (j = 0; j < numAlunos - i - 1; j++) {
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                tempAluno = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = tempAluno;
            }
        }
    }

    printf("Alunos ordenados por ordem alfabética:\n");
    printf("--------------------------------------\n");
    printf("\n");

    for (i = 0; i < numAlunos; i++) {
        printf("%d - Aluno: %s | Matrícula: %d\n", i + 1, alunos[i].nome, alunos[i].matricula);
    }
}

// Excluir aluno do sistema
void excluirAluno(Aluno alunos[], int *numAlunos) {

    int matricula, i, posicao;
    char decisao;
    bool alunoEncontrado = false;

    printf("Digite a matricula do aluno que deseja excluir:\n");
    scanf("%d", &matricula);

    for (i = 0; i < *numAlunos; i++) {
        if (alunos[i].matricula == matricula) {
            posicao = i;
            alunoEncontrado = true;

            printf("\n");
            printf("Deseja remover o aluno '%s' do cadastro?\n", alunos[i].nome);
            printf("\n");
            printf("S - Sim || N - Não");
            printf("\n");
            scanf("%s", &decisao);

            if (decisao == 's' || decisao == 'S'){

                if (i < *numAlunos) {
                    for (i = posicao; i < *numAlunos - 1; i++) {
                        alunos[i] = alunos[i + 1];
                    }

                (*numAlunos)--;
                printf("Aluno removido com sucesso!\n");
                break;
                }

            } else if (decisao == 'n' || decisao == 'N'){

                printf("Operação cancelada!\n");

            } else {

                printf("Opção inválida!\n");

            }

            break;

        }
    }

    if(!alunoEncontrado){

        printf("Aluno não encontrado!\n");

    }
}

// Editar nome
void editarNome(Aluno alunos[], int numAlunos){

    int matricula, i;
    bool alunoEncontrado = false;

    printf("Digite a matricula do aluno que deseja editar:\n");
    scanf("%d", &matricula);
    

    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].matricula == matricula) {

            getchar();
            printf("\n");
            printf("Editando informações do aluno %s\n", alunos[i].nome);
            printf("\n");
            printf("Insira o novo nome do aluno:\n");
            scanf("%49[^\n]", alunos[i].nome);
            printf("\nNome do aluno editado com sucesso para: %s\n", alunos[i].nome);
            
            alunoEncontrado = true;
            break;
        }
    }

    if(!alunoEncontrado){

        printf("Aluno não encontrado!\n");

    }
}

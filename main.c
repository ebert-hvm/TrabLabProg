#pragma region Header

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

#pragma endregion

#pragma region Definitions

#define NAME_SIZE 100
#define CPF_SIZE 20

typedef struct aluno {
    char nome[NAME_SIZE];
    char cpf[CPF_SIZE];
    int codigo;
    node* disciplinas;
} aluno;

typedef struct disciplina {
    char nome[NAME_SIZE];
    char professor[NAME_SIZE];
    int codigo;
    int creditos;
    node* alunos;
} disciplina;

#pragma endregion

#pragma region EBFunctions

aluno* create_aluno(const char nome[], const char cpf[], const int codigo){
    aluno* new_aluno = (aluno*)malloc(sizeof(aluno));

    strncpy(new_aluno->nome, nome, strlen(nome));
    (new_aluno->nome)[strlen(nome)] = '\0';
    strncpy(new_aluno->cpf, cpf, strlen(nome));
    (new_aluno->cpf)[strlen(cpf)] = '\0';

    new_aluno->codigo = codigo;
    new_aluno->disciplinas = new_list();
    
    return new_aluno;
}

disciplina* create_disciplina(const char nome[], const char professor[], const int codigo, const int creditos){
    disciplina* new_disciplina = (disciplina*)malloc(sizeof(disciplina));
    
    strncpy(new_disciplina->nome, nome, strlen(nome));
    (new_disciplina->nome)[strlen(nome)] = '\0';
    strncpy(new_disciplina->professor, professor, strlen(professor));
    (new_disciplina->professor)[strlen(professor)] = '\0';

    new_disciplina->codigo = codigo;
    new_disciplina->creditos = creditos;
    new_disciplina->alunos = new_list();
    return new_disciplina;
}

int cmp_aluno(void* val1, void* val2) {
    if (((aluno*)val1)->codigo == ((aluno*)val2)->codigo &&
        !strcmp(((aluno*)val1)->cpf, ((aluno*)val1)->cpf) &&
        !strcmp(((aluno*)val1)->nome, ((aluno*)val1)->nome)) {
        return 0;
    } else
        return 1;
}

int cmp_disciplina(void* val1, void* val2) {
    if (((disciplina*)val1)->codigo == ((disciplina*)val2)->codigo &&
        ((disciplina*)val1)->creditos == ((disciplina*)val2)->creditos &&
        !strcmp(((disciplina*)val1)->nome, ((disciplina*)val1)->nome) &&
        !strcmp(((disciplina*)val1)->professor, ((disciplina*)val1)->professor)) {
        return 0;
    } else
        return 1;
}

void print_aluno(void* val) {
    printf("Aluno: %s\nCodigo: %d\nCPF: %s\n\n",
           ((aluno*)val)->nome,
           ((aluno*)val)->codigo,
           ((aluno*)val)->cpf);
}

void print_disciplina(void* val) {
    printf("Disciplina: %s\nProfessor: %s\nCodigo: %d\nCreditos: %d\n\n",
           ((disciplina*)val)->nome,
           ((disciplina*)val)->professor,
           ((disciplina*)val)->codigo,
           ((disciplina*)val)->creditos);
}

#pragma endregion

aluno* read_aluno(){
    char nome[NAME_SIZE], cpf[CPF_SIZE];
    int codigo;
    scanf("%[^\n] %[^\n] %d", nome, cpf, &codigo);
    aluno* new_aluno = create_aluno(nome, cpf, codigo);
    return new_aluno;
}

disciplina* read_disciplina(){
    char nome[NAME_SIZE], professor[NAME_SIZE];
    int codigo, creditos;
    scanf("%[^\n] %[^\n] %d %d", nome, professor, &codigo, &creditos);
    disciplina* new_disciplina = create_disciplina(nome, professor, codigo, creditos);
    return new_disciplina;
}

#pragma region BIGFunctions

void cadastrar_aluno(){

}

void cadastrar_disciplina(){
    
}

void matricular_aluno_na_disciplina(){

}

void desmatricular_aluno_da_disciplina(){

}

void excluir_aluno(){

}

void excluir_disciplina(){

}

void consultar_disciplinas_por_aluno(){

}

void consultar_alunos_por_disciplina(){
    
}

void salvar(){

}

void recuperar(){
    
}

void free_disciplina_contents(void* disc){
    disciplina* Disciplina = (disciplina*) ((node*) disc)->val;
    node* it = Disciplina->alunos;
    node* prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    free(Disciplina);
}

void free_aluno_contents(void* alu){
    aluno* Aluno = (aluno*) ((node*) alu)->val;
    node* it = Aluno->disciplinas;
    node* prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    free(Aluno);
}

#pragma endregion

#pragma region AreaFunctions
void handle_area_de_alunos(){
    int choice;
    while (1){
        printf("SISTEMA DE MATRICULAS --- AREA DE ALUNOS\n\n"
               "O que voce deseja fazer?\n"
               "  1-??\n"
               "  2-??\n"
               "  0-Retornar ao menu principal\n\n"
               "Escolha: "
        );
        while (scanf("%d", &choice) != 1){
            printf("Escolha Invalida! Apenas numeros inteiros sao aceitos\n\n");
            printf("Escolha: ");
            fflush(stdin);
        }
        fflush(stdin);

        switch (choice){
            case 0:
                return;
            case 1:
                printf("faz ai");
                break;
            case 2:
                printf("faz ai");
                break;
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }
}

void handle_area_de_disciplinas(){
    int choice;
    while (1){
        printf("SISTEMA DE MATRICULAS --- AREA DE DISCIPLINAS\n\n"
               "O que voce deseja fazer?\n"
               "  1-??\n"
               "  2-??\n"
               "  0-Retornar ao menu principal\n\n"
               "Escolha: "
        );
        while (scanf("%d", &choice) != 1){
            printf("Escolha Invalida! Apenas numeros inteiros sao aceitos\n\n");
            printf("Escolha: ");
            fflush(stdin);
        }
        fflush(stdin);

        switch (choice){
            case 0:
                return;
            case 1:
                printf("faz ai");
                break;
            case 2:
                printf("faz ai");
                break;
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }
}
#pragma endregion

int main(){
    #pragma region Test
    // node* aluno_list = new_list();
    // node* disc_list = new_list();
    // aluno_list = insert(aluno_list, create_aluno("Ebo", "123", 21018));
    // aluno_list = insert(aluno_list, create_aluno("Biggers", "456", 21023));
    // disc_list = insert(disc_list, create_disciplina("sisdig", "faccao rotava", 10, 1));
    // disc_list = insert(disc_list, create_disciplina("matdisc", "velento", 1024, 0));

    // print_list(disc_list, print_disciplina);
    // print_list(aluno_list, print_aluno);
    
    // printf("ROTAVABALLS\n\n");

    // disc_list = remove_from_list(disc_list, create_disciplina("matdisc", "velento", 1024, 0), cmp_disciplina, free_disciplina_contents);
    // aluno_list = remove_from_list(aluno_list, create_aluno("Biggers", "456", 21023), cmp_aluno, free_aluno_contents);
    // print_list(disc_list, print_disciplina);
    // print_list(aluno_list, print_aluno);

    // printf("rotavaballs");
    #pragma endregion
    
    int choice;

    while (1){
        printf("SISTEMA DE MATRICULAS --- MENU PRINCIPAL\n\n"
           "O que voce deseja fazer?\n"
           "  1-Area de alunos\n"
           "  2-Area de disciplinas\n"
           "  0-Sair\n\n"
           "Escolha: ");
        while (scanf("%d", &choice) != 1){
            printf("Escolha Invalida! Apenas numeros inteiros sao aceitos\n\n");
            printf("Escolha: ");
            fflush(stdin);
        }
        fflush(stdin);

        switch (choice){
            case 0:
                return 0;
            case 1:
                handle_area_de_alunos();
                break;
            case 2:
                handle_area_de_disciplinas();
                break;
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }



    return 0;
}
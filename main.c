#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct aluno {
    char nome[100];
    char cpf[20];
    int codigo;
    node* disciplinas;
} aluno;

typedef struct disciplina {
    char* nome[100];
    char* professor[100];
    int codigo;
    int creditos;
    node* alunos;
} disciplina;

void set_name(char **s, const char *new_name) {
    strncpy(*s, new_name, sizeof(*s) - 1);
    (*s)[sizeof(*s) - 1] = '\0'; // Make sure the string is null-terminated
}

aluno* create_aluno(const char * nome, const char * cpf, const int codigo){
    aluno* new_aluno = (aluno*)malloc(sizeof(aluno));
    set_name(&new_aluno->nome, nome);
    set_name(&new_aluno->cpf, cpf);
    new_aluno->codigo = codigo;
    new_aluno->disciplinas = new_list();
    return new_aluno;
}

disciplina* create_disciplina(const char * nome, const char * professor, const int codigo, const int creditos){
    disciplina* new_disciplina = (disciplina*)malloc(sizeof(disciplina));
    set_name(&new_disciplina->nome, nome);
    set_name(&new_disciplina->professor, professor);
    new_disciplina->codigo = codigo;
    new_disciplina->creditos = creditos;
    new_disciplina->alunos = new_list();
    return new_disciplina;
}

// retorna 0 se for igual e 1 for diferente
int cmp_aluno(void* val1, void* val2) {
    if (((aluno*)val1)->codigo == ((aluno*)val2)->codigo &&
        ((aluno*)val1)->cpf == ((aluno*)val2)->cpf &&
        !strcmp(((aluno*)val1)->nome, ((aluno*)val1)->nome)) {
        return 0;
    } else
        return 1;
}

// retorna 0 se for igual e 1 for diferente
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
    
    printf("Aluno: %s\nCódigo: %d\nCPF: %s\n\n",
           ((aluno*)val)->nome,
           ((aluno*)val)->codigo,
           ((aluno*)val)->cpf);
}

void print_disciplina(void* val) {
    printf("Disciplina: %s\nProfessor: %d\nCódigo: %s\n\nCréditos: %s\n\n",
           ((disciplina*)val)->nome,
           ((disciplina*)val)->professor,
           ((disciplina*)val)->codigo,
           ((disciplina*)val)->creditos);
}

aluno* read_aluno(){
    char nome[100], cpf[20];
    int codigo;
    scanf("%[^\n] %[^\n] %d", nome, cpf, &codigo);
    aluno* new_aluno = create_aluno(nome, cpf, codigo);
    return new_aluno;
}

disciplina* read_disciplina(){
    char nome[100], professor[100];
    int codigo, creditos;
    scanf("%[^\n] %[^\n] %d %d", nome, professor, &codigo, &creditos);
    disciplina* new_disciplina = create_disciplina(nome, professor, codigo, creditos);
    return new_disciplina;
}

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

int main(){
    return 0;
}
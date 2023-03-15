#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


#define NAME_SIZE 100
#define CPF_SIZE 20


typedef struct periodo {
    int ano;
    int semestre;
    node* alunos_cadastrados;
    node* disciplina_cadastradas;
} periodo;

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



periodo* create_periodo(const int ano, const int semestre);
aluno* create_aluno (const char nome[], const char cpf[], const int codigo);
disciplina* create_disciplina (const char nome[], const char professor[], const int codigo, const int creditos);
int cmp_periodo (void* val1, void* val2);
int cmp_aluno (void* val1, void* val2);
int cmp_disciplina (void* val1, void* val2);
void print_periodo(void* val);
void print_aluno (void* val);
void print_disciplina (void* val);


void handle_area_do_periodo (int ano, int semestre, node** alunos_list, node** disciplinas_list);
void handle_area_de_alunos (node** alunos_list, node** disciplinas_list);
void handle_area_de_disciplinas (node** alunos_list, node** disciplinas_list);

void free_periodo_contents(void* periodo_struct);
void free_aluno_contents(void* aluno_struct);
void free_disciplina_contents(void* disciplina_struct);


int scan_int_choice (int choice);
node* register_new_period(node* lista);
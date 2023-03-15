#include "header.h"

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

node* delete_period_from_list(node* lista){
    int ano, semestre;

    printf("Para deletar um periodo existente, especifique o ano e o semestre:\n   Ano: ");
    while (scanf("%d", &ano) != 1){
        printf("Ano Invalido! Apenas numeros inteiros sao aceitos.\n\n");
        printf("   Ano: ");
        fflush(stdin);
    }
    fflush(stdin);

    printf("   Semestre: ");
    while (scanf("%d", &semestre) != 1 || !(semestre == 1 || semestre == 2)){
        printf("Semestre Invalido! Apenas numeros inteiros (1 ou 2) sao aceitos.\n\n");
        printf("   Semestre: ");
        fflush(stdin);
    }
    fflush(stdin);

    node* it = lista;
    node* prev = NULL;
    while(it != NULL){
        if(((periodo*)(it->val))->ano == ano && ((periodo*)(it->val))->semestre == semestre) break;
        else{
            prev = it;
            it = it->next;
        }
    }

    if(it == NULL){
        printf("\nPeriodo %d.%d nao encontrado. procure os periodos na opcao \"1\".\n\n"
               "O periodo especificado nao foi removido", ano, semestre);
        return lista;
    }
    else{
        if(prev == NULL) lista = it->next;
        else prev->next = it->next;
        free_periodo_contents(it->val);
        free(it);
        return lista;
    }
}

#pragma endregion



//IMPORTANTE: TODAS AS FUCOES 'create-*();', APOS CHAMADAS, DEVEM SER SEGUIDAS (EM ALGUM PONTO NO CODIGO) POR 'free();'
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
    //Ao inves de ser uma lista nova, verificar o arquivo e importar a lista do arquivo
    node* periodos_list = new_list();
    node* alunos_list = new_list();
    node* disciplinas_list = new_list();

    while (1){
        printf("SISTEMA DE MATRICULAS --- MENU PRINCIPAL\n\n"
           "O que voce deseja fazer?\n"
           "  1-Listar todos os periodos\n"
           "  2-Registrar um periodo\n"
           "  3-Acessar um periodo\n"
           "  4-Deletar um periodo\n"
           "  0-Sair\n\n"
           "Escolha: "
        );

        switch (choice = scan_int_choice(choice)){
            case 0:
                return 0;
            case 1:
                if(periodos_list == NULL) printf("Nao ha periodos disponiveis! Registre um novo periodo com a opcao \"2\".\n\n");
                else print_list(periodos_list, print_periodo);
                break;
            case 2:
                periodos_list = register_new_period(periodos_list);
                break;
            case 3:
                handle_area_do_periodo(2023, 1, &alunos_list, &disciplinas_list);
                break;
            case 4:
                periodos_list = delete_period_from_list(periodos_list);
                break;
            case 5:
                handle_area_de_alunos(&alunos_list, &disciplinas_list);
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }


    return 0;
}



#pragma region EberFunctions (terminadas)

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


#pragma region BigoFunctions (terminadas)

periodo* create_periodo(const int ano, const int semestre){
    periodo* new_periodo = (periodo*) malloc(sizeof(periodo));

    new_periodo->ano = ano;
    new_periodo->semestre = semestre;
    new_periodo->alunos_cadastrados = new_list();
    new_periodo->disciplina_cadastradas = new_list();

    return new_periodo;
}

void print_periodo(void* val){
    printf("%d.%d\n", 
        ((periodo* ) val)->ano,
        ((periodo* ) val)->semestre
    );
}

int cmp_periodo(void* val1, void* val2){
    periodo* a = (periodo*) val1;
    periodo* b = (periodo*) val2;
    if(a->ano == b->ano && a->semestre == b->semestre) return 0;
    else return 1;
}

int scan_int_choice(int choice){
    while (scanf("%d", &choice) != 1){
        printf("Escolha Invalida! Apenas numeros inteiros sao aceitos\n\n");
        printf("Escolha: ");
        fflush(stdin);
    }
    fflush(stdin);
    return choice;
}

node* register_new_period(node* lista){
    int ano, semestre;

    printf("Para registrar um novo periodo, especifique o ano e o semestre:\n   Ano: ");
    while (scanf("%d", &ano) != 1){
        printf("Ano Invalido! Apenas numeros inteiros sao aceitos.\n\n");
        printf("   Ano: ");
        fflush(stdin);
    }
    fflush(stdin);

    printf("   Semestre: ");
    while (scanf("%d", &semestre) != 1 || !(semestre == 1 || semestre == 2)){
        printf("Semestre Invalido! Apenas numeros inteiros (1 ou 2) sao aceitos.\n\n");
        printf("   Semestre: ");
        fflush(stdin);
    }
    fflush(stdin);

    periodo* new_periodo = create_periodo(ano, semestre);

    if(search(lista, new_periodo, cmp_periodo)){
        printf("\nJa existe o periodo %d.%d! Verifique com a opcao as opcoes \"1\" e \"3\", ou tente novamente com a opcao \"2\".\n"
               "O periodo especificado nao foi adicionado.\n\n", ano, semestre);
        free(new_periodo);
        return lista;
    }
    else{
        printf("\nO periodo %d.%d foi adicionado com sucesso!\n\n", ano, semestre);
        return (insert(lista, new_periodo));
    }
}

void free_periodo_contents(void* periodo_struct){
    node* it = ((periodo*) periodo_struct)->disciplina_cadastradas;
    node* prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    it = ((periodo*) periodo_struct)->alunos_cadastrados;
    prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    free((periodo*) periodo_struct);
}

void free_aluno_contents(void* aluno_struct){
    node* it = ((aluno*) aluno_struct)->disciplinas;
    node* prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    free((aluno*) aluno_struct);
}

void free_disciplina_contents(void* disciplina_struct){
    node* it = ((disciplina*) disciplina_struct)->alunos;
    node* prev = NULL;
    while (it != NULL){
        prev = it;
        it = it->next;
        free(prev);
    }
    free((disciplina*) disciplina_struct);
}

#pragma endregion


#pragma region AreaFunctions (em progresso)
//The lists are passed by reference so they can be altered outside the scope of the function, so the argument is a pointer to the head pointer
void handle_area_do_periodo(int ano, int semestre, node** alunos_list, node** disciplinas_list){
    int choice;
    while (1){
        printf("SISTEMA DE MATRICULAS --- PERIODO %d.%d\n\n"
           "O que voce deseja fazer?\n"
           "  1-Area de alunos\n"
           "  2-Area de disciplinas\n"
           "  0-Retornar ao Menu Principal\n\n"
           "Escolha: "
           , ano, semestre);

        switch (choice = scan_int_choice(choice)){
            case 0:
                return;
            case 1:
                handle_area_de_alunos(alunos_list, disciplinas_list);
                break;
            case 2:
                handle_area_de_disciplinas(alunos_list, disciplinas_list);
                break;
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }
}

void handle_area_de_alunos(node** alunos_list, node** disciplinas_list){
    int choice;
    while (1){
        printf("SISTEMA DE MATRICULAS --- AREA DE ALUNOS\n\n"
               "O que voce deseja fazer?\n"
               "  1-Mostrar os alunos cadastrados\n"
               "  2-Cadastrar Eber\n"
               "  3-Cadastrar Bigger\n"
               "  0-Retornar ao menu do periodo\n\n"
               "Escolha: "
        );

        switch (choice = scan_int_choice(choice)){
            case 0:
                return;
            case 1:
                print_list(* alunos_list, print_aluno);
                break;
            case 2:
                * alunos_list = insert(* alunos_list, create_aluno("Ebo", "123", 21018));
                break;
            case 3:
                * alunos_list = insert(* alunos_list, create_aluno("Biggers", "456", 21023));
                break;
            default:
                printf("Nao ha opcoes correspondentes a sua escolha\n\n");
                break;
        }
    }
}

void handle_area_de_disciplinas(node** alunos_list, node** disciplinas_list){
    int choice;
    while (1){
        printf("SISTEMA DE MATRICULAS --- AREA DE DISCIPLINAS\n\n"
               "O que voce deseja fazer?\n"
               "  1-??\n"
               "  2-??\n"
               "  0-Retornar ao menu do periodo\n\n"
               "Escolha: "
        );

        switch (choice = scan_int_choice(choice)){
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
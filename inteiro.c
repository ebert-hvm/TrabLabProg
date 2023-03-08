#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

typedef struct inteiro {
    int val;
} inteiro;

int cmp(void * val1, void * val2){
    if(((inteiro*)val1)->val < ((inteiro*)val2)->val) return -1;
    else if(((inteiro*)val1)->val == ((inteiro*)val2)->val) return 0;
    else return 1;
}

void print_inteiro(void * val){
    printf("%d ", ((inteiro*)val)->val);
}

void do_nothing(void * val){
    printf("cock\n");
}

int main() {
    node* list = new_list();
    int n;
    scanf("%d", &n); 

    while(n--)
    {
        inteiro * temp = (inteiro*)malloc(sizeof(inteiro));
        scanf("%d", &(temp->val));
        list = insert(list, temp);
    }
    print_list(list, print_inteiro);
    inteiro * temp = (inteiro*)malloc(sizeof(inteiro));
    scanf("%d", &n);
    if(search(list, &n, cmp)) printf("ta na lista\n");
    else printf("nao ta na lista\n");
    scanf("%d", &n);
    list = remove_from_list(list, &n, cmp, do_nothing);
    print_list(list, print_inteiro);
}
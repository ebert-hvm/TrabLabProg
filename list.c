#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

static node* create_node(void * val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

//Freeing the node does not free its contents. A specific free funtion wil be needed for each of the node types (aluno, disciplina)
static void free_node(node* nd) {
    free(nd);
}

node* new_list(){
    return NULL;
}

node* insert(node* head, void * val) {
    // returns the head of the list
    node* new_node = create_node(val);
    if (head == NULL) {
        return new_node;
    }
    new_node->next = head;
    return new_node;
}

bool search(node* head, void * val, int (*cmp)(void *, void *)) {
    node* it = head;
    while (it != NULL) {
        if (!cmp(it->val, val)) return true;
        it = it->next;
    }
    return false;
}

node* remove_from_list(node* head, void * val, int (*cmp)(void *, void *), void (*free_node_contents)(void *)) {
    if (!search(head, val, cmp)) return head;
    node* it = head;
    node* prev = NULL;
    while (it != NULL) {
        if(!cmp(it->val, val)){
            node* next = it->next;
            free_node_contents(it->val);
            free_node(it);
            if (prev == NULL) head = next;
            else prev->next = next;
            break;
        }
        prev = it;
        it = it->next;
    }
    return head;
}

void print_list(node* head, void (*print)(void *)) {
    node* it = head;
    while (it != NULL) {
        print(it->val);
        it = it->next;
    }
    printf("\n");
}

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

static void remove_node(node* nd) {
    nd->next = NULL;
    free(nd);
    nd = NULL;
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

node* remove(node* head, void * val, int (*cmp)(void *, void *)) {
    if (!list_search(head, val, cmp)) return head;
    node* it = head;
    node* prev = NULL;
    while (it != NULL) {
        if(!cmp(it->val, val)){
            node* next = it->next;
            remove_node(it);
            if (prev == NULL) head = next;
            else prev->next = next;
            break;
        }
        prev = it;
        it = it->next;
    }
    return head;
}

void recover(node* head, void (*print)(void *)) {
    node* it = head;
    while (it != NULL) {
        print(it->val);
        it = it->next;
    }
    printf("\n");
}

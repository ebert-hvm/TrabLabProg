#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct node {
    void * val;
    struct node* next;
} node;

static node* create_node(void * val);
static void remove_node(node* nd);
node* new_list();
node* insert(node* head, void * val);
bool search(node* head, void * val, int (*cmp)(void *, void *));
node* remove_from_list(node* head, void * val, int (*cmp)(void *, void *), void (*free_node_contents)(void *));
void print_list(node* head, void (*print)(void *));

#endif
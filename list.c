
#include "list.h"

void init(list *l) {
    *l = NULL;
    return;
}

int isempty(list l){
    if(l == NULL)
        return 1;
    else
        return 0;
 }

void destroy_list(list *l){
    list_node *p = *l;
    list_node * q;
    q = p;
    while(p){
        p = p->next;
        free(q);
    }
    *l = NULL;
    return ;
}

void traverse(list l){
    printf("[");
    list_node *p;
    p = l;
    while(p){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");
    return;
}


int get_next(list *l){ /*removes and returns 1st element*/
    list p = *l;
    if(!p)
        return INT_MAX;
    int k = p->data;
    *l = p->next;
    free(p);
    return k;
}

int touch(list l) {
    if(!l)
        return INT_MAX;
    return l->data;
}

void insert_beg(list *l, int d){
    list newnode;
    newnode = (list_node*)malloc(sizeof(list_node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    newnode->next = *l;
    *l = newnode;
    return;
}

void append(list *l, int d){
    list p, newnode;
    newnode = (list_node*)malloc(sizeof(list_node));
    if(newnode){
        newnode->data = d;
        newnode->next = NULL;
    }
    else return;
    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;
    while(p -> next) {
       p = p->next;
    }
    p->next = newnode;
    return;
}

/*
int main() {
    list L1, L2;
    init(&L1);

    int ch;
    while ((ch = getchar()) != '\n') {
      append(&L1, ch);
   }

	traverse(L1);
	printf("%d\n", peek(L1));
	return 0;
}*/

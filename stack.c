#include <stdio.h>
#include <stdlib.h>
#include "num.h"
#include "stack.h"

void init_Big_stack(Big_stack *s) {
	(*s) = NULL;
}

void init_char_stack(char_stack *s) {
        (*s) = NULL;
}


void push_Big_N(Big_stack *head, Big_N num) {
        Big_stack nn;
        nn = (Big_node*)malloc(sizeof(Big_node));
        if(nn) {
                nn->num = num;
                nn->next = NULL;
	}
        else return;

        if(*head == NULL) {
                *head = nn;
                return;
	}
        nn->next = *head;
        *head = nn;
        return;
}

void push_char(char_stack *head, char num) {
        char_stack nn;
        nn = (char_node*)malloc(sizeof(char_node));
        if(nn) {
                nn->num = num;
                nn->next = NULL;
        }
        else return;

        if(*head == NULL) {
                *head = nn;
                return;
        }
        nn->next = *head;
        *head = nn;
        return;
}


Big_N pop_Big_N(Big_stack *head) {
        Big_N empty, num;
        Big_stack temp;
        /*To indicate stack is empty*/
        empty.sign = -1;
        if (*head == NULL)
            /*current token*/
                return empty;
        temp = *head;
        num = (*head)->num;
        *head = (*head)->next;
        free(temp);
        return num;
}

char pop_char(char_stack *head) {
	char empty, num;
	char_stack temp;
	/*To indicate stack is empty*/
	empty = 255;
	if (*head == NULL)
		return empty;
	temp = *head;
	num = (*head)->num;
	*head = (*head)->next;
	free(temp);
	return num;
}



Big_N peek_Big_N(Big_stack st) {
	if(st)
		return st->num;
	else{
		Big_N tmp;
		tmp.sign = -128;
		return tmp;
	}
}

char peek_char(char_stack st) {
        if(st)
                return st->num;
	else return -128;
}


int isEmpty_Big_N(Big_stack st) {
        if(peek_Big_N(st).sign == -128)
                return 1;
	else return 0;
}

int isEmpty_char(char_stack st) {
	if(peek_char(st) == -128){
		return 1;}
	else return 0;
}

/*
int main() {
	char num, temp, tt;
	num = 60;
	tt = 67;
	char_stack st;
	init_char_stack(&st);
	push_char(&st, num);
	push_char(&st, tt);

	printf("%d\n",pop_char(&st));
	printf("%d\n",pop_char(&st));
	if(isEmpty_char(st))
		printf("full");
	//printf("%d", temp.sign);
	return 0;
}*/

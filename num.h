#ifndef NUM_H
#define NUM_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Structure of Doubly Linked List
typedef struct node {
    // To store a single digit
    char data;
    // Pointers to the previous and next digit
    struct node* next;
    struct node* prev;
} node;

//structure to store information of big number and head pointer.
typedef struct Big_N {
        int size;
        // 0 for +ve and 1 for -ve
        char sign;
	// head pointer to big number linked list
        node *head;
	// tail pointer to big number linked list
        node *tail;
} Big_N;


// to indicate error and exit from loop
extern int cont;


// to init head structure of big number
void init_num(Big_N *num);

// to change the sign of number
void neg(Big_N *num);

void rem_lead_zeros(Big_N *num);

// to free corresponding big number linked list
void destroy(Big_N *num);

/*To display the number.*/
void display(Big_N num);

// To insert at the beginning of the list
void insertInFront(Big_N *num, int value);

// To insert in the end
void insertInEnd(Big_N *num, int value);

// Returns the number of digits
int length(Big_N num);

// This compares the two numbers and returns
// 1 when 1st is greater, 2 when 2nd is greater and
// 0 when both numbers are ezual
int compare(Big_N a, Big_N b);

/* Uses simple addition method that we
   follow using carry*/
Big_N add(Big_N *a, Big_N *b);

// Normal subtraction is done by borrowing
Big_N sub(Big_N *a, Big_N *b);

// Normal multiplication is used i.e. in one to all way
Big_N mult(Big_N *a, Big_N *b);

Big_N power(Big_N base, Big_N exp);

// Performs two works, choice = 0 for normal division,
// choce = 1 for modulo operation.              //TODO try to remove first part
Big_N division(Big_N *l, Big_N *m);

Big_N modulo(Big_N *l, Big_N *m);

Big_N changeBase(Big_N num, int k);

Big_N toDeci(list *L, int b);

Big_N fact(Big_N *a);

Big_N gcd(Big_N a1, Big_N b1);

Big_N lcm(Big_N *a, Big_N *b);

#endif


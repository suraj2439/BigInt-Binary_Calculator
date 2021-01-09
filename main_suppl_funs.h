#ifndef MAIN_SUPPL_FUNS_H
#define MAIN_SUPPL_FUNS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "num.h"
#include "stack.h"
#include "list.h"

/*structure to mantain token information*/
typedef struct get_info {
	/*info of input base*/
        char inp_base;
	/*infor of output base*/
        char out_base;
	/*set flag for unary sign*/
        char unary_neg;
	/*set flag for right associative operator*/
        char r_ass;
	/*info of previous token*/
        char prev_token;
	/*info of current token*/
        char token;
	/*info of next token*/
        char next_token;
} get_info;


/*to set flag if error is 
 * present in expression*/
extern int cont;

/*init token information i.e. init get_info structure*/
void init_info(get_info *info);

/*return precedence value of operator(manually given)*/
int precedence(char c);

/*set flag if error is present in expression*/
void error(char prev, char next);

/*return 1 if token is operator,
 * else return 0*/
int isOperator(char c);

/*evaluate one operation given two operands and one operator*/
Big_N eval(Big_N *op1, Big_N *op2, char operan);

/*use to get next token after eliminating spaces*/
int get_token(get_info *info, list *inp);

void handle_tokens(get_info *info, list *inp, Big_stack *val);


#endif

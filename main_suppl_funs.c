#include "main_suppl_funs.h"

void init_info(get_info *info) {
        info->inp_base = 10;
        info->out_base = 10;
        info->unary_neg = 0;
        info->r_ass = 0;
        info->prev_token = 0;
        /*To handle first unary negative sign*/
        info->token = '+';
        info->next_token = 0;
        return;
}


int precedence(char c) {
    switch(c) {
        case '(':
                return 5;
        case '+':
                return 10;
        case '-':
                return 10;
        case '*':
                return 20;
        case '/':
                return 20;
        case '%':
                return 20;
        case '^':
                return 30;
        case 'L':
                return 40;
        case 'H':
                return 40;
        default:
                return 0;

    }
}


void error(char prev, char next) {
        printf("Syntax Error\n");
	printf("TYPE: wrong operator '%c', after '%c'.\n", next, prev);
	cont = 1;
        //exit(1);
}


int isOperator(char c) {
	switch(c) {
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
                        return 1;
                case '/':
                        return 1;
		case '%':
                        return 1;
                case '^':
                        return 1;
		case 'L':
			return 1;
		case 'H':
			return 1;
		default:
			return 0;
	}
}

Big_N eval(Big_N *op1, Big_N *op2, char operan) {
        switch(operan){
                case('+'):
                        return add(op1, op2);
                case('-'):
                        return sub(op1, op2);
                case('*'):
                        return mult(op1, op2);
                case('/'):
                        return division(op1, op2);
		case('%'):
                        return modulo(op1, op2);
		case('^'):
                        return power(*op1, *op2);
		case('L' ):
			return lcm(op1, op2);
		case('H'):
			return gcd(*op1, *op2);
        }
}


int get_token(get_info *info, list *inp) {
        info->prev_token = info->token;
        for( ; touch(*inp) != '\0' && touch(*inp) == ' '; get_next(inp));
        info->token = get_next(inp);
        for( ; touch(*inp) != '\0' && touch(*inp) == ' '; get_next(inp));
        info->next_token = touch(*inp);
        return 0;
}


void handle_tokens(get_info *info, list *inp, Big_stack *val) {
        switch(info->token) {
                case '/':
                        if(isOperator(info->prev_token))
                                error(info->prev_token, info->token);
			break;
                case '*':
                        if(isOperator(info->prev_token))
                                error(info->prev_token, info->token);
			break;
		case 'L':
                        if(isOperator(info->prev_token))
                                error(info->prev_token, info->token);
			break;
		case 'H':
                        if(isOperator(info->prev_token))
                                error(info->prev_token, info->token);
			break;
		case '^':
                        if(isOperator(info->prev_token))
                                error(info->prev_token, info->token);
			break;
                case '-':
                        if(isOperator(info->prev_token) && isdigit(info->next_token)) {
                                info->unary_neg = 1;
                                info->token = info->next_token;
                                info->next_token = get_token(info, inp);
                        }
                        else if(isOperator(info->prev_token) && isOperator(info->next_token))
                                error(info->prev_token, info->token);
                        break;
                case '+':
                        if(isOperator(info->prev_token) && isdigit(info->next_token)) {
                                info->token = info->next_token;
                                info->next_token = get_token(info, inp);
                        }
                        else if(isOperator(info->prev_token) && isOperator(info->next_token))
                                error(info->prev_token, info->token);
                        break;
                case '\0':
                        if(isOperator(info->prev_token)) { 
                        	printf("Syntax Error.\n");
                 		printf("TYPE: Unterminated operator '%c'\n", info->prev_token);
                               cont = 1;
                               return;
                        }
                        break;
		case '!': {
				if(isOperator(info->prev_token))
                                	error(info->prev_token, info->token);

				Big_N hcf = pop_Big_N(val);
				push_Big_N(val, fact(&hcf));

				info->token = info->next_token;
                                info->next_token = get_token(info, inp);
				break;
			}
                case '<':
                        {
                        char tmp;
                        /*prev token should be operator if not-error*/
                        if(! isOperator(tmp = info->prev_token))
                                error(info->prev_token, info->token);
                        get_token(info, inp);
                        if(info->token != 'I') {
                                printf("Syntax Error");
                                printf("TYPE: 'I' is necessry after '<' \n");
                                cont = 0;
                                return;
                        }
			/*to remove '<' token*/
                        get_token(info, inp);
                        if(isdigit(info->token))
                                info->inp_base = info->token - '0';
                        get_token(info, inp);
			/*if input base is 2 digit no*/
                        if(isdigit(info->token)){
                                info->inp_base = (info->inp_base)*10 + (info->token - '0');
                                get_token(info, inp);
                        }

			/*to remove '>' token*/
                        if(info->token == '>')
                                get_token(info, inp);
                        else {
                        	printf("Syntax Error");
                        	printf("TYPE: '>' is necessry after '<' \n");
                        	cont = 0;
                        	return; 
                        }

                        list M;
                        init(&M);
                        while(isdigit(info->token) || (info->token >= 'A' && info->token <='Z')) {
                                insert_beg(&M, info->token);
                                get_token(info, inp);
                        }
                        push_Big_N(val, toDeci(&M, info->inp_base));
                        info->prev_token = tmp;
                        break;
                        }
        }
        return;
}


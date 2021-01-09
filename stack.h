
typedef struct Big_node{
        Big_N num;
        struct Big_node* next;
} Big_node;

typedef struct char_node{
        char num;
        struct char_node* next;
} char_node;


typedef Big_node* Big_stack;

typedef char_node* char_stack;



void init_Big_stack(Big_stack *s);
void init_char_stack(char_stack *s);

void push_Big_N(Big_stack *head, Big_N num);
void push_char(char_stack *head, char num);

Big_N pop_Big_N(Big_stack *head);
char pop_char(char_stack *head);

Big_N peek_Big_N(Big_stack st);
char peek_char(char_stack st);

int isEmpty_Big_N(Big_stack st);
int isEmpty_char(char_stack st);

typedef struct stackNode
{
    char* value;
    struct stackNode *next;
} stack;

typedef stack* node;

void push(node* head, char* val);
char* pop(node* head);

float calculate(char* expression);

typedef struct Stack {
	int  value;
	struct Stack* next;
}stack;
void push(struct Stack** head, int value);
int pop(struct Stack** head);
int not_exists(struct Stack* head, int val);
int gethead(struct Stack* head);
void print_stack(struct Stack* head);



#include <stdlib.h>
#include "stack.h"
#include <stdio.h>


void push(struct Stack **head, int value){
    struct Stack *tmp = malloc(sizeof(struct Stack));
    if(tmp == NULL){
        exit(-1);
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}

int pop( struct Stack **head){
    struct Stack *away;
    int value;
    if(*head == NULL){
        exit(-2);
    }
    away = *head;
    *head = (*head)->next;
    value = away->value;
    free(away);
    return value;
}



/*int size(struct node *head){
    int s = 0;
    while (head){
        s++;
        head = head->next;
    }
    return s;
}*/

int not_exists(struct Stack *head, int val){
    while (head){
        if(head->value == val){
            return 0;
        }
        head = head->next;
    }
    return 1;
}


int gethead(struct Stack* head) {
    if (head == NULL) {
        exit(-3);
    }
    return head->value;
}

void print_stack(struct Stack* head) {
    while (head) {
        printf("%d  ", head->value);
        head = head->next;
    }
}
#include <time.h>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int randint(const int min, const int max) {
	return rand() % (max - min + 1) + min;
}

int main() {

	struct Stack* onestack = NULL;
	struct Stack* toostack = NULL;
	struct Stack* answerstack = NULL;
	int i;
	int stack1size = randint(1, 15);
	int stack2size = randint(1, 15);
	int prevrand1 = 0;
	int prevrand2 = 0;

	for (i = 0; i < stack1size; i++) {
		prevrand1 = randint(1 + prevrand1, 5 + prevrand1);
		push(&onestack, randint(prevrand1, 5 + prevrand1));
	}
	for (i = 0; i < stack2size; i++) {
		prevrand2 = randint(prevrand2, 5 + prevrand2);
		push(&toostack, randint(1 + prevrand2, 5 + prevrand2));
	}

	printf("\n");
	printf("first stack: ");
	print_stack(onestack);
	printf("\n");
	printf("second stack: ");
	print_stack(toostack);
	printf("\n");

	while (onestack || toostack) {
		if (onestack && !toostack) {
			if (not_exists(answerstack, gethead(onestack))) {
				push(&answerstack, pop(&onestack));
			}
			else { pop(&onestack); }
		}
		if (toostack && !onestack) {
			if (not_exists(answerstack, gethead(toostack))) {
				push(&answerstack, pop(&toostack));
			}
			else { pop(&toostack); }
		}
		if (onestack && toostack) {
			if (not_exists(answerstack, gethead(onestack)) && not_exists(answerstack, gethead(toostack))) {
				if (gethead(onestack) > gethead(toostack)) {
					push(&answerstack, pop(&onestack));
				}
				else {
					push(&answerstack, pop(&toostack));
				}
			}
			else {
				if (!not_exists(answerstack, gethead(onestack))) {
					pop(&onestack);
				}
				if (!not_exists(answerstack, gethead(toostack))) {
					pop(&toostack);
				}
			}
		}
	}
	printf("\n");
	printf("Answer stack: ");
	print_stack(answerstack);
	(void)_getch();


	return 0;
}
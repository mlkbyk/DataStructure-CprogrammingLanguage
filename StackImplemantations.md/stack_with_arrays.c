//file:stack_with_arrays.c
//Creating stack with array 
#include<stdio.h>
#define N 500 //max elements that stack can have 
int S[N];//array that acts like stack
int sp = 0;//stack pointer

//function declaritions
int push(int item);
int pop();
void reset();
int top();
int size();
int isEmpty();

//program execution begigs with main function
int main() {
	printf("Enter the text that you want to writing it out backwards:\n");
	char c;
	while ((c = getchar()) != '\n') {
		push(c);

	}
	while (sp > 0) {
		printf("%c", pop());

	}
	printf("\n");

	return 0;//end main function
}

//function definitions

//function that add item to the stack
int push(int item) {
	if (sp >= N) {
		printf("Stack is full.Value cannot be inserted.");
		return -1;
	}
	else{
		S[sp] = item;
		sp++;
		return 0;

	}
}

//remove element from the stack 
int pop() {
	if (sp <= 0) {
		printf("Stack is empty.\n");
		return -1;
	}
	else {
		sp--;
		return S[sp];
	}

}

//empty the stack
void reset() {
	sp = 0;
}

//returns the reference to the last
//instered element without removing it
int  top() {
	return (sp - 1);
}

int size() {//return the elements that stored
	return sp;
}

//returns 1 if no elements are stored
//returns 0 otherwise
int isEmpty() {
	if (sp == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

#include <stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* top = NULL;

int isempty(){
     return top == NULL;
}

void push(int value){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

int pop() {
	if (isempty()) {
		printf("Stack UnderFlow\n");
		return -1;
	}
	struct node* temp = top;
	int val = temp->data;
	top = top->next;
	free(temp);
	return val;
}

int peek(){
	if (isempty()) {
		printf("Stack UnderFlow\n");
		return -1;
	}
	return top->data; 
}

void display(){
	struct node* temp = top;
	while(temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
	push(10);
	push(20);
	push(30);
	display();
	printf("top is %d\n", peek());
	pop();
	display();
}
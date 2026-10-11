#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node* nodeptr;

struct node* head = NULL;

void InsertatBegin(int value){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = head;
	head = newnode;
}
 
void InsertEnd(int value){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	if(head == NULL){
		head = newnode;
		return;
	}
	struct  node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;	
	temp->next = newnode;
} 

void InsertatPosition(int value, int position){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	
	if(position == 1){
		newnode->next = head;
		head = newnode;
		return;
	}
	
	struct node* temp = head;
	for(int i = 1; i < position-1 && temp != NULL; i++)
	    temp = temp->next;
	
	if (temp == NULL){
		printf("position out of range\n");
		free(newnode);
		return;
	}    
	
	newnode->next = temp->next;
	temp->next = newnode;
}

void DeleteatBegin(){
    if(head == NULL) return;
	struct node* temp = head;
	head = head->next;
	free(temp);	
}

void DeleteatEnd(){
	if(head == NULL) return;
	
	if(head->next == NULL){
		free(head);
		head = NULL;
		return;
	}
	
	struct node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

void DeleteatPosition(int position){
	if(head == NULL) return;
	
	struct node* temp = head;
	if(position == 1){
		head = temp->next;
		free(temp);
		return;
	}
	
	struct node* prev = NULL;
	for(int i = 1; i < position-1 && temp != NULL;i++){
		prev = temp;
		temp = temp->next;
	}
	
	if(temp == NULL){
		printf("position out of range\n");
		return;
	}
	
	prev->next = temp->next;
	free(temp);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main(){
	display();
	InsertatBegin(20);
	InsertatBegin(10);
	InsertEnd(30);
	display();
	DeleteatEnd();
	DeleteatPosition(3);
	DeleteatBegin();
	display();
	InsertatPosition(5,1);
	display();
	return 0;
}






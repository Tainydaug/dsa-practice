#include<stdio.h>
#include<stdlib.h>

struct cslinklist{
	int data;
	struct cslinklist* next;
};

typedef struct cslinklist node;

node* start = NULL;

int nodectr;

node* getnode(){
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
return newnode;
}

int menu(){
    int ch;
    printf("\n 1. Create a list ");
    printf("\n\n");
    printf("\n 2. Insert a node at beginning ");
    printf("\n 3. Insert a node at end");
    printf("\n 4. Insert a node at middle");
    printf("\n\n ");
    printf("\n 5. Delete a node from beginning");
	printf("\n 6. Delete a node from Last");
	printf("\n 7. Delete a node from Middle");
	printf("\n\n ");
	printf("\n 8. Display the list");
	printf("\n 9. Exit");
	printf("\n\n ");
	printf("\n Enter your choice: ");
	scanf("%d", &ch);
return ch;
}

void createlist(int n){
	int i;
	node *newnode;
	node *temp;
	nodectr = n;
	for(i=0;i<n;i++){
		newnode = getnode();
		if(start==NULL){
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp->next!=NULL)
				temp = temp->next;
			temp->next = newnode;	
		}
	}
	newnode->next = start;
}

void display(){
	node *temp;
	temp = start;
	printf("\n The contents of List (Left to Right): ");
	if (start==NULL){
		printf("\n Empty List\n");
	}
	else{
		do{
			printf("%d -> ", temp->data);
			temp = temp->next;
		}while(temp!=start);
		printf("X\n");
	}
}

void insert_beg(){
	node *newnode, *last;
	newnode = getnode();
	if(start==NULL){
		start = newnode;
		newnode->next = start;
	}
	else{
		last = start;
		while(last->next!=start)
			last = last->next;
		newnode->next = start;
		start = newnode;
		last->next = start;	
	}
	printf("\n Node inserted at Beginning..\n");
	nodectr++;
}

void insert_end(){
	node *newnode, *temp;
	newnode = getnode();
	if(start==NULL){
		start = newnode;
		newnode->next = start;
	}
	else{
		temp = start;
		while(temp->next != start)
			temp = temp->next;
		temp->next = newnode;
		newnode->next = start;	
	}
	printf("\n Node inserted at end..\n");
	nodectr++; 	
}

void insert_mid(){
	node *newnode, *temp, *prev;
	int i, pos;
	newnode = getnode();
	printf("\n Enter the position: ");
	scanf("%d", &pos);
	if(pos > 1 && pos < nodectr){
		temp = start;
		prev = temp;
		i = 1;
		while(i < pos){
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = newnode;
		newnode->next = temp;
		nodectr++;
		printf("\n Node inserted at Middle..\n");
	}
	else{
		printf("postion %d of list is not a middle position\n", pos);
	}
}

void delete_beg(){
	node *temp, *last;
	if(start == NULL){
    	printf("\n No nodes exist..\n");
		return ;
	} 
	else{
		last = temp = start;
		while(last->next != start)
			last = last->next;
		start = start->next;
		last->next = start;
		free(temp);
		nodectr--;
		printf("\n Node deleted..\n");
		if(nodectr == 0)
			start = NULL;
	}	
}

void delete_end(){
	node *temp, *prev;
	if(start == NULL){
    	printf("\n No nodes exist..\n");
		return ;
	} 
	else{
		temp = start;
		prev = start;
		while(temp->next != start){
			prev = temp;
			temp = temp->next;
		}
		prev->next = start;
		free(temp);
		nodectr--;
		if(nodectr == 0)
			start = NULL;
		printf("\n Node deleted..\n");
	}
}

void delete_mid(){
	node *temp, *prev;
	int i = 0, pos;
	if(start == NULL){
    	printf("\n No nodes exist..\n");
		return ;
	} 
	else{
		printf("\n Which node to delete: ");
        scanf("%d", &pos);
		if(pos > nodectr){
			printf("\n This node does not exist\n");
			return;
		}
		if(pos > 1 && pos < nodectr){
			temp = start;
			prev = temp;
			i = 0;
		while(i < pos-1){
			prev = temp;
			temp = temp->next;
			i++;
		}
		prev->next = temp->next;
		free(temp);
		nodectr--;
		printf("\n Node Deleted..\n");
		}
		else{
		printf("\n It is not a middle position..\n");
		}
	}
}

void main(void){
	int result;
	int ch, n;
	while(1){
		ch = menu();
		switch(ch){
			case 1 :
				if(start == NULL){
					printf("\n Enter Number of nodes to create: ");
					scanf("%d", &n);
					createlist(n);
					printf("\n List created..\n");
				}
				else{
					printf("\n List is already Exist\n");
				}
				break;
			case 2 :
				insert_beg();
				break;
			case 3 :
				insert_end();
				break;
			case 4 :
				insert_mid();
				break;
			case 5 :
				delete_beg();
				break;
			case 6 :
				delete_end();
				break;
			case 7 :
				delete_mid();
				break;
			case 8 :
				display();
				break;
			case 9 :
				exit(0);	
		}
	}
}

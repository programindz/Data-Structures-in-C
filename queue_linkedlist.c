#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void push(struct node **head, int val){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	
	if(*head == NULL){
		*head = newNode;
	}
	else{
		struct node *temp = *head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
void pop(struct node **head){
	struct node *temp = *head;
	if(temp == NULL){
		printf("Nothing to Pop.");
	}
	else{
		*head = (*head)->next;
		free(temp);
	}
	
}
int searchNode(struct node *head, int key){
	struct node *temp= head;
	while(temp != NULL){
		if(temp->data == key)
			return 1;
		temp = temp->next;
	}
	return -1;
}

void display(struct node *head){
	struct node *temp = head;
	printf("\nQueue is: ");
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

main(){
	struct node *head = NULL;
	
	push(&head, 2);
	push(&head, 4);
	push(&head, 6);
	display(head);
	pop(&head);
	printf("\n");
	display(head);
	int t = searchNode(head, 6);
	if(t == 1)
		printf("\nNode Found");
	else
		printf("\nNode Not Found");
}




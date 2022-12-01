#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head = NULL;
int nodeNumber = 0;

void insertAtPosition(int val, int pos){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	
	int count = 0;
	if(head == NULL){
		head = newNode;
		newNode->next = head;
		nodeNumber++;
	}
	else{
		struct node *current = head;
		struct node *prev = NULL;
		
		while(count < pos){
			prev = current;
			current = current->next;
			count++;
		}
		newNode->next = current;
		prev->next = newNode;
		nodeNumber++;
	}
}

void nextElement(int data){
	struct node *temp = head;
	while(temp->data != data){
		temp = temp->next;
	}
	printf("\nNext element of %d is: %d", data, temp->next->data);
}

void display(){
	if(head == NULL)
		printf("Nothing to display.\n");
	else{
		struct node *temp = head;
		int count;
		while(count != nodeNumber){
			printf("%d->", temp->data);
			temp = temp->next;
			count++;
		}
		printf("%d", head->data);
	}
}

main(){
	insertAtPosition(1,0);
	insertAtPosition(2, 1);
	insertAtPosition(7, 1);
	insertAtPosition(3, 1);
	display();
	
	nextElement(2);
}

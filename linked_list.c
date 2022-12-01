#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
void addFirst(struct node **head, int val){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = *head;
	*head = newNode;	
}
void addEnd(struct node **head, int val){
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

void delNode(struct node **head, int key){
	struct node *temp;
	
	if((*head)->data == key){
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else{
		struct node *current = *head;
		while(current->next != NULL){
			if(current->next->data == key){
				temp = current->next;
				current->next = current->next->next;
				free(temp);
				break;
			}
			else{
				current = current->next;
			}
		}
	}
}

int searchNode(struct node *head, int key){
	struct node *temp = head;
	
	while(temp != NULL){
		if(temp->data == key){
			return 1;
		}
		temp = temp->next;
	}
	return -1;
}

void printList(struct node *head){
	struct node *temp = head;
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
main(){
	struct node *head = NULL;
	
	addFirst(&head, 2);
	addFirst(&head, 4);
	addFirst(&head, 6);
	addEnd(&head, 1);
	printList(head);
	delNode(&head, 1);
	delNode(&head, 6);
	printf("\n");
	printList(head);
	int t = searchNode(head, 6);
	if(t == 1)
		printf("\nNode Found");
	else
		printf("\nNode Not Found");
}
	

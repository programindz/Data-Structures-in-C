#include<stdio.h>
#define SIZE 5

int arr[SIZE];
int front = 0;
int rear = -1;

int isFull(){
	if(rear == SIZE - 1)
		return 1;
	return 0;
}

int isEmpty(){
	if(rear == -1)
		return 1;
	return 0;
}
void push(int val){
	if(isFull())
		printf("Queue is Full");
	else{
		arr[++rear] = val;
	}
}
void pop(){
	if(isEmpty())
		printf("Queue is empty");
	else{
		arr[front] = NULL;
		front++;
	}
}
void display(){
	int i;
	printf("\nQueue is : ");
	for (i = front; i<=rear; i++){
		printf("%d ", arr[i]);
	}
}
main(){
	push(1);
	display();
	push(2);
	display();
	push(3);
	display();
	push(4);
	display();
	pop();
	printf("\nAfter Popping....");
	display();
	
}


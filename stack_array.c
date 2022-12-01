#include<stdio.h>
#define SIZE 5

int arr[SIZE];
int top = -1;

int isFull(){
	if(top == SIZE-1)
		return 1;
	return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	return 0;
}

void push(int val){
	if(isFull())
		printf("Stack is full");
	else{
		arr[++top] = val;
	}
}

void pop(){
	if(isEmpty())
		printf("Stack is empty");
	else{
		printf("\nElement popped: %d", arr[top]);
		top--;
	}
}

void display(){
	int i;
	if(top == -1)
		printf("Nothing to display");
	else{
		for(i = 0; i<=top; i++){
			printf("%d ", arr[i]);
		}
	}
}

int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	display();
	pop();
	pop();
	printf("\n");
	display();
	return 0;
}

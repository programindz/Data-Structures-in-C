#include<stdio.h>
#include<string.h>
#define SIZE 20

char infix[SIZE], prefix[SIZE], stack[SIZE];
int top = -1;

int isEmpty(){
	if(top == -1)
		return 1;
	return 0;
}
int isFull(){
	if(top == SIZE - 1)
		return 1;
	return 0;
}

void push(char oper){
	if(isFull())
		printf("Stack Overflow.");
	else{
		top++;
		stack[top] = oper;
	}
}

char pop(){
	if(isEmpty())
		return "Stack Underflow.";
	char item;
	item = stack[top];
	top--;
	return item;
}

int precedence(char symb){
	if(symb == '+' || symb == '-')
		return 1;
	else if(symb == '*' || symb == '/')
		return 2;
	else
		return 0;
}

void infixToPrefix(){
	int i = 0, j = 0;
	strrev(infix);
	while(infix[i] != '\0'){
		if(infix[i] == ')'){
			push(infix[i]);
			i++;
		}
		else if(infix[i] == '('){
			while(stack[top] != ')'){
				prefix[j] = pop();
				j++;
			}
			pop();
			i++;
		}
		else if(infix[i] > '0'){
			prefix[j] = infix[i];
			i++;j++;
		}
		else{
			if(isEmpty()){
			
				push(infix[i]);
				i++;
			}
			else if(precedence(infix[i]) < precedence(stack[top])){
				prefix[j] = pop();
				j++;
			}
			else if(precedence(infix[i]) >= precedence(stack[top])){
				push(infix[i]);
				i++;
			}
		}
	}
	while(top != -1){
		prefix[j] = pop();
		j++;
	}
	strrev(prefix);
	prefix[j] = '\0';
	
	printf("Equivalent Prefix Expression is: %s", prefix); 
}

main(){
	printf("Enter the Infix Expression: ");
	gets(infix);
	infixToPrefix();	
}



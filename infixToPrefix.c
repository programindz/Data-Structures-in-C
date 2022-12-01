#include<stdio.h>
#include<string.h>


char stack[20],infix[20], prefix[20];
int top = -1;

int isFull(){
	if(top == 19)
		return 1;
	return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	return 0;
}

void push(int pos){
	if(isFull())
		printf("Stack is full");
	else{
		++top;
		stack[top] = infix[pos];
	}
}

char pop(){
	if(isEmpty())
		return ("Stack Underflow");
	char item;
	item = stack[top];
	stack[top] = '\0';
	top = top-1;
	return item;
}
int precedence(char symbol){
	if(symbol == '+' || symbol == '-')
		return 1;
	else if(symbol == '*' || symbol == '/')
		return 2;
	else
		return 0;
		
}

void infixToPrefix(){
	int i = 0, j = 0;
	strrev(infix);
	while(infix[i] != '\0'){
		if(infix[i] >= '1'){
			prefix[j] = infix[i];
			i++;
			j++;
		}
		else if (infix[i] == ')'){
			push(i);
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
		else{
			// if the stack if empty, then we simply put the operator in stack
			if(isEmpty())
			{
				push(i);
				i++;
			}
			// if the precedence of operator is less than the stack top then
			else if( precedence(infix[i]) < precedence(stack[top]))
			{
				prefix[j] = pop();  // pop the stack top and add it to the prefix string
				j++;
			}
			// if the precedence of operator is greater than or equal to the stack top 
			else if(precedence(infix[i]) >= precedence(stack[top]))
			{
			push(i);  //  Push it onto the stack
			i++;
			}
		}
	}
	// At the end remove all the operators from the stack
	while(top != -1)
	{
		prefix[j] = pop();
		j++;
	}
	// Reverse the final string before output
	strrev(prefix);
	prefix[j] = '\0';
	printf("EQUIVALENT PREFIX NOTATION : %s ",prefix);
	}
		

int main(){
	printf("Enter Infix Expression: ");
	gets(infix);
	infixToPrefix();
	
	return 0;
}











#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;
void insert(int data){
	struct node *newNode = malloc(sizeof(struct node));
	struct node *current, *parent;
	
	newNode->data = data;
	newNode->left =NULL;
	newNode->right = NULL;
	
	if(root == NULL)
		root = newNode;
	else{
		current = root;
		parent = NULL;
		
		while(1){
			parent = current;
			
			if(data<parent->data){
				current = current->left;
				
				if(current == NULL)
					parent->left = newNode; return;
			}
			
			else{
				current = current->right;
				if(current == NULL)
					parent->right = newNode;return;
			}				
			
		}	
	}
}

void display()
{
   if(root != NULL){
      display(root->left);
      printf("%d\t",root->data);
      display(root->right);
   }
}

main(){
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	display();
	
}

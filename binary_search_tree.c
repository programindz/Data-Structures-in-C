#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node *left;
	struct node *right;
};

//newnode
struct node *getNewNode(int val){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->key = val;
	newNode->right = NULL;
	newNode->left = NULL;
	
	return newNode;
}

//insert function
struct node *insert(struct node *root, int val){
	if(root == NULL)
		return getNewNode(val);
	
	if(val <  root->key)
		root->left = insert(root->left, val);
		
	if(val > root->key)
		root->right = insert(root->right, val);
		
	return root;
}

//inorder traversal function
void inorder(struct node *root){
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d -> ", root->key);
	inorder(root->right);
}

int main(){
	struct node *root = NULL;
	
    root = insert(root,100);
    insert(root, 120);
    insert(root, 50);
    insert(root, 20);
    insert(root, 12);
    insert(root, 70);
    insert(root, 200);
    insert(root, 110);

    inorder(root);
	return 0;
}


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

int max(int a, int b){
	return (a>b)? a:b;
}

int height(struct node *root){
	if(root == NULL)
		return 0;
	return 1+max(height(root->left), height(root->right));
}

struct node* newNode(int val){
	struct node *newNode = malloc(sizeof(struct node));
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 0;
	
	return newNode;
}

struct node *rightRotate(struct node *y){
	struct node *x = y->left;
	struct node *T = x->right;
	
	x->right = y;
	y->left = T;
	
	y->height = height(y);
	x->height = height(x);
	
	return x;
}
struct node *leftRotate(struct node *x){
	struct node *y = x->right;
	struct node *T = y->left;
	
	y->left = x;
	x->right = T;
	
	y->height = height(y);
	x->height = height(x);
	
	return y;
}

int getBalanceFactor(struct node *root){
	if(root == NULL)
		return 0;
	return height(root->left) - height(root->right);
}
struct node *insert(struct node *root, int val){
	if(root == NULL)
		return newNode(val);
	if(val<root->data)
		root->left = insert(root->left, val);
	else if(val>root->data)
		root->right = insert(root->right,val);
	else
		return root;
		
	
	int bal = getBalanceFactor(root);
	
	if(bal>1 && val<root->left->data)
		return rightRotate(root);
		
	if(bal< -1 && val>root->right->data)
		return leftRotate(root);
	
	if(bal>1 && val>root->left->data){
	
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(bal<-1 &&val<root->right->data){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

void preorder(struct node *root){
	if(root!=NULL){
		printf(" %d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

main(){
	struct node *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root,30);
	root = insert(root, 40);
	root = insert(root,50);
	root = insert(root,25);
	
	preorder(root);
	
}

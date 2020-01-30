#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
void preorder(node *root){
	if(root!=NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(node *root){
	if(root!=NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
node *rotateright(node *root){
	node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}
node *rotateleft(node *root){
	node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}
node *rotateleftright(node *root){
	root->left = rotateleft(root->left);
	root = rotateright(root);
	return root;
}
node *rotaterightleft(node *root){
	root->right = rotateright(root->right);
	root = rotateleft(root);
	return root;
}
int findHeight(node *root){
	if(root == NULL)
		return -1;
	return max(findHeight(root->left) , findHeight(root->right)) + 1;	
}
node *insert(node *root , int data){
	node *temp = (node *)malloc(sizeof(node));
	temp->data = data;
	if(root == NULL){
		root = temp;
		root->left = NULL;
		root->left = NULL;
	}
	else if(data <= root->data){
		root->left = insert(root->left,data);
		if(findHeight(root->left) - findHeight(root->right) == 2){
			if(findHeight((root->left)->left) - findHeight((root->left)->right) == 1)
				root = rotateright(root);
			else
				root = rotateleftright(root);
		}
	}
	else{
		root->right = insert(root->right,data);
		if(findHeight(root->left) - findHeight(root->right) == -2){
			if(findHeight((root->right)->left) - findHeight((root->right)->right) == -1)
				root = rotateleft(root);
			else
				root = rotaterightleft(root);
		}
	}
	return root;
}
node *search(node *root , int data){
	if(root == NULL)
		return NULL;
	else if(root->data == data)
		return root;
	else if(root->data < data)
		return search(root->left , data);
	else 
		return search(root->right , data);
}
node *findMinAddr(node *root){
	node *current = root;
	while(current->left!=NULL)
		current = current->left;
	return current;
}
node *deletenode(node *root , int data){
	if(root == NULL)
		return NULL;
	else if(root->data < data){
		root->right = deletenode(root->right , data);
		if(findHeight(root->left) - findHeight(root->right) == 2){
			root = rotateright(root);
		}
		return root;
	}
	else if(root->data > data){
		root->left = deletenode(root->left , data);
		if(findHeight(root->left) - findHeight(root->right) == -2){
				root = rotateleft(root);
		}
		return root;
	}
	else{
		if(root->right == NULL && root->left == NULL)
			return NULL;
		else if(root->right == NULL)
			return root->left;
		else if(root->left == NULL)
			return root->right;
		else{
			node *temp = findMinAddr(root->right);
			root->data = temp->data;
			root->right = deletenode(root->right,temp->data);
			return root;
		}
	}
}
int main(){
	int ch = 1 , i , a;
	node *root = NULL;
	while(ch){
		cout<<"Enter your choice\n1.Insert\n2.Delete\n3.Preorder\n4.Inorder\n5.Search\n";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"Enter the number to be inserted\n";
				cin>>a;
				root = insert(root,a);
				break;
			case 2:
				cout<<"Enter the number to be deleted\n";
				cin>>a;
				root = deletenode(root,a);
				break;
			case 3:
				preorder(root);
				cout<<endl;
				break;
			case 4:
				inorder(root);
				cout<<endl;
				break;
			case 5:
				node *temp = search(root,a);
				if(temp)
					cout<<"Found"<<endl;
				else
					cout<<"Not found"<<endl;
		}
		cout<<"Do you want to continue?\n";
		cin>>ch;
	}
	return 0;
}
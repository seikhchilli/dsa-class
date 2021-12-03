#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left, *right;
  int height;
};

int height(Node *n){
  if(n == NULL){
    return 0;
  }
  return n->height;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

Node* newNode(int value){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;
  temp->height = 1;
  return temp;
}

Node* rightRotate(Node *y){
  Node *x = y->left;
  Node *t2 = x->right;

  x->right = y;
  y->left = t2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node* leftRotate(Node *x){
  Node *y = x->right;
  Node *t2 = y->left;

  y->left = x;
  x->right = t2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(Node *n){
  if(n == NULL){
    return 0;
  }
  return height(n->left) - height(n->right);
}



Node* insert(Node *root, int value){

  if(root == NULL){
    return(newNode(value));
  }

  if(value < root->data){
    root->left = insert(root->left, value);
  }
  else if(value > root->data){
    root->right = insert(root->right, value);
  }

  root->height = 1 + max(height(root->left), height(root->right));

  int balance = getBalance(root);

  if(balance > 1 && value < root->left->data){
    return rightRotate(root);
  }

  if(balance < -1 && value > root->right->data){
    return leftRotate(root);
  }

  if(balance > 1 && value > root->left->data){
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if(balance < -1 && value < root->right->data){
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

void preOrder(Node *root){
  if(root != NULL){
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main(){

  Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  cout<<"Preorder Transversal of the tree: ";

  cout<<endl;
  preOrder(root);

}

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left, *right;
};

void additem(int value, Node **root){
  Node *current, *parent, *temp;
  temp = (Node*)malloc(sizeof(Node));

  temp->data = value;
  temp->left = NULL;
  temp->right = NULL;
  if(*root == NULL){
    *root = temp;
    return;
  }
  current = *root;
  while(current != NULL){
    parent = current;
    if(value < current->data){
      current = current->left;
    }
    else{
      current = current->right;
    }
  }
  if(value < parent->data){
    parent->left = temp;
  }
  else{
    parent->right = temp;
  }
}

void inorder(Node *root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void inorder_wout_rec(Node *root){
  stack<Node *> stk;
  Node *current = root;
  
  while(current != NULL || stk.empty() == false){
    while(current != NULL){
      stk.push(current);
      current = current->left;
    }

    current = stk.top();
    stk.pop();
    cout<<current->data<<" ";
    
    current = current->right;
  }

}



int main(){
  Node *root = NULL;
  int arr[] = {3, 2, 5, 1, 4};
  for(auto i: arr){
    additem(i, &root);
  }
  
  inorder_wout_rec(root);

}

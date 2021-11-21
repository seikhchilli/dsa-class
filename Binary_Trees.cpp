#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *leftChild;
  node *rightChild;
};

// BST : root node is always greater than its left child and smaller than its right child


void insertBst(node **root, int val){
  node* temp = (node*)malloc(sizeof(node));
  if(temp == NULL){
    cout<<"Memory is insufficent"<<endl;
    return;
  }
  temp->data = val;
  temp->leftChild =  NULL;
  temp->rightChild = NULL;

  if(*root == NULL){
    *root = temp;
    return;
  }
  node *current = *root;
  node *parent;
  while(1){
    parent = current;
    if(val < current->data){
      current = current->leftChild;
      if(current == NULL){
        parent->leftChild = temp;
        return;
      }
    }
    else{
      current = current->rightChild;
      if(current == NULL){
        parent->rightChild = temp;
        return;
      }
    }
  }

}

void inorder(node *root){
  if(root == NULL){
    return;
  }
  cout<<root->data<<" ";
  inorder(root->leftChild);
  inorder(root->rightChild);
}

int main(){
  node *root = NULL;

  int arr[5] = {1, 3, 4, 2, 7};

  for(auto i : arr){
    insertBst(&root, i);
  }

  inorder(root);

}

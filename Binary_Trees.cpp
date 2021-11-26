#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *leftChild;
  node *rightChild;
};

// BST : root node is always greater than its left child and smaller than its right child

//Function to insert nodes in BST:

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

//inorder transeversal:

void inorder(node *root){
  if(root == NULL){
    return;
  }
  inorder(root->leftChild);
  cout<<root->data<<" ";
  inorder(root->rightChild);
}

//postorder transeversal:

void postorder(node *root){
  if(root == NULL){
    return;
  }
  postorder(root->leftChild);
  postorder(root->rightChild);
  cout<<root->data<<" ";

}

//preorder transeversal:

void preorder(node *root){
  if(root == NULL){
    return;
  }

  cout<<root->data<<" ";
  preorder(root->leftChild);
  preorder(root->rightChild);
}

//search nodes:

bool ifExists(node *root, int value){
  node *current = root;
  while(current != NULL){
    if(value < current->data){
      current = current->leftChild;
    }
    else if(value > current->data){
      current = current->rightChild;
    }
    else{
      return true;
    }
  }
  return false;
}


//driver code
int main(){
  node *root = NULL;

  int arr[5] = {1, 3, 4, 2, 7};

  for(auto i : arr){
    insertBst(&root, i);
  }

  cout<<"Inorder transeversal: ";
  inorder(root);
  cout<<endl;
  cout<<"\nPostorder transeversal: ";
  postorder(root);
  cout<<endl;
  cout<<"\nPreorder transeversal: ";
  preorder(root);
  cout<<endl<<endl;

  cout<<"Enter the number to be searched: ";
  int n;
  cin>>n;
  if(ifExists(root, n)){
    cout<<"YES, the number is present."<<endl;
  }
  else{
    cout<<"NO, the number is not present."<<endl;
  }
}

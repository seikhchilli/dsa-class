#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *left, *right;
};

void add_node(Node **root, int data){
  Node *current, *parent;
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->right = NULL;
  temp->left = NULL;

  if(*root == NULL){
    *root = temp;
    return;
  }

  current = *root;
  while(1){
    parent = current;
    if(data < current->data){
      current = current->left;
      if(current == NULL){
        parent->left = temp;
        return;
      }
    }
    else{
      current= current->right;
      if(current == NULL){
        parent->right = temp;
        return;
      }
    }
  }
}

Node* FindMin(Node *root){
  Node *temp = root;
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp;
}

Node* delete_node(Node *root, int data){
  if(root == NULL){
    return root;
  }
  else if(data < root->data){
    root->left = delete_node(root->left, data);
  }
  else if(data > root->data){
    root->right = delete_node(root->right, data);
  }
  else{
    if(root->left == NULL && root->right == NULL){
      free(root);
      root = NULL;
    }
    else if(root->left == NULL){
      Node *temp = root;
      root = root->right;
      free(temp);
    }
    else if(root->right == NULL){
      Node *temp = root;
      root = root->left;
      free(temp);
    }
    else{
      Node *temp = FindMin(root->right);
      root->data = temp->data;
      root->right = delete_node(root->right, temp->data);
    }
  }
  return root;
}

void inorder(Node *root){
  if(root == NULL){
    return;
  }

  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main(){
  Node *root = NULL;

  int n;
  cout<<"Enter number of nodes to be created: ";
  cin>>n;
  cout<<"Enter the data to be added: "<<endl;
  while(n--){
    int x;
    cin>>x;
    add_node(&root, x);
  }

  cout<<endl<<endl;
  cout<<"inorder transversal: ";
  inorder(root);
  char check;
  do{
    cout<<"\n\nEnter value of node to be deleted: ";
    int delete_data;
    cin>>delete_data;
    delete_node(root, delete_data);

    cout<<"\nAfter deletion : ";
    inorder(root);
    cout<<"Do you want to keep deleting?(y/n)  ";
    cin>>check;
  }while(check != 'n');

}

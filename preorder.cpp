#include  <iostream>
using  namespace std;
class node{
    
    public:
    int data;
    node *left;
    node *right;
    
    node(int data){
        this->left=NULL;
        this->data=data;
        this->right=NULL;
    }
};


node *insert(int data){
    node *newnode=new node(data);
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void preorder(node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(root==NULL){
        return ;
    }
   
    postorder(root->left);
    postorder(root->right);
     cout<<root->data<<" ";
}


void inorder(node*root){
    if(root==NULL){
        return ;
    }
   
    inorder(root->left);
     cout<<root->data<<" ";
    inorder(root->right);
}

node* buildTree() {
    int data;
    cout << "Enter the root value or to exit press -1->";
    cin >> data;
    
    if (data == -1) {
        return NULL;
    }

    node* root = insert(data);

    cout << "Enter left child of " << data << ": ";
    root->left = buildTree();

    cout << "Enter right child of " << data << ": ";
    root->right = buildTree();

    return root;
}
int main(){
     node* root=buildTree();
    cout<<"Preorder"<<endl;
     preorder(root);
     cout<<"Post Order"<<endl;
     postorder(root);
     cout<<"Inorder "<<endl;
     inorder(root);
    
    return 0;
    
    
}
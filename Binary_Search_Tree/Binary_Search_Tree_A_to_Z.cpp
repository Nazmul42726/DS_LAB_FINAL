#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};

class BST{
private:
    TreeNode* root;
    
    TreeNode* Inserting(TreeNode* parent, int data){
        if(parent==nullptr){
            TreeNode* nodeToInsert=new TreeNode(data);
            return nodeToInsert;
        }
        if(data<(parent->data))
            parent->left=Inserting(parent->left,data);
        else if(data>=(parent->data))
            parent->right=Inserting(parent->right,data);
        
        return parent;
    }
    TreeNode* Deleting(TreeNode* parent, int data){
        //code here

        return parent;
    }
    TreeNode* NodeOfMinimumData(TreeNode* node){
        while(node->left!=nullptr)
            node=node->left;
        return node;
    }
    TreeNode* NodeOfMaximumData(TreeNode* node){
        while(node->right!=nullptr)
            node=node->right;
        return node;
    }
    TreeNode* Searching(TreeNode* root, int data){
        if(root==nullptr || root->data==data)
            return root;
        
        if(data<(root->data))
            return Searching(root->left,data);

        return Searching(root->right,data);
    }
    void inorderTraversing(TreeNode* root){
        if(root!=nullptr){
            inorderTraversing(root->left);
            cout<<root->data<<" ";
            inorderTraversing(root->right);
        }
    }
    void preorderTraversing(TreeNode* root){
        if(root!=nullptr){
            cout<<root->data<<" ";
            preorderTraversing(root->left);
            preorderTraversing(root->right);
        }
    }
    void postorderTraversing(TreeNode* root){
        if(root!=nullptr){
            postorderTraversing(root->left);
            postorderTraversing(root->right);
            cout<<root->data<<" ";
        }
    }

public:
    BST(){
        root=nullptr;
    }
    void insert(int data){
        root=Inserting(root,data);
    }
    void Delete(int data){
        root=Deleting(root,data);
    }
    bool search(int data){
        TreeNode* node=Searching(root,data);
        return node!=nullptr;
    }
    int min(){
        TreeNode* minNode=NodeOfMinimumData(root);
        if(minNode==nullptr){
            cout<<"Tree is Empty!"<<endl;
            return 0;
        }
        else return minNode->data;
    }
    int max(){
        TreeNode* maxNode=NodeOfMaximumData(root);
        if(maxNode==nullptr){
            cout<<"Tree is Empty!"<<endl;
            return 0;
        }
        else return maxNode->data;
    }
    void inorder(){
        inorderTraversing(root);
        cout<<endl;
    }
    void preorder(){
        preorderTraversing(root);
        cout<<endl;
    }
    void postorder(){
        postorderTraversing(root);
        cout<<endl;
    }
};

int main(){
    BST bst;
    
    bst.insert(3);
    bst.insert(6);
    bst.insert(1);
    bst.insert(4);
    bst.insert(4);
    bst.insert(5);
    bst.insert(7);

    cout<<"Minimum: "<<bst.min()<<endl;
    cout<<"Maximum: "<<bst.max()<<endl;

    cout<<"Inorder Traversal: ";
    bst.inorder();
    cout<<"Pre-order Traversal: ";
    bst.preorder();
    cout<<"Post-order Traversal: ";
    bst.postorder();   
}
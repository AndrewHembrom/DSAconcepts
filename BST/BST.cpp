#include <iostream>
#include <queue>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

        Node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int d){
    // base case
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //need to insert in right part
        root->right = insertIntoBST(root->right, d);
    }
    else{
        //need to insert in left part
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " "; 
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data!=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

bool searchInBSTRec(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }

    if(root->data > key){
        return searchInBSTRec(root->left, key);
    }
    else{
        return searchInBSTRec(root->right, key);
    }
}

bool searchInBSTIter(Node* root, int key){
    Node* temp = root;

    while(temp!=NULL){
        if(temp->data == key){
            return true;
        }
        if(temp->data > key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return false;
}

Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }


        //2 children
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }


    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    Node* root = NULL;

    cout<<"Enter data to create BST: "<< endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<endl<<"Printing Preorder"<<endl;
    preorder(root);

    cout<<endl<<endl<<"Printing Postorder"<<endl;
    postorder(root);

    int key;
    
    cout<<endl<<endl<<"Enter key to search in BST: "<<endl;
    cin>>key;
    cout<<searchInBSTIter(root, key)<<endl;

    cout<<" "<<endl;
    cout<<"Min and Max Values in BST: "<<endl;
    cout<<"Min Value in BST: "<< minVal(root)->data<<endl;
    cout<<"Max Value in BST: "<< maxVal(root)->data<<endl;

    cout<<" "<<endl;
    root = deleteFromBST(root, 30);
    cout<<" "<<endl;

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<"Printing Inorder"<<endl;
    inorder(root);

    cout<<endl<<endl<<"Printing Preorder"<<endl;
    preorder(root);

    cout<<endl<<endl<<"Printing Postorder"<<endl;
    postorder(root);

    return 0;
}
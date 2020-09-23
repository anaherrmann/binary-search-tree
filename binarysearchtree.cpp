#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    
    Node(int data){
        this->data = data;
        this->left = this->right = nullptr;
    };
};

void insert(Node **root, int data){
    if(*root == NULL){
        *root = new Node(data);
    }
    else if((*root)->data <= data){
        insert(&((*root)->right), data);
    }
    else if((*root)->data > data){
        insert(&((*root)->left), data);
    }
}

Node* buildTree(int* array, int size){
    Node* root = NULL;
    for(int i = 0; i < size; i++){
        insert(&root, array[i]);
    }
    return root;
}

void preOrderIterativeSearch(Node* root){
    if(root == nullptr){
        return;
    }

    stack<Node*> stack;
    stack.push(root);

    Node* current = root;

    while(!stack.empty()){
        if(current != nullptr) {
            cout << current->data << " ";

            if(current->right) 
                stack.push(current->right);

            current = current->left;
        }
        else {
            current = stack.top();
            stack.pop();
        }
    }
    
}

void preOrderRecursiveSearch(Node* root){
    if(root == nullptr)
        return;

    cout << root->data << " ";

    preOrderRecursiveSearch(root->left);

    preOrderRecursiveSearch(root->right);
}

void inOrderIterativeSearch(Node* root){}

void inOrderRecursiveSearch(Node* root){
     if(root == nullptr)
        return;

    preOrderRecursiveSearch(root->left);

    cout << root->data << " ";

    preOrderRecursiveSearch(root->right);
}

void postOrderIterativeSearch(Node* root){}

void postOrderRecursiveSearch(Node* root){
     if(root == nullptr)
        return;

    preOrderRecursiveSearch(root->left);

    preOrderRecursiveSearch(root->right);

    cout << root->data << " ";    
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "\nNot enough arguments.\n";
        cout << "You should pass the data file path and size.\n";
        exit(1);
    }
    else if (argc >= 3)
    {
        cout << "Input counter: " << argv[1] << endl;
        cout << "File name: " << argv[2] << endl << endl;
    }

    stringstream str;
    str << argv[1];
    int inputCount;
    str >> inputCount;

    string filePath = argv[2];

    ifstream dataFile;
    dataFile.open(filePath);

    if(!dataFile.is_open()){
        cout << "\nError opening file.\n";
        exit(1);
    }

    int dataArray[inputCount];
    int counter = 0;
    int integer;

    while(dataFile >> integer){
        dataArray[counter] = integer;
        counter++;
    }

    cout << endl << endl;

    Node *root = buildTree(dataArray, inputCount);
    
    preOrderRecursiveSearch(root);
    cout << endl << endl;
    inOrderRecursiveSearch(root);
    cout << endl << endl;
    postOrderRecursiveSearch(root);
    cout << endl << endl;

    return 0;
}

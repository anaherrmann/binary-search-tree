#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <chrono>

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

typedef void (*treeSearches) (Node* root);

void insertRecursive(Node **root, int data){    
    if(*root == NULL){
        *root = new Node(data);
    }
    else if((*root)->data <= data){
        insertRecursive(&((*root)->right), data);
    }
    else if((*root)->data > data){
        insertRecursive(&((*root)->left), data);
    }
}

Node* insertIterative(Node* root, int data){
    Node* newNode = new Node(data);

    Node* x = root;
    Node* y = NULL;

    while(x != NULL){
        y = x;
        if(data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    if(y == NULL)
        y = newNode;
    else if(data < y->data)
        y->left = newNode;
    else 
        y->right = newNode;
    
    return y;
}
 
Node* buildTree(int* array, int size){
    Node* root = new Node(array[0]);
    for(int i = 0; i < size; i++){
        insertIterative(root, array[i]);
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

void inOrderIterativeSearch(Node* root){
    if(root == nullptr){
        return;
    }

    stack<Node*> stack;

    Node* current = root;

    while(!stack.empty() || current != nullptr){
        if(current != nullptr) {
            stack.push(current);
            current = current->left;                   
        }
        else {            
            current = stack.top();
            stack.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}

void inOrderRecursiveSearch(Node* root){
     if(root == nullptr)
        return;

    inOrderRecursiveSearch(root->left);

    cout << root->data << " ";

    inOrderRecursiveSearch(root->right);
}

void postOrderIterativeSearch(Node* root){
    if(root == nullptr){
        return;
    }
    
    stack<Node*> stk;
    stk.push(root);

    stack<int> out;

    while(!stk.empty()){
        Node* current = stk.top();
        stk.pop();

        out.push(current->data);

        if(current->left)
            stk.push(current->left);

        if(current->right)
            stk.push(current->right);
    }

    while(!out.empty()){
        cout << out.top() << " ";
        out.pop();
    }

}

void postOrderRecursiveSearch(Node* root){
     if(root == nullptr)
        return;

    postOrderRecursiveSearch(root->left);

    postOrderRecursiveSearch(root->right);

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
        //cout << "Input counter: " << argv[1] << endl;
        //cout << "File name: " << argv[2] << endl << endl;
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
    int dataAux[150000];
    copy(dataArray, dataArray + 150000, dataAux);
    cout << endl << endl;

    Node *root = buildTree(dataAux, inputCount);

    treeSearches searches[] =
    {   
        preOrderIterativeSearch,
        preOrderRecursiveSearch,
        inOrderIterativeSearch,
        inOrderRecursiveSearch,
        postOrderIterativeSearch,
        postOrderRecursiveSearch
    };

    chrono::steady_clock::time_point begin;
    chrono::steady_clock::time_point end;
    
    int time_ns = 0;
    cout << inputCount << " ";
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            begin = chrono::steady_clock::now();
            searches[i](root);
            end = chrono::steady_clock::now();

            time_ns += chrono::duration_cast<chrono::nanoseconds> (end - begin).count();
        } 

        cout << (time_ns/10) << " ";  
        time_ns = 0; 
    }    
    cout << endl;
    
    return 0;
}

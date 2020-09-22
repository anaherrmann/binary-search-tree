#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void preOrderSearch(Node* root){
    
}

void inOrderSearch(Node* root){
    
}

void postOrderSearch(Node* root){
    
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
    cout << root->data << endl;


    return 0;
}

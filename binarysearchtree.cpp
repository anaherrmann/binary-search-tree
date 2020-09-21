/*
- recebe a localizacao de um arquivo txt
- abre o arquivo e preenche a árvore conforme a entrada
- pra cada árvore montada, realizar as seis buscas
- a saída é o tempo que levou pra chegar na última folha
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

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
        cout << argv[1] << endl;
        cout << argv[2] << endl;
    }

    stringstream str;
    str << argv[1];
    int file_size;
    str >> file_size;

    string file_path = argv[2];

    ifstream data_file;
    data_file.open(file_path);

    if(!data_file.is_open()){
        cout << "\nError opening file.\n";
        exit(1);
    }

    int data_array[file_size];
    int counter = 0;
    int integer;

    while(data_file >> integer){
        data_array[counter] = integer;
        cout << integer << " ";
        counter++;
    }

    return 0;
}

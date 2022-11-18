// C++ program for the above approach
  
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
  
class Encdec {
    private:
        int key = 13;
        char c;
        string username, password;
  
public:
    Encdec(string rol);
    string getUsername(){return this->username;}
    string getPassword(){return this->password;}
    void decrypt();
    ~Encdec();
};

Encdec::Encdec(string rol){
    decrypt();
    ifstream archivo;
    archivo.open("decrypt.txt");
    string rolArchivo, username, password;
    if(archivo.is_open()){
        while (archivo >> rolArchivo >> username >> password){
            if(rolArchivo == rol){
                this->username = username;
                this->password = password;
            };
        }
        archivo.close();
        } else{
            cout << "No puedo abrir el archivo...\n";
            archivo.close();
        }
        remove("decrypt.txt");
}

void Encdec::decrypt()
{
    fstream fin;
    fstream fout;
    fin.open("encrypt.txt", fstream::in);
    fout.open("decrypt.txt", fstream::out);
  
    while (fin >> noskipws >> c) {
  
        // Remove the key from the character
        int temp = (c - key);
        fout << (char)temp;
    }
    fin.close();
    fout.close();
}
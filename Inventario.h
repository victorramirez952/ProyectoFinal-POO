#include "vector"
#include "Comic.h"
#include "fstream"
class Inventario{
    private:
        vector<Comic> comics;
        // vector<string> categorias;
        int total_comics;
    public:
        Inventario();
        void buscarComics();
        void editarComics();
        void eliminarComicsVendidos();
        void mostrarInventario();
        ~Inventario();
};
//derivaciones
Inventario::Inventario(){
    string linea;
    ifstream archivoBD("BDComics.txt");
    if(archivoBD.is_open()){
        int contadorArrayComics = 0, contador = 0;
        while(getline(archivoBD, linea)){
            if(contador == 0) 
                comics[contador] = new Comic(); //Pendiente
                comics[contadorArrayComics].setCompania(linea);
            if(contador == 1)
                comics[contadorArrayComics].setNombre(linea);
            if(contador == 2)
                comics[contadorArrayComics].setPrecio(stoi(linea.c_str()));
            if(contador == 3)
                comics[contadorArrayComics].setCodigo(linea);
            if(contador == 4)
                comics[contadorArrayComics].setFecha(linea);
            if(contador == 5)
                comics[contadorArrayComics].setCantidad(stoi(linea.c_str()));
            if(contador == 6){
                comics[contadorArrayComics].setOferta(stoi(linea.c_str()));
                contadorArrayComics++;
                contador = 0;
                continue;
            }
            contador++;
        }
    } else{
        cout << "No puedo abrir el archivo...";
    }
    archivoBD.close();
}

void Inventario::buscarComics(){}

void Inventario::editarComics(){}

void Inventario::eliminarComicsVendidos(){}

void Inventario::mostrarInventario(){
    cout << "Flag\n";
    // for(int i = 0; i < comics.size(); i++){
    //     // comics[i].mostrarDatos();
    //     cout << "************\n";
    // }
}

Inventario::~Inventario(){}

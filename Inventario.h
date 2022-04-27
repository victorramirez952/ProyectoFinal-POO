#include "vector"
#include "Comic.h"
#include "Recibo.h"
#include "fstream"
class Inventario{
    protected:
        vector<Comic> comics;
        int total_comics;
    public:
        Inventario();
        void refrescarInventario();
        void buscarComic(string search);
        void editarComics();
        void eliminarComicsVendidos();
        void mostrarInventario();
        ~Inventario();
};

class ComicsAdquiridos : public Inventario, public Recibo_lotes_adquiridos{
    private:
        vector<Comic> comicsAdquiridos;
    public:
        ComicsAdquiridos();
        void pedirNuevosComics();
        void establecerComicsAdquiridos();
        void organizarLotesAdquiridos();
        void mostrarComicsAdquiridos();
        ~ComicsAdquiridos();
};
///////////////////////////////////////////////////////7
//derivaciones
Inventario::Inventario(){
    refrescarInventario();
}

void Inventario::refrescarInventario(){
    string linea;
    ifstream archivoBD("BDComics.txt");
    if(archivoBD.is_open()){
        int contadorArrayComics = 0, contador = 0;
        while(getline(archivoBD, linea)){
            if(contador == 0){
                comics.emplace(comics.end());
                comics[contadorArrayComics].setCodigo(linea);
            }
            if(contador == 1)
                comics[contadorArrayComics].setCompania(linea);
            if(contador == 2)
                comics[contadorArrayComics].setNombre(linea);
            if(contador == 3)
                comics[contadorArrayComics].setPrecio(stoi(linea.c_str()));
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

void Inventario::buscarComic(string search){
    string linea;
    ifstream objetoArchivo("BDComics.txt");
    int contador = 7;
    bool encontrado = false;
    if(objetoArchivo.is_open()){
        while(getline(objetoArchivo, linea)){

            if(linea == search){
                encontrado = true;
            }

            if(encontrado == false) continue;

            if(encontrado){
                cout << linea << endl;
                if(contador == 1) break;
                contador--;
            }
        }
        if(encontrado == false) cout << "No se encontro el comic\n";
        objetoArchivo.close();
    } else{
        cout << "No puedo abrir el archivo...";
    }
}

void Inventario::editarComics(){}

void Inventario::eliminarComicsVendidos(){}

void Inventario::mostrarInventario(){
    for(int i = 0; i < comics.size(); i++){
        comics[i].mostrarDatos();
        cout << "************\n";
    }
}

Inventario::~Inventario(){}

////////////////////////////////////////////////////
ComicsAdquiridos::ComicsAdquiridos(){}

void ComicsAdquiridos::pedirNuevosComics(){
    string compania, comic, answer, codigo;
    int dia, mes, anio, nLotes, totalLotes;
    float precio;
    bool continuar = true;

    ofstream objetoArchivo("ComicsAdquiridos.txt");
    do {
        cout << "Ingresa el codigo del comic: ";
        getline(cin, codigo);
        cout << "Ingresa la compania: ";
        getline(cin, compania);
        cout << "Ingresa el nombre del comic: ";
        getline(cin, comic);
        cout << "Ingresa el precio individual del comic: ";
        cin >> precio;
        cout << "Ingresa el dia de publicacion: ";
        cin.ignore();
        cin >> dia;
        cout << "Ingresa el mes de publicacion: ";
        cin.ignore();
        cin >> mes;
        cout << "Ingresa el anio de publicacion: ";
        cin.ignore();
        cin >> anio;

        cout << "Ingresa la cantidad de lotes a comprar del comic: ";
        cin.ignore();
        cin >> nLotes;
        totalLotes += nLotes;
        cin.ignore();

        if(objetoArchivo.is_open()){
            objetoArchivo << codigo << endl;
            objetoArchivo << compania << endl;
            objetoArchivo << comic << endl;
            objetoArchivo << precio << endl;
            objetoArchivo << dia << "/" << mes << "/" << anio << endl;
            objetoArchivo << nLotes << endl;
        } else{
            cout << "No se puede abrir el archivo\n";
        }

        cout << "Desea continuar (1 - Si, 2 - No): ";
        getline(cin, answer);
        if(answer == "2"){
            continuar = false;
            objetoArchivo.close();
        }
        
    } while(continuar);

    cout << "Desea imprimir la factura?: (1 - Si, 2 - No)";
    cin >> answer;
    if(answer == "1"){
        this->imprimirRecibo(totalLotes);
    }
}


void ComicsAdquiridos::establecerComicsAdquiridos(){
    string linea;
    ifstream objetoArchivo("ComicsAdquiridos.txt");
    int contador = 0, contadorArray = 0;
    if(objetoArchivo.is_open()){
        while(getline(objetoArchivo, linea)){
            if(contador == 0){
                comicsAdquiridos.emplace(comicsAdquiridos.end());
                comicsAdquiridos[contadorArray].setCodigo(linea);
            }
            if(contador == 1){
                comicsAdquiridos[contadorArray].setCompania(linea);
            }
            if(contador == 2){
                comicsAdquiridos[contadorArray].setNombre(linea);
            }
            if(contador == 3){
                comicsAdquiridos[contadorArray].setPrecio(stoi(linea.c_str()));
            }
            if(contador == 4){
                comicsAdquiridos[contadorArray].setFecha(linea);
            }
            if(contador == 5){
                comicsAdquiridos[contadorArray].setCantidad(stoi(linea.c_str()) * 20); // cada lote tienen 20 comics
                contadorArray++;
                contador = 0;
                continue;
            }
            contador++;
        }
        cout << "Lotes establecidos con exito" << endl;
        objetoArchivo.close();
    } else{
        cout << "No puedo abrir el archivo...";
    }
}

void ComicsAdquiridos::organizarLotesAdquiridos(){
    bool encontrado = false;
    int indice = 0;
    for(int i = 0; i < comicsAdquiridos.size(); i++){
        for(int j = 0; j < this->comics.size(); j++){
            if(comicsAdquiridos[i].getCodigo() == this->comics[j].getCodigo()){
                encontrado = true;
                indice = j;
                break;
            }
        }
        if(encontrado){
            cout << "Si encontrado"<< endl;
            int cant = this->comics[indice].getCantidad();
            int newPrecio, option;
            this->comics[indice].setCantidad(cant + comicsAdquiridos[i].getCantidad());
            cout << "Ingrese el nuevo precio del comic: ";
            cin.ignore();
            cin >> newPrecio;
            this->comics[indice].setPrecio(newPrecio);

            cout << "El comic está en oferta? (1-Si, 0-No): ";
            cin >> option;
            if(option == 1) this->comics[indice].setOferta(true);
            if(option == 2) this->comics[indice].setOferta(false);
        } 
        else{
            int newPrecio, option;
            this->comics.emplace(comics.end());
            this->comics[comics.size()-1].setCodigo(comicsAdquiridos[i].getCodigo());
            this->comics[comics.size()-1].setCompania(comicsAdquiridos[i].getCompania());
            this->comics[comics.size()-1].setNombre(comicsAdquiridos[i].getNombre());

            cout << "Ingrese el nuevo precio del comic: ";
            cin.ignore();
            cin >> newPrecio;
            this->comics[indice].setPrecio(newPrecio);

            this->comics[comics.size()-1].setFecha(comicsAdquiridos[i].getFecha());
            this->comics[comics.size()-1].setCantidad(comicsAdquiridos[i].getCantidad());

            cout << "El comic esta en oferta? (1-Si, 0-No): ";
            cin >> option;
            if(option == 1) this->comics[comics.size()-1].setOferta(true);
            if(option == 2) this->comics[comics.size()-1].setOferta(false);
        }
    }
    cout << "--------------------------" << endl;
    for(int i = 0; i < comics.size(); i++){
        comics[i].mostrarDatos();
        cout << "--------------------------\n" << endl;
    }
}

void ComicsAdquiridos::mostrarComicsAdquiridos(){
    for(int i = 0; i < comicsAdquiridos.size(); i++){
        comicsAdquiridos[i].mostrarDatos();
    }
}

ComicsAdquiridos::~ComicsAdquiridos(){}
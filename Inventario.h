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
        void buscarComic(string search);
        void editarComics();
        void eliminarComicsVendidos();
        void mostrarInventario();
        void actualizarInventario();
        void actualizarInventario(vector<Comic> comics);
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
////////////////////////////////////////////////////////
//derivaciones
Inventario::Inventario(){
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

void Inventario::editarComics(){
    int n;
    cout << "Cuantos comics vas a editar?: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cin.ignore();
        string codigo;
        string compania, nombre, fecha;
        float precio;
        int cantidad, oferta, indice;

        bool encontrado = false;
        cout << "Ingresa el codigo del comic que vas a editar: ";
        getline(cin, codigo);
        for(int j = 0; j < comics.size(); j++){
            if(comics[j].getCodigo() == codigo){
                comics[j].mostrarDatos();
                encontrado = true;
                indice = j;
            }
        }
        if(!encontrado){
            cout << "No se encontro el comic\n";
            continue;
        }
        Comic comicEncontrado = comics[indice];

        cout << comicEncontrado.getCompania() << endl;
        cout << "Ingresa la nueva compania: ";
        getline(cin, compania);
        comics[indice].setCompania(compania);

        cout << comicEncontrado.getNombre() << endl;
        cout << "Ingresa el nuevo nombre: ";
        getline(cin, nombre);
        comics[indice].setNombre(nombre);

        cout << comicEncontrado.getPrecio() << endl;
        cout << "Ingresa el nuevo precio: ";
        cin >> precio;
        comics[indice].setPrecio(precio);

        cin.ignore();

        cout << comicEncontrado.getFecha() << endl;
        cout << "Ingresa la nueva fecha: ";
        getline(cin, fecha);
        comics[indice].setFecha(fecha);
        
        cout << comicEncontrado.getCantidad() << endl;
        cout << "Ingresa la nueva cantidad: ";
        cin >> cantidad;
        comics[indice].setCantidad(cantidad);
        
        cout << "Deseas poner el comic en oferta (1-Si, 2-NO): ";
        cin >> oferta;
        comics[indice].setOferta(oferta);
    }
    actualizarInventario();
}

void Inventario::eliminarComicsVendidos(){
    vector<Comic> leftComics;
    string codigo;
    int cantidad, indice;
    bool encontrado;
    cout << "Ingresa el codigo del comic vendido: ";
    getline(cin, codigo);
    buscarComic(codigo);
    for(int i = 0; i < comics.size(); i++){
        if(comics[i].getCodigo() == codigo){
            encontrado = true;
            indice = i;
            cout << "Ingresa la cantidad vendida de ese comic: ";
            cin >> cantidad;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic\n";
        return;
    }
    int cantidadRestante = comics[indice].getCantidad() - cantidad;
    comics[indice].setCantidad(cantidadRestante);
    if(comics[indice].getCantidad() == 0){
        comics.erase(comics.begin()+indice);
    }
    actualizarInventario();
}

void Inventario::mostrarInventario(){
    for(int i = 0; i < comics.size(); i++){
        comics[i].mostrarDatos();
        cout << "************\n";
    }
}

void Inventario::actualizarInventario(){
    ofstream archivo("BDComics.txt");
    if(archivo.is_open()){
        for(int i = 0; i < comics.size(); i++){
            archivo << comics[i].getCodigo() << endl;
            archivo << comics[i].getCompania() << endl;
            archivo << comics[i].getNombre() << endl;
            archivo << comics[i].getPrecio() << endl;
            archivo << comics[i].getFecha() << endl;
            archivo << comics[i].getCantidad() << endl;
            if(comics[i].getOferta()){
                archivo << 1 << endl;
            } else{
                archivo << 0 << endl;
            }
        }
        archivo.close();
    } else{
        cout << "No puede abrir el archivo";
    }
}

Inventario::~Inventario(){}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
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
            int cant = this->comics[indice].getCantidad();
            int newPrecio, option;
            this->comics[indice].setCantidad(cant + comicsAdquiridos[i].getCantidad());
            cout << "Ingrese el nuevo precio del comic: ";
            cin >> newPrecio;
            this->comics[indice].setPrecio(newPrecio);

            cin.ignore();
            cout << "El comic esta en oferta? (1-Si, 0-No): ";
            cin >> option;
            if(option == 1) this->comics[indice].setOferta(1);
            if(option == 0) this->comics[indice].setOferta(0);
        } 
        else{
            float newPrecio, option;
            this->comics.emplace(comics.end());
            this->comics[comics.size()-1].setCodigo(comicsAdquiridos[i].getCodigo());
            this->comics[comics.size()-1].setCompania(comicsAdquiridos[i].getCompania());
            this->comics[comics.size()-1].setNombre(comicsAdquiridos[i].getNombre());

            cout << "Ingrese el nuevo precio del comic: ";
            cin >> newPrecio;
            this->comics[comics.size()-1].setPrecio((float) newPrecio);

            this->comics[comics.size()-1].setFecha(comicsAdquiridos[i].getFecha());
            this->comics[comics.size()-1].setCantidad(comicsAdquiridos[i].getCantidad());

            cout << "El comic esta en oferta? (1-Si, 0-No): ";
            cin >> option;
            if(option == 1) this->comics[comics.size()-1].setOferta(true);
            if(option == 2) this->comics[comics.size()-1].setOferta(false);
        }
    }
    actualizarInventario();
    remove("ComicsAdquiridos.txt");
    fstream archivo;

    archivo.open("ComicsAdquiridos.txt", std::ios_base::app);
    archivo.close();
}

void ComicsAdquiridos::mostrarComicsAdquiridos(){
    for(int i = 0; i < comicsAdquiridos.size(); i++){
        comicsAdquiridos[i].mostrarDatos();
    }
}

ComicsAdquiridos::~ComicsAdquiridos(){}
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
        int buscarIndiceComic(string search); //regresa indice de un comic buscado
        void editarComic();
        void eliminarComicsVendidos();
        void eliminarComic();
        void mostrarInventario();
        void guardarInventario();
        void cargarInventario();
        ~Inventario();
};

class ComicsAdquiridos : public Inventario{
    private:
        vector<ComicAdquirido> comicsAdquiridos;
    public:
        ComicsAdquiridos();
        void pedirNuevosComics();
        void cargarInventarioComicsAdquiridos();
        void organizarLotesAdquiridos();
        void mostrarComicsAdquiridos();
        void guardarComicsAdquiridos();
        ~ComicsAdquiridos();
};
////////////////////////////////////////////////////////
//derivaciones
Inventario::Inventario(){
    cargarInventario();
}

void Inventario::buscarComic(string search){
    bool encontrado = false;
    cargarInventario();
    for(int i = 0; i < comics.size(); i++){
        if(comics[i].getCodigo() == search){
            cout << "\nComic encontrado exitosamente!\n\n";
            encontrado = true;
            comics[i].mostrarDatos();
            cout << endl;
            break;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic con el codigo " << search << endl;
    }
}

int Inventario::buscarIndiceComic(string search){
    bool encontrado = false;
    cargarInventario();
    for(int i = 0; i < comics.size(); i++){
        if(comics[i].getCodigo() == search){
            cout << "\nComic encontrado exitosamente!\n\n";
            encontrado = true;
            comics[i].mostrarDatos();
            cout << endl;
            return i;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic con el codigo " << search << endl;
        return -1;
    }
}


void Inventario::editarComic(){
    cargarInventario();
    string codigo;
    int indice;

    bool encontrado = false;
    cout << "Ingresa el codigo del comic que vas a editar: ";
    getline(cin, codigo);
    for(int i = 0; i < comics.size(); i++){
        if(comics[i].getCodigo() == codigo){
            comics[i].mostrarDatos();
            encontrado = true;
            indice = i;
            break;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic\n";
        return;
    }
    comics[indice].modificarDatos();
    guardarInventario();
    cout << "Comic actualizado correctamente!" << endl;
}

void Inventario::eliminarComicsVendidos(){
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
            string _cantidad;
            while(true){
                cout << "Ingresa la cantidad vendida de ese comic: ";
                getline(cin, _cantidad);
                if(validarNumero(_cantidad)){
                    cantidad = stoi(_cantidad.c_str());
                    break;
                } else{
                    cout << "Ingresa una cantidad valida" << endl;
                }
            }
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
    guardarInventario();
}

void Inventario::eliminarComic(){
    cargarInventario();
    string codigo;
    int indice;
    bool encontrado;
    cout << "Ingresa el codigo del comic vendido: ";
    getline(cin, codigo);

    for(int i = 0; i < comics.size(); i++){
        if(comics[i].getCodigo() == codigo){
            encontrado = true;
            indice = i;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic\n";
        return;
    }
    
    comics[indice].mostrarDatos();
    comics.erase(comics.begin()+indice);
    guardarInventario();
}

void Inventario::mostrarInventario(){
    cout << "INVENTARIO DE COMICS" << endl;
    cout << "---------------------------\n";
    for(int i = 0; i < comics.size(); i++){
        comics[i].mostrarDatos();
        cout << "---------------------------\n";
    }
}

void Inventario::guardarInventario(){
    ofstream archivo("BDComics.dat");
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
        cout << "No se puede abrir el archivo BDComics.dat";
    }
}

void Inventario::cargarInventario(){
    comics.clear();
    string linea;
    ifstream archivoBD("BDComics.dat");
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
        cout << "No se puede abrir el archivo BDComics.dat\n";
        exit(1);
    }
    archivoBD.close();
}

Inventario::~Inventario(){}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
ComicsAdquiridos::ComicsAdquiridos(){}

void ComicsAdquiridos::pedirNuevosComics(){
    cargarInventarioComicsAdquiridos();

    do {
        this->comicsAdquiridos.emplace(comicsAdquiridos.end());
        int size = comicsAdquiridos.size();
        comicsAdquiridos[size-1].setDatos();

        cout << "Desea continuar (1 - Si, 2 - No): ";
        string answer;
        while(answer != "1" && answer != "2"){
            getline(cin, answer);
        }
        if(answer == "2"){
            break;
        }
        
    } while(true);

    guardarComicsAdquiridos();

    string answer;
    cout << "Desea imprimir la factura?: (1 - Si, 2 - No)";
    while(answer != "1" && answer != "2"){
        getline(cin, answer);
    }
    if(answer == "1"){
        Recibo_lotes_adquiridos *reciboLotes = new Recibo_lotes_adquiridos();
        reciboLotes->imprimirRecibo();
    }
}


void ComicsAdquiridos::cargarInventarioComicsAdquiridos(){
    comicsAdquiridos.clear();
    string linea;
    ifstream archivo("ComicsAdquiridos.dat");
    if(archivo.is_open()){
        int contadorArrayComics = 0, contador = 0;
        while(getline(archivo, linea)){
            if(contador == 0){
                comicsAdquiridos.emplace(comicsAdquiridos.end());
                comicsAdquiridos[contadorArrayComics].setCodigo(linea);
            }
            if(contador == 1)
                comicsAdquiridos[contadorArrayComics].setCompania(linea);
            if(contador == 2)
                comicsAdquiridos[contadorArrayComics].setNombre(linea);
            if(contador == 3)
                comicsAdquiridos[contadorArrayComics].setPrecio(stoi(linea.c_str()));
            if(contador == 4)
                comicsAdquiridos[contadorArrayComics].setFecha(linea);
            if(contador == 5){
                comicsAdquiridos[contadorArrayComics].setNLotes(stoi(linea.c_str())); // cada lote tienen 20 comics
                contadorArrayComics++;
                contador = 0;
                continue;
            }
            contador++;
        }
    } else{
        cout << "No puedo abrir el archivo...";
        archivo.close();
        return;
    }
    archivo.close();
}

void ComicsAdquiridos::organizarLotesAdquiridos(){
    cargarInventarioComicsAdquiridos();
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
            cout << "Comic #" << i+1 << endl;
            comicsAdquiridos[i].mostrarDatos();
            cout << "-------------------------\n";

            int cant = this->comics[indice].getCantidad();
            this->comics[indice].setCantidad(cant + comicsAdquiridos[i].getNLotes() * 20);


            float newPrecio;
            string option;
            cout << "Precio actual en inventario: " << comics[indice].getPrecio() << endl;
            cout << "Precio actual del lote: " << comicsAdquiridos[indice].getPrecio() << endl;
            string _precio;
            while(true){
                cout << "Ingrese el nuevo precio del comic: ";
                getline(cin, _precio);
                if(validarNumero(_precio)){
                    newPrecio = stof(_precio.c_str());
                    break;
                }
            }
            this->comics[indice].setPrecio((float) newPrecio);

            bool oferta = comics[indice].getOferta();
            if(oferta)cout << "El comic esta en oferta" << endl;
            if(!oferta) cout << "El comic no esta en oferta" << endl;
            cout << "Desea cambiar el estado de la oferta? (1-Si, 0-No): ";
            while(option != "1" && option != "0"){
                getline(cin, option);
            }
            if(option == "1") this->comics[indice].setOferta(!oferta);
        } 
        else{
            cout << "Comic #" << i+1 << endl;
            comicsAdquiridos[i].mostrarDatos();
            cout << "-------------------------\n";

            float newPrecio;
            string option;
            this->comics.emplace(comics.end());
            this->comics[comics.size()-1].setCodigo(comicsAdquiridos[i].getCodigo());
            this->comics[comics.size()-1].setCompania(comicsAdquiridos[i].getCompania());
            this->comics[comics.size()-1].setNombre(comicsAdquiridos[i].getNombre());

            cout << "Precio actual del lote: " << comicsAdquiridos[indice].getPrecio() << endl;
            string _precio;
            while(true){
                cout << "Ingrese el nuevo precio del comic: ";
                getline(cin, _precio);
                if(validarNumero(_precio)){
                    newPrecio = stof(_precio.c_str());
                    break;
                } else{
                    cout << "Ingrese un precio valido"<< endl;
                }
            }
            this->comics[comics.size()-1].setPrecio((float) newPrecio);

            this->comics[comics.size()-1].setFecha(comicsAdquiridos[i].getFecha());
            this->comics[comics.size()-1].setCantidad(comicsAdquiridos[i].getNLotes() * 20);

            cout << "El comic esta en oferta? (1-Si, 0-No): ";
            while(option != "1" && option != "0"){
                getline(cin, option);
            }
            if(option == "1") this->comics[comics.size()-1].setOferta(true);
            if(option == "2") this->comics[comics.size()-1].setOferta(false);
        }
    }
    guardarInventario();
    ofstream archivo("ComicsAdquiridos.dat");
    if(archivo.is_open()){
        archivo << ""; 
        archivo.close();
    } else{
        cout << "No se puede abrir el archivo" << endl;
    }
}

void ComicsAdquiridos::mostrarComicsAdquiridos(){
    cargarInventarioComicsAdquiridos();
    cout << "MOSTRANDO LOTES ADQUIRIDOS..." << endl; 
    for(int i = 0; i < comicsAdquiridos.size(); i++){
        comicsAdquiridos[i].mostrarDatos();
        cout << "----------------------" << endl; 
    }
}
        
void ComicsAdquiridos::guardarComicsAdquiridos(){
    ofstream archivo("ComicsAdquiridos.dat");
    if(archivo.is_open()){
        for(int i = 0; i < comicsAdquiridos.size(); i++){
            archivo << comicsAdquiridos[i].getCodigo() << endl;
            archivo << comicsAdquiridos[i].getCompania() << endl;
            archivo << comicsAdquiridos[i].getNombre() << endl;
            archivo << comicsAdquiridos[i].getPrecio() << endl;
            archivo << comicsAdquiridos[i].getFecha() << endl;
            archivo << comicsAdquiridos[i].getNLotes() << endl;
        }
    } else{
        cout << "No se pudo abrir el archivo ComicsAdquiridos" << endl; 
    }
    archivo.close();
}

ComicsAdquiridos::~ComicsAdquiridos(){}
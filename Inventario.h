#include "Comic.h"
#include "Recibo.h"
#include <vector>
#include <fstream>
#include <algorithm>
class Inventario{
    protected:
        vector<Comic> comics;
        int total_comics;
    public:
        Inventario();
        void buscarComic();
        void buscarComicCodigo(string search);
        bool buscarComicNombre(string search);
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

void Inventario::buscarComic(){
    bool ans;
    string nombre, codigo;

    cout << question << "Conoces el codigo del comic? (1 - Si, 2 - No): ";
    ans = validarSiNo();
    if(!ans){
        bool nombreEncontrado = false;
        while(!nombreEncontrado){
            while (nombre.length() <= 3)
            {
               cout << "Ingresa el nombre del comic: ";
                getline(cin, nombre); 
            }
            
            nombreEncontrado = buscarComicNombre(nombre);
            if(!nombreEncontrado){
                cout << "Desea continuar buscando? (1 - Si, 2 - No): ";
                ans = validarSiNo();
                if(!ans) break;
            }
            nombre = "";
        }
    
    } else{
        cout << "Ingrese el codigo del comic: ";
        getline(cin, codigo);
        buscarComicCodigo(codigo);
    }
}


void Inventario::buscarComicCodigo(string search){
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

bool Inventario::buscarComicNombre(string search){
    bool encontrado = false;
    cargarInventario();
    for(int i = 0; i < comics.size(); i++){
        if(toUpper(comics[i].getNombre()).find(toUpper(search)) != string::npos){
            cout << "\nComic encontrado!\n\n";
            encontrado = true;
            comics[i].mostrarDatos();
            cout << endl;
        }
    }
    if(!encontrado){
        cout << "No se encontro el comic llamado " << search << endl;
        return false;
    }
    return true;
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
    string codigo, nombre;
    int indice;

    bool ans;

    cout << question << "Conoces el codigo del comic? (1 - Si, 2 - No): ";
    ans = validarSiNo();

    if(!ans){
        bool nombreEncontrado = false;
        while(!nombreEncontrado){
            while (nombre.length() <= 3)
            {
               cout << "Ingresa el nombre del comic: ";
                getline(cin, nombre); 
            }
            
            nombreEncontrado = buscarComicNombre(nombre);
            if(!nombreEncontrado){
                cout << "Desea continuar buscando? (1 - Si, 2 - No): ";
                ans = validarSiNo();
                if(!ans) break;
            } else{
                break;
            }
        }
    }

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
    buscarComicCodigo(codigo);
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
    string codigo, nombre;
    int indice;
    bool ans;

    cout << question << "Conoces el codigo del comic? (1 - Si, 2 - No): ";
    ans = validarSiNo();

    bool nombreEncontrado = false;
    if(!ans){
        while(!nombreEncontrado){
            while (nombre.length() <= 3)
            {
                cout << "Ingresa el nombre del comic: ";
                getline(cin, nombre); 
            }
            
            nombreEncontrado = buscarComicNombre(nombre);
            if(!nombreEncontrado){
                cout << "Desea continuar buscando? (1 - Si, 2 - No): ";
                ans = validarSiNo();
                if(!ans) break;
            }
            nombre = "";
        }
    }

    if(!nombreEncontrado) return;
    bool encontrado;
    do{
        cout << "Ingresa el codigo del comic vendido: ";
        getline(cin, codigo);
    }while(!validarCodigo(codigo));

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
    cout << "Comic eliminado satisfactoriamente!\n";
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
            archivo << comics[i].getCodigo() << " ";

            string compania = comics[i].getCompania();
            std::replace(compania.begin(), compania.end(), ' ', '-');
            archivo << compania << " ";
            
            string nombre = comics[i].getNombre();
            std::replace(nombre.begin(), nombre.end(), ' ', '-');
            archivo << nombre << " ";

            archivo << comics[i].getPrecio() << " ";
            archivo << comics[i].getFecha() << " ";
            archivo << comics[i].getCantidad() << " ";
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
    ifstream archivoBD;
    archivoBD.open("BDComics.dat");
    string codigo, compania, nombre, precio, fecha, cantidad, oferta;
    if(archivoBD.is_open()){
        int contadorArrayComics = 0, contador = 0;
        while (archivoBD >> codigo >> compania >> nombre >> precio >> fecha >> cantidad >> oferta)
    {
        comics.emplace(comics.end());
        comics[contadorArrayComics].setCodigo(codigo);
        std::replace(compania.begin(), compania.end(), '-', ' ');
        comics[contadorArrayComics].setCompania(compania);
        std::replace(nombre.begin(), nombre.end(), '-', ' ');
        comics[contadorArrayComics].setNombre(nombre);
        comics[contadorArrayComics].setPrecio(stoi(precio.c_str()));
        comics[contadorArrayComics].setFecha(fecha);
        comics[contadorArrayComics].setCantidad(stoi(cantidad.c_str()));
        comics[contadorArrayComics].setOferta(stoi(oferta.c_str()));
        contadorArrayComics++;
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

        cout << "Comic agregado al inventario de Comics Adquiridos\n";

        cout << question << "Desea continuar? (1 - Si, 2 - No): ";
        string answer;
        while(answer != "1" && answer != "2"){
            getline(cin, answer);
            if(answer != "1" && answer != "2") printf("Opcion invalida\n");
        }
        if(answer == "2"){
            break;
        }
        
    } while(true);

    guardarComicsAdquiridos();

    string answer;
    cout << question << "Desea imprimir la factura? (1 - Si, 2 - No): ";
    while(answer != "1" && answer != "2"){
        getline(cin, answer);
        if(answer != "1" && answer != "2") printf("Opcion invalida\n");
    }
    if(answer == "1"){
        Recibo_lotes_adquiridos *reciboLotes = new Recibo_lotes_adquiridos();
        reciboLotes->imprimirRecibo();
    }
}


void ComicsAdquiridos::cargarInventarioComicsAdquiridos(){
    comicsAdquiridos.clear();
    ifstream archivo;
    archivo.open("ComicsAdquiridos.dat");
    string codigo, compania, nombre, precio, fecha, nLotes;
    if(archivo.is_open()){
        int contadorArrayComicsA = 0;
        while (archivo >> codigo >> compania >> nombre >> precio >> fecha >> nLotes){
            comicsAdquiridos.emplace(comicsAdquiridos.end());
            comicsAdquiridos[contadorArrayComicsA].setCodigo(codigo);
            std::replace(compania.begin(), compania.end(), '-', ' ');
            comicsAdquiridos[contadorArrayComicsA].setCompania(compania);
            std::replace(nombre.begin(), nombre.end(), '-', ' ');
            comicsAdquiridos[contadorArrayComicsA].setNombre(nombre);
            comicsAdquiridos[contadorArrayComicsA].setPrecio(stoi(precio.c_str()));
            comicsAdquiridos[contadorArrayComicsA].setFecha(fecha);
            comicsAdquiridos[contadorArrayComicsA].setNLotes(stoi(nLotes.c_str())); // cada lote tienen 20 comics
            contadorArrayComicsA++;
        }
    } else{
        cout << "No puedo abrir el archivo...";
        archivo.close();
        return;
    }
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
            cout << "------------------------------------\n";
            cout << "Comic #" << i+1 << endl << endl;
            comicsAdquiridos[i].mostrarDatos();

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
                if(validarStringVacio(_precio)){
                    if(validarNumero(_precio)){
                        newPrecio = stof(_precio.c_str());
                        break;
                    }
                }
            }
            this->comics[indice].setPrecio((float) newPrecio);
            cout << "Precio actualizado correctamente!" << endl;

            bool oferta = comics[indice].getOferta();
            if(oferta)cout << "El comic esta en oferta" << endl;
            if(!oferta) cout << "El comic no esta en oferta" << endl;
            cout << question << "Desea cambiar el estado de la oferta? (1 - Si, 2 - No): ";
            while(option != "1" && option != "2"){
                getline(cin, option);
                if(option != "1" && option != "2") printf("Opcion invalida\n");
            }
            if(option == "1"){
                this->comics[indice].setOferta(!oferta);
                cout << "El estado de oferta del comic ha sido cambiado correctamente!" << endl;
            }
        } 
        else{
            cout << "------------------------------------\n";
            cout << "Comic #" << i+1 << endl;
            comicsAdquiridos[i].mostrarDatos();

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
                if(validarStringVacio(_precio)){
                    if(validarNumero(_precio)){
                        newPrecio = stof(_precio.c_str());
                        break;
                    } else{
                        cout << "Ingrese un precio valido"<< endl;
                    }
                }
            }
            this->comics[comics.size()-1].setPrecio((float) newPrecio);
            cout << "Precio actualizado correctamente!" << endl;

            this->comics[comics.size()-1].setFecha(comicsAdquiridos[i].getFecha());
            this->comics[comics.size()-1].setCantidad(comicsAdquiridos[i].getNLotes() * 20);

            cout << question << "El comic esta en oferta? (1 - Si, 2 - No): ";
            while(option != "1" && option != "2"){
                getline(cin, option);
                if(option != "1" && option != "2") printf("Opcion invalida\n");
            }
            if(option == "1") this->comics[comics.size()-1].setOferta(true);
            if(option == "2") this->comics[comics.size()-1].setOferta(false);
            cout << "Estado de oferta del comic establecido correctamente!" << endl;
        }
    }
    guardarInventario();
    cout << "\nTodos los comics han sido organizados correctamente en el inventario de comics\n";
    ofstream archivo("ComicsAdquiridos.dat");
    if(archivo.is_open()){
        archivo << ""; 
        archivo.close();
    } else{
        cout << "No se puede abrir el archivo 'ComicsAdquiridos.dat'" << endl;
    }
    cout << "El inventario de Comics Adquiridos ha sido actualizado correctamente!\n";
}

void ComicsAdquiridos::mostrarComicsAdquiridos(){
    cargarInventarioComicsAdquiridos();
    cout << "-- MOSTRANDO LOTES ADQUIRIDOS --" << endl; 
    for(int i = 0; i < comicsAdquiridos.size(); i++){
        comicsAdquiridos[i].mostrarDatos();
        cout << "------------------------------------\n"; 
    }
}
        
void ComicsAdquiridos::guardarComicsAdquiridos(){
    ofstream archivo("ComicsAdquiridos.dat");
    if(archivo.is_open()){
        for(int i = 0; i < comicsAdquiridos.size(); i++){
            archivo << comicsAdquiridos[i].getCodigo() << " ";
            
            string compania = comicsAdquiridos[i].getCompania();
            std::replace(compania.begin(), compania.end(), ' ', '-');
            archivo << compania << " ";

            string nombre = comicsAdquiridos[i].getNombre();
            std::replace(nombre.begin(), nombre.end(), ' ', '-');
            archivo << nombre << " ";

            archivo << comicsAdquiridos[i].getPrecio() << " ";
            archivo << comicsAdquiridos[i].getFecha() << " ";
            archivo << comicsAdquiridos[i].getNLotes() << endl;
        }
    } else{
        cout << "No se pudo abrir el archivo 'ComicsAdquiridos.dat'" << endl; 
    }
    archivo.close();
}

ComicsAdquiridos::~ComicsAdquiridos(){}
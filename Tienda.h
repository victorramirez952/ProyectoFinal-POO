#include "vector"
#include "fstream"
#include "Recibo.h"
class Tienda : public Recibo_lotes_adquiridos{
    private:
        // vector<Comic> comics;
        // vector<Categorias> categorias;
    public:
        Tienda();
        void pedirNuevosComics();
        void organizarLotesAdquiridos();
        ~Tienda();
};

// derivaciones

Tienda::Tienda(){}

void Tienda::pedirNuevosComics(){
    string compania, comic, answer, codigo;
    int dia, mes, anio, nLotes, totalLotes;
    float precio;
    bool continuar = true;

    ofstream objetoArchivo("ComicsAdquiridos.txt");

    do {
        cout << "Ingresa la compania: ";
        getline(cin, compania);
        cout << "Ingresa el nombre del comic: ";
        getline(cin, comic);
        cout << "Ingresa el precio individual del comic: ";
        cin >> precio;
        cout << "Ingresa el codigo del comic: ";
        cin.ignore();
        getline(cin, codigo);
        cout << "Ingresa el dia de publicacion: ";
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
            objetoArchivo << compania << endl;
            objetoArchivo << comic << endl;
            objetoArchivo << precio << endl;
            objetoArchivo << codigo << endl;
            objetoArchivo << dia << endl;
            objetoArchivo << mes << endl;
            objetoArchivo << anio << endl;
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

void Tienda::organizarLotesAdquiridos(){
    // ifstream archivoComicsAdquiridos("ComicsAdquiridos.txt");
}

Tienda::~Tienda(){}

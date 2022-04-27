#include "vector"
#include "fstream"
class ComicsAdquiridos{
    private:
        vector<Comic> comicsAdquiridos;
    public:
        ComicsAdquiridos();
        // void establecerComicsAdquiridos();
        void organizarLotesAdquiridos();
        void pedirNuevosComics();
        ~ComicsAdquiridos();
};

ComicsAdquiridos::ComicsAdquiridos(){}

// void ComicsAdquiridos::establecerComicsAdquiridos(){
//     string linea;
//     ifstream objetoArchivo("ComicsAdquiridos.txt");
//     int contador = 0, contadorArray = 0;
//     if(objetoArchivo.is_open()){
//         while(getline(objetoArchivo, linea)){
//             if(contador == 0){
//                 comicsAdquiridos.emplace(comicsAdquiridos.end());
//                 ComicsAdquiridos[contadorArray]; 
//             }
//         }
//         objetoArchivo.close();
//     } else{
//         cout << "No puedo abrir el archivo...";
//     }
// }

void Gerente::pedirNuevosComics(){
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

void ComicsAdquiridos::organizarLotesAdquiridos(){}

ComicsAdquiridos::~ComicsAdquiridos(){}

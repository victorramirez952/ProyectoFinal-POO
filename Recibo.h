#include "vector"
#include "fstream"

class Recibo{
    public:
        Recibo();
        virtual void imprimirRecibo();
        ~Recibo();
};

class Recibo_del_cliente : public Recibo{
    private:
        string nombre_vendedor;
        vector<string> comics;
        vector<string> codigos;
        vector<float> precio_individual;
        int cantidad;
    public:
        Recibo_del_cliente();
        void imprimirRecibo(string _vendedor, float total, vector<string> comicsComprados, vector<string> _codigos, vector<float> preciosComics, vector<int> cantidades, int pagoCliente);
        ~Recibo_del_cliente();
};

class Recibo_lotes_adquiridos : public Recibo{
    private:
        string nombre_distribuidor;
        int cantidad_lotes_comprados;
        vector<string> nombres_de_comics;
        vector<int> precio_lotes;
    public:
        Recibo_lotes_adquiridos();
        void imprimirRecibo();
        ~Recibo_lotes_adquiridos();
};

////////////////////////////////////////////////////////////////
// derivaciones
// Recibo
Recibo::Recibo(){}

void Recibo::imprimirRecibo(){
    cout << "\n************************************\n";
    cout << "-- RECIBO LOTES ADQUIRIDOS --\n";
    cout << "Proveedor: Comics SA\n";
    cout << "Tienda: " << nombreTienda << "\n";
    cout << "Fecha de compra: " << getFechaActual() << "\n";
    cout << "Hora de compra: " << getHoraActual() << " hrs\n";
    cout << "************************************\n";
}

Recibo::~Recibo(){}

////////////////////////////////////////////////////////////////
// RECIBO/FACTURA DEL CLIENTE
Recibo_del_cliente::Recibo_del_cliente(){}

void Recibo_del_cliente::imprimirRecibo(string _vendedor, float total, vector<string> comicsComprados, vector<string> _codigos, vector<float> preciosComics, vector<int> cantidades, int pagoCliente){
    cout << "\n------- RECIBO DEL CLIENTE --------\n";
    cout << "************************************\n";
    cout << "Sucursal: " <<  nombreTienda << "\n";
    cout << "Fecha: " << getFechaActual() << endl;
    cout << "Hora: " << getHoraActual() << endl; 
    cout << "Vendedor: " << _vendedor << endl;
    cout << "************************************\n";
    int sizeArray = comicsComprados.size();
    for(int i = 0; i < sizeArray; i++){
        cout << "Comic: " << comicsComprados[i] << endl;
        cout << "Codigo: " << _codigos[i] << endl;
        cout << "Precio: " << preciosComics[i] << endl;
        cout << "Cantidad: " << cantidades[i] << endl; 
        if(i != sizeArray-1){
            cout << "------------------------------------\n";
        }
    }
    cout << "************************************\n";
    cout << "Total: " << total << " MXN\n";
    cout << "Pago con: " << pagoCliente << " MXN\n";
    cout << "Su cambio: " << pagoCliente-total << " MXN\n"; 
    cout << "************************************\n\n";
}

Recibo_del_cliente::~Recibo_del_cliente(){}

////////////////////////////////////////////////////////////////
// RECIBO LOTES ADQUIRIDOS
Recibo_lotes_adquiridos::Recibo_lotes_adquiridos(){}

void Recibo_lotes_adquiridos::imprimirRecibo(){
    Recibo::imprimirRecibo();
    string linea;
    int contador = 0, precio_individual = 0, totalLotes = 0, total = 0;
    ifstream archivoComicsAdquiridos("ComicsAdquiridos.dat");
    if(archivoComicsAdquiridos.is_open()){
        while(getline(archivoComicsAdquiridos, linea)){
            if(contador == 0){
                cout << "Codigo: " << linea << endl;
            }
            if(contador == 1) cout << "Compania: " << linea << "\n";
            if(contador == 2) cout << "Comic: " << linea << "\n";
            if(contador == 3){
                precio_individual = stoi(linea.c_str());
                cout << "Precio: " << precio_individual << endl;
            }
            if(contador == 4){
                cout << "Fecha publicacion: " << linea << endl;
            }
            if(contador == 5){
                int totalPorComic = 20 * precio_individual * stoi(linea.c_str());
                total += totalPorComic;

                cout << "Cantidad de lotes: " << linea << endl;
                totalLotes += stoi(linea.c_str());

                cout << "Total por este comic: " << totalPorComic << " MXN" << endl;
                contador = 0;
                cout << "------------------------------------\n";
                continue;
            }
            contador++;
        }
        archivoComicsAdquiridos.close();
    } else{
        cout << "No se pudo abrir el archivo 'ComicsAdquiridos.dat.";
    }
    cout << "\n************************************\n";
    cout << "Cantidad total de lotes comprados: " << totalLotes << endl;
    cout << "Total a pagar: " << total <<  " MXN" << endl;
    cout << "************************************\n\n";
}

Recibo_lotes_adquiridos::~Recibo_lotes_adquiridos(){}

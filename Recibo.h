#include "vector"
#include "fstream"
class Recibo{
    private:
        float subtotal, iva, total_a_pagar;
        string fecha, hora, tipo_de_pago, nombre_tienda;
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
        void imprimirRecibo(string _vendedor, string fecha, float total, vector<string> comicsComprados, vector<string> _codigos, vector<float> preciosComics, vector<int> cantidades);
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
    cout << "************************************\n";
    cout << "RECIBO LOTES ADQUIRIDOS\n";
    cout << "Proveedor: Comics SA\n";
    cout << "Tienda: La cueva del comic\n";
    cout << "Fecha de compra: 25/04/2022\n";
    cout << "Hora de compra: 16:00 hrs\n";
    cout << "************************************\n";
}

Recibo::~Recibo(){}

////////////////////////////////////////////////////////////////
// RECIBO/FACTURA DEL CLIENTE
Recibo_del_cliente::Recibo_del_cliente(){}

void Recibo_del_cliente::imprimirRecibo(string _vendedor, string fecha, float total, vector<string> comicsComprados, vector<string> _codigos, vector<float> preciosComics, vector<int> cantidades){
    cout << "------- Recibo del Cliente --------\n";
    cout << "Sucursal: La cueva del Comic\n";
    cout << "Fecha: " << fecha << endl;
    cout << "Vendedor: " << _vendedor << endl;
    cout << "***********************\n";
    for(int i = 0; i < comicsComprados.size(); i++){
        cout << "Comic: " << comicsComprados[i] << endl;
        cout << "Codigo: " << _codigos[i] << endl;
        cout << "Precio: " << preciosComics[i] << endl;
        cout << "Cantidad: " << cantidades[i] << endl; 
        cout << "------------" << endl;
    }
    cout << "Total: " << total << " MXN\n";
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

                cout << "Total por este comic: " << totalPorComic << endl;
                contador = 0;
                cout << "----------------------------------------\n";
                continue;
            }
            contador++;
        }
        archivoComicsAdquiridos.close();
    } else{
        cout << "No se puede abrir el archivo...";
    }
    cout << "**********************" << endl;
    cout << "Cantidad total de lotes comprados: " << totalLotes << endl;
    cout << "Total a pagar: " << total << endl << endl;
}

Recibo_lotes_adquiridos::~Recibo_lotes_adquiridos(){}

#include "vector"
#include "fstream"
class Recibo{
    private:
        float subtotal, iva, total_a_pagar;
        string fecha, hora, tipo_de_pago, nombre_tienda;
    public:
        Recibo();
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
        void imprimirRecibo(int totalLotes);
        ~Recibo_lotes_adquiridos();
};

// derivaciones
// Recibo
Recibo::Recibo(){}

Recibo::~Recibo(){}

// Recibo cliente
Recibo_del_cliente::Recibo_del_cliente(){}

Recibo_del_cliente::~Recibo_del_cliente(){}

// Recibo lotes adquiridos
Recibo_lotes_adquiridos::Recibo_lotes_adquiridos(){}

void Recibo_lotes_adquiridos::imprimirRecibo(int totalLotes){
    string linea;
    int contador = 0, precio_individual = 0, total = 0;
    ifstream archivoComicsAdquiridos("ComicsAdquiridos.txt");

    cout << "************************************\n";
    cout << "Proveedor: Comics SA\n";
    cout << "Tienda: La cueva del comic\n";
    cout << "Fecha de compra: 25/04/2022\n";
    cout << "Hora de compra: 16:00 hrs\n";
    cout << "Cantidad total de lotes comprados: " << totalLotes << endl;
    cout << "************************************\n";
    if(archivoComicsAdquiridos.is_open()){
        while(getline(archivoComicsAdquiridos, linea)){
            if(contador == 0){
                cout << "Codigo: " << linea << endl;
            }
            if(contador == 1) cout << "Compania: " << linea << "\n";
            if(contador == 2) cout << "Comic: " << linea << "\n";
            if(contador == 3){
                cout << "Precio: " << stoi(linea.c_str()) << endl;
                precio_individual = stoi(linea.c_str());
            }
            if(contador == 4){
                cout << "Fecha publicacion: " << linea << endl;
            }
            if(contador == 5){
                int totalPorComic = precio_individual * stoi(linea);
                cout << "Cantidad de lotes: " << linea << endl;
                total += totalPorComic;
                cout << "Total por este comic: " << totalPorComic << endl;
                contador = 0;
                cout << "--  --\n";
                continue;
            }
            contador++;
        }
        archivoComicsAdquiridos.close();
    } else{
        cout << "No se puede abrir el archivo...";
    }
    cout << "**********************" << endl;
    cout << "Total a pagar: " << total << endl;
}

Recibo_lotes_adquiridos::~Recibo_lotes_adquiridos(){}

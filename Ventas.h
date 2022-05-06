#include "vector"
class Ventas : public Inventario{
    private:
        float total_ganado, ventas_totales;
        vector<string> codigos;
        vector<string> fechasVenta;
        vector<string> vendedores;
        vector<int> cantidadVendida; 
        vector<float> preciosComics;
    public:
        Ventas();
        void agregarVentas(vector<string> _codigos, vector<float> preciosIndividuales, vector<int> cantidadesVendidas, string vendedor);
        void mostrarDatosVentas();
        void guardarVentas();
        void cargarVentas();
        ~Ventas();
};

/////////////////////////////////////////////
// Derivaciones
Ventas::Ventas(){
    cargarVentas();
}

void Ventas::agregarVentas(vector<string> _codigos, vector<float> preciosIndividuales, vector<int> cantidadesVendidas, string vendedor){
    // _codigos son los nuevos codigos que llegan
    // codigos son los que ya estaban en el archivo
    bool encontrado;
    int indice;
    for(int i = 0; i < _codigos.size(); i++){
        encontrado = false;
        for(int j = 0; j < codigos.size(); j++){
            if(_codigos[i] == codigos[j]){
                encontrado = true;
                indice = j;
                break;
            }
        }
        if(encontrado){
            fechasVenta[indice] = getFechaActual();
            cantidadVendida[indice] += cantidadesVendidas[i];
            if(vendedores[indice].find(vendedor) == std::string::npos){
                vendedores[indice] += ", " + vendedor;
            }
        } else{
            codigos.push_back(_codigos[i]);    
            fechasVenta.push_back(getFechaActual());
            vendedores.push_back(vendedor);
            cantidadVendida.push_back(1);
            preciosComics.push_back(preciosIndividuales[i]);
        }
    }
    guardarVentas();
}

void Ventas::mostrarDatosVentas(){
    cargarVentas();
    cout << "-- Ventas --\n";
    cout << "\n************************************\n";
    int sizeArray = codigos.size();
    for(int i = 0; i < codigos.size(); i++){
        cout << "Codigo: " << codigos[i] << endl;
        cout << "Fecha de venta mas reciente: " << fechasVenta[i] << endl;
        cout << "Vendido por: " << vendedores[i] << endl;
        cout << "Cantidad total vendida: " << cantidadVendida[i] << endl;
        cout << "Precio del comic vendido: " << preciosComics[i] << endl;
        if(i != sizeArray-1){
            cout << "------------------------------------\n";
        }
    }
    cout << "\n************************************\n";
    cout << "Cantidad total de comics vendidos: " << this->ventas_totales << endl;
    cout << "Total Ganado: " << this->total_ganado << " MXN" << endl;
}

void Ventas::guardarVentas(){
    ofstream archivo("Ventas.dat");
    if(archivo.is_open()){
        for(int i = 0; i < codigos.size(); i++){
            archivo << codigos[i] << endl;
            archivo << fechasVenta[i] << endl;
            archivo << vendedores[i] << endl;
            archivo << cantidadVendida[i] << endl;
            archivo << preciosComics[i] << endl;
        }
    } else{
        cout << "No se pudo abrir el archivo" << endl;
    }
}

void Ventas::cargarVentas(){
    codigos.clear();
    fechasVenta.clear();
    vendedores.clear();
    cantidadVendida.clear();
    ventas_totales = 0;
    total_ganado = 0;

    string linea;
    ifstream archivo("Ventas.dat");
    int contador = 0, contadorArrayComics = 0;
    if(archivo.is_open()){
        int cantComicsVendidos;
        while(getline(archivo, linea)){
            if(contador == 0){
                codigos.push_back(linea);
            }
            if(contador == 1){
                fechasVenta.push_back(linea);
            }
            if(contador == 2){
                vendedores.push_back(linea);
            }
            if(contador == 3){
                cantComicsVendidos = stoi(linea.c_str());
                this->ventas_totales += cantComicsVendidos;
                cantidadVendida.push_back(cantComicsVendidos);
            }
            if(contador == 4){
                int precioIndividual = stoi(linea.c_str());
                preciosComics.push_back(precioIndividual);

                this->total_ganado += precioIndividual * cantComicsVendidos;
                cantComicsVendidos = 0;

                contadorArrayComics++;
                contador = 0;
                continue;
            }
            contador++;
        }
    } else{
        cout << "No se pudo abrir el archivo" << endl;
    }
}

Ventas::~Ventas(){}
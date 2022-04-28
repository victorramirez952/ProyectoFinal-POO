#include "vector"
class Ventas : public Inventario{
    private:
        float promedio_ventas, total_ganado, ventas_totales;
        vector<string> codigos;
        vector<string> fechasVenta;
        vector<string> vendedores;
        vector<int> cantidadVendida; 
    public:
        Ventas();
        void agregarVentas(vector<string> _codigos, string fecha, string vendedor);
        void mostrarDatosVentas();
        void actualizarVentas();
        void refrescarVentas();
        ~Ventas();
};

/////////////////////////////////////////////
// Derivaciones
Ventas::Ventas(){
    refrescarVentas();
}

void Ventas::agregarVentas(vector<string> _codigos, string fecha, string vendedor){
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
            fechasVenta[indice] = fecha;
            cantidadVendida[indice] += 1;
            if(vendedores[indice].find(vendedor) == std::string::npos){
                vendedores[indice] += ", " + vendedor;
            }
        } else{
            codigos.push_back(_codigos[i]);    
            fechasVenta.push_back(fecha);
            vendedores.push_back(vendedor);
            cantidadVendida.push_back(1);
        }
    }
    actualizarVentas();
}

void Ventas::mostrarDatosVentas(){
    refrescarVentas();
    cout << "***********************************\n";
    for(int i = 0; i < codigos.size(); i++){
        cout << codigos[i] << endl;
        cout << fechasVenta[i] << endl;
        cout << vendedores[i] << endl;
        cout << cantidadVendida[i] << endl;
        cout << "-----------------\n";
    }
    cout << "Cantidad total vendida: " << ventas_totales << endl;
    cout << "Total Ganado: " << total_ganado << endl;
}

void Ventas::actualizarVentas(){
    ofstream archivo("Ventas.txt");
    if(archivo.is_open()){
        for(int i = 0; i < codigos.size(); i++){
            archivo << codigos[i] << endl;
            archivo << fechasVenta[i] << endl;
            archivo << vendedores[i] << endl;
            archivo << cantidadVendida[i] << endl;
        }
    } else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    
}

void Ventas::refrescarVentas(){
    float ventasTotales = 0, totalGanado = 0;
    string linea;
    ifstream archivo("Ventas.txt");
    int contador = 0, contadorArrayComics = 0;
    if(archivo.is_open()){
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
                int cantComicsVendidos = stoi(linea.c_str());
                ventasTotales += cantComicsVendidos;
                cantidadVendida.push_back(cantComicsVendidos);

                totalGanado += comics[contadorArrayComics].getPrecio() * cantComicsVendidos;

                contadorArrayComics++;
                contador = 0;
                continue;
            }
            contador++;
        }
        this->ventas_totales = ventasTotales;
        this->total_ganado = totalGanado;
    } else{
        cout << "No se pudo abrir el archivo" << endl;
    }
}

Ventas::~Ventas(){}
#include "fstream"
#include "vector"
class Persona{
    protected:
        string nombre, rfc;
    public:
        Persona();
        Persona(string _nombre, string _rfc);
        ~Persona();
};

class Empleado : public Persona, public Inventario{
    private:
        int asistenciaEmpleado = 0;
        float sueldo;
    public:
        Empleado();
        Empleado(string _nombre, string _rfc);
        void setDatos(string _nombre, string _rfc, float sueldo);
        void setNombre(string _nombre);
        void setRFC(string _rfc);
        void setSueldo(float _sueldo);
        void setAsistencia(int _asistencia);

        string getRFC();
        string getNombre();
        float getSueldo();
        int getAsistencia();

        void venderComics();
        void mostrarDatos();
        ~Empleado();
};

class Empleados{
    protected:
        vector<Empleado> empleados;
    public:
        Empleados();
        void mostrarEmpleados();
        void actualizarEmpleados();
        ~Empleados();
};

class Gerente : public Persona, public Empleados{
    private:
    public:
        Gerente();
        Gerente(string _nombre, string _rfc);
        void registroNuevoEmpleado();
        void mostrarRegistrosEmpleados();

        void registrarAsistenciaEmpleados();
        void mostrarSueldoAPagarEmpleados();
        ~Gerente();
};

// Inicialización de clases
// Persona
Persona::Persona(){}

Persona::Persona(string _nombre, string _rfc){}

Persona::~Persona(){}

//////////////////////////////////////////////////////////////////77
// Empleado
Empleado::Empleado(){}

Empleado::Empleado(string _nombre, string _rfc){}

void Empleado::setDatos(string _nombre, string _rfc, float _sueldo){
    this->nombre = _nombre;
    this->rfc = _rfc;
    this->sueldo = _sueldo;
}

void Empleado::setNombre(string _nombre){
    this->nombre = _nombre;
}

void Empleado::setRFC(string _rfc){
    this->rfc = _rfc;
}

void Empleado::setSueldo(float _sueldo){
    this->sueldo = _sueldo;
}

void Empleado::setAsistencia(int _asistencia){
    this->asistenciaEmpleado = _asistencia;
}

string Empleado::getRFC(){
    return this->rfc;
}

string Empleado::getNombre(){
    return this->nombre;
}

float Empleado::getSueldo(){
    return this->sueldo;
}

int Empleado::getAsistencia(){
    return this->asistenciaEmpleado;
}



void Empleado::venderComics(){
    string codigo;
    int nComics;
    float total;
    int NIP;
    string pagar;


    cout << "Cuantos comics vas a llevar? ";
    cin >> nComics;
    int indice = 0;
    
    cin.ignore();
    for(int i = 0; i < nComics; i++){
        cout << "Ingresa el codigo del comic: ";
        getline(cin, codigo);
        for(int j = 0; j < comics.size(); j++){
            if(comics[j].getCodigo() == codigo){
                indice = j;
                break;
            }
        }
        float precioComic = comics[indice].getPrecio();
        int cantidad = comics[indice].getCantidad();
        total += precioComic;
        comics[indice].setCantidad(cantidad-1);
    }
    mostrarInventario();
    cout << "El total a pagar es: " << total << endl;

    // cout << "Ingrese su metodo de pago (Efectivo/Tarjeta) ";
    // cin >> pagar;
    // if(pagar == "tarjeta"){
    //     cout << "Ingrese su NIP: ";
    //     cin >> NIP;
    //     cout << endl << "*Recibo*" << endl; //imprimirRecibo
    //     cout << "Gracias por su compra! "; 
    // }
    // else if (pagar == "efectivo"){
    //     int cantidadCliente;
    //     cout << "Ingrese la cantidad con la que pagara: ";
    //     cin >> cantidadCliente;
    //     if(total < cantidadCliente){
    //         cout << "El cambio a regresar: " << cantidadCliente - total << endl;
    //         cout << "*Recibo*" << endl;
    //         cout << "Gracias por su compra! ";
    //     }
    //     else if (total = cantidadCliente){
    //         cout << "*Recibo*" << endl;
    //         cout << "Gracias por su compra! ";
    //     } 
    // }
}

void Empleado::mostrarDatos(){
    cout << this->rfc << endl;
    cout << this->nombre << endl;
    cout << this->sueldo << endl;
    cout << this->asistenciaEmpleado << endl;
}

Empleado::~Empleado(){}

//////////////////////////////////////////////////////////
// Empleados
Empleados::Empleados(){
    string linea;
    ifstream archivo("Empleados.txt");
    int contador = 0, contadorArray = 0;
    if(archivo.is_open()){
        while(getline(archivo, linea)){
            if(contador == 0){
                empleados.emplace(empleados.end());
                empleados[contadorArray].setRFC(linea);
            }
            if(contador == 1){
                empleados[contadorArray].setNombre(linea);
            }
            if(contador == 2){
                empleados[contadorArray].setSueldo(stof(linea));
            }
            if(contador == 3){
                empleados[contadorArray].setAsistencia(stoi(linea.c_str()));
                contador = 0;
                contadorArray++;
                continue;
            }
            contador++;
        }
    } else{
        cout << "No se pudo abrir el archivo\n";
    }
    archivo.close();
}

void Empleados::mostrarEmpleados(){
    for(int i = 0; i < empleados.size(); i++){
        empleados[i].mostrarDatos();
    }
}

void Empleados::actualizarEmpleados(){
    ofstream archivo("Empleados.txt");
    if(archivo.is_open()){
        for(int i = 0; i < empleados.size(); i++){
            archivo << empleados[i].getRFC() << endl;
            archivo << empleados[i].getNombre() << endl;
            archivo << empleados[i].getSueldo() << endl;
            archivo << empleados[i].getAsistencia() << endl;
        }
        archivo.close();
    } else{
        cout << "No puede abrir el archivo";
    }
}

Empleados::~Empleados(){}

///////////////////////////////////////////////
// Gerente
Gerente::Gerente(){}

Gerente::Gerente(string _nombre, string _rfc){
    this->nombre = _nombre;
    this->rfc = _rfc;
}

void Gerente::registroNuevoEmpleado(){
    string nombre, rfc;
    float sueldo;
    empleados.emplace(empleados.end());
    cout << "Ingresa el nombre del empleado: ";
    getline(cin, nombre);
    cout << "Ingresa el rfc del empleado: ";
    getline(cin, rfc);
    cout << "Ingresa el sueldo del empleado: ";
    cin >> sueldo;
    empleados[empleados.size()-1].setDatos(nombre, rfc, sueldo);
    actualizarEmpleados();
}

void Gerente::registrarAsistenciaEmpleados(){
    int asistenciaEmpleado;
    for(int i = 0; i < empleados.size(); i++){
        cout << "Asistencia de " << empleados[i].getNombre() << endl;
        cout << "[1] Asisitio   [0] No asistio ";
        cin >> asistenciaEmpleado;
        if(asistenciaEmpleado != 1) continue;
        int asistencia = empleados[i].getAsistencia();
        empleados[i].setAsistencia(asistencia + 1);
        // cout << "Desea continuar? (1) Si    (0) No " << endl;
        // cin >> repetir;
    }
    actualizarEmpleados();
    cout << "Informacion actualizada\n";
}

void Gerente::mostrarSueldoAPagarEmpleados(){
    cout << "------------------------" << endl;
    for(int i = 0; i < empleados.size(); i++){
        Empleado empleadoi = empleados[i];
        cout << "Nombre empleado: " << empleadoi.getNombre() << endl;
        int asistencia = empleadoi.getAsistencia();
        cout << "Asistencia del empleado (dias): " << asistencia << endl;
        cout << "Total a pagar: " << empleadoi.getSueldo() * asistencia << endl;
        cout << "------------------------" << endl;
    }
}

Gerente::~Gerente(){}

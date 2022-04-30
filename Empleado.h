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

        void modificarDatos();

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
        void cargarEmpleados();
        void mostrarEmpleados();
        void guardarEmpleados();
        ~Empleados();
};

class Gerente : public Persona, public Empleados{
    private:
    public:
        Gerente();
        Gerente(string _nombre, string _rfc);
        void registrarNuevoEmpleado();
        void eliminarEmpleado();
        void editarEmpleado();
        void resetAsistencias();
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

//Funcion utilizada para modificar datos
bool modificarE(string text){
    string option;
    cout << "Deseas modificar " << text << "? (1 - Si, 2 - No): " << endl;
    getline(cin, option);
    if(option == "1"){
        return true;
    }
    return false;
}

void Empleado::modificarDatos(){
    cout << "RFC: " << this->rfc << endl;
    if(modificarE("el RFC")){
        cout << "Ingresa el nuevo RFC: ";
        getline(cin, this->rfc);
    }

    cout << "Nombre: " << this->nombre << endl;
    if(modificarE("el nombre del empleado")){
        cout << "Ingresa el nuevo nombre: ";
        getline(cin, this->nombre);
    }

    cout << "Sueldo: " << this->sueldo << endl;
    if(modificarE("el sueldo")){
        cout << "Ingresa el sueldo: ";
        cin >> this->sueldo;
        cin.ignore();
    }

    cout << "Asistencia: " << this->asistenciaEmpleado << endl;
    if(modificarE("la asistencia")){
        cout << "Ingresa la nueva asistencia: ";
        cin >> asistenciaEmpleado;
        cin.ignore();
    }
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
    float total;

    vector<string> codigosComics;
    vector<string> comicsComprados; //Nombres de Comics
    vector<float> preciosIndividuales;
    vector<int> cantidadesCompradas;

    int contador = 0;
    while(true){
        cout << "Sugerencia temporal (ASW202219 / GLX202224) " << endl;
        cout << "Ingresa el codigo del comic: ";
        getline(cin, codigo);

        int indice = buscarIndiceComic(codigo);
        if(indice < 0){
            continue;
        }

        comicsComprados.push_back(comics[indice].getNombre());
        codigosComics.push_back(comics[indice].getCodigo());
        float precioComic = comics[indice].getPrecio();
        preciosIndividuales.push_back(precioComic);

        int cantidadDisponible = comics[indice].getCantidad();
        int cantidad;

        while(true){
            cout << "Cuantos ejemplares se llevara el cliente de este comic? ";
            cin >> cantidad;
            cin.ignore();
            if(cantidadDisponible < cantidad){
                cout << "No quedan suficientes ejemplares disponibles\n";
                cout << "Ingrese otra cantidad\n";
                continue;
            }
            cantidadesCompradas.push_back(cantidad);
            break;
        }
        
        comics[indice].setCantidad(cantidadDisponible - cantidad);
        total += precioComic * cantidad;
        contador++;

        string option;
        cout << "Desea agregar otro comic? (1 - Si, 2 - No): ";
        getline(cin, option);
        if(option != "1") break;
    }

    string vendedor;
    string fecha; // Usada tambien en Recibo_del_cliente
    
    cout << "Ingresar nombre del vendedor: ";
    getline(cin, vendedor);

    cout << "Ingresa la fecha (DD/MM/AA): ";
    getline(cin, fecha);

    string pagar;
    int NIP;
    cout << "El total a pagar es: " << total << " MXN" << endl;
    while (true){   
        cout << "Ingrese su metodo de pago (1 - Efectivo/ 2 - Tarjeta): ";
        getline(cin, pagar);
        if(pagar == "1" | pagar == "2") break;
    }
    
    if(pagar == "2"){
        cout << "Ingrese su NIP: ";
        cin >> NIP;
    }
    else if (pagar == "1"){
        int pagoCliente;
        while(true){
            cout << "Ingrese la cantidad con la que pagara: ";
            cin >> pagoCliente;
            if(pagoCliente < total){
                cout << "El total a pagar es mayor!\n";
                cout << "Ingrese nuevamente el pago del cliente\n";
                continue;
            }
            if(total <= pagoCliente){
                cout << "El cambio a regresar: " << pagoCliente - total << endl;
                break;
            }
        }
    }

    cout << "Pago realizado!" << endl;

    Recibo_del_cliente *recibo = new Recibo_del_cliente();
    recibo->imprimirRecibo(vendedor, fecha, total, comicsComprados, codigosComics, preciosIndividuales, cantidadesCompradas);
    cout << "Gracias por su compra!" << endl;
    
    guardarInventario();

    Ventas *ventas = new Ventas();
    ventas->agregarVentas(codigosComics, preciosIndividuales, cantidadesCompradas, fecha, vendedor);
}

void Empleado::mostrarDatos(){
    cout << "RFC: " << this->rfc << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Sueldo: " << this->sueldo << " semanales" << endl;
    cout << "Dias asistidos: " << this->asistenciaEmpleado << endl;
}

Empleado::~Empleado(){}

//////////////////////////////////////////////////////////
// Empleados
Empleados::Empleados(){
    cargarEmpleados();
}

void Empleados::cargarEmpleados(){
    empleados.clear();
    string linea;
    ifstream archivo("Empleados.dat");
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
    cargarEmpleados();
    cout << "---------------------------------" << endl;
    for(int i = 0; i < empleados.size(); i++){
        empleados[i].mostrarDatos();
        cout << "------------------------" << endl;
    }
}

void Empleados::guardarEmpleados(){
    ofstream archivo("Empleados.dat");
    if(archivo.is_open()){
        for(int i = 0; i < empleados.size(); i++){
            archivo << empleados[i].getRFC() << endl;
            archivo << empleados[i].getNombre() << endl;
            archivo << empleados[i].getSueldo() << endl;
            archivo << empleados[i].getAsistencia() << endl;
        }
        archivo.close();
    } else{
        cout << "No se puede abrir el archivo" << endl;
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

void Gerente::registrarNuevoEmpleado(){
    cargarEmpleados();
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
    guardarEmpleados();
}

void Gerente::eliminarEmpleado(){
    string rfc;
    int indice;
    bool encontrado;
    cout << "Ingresa el rfc del empleado a eliminar: ";
    getline(cin, rfc);
    for(int i = 0; i < empleados.size(); i++){
        if(empleados[i].getRFC() == rfc){
            encontrado = true;
            indice = i;
        }
    }
    if(!encontrado){
        cout << "No se encontro el empleado\n";
        return;
    }
    empleados.erase(empleados.begin()+indice);
    guardarEmpleados();
    cout << "Empleado eliminado!" << endl;
}

void Gerente::resetAsistencias(){
    cargarEmpleados();
    for(int i= 0; i < empleados.size(); i++){
        empleados[i].setAsistencia(0);
    }
    guardarEmpleados();
}

void Gerente::editarEmpleado(){
    cargarEmpleados();
    string rfc;
    int indice;

    bool encontrado = false;
    cout << "Ingresa el RFC del empleado que vas a editar: ";
    getline(cin, rfc);
    for(int i = 0; i < empleados.size(); i++){
        if(empleados[i].getRFC() == rfc){
            empleados[i].mostrarDatos();
            encontrado = true;
            indice = i;
            break;
        }
    }
    if(!encontrado){
        cout << "No se encontro el empleado\n";
        return;
    }
    empleados[indice].modificarDatos();
    guardarEmpleados();
    cout << "Empleado actualizado correctamente!" << endl;
}

void Gerente::registrarAsistenciaEmpleados(){
    cargarEmpleados();
    int asistenciaEmpleado;
    for(int i = 0; i < empleados.size(); i++){
        cout << "Asistencia de " << empleados[i].getNombre() << endl;
        cout << "[1] Asisitio   [0] No asistio " << endl;
        cin >> asistenciaEmpleado;
        if(asistenciaEmpleado != 1) continue;

        int asistencia = empleados[i].getAsistencia();
        empleados[i].setAsistencia(asistencia + 1);
    }
    guardarEmpleados();
    cout << "Informacion actualizada\n";
}

void Gerente::mostrarSueldoAPagarEmpleados(){
    cargarEmpleados();
    cout << "------------------------" << endl;
    for(int i = 0; i < empleados.size(); i++){
        Empleado empleadoi = empleados[i];
        cout << "Nombre: " << empleadoi.getNombre() << endl;
        cout << "Sueldo Semanal: " << empleadoi.getSueldo() << " MXN" << endl;

        int asistencia = empleadoi.getAsistencia();
        cout << "Asistencia del empleado (dias): " << asistencia << endl;

        int total_pagar = (asistencia * empleadoi.getSueldo()) / 6;
        cout << "Total a pagar: " << total_pagar << " MXN" << endl;
        cout << "------------------------" << endl;
    }
}

Gerente::~Gerente(){}

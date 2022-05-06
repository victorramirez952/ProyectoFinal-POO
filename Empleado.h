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
    while(option != "1" && option != "2"){
        getline(cin, option);
    }
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
        string _sueldo;
        while(true){
            cout << "Ingresa el sueldo: ";
            getline(cin, _sueldo);
            if(validarNumeroFlotante(_sueldo)){
                this->sueldo = stoi(_sueldo.c_str());
                break;
            } else{
                cout << "Ingresa un sueldo valido" << endl;
            }
        }
    }

    cout << "Asistencia: " << this->asistenciaEmpleado << endl;
    if(modificarE("la asistencia")){
        string _asistencia;
        while(true){
            cout << "Ingresa la nueva asistencia: ";
            getline(cin, _asistencia);
            if(validarNumero(_asistencia)){
                this->asistenciaEmpleado = stoi(_asistencia.c_str());
                break;
            } else{
                cout << "Ingresa un numero valido" << endl;
            }
        }
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
    float total;

    vector<string> codigosComics;
    vector<string> comicsComprados; //Nombres de Comics
    vector<float> preciosIndividuales;
    vector<int> cantidadesCompradas;

    int contador = 0;
    while(true){
        cargarInventario();
        string codigo;
        bool ans, nombreEncontrado = false;

        cout << question << "Conoces el codigo del comic? (1 - Si, 2 - No): ";
        ans = validarSiNo();
        
        if(!ans){ // búsqueda de Comic por nombre
            while(true){
                string nombre;
                while (nombre.length() < 3)
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
                    break;;
                }
            }
            
        }
        if(!nombreEncontrado & !ans) break;

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
            string _cantidad;
            while(true){
                cout << question << "Cuantos ejemplares se llevara el cliente de este comic? ";
                getline(cin, _cantidad);
                if(validarNumero(_cantidad)){
                    cantidad = stoi(_cantidad.c_str());
                    if(cantidad > 0) break;
                    continue;
                } else{
                    cout << "Ingresa una cantidad valida" << endl;
                }
            }
            if(cantidadDisponible < cantidad){
                cout << "No quedan suficientes ejemplares disponibles\n";
                cout << "Ingrese otra cantidad\n";
                continue;
            }
            cantidadesCompradas.push_back(cantidad);
            break;
        }
        
        this->comics[indice].setCantidad(cantidadDisponible - cantidad);
        total += precioComic * cantidad;
        contador++;

        string option;
        guardarInventario();
        cout << question << "Desea agregar otro comic? (1 - Si, 2 - No): ";
        while(option != "1" && option != "2"){
            getline(cin, option);
        }
        if(option != "1") break;
    }


    // Pago del cliente
    string vendedor;
    
    cout << "Ingresar nombre del vendedor: ";
    getline(cin, vendedor);

    string pagar;
    string NIP;
    cout << "El total a pagar es: " << total << " MXN" << endl;
    while (true){   
        cout << "Ingrese su metodo de pago (1 - Efectivo/ 2 - Tarjeta): ";
        while(pagar != "1" && pagar != "2"){
            getline(cin, pagar);

        }
        if(pagar == "1" | pagar == "2") break;
    }
    
    int pagoCliente;
    if(pagar == "2"){
        cout << "Ingrese su NIP: ";
        getline(cin, NIP);
    }
    else if (pagar == "1"){
        while(true){
            cout << "Ingrese la cantidad con la que pagara: ";
            string _pago;
            while(true){
                getline(cin, _pago);
                if(validarNumeroFlotante(_pago)){
                    pagoCliente = stof(_pago.c_str());
                    break;
                } else{
                    cout << "Ingresa una cantidad valida" << endl;
                }
            }
            if(pagoCliente < total){
                cout << "El total a pagar es mayor!\n";
                cout << "Ingrese nuevamente el pago del cliente\n";
                continue;
            }
            if(total <= pagoCliente){
                break;
            }
        }
    }

    cout << "Pago realizado!" << endl;

    // Impreción de Ticket
    Recibo_del_cliente *recibo = new Recibo_del_cliente();
    recibo->imprimirRecibo(vendedor, total, comicsComprados, codigosComics, preciosIndividuales, cantidadesCompradas, pagoCliente);
    cout << "Gracias por su compra!" << endl;
    

    Ventas *ventas = new Ventas();
    ventas->agregarVentas(codigosComics, preciosIndividuales, cantidadesCompradas, vendedor);
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
    cout << "-- EMPLEADOS --\n";
    cout << "\n************************************\n";
    int sizeArray = empleados.size();
    for(int i = 0; i < sizeArray; i++){
        empleados[i].mostrarDatos();
        if(i != sizeArray-1){
            cout << "------------------------------------\n";
        }
    }
    cout << "\n************************************\n";
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
        cout << "No se puede abrir el archivo 'Empleados.dat'" << endl;
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
    string _sueldo;
    while(true){
        getline(cin, _sueldo);
        if(validarNumeroFlotante(_sueldo)){
            sueldo = stof(_sueldo.c_str());
            break;
        } else{
            cout << "Ingresa un sueldo valido" << endl;
        }
    }
    empleados[empleados.size()-1].setDatos(nombre, rfc, sueldo);
    guardarEmpleados();
    cout << "Empleado agregado con exito!" << endl;
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
        cout << "No se encontro el empleado con el rfc: " << rfc << endl;
        return;
    }
    empleados.erase(empleados.begin()+indice);
    guardarEmpleados();
    cout << "Empleado eliminado satisfactoriamente!" << endl;
}

void Gerente::resetAsistencias(){
    cargarEmpleados();
    for(int i= 0; i < empleados.size(); i++){
        empleados[i].setAsistencia(0);
    }
    guardarEmpleados();
    cout << "Asistencia de los empleados reiniciada con exito!\n";
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
        cout << "No se encontro el empleado con el rfc: " << rfc << "\n";
        return;
    }
    empleados[indice].modificarDatos();
    guardarEmpleados();
    cout << "Empleado actualizado correctamente!" << endl;
}

void Gerente::registrarAsistenciaEmpleados(){
    cargarEmpleados();
    for(int i = 0; i < empleados.size(); i++){
        cout << "Asistencia de " << empleados[i].getNombre() << endl;
        cout << "[1] Asisitio   [0] No asistio " << endl;
        string asistenciaEmpleado;
        while(asistenciaEmpleado != "1" && asistenciaEmpleado != "0"){
            cin >> asistenciaEmpleado;
        }
        if(asistenciaEmpleado != "1") continue;

        int asistencia = empleados[i].getAsistencia();
        empleados[i].setAsistencia(asistencia + 1);
    }
    cin.ignore();
    guardarEmpleados();
    cout << "Asistencia de los empleados registrada con exito!\n";
}

void Gerente::mostrarSueldoAPagarEmpleados(){
    cargarEmpleados();
    cout << "-- SUELDO A PAGAR A EMPLEADOS --\n";
    cout << "************************************\n";
    float totalPagarEmpleados = 0;
    int sizeArray = empleados.size();
    for(int i = 0; i < sizeArray; i++){
        Empleado empleadoi = empleados[i];
        cout << "Nombre: " << empleadoi.getNombre() << endl;
        cout << "Sueldo Semanal: " << empleadoi.getSueldo() << " MXN" << endl;

        int asistencia = empleadoi.getAsistencia();
        cout << "Asistencia del empleado (dias): " << asistencia << endl;

        int total_pagar = (asistencia * empleadoi.getSueldo()) / 6;
        cout << "Total a pagar: " << total_pagar << " MXN" << endl;
        totalPagarEmpleados += total_pagar;
        if(i != sizeArray-1){
            cout << "------------------------------------\n";
        }
    }
    cout << "************************************\n";
    cout << "Total a pagar a los empleados: " << totalPagarEmpleados << " MXN" << endl;
    cout << "************************************\n\n";
}

Gerente::~Gerente(){}

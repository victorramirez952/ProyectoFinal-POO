class Comic{
    protected:
        string nombre, compania, codigo, fecha;
        float precio;
        int cantidad;
        bool oferta = false;
    public:
        Comic();
        virtual void setDatos();
        void modificarDatos();
        void setCodigo(string _codigo);
        void setCompania(string _compania);
        void setNombre(string _nombre);
        void setPrecio(float _precio);
        void setFecha(string _fecha);
        void setCantidad(int _cantidad);
        void setOferta(bool _oferta);

        string getCodigo();
        string getCompania();
        string getNombre();
        float getPrecio();
        string getFecha();
        int getCantidad();
        bool getOferta();

        virtual void mostrarDatos();
        ~Comic();
};

class ComicAdquirido : public Comic{
    private:
        int nLotes = 0;
    public:
        ComicAdquirido();
        void setDatos();
        void setNLotes(int _nLotes);

        int getNLotes();

        void mostrarDatos();
        ~ComicAdquirido();
};

//derivaciones
Comic::Comic(){}

void Comic::setDatos(){
    string dia, mes, anio;
    string _codigo = "";
    do{
        cout << "Ingresa el codigo del comic: ";
        getline(cin, _codigo);
    }
    while(!validarCodigo(_codigo));
    this->codigo = _codigo;

    do{
        cout << "Ingresa la compania: ";
        getline(cin, this->compania);
    } while(!validarStringVacio(this->compania));

    do{
        cout << "Ingresa el nombre del comic: ";
        getline(cin, this->nombre);
    }while(!validarStringVacio(this->nombre));

    cout << "Ingresa el precio individual del comic (MXN): ";  

    string precio;
    while(true){
        getline(cin, precio);
        if(validarStringVacio(precio)){
            if(validarNumeroFlotante(precio)){
                this->precio = stof(precio);
                break;
            } else{
                cout << "Ingrese un precio valido" << endl;
            }
        } else{
                cout << "Ingrese un precio valido" << endl;
        }
    }

    cout << "Ingresar fecha de publicacion del comic\n";

    this->fecha = ingresarFecha();
}

//Funcion utilizada para modificar datos
bool modificar(string text){
    string option;
    cout << "Deseas modificar " << text << "? (1 - Si, 2 - No): " << endl;
    while(option != "1" && option != "2"){
        getline(cin, option);
        if(option != "1" && option != "2") printf("Opcion invalida\n");
    }
    if(option == "1"){
        return true;
    }
    return false;
}

void Comic::modificarDatos(){
    cout << "Compania: " << this->compania << endl;
    if(modificar("la compania")){
        do{
            cout << "Ingresa la nueva compania: ";
            getline(cin, this->compania);
        }while(!validarStringVacio(this->compania));
    }

    cout << "Comic: " << this->nombre << endl;
    if(modificar("el nombre del comic")){
        do{
            cout << "Ingresa el nuevo nombre: ";
            getline(cin, this->nombre);
        }while(!validarStringVacio(this->nombre));
    }

    cout << "Precio: " << this->precio << endl;
    if(modificar("el precio")){
        string _precio;
        while(true){
            cout << "Ingrese el nuevo precio: ";
            getline(cin, _precio);
            if(validarStringVacio(_precio)){
                if(validarNumeroFlotante(_precio)){
                    this->precio = stof(_precio);
                    break;
                } else{
                    cout << "Ingrese un precio valido" << endl;
                }
            }
        }
    }

    cout << "Fecha: " << this->fecha << endl;
    if(modificar("la fecha")){
        this->fecha = ingresarFecha();
    }
    
    cout << "Cantidad: " << this->cantidad << endl;
    if(modificar("la cantidad")){
        string _cantidad;
        while (true){
            cout << "Ingresa la nueva cantidad: ";
            getline(cin, _cantidad);
            if(validarStringVacio(_cantidad)){
                if(validarNumero(_cantidad)){
                    this->cantidad = stoi(_cantidad.c_str());
                    break;
                } else{
                    cout << "Ingrese una cantidad valida" << endl;
                }
            }
        }
    }
    
    if(this->oferta)
        cout << "El comic esta en oferta" << endl;
    string option;
    while(true){
        cout << "Deseas cambiar el estado de la oferta del comic (1-Si, 2-NO): ";
        getline(cin, option);
        if(validarStringVacio(option)){
            if(validarNumeroRango(option, 1, 2)){
                break;
            } else{
                cout << "Opcion invalida" << endl;
            }
        }
    }
    if(option == "1")
        this->oferta = !this->oferta;
}

void Comic::setCompania(string _compania){
    this->compania = _compania;
}

void Comic::setNombre(string _nombre){
    this->nombre = _nombre;
}

void Comic::setPrecio(float _precio){
    this->precio = _precio;
}

void Comic::setCodigo(string _codigo){
    this->codigo = _codigo;
}

void Comic::setFecha(string _fecha){
    this->fecha = _fecha;
}

void Comic::setCantidad(int _cantidad){
    this->cantidad = _cantidad;
}

void Comic::setOferta(bool _oferta){
    this->oferta = _oferta;
}

string Comic::getCodigo(){
    return this->codigo;
}

string Comic::getCompania(){
    return this->compania;
}

string Comic::getNombre(){
    return this->nombre;
}

float Comic::getPrecio(){
    return this->precio;
}

string Comic::getFecha(){
    return this->fecha;
}

int Comic::getCantidad(){
    return this->cantidad;
}

bool Comic::getOferta(){
    return this->oferta;
}


void Comic::mostrarDatos(){
    cout << "Codigo: " << this->codigo << endl;
    cout << "Compania: " << this->compania << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Precio: " << this->precio << endl;
    cout << "Fecha: " << this->fecha << endl;
    cout << "Cantidad: " << this->cantidad << endl;
    if(this->oferta) cout << "Esta en oferta" << endl;
}

Comic::~Comic(){}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
ComicAdquirido::ComicAdquirido(){}

void ComicAdquirido::setDatos(){
    Comic::setDatos();
    string _nLotes;
    while (true){
        cout << "Ingresa la cantidad de lotes a comprar del comic (cada lote tiene 20 comics): ";
        getline(cin, _nLotes);
        if(validarStringVacio(_nLotes)){
            if(validarNumero(_nLotes)){
                this->nLotes = stoi(_nLotes.c_str());
                break;
            } else{
                cout << "Ingrese un numero valido" << endl;
            }
        }
    }
}

void ComicAdquirido::setNLotes(int _nLotes){
    this->nLotes = _nLotes;
}

int ComicAdquirido::getNLotes(){
    return this->nLotes;
}

void ComicAdquirido::mostrarDatos(){
    cout << "Codigo: " << this->codigo << endl;
    cout << "Compania: " << this->compania << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Precio: " << this->precio << endl;
    cout << "Fecha: " << this->fecha << endl;
    cout << "Lotes: " << this->nLotes << endl; 
}

ComicAdquirido::~ComicAdquirido(){}

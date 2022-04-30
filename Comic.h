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
    cout << "Ingresa el codigo del comic: ";
    getline(cin, this->codigo);
    cout << "Ingresa la compania: ";
    getline(cin, this->compania);
    cout << "Ingresa el nombre del comic: ";
    getline(cin, this->nombre);
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
    this->fecha = dia + "/" + mes + "/" + anio;
}

//Funcion utilizada para modificar datos
bool modificar(string text){
    string option;
    cout << "Deseas modificar " << text << "? (1 - Si, 2 - No): " << endl;
    getline(cin, option);
    if(option == "1"){
        return true;
    }
    return false;
}

void Comic::modificarDatos(){
    cout << "Compania: " << this->compania << endl;
    if(modificar("la compania")){
        cout << "Ingresa la nueva compania: ";
        getline(cin, this->compania);
    }

    cout << "Comic: " << this->nombre << endl;
    if(modificar("el nombre del comic")){
        cout << "Ingresa el nuevo nombre: ";
        getline(cin, this->nombre);
    }

    cout << "Precio: " << this->precio << endl;
    if(modificar("el precio")){
        cout << "Ingresa el nuevo precio: ";
        cin >> this->precio;
        cin.ignore();
    }

    cout << "Fecha: " << this->fecha << endl;
    if(modificar("la fecha")){
        cout << "Ingresa la nueva fecha: ";
        getline(cin, this->fecha);
    }
    
    cout << "Cantidad: " << this->cantidad << endl;
    if(modificar("la cantidad")){
        cout << "Ingresa la nueva cantidad: ";
        cin >> cantidad;
        cin.ignore();
    }
    
    if(this->oferta)
        cout << "El comic esta en oferta" << endl;
    cout << "Deseas cambiar el estado de la oferta del comic (1-Si, 2-NO): ";
    string option;
    getline(cin, option);
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
    cout << "Ingresa la cantidad de lotes a comprar del comic (cada lote tiene 20 comics): ";
    cin.ignore();
    cin >> this->nLotes;
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

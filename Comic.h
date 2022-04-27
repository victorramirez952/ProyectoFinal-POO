class Comic{
    private:
        string nombre, compania, codigo, fecha;
        float precio;
        int cantidad;
        bool oferta = false;
    public:
        Comic();
        void setCodigo(string _codigo);
        void setCompania(string _compania);
        void setNombre(string _nombre);
        void setPrecio(float _precio);
        void setFecha(string _fecha);
        void setCantidad(int _cantidad);
        void setOferta(int _oferta);

        string getCodigo();
        string getCompania();
        string getNombre();
        int getPrecio();
        string getFecha();
        int getCantidad();
        bool getOferta();

        void mostrarDatos();
        ~Comic();
};

//derivaciones
Comic::Comic(){}

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

void Comic::setOferta(int _oferta){
    if(_oferta == 1) this->oferta = true;
    else this->oferta = false;
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

int Comic::getPrecio(){
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


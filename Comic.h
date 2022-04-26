class Comic{
    private:
        string nombre, compania, codigo, fecha;
        float precio;
        int cantidad;
        bool oferta;
    public:
        Comic();
        void setCompania(string _compania);
        void setNombre(string _nombre);
        void setPrecio(float _precio);
        void setCodigo(string _codigo);
        void setFecha(string _fecha);
        void setCantidad(int _cantidad);
        void setOferta(int _oferta);

        void mostrarDatos(){}
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
    if(_oferta = 1) this->oferta = true;
    else this->oferta = false;
}

// void Comic::mostrarDatos(){
//     cout << "Compania: " << this->compania << endl;
//     cout << "Nombre: " << this->nombre << endl;
//     cout << "Precio: " << this->precio << endl;
//     cout << "Codigo: " << this->codigo << endl;
//     cout << "Fecha: " << this->fecha << endl;
//     cout << "Cantidad: " << this->cantidad << endl;
//     if(this->oferta) cout << "Esta en oferta" << endl;
// }

Comic::~Comic(){}


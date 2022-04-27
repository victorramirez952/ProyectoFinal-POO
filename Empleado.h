class Persona{
    protected:
        string nombre, rfc;
    public:
        Persona();
        Persona(string _nombre, string _rfc);
        ~Persona();
};

class Empleado : public Persona{
    private:
        int asistencia;
        float sueldo;
    public:
        Empleado();
        Empleado(string _nombre, string _rfc);
        void venderComics();
        ~Empleado();
};

class Gerente : public Persona{
    private:
    public:
        Gerente();
        Gerente(string _nombre, string _rfc);
        // void crearNuevoEmpleado();
        void registrarAsistenciaEmpleados();
        void mostrarSueldoAPagarEmpleados();
        ~Gerente();
};

// Inicialización de clases
// Persona
Persona::Persona(){}

Persona::Persona(string _nombre, string _rfc){}

Persona::~Persona(){}

// Empleado
Empleado::Empleado(){}

Empleado::Empleado(string _nombre, string _rfc){}

void Empleado::venderComics(){}

Empleado::~Empleado(){}

// Gerente
Gerente::Gerente(){}

Gerente::Gerente(string _nombre, string _rfc){
    this->nombre = _nombre;
    this->rfc = _rfc;
}

// void crearNuevoEmpleado();
void Gerente::registrarAsistenciaEmpleados(){}

void Gerente::mostrarSueldoAPagarEmpleados(){}

Gerente::~Gerente(){}

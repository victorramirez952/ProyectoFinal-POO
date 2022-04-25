class Empleado{
    private:
        string nombre, rfc;
        int asistencia;
        float sueldo;
    public:
        Empleado();
        void venderComics();
        ~Empleado();
};

class Gerente{
    private:
        string nombre;
    public:
        Gerente();
        void registrarAsistenciaEmpleados();
        void mostrarSueldoAPagarEmpleados();
        ~Gerente();
};
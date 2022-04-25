#include "vector"
class Ventas{
    private:
        float promedio_ventas, total_ganado;
        vector<Comic> comics_vendidos;
    public:
        Ventas();
        void agregarComicsVendidos();
        ~Ventas();
};
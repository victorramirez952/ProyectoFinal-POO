#include "vector"
class Tienda{
    private:
        vector<Comic> comics;
        vector<Categorias> categorias;
    public:
        Tienda();
        void acomodarLotesRecibidos();
        ~Tienda();
};
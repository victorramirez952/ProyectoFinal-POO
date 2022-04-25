#include "vector"
class Inventario{
    private:
        vector<Comic> comics;
        vector<string> categorias;
        int total_comics;
    public:
        Inventario();
        void buscarComics();
        void editarComics();
        void eliminarComicsVendidos();
        ~Inventario();
};
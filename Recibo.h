#include "vector"
class Recibo{
    private:
        float subtotal, iva, total_a_pagar;
        string fecha, hora, tipo_de_pago, nombre_tienda;
    public:
        Recibo();
        ~Recibo();
};

class Recibo_del_cliente{
    private:
        string nombre_vendedor;
        vector<string> comics;
        vector<string> codigos;
        vector<float> precio_individual;
        int cantidad;
    public:
        Recibo_del_cliente();
        ~Recibo_del_cliente();
};

class Comprobante_lotes_adquiridos{
    private:
        string nombre_distribuidor;
        int cantidad_lotes_comprados;
        vector<string> nombres_de_comics;
        vector<int> precio_lotes;
    public:
        Comprobante_lotes_adquiridos();
        ~Comprobante_lotes_adquiridos();
};
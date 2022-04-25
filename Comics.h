class Comic{
    private:
        string nombre, compania;
        float precio;
        int codigo, cantidad;
        bool oferta;
    public:
        Comic();
        void setCantidad();
        void setNombre();
        ~Comic();
};
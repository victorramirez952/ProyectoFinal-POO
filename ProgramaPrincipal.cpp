#include "iostream"
using namespace std;
#include "Empleado.h"
#include "Inventario.h"

int main(){
    Gerente *gerente = new Gerente("Alberto Alvarez", "VATL900113MW8");
    ComicsAdquiridos *inventario = new ComicsAdquiridos();
    // inventario->establecerComicsAdquiridos();
    // inventario->mostrarInventario();

    // inventario->organizarLotesAdquiridos();
    // inventario->mostrarInventario();

    // inventario->editarComics();
    // inventario->mostrarInventario();

    // inventario->eliminarComicsVendidos();
    // inventario->mostrarInventario();

    // inventario->pedirNuevosComics();

    return 0;
}
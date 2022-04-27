#include "iostream"
using namespace std;
#include "Inventario.h"
#include "Empleado.h"

int main(){
    Gerente *gerente = new Gerente("Alberto Alvarez", "VATL900113MW8");
    ComicsAdquiridos *inventario = new ComicsAdquiridos();
    Empleado *empleado = new Empleado();
    // inventario->establecerComicsAdquiridos();
    // inventario->mostrarInventario();

    // inventario->organizarLotesAdquiridos();
    // inventario->mostrarInventario();

    // inventario->editarComics();
    // inventario->mostrarInventario();

    // inventario->eliminarComicsVendidos();
    // inventario->mostrarInventario();

    // inventario->pedirNuevosComics();
    // gerente->mostrarSueldoAPagarEmpleados();
    // gerente->mostrarEmpleados();

    empleado->venderComics();

    return 0;
}
#include "iostream"
using namespace std;
#include "Empleado.h"
#include "Inventario.h"

int main(){
    Gerente *gerente = new Gerente("Alberto Alvarez", "VATL900113MW8");
    Inventario *inventario = new Inventario();

    comicsAdquiridos->establecerComicsAdquiridos();
    inventario->mostrarInventario();
    comicsAdquiridos->organizarLotesAdquiridos();
    inventario->mostrarInventario();

    // inventario->mostrarInventario();
    // comicsAdquiridos->mostrarComicsAdquiridos();


    // comicsAdquiridos->pedirNuevosComics();

    // Empleado *empleado1 = new Empleado();
    // gerente->pedirNuevosComics();
    return 0;
}
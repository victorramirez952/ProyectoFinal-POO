#include "iostream"
using namespace std;
#include "Empleado.h"

int main(){
    Gerente *gerente = new Gerente("Alberto Alvarez", "VATL900113MW8");
    Empleado *empleado1 = new Empleado();
    empleado1->mostrarInventario();
    // gerente->pedirNuevosComics();
    return 0;
}
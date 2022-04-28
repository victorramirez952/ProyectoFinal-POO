#include "iostream"
using namespace std;
#include "Inventario.h"
#include "Ventas.h"
#include "Empleado.h"
#include "Conio.h"

int main(){
    Gerente *gerente = new Gerente("Alberto Alvarez", "VATL900113MW8");
    ComicsAdquiridos *inventario = new ComicsAdquiridos();
    Empleado *empleado = new Empleado();
    Ventas *ventas = new Ventas();

    bool continuar = true;
    while(continuar){
        string option;
        cout << "[1] Pedir comics a un proveedor\n";
        cout << "[2] Organizar productos adquiridos\n";
        cout << "[3] Editar informacion de comics\n";
        cout << "[4] Buscar comic\n";
        cout << "[5] Vender comics\n";
        cout << "[6] Conocer informacion sobre las ventas\n";
        cout << "[7] Registrar asistencia de empleados\n";
        cout << "[8] Ver sueldo a pagar a los empleados\n";
        cout << "Eliga una opcion: ";
        getline(cin, option);
        if(option == "1"){
            inventario->pedirNuevosComics();
        } else if(option == "2"){
            inventario->organizarLotesAdquiridos();
        } else if(option == "3"){
            inventario->editarComics();
        } else if(option == "4"){
            string search;
            cout << "Ingresa el codigo del comic que deseas buscar: ";
            getline(cin, search);
            inventario->buscarComic(search);
        } else if(option == "5"){
            empleado->venderComics();
        } else if(option == "6"){
            ventas->mostrarDatosVentas();
        } else if(option == "7"){
            gerente->registrarAsistenciaEmpleados();
        } else if(option == "8"){
            gerente->mostrarSueldoAPagarEmpleados();
        } else {
            cout << "La opcion que ingresaste es invalida!" << endl;
        }
        cout << "Pulse cualquier tecla para continuar..." << endl;
        getch();
        cout << "Deseas continuar?\n";
        cout << "[1] Si    [2] No\n";
        string answer;
        getline(cin, answer);
        if(answer == "2") continuar = false;
    }
    return 0;
}
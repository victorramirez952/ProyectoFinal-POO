//Cpp principal
//Proyecto Final
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#include "VariablesGlobales.h"

#include "Funcionalidades.h"
#include "Validaciones.h"
#include "Inventario.h"
#include "Ventas.h"
#include "Empleado.h"
#include "Cifrado.h"

int main(){
    Gerente *objGerente = new Gerente();
    Inventario *inventario = new Inventario();
    ComicsAdquiridos *comicsAdquiridos = new ComicsAdquiridos();
    Empleado *empleado = new Empleado();
    Empleados *empleados = new Empleados();
    Ventas *ventas = new Ventas();
    Recibo_lotes_adquiridos *reciboLotesAdquiridos = new Recibo_lotes_adquiridos();

    string x;

    cout << "Bienvenido al sistema! " << endl;
    while(true){
        cout << "\n" << question << "Quien va a acceder? " << endl;
        cout << "[1] Gerente    [2] Vendedor    [3] Administrador\n";
        getline(cin, x);
        if(validarNumeroRango(x, 1, 3)) break;
    }
    
    //GERENTE
    if (x == "1"){
        const int intentos = 3;
        int contador = 0;
        string gerente;
        string pGerente;
        Encdec *encdec = new Encdec("gerente");
        do{
            cout << "\n-- LOG IN DEL GERENTE --" << endl;
            cout << "Ingrese el usuario del gerente: ";
            do{
                getline(cin, gerente);
            }
            while(!validarStringVacio(gerente));
            cout << "Ingrese la contrase" << enie << "a del gerente: ";
            do{
                getline(cin, pGerente);
            }
            while(!validarStringVacio(pGerente));
            contador++;
        } while((gerente != encdec->getUsername() || pGerente != encdec->getPassword()) && contador < intentos);

        if(contador == intentos){
            cout << "Datos incorrectos!" << endl;
            cout << "Utilizaste todos tus intentos" << endl;
            cout << "Sesion cerrada " << endl;
            return 0;
        }
        else{
            while(true){
                string a; //Variable para switch
                cout << "-------- MENU DEL GERENTE -------- " << endl;
                cout << "[1] Pedir comics a un proveedor" << endl;
                cout << "[2] Mostrar inventario" << endl;
                cout << "[3] Buscar comic" << endl;
                cout << "[4] Imprimir recibo lotes adquiridos" << endl;
                cout << "[5] Organizar lotes adquiridos" << endl;
                cout << "[6] Conocer informacion sobre las ventas" << endl;
                cout << "[7] Mostrar empleados" << endl;
                cout << "[8] Registrar nuevo empleado" << endl;
                cout << "[9] Editar informacion de un empleado" << endl;
                cout << "[10] Eliminar un empleado" << endl;
                cout << "[11] Registrar asistencia empleados" << endl;
                cout << "[12] Resetear asistencia empleados" << endl;
                cout << "[13] Mostrar sueldo a pagar a empleados" << endl;
                cout << "[14] Terminar programa" << endl;
                while(true){
                    getline(cin, a);
                    if(validarNumeroRango(a, 1, 14)) break;
                    cout << "Ingrese una opcion valida" << endl; 
                }
                string codigo;
                switch (stoi(a.c_str()))
                {
                case 1:
                    comicsAdquiridos->pedirNuevosComics();
                    break;
                case 2:
                    cout << endl;
                    inventario->mostrarInventario();
                    break;
                case 3:
                    inventario->buscarComic();
                    break;
                case 4:
                    reciboLotesAdquiridos->imprimirRecibo();
                    break;
                case 5:
                    comicsAdquiridos->organizarLotesAdquiridos();
                    break;
                case 6:
                    ventas->mostrarDatosVentas();
                    break;
                case 7:
                    empleados->mostrarEmpleados();
                    break;
                case 8:
                    objGerente->registrarNuevoEmpleado();
                    break;
                case 9:
                    objGerente->editarEmpleado();
                    break;
                case 10:
                    objGerente->eliminarEmpleado();
                    break;
                case 11:
                    objGerente->registrarAsistenciaEmpleados();
                    break;
                case 12:
                    objGerente->resetAsistencias();
                    break;
                case 13:
                    objGerente->mostrarSueldoAPagarEmpleados();
                    break;
                case 14:
                    return 0;
                    break;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
                }

                cout << "\n" << question << "Deseas continuar?\n";
                cout << "[1] Si    [2] No\n";
                string answer;
                while(answer != "1" && answer != "2"){
                    getline(cin, answer);
                    if(answer != "1" && answer != "2") printf("Opcion invalida\n");
                }
                if(answer != "1") break;
            }
            
        } //fin else
    }


    //VENDEDOR
    
    else if(x == "2"){
        const int intentos = 3;
        int contador = 0;
        string vendedor;
        string pVendedor;
        Encdec *encdec = new Encdec("vendedor1");
        do{
            cout << "\n-- LOG IN DEL VENDEDOR -- " << endl;
            do{
                cout << "Ingrese el usuario del vendedor: ";
                getline(cin, vendedor);
            }while(!validarStringVacio(vendedor));

            do{
                cout << "Ingrese la contrase" << enie << "a del vendedor: ";
                getline(cin, pVendedor);
            }while(!validarStringVacio(pVendedor));
            contador++;
        }while((vendedor != encdec->getUsername() || pVendedor != encdec->getPassword()) && contador < intentos);
        if (contador == intentos){
            cout << "Datos incorrectos! \n";
            cout << "Utilizaste todos tus intentos" << endl;
            cout << "Sesion cerrada " << endl;
            return 0;
        }
        else{
            while(true){
                string a; //Variable para switch
                cout << "-------- MENU DEL VENDEDOR -------- " << endl;
                cout << "[1] Vender comics " << endl;
                cout << "[2] Buscar comics " << endl;
                cout << "[3] Mostrar inventario de comics " << endl;
                cout << "[4] Organizar comics " << endl;
                cout << "[5] Mostrar comics adquiridos " << endl;
                cout << "[6] Terminar programa " << endl;
                while(true){
                    getline(cin, a);
                    if(validarNumeroRango(a, 1, 6)) break;
                    cout << "Ingrese una opcion valida" << endl; 
                }
                string codigo;
                switch (stoi(a.c_str()))
                {
                case 1:
                    empleado->venderComics();
                    break;
                case 2:
                    inventario->buscarComic();
                    break;
                case 3:
                    inventario->mostrarInventario();
                    break;
                case 4:
                    comicsAdquiridos->organizarLotesAdquiridos();
                    break;
                case 5:
                    comicsAdquiridos->mostrarComicsAdquiridos();
                    break;
                case 6:
                    return 0;
                default:
                    cout << "Opcion invalida" << endl;
                    break;
                }

                cout << "\n" << question << "Deseas continuar?\n";
                cout << "[1] Si    [2] No\n";
                string answer;
                while(answer != "1" && answer != "2"){
                    getline(cin, answer);
                    if(answer != "1" && answer != "2") printf("Opcion invalida\n");
                }
                if(answer != "1") break;
            }
            
        } //fin else
    }
    //ADMIN
    else if(x == "3"){
        const int intentos = 3;
        int contador = 0;
        string admin;
        string pAdmin;
        Encdec *encdec = new Encdec("admin");
        do{
            cout << "\n-- LOG IN DEL ADMINISTRADOR -- " << endl;
            do{
                cout << "Ingrese el usuario del administrador: ";
                getline(cin, admin);
            }while(!validarStringVacio(admin));

            do{
                cout << "Ingrese la contrase" << enie << "a del administrador: ";
                getline(cin, pAdmin);
            }while(!validarStringVacio(pAdmin));
            contador++;
        }while((admin != encdec->getUsername() || pAdmin != encdec->getPassword()) && contador < intentos);
        if (contador == intentos){
            cout << "Datos incorrectos! \n";
            cout << "Utilizaste todos tus intentos" << endl;
            cout << "Sesion cerrada " << endl;
            return 0;
        }
        else{
            while(true){
                string a; //Variable para switch
                cout << "-------- MENU DEL ADMINISTRADOR -------- " << endl;
                cout << "[1] Mostrar inventario de comics" << endl;
                cout << "[2] Buscar comic" << endl;
                cout << "[3] Editar comic" << endl;
                cout << "[4] Eliminar comic" << endl;
                cout << "[5] Mostrar comics adquiridos" << endl;
                cout << "[6] Organizar comics adquiridos" << endl;
                cout << "[7] Imprimir recibo lotes adquiridos" << endl;
                cout << "[8] Terminar programa" << endl;
                while(true){
                    getline(cin, a);
                    if(validarNumeroRango(a, 1, 8)) break;
                    cout << "Ingrese una opcion valida" << endl; 
                }
                string codigo;
                switch (stoi(a.c_str()))
                {
                case 1:
                    inventario->mostrarInventario();
                    break;
                case 2:
                    inventario->buscarComic();
                    break;
                case 3:
                    inventario->editarComic();
                    break;
                case 4:
                    inventario->eliminarComic();
                    break;
                case 5:
                    comicsAdquiridos->mostrarComicsAdquiridos();
                    break;
                case 6:
                    comicsAdquiridos->organizarLotesAdquiridos();
                    break;
                case 7:
                    reciboLotesAdquiridos->imprimirRecibo();
                    break;
                case 8:
                    return 0;
                    break;
                default:
                    break;
                }
                cout << "\n" << question << "Deseas continuar?\n";
                cout << "[1] Si    [2] No\n";
                string answer;
                while(answer != "1" && answer != "2"){
                    getline(cin, answer);
                    if(answer != "1" && answer != "2") printf("Opcion invalida\n");
                }
                if(answer != "1") break;
            }
            
        } //fin else
    }
    return 0;
}    
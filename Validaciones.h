bool validarStringVacio(string str){
    if(str.size() == 0){
        cout << "La cadena esta vacia!\n";
        return false;
    } 
    return true;
}

bool validarNumero(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable >= 0){
            return true;
        }
    }
    return false;
}

bool validarNumeroRango(string x, int lower, int bigger){
    if(!validarStringVacio(x)) return false;
    if(!validarNumero(x)) return false;
    int variable = stoi(x.c_str());
    if(variable >= lower & variable <= bigger){
        return true;
    }
    return false;
}

bool validarNumeroFlotante(string x){
    if(x.find_first_not_of("0123456789.-") == string::npos){
        int variable = stoi(x.c_str());
        if(variable > 0){
            return true;
        }
    }
    return false;
}

bool validarDia(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable > 0 && variable <= 32){
            return true;
        }
    }
    return false;
}

bool validarMes(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable > 0 & variable <= 12){
            return true;
        }
    }
    return false;
}

bool validarAnio(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable >= 0 && x.size() != 3){
            return true;
        }
    }
    return false;
}


string ingresarFecha(){
    string dia, mes, anio;
    while (true){
        cout << "Ingresa el dia: ";
        getline(cin, dia);
        if(validarStringVacio(dia)){
            if(validarDia(dia)){
                int num = stoi(dia.c_str());
                if(num < 10){
                    dia = "0" + to_string(num);
                } else{
                    dia = to_string(num);
                }
                break;
            } else{
                cout << "Ingrese un dia valido" << endl;
            }
        }
    }

    while (true){
        cout << "Ingresa el mes: ";
        getline(cin, mes);
        if(validarStringVacio(mes)){
            if(validarMes(mes)){
                int num = stoi(mes.c_str());
                if(num < 10){
                    mes = "0" + to_string(num);
                } else{
                    mes = to_string(num);
                }
                break;
            } else{
                cout << "Ingrese un mes valido" << endl;
            }
        }
    }

    while (true){
        string anioActual = to_string(getAnioActual());
        anioActual.erase(0, 2);
        cout << "Ingresa el anio: ";
        getline(cin, anio);
        if(validarStringVacio(anio)){
            if(validarAnio(anio)){
                int num = stoi(anio.c_str());
                if(num <= stoi(anioActual.c_str())){
                    if(num < 100 & num >= 10){
                        anio = "20" + to_string(num);
                    } else if(num < 10){
                        anio = "200" + to_string(num);
                    }
                    else{
                        anio = to_string(num);
                    }
                } else{
                    if(num < 100 & num >= 10){
                        anio = "19" + to_string(num);
                    }
                }
                break;
            } else{
                cout << "Ingrese un anio valido" << endl;
            }
        }
    }
    string fecha = dia + "/" + mes + "/" + anio;
    return fecha;
}

bool validarSiNo(){
    string answer;
    // (1 - Si, 2 - No):
    while(answer != "1" && answer != "2"){
        getline(cin, answer);
        if(answer != "1" && answer != "2") printf("Opcion invalida\n");
    }
    if(answer == "1") return true;
    return false;
}


bool validarStringSinEspacio(string str){
    int strlength = str.size();
    for ( int i = 0; i < strlength; i++ ) {
        // espacio, tabulador horizontal o vertical 
        if ( str[i] == ' ' || str[i] == '\t' || str[i] == '\v') {
            cout << "La cadena tiene espacios en blanco\n";
            return false;
        }
    }
    return true;
}

bool validarCodigo(string str){
    if(!validarStringSinEspacio(str)) return false;
    if(str.size() >= 7) return true;
    else{
        cout << "El codigo ingresado no tiene una longitud mayor a 7 caracters\n";
        return false;
    } 
}

bool validarNombrePersona(string str){
    if(str.size() <= 1) return false;
    if(str.find_first_of("0123456789-.*?¿/\t\v~+°|'()%$#&\"!¡=") == string::npos){
        return true;
    }
    cout << "Nombre invalido\n";
    return false;
}
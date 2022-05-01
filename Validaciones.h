bool validarNumeroRango(string x, int lower, int bigger){
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
        if(variable >= 0 && variable <= 32){
            return true;
        }
    }
    return false;
}

bool validarMes(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable >= 0 & variable <= 12){
            return true;
        }
    }
    return false;
}

bool validarAnio(string x){
    if(x.find_first_not_of("0123456789") == string::npos){
        int variable = stoi(x.c_str());
        if(variable >= 0){
            return true;
        }
    }
    return false;
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

string ingresarFecha(){
    string dia, mes, anio;
    while (true){
        cout << "Ingresa el dia: ";
        getline(cin, dia);
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

    while (true){
        cout << "Ingresa el mes: ";
        getline(cin, mes);
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

    while (true){
        cout << "Ingresa el anio: ";
        getline(cin, anio);
        if(validarAnio(anio)){
            int num = stoi(anio.c_str());
            if(num < 100 & num >= 10){
                anio = "20" + to_string(num);
            } else if(num < 10){
                anio = "200" + to_string(num);
            }
            else{
                anio = to_string(num);
            }
            break;
        } else{
            cout << "Ingrese un anio valido" << endl;
        }
    }
    string fecha = dia + "/" + mes + "/" + anio;
    return fecha;
}
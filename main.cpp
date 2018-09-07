#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

void showMenu(){
    cout << "--------------------------MENU--------------------------\n";
    cout << "1. Ingreso de factura\n";
    cout << "2. Ingreso de calcomania\n";
    cout << "3. Salida\n";
}

void poliza(){
    time_t now = time(0);
    string dt = ctime(&now);
    string calcomania, placa, nit, direccion, nombre, tipo;
    int poliza, modelo, motor;
    float valor_vehiculo,valor_impuesto, total, porcentaje_impuesto;
    float iva = 0.12;

    cout << "\n-------------------------POLIZA-------------------------";
    cout << "\nFecha: " << dt;
    cout << "Calcomania: ";
    cin >> calcomania;
    cout << "Placa: ";
    cin >> placa;
    cout << "NIT: ";
    cin >> nit;
    cout << "Poliza: ";
    cin >> poliza;
    cout << "Direccion: ";
    cin >> direccion;
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Modelo: ";
    cin >> modelo;
    cout << "Tipo: ";
    cin >> tipo;
    cout << "Motor: ";
    cin >> motor;
    cout << "Valor del vehiculo: ";
    cin >> valor_vehiculo;

    /*
        2018: 8%
        2010 - 2017: 5%
        2000 - 2009: 3%
        Any: 2%
    */
    if(modelo == 2018){
        porcentaje_impuesto = 0.08;
        valor_impuesto = porcentaje_impuesto * valor_vehiculo;
    }else if(modelo >= 2010 && modelo <= 2017){
        porcentaje_impuesto = 0.05;
        valor_impuesto = porcentaje_impuesto * valor_vehiculo;
    }else if(modelo >= 2000 && modelo <= 2009){
        porcentaje_impuesto = 0.03;
        valor_impuesto = porcentaje_impuesto * valor_vehiculo;
    }else if(modelo < 2000){
        porcentaje_impuesto = 0.02;
        valor_impuesto = porcentaje_impuesto * valor_vehiculo;
    }

    total = valor_vehiculo + valor_impuesto;

    cout << "\n-------------------------FACTURA-------------------------";
    cout << "\nTotal de vehiculo: " << valor_vehiculo;
    cout << "\nPorcentaje: " << porcentaje_impuesto << "%";
    cout << "\nValor del impuesto: " << valor_impuesto;
    cout << "\nTotal: " << total;
    cout << "\nIVA: " << iva * 100 << "%";
    cout << "\nFactura: " << total * iva << endl;
}

int main (){
    int option;

    while(option != 3){
        showMenu();
        cout << "\nOption > ";
        cin >> option;

        switch (option)
        {
            case 1:
                /* function to bill */
                break;
            case 2:
                poliza();
                break;
            default:
                break;
        }
    }
    
    // cout << "hello" << saludo;
    return 0;
}
// Mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <mysql.h>
#include <iostream>

using namespace std;

int main()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "Ejercicio", "C@rl0sy0c2519", "producto", 3306, NULL, 0);
    if (conectar) {
        cout << "conexion Exitosa..." << endl;
    }
    else {
        cout << "Error en la conexion..." << endl;
    }
    system("pause");
    return 0;

}
void insert_productos()
{
    MYSQL* conectar;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "root", "crud", 3309, NULL, 0);
    if (conectar)
    {
        string producto, descripcion, fecha_ingreso = "now()";
        string id_marca, existencia, precio_costo, precio_venta;
        //int id_marca, existencia;
        //double precio_costo, precio_venta;

        cout << "\ningrese el producto: ";
        getline(cin, producto);
        cout << "\ningrese el id_marca: ";
        cin >> id_marca;
        cin.ignore();
        cout << "\ningrese la descripcion: ";
        getline(cin, descripcion);
        cout << "\ningrese el precio costo: ";
        cin >> precio_costo;
        cin.ignore();
        cout << "\ningrese el precio venta: ";
        cin >> precio_venta;
        cin.ignore();
        cout << "\ningrese las existencias: ";
        cin >> existencia;
        cout << "\nla fecha de ingreso será esta hora en la que se estan ingresando datos" << endl;

        string insert = "insert into productos(producto,id_marca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values ('" + producto + "' , " + id_marca + " , '" + descripcion + "' , " + precio_costo + "," + precio_venta + "," + existencia + "," + fecha_ingreso + ")";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado)
        {
            cout << "insert exitoso" << endl;
        }
        else
        {
            cout << "error en insert" << endl;
        }
    }
}


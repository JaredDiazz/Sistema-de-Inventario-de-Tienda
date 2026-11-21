#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Structure for the users
struct user{
    int iduser;
    string username;
    string password;
    int rol;
};

//Structure for the products
struct Product{
    int idProducto;
    string product;
    float price;
    int stock;
    int minimumStock;
    int totalSales;
    int yearExp;
    int dayExp;
    int monthExp;
};


//Simulator - Victor
void inventorySimulator(Product inventory[], int numProducts){


    int actualMonth = 11;
    int actualYear = 2026;
    int actualDay = 18;

    for(int i = 0; i < numProducts; i++){
        double daySales;

        cout <<"====================================================" << endl;

        cout <<"Producto:" << inventory[i].product << endl;
        cout <<"Ingrese el promedio diario de ventas de ese producto " << i+1 << ": " << endl;
        cin >> daySales;

        if(daySales <= 0){
            cout <<"Error el valor promedio tiene que ser mayor a 0" << endl;    
        } else {
            double days = (inventory[i].stock*1.0)/daySales;

        cout <<"Quedan " << days <<" dias restantes de stock" << endl;

        }  if(inventory[i].yearExp < actualYear || 
            (inventory[i].yearExp == actualYear && inventory[i].monthExp < actualMonth) ||
            (inventory[i].yearExp == actualYear && inventory[i].monthExp == actualMonth && inventory[i].dayExp < actualDay )) {
             cout <<"[ALERTA] El producto ya ha caducado! RETIRAR DE INVENTARIO" << endl;
            } else if(inventory[i].yearExp == actualYear && inventory[i].monthExp == actualMonth && inventory[i].dayExp >=  actualDay && inventory[i].dayExp <= (actualDay + 7)) {
                cout <<"[ALERTA] El producto esta a menos de una semana de caducar! LIQUIDAR PRODUCTO" << endl;
            } else {
                cout <<"[ESTADO] El producto aun no caduca" << endl;
            }
        cout <<"====================================================" << endl;
    }
}

void mostrarCreditos(){
    cout <<"===================================================" << endl;
    cout <<"---------------CREDITOS DEL PROYECTO---------------" << endl;
    cout <<"===================================================" << endl;
    cout <<"----------Sistema de Inventario de Tienda----------" << endl;
    cout <<"===================================================" << endl;
    cout <<"Integrantes:" << endl;
    cout <<"Josse Jared Diaz Ramirez (carnet: 00082426)" << endl;
    cout <<"Victor Alfredo Osorio Gutierrez (carnet: 00376826)" << endl;
    cout <<"Henry Alberto Serrano Mejia (carnet: 00058426)" << endl;
    cout << "Materia:      Fundamentos de Programacion" << endl;
    cout << "Catedratico:  Ing. Elisa Aldana" << endl;
    cout << "Ciclo 02 / Ano:  2026" << endl;
    cout <<"===================================================" << endl;

}




//Inventory and sales - Jared
int registerProduct(Product inventory[], int numProducts){
    if (numProducts >= 100) {
        cout << "El inventario esta lleno" << endl;
        return numProducts;
    }

    string name;
    float price;
    int stock, minimumStock;

    cout << "=====Registrar producto=====" << endl;
    cout << "Nombre: ";
    cin >> name;

    do{
        cout << "Precio: ";
        cin >> price;
        if (price <= 0){
            cout << "El precio debe ser mayor a 0" << endl;
        }
    }while (price <= 0);

    do{
        cout << "Stock inicial: ";
        cin >> stock;
        if (stock < 0)
        {
            cout << "El stock no puede ser negativo" << endl;
        }
    }while(stock < 0);

    do
    {
        cout << "Stock minimo: ";
        cin >> minimumStock;
        if (minimumStock < 0)
        {
            cout << "El stock minimo no puede ser negativo" << endl;
        }
    } while (minimumStock < 0);

    inventory[numProducts].idProducto = numProducts + 1;
    inventory[numProducts].product = name;
    inventory[numProducts].price = price;
    inventory[numProducts].stock = stock;
    inventory[numProducts].minimumStock = minimumStock;
    inventory[numProducts].totalSales = 0;
    cout << "Producto registrado exitosamente!" << endl;
    return numProducts + 1;
}

void makeSale(Product inventory[], int numProducts){
    
}
void showInventory(Product inventory[], int numProducts){

}

void reviewStock(Product inventory[], int numProducts){

}

//Main structure of the system
int main(){
    int option, optionProduct, optionSales;

    //Variables(No globals)
    user users[4];
    Product inventory[100];
    int numusers = 0;
    int numProducts = 0;
    int currentuserRoles = 0;
    int yearexp;
    int dayexp;
    int monthexp;


    //Menu - Victor
    do{
        cout <<"=====SISTEMA DE INVENTARIO=====" << endl;
        cout <<"1.Productos" << endl;
        cout <<"2.Ventas" << endl;
        cout <<"3.Ayuda" << endl;
        cout <<"4.Creditos" << endl;
        cout <<"5.Cerrar Sesion" << endl;
        cout <<"Ingrese una opcion:" << endl;
        cin >> option;

        switch (option){
            case 1:
                do{
                    cout <<"=====Producto=====" << endl;
                    cout <<"1.Registrar producto" << endl;
                    cout <<"2.Ver inventario" << endl;
                    cout <<"3.Ver simulador de dias de inventario" << endl;
                    cout <<"4.Revisar stock" << endl;
                    cout <<"5.Volver al menu principal" << endl;
                    cout <<"Ingrese una opcion:" << endl;
                    cin >> optionProduct;
                    switch (optionProduct){
                        case 1:
                            numProducts = registerProduct(inventory, numProducts);
                            break;
                        case 2:
                            showInventory(inventory, numProducts);
                            break;
                        case 3:
                            inventorySimulator(inventory, numProducts);
                            break;
                        case 4:
                            reviewStock(inventory, numProducts);
                            break;
                    }
                }while(optionProduct !=5);
                break;
            case 2:
                do{
                    cout <<"=====Ventas=====" << endl;
                    cout <<"1.Realizar ventas" << endl;
                    cout <<"2.Ver inventario" << endl;
                    cout <<"3.Volver al menu principal" << endl;
                    cout <<"Ingrese una opcion:" << endl;
                    cin >> optionSales;

                    switch (optionSales){
                        case 1:
                            makeSale(inventory, numProducts);
                            break;
                        case 2:
                            showInventory(inventory, numProducts);
                            break;
                    }
                }while(optionSales !=3);
                break;
            case 3:
                cout <<"=========================================AYUDA========================================="<< endl;
                cout <<"=======================================================================================" << endl;
                cout <<"Producto: Al ingresar hacia el apartado producto podra" << endl;
                cout <<"encontrar 5 opciones que son: " << endl;
                cout <<"1. Registrar Inventario (Sirve para registrar los productos en el sistema)" << endl;
                cout <<"2. Ver inventario (Sirve para poder supervizar y poder tomar control" << endl;
                cout <<"sobre los productso que estan en el inventario)." << endl;
                cout <<"3. Ver Simulador De Dias De Inventario (Avisa al usuario si es conveniente actualizar" << endl;
                cout <<"el stock del producto)." << endl;
                cout <<"4.Revisar Stock (Permite al usuario revisar el stock de cada producto)" << endl;
                cout <<"5.Volver al menu principal (Regresa al menu principal)." << endl;
                cout <<"=======================================================================================" << endl;
                cout <<"Ventas: Al ingresar hacia el apartado producto podra" << endl;
                cout <<"encontrar 3 opciones que son: " << endl;
                cout <<"1.Realizar ventas (Permite al usuario realizar venta de productos)" << endl;
                cout <<"2. Ver inventario (Sirve para poder supervizar y poder tomar control" << endl;
                cout <<"sobre los productso que estan en el inventario)" << endl;
                cout <<"3. Volver Al Menu Principal (Regresa al menu principal)" << endl;
                cout <<"=======================================================================================" << endl;
                cout <<"Cerrar sesion: El suario cierra sesion en el programa y termina turno" << endl;
                break;
            case 4:
                mostrarCreditos();
                break;

             case 5:
                cout <<"Cerrando sesion..." << endl;
                break;
            default: 
                cout <<"Ingrese opcion valida." << endl;
        }
    }while(option !=5);
    return 0;
}
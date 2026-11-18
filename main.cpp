#include <iostream>
#include <string>
using namespace std;

//Structure for the users
struct User{
    int idUser;
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
};

//Simulator - Victor
void salesSimulator(Product inventory[], int numProducts){
    for(int i = 0; i < numProducts; i++){
        double daySales;

        cout <<"====================================================" << endl;
        cout <<"Ingrese el promedio diario de ventas de ese producto " << i+1 << ": " << endl;
        cin >> daySales;

        if(daySales <= 0){
            cout <<"Error el valor promedio tiene que ser mayor a 0" << endl;    
        } else {
            double days = (inventory[i].stock*1.0)/daySales;

        cout <<"Quedan " << days <<" dias restantes de stock" << endl;

        }
        cout <<"====================================================" << endl;
    }
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
    User users[4];
    Product inventory[100];
    int numUsers = 0;
    int numProducts = 0;
    int currentUserRoles = 0;

    //Test products
    inventory[0] = {1, "Frijoles", 1.50, 20, 5, 17};
    inventory[1] = {2, "Tortillas", 0.50, 24, 5, 24};
    numProducts = 2;

    //Menu - Victor
    do{
        cout <<"=====SISTEMA DE INVENTARIO=====" << endl;
        cout <<"1.Productos" << endl;
        cout <<"2.Ventas" << endl;
        cout <<"3.Ayuda" << endl;
        cout <<"4.Cerrar sesion" << endl;
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
                            salesSimulator(inventory, numProducts);
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
                cout <<"Cerrando sesion..." << endl;
                break;
            default: 
                cout <<"Ingrese opcion valida." << endl;
        }
    }while(option !=4);
    return 0;
}
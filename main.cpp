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
int registerProduct(Product inventory[], int numProducts);
void makeSale(Product inventory[], int numProdcuts);
void showInventory(Product inventory[], int numProducts);
void reviewStock(Product inventory[], int numProducts);

//Global variables
const int maxUsers = 5;
const int maxProducts = 50;
User users [maxUsers];
Product inventory[maxProducts];
int numUsers = 0;
int numProducts = 0;
int currentUserRoles = 0;


//Main structure of the system
int main(){

     int opcion, opcionproducto, opcionventas;
     Product inventory [2]{
       {1,"frijoles", 1.50,20,5,17},
     {2,"tortillas", 0.50,24,5,24}
     };

//Menu - Victor
do{
    cout <<"=====SISTEMA DE INVENTARIO=====" << endl;
    cout <<"1.Productos" << endl;
    cout <<"2.Ventas." << endl;
    cout <<"3.Ayuda" << endl;
    cout <<"4.Cerrar sesion." << endl;
    cout <<"Ingrese una opcion:" << endl;
    cin >> opcion;

    switch (opcion){
      
        case 1:
        do{        
    cout <<"=====Producto=====" << endl;
    cout <<"1.Registrar Producto." << endl;
    cout <<"2.Ver Inventario." << endl;
    cout <<"3.Ver Simulador De Dias De Inventario" << endl;
    cout <<"4.Revisar Stock." << endl;
    cout <<"5.Volver Al Menu Principal." << endl;
    cout <<"Ingrese una opcion:" << endl;
    cin >> opcionproducto;

    switch (opcionproducto){
        //Aqui iran los case de case 1
        //case 1
        case 1:
        break;

        case 2:
        break;

        case 3:

        salessimulator(inventory, 2);
        break;

        case 4:
        break;

    }
    
    
        }while(opcionproducto !=5);
        break;

        case 2:
        do{
    cout <<"=====Ventas=====" << endl;
    cout <<"1.Realizar ventas." << endl;
    cout <<"2.Ver inventario." << endl;
    cout <<"3.Volver al menu principal." << endl;
    cout <<"Ingrese una opcion:" << endl;
    cin >> opcionventas;

    switch (opcionventas);
    //Aqui iran los case de case 2
    
        }while(opcionventas !=3);
        break;

        case 3:

        cout <<"=========================================AYUDA========================================="<< endl;
        cout <<"=======================================================================================" << endl;
        cout <<"Producto: Al ingresar hacia el apartado producto podra" << endl;
        cout <<"encontrar 5 opciones que son: " << endl;
        cout <<"1. Registrar Inventario (Sirve para registrar los productos en el sistema)." << endl;
        cout <<"2. Ver inventario (Sirve para poder supervizar y poder tomar control" << endl;
        cout <<"sobre los productso que estan en el inventario)." << endl;
        cout <<"3. Ver Simulador De Dias De Inventario (Avisa al usuario si es conveniente actualizar" << endl;
        cout <<"el stock del producto)." << endl;
        cout <<"4.Revisar Stock (Permite al usuario revisar el stock de cada producto)." << endl;
        cout <<"5.Volver Al Menu Principal (Regresa al menu principal)." << endl;
        cout <<"=======================================================================================" << endl;
        cout <<"Ventas: Al ingresar hacia el apartado producto podra" << endl;
        cout <<"encontrar 3 opciones que son: " << endl;
        cout <<"1.Realizar ventas (Permite al usuario realizar venta de productos)." << endl;
        cout <<"2. Ver inventario (Sirve para poder supervizar y poder tomar control" << endl;
        cout <<"sobre los productso que estan en el inventario)" << endl;
        cout <<"3. Volver Al Menu Principal (Regresa al menu principal)." << endl;
        cout <<"=======================================================================================" << endl;
        cout <<"Cerrar sesion: El suario cierra sesion en el programa y termina turno." << endl;

        break;

        case 4:
        cout <<"Cerrando sesion..." << endl;
        break;
        default: 
        cout <<"Ingrese opcion valida." << endl;
    }
}while(opcion !=4);
    return 0;
}



   

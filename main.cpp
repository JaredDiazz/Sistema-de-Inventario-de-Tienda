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
void salessimulator(Product inventory[], int numproducts){
    for(int i = 0; i < numproducts; i++){
        double daysales;

        cout <<"====================================================" << endl;
        cout <<"ingrese el promedio diario de ventas de ese producto" << i+1 << ":" << endl;
        cin >> daysales;

        if(daysales <= 0){
            cout <<"Error el valor promedio tiene que ser mayor a 0" << endl;
            
        } else {
            double days = (inventory[i].stock*1.0)/daysales;

        cout <<"queda " << days <<" Dias restantes de stock" << endl;

        }
        cout <<"====================================================" << endl;
    }
    
}

//Inventory and sales - Jared
void registerProduct();
void makeSale();
void showInventory();
void reviewStock();


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
       {1,"frijoles", 1,4,5,8},
     {2,"tortillas", 2,5,7,12}
     };

//Menu - Victor
do{
    cout <<"=====SISTEMA DE INVENTARIO=====" << endl;
    cout <<"1.Productos" << endl;
    cout <<"2.Ventas." << endl;
    cout <<"3.Cerrar sesion." << endl;
    cout <<"Ingrese una opcion:" << endl;
    cin >> opcion;

    switch (opcion){
      
        case 1:
        do{        
    cout <<"=====Producto=====" << endl;
    cout <<"1.Registrar Producto." << endl;
    cout <<"2.Ver inventario." << endl;
    cout <<"3.Ver simulador de dias de inventario" << endl;
    cout <<"4.Revisar stock." << endl;
    cout <<"5.Volver al menu principal." << endl;
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
        cout <<"Cerrando sesion..." << endl;
        break;
        default: 
        cout <<"Ingrese opcion valida." << endl;
    }
}while(opcion !=3);

    return 0;
}



   

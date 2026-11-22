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
//Henry funcion para guardar usuarios.
// Guarda todos los usuarios dentro del archivo usuarios.txt.
void guardarUsuarios(user newUser[], int totalusuarios) {
    ofstream archivo("usuarios.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo guardar el archivo de usuarios." << endl;
        return;
    }

    archivo << totalusuarios << endl;

    for (int i = 0; i < totalusuarios; i++) {
        archivo << newUser[i].iduser << endl;
        archivo << newUser[i].username << endl;
        archivo << newUser[i].password << endl;
        archivo << newUser[i].rol << endl;
    }

    archivo.close();
}

// Carga los usuarios desde el archivo cada vez que inicia el programa.
void cargarUsuarios(user newUser[], int &totalusuarios) {
    ifstream archivo("usuarios.txt");

    if (!archivo.is_open()) {
        newUser[0] = {1, "Henry", "1325", 1};
        totalusuarios = 1;
        guardarUsuarios(newUser, totalusuarios);
        return;
    }

    archivo >> totalusuarios;

    if (totalusuarios < 1) {
        totalusuarios = 1;
        newUser[0] = {1, "Henry", "1325", 1};
        archivo.close();
        guardarUsuarios(newUser, totalusuarios);
        return;
    }

    for (int i = 0; i < totalusuarios; i++) {
        archivo >> newUser[i].iduser;
        archivo >> newUser[i].username;
        archivo >> newUser[i].password;
        archivo >> newUser[i].rol;
    }

    archivo.close();
}
// Solicita los datos de un nuevo usuario y lo agrega al arreglo.
void registrarUsuario(user newUser[], int &totalusuarios) {
    if (totalusuarios >= 5) {
        cout << "Limite de usuarios alcanzado." << endl;
        return;
    }

    newUser[totalusuarios].iduser = totalusuarios + 1;

    cout << "Ingrese el nombre de usuario: ";
    cin >> newUser[totalusuarios].username;
    cout << "Ingrese la contrasena: ";
    cin >> newUser[totalusuarios].password;
    cout << "Ingrese el rol (1 = Administrador, 2 = Vendedor): ";
    cin >> newUser[totalusuarios].rol;

    if (newUser[totalusuarios].rol != 1 && newUser[totalusuarios].rol != 2) {
        cout << "Rol no valido." << endl;
        return;
    }

    totalusuarios++;
    guardarUsuarios(newUser, totalusuarios);
    cout << "Usuario registrado exitosamente." << endl;
}

// Busca un usuario por nombre y elimina su registro del arreglo.
void eliminarUsuario(user newUser[], int &totalusuarios) {
    string nombreEliminar;
    int posicion = -1;

    cout << "Ingrese el usuario a eliminar: ";
    cin >> nombreEliminar;

    for (int i = 0; i < totalusuarios; i++) {
        if (newUser[i].username == nombreEliminar) {
            posicion = i;
            break;
        }
    }

    if (posicion == -1) {
        cout << "Usuario no encontrado." << endl;
        return;
    }

    if (posicion == 0) {
        cout << "No se puede eliminar el usuario inicial." << endl;
        return;
    }

    for (int i = posicion; i < totalusuarios - 1; i++) {
        newUser[i] = newUser[i + 1];
    }

    totalusuarios--;

    for (int i = 0; i < totalusuarios; i++) {
        newUser[i].iduser = i + 1;
    }

    guardarUsuarios(newUser, totalusuarios);
    cout << "Usuario eliminado exitosamente." << endl;
}

// Recorre el arreglo y muestra todos los usuarios registrados.
void verUsuarios(user newUser[], int totalusuarios) {
    cout << "Lista de usuarios registrados:" << endl;

    for (int i = 0; i < totalusuarios; i++) {
        cout << "ID: " << newUser[i].iduser
             << ", Nombre: " << newUser[i].username
             << ", Rol: " << newUser[i].rol << endl;
    }
}

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
    user users[5];
    int posicionUsuario = -1;
    Product inventory[100];
    int numusers = 0;
    cargarUsuarios(users, numusers);
    int numProducts = 0;
    int currentuserroles = 0;
    int yearexp;
    int dayexp;
    int monthexp;

    user enteredUser;
    cout << "Ingrese su nombre de usuario: ";
    cin >> enteredUser.username;
    cout << "Ingrese su contrasena: ";
    cin >> enteredUser.password;

    for (int i=0; i < numusers; i++){
    
        if (enteredUser.username == users[i].username && enteredUser.password == users[i].password){
            posicionUsuario = i;
        break;
        }
    }
    if (posicionUsuario == -1){
        cout << "Usuario o contrasena incorrectos" << endl;
        return 1;
    }

    currentuserroles = users[posicionUsuario].rol;
    cout << "Acceso concedido." << endl;
    cout << "ID de usuario: " << users[posicionUsuario].iduser << endl;
    cout << "Nombre de usuario: " << users[posicionUsuario].username << endl;

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
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Structure for the users
struct user{
    int idUser;
    string username;
    string password;
    int rol;
};

//Structure for the products
struct Product{
    int idProduct;
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
// Recibe el arreglo de usuarios y la cantidad actual de registros validos.
void guardarUsuarios(user newUser[], int totalusuarios) {
    ofstream archivo("users.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo guardar el archivo de usuarios." << endl;
        return;
    }

    archivo << totalusuarios << endl;

    for (int i = 0; i < totalusuarios; i++) {
        archivo << newUser[i].idUser << endl;
        archivo << newUser[i].username << endl;
        archivo << newUser[i].password << endl;
        archivo << newUser[i].rol << endl;
    }

    archivo.close();
}

//Function to load default users
void defaultUsers(user newUser[], int &totalusuarios) {
    newUser[0] = {1, "admin", "1234", 1};
    newUser[1] = {2, "Henry", "1234", 2};
    newUser[2] = {3, "Jared", "1234", 2};
    newUser[3] = {4, "Victor", "1234", 2};
    totalusuarios = 4;
}

// Carga los usuarios desde el archivo cada vez que inicia el programa.
//si el archivo no existe o esta vacio, inicializa el usuario base y lo guarda.
void cargarUsuarios(user newUser[], int &totalusuarios) {
    ifstream archivo("users.txt");

    if (!archivo.is_open()) {
        defaultUsers(newUser, totalusuarios);
        guardarUsuarios(newUser, totalusuarios);
        return;
    }

    archivo >> totalusuarios;

    if (totalusuarios < 1) {
        defaultUsers(newUser, totalusuarios);
        archivo.close();
        guardarUsuarios(newUser, totalusuarios);
        return;
    }

    for (int i = 0; i < totalusuarios; i++) {
        archivo >> newUser[i].idUser;
        archivo >> newUser[i].username;
        archivo >> newUser[i].password;
        archivo >> newUser[i].rol;
    }

    archivo.close();
}

// Solicita los datos de un nuevo usuario y lo agrega al arreglo.
// Valida que el rol sea 1 (administrador) o 2 (vendedor) y persiste el cambio en archivo.
void registerUser(user newUser[], int &totalUsers) {
    if (totalUsers >= 5) {
        cout << "Limite de usuarios alcanzado." << endl;
        return;
    }

    string username, password;
    int rol;

    cout << "Ingrese el nombre de usuario: ";
    cin >> username;

    for (int i = 0; i < totalUsers; i++)
    {
        if (newUser[i].username == username)
        {
            cout << "Ese nombre de usuario ya esta en uso." << endl;
            return;
        }
    }
    
    cout << "Ingrese la contraseña: ";
    cin >> password;
    cout << "Ingrese el rol (1 = Admin, 2 = Vendedor): ";
    cin >> rol;

    if (rol != 1 && rol != 2)
    {
        cout << "Rol invalido." << endl;
        return;
    }
    
    newUser[totalUsers].idUser = totalUsers + 1;
    newUser[totalUsers].username = username;
    newUser[totalUsers].password = password;
    newUser[totalUsers].rol = rol;

    totalUsers++;
    guardarUsuarios(newUser, totalUsers);
    cout << "Usuario registrado exitosamente." << endl;
}

// Busca un usuario por nombre y elimina su registro del arreglo.
// Restantes reasignando sus IDs antes de actualizar totalusuarios y guardar en archivo.
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
        newUser[i].idUser = i + 1;
    }

    guardarUsuarios(newUser, totalusuarios);
    cout << "Usuario eliminado exitosamente." << endl;
}

// Recorre el arreglo y muestra todos los usuarios registrados.
//Junto con su ID, nombre de usuario y rol asignado.
void verUsuarios(user newUser[], int totalusuarios) {
    cout << "Lista de usuarios registrados:" << endl;

    for (int i = 0; i < totalusuarios; i++) {
        cout << "ID: " << newUser[i].idUser
             << ", Nombre: " << newUser[i].username
             << ", Rol: " << newUser[i].rol << endl;
    }
}

//Simulator - Victor
void inventorySimulator(Product inventory[], int numProducts){
    if (numProducts == 0)
    {
        cout << "No hay productos registrados" << endl;
        return;
    }

    int actualDay, actualMonth, actualYear;
    cout << "Ingrese la fecha de hoy" << endl;

    do{
        cout << "Dia: ";
        cin >> actualDay;
        if (actualDay < 1 || actualDay > 31)
        {
            cout << "Dia invalido" << endl;
        }
    }while(actualDay < 1 || actualDay > 31);

    do{
        cout << "Mes: ";
        cin >> actualMonth;
        if (actualMonth < 1 || actualMonth > 12)
        {
            cout << "Mes invalido" << endl;
        }
    }while(actualMonth < 1 || actualMonth > 12);

    do{
        cout << "Anio: ";
        cin >> actualYear;
        if (actualYear < 2026)
        {
            cout << "Anio invalido" << endl;
        }
    }while(actualYear < 2026);

    int actualDays = actualYear * 360 + actualMonth * 30 + actualDay;

    for(int i = 0; i < numProducts; i++)
    {
        double daySales;
        cout <<"====================================================" << endl;
        cout <<"Producto: " << inventory[i].product << endl;
        cout <<"Ingrese el promedio diario de ventas: ";
        cin >> daySales;

        if(daySales <= 0)
        {
            cout <<"Error el promedio tiene que ser mayor a 0" << endl;
        } else {
            double days = (inventory[i].stock*1.0)/daySales;
            cout <<"Quedan " << days <<" dias restantes de stock" << endl;
        }

        int expDays = inventory[i].yearExp * 360 + inventory[i].monthExp * 30 + inventory[i].dayExp;
        int remaining = expDays - actualDays;

        if(remaining < 0)
        {
            cout <<"ALERTA El producto ya ha caducado ALERTA" << endl;
        } else if(remaining <= 7)
        {
            cout <<"ALERTA El producto esta a menos de una semana de caducar ALERTA" << endl;
        } else {
            cout <<"El producto aun no caduca" << endl;
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

void saveProducts(Product inventory[], int numProducts){
    ofstream archivo("products.txt");

    if (!archivo.is_open())
    {
        cout << "No se pudo guardar el archivo de los productos." << endl;
        return;
    }
    
    archivo << numProducts << endl;

    for (int i = 0; i < numProducts; i++)
    {
        archivo << inventory[i].idProduct << endl;
        archivo << inventory[i].product << endl;
        archivo << inventory[i].price << endl;
        archivo << inventory[i].stock << endl;
        archivo << inventory[i].minimumStock << endl;
        archivo << inventory[i].totalSales << endl;
        archivo << inventory[i].yearExp << endl;
        archivo << inventory[i].dayExp << endl;
        archivo << inventory[i].monthExp << endl;
    }

    archivo.close();
}

void loadDefaultProducts(Product inventory[]){
    string names[50] = {
        "Arroz", "Frijoles", "Azucar", "Sal", "Harina", "Aceite", "Pasta", "Avena", "Cereal", "Galletas",
        "Pan", "Tortillas", "Leche", "Queso", "Crema", "Mantequilla", "Yogurt", "Huevos", "Jamon", "Salchicha",
        "Pollo", "Carne", "Pescado", "Atun", "Sardina", "Manzana", "Banano", "Naranja", "Limon", "Tomate",
        "Cebolla", "Papa", "Zanahoria", "Lechuga", "Aguacate", "Cafe", "Te", "Chocolate", "Mermelada", "Miel",
        "Salsa", "Mayonesa", "Mostaza", "Jugo", "Refresco", "Agua", "Cerveza", "Papas", "Chicles", "Helado"
    };

    float prices[50] = {
        1.25, 1.50, 0.90, 0.40, 0.85, 2.50, 1.10, 1.30, 2.75, 1.20,
        0.75, 0.50, 1.15, 3.20, 1.80, 2.40, 0.95, 2.10, 2.60, 1.90,
        4.50, 5.50, 3.80, 1.75, 1.00, 0.60, 0.35, 0.45, 0.30, 0.55,
        0.40, 0.35, 0.50, 0.80, 1.25, 3.50, 1.60, 2.20, 2.00, 3.90,
        1.35, 2.30, 1.45, 1.70, 1.25, 0.75, 1.50, 1.00, 0.50, 2.80
    };

    for (int i = 0; i < 50; i++){
        inventory[i].idProduct = i + 1;
        inventory[i].product = names[i];
        inventory[i].price = prices[i];
        inventory[i].minimumStock = 5 + i % 6;
        inventory[i].stock = 15 + (i * 7) % 60;
        inventory[i].totalSales = (i * 3) % 25;
        inventory[i].dayExp = 1 + (i * 3) % 28;
        inventory[i].monthExp = 1 + i % 12;
        inventory[i].yearExp = 2027;

        if (i % 10 == 0){
            inventory[i].stock = inventory[i].minimumStock;
        }
        if (i % 17 == 0){
            inventory[i].monthExp = 10;                      
            inventory[i].yearExp = 2026;
        }
        if (i % 13 == 0){
            inventory[i].dayExp = 27;               
            inventory[i].monthExp = 11;
            inventory[i].yearExp = 2026;
        }
    }
}

int loadProducts(Product inventory[]){
    ifstream archivo("products.txt");
    int total = 0;

    if (!archivo.is_open())
    {
        loadDefaultProducts(inventory);
        saveProducts(inventory, 50);
        return 50;
    }

    archivo >> total;

    if (total > 100)
    {
        total = 100;
    }

    for (int i = 0; i < total; i++)
    {
        archivo >> inventory[i].idProduct;
        archivo >> inventory[i].product;
        archivo >> inventory[i].price;
        archivo >> inventory[i].stock;
        archivo >> inventory[i].minimumStock;
        archivo >> inventory[i].totalSales;
        archivo >> inventory[i].yearExp;
        archivo >> inventory[i].dayExp;
        archivo >> inventory[i].monthExp;
    }

    archivo.close();
    return total;
}

int readInt(string message){
    int value;
    cout << message;
    cin >> value; 

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. " << message;
        cin >> value;
    }
    return value;
}

float readFloat(string message){
    float value;
    cout << message;
    cin >> value;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Entrada invalida. " << message;
        cin >> value;
    }

    return value;
}

int daysMonth(int month, int year){
    if (month == 2){
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            return 29;
        }
        return 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11){
        return 30;
    }

    return 31;
}

void askDate(int &day, int &month, int &year){
    do{
        month = readInt("Mes: ");
        if (month < 1 || month > 12)
        {
            cout << "Mes invalido" << endl;
        }
    }while(month < 1 || month > 12);

    do{
        year = readInt("Anio: ");
        if (year < 2026)
        {
            cout << "Anio invalido" << endl;
        }
    }while(year < 2026);

    do{
        day = readInt("Dia: ");
        if (day < 1 || day > daysMonth(month, year))
        {
            cout << "Dia invalido para ese mes" << endl;
        }
    }while(day < 1 || day > daysMonth(month, year));
}

//Inventory and sales - Jared
int registerProduct(Product inventory[], int numProducts){
    if (numProducts >= 100) 
    {
        cout << "El inventario esta lleno" << endl;
        return numProducts;
    }

    string name;
    float price;
    int stock, minimumStock;
    int dayExp, monthExp, yearExp;

    cout << "=====REGISTRAR PRODUCTO=====" << endl;
    cout << "Nombre (Una palabra): ";
    cin >> name;

    do{
        price = readFloat("Precio: ");
        if (price <= 0)
        {
            cout << "El precio debe ser mayor a 0" << endl;
        }
    }while (price <= 0);

    do{
        stock = readInt("Stock inicial: ");
        if (stock < 0)
        {
            cout << "El stock no puede ser negativo" << endl;
        }
    }while(stock < 0);

    do{
        minimumStock = readInt("Stock minimo: ");
        if (minimumStock < 0)
        {
            cout << "El stock minimo no puede ser negativo" << endl;
        }
    }while (minimumStock < 0);

    cout << "Fecha de caducidad" << endl;
    askDate(dayExp, monthExp, yearExp);

    inventory[numProducts].idProduct = numProducts + 1;
    inventory[numProducts].product = name;
    inventory[numProducts].price = price;
    inventory[numProducts].stock = stock;
    inventory[numProducts].minimumStock = minimumStock;
    inventory[numProducts].totalSales = 0;
    inventory[numProducts].dayExp = dayExp;
    inventory[numProducts].monthExp = monthExp;
    inventory[numProducts].yearExp = yearExp;

    cout << "Producto registrado exitosamente." << endl;
    return numProducts + 1;
}

bool isExpired(Product product, int day, int month, int year){
    if (product.yearExp < year)
    {
        return true;
    }
    if (product.yearExp == year && product.monthExp < month)
    {
        return true;
    }
    if (product.yearExp == year && product.monthExp == month && product.dayExp < day)
    {
        return true;
    }
    return false;
}

void makeSale(Product inventory[], int numProducts, int day, int month, int year){
    if  (numProducts == 0)
    {
        cout << "No hay productos para vender" << endl;
        return;
    }

    int id, index, quantity;

    cout << "=====REALIZAR VENTA=====" << endl;
    for (int i = 0; i < numProducts; i++)
    {
        cout << inventory[i].idProduct << " " << inventory[i].product << " $" << inventory[i].price << " Stock: " << inventory[i].stock << endl;
    }
    
    do{
        id = readInt("ID: ");
        if (id < 1 || id > numProducts)
        {
            cout << "ID incorrecto" << endl;
        }
    } while (id < 1 || id > numProducts);

    index = id - 1;

    if (isExpired(inventory[index], day, month, year))
    {
        cout << "No se puede vender: el producto " << inventory[index].product << " esta caducado" << endl;
        return;
    }

    do{
        quantity = readInt("Cantidad: ");
        if (quantity <= 0)
        {
            cout << "La cantidad debe ser mayor a 0" << endl;
        }
    } while (quantity <= 0);

    if (quantity > inventory[index].stock)
    {
        cout << "Stock insuficiente. Disponible: " << inventory[index].stock << endl;
        return;
    }

    inventory[index].stock = inventory[index].stock - quantity;
    inventory[index].totalSales = inventory[index].totalSales + quantity;

    float total = quantity * inventory[index].price;
    cout << "Venta realizada. Total: $" << total << endl;

    if (inventory[index].stock <= inventory[index].minimumStock)
    {
        cout << "ALERTA: Quedan " << inventory[index].stock << " unidades de " << inventory[index].product << " (minimo: " << inventory[index].minimumStock << ")" << endl;
    }
}

void addStock(Product inventory[], int numProducts){
    if (numProducts == 0)
    {
        cout << "No hay productos registrados" << endl;
        return;
    }

    int id, quantity, invoice;

    cout << "=====INGRESO DE FACTURA=====" << endl;

    do{
        invoice = readInt("Numero de factura: ");
        if (invoice <= 0)
        {
            cout << "El numero de factura debe ser mayor a 0" << endl;
        }
    } while (invoice <= 0);

    for (int i = 0; i < numProducts; i++)
    {
        cout << inventory[i].idProduct << ". " << inventory[i].product << " (stock: " << inventory[i].stock << ")" << endl;
    }

    do{
        id = readInt("ID del producto: ");
        if (id < 1 || id > numProducts)
        {
            cout << "ID invalido" << endl;
        }
    } while (id < 1 || id > numProducts);

    do{
        quantity = readInt("Cantidad recibida: ");
        if (quantity <= 0)
        {
            cout << "La cantidad debe ser mayor a 0" << endl;
        }
    } while (quantity <= 0);

    inventory[id - 1].stock = inventory[id - 1].stock + quantity;

    cout << "Factura " << invoice << " registrada. " << inventory[id - 1].product << " ahora tiene " << inventory[id - 1].stock << " unidades" << endl;
}

void showInventory(Product inventory[], int numProducts){
    cout << "=====INVENTARIO=====" << endl;

    if (numProducts == 0)
    {
        cout << "No hay productos registrados" << endl;
        return;
    }
    
    for( int i = 0; i < numProducts; i++){
        cout << "ID: " << inventory[i].idProduct << endl;
        cout << "Producto: " << inventory[i].product << endl;
        cout << "Precio: " << inventory[i].price << endl;
        cout << "Stock: " << inventory[i].stock << endl;
        cout << "Stock minimo: " << inventory[i].minimumStock << endl;
        cout << "Ventas Totales: " << inventory[i].totalSales << endl;
        cout << "Caducidad: " << inventory[i].dayExp << "/" << inventory[i].monthExp << "/" << inventory[i].yearExp << endl;
        cout << "====================" << endl;
    }
}

void reviewStock(Product inventory[], int numProducts){
    cout << "=====REVISION DE STOCK=====" << endl;

    if (numProducts == 0){
        cout << "NO HAY PRODUCTO REGISTRADOS" << endl;
        return;
    }

    int alert = 0;

    for (int i = 0; i < numProducts; i++){
        if (inventory[i].stock == 0){
            cout << "PRODUCTO AGOTADO: " << inventory[i].product << endl;
            alert++;
        } else if (inventory[i].stock <= inventory[i].minimumStock)
        {
            cout << "ALERTA: " << inventory[i].product << " tiene " << inventory[i].stock << " unidades (minimo de unidades: " << inventory[i].minimumStock << ")" << endl;
            alert++;
        }
    }
    
    if (alert == 0)
    {
        cout << "Todos los productos cuentan con suficiente stock" << endl;
    }
}

//Main structure of the system
int main(){
    int option, optionProduct, optionSales;

    //Variables(No globals)
    user users[5];
    int userPosition = -1;
    Product inventory[100];
    int numUsers = 0;
    cargarUsuarios(users, numUsers);
    int numProducts = loadProducts(inventory);
    int currentUserRoles = 0;

    user enteredUser;
    int attempts = 0;
    while (userPosition == -1 && attempts < 3)
    {
        cout << "Ingrese su nombre de usuario: ";
        cin >> enteredUser.username;
        cout << "ingrese su contrasena: ";
        cin >> enteredUser.password;

        for (int i = 0; i < numUsers; i++)
        {
            if (enteredUser.username == users[i].username && enteredUser.password == users[i].password)
            {
                userPosition = i;
                break;
            }
        }
        
        if (userPosition == -1)
        {
            attempts++;
            cout << "Usuario o contrasenas incorrectos." << endl;
        }
    }
    
    if (userPosition == -1)
    {
        cout << "Demasiados intentos. Cerrando el programa" << endl;
        return 1;
    }
    
    currentUserRoles = users[userPosition].rol;
    cout << "Acceso concedido." << endl;
    cout << "ID de usuario: " << users[userPosition].idUser << endl;
    cout << "Nombre de usuario: " << users[userPosition].username << endl;

    int todayDay, todayMonth, todayYear;
    cout << "Ingrese la fecha de hoy: " << endl;
    askDate(todayDay, todayMonth, todayYear);

    //Menu - Victor
    do{
        cout <<"=====SISTEMA DE INVENTARIO=====" << endl;
        if (currentUserRoles == 1){
            cout <<"1. Productos" << endl;
        }
        cout <<"2. Ventas" << endl;
        cout <<"3. Ayuda" << endl;
        cout <<"4. Creditos" << endl;
        cout <<"5. Cerrar Sesion" << endl;
        if (currentUserRoles == 1) {
            cout << "6. Registrar Usuario" << endl;
            cout << "7. Eliminar usuario" << endl;
            cout << "8. Ver usuarios" << endl;
        }else if (currentUserRoles == 2) {
            cout << "6. Ver usuarios" << endl;
        } else {
            cout << "Error: rol de usuario no valido." << endl;
            return 1;
        }
        option = readInt("Ingrese una opcion: ");

        switch (option){
            case 1:
            if (currentUserRoles == 1){
                do{
                    cout << "=====Producto=====" << endl;
                    cout << "1. Registrar producto" << endl;
                    cout << "2. Ver inventario" << endl;
                    cout << "3. Ver simulador de dias de inventario" << endl;
                    cout << "4. Revisar stock" << endl;
                    cout << "5. Ingresar factura" << endl;
                    cout << "6. Volver al menu principal" << endl;
                    optionProduct = readInt("Ingrese una opcion: ");
                    switch (optionProduct){
                        case 1:
                            numProducts = registerProduct(inventory, numProducts);
                            saveProducts(inventory, numProducts);
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
                        case 5:
                            addStock(inventory, numProducts);
                            saveProducts(inventory, numProducts);
                            break;
                    }
                }while(optionProduct !=6);
                }else {
                cout <<"acceso denegado: solo para administradores." << endl;
                }
                break;
            case 2:
                do{
                    cout <<"=====Ventas=====" << endl;
                    cout <<"1.Realizar ventas" << endl;
                    cout <<"2.Ver inventario" << endl;
                    cout <<"3.Volver al menu principal" << endl;
                    optionSales = readInt("Ingrese una opcion: ");

                    switch (optionSales){
                        case 1:
                            makeSale(inventory, numProducts, todayDay, todayMonth, todayYear);
                            saveProducts(inventory, numProducts);
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
                cout <<"4. Revisar Stock (Permite al usuario revisar el stock de cada producto)" << endl;
                cout <<"5. Ingresar factura (aumenta el stock de un producto que ya existe)." << endl;
                cout <<"6.Volver al menu principal (Regresa al menu principal)." << endl;
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
            case 6 :
             if (currentUserRoles == 1){
                registerUser(users, numUsers);
                }else if (currentUserRoles == 2){
                    verUsuarios(users, numUsers);
                }else {
                cout << "Ingrese opcion valida." << endl;
                }
                break;
            case 7 :
                if (currentUserRoles == 1){
                    eliminarUsuario(users,numUsers);
                } else {
                    cout << "Ingrese opcion valida." << endl;
                }
                break;
            case 8 :
                if (currentUserRoles == 1){
                    verUsuarios(users,numUsers);
                } else {
                cout << "Ingrese opcion valida." << endl;
                }
                break;
            default: 
                cout <<"Ingrese opcion valida." << endl;
        }
    }while(option !=5);
    return 0;
}
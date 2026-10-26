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
    cout << "Hola mundo";
    return 0;
}
#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <memory>

typedef std::vector<std::unique_ptr<std::string>> VECUNIQPTRSTR;
typedef std::vector<std::unique_ptr<int>> VECUNIQPTRINT;
typedef std::vector<std::unique_ptr<double>> VECUNIQPTRD;

int InventoryCount{0};

void addPlayerInventory(
    VECUNIQPTRSTR &vupNames,
    VECUNIQPTRINT &vupQtys,
    VECUNIQPTRD &vupPrices);

void removePlayerInventory(
    VECUNIQPTRSTR &vupNames,
    VECUNIQPTRINT &vupQtys,
    VECUNIQPTRD &vupPrices);

void displayPlayerInventory(
    VECUNIQPTRSTR &vupNames,
    VECUNIQPTRINT &vupQtys,
    VECUNIQPTRD &vupPrices);

int main()
{
    return 0;
}

void addPlayerInventory(
    VECUNIQPTRSTR &vupNames,
    VECUNIQPTRINT &vupQtys,
    VECUNIQPTRD &vupPrices)
{
    std::cout << "==============================================================" << '\n';
    std::cout << "\t Add Player Inventory \t" << '\n';

    std::cout << "\t Enter Player Inventory Name \t" << '\n';
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "\t Enter Player Inventory Quantity \t" << '\n';
    int quantity;
    std::cin >> quantity;

    std::cout << "\t Enter Player Inventory Price \t" << '\n';
    std::cout << "$ ";
    double price;
    std::cin >> price;

    vupNames.push_back(std::move(std::make_unique<std::string>(name)));
    vupQtys.push_back(std::move(std::make_unique<int>(quantity)));
    vupPrices.push_back(std::move(std::make_unique<double>(price)));

    std::cout << "==========================================================" << '\n';
}

void displayPlayerInventory(
    VECUNIQPTRSTR &vupNames,
    VECUNIQPTRINT &vupQtys,
    VECUNIQPTRD &vupPrices)
{
    std::cout << "\n Inventory: \n";
    std::cout << "ID\t\tName\t\tPrice\t\tQuantity\n";
    std::cout << "==========================================================================" << '\n';
   for(int i{0}; i <InventoryCount; i++){
    
   }
}
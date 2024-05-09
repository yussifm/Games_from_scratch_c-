#include <iostream>
#include <vector>
#include <format>
#include <string>
#include <memory>

typedef std::vector<std::unique_ptr<std::string>> VECUNIQPTRSTR;
typedef std::vector<std::unique_ptr<int>> VECUNIQPTRINT;
typedef std::vector<std::unique_ptr<double>> VECUNIQPTRD;

int InventoryCount{ 0 };

void addPlayerInventory(
    VECUNIQPTRSTR& vupNames,
    VECUNIQPTRINT& vupQtys,
    VECUNIQPTRD& vupPrices);



void displayPlayerInventory(
  const  VECUNIQPTRSTR& vupNames,
 const   VECUNIQPTRINT& vupQtys,
 const   VECUNIQPTRD& vupPrices);

int main()
{

    VECUNIQPTRSTR vupNames;
    VECUNIQPTRINT vupQtys;
    VECUNIQPTRD vupPrices;

    while (true) {
        std::cout << "\nChoose an Option:\n"
            << "1: Add Inventory\n"
            << "2: Display Inventory\n"
            << "3: Quit\n";

        int choice{ 0 };
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            addPlayerInventory(vupNames, vupQtys, vupPrices);
            break;

        case 2:
            displayPlayerInventory(vupNames, vupQtys, vupPrices);
            break;

        case 3:
            std::cout << "\n Exiting Program .....\n";
            return 0;
            
        default:
            std::cout << "Invalid Choice, try again \n";
            break;
        }
   }
    
    return 0;
}

void addPlayerInventory(
    VECUNIQPTRSTR& vupNames,
    VECUNIQPTRINT& vupQtys,
    VECUNIQPTRD& vupPrices)
{
    std::cout << "==============================================================" << '\n';
    std::cout << "Add Player Inventory" << '\n';
    std::unique_ptr<std::string> name = std::make_unique<std::string>();
    std::unique_ptr<int>quantity = std::make_unique<int>();
    std::unique_ptr<double> price = std::make_unique<double>();

    std::cout << "Enter Player Inventory Name: ";
    
    std::cin.ignore();
    std::getline(std::cin, *name);

    std::cout << "Enter Player Inventory Quantity: ";
   
    std::cin >> *quantity;

    std::cout << "Enter Player Inventory Price: ";
    std::cout << "$";
 
    std::cin >> *price;

    vupNames.push_back(std::move(name));
    vupQtys.push_back(std::move(quantity));
    vupPrices.push_back(std::move(price));
    InventoryCount++;

    std::cout << "==========================================================" << '\n';
}

void displayPlayerInventory(
  const  VECUNIQPTRSTR& vupNames,
  const  VECUNIQPTRINT& vupQtys,
   const VECUNIQPTRD& vupPrices)
{
    std::cout << "\n Inventory: \n";
    std::cout << "ID\t\tName\t\tPrice\t\tQuantity\n";
    std::cout << "==========================================================================" << '\n';
    for (int i{ 0 }; i < InventoryCount; i++) {
        std::cout << std::format("{}\t\t{}\t\t{}\t\t{}", i+1, *vupNames[i], *vupPrices[i], *vupQtys[i]) <<'\n';
    }

    std::cout << "==========================================================================" << '\n';
}
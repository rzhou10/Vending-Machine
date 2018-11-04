#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

struct Drink{
    std::string name;
    double price;
    int quantity;

    Drink(){
        name = "";
        price = 0;
        quantity = 0;
    }

    Drink(std::string n, double p, int q){
        name = n;
        price = p;
        quantity = q;
    }
};

Drink drinks[6] = {Drink("Coke", 1.00, 5), Drink("Sprite", 1.00, 5), Drink("Water", 1.25, 5), Drink("Gatorade", 1.00, 5), Drink("Ginger Ale", 1.25, 5), Drink("Iced Tea", 1.50, 5)};
int choice;
double payment;
double total;
double change;
bool isVending = true;

void getDrink(int total, Drink drinks[], int choice){
    if (total < drinks[choice].price){
        std::cout << "Insufficient amount, please try again.\n";
    }
    else if (drinks[choice].quantity == 0){
        std::cout << "There is no " + drinks[choice].name + " left.\n";
    }
    else{
        drinks[choice].quantity--;
        total -= drinks[choice].price;
        if (total > 0){
            std::cout << "Your change is: " << total << ".\n";
        }
        std::cout << "Enjoy your drink!\n";
    }
}

int main(){
    while (isVending){
        std::cout << "Enter your payment amounts in value (0.01, 0.05, etc) up to 5.00. Enter -1 to exit.\n";
        std::vector<double> vec = {0.01, 0.05, 0.10, 0.25, 1.00, 5.00};

        while (true){
            std::cin >> payment;
            if (payment <= -1.0){
                break;
            }
            else if (payment > 5.0){
                std::cout << "Cannot accept anything greater than 5 dollars.\n";
            }
            else if (std::find(vec.begin(), vec.end(), payment) == vec.end()){
                std::cout << "Not a valid form of payment.\n";
            }
            else{
                total += payment;
                std::cout << "Amount: " + std::to_string(total) + ".\n";
            }
        }

        std::cout << "Hello, what drink would you like today?\n";
        std::cout << "0 - Coke, $" << drinks[0].price << ".\n";
        std::cout << "1 - Sprite, $" << drinks[1].price << ".\n";
        std::cout << "2 - Water, $" << drinks[2].price << ".\n";
        std::cout << "3 - Gatorade, $" << drinks[3].price << ".\n";
        std::cout << "4 - Ginger Ale, $" << drinks[4].price << ".\n";
        std::cout << "5 - Iced Tea, $" << drinks[5].price << ".\n";
        std::cout << "6 - Leave\n";
        std::cin >> choice;

        switch(choice){
            case 0:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 1:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 2:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 3:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 4:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 5:
                getDrink(total, drinks, choice);
                total = 0.0;
                break;
            case 6:
                std::cout << "Have a nice day!";
                isVending = false;
                break;
            default:
                std::cout << "Not a valid operation, please try again";
        }
    }
}
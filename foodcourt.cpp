#include <iostream>
#include <iomanip>
using namespace std;
//USING CLASSES AND OBJECTS
class FoodItem {
public:
    int id;
    string name;
    float price;

    FoodItem() {}
    FoodItem(int fid, string fname, float fprice) {
        id = fid;
        name = fname;
        price = fprice;
    }

    void display() {
        cout << setw(5) << id << setw(25) << name << setw(10) << price << endl;
    }
};
//IMPLEMENTING INHERITANCE
class OrderItem : public FoodItem {
    int quantity;
public:
    void setItem(FoodItem f, int qty) {
        id = f.id;
        name = f.name;
        price = f.price;
        quantity = qty;
    }

    float getTotal() {
        return price * quantity;
    }

    void displayItem() {
        cout << left << setw(25) << name
             << right << setw(10) << price
             << setw(10) << quantity
             << setw(10) << getTotal() << endl;
    }
};

int main() {
    // Predefined food menu
    FoodItem menu[6] = {
        FoodItem(1, "Cheese Pizza", 120.0),
        FoodItem(2, "Veg Burger", 80.0),
        FoodItem(3, "French Fries", 60.0),
        FoodItem(4, "Cold Coffee", 50.0),
        FoodItem(5, "Pasta", 100.0),
        FoodItem(6, "Ice Cream", 40.0)
    };

    OrderItem cart[10]; // max 10 items
    int cartCount = 0;
    char choice;

    do {
        cout << "\n========== FOOD COURT MENU ==========\n";
        cout << setw(5) << "ID" << setw(25) << "Item" << setw(10) << "Price" << endl;
        cout << "---------------------------------------------\n";
        for (int i = 0; i < 6; i++) {
            menu[i].display();
        }

        int fid, qty;
        cout << "\nEnter Food ID to order: ";
        cin >> fid;

        if (fid < 1 || fid > 6) {
            cout << "Invalid ID! Try again.\n";
        } else {
            cout << "Enter quantity: ";
            cin >> qty;
            cart[cartCount].setItem(menu[fid - 1], qty);
            cartCount++;
        }

        cout << "Order more items? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Final bill
    float grandTotal = 0;
    cout << "\n=========== YOUR BILL ===========\n";
    cout << left << setw(25) << "Item"
         << right << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(10) << "Total" << endl;
    cout << "---------------------------------------------\n";
    for (int i = 0; i < cartCount; i++) {
        cart[i].displayItem();
        grandTotal += cart[i].getTotal();
    }
    cout << "---------------------------------------------\n";
    cout << right << setw(45) << "Grand Total: Rs." << grandTotal << endl;
    cout << "Thanks for ordering at the Food Court!\n";

    return 0;
}

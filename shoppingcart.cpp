#include <iostream>
#include <iomanip>
using namespace std;

class Item {
public:
    int id;
    string name;
    float price;

    Item() {}
    Item(int iid, string iname, float iprice) {
        id = iid;
        name = iname;
        price = iprice;
    }

    void display() {
        cout << setw(5) << id << setw(25) << name << setw(10) << price << endl;
    }
};

class CartItem : public Item {
    int quantity;
public:
    void setItem(Item i, int qty) {
        id = i.id;
        name = i.name;
        price = i.price;
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
    // Predefined shopping items
    Item store[6] = {
        Item(1, "T-Shirt", 499.0),
        Item(2, "Jeans", 999.0),
        Item(3, "Sneakers", 1499.0),
        Item(4, "Cap", 199.0),
        Item(5, "Backpack", 1299.0),
        Item(6, "Wallet", 349.0)
    };

    CartItem cart[10]; // max 10 items in cart
    int cartCount = 0;
    char choice;

    do {
        cout << "\n========== SHOPPING CART MENU ==========\n";
        cout << setw(5) << "ID" << setw(25) << "Item" << setw(10) << "Price" << endl;
        cout << "---------------------------------------------\n";
        for (int i = 0; i < 6; i++) {
            store[i].display();
        }

        int pid, qty;
        cout << "\nEnter Product ID to add: ";
        cin >> pid;

        if (pid < 1 || pid > 6) {
            cout << "Invalid ID! Try again.\n";
        } else {
            cout << "Enter quantity: ";
            cin >> qty;
            cart[cartCount].setItem(store[pid - 1], qty);
            cartCount++;
        }

        cout << "Add more items? (y/n): ";
        cin >> choice;

    } while ((choice == 'y' || choice == 'Y') && cartCount < 10);

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
    cout << "Thanks for shopping with us!\n";

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
//USE OF CLASSES AND OBJECTS
class Product {
public:
    int id;
    string name;
    float price;

    Product() {}
    Product(int pid, string pname, float pprice) {
        id = pid;
        name = pname;
        price = pprice;
    }

    void display() {
        cout << setw(5) << id << setw(20) << name << setw(10) << price << endl;
    }
};
//IMPLEMENTING INHERITANCE
class CartItem : public Product {
    int quantity;
public:
    void setItem(Product p, int qty) {
        id = p.id;
        name = p.name;
        price = p.price;
        quantity = qty;
    }

    float getTotal() {
        return price * quantity;
    }

    void displayItem() {
        cout << left << setw(20) << name
             << right << setw(10) << price
             << setw(10) << quantity
             << setw(10) << getTotal() << endl;
    }
};

int main() {
    Product productList[5] = {
        Product(1, "Milk", 40.0),
        Product(2, "Bread", 30.0),
        Product(3, "Eggs", 60.0),
        Product(4, "Rice", 70.0),
        Product(5, "Soap", 25.0)
    };

    CartItem cart[10];  
    int cartCount = 0;
    char choice;
    do {
        // Show menu
        cout << "\n======= SUPERMARKET MENU =======\n";
        cout << setw(5) << "ID" << setw(20) << "Product" << setw(10) << "Price" << endl;
        cout << "----------------------------------------\n";
        for (int i = 0; i < 5; i++) {
            productList[i].display();
        }

        int pid, qty;
        cout << "\nEnter Product ID to add to cart: ";
        cin >> pid;
        if (pid < 1 || pid > 5) {
            cout << "Invalid Product ID!\n";
        } else {
            cout << "Enter quantity: ";
            cin >> qty;
            cart[cartCount].setItem(productList[pid - 1], qty);
            cartCount++;
        }

        cout << "Add more items? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Generate Bill
    float grandTotal = 0;
    cout << "\n========= FINAL BILL =========\n";
    cout << left << setw(20) << "Product"
         << right << setw(10) << "Price"
         << setw(10) << "Qty"
         << setw(10) << "Total" << endl;
    cout << "------------------------------------------\n";

    for (int i = 0; i < cartCount; i++) {
        cart[i].displayItem();
        grandTotal += cart[i].getTotal();
    }

    cout << "------------------------------------------\n";
    cout << right << setw(40) << "Grand Total: Rs." << grandTotal << endl;
    cout << "Thank you for shopping with us!\n";

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;

class Item
{
private:
    string name;
    double price;

public:
    Item(string n = "", double p = 0.0)
    {
        name = n;
        price = p;
    }

    string getName() const { return name; }
    double getPrice() const { return price; }

    friend ostream &operator<<(ostream &os, const Item &it);
};

ostream &operator<<(ostream &os, const Item &it)
{
    os << it.name << " - Rs." << it.price;
    return os;
}

class CartItem
{
public:
    Item item;
    int quantity;

    CartItem(Item i, int q)
    {
        item = i;
        quantity = q;
    }

    double getItemTotal() const
    {
        return item.getPrice() * quantity;
    }
};

class Bill
{
protected:
    vector<CartItem> cart;
    double total;
    double taxRate;

public:
    Bill()
    {
        total = 0;
        taxRate = 0.18;
    }

    virtual void generateBill() = 0;
};

class LaptopBill : public Bill
{
private:
    vector<Item> store;
    string cashier;
    string datetime;
    int bill_no;

public:
    LaptopBill()
    {
        cashier = "Alice";

        store = {
            {"Dell Inspiron 15", 55000},
            {"HP Pavilion 14", 62000},
            {"Lenovo ThinkPad X1", 95000},
            {"Asus ZenBook 13", 72000},
            {"Apple MacBook Air", 105000},
            {"Acer Aspire 5", 48000},
            {"MSI GF63 Gaming", 78000},
            {"Dell XPS 13", 110000},
            {"HP Spectre x360", 99000},
            {"Logitech Wireless Mouse", 2500}};
    }

    void displayItems()
    {
        cout << "\nAvailable Items:\n";
        for (size_t i = 0; i < store.size(); ++i)
        {
            cout << i + 1 << ". " << store[i] << "\n";
        }
        cout << "0. Finish and generate bill\n";
    }

    void shopping()
    {
        int choice, qty;
        while (true)
        {
            displayItems();
            cout << "Enter item number: ";
            cin >> choice;
            if (choice == 0)
                break;

            if (choice > 0 && choice <= (int)store.size())
            {
                cout << "Enter quantity: ";
                cin >> qty;
                cart.push_back(CartItem(store[choice - 1], qty));
                cout << store[choice - 1].getName() << " x" << qty << " added to cart.\n";
            }
            else
            {
                cout << "Invalid choice, try again.\n";
            }
        }
    }

    void generateMeta()
    {
        srand(time(0));
        bill_no = 1000 + rand() % 9000;

        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[50];
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", ltm);
        datetime = buffer;
    }

    void generateBill() override
    {
        generateMeta();

        ostringstream bill;
        bill << "========================================\n";
        bill << "            LAPTOP SHOP\n";
        bill << "========================================\n";
        bill << "Bill No: " << bill_no << "   Cashier: " << cashier << "\n";
        bill << "Date/Time: " << datetime << "\n";
        bill << "----------------------------------------\n";
        bill << left << setw(20) << "Item"
             << right << setw(5) << "Qty"
             << right << setw(12) << "Price\n";
        bill << "----------------------------------------\n";

        for (const auto &ci : cart)
        {
            double item_total = ci.getItemTotal();
            bill << left << setw(20) << ci.item.getName()
                 << right << setw(5) << ci.quantity
                 << right << setw(12) << ("Rs." + to_string(item_total)) << "\n";
            total += item_total;
        }

        double tax = total * taxRate;
        double grand_total = total + tax;

        bill << "----------------------------------------\n";
        bill << left << setw(20) << "Subtotal" << right << setw(12) << ("Rs." + to_string(total)) << "\n";
        bill << left << setw(20) << "GST (18%)" << right << setw(12) << ("Rs." + to_string(tax)) << "\n";
        bill << left << setw(20) << "TOTAL" << right << setw(12) << ("Rs." + to_string(grand_total)) << "\n";
        bill << "========================================\n";
        bill << "       Thank you for shopping with us!\n";
        bill << "========================================\n";

        cout << "\n"
             << bill.str();

        string phone;
        cout << "Enter WhatsApp number (with country code, e.g., +91xxxxxxxxxx): ";
        cin >> phone;

        string bill_cmd = bill.str();
        replace(bill_cmd.begin(), bill_cmd.end(), '\n', '`');

        string command = "python app.py " + phone + " \"" + bill_cmd + "\"";
        int result = system(command.c_str());

        if (result == 0)
            cout << "WhatsApp invoice sent successfully!\n";
        else
            cout << "Failed to send WhatsApp invoice.\n";
    }
};

int main()
{
    cout << "Welcome to LAPTOP SHOP Billing System!\n";

    LaptopBill bill;
    bill.shopping();
    bill.generateBill();

    return 0;
}

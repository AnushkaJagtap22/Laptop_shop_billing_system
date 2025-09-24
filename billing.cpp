#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>

struct Item
{
    std::string name;
    double price;
};

struct CartItem
{
    Item item;
    int quantity;
};

int main()
{
    // Laptop shop items (10 realistic items)
    std::vector<Item> store = {
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

    std::vector<CartItem> cart;
    int choice, qty;

    std::cout << "Welcome to LAPTOP SHOP Billing System!\n";

    // Shopping loop
    while (true)
    {
        std::cout << "\nAvailable Items:\n";
        for (size_t i = 0; i < store.size(); ++i)
        {
            std::cout << i + 1 << ". " << store[i].name << " - Rs." << store[i].price << "\n";
        }
        std::cout << "0. Finish and generate bill\n";
        std::cout << "Enter item number: ";
        std::cin >> choice;
        if (choice == 0)
            break;

        if (choice > 0 && choice <= (int)store.size())
        {
            std::cout << "Enter quantity: ";
            std::cin >> qty;
            cart.push_back({store[choice - 1], qty});
            std::cout << store[choice - 1].name << " x" << qty << " added to cart.\n";
        }
        else
        {
            std::cout << "Invalid choice, try again.\n";
        }
    }

    // Generate bill number
    srand(time(0));
    int bill_no = 1000 + rand() % 9000;

    // Date/time
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char datetime[50];
    strftime(datetime, sizeof(datetime), "%d/%m/%Y %H:%M:%S", ltm);

    // Cashier name
    std::string cashier = "Alice";

    // Generate receipt
    double total = 0;
    double tax_rate = 0.18; // 18% GST for electronics
    std::ostringstream bill;

    bill << "========================================\n";
    bill << "            LAPTOP SHOP\n";
    bill << "========================================\n";
    bill << "Bill No: " << bill_no << "   Cashier: " << cashier << "\n";
    bill << "Date/Time: " << datetime << "\n";
    bill << "----------------------------------------\n";
    bill << std::left << std::setw(20) << "Item"
         << std::right << std::setw(5) << "Qty"
         << std::right << std::setw(12) << "Price\n";
    bill << "----------------------------------------\n";

    for (const auto &ci : cart)
    {
        double item_total = ci.item.price * ci.quantity;
        bill << std::left << std::setw(20) << ci.item.name
             << std::right << std::setw(5) << ci.quantity
             << std::right << std::setw(12) << ("Rs." + std::to_string(item_total)) << "\n";
        total += item_total;
    }

    double tax = total * tax_rate;
    double grand_total = total + tax;

    bill << "----------------------------------------\n";
    bill << std::left << std::setw(20) << "Subtotal" << std::right << std::setw(12) << ("Rs." + std::to_string(total)) << "\n";
    bill << std::left << std::setw(20) << "GST (18%)" << std::right << std::setw(12) << ("Rs." + std::to_string(tax)) << "\n";
    bill << std::left << std::setw(20) << "TOTAL" << std::right << std::setw(12) << ("Rs." + std::to_string(grand_total)) << "\n";
    bill << "========================================\n";
    bill << "       Thank you for shopping with us!\n";
    bill << "========================================\n";

    std::cout << "\n"
              << bill.str();

    // WhatsApp sending
    std::string phone;
    std::cout << "Enter WhatsApp number (with country code, e.g., +91xxxxxxxxxx): ";
    std::cin >> phone;

    // Replace line breaks for command-line
    std::string bill_cmd = bill.str();
    std::replace(bill_cmd.begin(), bill_cmd.end(), '\n', '`'); // use ` as placeholder

    std::string command = "python app.py " + phone + " \"" + bill_cmd + "\"";
    int result = system(command.c_str());

    if (result == 0)
        std::cout << "WhatsApp invoice sent successfully!\n";
    else
        std::cout << "Failed to send WhatsApp invoice.\n";

    return 0;
}

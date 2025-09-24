# Laptop Shop Billing System

![C++](https://img.shields.io/badge/Language-C++-blue)
![Python](https://img.shields.io/badge/Python-3.x-green)
![License](https://img.shields.io/badge/License-MIT-yellow)

A **console-based billing system** for a laptop shop, written in **C++**, with **Python integration** to send invoices via **WhatsApp** using **Twilio**.  
The system generates realistic POS-style bills including itemized lists, subtotal, GST, total, bill number, cashier name, and date/time.

---

## Features

- Realistic **itemized bill** with quantity, price, subtotal, GST (18%), and total.
- **Bill number, cashier name, date & time** included.
- **10 realistic laptop-related products** (laptops & accessories).
- Sends **bill directly to WhatsApp** via Twilio sandbox.
- **Well-formatted receipt**, looks like a real POS invoice.

---

## Requirements

- **C++ compiler** (g++, clang, etc.)
- **Python 3.x**
- Python packages: `twilio`, `python-dotenv`
  

pip install twilio python-dotenv
Twilio account with WhatsApp sandbox enabled.

Setup
Clone the repository:

git clone https://github.com/<your-username>/laptop-shop-billing.git
cd laptop-shop-billing
Copy environment variables:

cp .env.example .env
Fill .env with your Twilio credentials.
## OUTPUT 

PS C:\Users\HP\Documents\ANUSHKA\Projects\OOP Billing_System> g++ billing.cpp -o billing
>> 
PS C:\Users\HP\Documents\ANUSHKA\Projects\OOP Billing_System> .\billing
>>
Welcome to LAPTOP SHOP Billing System!

Available Items:
1. Dell Inspiron 15 - Rs.55000
2. HP Pavilion 14 - Rs.62000
3. Lenovo ThinkPad X1 - Rs.95000
4. Asus ZenBook 13 - Rs.72000
5. Apple MacBook Air - Rs.105000
6. Acer Aspire 5 - Rs.48000
7. MSI GF63 Gaming - Rs.78000
8. Dell XPS 13 - Rs.110000
9. HP Spectre x360 - Rs.99000
10. Logitech Wireless Mouse - Rs.2500
0. Finish and generate bill
Enter item number: 5
Enter quantity: 1
Apple MacBook Air x1 added to cart.

Available Items:
1. Dell Inspiron 15 - Rs.55000
2. HP Pavilion 14 - Rs.62000
3. Lenovo ThinkPad X1 - Rs.95000
4. Asus ZenBook 13 - Rs.72000
5. Apple MacBook Air - Rs.105000
6. Acer Aspire 5 - Rs.48000
7. MSI GF63 Gaming - Rs.78000
8. Dell XPS 13 - Rs.110000
9. HP Spectre x360 - Rs.99000
10. Logitech Wireless Mouse - Rs.2500
0. Finish and generate bill
Enter item number: 10
Enter quantity: 3
Logitech Wireless Mouse x3 added to cart.

Available Items:
1. Dell Inspiron 15 - Rs.55000
2. HP Pavilion 14 - Rs.62000
3. Lenovo ThinkPad X1 - Rs.95000
4. Asus ZenBook 13 - Rs.72000
5. Apple MacBook Air - Rs.105000
6. Acer Aspire 5 - Rs.48000
7. MSI GF63 Gaming - Rs.78000
8. Dell XPS 13 - Rs.110000
9. HP Spectre x360 - Rs.99000
10. Logitech Wireless Mouse - Rs.2500
0. Finish and generate bill
Enter item number: 0

<img width="347" height="293" alt="image" src="https://github.com/user-attachments/assets/c851d8a6-0464-4a0e-b8ab-4174ac33dab3" />


Enter WhatsApp number (with country code, e.g., +91xxxxxxxxxx): +919503353458
Message sent! SID: SM99e75e8b65099e961c55d8e58f3e5b03
WhatsApp invoice sent successfully!
PS C:\Users\HP\Documents\ANUSHKA\Projects\OOP Billing_System>

<img width="732" height="565" alt="image" src="https://github.com/user-attachments/assets/1a01850c-f78c-4974-a1c2-8c541ba4a807" />




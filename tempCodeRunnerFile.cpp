#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Structure to hold product information
struct Product {
    int id;
    string name;
    float price;
    int quantity;

    // Function to calculate the total price of a product
    float totalPrice() const {
        return price * quantity;
    }
};

// Global vector to store products
vector<Product> products;

// Function prototypes
void addProduct();
void displayProducts();
void updateProduct();
void deleteProduct();
void menu();

int main() {
    while (true) {
        menu();
    }
    return 0;
}

// Function to display the menu
void menu() {
    cout << "\n========== General Store Management System ==========\n";
    cout << "1. Add Product\n";
    cout << "2. Display Products\n";
    cout << "3. Update Product\n";
    cout << "4. Delete Product\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            addProduct();
            break;
        case 2:
            displayProducts();
            break;
        case 3:
            updateProduct();
            break;
        case 4:
            deleteProduct();
            break;
        case 5:
            cout << "Exiting... Thank you!\n";
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
    }
}

// Function to add a new product
void addProduct() {
    Product newProduct;
    cout << "\nEnter Product ID: ";
    cin >> newProduct.id;
    cout << "Enter Product Name: ";
    cin.ignore(); // Clear the buffer
    getline(cin, newProduct.name);
    cout << "Enter Product Price: ";
    cin >> newProduct.price;
    cout << "Enter Product Quantity: ";
    cin >> newProduct.quantity;

    products.push_back(newProduct);
    cout << "Product added successfully!\n";
}

// Function to display all products
void displayProducts() {
    if (products.empty()) {
        cout << "\nNo products available.\n";
        return;
    }

    float grandTotal = 0; // To calculate the grand total price of all products

    cout << "\n========== Product List ==========\n";
    cout << setw(10) << left << "ID"
         << setw(20) << left << "Name"
         << setw(10) << left << "Price"
         << setw(10) << left << "Quantity"
         << setw(15) << left << "Total Price" << "\n";

    for (const auto& product : products) {
        float total = product.totalPrice();
        grandTotal += total;

        cout << setw(10) << left << product.id
             << setw(20) << left << product.name
             << setw(10) << left << product.price
             << setw(10) << left << product.quantity
             << setw(15) << left << total << "\n";
    }

    // Display the grand total
    cout << "\n========== Grand Total Price: $" << grandTotal << " ==========\n";
}

// Function to update a product
void updateProduct() {
    if (products.empty()) {
        cout << "\nNo products available to update.\n";
        return;
    }

    int id;
    cout << "\nEnter the Product ID to update: ";
    cin >> id;

    for (auto& product : products) {
        if (product.id == id) {
            cout << "Enter new name (or press Enter to skip): ";
            cin.ignore();
            string newName;
            getline(cin, newName);
            if (!newName.empty()) product.name = newName;

            cout << "Enter new price (or -1 to skip): ";
            float newPrice;
            cin >> newPrice;
            if (newPrice != -1) product.price = newPrice;

            cout << "Enter new quantity (or -1 to skip): ";
            int newQuantity;
            cin >> newQuantity;
            if (newQuantity != -1) product.quantity = newQuantity;

            cout << "Product updated successfully!\n";
            return;
        }
    }

    cout << "Product with ID " << id << " not found.\n";
}

// Function to delete a product
void deleteProduct() {
    if (products.empty()) {
        cout << "\nNo products available to delete.\n";
        return;
    }

    int id;
    cout << "\nEnter the Product ID to delete: ";
    cin >> id;

    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->id == id) {
            products.erase(it);
            cout << "Product deleted successfully!\n";
            return;
        }
    }

    cout << "Product with ID " << id << " not found.\n";
}

#include <iostream>
#include <iomanip>

const int NUM_SALESPERSONS = 4;
const int NUM_PRODUCTS = 5;

int main() {
    //two-dimensional array for sales
    double sales[NUM_PRODUCTS][NUM_SALESPERSONS] = {0.0};

    //sales data for last week- input
    for (int i = 0; i < NUM_SALESPERSONS; ++i) {
        for (int j = 0; j < NUM_PRODUCTS; ++j) {
            int salesperson, product;
            double salesAmount;

            std::cout << "Enter sales data for Salesperson " << i + 1 << ", Product " << j + 1 << ":\n";
            
            std::cout << "Salesperson (1 to 4): ";
            std::cin >> salesperson;

            //check input for salesperson
            while (salesperson < 1 || salesperson > NUM_SALESPERSONS) {
                std::cout << "Invalid input. Salesperson must be between 1 and " << NUM_SALESPERSONS << ". Try again: ";
                std::cin >> salesperson;
            }

            std::cout << "Product (1 to 5): ";
            std::cin >> product;

            // check input for product
            while (product < 1 || product > NUM_PRODUCTS) {
                std::cout << "Invalid input. Product must be between 1 and " << NUM_PRODUCTS << ". Try again: ";
                std::cin >> product;
            }

            std::cout << "Sales Amount: $";
            std::cin >> salesAmount;

            //update the sales array
            sales[product - 1][salesperson - 1] += salesAmount;
        }
    }

    //tabular format with totals
    std::cout << std::setw(10) << "Product";
    for (int i = 1; i <= NUM_SALESPERSONS; ++i) {
        std::cout << std::setw(15) << "Salesperson " << i;
    }
    std::cout << std::setw(15) << "Total" << std::endl;

    for (int i = 0; i < NUM_PRODUCTS; ++i) {
        std::cout << std::setw(10) << i + 1;

        double rowTotal = 0.0;
        for (int j = 0; j < NUM_SALESPERSONS; ++j) {
            std::cout << std::setw(15) << std::fixed << std::setprecision(2) << sales[i][j];
            rowTotal += sales[i][j];
        }

        // total for each product
        std::cout << std::setw(15) << std::fixed << std::setprecision(2) << rowTotal << std::endl;
    }

    // total for each salesperson
    std::cout << std::setw(10) << "Total";
    for (int i = 0; i < NUM_SALESPERSONS; ++i) {
        double colTotal = 0.0;
        for (int j = 0; j < NUM_PRODUCTS; ++j) {
            colTotal += sales[j][i];
        }

        std::cout << std::setw(15) << std::fixed << std::setprecision(2) << colTotal;
    }

    std::cout << std::endl;

    return 0;
}

#include "MainMenu.h"
#include "TicketPurch.h"
void cinemaBook() {
    ascii();
        const double ADULT_PRICE = 12.0;
        const double CHILD_PRICE = 8.0;
        int adultCount = 0, childCount = 0;
        double totalPrice = 0.0;

        while (true) {
            std::cout << std::setw(40) << "" << "Select the category of the ticket:" << std::endl;
            std::cout << std::endl;
            std::cout << std::setw(40) << "" << "1. Adult - $" << ADULT_PRICE << std::endl;
            std::cout << std::setw(40) << "" << "2. Child - $" << CHILD_PRICE << std::endl;
            std::cout << std::setw(40) << "" << "3. Finish and calculate total" << std::endl;

            int choice;
            std::cin >> choice;

            if (choice == 3) break;

            if (choice != 1 && choice != 2) {
                std::cout << std::setw(40) << "" << "\033[1;31mInvalid choice. Please try again.\033[0m" << std::endl;
                continue;
            }
            system("CLS");
            std::cout << std::setw(40) << "" << "Enter the number of tickets: ";
            int count;
            std::cin >> count;

            if (count < 0) {
                std::cout << std::setw(40) << "" << "\033[1;31mInvalid number. Please enter a non-negative number.\033[0m" << std::endl;
                continue;
            }

            if (choice == 1) {
                adultCount += count;
                totalPrice += count * ADULT_PRICE;
            }
            else {
                childCount += count;
                totalPrice += count * CHILD_PRICE;
            }
        }

        std::cout << std::endl;
        std::cout << std::setw(40) << "" << "Booking Summary" << std::endl;
        cout << endl;
        std::cout << std::setw(40) << "" << "Adults: " << adultCount << " x $" << ADULT_PRICE << " = $" << (adultCount * ADULT_PRICE) << std::endl;
        std::cout << std::setw(40) << "" << "Children: " << childCount << " x $" << CHILD_PRICE << " = $" << (childCount * CHILD_PRICE) << std::endl;
        std::cout << std::setw(40) << "" << "Total Price: $" << totalPrice << std::endl;
    }
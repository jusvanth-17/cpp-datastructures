
#include <iostream>
#include <vector>
#include <string>

class Car {
public:
    Car(const std::string& make, const std::string& model, int year, double dailyRate)
        : make(make), model(model), year(year), dailyRate(dailyRate), rented(false) {}

    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
    double getDailyRate() const { return dailyRate; }
    bool isRented() const { return rented; }

    void rentCar() { rented = true; }
    void returnCar() { rented = false; }

private:
    std::string make;
    std::string model;
    int year;
    double dailyRate;
    bool rented;
};

class Customer {
public:
    Customer(const std::string& name) : name(name) {}

    std::string getName() const { return name; }
    int getRentedCarIndex() const { return rentedCarIndex; }

    void rentCar(int carIndex) { rentedCarIndex = carIndex; }
    void returnCar() { rentedCarIndex = -1; }

private:
    std::string name;
    int rentedCarIndex = -1;  // Index of the rented car in the car list (-1 if not rented)
};

class CarRentalSystem {
public:
    void addCar(const Car& car) { cars.push_back(car); }
    void addCustomer(const Customer& customer) { customers.push_back(customer); }

    void displayCars() const {
        std::cout << "Available Cars:\n";
        for (size_t i = 0; i < cars.size(); ++i) {
            if (!cars[i].isRented()) {
                std::cout << i + 1 << ". " << cars[i].getMake() << " " << cars[i].getModel()
                          << " (" << cars[i].getYear() << "), Daily Rate: $" << cars[i].getDailyRate() << "\n";
            }
        }
    }

    void rentCarToCustomer(int carIndex, int customerIndex) {
        if (carIndex >= 0 && carIndex < cars.size() && customerIndex >= 0 && customerIndex < customers.size()) {
            if (!cars[carIndex].isRented() && customers[customerIndex].getRentedCarIndex() == -1) {
                cars[carIndex].rentCar();
                customers[customerIndex].rentCar(carIndex);
                std::cout << "Car rented successfully.\n";
            } else {
                std::cout << "Car is not available for rent or customer already has a rented car.\n";
            }
        } else {
            std::cout << "Invalid car or customer index.\n";
        }
    }

    void returnCarFromCustomer(int customerIndex) {
        if (customerIndex >= 0 && customerIndex < customers.size()) {
            int rentedCarIndex = customers[customerIndex].getRentedCarIndex();
            if (rentedCarIndex != -1) {
                cars[rentedCarIndex].returnCar();
                customers[customerIndex].returnCar();
                std::cout << "Car returned successfully.\n";
            } else {
                std::cout << "Customer has no rented car.\n";
            }
        } else {
            std::cout << "Invalid customer index.\n";
        }
    }

private:
    std::vector<Car> cars;
    std::vector<Customer> customers;
};

int main() {
    CarRentalSystem rentalSystem;

    rentalSystem.addCar(Car("Toyota", "Camry", 2022, 50.0));
    rentalSystem.addCar(Car("Honda", "Civic", 2021, 45.0));
    rentalSystem.addCar(Car("Ford", "Fusion", 2023, 55.0));

    rentalSystem.addCustomer(Customer("John Doe"));
    rentalSystem.addCustomer(Customer("Jane Smith"));

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Available Cars\n";
        std::cout << "2. Rent a Car\n";
        std::cout << "3. Return a Car\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                rentalSystem.displayCars();
                break;
            case 2: {
                int carIndex, customerIndex;
                std::cout << "Enter car index and customer index to rent the car: ";
                std::cin >> carIndex >> customerIndex;
                rentalSystem.rentCarToCustomer(carIndex - 1, customerIndex - 1);
                break;
            }
            case 3: {
                int customerIndex;
                std::cout << "Enter customer index to return the car: ";
                std::cin >> customerIndex;
                rentalSystem.returnCarFromCustomer(customerIndex - 1);
                break;
            }
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

#include <iostream>
#include <string>

class Car {
private:
    std::string model;
    int kilometers; // Numărul de kilometri parcurși

public:
    // Constructor
    Car(const std::string& model = "Necunoscut", int kilometers = 0)
        : model(model), kilometers(kilometers) {}

    // Copy Constructor (Item 12: Copy all parts of an object)
    Car(const Car& other)
        : model(other.model), kilometers(other.kilometers) {
        std::cout << "Copy constructor apelat pentru \"" << model << "\".\n";
    }

    // Copy Assignment Operator (Item 10, 11)
    Car& operator=(const Car& other) {
        if (this == &other) { // Handle self-assignment (Item 11)
            return *this;
        }

        // Copierea membrilor
        model = other.model;
        kilometers = other.kilometers;

        std::cout << "Operator= de copiere apelat pentru \"" << model << "\".\n";
        return *this; // Return a reference to *this (Item 10)
    }

    // Move Constructor
    Car(Car&& other) noexcept
        : model(std::move(other.model)), kilometers(other.kilometers) {
        other.kilometers = 0; // Resetăm sursa
        std::cout << "Move constructor apelat pentru \"" << model << "\".\n";
    }

    // Move Assignment Operator
    Car& operator=(Car&& other) noexcept {
        if (this == &other) { // Handle self-assignment (Item 11)
            return *this;
        }

        // Mutăm membrii
        model = std::move(other.model);
        kilometers = other.kilometers;
        other.kilometers = 0;

        std::cout << "Operator= de mutare apelat pentru \"" << model << "\".\n";
        return *this; // Return a reference to *this (Item 10)
    }

    // Destructor
    ~Car() {
        std::cout << "Destructor apelat pentru \"" << model << "\".\n";
    }

    // Funcție de afișare
    void display() const {
        std::cout << "Mașina \"" << model << "\" a parcurs " << kilometers << " kilometri.\n";
    }
};

int main() {
    Car c1("Dacia", 50000);
    Car c2("BMW", 120000);

    c1.display();
    c2.display();

    // Testare operator= (copiere)
    c2 = c1;
    c2.display();

    // Testare constructor de copiere
    Car c3 = c1;
    c3.display();

    // Testare mutare
    Car c4 = std::move(c3);
    c4.display();

    // Testare operator= (mutare)
    c4 = std::move(c2);
    c4.display();

    return 0;
}

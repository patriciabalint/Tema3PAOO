#include <iostream>
#include <string>

// Item 10: Operatorii de atribuire trebuie să returneze o referință la *this.
// Item 11: Gestionează atribuirea unui obiect către el însuși în operator= (self-assignment).
// Item 12: Copiază toate părțile unui obiect în operator= (deep copy), inclusiv în constructorul de copiere.

class Car {
    std::string model; // Modelul mașinii
    int kilometers; // Numărul de kilometri parcurși

public:
    // Constructor implicit
    Car(const std::string& initialModel = "", int initialKilometers = 0)
        : model(initialModel), kilometers(initialKilometers) {}

    // Constructor de copiere
    Car(const Car& other)
        : model(other.model), kilometers(other.kilometers) { // Copiem modelul și kilometrii (Item 12)
        std::cout << "Constructor de copiere apelat pentru '" << model << "'.\n";
    }

    // Operator de atribuire
    Car& operator=(const Car& other) {
        // Item 11: Verificare auto-atribuire
        if (this == &other) {
            return *this; // Întoarcem *this pentru auto-atribuire
        }

        // Item 12: Copiem toate părțile obiectului
        model = other.model; // Copiem modelul
        kilometers = other.kilometers; // Copiem kilometrii

        std::cout << "Operator= de copiere apelat pentru '" << model << "'.\n";

        // Item 10: Returnăm referința la obiectul curent
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Destructor apelat pentru '" << model << "'.\n";
    }

    // Funcție pentru afișare
    void display() const {
        std::cout << "Model: " << model << ", Kilometri: " << kilometers << "\n";
    }
};

int main() {
    // Creăm un obiect Car
    Car c1("BMW", 50000);
    c1.display();

    // Copiem un obiect Car folosind constructorul de copiere
    Car c2 = c1; // Apel constructor de copiere (Item 12)
    c2.display();

    // Creăm un alt obiect Car
    Car c3("Audi", 80000);
    c3.display();

    // Folosim operatorul de atribuire
    c3 = c1; // Apel operator= (Item 10, Item 11, Item 12)
    c3.display();

    // Testăm auto-atribuirea
    c1 = c1; // Apel operator= pentru auto-atribuire (Item 11)

    return 0;
}

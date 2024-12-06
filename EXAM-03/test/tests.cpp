#include "catch.hpp"

#include "vehicle.hpp"
#include <sstream>

// 1. Test de l'héritage
TEST_CASE("Test de l'héritage de base") {
    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    car.displayInfo();
    truck.displayInfo();

    REQUIRE(car.name == "Tesla");
    REQUIRE(truck.name == "Ford");
}


// 2. Test de la surcharge de méthode
TEST_CASE("Test de la surcharge de displayInfo") {
    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    REQUIRE(car.maxSpeed == 250);
    REQUIRE(truck.maxSpeed == 180);
}


// 3. Test de l'héritage multiple
TEST_CASE("Test de l'héritage multiple (Vehicle + Fuel)") {
    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    REQUIRE(car.getFuelLevel() == 100);
    REQUIRE(truck.getFuelLevel() == 200);
}


// 4. Test de l'appel à une méthode spécifique de l'interface Fuel
TEST_CASE("Test des méthodes de Fuel") {
    Car car("Tesla", 250, 100);
    car.consume(20);
    REQUIRE(car.getFuelLevel() == 80);
    car.refuel(50);
    REQUIRE(car.getFuelLevel() == 130);
}


// 5. Test de l'opérateur de mouvement (move)
TEST_CASE("Test de l'opérateur de mouvement") {
    Car car("Tesla", 250, 100);
    Car car2 = std::move(car);

    REQUIRE(car.getFuelLevel() == 0);  // Après mouvement, `car` ne doit plus avoir de carburant
    REQUIRE(car2.getFuelLevel() == 100);  // Le carburant est transféré à `car2`
}


// 6. Test de la spécialisation de template pour véhicules électriques
TEST_CASE("Test de la spécialisation du Garage pour véhicules électriques") {
    Car electricCar("Tesla Model 3", 220, 0); // Véhicule électrique avec 0 carburant
    Truck electricTruck("Electric Truck", 150, 0); // Même pour un camion électrique

    Garage<Car> electricGarage;
    electricGarage.addVehicle(electricCar);
    electricGarage.addVehicle(electricTruck);

    electricGarage.display();
}


// 7. Test de l'introspection avec `typeid`
TEST_CASE("Test de l'introspection") {
    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    introspect(car);   // Devrait afficher "Car"
    introspect(truck); // Devrait afficher "Truck"
}


// 8. Test de la redéfinition de l'opérateur `==`
TEST_CASE("Test de la redéfinition de l'opérateur `==` pour les véhicules") {
    Car car1("Tesla", 250, 100);
    Car car2("Tesla", 250, 100);
    Car car3("Ford", 200, 150);

    REQUIRE(car1 == car2);  // Deux véhicules avec les mêmes caractéristiques doivent être égaux
    REQUIRE(car1 != car3);  // Deux véhicules différents doivent être inégaux
}



// 9. Test de la comparaison de véhicules (égalité et inégalité)
TEST_CASE("Test de la comparaison des véhicules (==)") {
    Car car1("Tesla", 250, 100);
    Car car2("Tesla", 250, 100);
    Car car3("Ford", 200, 150);

    REQUIRE(car1 == car2);
    REQUIRE(car1 != car3);
}


// 10. Test d'un foncteur pour vérifier la vitesse d’un véhicule
TEST_CASE("Test d'un foncteur pour vérifier la vitesse d'un véhicule") {
    auto checkSpeed = [](const Vehicle& v) { return v.maxSpeed < 200; };

    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    REQUIRE(checkSpeed(car) == false);
    REQUIRE(checkSpeed(truck) == true);
}

// 11. Test d'un foncteur pour valider la consommation d'essence
TEST_CASE("Test d'un foncteur pour valider la consommation d'essence") {
    auto checkFuel = [](const Fuel& f) { return f.getFuelLevel() > 50; };

    Car car("Tesla", 250, 100);
    Truck truck("Ford", 180, 200);

    REQUIRE(checkFuel(car) == true);
    REQUIRE(checkFuel(truck) == true);
}


// 12. Test de la surcharge de l'opérateur `<<`
TEST_CASE("Test de la surcharge de l'opérateur `<<`") {
    Car car("Tesla", 250, 100);
    std::ostringstream oss;
    oss << car;

    REQUIRE(oss.str() == "Vehicle Name: Tesla\nMax Speed: 250 km/h\nFuel Level: 100 L\n");
}


// 14. Test du mouvement d’un véhicule avec un opérateur de déplacement correct
TEST_CASE("Test du mouvement d’un véhicule avec opérateur de déplacement") {
    Car car("Tesla", 250, 100);
    Car car2 = std::move(car);

    REQUIRE(car.getFuelLevel() == 0);  // Après mouvement, `car` doit avoir une quantité de carburant nulle
    REQUIRE(car2.getFuelLevel() == 100);  // `car2` doit avoir récupéré la quantité de carburant
}

// 15. Test de l'affectation d'un véhicule à partir d'un autre (sans copie, avec référence)
TEST_CASE("Test de l'affectation d'un véhicule par référence") {
    Car car("Tesla", 250, 100);
    Car& carRef = car;
    REQUIRE(&car == &carRef);  // Les deux doivent pointer vers le même objet
}

// 16. Test d'un véhicule avec une quantité de carburant égale à zéro
TEST_CASE("Test d'un véhicule avec carburant à zéro") {
    Car car("Tesla", 250, 0);
    REQUIRE(car.getFuelLevel() == 0);
}
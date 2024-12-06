#include "catch.hpp"

#include "machine.hpp"
#include "peripheral.hpp"

#include <sstream>


// TESTS

// 1. Test de l'ajout et de l'affichage d'une machine
TEST_CASE("Test de la machine") {
    Machine m("PC", 8000, 50);
    std::ostringstream oss;
    oss << m << std::endl;
    REQUIRE(m.getName() == "PC");
    REQUIRE(m.getMemoryUsage() == 8000);
    REQUIRE(m.getCpuUsage() == 50);
}

// 2. Test de l'ajout et de la recherche de périphériques dans un multiset
TEST_CASE("Test d'ajout et de recherche dans multiset") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");
    Peripheral<std::string> printer3("Laser Printer", "On");

    system.addPeripheral(printer1);
    system.addPeripheral(printer2);
    system.addPeripheral(printer3);

    REQUIRE(system.searchPeripheral("Laser Printer") == true);
    REQUIRE(system.searchPeripheral("Inkjet Printer") == true);
    REQUIRE(system.searchPeripheral("Non Existent Printer") == false);
}

// Test concept
TEST_CASE("Test de la contrainte de concept pour le statut du périphérique") {
    // Périphérique avec un statut de type std::string
    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");

    // Utilisation du concept pour vérifier que le statut est bien un std::string
    REQUIRE_NOTHROW(checkStatusType(printer1)); // Devrait passer, car le statut est un std::string
    REQUIRE_NOTHROW(checkStatusType(printer2)); // Devrait passer aussi

    // Si nous tentons d'utiliser un périphérique avec un statut d'un autre type, ça échouera
    Peripheral<int> ssd("Samsung SSD", 500);  // Statut de type int

    // Concept 'HasStringStatus' doit échouer pour ce cas, car le statut est un int
    REQUIRE_THROWS_AS(checkStatusType(ssd), std::exception);  // Devrait échouer car 'status' n'est pas un std::string
}



// 3. Test de recherche et de manipulation avec foncteur
TEST_CASE("Test de recherche et foncteur de statut de périphérique") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");

    system.addPeripheral(printer1);
    system.addPeripheral(printer2);

    CheckPeripheralStatus<std::string> checkStatus;

    REQUIRE(checkStatus(printer1) == true);   // Laser Printer est "On"
    REQUIRE(checkStatus(printer2) == false);  // Inkjet Printer est "Off"
}


// 4. Test de l'opérateur de mouvement pour un périphérique
TEST_CASE("Test de l'opérateur de mouvement pour périphérique") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2 = std::move(printer1);

    system.addPeripheral(std::move(printer2));
    REQUIRE(system.searchPeripheral("Laser Printer") == true);
}

/*
// 5. Test d'utilisation de multiset avec SSD (périphérique avec données numériques)
TEST_CASE("Test d'utilisation de multiset avec SSD") {
    System<Peripheral<int>> storageSystem;

    Peripheral<int> ssd1("Samsung SSD", 500);
    Peripheral<int> ssd2("Crucial SSD", 1000);

    storageSystem.addPeripheral(ssd1);
    storageSystem.addPeripheral(ssd2);

    std::ostringstream oss;
    storageSystem.displayAll();

    REQUIRE(storageSystem.searchPeripheral("Samsung SSD") == true);
    REQUIRE(storageSystem.searchPeripheral("Crucial SSD") == true);
}

// 6. Test d'ajout de périphériques dans un multiset générique
TEST_CASE("Test de l'ajout et de l'affichage dans multiset générique") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");
    system.addPeripheral(printer1);
    system.addPeripheral(printer2);

    std::ostringstream oss;
    system.displayAll();

    REQUIRE(system.searchPeripheral("Laser Printer") == true);
    REQUIRE(system.searchPeripheral("Inkjet Printer") == true);
}
*/

// 7. Test de recherche dans multiset avec contraintes
TEST_CASE("Test de recherche dans multiset avec contraintes") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");

    system.addPeripheral(printer1);
    system.addPeripheral(printer2);

    // Recherche du périphérique "Laser Printer"
    bool found = system.searchPeripheral("Laser Printer");
    REQUIRE(found == true);

    // Recherche d'un périphérique inexistant
    found = system.searchPeripheral("Dot Matrix Printer");
    REQUIRE(found == false);
}
/*
// 8. Test de l'affichage et manipulation des périphériques dans un multiset
TEST_CASE("Test d'affichage et manipulation dans multiset") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");
    Peripheral<std::string> printer3("Laser Printer", "On");

    system.addPeripheral(printer1);
    system.addPeripheral(printer2);
    system.addPeripheral(printer3);

    // Test affichage des périphériques
    std::ostringstream oss;
    system.displayAll(); // Tous les périphériques ajoutés sont affichés

    // Test de suppression et recherche
    system.addPeripheral(printer2); // Ajout de l'imprimante Inkjet Printer
    REQUIRE(system.searchPeripheral("Inkjet Printer") == true);
}

// 9. Test d'un foncteur pour la vérification de périphérique
TEST_CASE("Test d'un foncteur pour vérifier un périphérique") {
    System<Peripheral<std::string>> system;

    Peripheral<std::string> printer1("Laser Printer", "On");
    Peripheral<std::string> printer2("Inkjet Printer", "Off");
    system.addPeripheral(printer1);
    system.addPeripheral(printer2);

    CheckPeripheralStatus<std::string> check;
    REQUIRE(check(printer1) == true);  // "Laser Printer" est "On"
    REQUIRE(check(printer2) == false); // "Inkjet Printer" est "Off"
}
*/
#include "catch.hpp"
#include "product.hpp"
#include "order.hpp"
#include "inventory.hpp"

TEST_CASE("Inventory management", "[inventory]") {

    // 1. Test d'ajout de produit avec une seule catégorie
    SECTION("Adding product with a single category") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        REQUIRE(apple.name == "Apple");
        REQUIRE(apple.price == 1.0);
        REQUIRE(apple.quantity == 10);
    }

    // 2. Test d'ajout de produit avec plusieurs catégories
    SECTION("Adding product with multiple categories") {
        Product<std::string, std::string> apple("Apple", 1.0, 10, "Fruit", "Organic");
        REQUIRE(apple.name == "Apple");
        apple.printCategories();
    }
    
    // 3. Test d'addition d'un produit à un magasin
    SECTION("Add product to store") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        REQUIRE(store.products.count("Apple") == 1);
    }

    
    // 4. Test de retrait d'un produit d'un magasin
    SECTION("Remove product from store") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        store.removeProduct("Apple", 5);
        REQUIRE(store.products["Apple"].quantity == 5);
    }

    
    // 5. Test d'ajout d'un produit avec quantité nulle
    SECTION("Adding product with zero quantity") {
        Product<std::string> apple("Apple", 1.0, 0, "Fruit");
        REQUIRE(apple.quantity == 0);
    }


    // 6. Test de création d'une commande avec un produit
    SECTION("Create order with one product") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Order<Product<std::string>> order(1, apple);
        REQUIRE(order.orderId == 1);
        order.printProducts();
    }

    // 7. Test d'ajout de produit avec un prix ajusté
    SECTION("Product with adjusted price") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        apple.price *= 0.9;  // Apply 10% discount
        REQUIRE(apple.price == Approx(0.9).epsilon(0.01));
    }

    
    // 8. Test d'ajout de produit avec des prix différents dans plusieurs magasins
    SECTION("Product with different prices in multiple stores") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store1("Store1");
        Store<Product<std::string>> store2("Store2");

        store1.addProduct(apple);
        apple.price = 1.2; // Price change in store2
        store2.addProduct(apple);

        REQUIRE(store1.products["Apple"].price == 1.0);
        REQUIRE(store2.products["Apple"].price == 1.2);
    }

    
    // 9. Test de retrait d'un produit avec quantité insuffisante
    SECTION("Remove product with insufficient quantity") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        REQUIRE_FALSE(store.removeProduct("Apple", 15));  // Not enough stock
    }

    
    // 10. Test de création d'une commande avec plusieurs produits
    SECTION("Create order with multiple products") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Product<std::string> banana("Banana", 0.5, 20, "Fruit");
        Order<Product<std::string>, Product<std::string>> order(1, apple, banana);
        order.printProducts();
        REQUIRE(order.orderId == 1);
    }

    
    // 11. Test de création d'une commande avec produits de catégories multiples
    SECTION("Order with products from multiple categories") {
        Product<std::string, std::string> apple("Apple", 1.0, 10, "Fruit", "Organic");
        Product<std::string, std::string> banana("Banana", 0.5, 20, "Fruit", "Tropical");
        Order<Product<std::string, std::string>, Product<std::string, std::string>> order(1, apple, banana);
        order.printProducts();
        REQUIRE(order.orderId == 1);
    }

    
    // 12. Test de gestion de l'inventaire avec des produits et des magasins différents
    SECTION("Store management with different products and stores") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Product<std::string> banana("Banana", 0.5, 20, "Fruit");
        Store<Product<std::string>> store1("Store1");
        Store<Product<std::string>> store2("Store2");

        store1.addProduct(apple);
        store2.addProduct(banana);

        REQUIRE(store1.products.count("Apple") == 1);
        REQUIRE(store2.products.count("Banana") == 1);
    }

    
    // 13. Test de gestion d'un produit dans plusieurs magasins
    SECTION("Product in multiple stores") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store1("Store1");
        Store<Product<std::string>> store2("Store2");

        store1.addProduct(apple);
        store2.addProduct(apple);

        REQUIRE(store1.products["Apple"].quantity == 10);
        REQUIRE(store2.products["Apple"].quantity == 10);
    }

    // 14. Test de suppression de produit d'un magasin
    SECTION("Remove product from multiple stores") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store1("Store1");
        Store<Product<std::string>> store2("Store2");

        store1.addProduct(apple);
        store2.addProduct(apple);
        store1.removeProduct("Apple", 5);
        store2.removeProduct("Apple", 5);

        REQUIRE(store1.products["Apple"].quantity == 5);
        REQUIRE(store2.products["Apple"].quantity == 5);
    }

    
    // 15. Test de gestion de stock d'un produit avec quantité dynamique
    SECTION("Dynamic stock management") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        store.removeProduct("Apple", 3);
        store.addProduct(apple);
        REQUIRE(store.products["Apple"].quantity == 17);
    }

    // 16. Test de gestion des stocks lorsque le produit est retiré d'un magasin
    SECTION("Remove product from store with sufficient stock") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        store.removeProduct("Apple", 10);
        REQUIRE(store.products["Apple"].quantity == 0);
    }

    // 17. Test de gestion des produits avec des catégories multiples
    SECTION("Product with multiple categories handling") {
        Product<std::string, std::string, std::string> apple("Apple", 1.0, 10, "Fruit", "Organic", "Seasonal");
        apple.printCategories();
        REQUIRE(apple.name == "Apple");
    }
    
    // 18. Test de gestion des produits avec un prix dynamique
    /* SECTION("Product with dynamic pricing based on conditions") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        apple.price = apple.price * 0.85;  // Apply discount
        REQUIRE(apple.price == Approx(0.85).epsilon(0.01));
    }

    
    // 19. Test d'intégrité des données : vérifier un prix invalide
    SECTION("Invalid product price should throw exception") {
        Product<std::string> apple("Apple", -1.0, 10, "Fruit");
        REQUIRE_THROWS_AS(apple.price, std::invalid_argument);
    }

    
    // 20. Test d'intégrité des données : vérifier une quantité invalide
    SECTION("Invalid product quantity should throw exception") {
        Product<std::string> apple("Apple", 1.0, -10, "Fruit");
        REQUIRE_THROWS_AS(apple.quantity, std::invalid_argument);
    } */

    // 21. Test d'ajout d'un produit avec une quantité insuffisante dans une commande
    SECTION("Add product to order with insufficient stock") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Order<Product<std::string>> order(1, apple);
        REQUIRE_FALSE(order.addProduct(apple, 15));  // Not enough stock
    }
    
    // 22. Test de création d'une commande avec des produits d'une catégorie spécifique
    SECTION("Create order with products of a specific category") {
        Product<std::string, std::string> apple("Apple", 1.0, 10, "Fruit", "Organic");
        Product<std::string, std::string> banana("Banana", 0.5, 20, "Fruit", "Tropical");
        Order<Product<std::string, std::string>, Product<std::string, std::string>> order(1, apple, banana);
        order.printProducts();
        REQUIRE(order.orderId == 1);
    }

    
    // 23. Test de création de plusieurs commandes avec des produits et vérification de leur statut
    SECTION("Multiple orders with different statuses") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Order<Product<std::string>> order1(1, apple);
        order1.confirmOrder();
        Order<Product<std::string>> order2(2, apple);
        order2.cancelOrder();
        REQUIRE(order1.status == "shipped");
        REQUIRE(order2.status == "canceled");
    }

    
    // 24. Test de création d'une commande avec une quantité de produit dépassant le stock
    SECTION("Order with quantity exceeding stock") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Order<Product<std::string>> order(1, apple);
        REQUIRE_FALSE(order.addProduct(apple, 15));  // Not enough stock
    }

    // 25. Test de gestion d'un produit avec plusieurs types de catégories
    SECTION("Product with multiple category types") {
        Product<std::string, std::string, std::string> apple("Apple", 1.0, 10, "Fruit", "Organic", "Seasonal");
        apple.printCategories();
        REQUIRE(apple.name == "Apple");
    }

    // 26. Test de gestion d'un produit avec un prix spécial en fonction de l'offre
    SECTION("Product with special offer") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        apple.price = apple.price * 0.8;  // Apply 20% offer
        REQUIRE(apple.price == Approx(0.8).epsilon(0.01));
    }

    // 27. Test de modification du prix d'un produit après ajout à l'inventaire
    SECTION("Price modification after product is added to store") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store("Store1");
        store.addProduct(apple);
        apple.price = 1.2; // Change price
        REQUIRE(store.products["Apple"].price == 1.0);
    }

    // 28. Test de gestion d'un produit dans un magasin avec des quantités variables
    SECTION("Product with variable quantities in different stores") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Store<Product<std::string>> store1("Store1");
        Store<Product<std::string>> store2("Store2");
        store1.addProduct(apple);
        apple.quantity = 5;
        store2.addProduct(apple);
        REQUIRE(store1.products["Apple"].quantity == 10);
        REQUIRE(store2.products["Apple"].quantity == 5);
    }

    // 29. Test de la création d'une commande avec plusieurs produits ayant différents prix
    SECTION("Create order with multiple products having different prices") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        Product<std::string> banana("Banana", 0.5, 20, "Fruit");
        Order<Product<std::string>, Product<std::string>> order(1, apple, banana);
        order.printProducts();
        REQUIRE(order.orderId == 1);
    }

    // 30. Test de l'intégrité des données de produit avec gestion des erreurs
    /*SECTION("Product data integrity check") {
        Product<std::string> apple("Apple", 1.0, 10, "Fruit");
        REQUIRE_THROWS_AS(apple.price = -1.0, std::invalid_argument);
        REQUIRE_THROWS_AS(apple.quantity = -10, std::invalid_argument);
    }*/
}

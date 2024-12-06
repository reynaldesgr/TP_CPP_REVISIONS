cmake_minimum_required(VERSION 3.10)
project(exam)

set(CMAKE_CXX_STANDARD 17)

# Inclure les répertoires source et de test
include_directories(src)
include_directories(test)  # Inclut test/ où se trouvent catch.hpp et catch.cpp

# Ajouter les fichiers source pour l'exécutable
add_executable(exam src/inventory.cpp src/product.cpp src/order.cpp test/tests.cpp test/catch.cpp)

# Activer les tests
enable_testing()
add_test(NAME testexam COMMAND exam)

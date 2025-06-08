#include <iostream>
#include "functions/functions.h"
#include <fstream>
#include <chrono>

int main() {
    bool print_flag = false;

    std::ifstream inputFile("samples.txt");
    if (!inputFile) {
        std::cerr << "Unable to open samples file" << std::endl;
        return 1;
    }

    double a, b, c;
    const auto start = std::chrono::high_resolution_clock::now();
    while (inputFile >> a >> b >> c) {
        if (print_flag) std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        const double discriminant = calculateDiscriminant(a, b, c);
        double root1;

        if (discriminant > 0) {
            double root2;
            calculateRoot1(a, b, discriminant, root1);
            calculateRoot2(a, b, discriminant, root2);
            if (print_flag) std::cout << root1 << "   " << root2 << std::endl;
        } else if (discriminant == 0) {
            calculateRoot1(a, b, discriminant, root1);
            if (print_flag) std::cout << root1 << std::endl;
        } else {
            if (print_flag) std::cout << "The equation has no real roots" << std::endl;
        }
    }

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> duration = end - start;
    std::cout << "Foreign: " << duration.count() << std::endl;

    inputFile.close();
    return 0;
}
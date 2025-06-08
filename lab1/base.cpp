#include <iostream>
#include <cmath>
#include <fstream>
#include <chrono>

double calculateDiscriminant(const double a, const double b, const double c) {
    return b * b - 4 * a * c;
}

void calculateRoot1(const double a, const double b, const double discriminant, double& root1) {
    if (discriminant >= 0) {
        root1 = (-b + std::sqrt(discriminant)) / (2 * a);
    }
}

void calculateRoot2(const double a, const double b, const double discriminant, double& root2) {
    if (discriminant >= 0) {
        root2 = (-b - std::sqrt(discriminant)) / (2 * a);
    }
}

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
    std::cout << "Base:    " << duration.count() << std::endl;

    inputFile.close();
    return 0;
}

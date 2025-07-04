#include <iostream>
#include <cmath>
#include <random>
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

int main(int argc, char* argv[]) {
    const bool print_flag = false;

    const std::string optimization_level = (argc > 1) ? argv[1] : "Unknown";

    // Random number generator setup
    const int LEFT = -10;
    const int RIGHT = 10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(LEFT, RIGHT);

    const int CNT = 100000000;
    const auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < CNT; ++i) {
        const double a = 1;
        const double b = dis(gen);
        const double c = 1;

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
    std::cout << optimization_level << ": " << duration.count() << std::endl;

    return 0;
}

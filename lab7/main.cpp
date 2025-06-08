#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

double computeDiscriminant(const double coeff_a, const double coeff_b, const double coeff_c) {
    return coeff_b * coeff_b - 4 * coeff_a * coeff_c;
}

void computeFirstRoot(const double coeff_a, const double coeff_b, const double discr, double& result1) {
    if (discr >= 0) {
        result1 = (-coeff_b + std::sqrt(discr)) / (2 * coeff_a);
    }
}

void computeSecondRoot(const double coeff_a, const double coeff_b, const double discr, double& result2) {
    if (discr >= 0) {
        result2 = (-coeff_b - std::sqrt(discr)) / (2 * coeff_a);
    }
}

int main(int argc, char* argv[]) {
    bool should_print = false;

    std::string opt_level = (argc > 1) ? argv[1] : "Undefined";

    // Инициализация генератора случайных чисел
    int RANGE_MIN = -100;
    int RANGE_MAX = 100;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_real_distribution<> distribution(RANGE_MIN, RANGE_MAX);

    int ITERATIONS = 100000000;
    const auto time_start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < ITERATIONS; ++i) {
        double a = distribution(generator);
        double b = distribution(generator);
        double c = distribution(generator);

        if (should_print) std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
        const double discr = computeDiscriminant(a, b, c);
        double root1;

        if (discr > 0) {
            double root2;
            computeFirstRoot(a, b, discr, root1);
            computeSecondRoot(a, b, discr, root2);
            if (should_print) std::cout << root1 << "   " << root2 << std::endl;
        } else if (discr == 0) {
            computeFirstRoot(a, b, discr, root1);
            if (should_print) std::cout << root1 << std::endl;
        } else {
            if (should_print) std::cout << "No real roots" << std::endl;
        }
    }

    const auto time_end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsed = time_end - time_start;
    std::cout << opt_level << ": " << elapsed.count() << std::endl;

    return 0;
}
#include "functions.h"
#include <cmath>

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
#include <iostream>
#include <vector>
#include <chrono>

void calculateSums(const std::vector<int>& array, int& sum1, int& sum2) {
    sum1 = 0; // Сумма для каждого 1000-го числа
    sum2 = 0; // Сумма для всех остальных чисел

    for (size_t i = 0; i < array.size(); ++i) {
        if (i % 1000 == 0) {
            sum1 += array[i];
        } else {
            sum2 += array[i];
        }
    }
}

int main(int argc, char* argv[]) {
    std::string optimization_level = (argc > 1) ? argv[1] : "Unknown";

    bool print_flag = false;

    const int cnt = 5;
    const int size = 1000000000;
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        array[i] = i;
    }

    int sum1, sum2;

    const auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < cnt; ++i) {
        calculateSums(array, sum1, sum2);
    }
    const auto end = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double> duration = end - start;
    std::cout << optimization_level << ": " << duration.count() << std::endl;

    if (print_flag) std::cout << "Sum of every 1000th number: " << sum1 << std::endl;
    if (print_flag) std::cout << "Sum of all other numbers: " << sum2 << std::endl;

    return 0;
}

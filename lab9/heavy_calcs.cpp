#include <iostream>
#include <vector>
#include <chrono>

int main(int argc, char* argv[]) {
    std::string optimization_level = (argc > 1) ? argv[1] : "Unknown";

    const int SIZE = 1000000000;
    const int CNT = 10;
    std::vector<int> data(SIZE, 1);

    const auto start = std::chrono::high_resolution_clock::now();

    for (int j = 0; j < CNT; j++) {
        int sum = 0;
        for (int i = 0; i < SIZE; ++i) {
            sum += data[i];
        }
    }

    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> duration = end - start;
    std::cout << optimization_level << ": " << duration.count() << std::endl;

    return 0;
}

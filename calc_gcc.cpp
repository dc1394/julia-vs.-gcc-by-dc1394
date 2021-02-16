#include <chrono>       // for std::chrono
#include <cstdint>      // for std::int64_t
#include <iomanip>      // for std::setiosflags, std::setprecision
#include <iostream>     // for std::cout

std::int64_t calc_gcc();

int main()
{
    using namespace std::chrono;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6);
    
    auto beg = high_resolution_clock::now();
    auto total = calc_gcc();
    auto end = high_resolution_clock::now();
    auto elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";

    beg = high_resolution_clock::now();
    total = calc_gcc();
    end = high_resolution_clock::now();
    elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";
    
    beg = high_resolution_clock::now();
    total = calc_gcc();
    end = high_resolution_clock::now();
    elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";

    std::cout << "total = " << total << std::endl;
}

std::int64_t calc_gcc()
{
    auto tmp = 0LL;
    auto total = 0LL;

    for (auto i = 1LL; i <= 100000; i++) {
        for (auto j = 1LL; j <= 10000; j++) {
            if (!(j % 4)) {
                tmp = i + j;
            } else if (j % 4 == 1) {
                tmp = i - j;
            } else if (j % 4 == 2) {
                tmp = i * j;
            } else {
                tmp = i / j;
            }
            total += tmp;
        }
    }
    return total;
}
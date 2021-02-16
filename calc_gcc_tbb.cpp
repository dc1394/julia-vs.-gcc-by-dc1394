#include <chrono>               // for std::chrono
#include <cstdint>              // for std::int64_t
#include <iomanip>              // for std::setiosflags, std::setprecision
#include <iostream>             // for std::cout
#include <tbb/combinable.h>     // for tbb::combinable
#include <tbb/parallel_for.h>   // for tbb::parallel_for

std::int64_t calc_gcc_tbb();

int main()
{
    using namespace std::chrono;
    
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6);
    
    auto beg = high_resolution_clock::now();
    auto total = calc_gcc_tbb();
    auto end = high_resolution_clock::now();
    auto elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";

    beg = high_resolution_clock::now();
    total = calc_gcc_tbb();
    end = high_resolution_clock::now();
    elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";
    
    beg = high_resolution_clock::now();
    total = calc_gcc_tbb();
    end = high_resolution_clock::now();
    elapsed_time = (duration_cast<duration<double>>(end - beg)).count();
    std::cout << elapsed_time << " seconds\n";

    std::cout << "total = " << total << std::endl;
}

std::int64_t calc_gcc_tbb()
{
    tbb::combinable<std::int64_t> total;

    tbb::parallel_for(
            tbb::blocked_range<std::int64_t>(1LL, 100001LL),
            [&total](auto const & range) {
                for (auto && i = range.begin(); i != range.end(); ++i) {
                    for (auto j = 1LL; j <= 10000; j++) {
                        std::int64_t tmp;

                        if (!(j % 4)) {
                            tmp = i + j;
                        } else if (j % 4 == 1) {
                            tmp = i - j;
                        } else if (j % 4 == 2) {
                            tmp = i * j;
                        } else {
                            tmp = i / j;
                        }
                        
                        total.local() += tmp;
                    }
                }
            });
    return total.combine(std::plus<>());
}
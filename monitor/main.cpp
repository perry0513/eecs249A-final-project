#include <iostream>
#include "monitor.hpp"

int main() {
    std::cout << "Testing monitor with length of 1, condition is cur < 2.5 and prev > 2.5" << std::endl;
    int id = initMonitor(1, [] (std::deque<double>::const_iterator it, double param) { return *it < param && *(it - 1) > param; }, 2.5, 2);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Testing monitor with length of 3, condition is lower bound of 2" << std::endl;
    id = initMonitorLowerBound(3, 2.0);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    return 0;
}

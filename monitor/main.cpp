#include <iostream>
#include "monitor.hpp"

int main() {
    std::cout << "Testing historically monitor with length of 1, condition is all (1) timestep satisfying cur < 2.5 and prev > 2.5" << std::endl;
    std::cout << "Note that there's no difference between historically and once with a length of 1" << std::endl;
    int id = initMonitor(1, false, [] (std::deque<double>::const_iterator it, double param) { return *it < param && *(it - 1) > param; }, 2.5, 2);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Testing once monitor with length of 3, condition is 1 of the 3 recent timesteps satisfying cur < 2.5 and prev > 2.5" << std::endl;
    id = initMonitor(3, true, [] (std::deque<double>::const_iterator it, double param) { return *it < param && *(it - 1) > param; }, 2.5, 2);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Testing historically monitor with length of 3, condition is all values having lower bound of 2.5" << std::endl;
    id = initMonitorLowerBound(3, 2.5);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Testing once monitor with length of 3, condition is one value being above threshold of 2.5" << std::endl;
    id = initMonitorAboveThreshold(3, 2.5);
    for (int i = 6; i > 0; i--) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
    for (int i = 0; i < 6; i++) {
        updateMonitor(id, (double)i);
        std::cout << "New value: " << i << ", Monitor status: " << checkMonitor(id) << std::endl;
    }
}

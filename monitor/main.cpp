#include <iostream>
#include "monitor.hpp"

int main() {
    int id = initMonitor(3, 2, [] (std::deque<double>::const_iterator it) { return *it + *(it - 1) > 4.5; });
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

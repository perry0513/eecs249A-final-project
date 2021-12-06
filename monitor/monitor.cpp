#include <vector>
#include "monitor.hpp"

struct monitor_t {
    int len;
    int num_vals;
    monitor_condition cond;
    std::deque<double> history;
    int last_false;
};

std::vector<monitor_t> monitors;

// Monitor that checks if condition is satisfied for all past <len> timesteps
// where the condition depends on checking the most recent <num_vals> values
// Condition is a boolean function that takes in an iterator to the last
// (most recent) element in the deque
// Condition is assumed to be false if it depends on nonexistent values
// Returns monitor id
int initMonitor(int len, int num_vals, monitor_condition cond) {
    monitor_t monitor;
    monitor.len = len;
    monitor.num_vals = num_vals;
    monitor.cond= cond;
    monitor.last_false = 0;
    monitors.push_back(monitor);
    return (int)monitors.size() - 1;
}

void updateMonitor(int id, double val) {
    if (id < 0 || id >= (int)monitors.size()) {
        return;
    }
    monitor_t &monitor = monitors[id];
    monitor.history.push_back(val);
    if ((int)monitor.history.size() > monitor.num_vals) {
        monitor.history.pop_front();
    }
    if ((int)monitor.history.size() == monitor.num_vals) {
        if (!monitor.cond(monitor.history.cend() - 1)) {
            monitor.last_false = 0;
        } else if (monitor.last_false < monitor.len) {
            monitor.last_false++;
        }
    }
}

bool checkMonitor(int id) {
    if (id < 0 || id >= (int)monitors.size()) {
        return false;
    }
    return monitors[id].last_false == monitors[id].len;
}


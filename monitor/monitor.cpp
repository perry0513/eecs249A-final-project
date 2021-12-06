#include <vector>
#include "monitor.hpp"

struct monitor_t {
    int len;
    monitor_condition cond;
    double cond_param;
    std::deque<double> history;
    int history_len;
    int last_false;
};

std::vector<monitor_t> monitors;

// Monitor that checks if condition is satisfied for all past <len> timesteps
// where the condition depends on checking the most recent <history_len> values
// Condition is a boolean function that takes in an iterator to the last
// (most recent) element in the deque and a double parameter
// Condition is assumed to be false if it depends on nonexistent values
// Returns monitor id
int initMonitor(int len, monitor_condition cond, double cond_param, int history_len) {
    monitor_t monitor;
    monitor.len = len;
    monitor.cond = cond;
    monitor.cond_param = cond_param;
    monitor.history_len = history_len;
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
    if ((int)monitor.history.size() > monitor.history_len) {
        monitor.history.pop_front();
    }
    if ((int)monitor.history.size() == monitor.history_len) {
        if (!monitor.cond(monitor.history.cend() - 1, monitor.cond_param)) {
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

int initMonitorLowerBound(int len, double lower_bound) {
    return initMonitor(len, [] (std::deque<double>::const_iterator it, double param) { return *it >= param; }, lower_bound, 1);
}

int initMonitorUpperBound(int len, double upper_bound) {
    return initMonitor(len, [] (std::deque<double>::const_iterator it, double param) { return *it <= param; }, upper_bound, 1);
}

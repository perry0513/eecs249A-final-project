#include <deque>

typedef bool (*monitor_condition)(std::deque<double>::const_iterator it);

int initMonitor(int len, int num_vals, monitor_condition cond);
void updateMonitor(int id, double val);
bool checkMonitor(int id);

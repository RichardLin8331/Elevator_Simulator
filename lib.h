#include <queue>
#include <mutex>
#include <vector>
using namespace std;
#ifndef LIB_H
#define LIB_H



class channel {
public:
    void push(vector<int> p);
    vector<int> front();
    void pop();
    bool empty();

private:
    queue<vector<int>> c;
    mutex m;
};

class Elevator {
private:
    int current_floor;
    
public:
    channel chan;
    Elevator();
    void display_floor();
    int move(int current, int floor, channel &sc);
    void handler(channel &sc);

};
class elevator_ui {
public:
    channel status_chan;
    Elevator *elevator1, *elevator2;
    elevator_ui();
    void input_run();
    void display_run();
};

#endif
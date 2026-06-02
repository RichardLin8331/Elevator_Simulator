#ifndef LIB_H
#define LIB_H

class Elevator {
private:
    int current_floor;
public:
    
    Elevator();
    void display_floor();
    int move(int floor);
};
class elevator_ui {
private:
    Elevator *elevator1, *elevator2;
public:
    
    elevator_ui();
    void run();
};

#endif
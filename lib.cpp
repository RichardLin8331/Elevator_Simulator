#include <iostream>
#include "lib.h"
using namespace std;

Elevator::Elevator() {
    current_floor = 1;
};

void Elevator::display_floor() {
    cout << "Current floor is " << this->current_floor << endl;
}

void Elevator::move(int floor) {
    cout << "+ Before move: ";
    this->display_floor();
    this->current_floor = floor;
    cout << "+ After move: ";
    this->display_floor();
}

elevator_ui::elevator_ui() {
    elevator1 = new Elevator;
    elevator2 = new Elevator;
}

void elevator_ui::run() {
    cout << "Elevator Start Running!! \n";
    cout << "Elevator1:\n+ ";
    this->elevator1->display_floor();
    cout << "Elevator2:\n+ ";
    this->elevator2->display_floor();
    cout << "\n";
    while (1) {
        int elevatur_num;
        int desired_floor;
        cout << "Choose Elevator: ";
        cin >> elevatur_num;
        if (elevatur_num != 1 && elevatur_num != 2) {
            cout << "Error: You can olny choose elevator 1 or 2\n\n";
            continue;
        }
        cout << "Choose Floor: ";
        cin >> desired_floor;
        if (desired_floor < 1 || desired_floor > 10) {
            cout<<"Error: Desired floor should between 1 and 10\n\n";
            continue;
        }
        switch (elevatur_num) {
            case 1:
                cout << "Elevator1:\n";
                this->elevator1->move(desired_floor);
                cout << "Elevator2:\n+ ";
                this->elevator2->display_floor();
                break;
            case 2:
                cout << "Elevator1:\n+ ";
                this->elevator1->display_floor();
                cout << "Elevator2:\n";
                this->elevator2->move(desired_floor);
                break;
            
        }

        cout << "\n";
    }
}
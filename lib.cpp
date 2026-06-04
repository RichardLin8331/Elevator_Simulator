#include <iostream>
#include <unistd.h>
#include <mutex>
#include <string>
#include <sstream>
#include <vector>
#include "lib.h"

using namespace std;

void channel::push(vector<int> p) {
    lock_guard<mutex> lock(m);
    this->c.push(p);
}

vector<int> channel::front() {
    lock_guard<mutex> lock(m);
    return this->c.front();
}

void channel::pop() {
    lock_guard<mutex> lock(m);
    this->c.pop();
}

bool channel::empty() {
    lock_guard<mutex> lock(m);
    return this->c.empty();
}

Elevator::Elevator() {
    current_floor = 1;
};

void Elevator::display_floor() {
    cout << "is at floor " << this->current_floor << endl;
}

int Elevator::move(int current, int floor, channel &sc) {
    vector<int> v = {current, floor};
    for (auto f: v) {
        int floor_diff = abs(this->current_floor - f);
        int dir = this->current_floor < f ? 1 : -1;

        for (int i = 0; i < floor_diff; i++) {
            this->current_floor += dir;
            sc.push({});
            sleep(1);
        }
    }
    
    return this->current_floor;
}

void Elevator::handler(channel& sc) {
    while(1) {
        while(this->chan.empty());
        auto p = this->chan.front();
        this->chan.pop();
        this->move(p[0], p[1], sc);
    }
}

elevator_ui::elevator_ui() {
    elevator1 = new Elevator;
    elevator2 = new Elevator;
}

void elevator_ui::display_run() {
    cout << "Elevator Start Running!! \n";
    cout << "Elevator 1 ";
    this->elevator1->display_floor();
    cout << "Elevator 2 ";
    this->elevator2->display_floor();
    cout << "---------------\n\n";
    cout << "Input (Elevator, Current, Desired): \n";
    while (1) {
        while (status_chan.empty());
        auto p = status_chan.front();
        status_chan.pop();
        cout << "Elevator 1 ";
        elevator1->display_floor();
        cout << "Elevator 2 ";
        elevator2->display_floor();
        

        cout << "---------------\n\n";
        cout << "Input (Elevator, Current, Desired): \n";
    }
}

void elevator_ui::input_run() {
    string s;
    while(getline(cin, s)) {
        stringstream ss(s);
        string w;
        vector<int> v;
        while (getline(ss, w, ' ')) {
            v.push_back(stoi(w));
        }
        if (v.size()!= 3) {
            cout << "Incorrect Input Format \n";
            cout << "Input (Elevator, Current, Desired): \n";
            continue;
        }
        if ((v[0] != 1 && v[0] != 2)) {
            cout << "Please Select Elevator 1 or 2\n";
            cout << "Input (Elevator, Current, Desired): \n";
            continue;
        }
        bool break_flag = false;
        for (int fi = 1; fi < 3 && !break_flag; fi++) {
            break_flag = false;
            if (v[fi] < 1 || v[fi] > 10) {
                cout << "Floor is in range (1, 10)\n";
                cout << "Input (Elevator, Current, Desired): \n";
                break_flag = true;
            }
        }
        if (break_flag) continue;

        if (v[0] == 1) {
            elevator1->chan.push({v[1], v[2]});
        } else if (v[0] == 2) {
            elevator2->chan.push({v[1], v[2]});
        }
    }
}
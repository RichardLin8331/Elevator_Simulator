#include <thread>
#include "lib.h"

using namespace std;

int main() {
    elevator_ui *ui = new elevator_ui;
    thread ui_thread(&elevator_ui::input_run, ui);
    thread display_thread(&elevator_ui::display_run, ui);
    thread elevater1_handler_thread(&Elevator::handler, ui->elevator1, ref(ui->status_chan));
    thread elevater2_handler_thread(&Elevator::handler, ui->elevator2, ref(ui->status_chan));
    ui_thread.join();
    display_thread.join();
    elevater1_handler_thread.join();
    elevater2_handler_thread.join();
    return 0;
}
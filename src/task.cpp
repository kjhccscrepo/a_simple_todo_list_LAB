#include "task.hpp"

task::task(const std::string &name) {
    myName = name;
    status = false;
}

std::string task::get_name_of_task() const {
    return myName;
}

std::string task::peekStatus() const {
    if (status) {
        return "T";
    }
    return "F";
}
void task::complete() {
    status = true;
}
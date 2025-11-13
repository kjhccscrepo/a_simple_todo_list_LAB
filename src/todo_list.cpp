#include "todo_list.hpp"

int todo_list::get_Task_pos(const task *target_task) const {
    if (myTasks.empty() || target_task == nullptr) {
        return -2;
    }
    for (int i = 0; i < myTasks.size(); i++) {
        if (myTasks[i]->get_name_of_task() == target_task->get_name_of_task()) {
            return i;
        }
    }
    return -1;
}


bool todo_list::allDone() const {
    if (myTasks.empty()) {
        return true;
    }
    for (int i = 0; i < myTasks.size(); i++) {
        if (myTasks[i] == nullptr || myTasks[i]->peekStatus() == "F") {
            return false;
        }
    }
    return true;
}

todo_list::todo_list() {
    myTasks.clear();
    empty_message = "The Task List is empty\n";
}

std::string todo_list::string_of_add(task *new_task) {
    if (get_Task_pos(new_task) < 0) {
        myTasks.push_back(new_task);
        return "Task (" + new_task->get_name_of_task() + ") added to To-Do List!\n";
    }
    return "Task (" + new_task->get_name_of_task() + ") was already present in To-Do List\n";
}
void todo_list::add(const std::string &new_task_string) {
    if (new_task_string.empty()) {
        std::cout << "Cannot add empty task to list!\n";
    } else {
        task *task_to_add = new task(new_task_string);
        std::cout << string_of_add(task_to_add);
    }
}
std::string todo_list::string_of_complete(const task *task_to_complete) const {
    if (int i = get_Task_pos(task_to_complete) >= 0) {
        myTasks[i]->complete();
        return "Task (" + task_to_complete->get_name_of_task() + ") marked complete!\n";
    }
    return "Could not complete task (" + task_to_complete->get_name_of_task() + "). "
    + "Is it in task list?\n";
}

void todo_list::complete(const std::string &task_string) const {
    task *temp_pointer = new task(task_string);
    std::cout << string_of_complete(temp_pointer);
    delete temp_pointer;
}

std::string todo_list::string_of_list_all() {
    if (myTasks.empty()) {
        return empty_message;
    }
    std::stringstream list_all;
    list_all << "\nALL TASKS:\n";
    for (int i = 0; i < myTasks.size(); i++) {
        list_all << "\t";
        list_all << myTasks[i]->get_name_of_task() << "\n";
        list_all << "\tIs it completed:  ";
        list_all << myTasks[i]->peekStatus();
        list_all << "\n\n";
    }
    return list_all.str();
}

std::string todo_list::string_of_list_completed() const {
    std::stringstream list_of_complete;
    list_of_complete << "\nComplete Tasks:";
    list_of_complete << "\n";
    if (myTasks.empty()) {
        list_of_complete << "\tNone.";
    } else {
        bool hasComp = false;
        for (int i = 0; i < myTasks.size(); i++) {
            if (myTasks[i]->peekStatus() == "T") {
                list_of_complete << "\t" + myTasks[i]->get_name_of_task() + "\n";
                if (!hasComp) {
                    hasComp = true;
                }
            }
        }
        if (!hasComp) {
            list_of_complete << "\tNone.";
        }
    }
    list_of_complete << "\n";
    return list_of_complete.str();
}

std::string todo_list::string_of_list_incomplete() const {
    std::stringstream list_of_incomplete;
    list_of_incomplete << "\nIncomplete Tasks:";
    list_of_incomplete << "\n";
    if (allDone()) {
        list_of_incomplete << "\tNone.";
    } else {
        for (int i = 0; i < myTasks.size(); i++) {
            if (myTasks[i]->peekStatus() == "F") {
                list_of_incomplete << "\t" + myTasks[i]->get_name_of_task() + "\n";
            }
        }
    }
    list_of_incomplete << "\n";
    return list_of_incomplete.str();
}

void todo_list::all() {
    std::cout << string_of_list_all();
}

void todo_list::completed() const {
    std::cout << string_of_list_completed();
}

void todo_list::incomplete() const {
    std::cout << string_of_list_incomplete();
}


void todo_list::clear() {
    const int size = myTasks.size() - 1;
    for (int i = size; i >= 0; i--) {
        delete myTasks[i];
        myTasks.erase(myTasks.begin() + i);
    }
    std::cout << "Cleared list of tasks\n";
}




#ifndef TODO_LIST_H
#define TODO_LIST_H
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "task.hpp"

class todo_list {
private:
    std::vector<task*> myTasks;
    std::string empty_message;
    int get_Task_pos(const task *target_task) const;
    bool allDone() const;
    std::string string_of_add(task *new_task);
    std::string string_of_complete(const task *task_to_complete) const;
    std::string string_of_list_all();
    std::string string_of_list_completed() const;
    std::string string_of_list_incomplete() const;

public:
    explicit todo_list();
    void add(const std::string &new_task_string);
    void complete(const std::string &task_string) const;
    void all();
    void completed() const;
    void incomplete() const;
    void clear();
};

#endif

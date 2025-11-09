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
    int get_Task_pos(const task *target_task) const;

    std::string empty_message;

    bool allDone() const;

public:
    explicit todo_list();
    std::string add(task *new_task);
    void add(const std::string &new_task_string);
    std::string complete(const task *task_to_complete) const;
    void complete(const std::string &task_string) const;
    std::string list_all();
    std::string list_completed() const;
    std::string list_incomplete() const;
    void all();
    void completed() const;
    void incomplete() const;
    void clear();
};

#endif

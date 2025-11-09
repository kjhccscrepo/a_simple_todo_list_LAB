#ifndef TASK_H
#define TASK_H
#include <string>
#include <vector>

class task {
private:
    std::string myName;
    bool status;
public:
    explicit task(const std::string &name);
    std::string get_name_of_task() const;
    std::string peekStatus() const;
    void complete();
};
#endif
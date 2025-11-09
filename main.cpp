#include <iostream>
#include "src/todo_list.hpp"

int main() {
    todo_list list;

    list.add("Buy milk");

    list.add("Buy eggs");
    list.add("Prepare a lesson for CSC 122");
    list.add("Sow beet seeds");
    list.add("");
    list.add("Buy milk");

    list.complete("Buy eggs");

    list.all();

    list.completed();

    list.incomplete();

    list.clear();

    list.all();

    return 0;
}

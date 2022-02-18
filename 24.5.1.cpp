#include <iostream>
#include <ctime>
#include <vector>
/*
struct Task {
    std::string name      {};
    std::time_t startTime {};
    std::time_t endTime   {};
};

using TaskStack = std::vector<Task>;

template <typename T>
void input (T &buffer);

std::string humanizedTimer(const std::time_t &timer);

void completeLastTask (TaskStack &taskStack);
Task createTask ();


int main() {
    TaskStack taskStack;

    std::string bufferStd;
    while (true) {
        std::cout << "Enter command from the list - begin, end, status, exit:";
        input(bufferStd);
        if (bufferStd == "begin") {
            completeLastTask(taskStack);
            taskStack.push_back(createTask());
        }
        else if (bufferStd == "end") {
            completeLastTask(taskStack);
        }
        else if (bufferStd == "status"){
            if (taskStack.empty()){
                std::cout << "No tasks" << std::endl;
            }
            else {
                for (const auto& item: taskStack){
                    if (item.endTime == 0) {
                        std::cout << "Current task: " << item.name << std::endl;
                    }
                    else {
                        std::cout << item.name << ":"
                                  << humanizedTimer(item.endTime - item.startTime)
                                  << std::endl;
                    }
                }
            }
        }
        else if (bufferStd == "exit"){
            return 0;
        }
        else {
            std::cout << "Unknown command." << std::endl;
        }
    }

}

template <typename T>
void input (T &buffer) {
    while (true) {
        std::cin.rdbuf()->pubsync();
        std::cin.clear();
        std::cin >> buffer;
        if (std::cin.fail()) {
            std::cout << "Entered error. Try again:";
            continue;
        }
        return;
    }
}

std::string humanizedTimer(const std::time_t &timer){
    std::string buffer{};
    return std::string {" h:"   + std::to_string(timer/3600)
                      + " min:" + std::to_string((timer % 3600) / 60)
                      + " s:"   + std::to_string(timer % 60)};
}

void completeLastTask (TaskStack &taskStack){
    if (!taskStack.empty() and taskStack.back().endTime == 0)
        std::time(&taskStack.back().endTime);
}

Task createTask (){
    Task bufferTask;
    std::cout << "Enter command name:";
    input(bufferTask.name);
    std::time(&bufferTask.startTime);
    return bufferTask;
}
 */
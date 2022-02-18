#include <iostream>
#include <ctime>
#include <iomanip>

int main(){
    std::tm targetTm{};

    while (true) {
        std::cin.rdbuf()->pubsync();
        std::cin.clear();

        std::cin >> std::get_time(&targetTm, "%M:%S");
        if (std::cin.fail()) {
            std::cout << "Time input error. Enter date again:";
            continue;
        }
        break;
    }

    std::time_t currentTime = std::time(nullptr);
    std::time_t endTime = currentTime + targetTm.tm_min * 60 + targetTm.tm_sec;

    std::time_t previousTime = currentTime;
    while (std::time(&currentTime) < endTime){
        if(currentTime - previousTime <= 0)
            continue;
        previousTime = currentTime;
        std::cout << (endTime - currentTime) / 60 << ':' << (endTime - currentTime) % 60 <<std::endl;
    }

    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
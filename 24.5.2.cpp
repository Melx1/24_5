#include <iostream>
#include <ctime>
#include <iomanip>
#include <map>
#include <limits>
/*
using DayMap = std::map<std::string, std::time_t>;
using FriendBirthdayMap = std::map<int, DayMap>; //[key] -> unique name - date
                                                 // where key = month * 100 + day

void fillFriendBirthdayMap(FriendBirthdayMap & fbm);

//use time before 1970
const int unixYear = 70; //year is equal 0 of time_t in tm_year (1970-1900)
const int minYear = unixYear - std::numeric_limits<std::time_t>::max()/31'556'952; //the minimum year that can be written to the database
std::time_t mktime1901(const std::tm & tmRef);
std::tm * localtime1901 (const time_t * timer);


int main() {
    FriendBirthdayMap friendBirthday;
    fillFriendBirthdayMap(friendBirthday);

    std::time_t currentDate;
    time(&currentDate);
    std::tm* bufferTime;
    bufferTime = std::localtime(&currentDate);
    int key = bufferTime->tm_mon * 100 + bufferTime->tm_mday;

    if (!friendBirthday.empty()){
        auto iterFBM = friendBirthday.upper_bound(key);
        if ((--iterFBM)->first == key){
            std::cout << "Special telegram! Today is the birthday of:" << std::endl;
            for (const auto & item: iterFBM->second){
                std::cout << item.first << ' ' << std::put_time(localtime1901(& item.second), "%Y/%m/%d") << std::endl;
            }
        }
        else {
            ++iterFBM;
            if (iterFBM == friendBirthday.end())
                iterFBM = friendBirthday.begin();

            std::cout << "The nearest birthdays of:" << std::endl;
            for (const auto & item: iterFBM->second){
                std::cout << item.first << ' ' << std::put_time(localtime1901(& item.second), "%Y/%m/%d") << std::endl;
            }
        }
    }
    else{
        std::cout << "You have not made any entries in the database." << std::endl;
    }
}

void fillFriendBirthdayMap (FriendBirthdayMap & fbm){
    std::cout << "Enter your friend's name followed by the friend's date of birth (format yyyy/mm/dd) "
                 "separated by a space or \"end\"." << std::endl;

    while (true) {
        std::cin.rdbuf()->pubsync();
        std::cin.clear();
        std::string name;
        std::cin >> name;

        if (name == "end")
            return;

        std::tm bufferTime {};
        while(true){
            std::cin >> std::get_time(&bufferTime,"%Y/%m/%d");
            if (std::cin.fail()) {
                std::cout << "Date input error. Enter date again:";
                std::cin.rdbuf()->pubsync();
                std::cin.clear();
                continue;
            }
            break;
        }
        if (bufferTime.tm_year < minYear) {
            std::cout << "Your friend is the oldest person in the world. "
                         "He is older than Kane Tanaka. Something is wrong here..." << std::endl;
            continue;
        }

        int key = bufferTime.tm_mon * 100 + bufferTime.tm_mday;
        auto entry = fbm[key].insert({name, mktime1901(bufferTime)});
        if (!entry.second) {
            std::cout << "Entry " << name << " already in use" << std::endl;
            std::cout << name << ' ' << std::put_time(localtime1901(& entry.first->second), "%Y/%m/%d") << std::endl;
            continue;
        }
    }

}

std::time_t mktime1901(const std::tm & tmRef) {
    std::tm bufferTm = tmRef;
    std::time_t bufferUnixTime;

    if (bufferTm.tm_year < unixYear){
        bufferTm.tm_year = unixYear + unixYear - bufferTm.tm_year;
        bufferUnixTime = - std::mktime (&bufferTm);
    }
    else {
        bufferUnixTime = std::mktime (&bufferTm);
    }

    return bufferUnixTime;
}

std::tm * localtime1901 (const time_t * timer){
    std::tm* bufferTm;
    std::time_t bufferUnixTime;
    if (*timer < 0){
        bufferUnixTime = -*timer;
        bufferTm = localtime(&bufferUnixTime);
        bufferTm->tm_year = unixYear + unixYear - bufferTm->tm_year;
        return bufferTm;
    }
    else
        return localtime(&bufferUnixTime);
}
 */
#include <sstream>
#include <iomanip>
#include "format_time.h"

using std::setw;
using std::setfill;

std::string format_time( PlayerTime playerTime){

    std::stringstream ss;
    ss << setw(2) << setfill('0') << playerTime.hours<< ":" << setw(2) << setfill('0') << playerTime.minutes << ":" << setw(2) << setfill('0') << playerTime.seconds;
    return ss.str();
}




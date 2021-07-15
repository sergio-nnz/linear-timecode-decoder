#include "timecodes.h"

#include <iostream>

int main() {
    EncodedTime time_1(1, 0, 0, 0);
    EncodedTime time_2(261, 773, 9, 261);
    EncodedTime time_3(521, 1289, 773, 515);

    Timecodes timecodes(30);

    timecodes.AddEncodedTime(time_1);
    timecodes.AddEncodedTime(time_2);
    timecodes.AddEncodedTime(time_3);

    std::cout << timecodes.GetMin() << std::endl;
    std::cout << timecodes.GetMax() << std::endl;
    std::cout << timecodes.GetValueFromMaxAt(2) << std::endl;

    return 0;
}

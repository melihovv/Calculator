#include <vld.h>
#include <sstream>
#include "driver.h"

int main(int argc, char* argv[])
{
    std::istringstream iss("-2+2*3");
    melihovv::calculator::Driver driver(&iss);
    double result = driver.parse();
    std::cout << result << std::endl;

    return 0;
}

#include <vld.h>
#include <sstream>
#include "driver.h"

int main(int argc, char* argv[])
{
    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        std::istringstream iss(input);
        melihovv::calculator::Driver driver(&iss);
        double result = driver.parse();

        std::cout << result << std::endl;
    }

    return 0;
}

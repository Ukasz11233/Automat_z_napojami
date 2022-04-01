#include <iostream>
#include <stdexcept>

void foo(...)
{
    std::cout << "Throws exception\n";
    throw std::exception();
}


int main()
{
    try{
        foo(1, 23, 3, "s");
    }
    catch(const std::invalid_argument & e)
    {
        std::cout << e.what() << "\n";
    }
    catch(...)
    {
        std::cerr << "err" << std::endl;
    }

    return 0;
}
#include "file/Saper.hpp"
#include "file/system.hpp"
int main()
{
    System sys;
    Saper saper(10);
    saper.setup(sys);
    saper.run(sys);
    return 0;
}

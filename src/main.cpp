#include <iostream>
#include <foo.h>

int main()
{
    std::cout << "Hello World!" << std::endl;
    Application::Foo foo;
    foo.print();
    return 0;
}

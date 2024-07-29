#include <iostream>
#include <limits>

#include "structs.hpp"

void confirm_read(container& c)
{
    try
    {
        std::cout << "string: " << (std::string) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n"; 
    }
    try
    {
        std::cout << "long double: " << (long double) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "double: " << (double) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "float: " << (float) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "long long int: " << (long long int) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "long int: " << (long int) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "int: " << (int) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
    try
    {
        std::cout << "bool: " << (bool) c.get() << '\n';
    }
    catch (std::logic_error& e)
    {
        std::cerr << "\033[31m" << e.what()  << "\033[0m\n";
    }
}

int main(void)
{
    
    container::accessor a = 42;

    container c{""};

    std::cout << "foobar:\n";
    c.get() = "foobar";
    confirm_read(c);

    std::cout << "bazquux (std::string)\n";
    c.get() = std::string("bazquux");
    confirm_read(c);

    long double ld = std::numeric_limits<long double>::max();
    std::cout << ld << '\n';
    c.get() = ld;
    confirm_read(c);

    double d = std::numeric_limits<double>::max();
    std::cout << d << '\n';
    c.get() = d;
    confirm_read(c);

    float f = std::numeric_limits<float>::max();
    std::cout << f << '\n';
    c.get() = f;
    confirm_read(c);

    long long ll = std::numeric_limits<long long>::max();
    std::cout << ll << '\n';
    c.get() = ll;
    confirm_read(c);

    long l = std::numeric_limits<long>::max();
    std::cout << l << '\n';
    c.get() = l;
    confirm_read(c);

    int i = std::numeric_limits<int>::max();
    std::cout << i << '\n';
    c.get() = i;
    confirm_read(c);

    std::cout << "true\n";
    c.get() = true;
    confirm_read(c);

}

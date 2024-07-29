#include "structs.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

container::accessor::accessor(container* parent) : parent(parent) {  }

container::accessor& container::accessor::operator=(const std::string& s)
{
    parent->data = '"';
    parent->data += s;
    parent->data += '"';

    return *this;
}

container::accessor& container::accessor::operator=(const char* c)
{
    parent->data = '"';
    parent->data += std::string(c);
    parent->data += '"';

    return *this;
}

container::accessor::operator std::string() const
{
    const std::string& line = parent->data;
    if (line.front() != '"') throw std::invalid_argument("data is not a std::string");
    return line.substr(1, line.size()-2);
}

container::accessor& container::accessor::operator=(long double d)
{
    std::stringstream ss;
    ss << d;
    parent->data = ss.str();
    return *this;
}

container::accessor& container::accessor::operator=(double d)
{
    std::stringstream ss;
    ss << d;
    parent->data = ss.str();
    return *this;
}

container::accessor& container::accessor::operator=(float d)
{
    std::stringstream ss;
    ss << d;
    parent->data = ss.str();
    return *this;
}

container::accessor::operator long double() const
{
    long double d;
    try
    {
        d = std::stold(parent->data);
        return d;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not floating point");
    }
    
}

container::accessor::operator double() const
{
    double d;
    try
    {
        d = std::stod(parent->data);
        return d;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not floating point");
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("data is too large to store in double");
    }
    
}

container::accessor::operator float() const
{
    float d;
    try
    {
        d = std::stof(parent->data);
        return d;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not floating point");
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("data is too large to store in float");
    }
    
}

container::accessor& container::accessor::operator=(long long i)
{
    std::stringstream ss;
    ss << i;
    parent->data = ss.str();
    return *this;
}

container::accessor& container::accessor::operator=(long i)
{
    std::stringstream ss;
    ss << i;
    parent->data = ss.str();
    return *this;
}

container::accessor& container::accessor::operator=(int i)
{
    std::stringstream ss;
    ss << i;
    parent->data = ss.str();
    return *this;
}

container::accessor::operator long long() const
{
    long long i;
    try
    {
        i = std::stoll(parent->data);
        return i;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not parsable as integer");
    }
}

container::accessor::operator long() const
{
    long i;
    try
    {
        i = std::stol(parent->data);
        return i;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not parsable as integer");
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("data is too large for long");
    }
}

container::accessor::operator int() const
{
    int i;
    try
    {
        i = std::stoi(parent->data);
        return i;
    }
    catch (const std::invalid_argument&)
    {
        throw std::invalid_argument("data is not parsable as integer");
    }
    catch (const std::out_of_range&)
    {
        throw std::out_of_range("data is too large for int");
    }
}

container::accessor& container::accessor::operator=(bool b)
{
    parent->data = b ? "true" : "false";
    return *this;
}

container::accessor::operator bool() const
{
    if (parent->data != "true" && parent->data != "false") throw std::invalid_argument("data is not a bool");
    return (parent->data == "true");
}

container::container(const std::string& data) : data(data) {  }

/* needs to return const_accessor where parent is const
const accessor container::get() const
{
    return accessor(this);
}
*/

container::accessor container::get()
{
    return accessor(this);
}

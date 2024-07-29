# Advanced Casting
This is an experiment with using casting and assignment operators to implement primative-like syntax for read-write access to complex variables

## Desired Syntax:
### Read
`std::string name = container.get();`

### Write
`data.get() = 3.14159;`

## Method:
`container::get()` returns an `accessor` type, that has assignment operators taking all desired types as arguments, and cast operators to those types\
This accessor is a private member of the container to prevent the assignment of the accessor to a variable

## Downsides:
Because C++ doesn't allow more than one cast, there needs to be a cast to each type, not just to one similar type. e.g. double and float both need to be implemented.\
I may be able to use `std::integral` and `std::floating_point`, but I don't know whether the compiler will be able to deduce the template parameter.\
In any case this will take C++20, which I want to avoid for hypothetical usability

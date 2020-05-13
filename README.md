# iter8

![CI](https://github.com/paul-reilly/iter8/workflows/CI/badge.svg?branch=master&event=push)

## a simple, single iterator for C++17+

Providing simple `next` functionality, iter8 makes use of `std::optional` to allow
safely attempting to iterate beyond the end of a container bounds without use of exceptions.

### Example:

```cpp
auto v = std::vector{ 42, 1337, 666 };
auto iter = Iter{ v };

std::cout << *iter.next();
iter.reset();

while (auto next = iter.next())
    std::cout << *next << "\n";
```



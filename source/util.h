#ifndef UTIL_H
#define UTIL_H

#include <iostream>

template<class Arg>
void println(Arg &&arg)
{
    using namespace std;
    cout << forward<Arg>(arg) << endl;
}

template<class Arg, class ...Args>
void println(Arg &&arg, Args &&...args)
{
    using namespace std;
    cout << forward<Arg>(arg) << ' ';
    println(forward<Args>(args)...);
}

#endif // UTIL_H

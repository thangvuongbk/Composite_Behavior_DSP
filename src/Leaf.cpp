#include "Leaf.h"

#include <iostream>
#include <string>

using namespace std;

Leaf::Leaf()
{
    cout << "ctor: " << __func__ << endl;
}

Leaf::~Leaf()
{
    cout << "dtor: " << __func__ << endl;
}
std::string Leaf::Operation()
{
    cout << "Entering func: " << __func__ << endl;
    cout << "Leaving func: " << __func__ << endl;
    return "Leaf";
}

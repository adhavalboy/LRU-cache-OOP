#pragma once
#include "Node.h"
#include <unordered_map>
using namespace std;
class myMap
{
public:
    myMap() {}
    unordered_map<int, Node *> mapStore;
    myMap(unordered_map<int, Node *> map)
    {
        mapStore = map;
    }
    virtual int add(int a, int b) const = 0;
};
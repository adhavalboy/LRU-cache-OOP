#pragma once
#include "Node.h"
#include <unordered_map>
#include "MyMap.cpp"
using namespace std;
class MapNurture : public myMap
{
public:
    unordered_map<int, Node *> mapStore;
    MapNurture(unordered_map<int, Node *> map)
    {
        mapStore = map;
    }
    int add(int a, int b) const
    {
        return a + b;
    }
};
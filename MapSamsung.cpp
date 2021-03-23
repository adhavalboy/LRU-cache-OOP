#pragma once
#include "Node.h"
#include "MyMap.cpp"
#include <unordered_map>
using namespace std;
class MapSamsung : public myMap
{
public:
    unordered_map<int, Node *> mapStore;
    MapSamsung() {}
    MapSamsung(unordered_map<int, Node *> map)
    {
        mapStore = map;
    }

    int add(int a, int b) const
    {
        return a + b;
    }
};
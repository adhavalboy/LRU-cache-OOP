#include <iostream>
#include "LRUcache.cpp"
using namespace std;

int main()
{

    LRUcache cache(3, 1); // define size of cache window and method
    cache.addPage(2, 2);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cache.addPage(1, 1);
    cache.addPage(2, 3);
    cache.addPage(5, 5);
    cache.addPage(1, 3);
    cout << cache.get(5) << endl;

}

#include <unordered_map>
#include "DoublyLinkedList.cpp"
#include "MapSamsung.cpp"
#include "MapNurture.cpp"
#include "MyMap.cpp"
using namespace std;
class LRUcache
{
    // window is cache limited size and size store current used page
    int window, size;
    DoublyLinkedList *pageList;
    myMap *map;                          // search operation O(1)
    unordered_map<int, Node *> mapStore; // using map of std library  but we can me class if in future new map implemtation

public:
    LRUcache(int window, int method)
    {
        this->window = window;             // capacity
        size = 0;                          // current fill size
        pageList = new DoublyLinkedList(); // store all page in list  delete operation would done in O(1)

        // according to user we can use map
        if (method == 1)
            map = new MapSamsung(mapStore);
        else
            map = new MapNurture(mapStore);
    }
    // request for storing page
    /*
        we are adding new page in front and remove at back
    */
    void addPage(int pageId, int mValue)
    {
        // if key already present, update value and move page to head
        if (map->mapStore.find(pageId) != map->mapStore.end())
        {
            // update value
            map->mapStore[pageId]->memoryValue = mValue;
            pageList->moveTohead(map->mapStore[pageId]);
            return;
        }

        if (size == window)
        {
            // remove last page
            int k = pageList->getLastPage()->pageId;
            map->mapStore.erase(k);
            pageList->removeRear();
            size--;
        }

        // add new page
        Node *page = pageList->addTohead(pageId, mValue);
        size++;
        map->mapStore[pageId] = page;
    }
    int get(int pageId)
    {
        if (map->mapStore.find(pageId) == map->mapStore.end())
        {
            return -1;
        }
        int val = map->mapStore[pageId]->memoryValue;

        // move the page to front
        pageList->moveTohead(map->mapStore[pageId]);
        return val;
    }
};
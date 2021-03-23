
// in cpp by default is private access
#pragma once
class Node
{
public:
    Node *prev, *next;
    int pageId, memoryValue; // key : pageid , value: memory location
    Node(int pageId, int mValue)
    {
        pageId = pageId;
        memoryValue = mValue;
        prev = NULL;
        next = NULL;
    }
    //TODO: gatter setter
};

// doubly linklist implementation
#include "Node.h"
class DoublyLinkedList
{
    Node *front, *rear;

public:
    DoublyLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    Node *addTohead(int pageId, int memoryValue)
    {
        Node *page = new Node(pageId, memoryValue);
        // if empty queue
        if (!front && !rear)
        {
            front = rear = page;
        }
        else
        {
            // add in the front
            page->next = front;
            front->prev = page;
            front = page;
        }
        return page;
    }

    void moveTohead(Node *page)
    {

        if (page == front) //if already on front
        {
            return;
        }
        if (page == rear) // if last then remove
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        else
        {
            // delete in between
            page->prev->next = page->next;
            page->next->prev = page->prev;
        }
        //add in front
        page->next = front;
        page->prev = NULL;
        front->prev = page;
        front = page;
    }
    // when queue is full remove least recent
    void removeRear()
    {
        if (isEmpty())
        {
            return;
        }
        if (front == rear)
        {
            delete rear;
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }
    }
    Node *getLastPage()
    {
        return rear;
    }

    bool isEmpty()
    {
        if (rear == NULL)
            return true;
        return false;
    }
};
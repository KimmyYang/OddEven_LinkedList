#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class ListNode;
class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();
        ListNode* mHead;
        ListNode* mTail;
        int mSize;
    protected:
    private:
};

#endif // LINKEDLIST_H

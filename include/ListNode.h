#ifndef LISTNODE_H
#define LISTNODE_H


class ListNode
{
    public:
        ListNode();
        ListNode(int);
        virtual ~ListNode();
        int mData;
        ListNode* mNext;
        ListNode* mPrevious;
    protected:
    private:
};

#endif // LISTNODE_H

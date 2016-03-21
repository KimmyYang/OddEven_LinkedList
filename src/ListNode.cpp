#include <iostream>
#include "ListNode.h"

using namespace std;
ListNode::ListNode()
{
    //ctor
}
ListNode::ListNode(int data)
{
    this->mData = data;
    this->mNext = NULL;
    this->mPrevious = NULL;
}

ListNode::~ListNode()
{
    //dtor
}

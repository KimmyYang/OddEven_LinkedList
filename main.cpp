#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ListNode.h"

using namespace std;

#define _DEBUG 0
#define MOD_2(X) X%2

void insertNode(LinkedList* linkedList, int num){

    //cout<<"[insertNode]+ num = "<<num<<endl;
    ListNode* node = new ListNode(num);
    if(linkedList->mHead == NULL){
        linkedList->mHead = node;
        linkedList->mTail = node;
        node->mPrevious = NULL;
        node->mNext = NULL;
    }
    else{
        ListNode* tail = linkedList->mTail;
        if(tail != NULL){
            tail->mNext = node;
            node->mPrevious = tail;
            linkedList->mTail = node;
        }
        else{
            cout<<"Error linked"<<endl;
        }
    }
}
void output(LinkedList *linkedList){
    cout<<"[output]+"<<endl;
    ListNode* node = linkedList->mHead;
    while(node->mPrevious!=NULL){
        linkedList->mHead = node->mPrevious;
        node = linkedList->mHead;
    }
    node = linkedList->mTail;
    while(node->mNext!=NULL){
        linkedList->mTail = node->mNext;
        node = linkedList->mTail;
    }
    int i = 1;
    node = linkedList->mHead;
    while(true){
        if(node==NULL){
            cout<<"NULL"<<endl;
            break;
        }
        cout<<node->mData<<"->";
        node = node->mNext;
#if _DEBUG == 1
        if(i==10)break;
#endif
    }
}
void insert_front(ListNode* pivot, ListNode* compNode, LinkedList* linkedList){
    if(pivot!=NULL && compNode!=NULL){
        ListNode* prev = pivot->mPrevious;
#if _DEBUG == 1
        if(prev!=NULL)cout<<"prev="<<prev->mData<<", pivot = "<<pivot->mData<<", compNode = "<<compNode->mData<<endl;
        else cout<<"pivot="<<pivot->mData<<", compNode = "<<compNode->mData<<endl;
#endif
        if(pivot->mData>compNode->mData){

            if(prev == NULL){
#if _DEBUG == 1
                cout<<"here 1"<<endl;
#endif
                ListNode* compNextNode = compNode->mNext;
                pivot->mPrevious = compNode;
                compNode->mNext = pivot;
                compNode->mPrevious = NULL;
                pivot->mNext = compNextNode;
                if(compNextNode!=NULL)compNextNode->mPrevious = pivot;
#if _DEBUG == 1
                output(linkedList);
#endif
                insert_front(pivot,pivot->mNext, linkedList);
            }
            else{
#if _DEBUG == 1
                cout<<"here 2"<<endl;
#endif
                ListNode* compNextNode = compNode->mNext;
                if(compNode->mPrevious==pivot){
                        pivot->mNext = compNextNode;
                }
                if(compNextNode!=NULL){
                        compNextNode->mPrevious = compNode->mPrevious;
                        compNode->mPrevious->mNext = compNextNode;
                }
                else{
                    compNode->mPrevious->mNext = NULL;
                }
                prev->mNext = compNode;
                compNode->mPrevious = prev;
                compNode->mNext = pivot;
                pivot->mPrevious = compNode;
#if _DEBUG == 1
                output(linkedList);
#endif
                insert_front(prev,compNode, linkedList);
            }
        }
        else{
#if _DEBUG == 1
            cout<<"here 3"<<endl;
#endif
            compNode = compNode->mNext;
            insert_front(pivot, compNode, linkedList);
        }
    }
}

void sort_list(ListNode* pivot, LinkedList* linkedList)
{
    //compare right
    while(pivot!=NULL && pivot->mNext != NULL){
        ListNode* compNode = pivot->mNext;
#if _DEBUG == 1
        cout<<"pivot:"<<pivot->mData<<",compNode:"<<compNode->mData<<endl;
#endif
        insert_front(pivot,compNode, linkedList);
        pivot = pivot->mNext;
    }
}
/*
leftList <- rightList
*/
LinkedList* merge_list(LinkedList* leftList, LinkedList* rightList){

    ListNode* leftTail = leftList->mTail;
    ListNode* rightHead = rightList->mHead;

    leftTail->mNext = rightHead;
    rightHead->mPrevious = leftTail;
    leftList->mTail = rightList->mTail;

    return leftList;
}

int main(int argc, char *argv[])
{
    LinkedList *oddList = new LinkedList();
    LinkedList *evenList = new LinkedList();

    for(int i=1;i<argc;++i){
        int num = stoi(argv[i]);
        if(MOD_2(num) == 1){
            insertNode(oddList, num);
            ++(oddList->mSize);
        }
        else{
            insertNode(evenList, num);
            ++(evenList->mSize);
        }
    }
#ifdef _DEBUG
    output(oddList);
    output(evenList);
#endif
    cout<<"\nStart sort ... "<<endl;
    ListNode* pivot = oddList->mHead;
    sort_list(pivot, oddList);
    pivot = evenList->mHead;
    sort_list(pivot, evenList);
    cout<<"Sorted odd list:";
    output(oddList);
    cout<<"Sorted event list:";
    output(evenList);
    cout<<"\nMerge list:";
    output(merge_list(oddList, evenList));

    return 0;
}

//
//  main.cpp
//  Golnaz
//
//  Created by Golnaz Ghodoosipour on 2019-10-22.
//  Copyright © 2019 Golnaz Ghodoosipour. All rights reserved.
//

#include <iostream>

struct ListNode {
    int data;
    ListNode* next;
};


ListNode* reverseList(ListNode* A)
{
    ListNode* dummy = nullptr;
    
    ListNode* AReverse = new ListNode();
    
    ListNode* curr = A;
    
    while(curr)
    {
        AReverse = curr;
        curr = curr->next;
        AReverse->next = dummy;
        dummy = AReverse;
    }
    
    return dummy;
}

int main(int argc, const char * argv[])
{
    ListNode* A = NULL;
    ListNode* second = NULL;
    ListNode* third = NULL;
    
    A = new ListNode();
    second = new ListNode();
    third = new ListNode();
    
    A->data = 1; // assign data in first node
    A->next = second; // Link first node with
    
    second->data = 2;
    second->next = third;
    
    third->data = 3; // assign data to third node
    third->next = NULL;
    
    ListNode* reverseHead = reverseList(A);
    
    
    while(reverseHead)
    {
        std::cout<<reverseHead->data<<std::endl;
        reverseHead = reverseHead->next;
    }
    
    return 0;
}

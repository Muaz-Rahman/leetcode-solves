/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include "commonHeader.h"
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *result = new ListNode();
        ListNode *temp = result;
        // the loop will run as long as either of the lists have digits left AND/OR there is a remaining 1 as carry; ANY one of these reasons is enough to go to the next iteration
        while (l1->next != nullptr || l2->next != nullptr || carry != 0)
        {
            // nodeValues represent the integers (val) from each of the linked list's current node; they will be added
            int nodeValue1 = 0, nodeValue2 = 0;
            // if we get either l1 or l2 to have reached the end of their list by checking if they have become nullptr, it will be as if we are adding 0, else the value they contain
            nodeValue1 = l1 == nullptr ? 0 : l1->val;
            nodeValue2 = l2 == nullptr ? 0 : l2->val;
            // now, if adding the nodeValues result in number greater than 9 then we need to break the number down to n%10 and 1 (since two digit addition can't have carry greater than one)
            int addedValue = nodeValue1 + nodeValue2 + carry;
            if (addedValue > 9)
            {
                temp->val = addedValue % 10;
                carry = 1;
            }
            // otherwise the two digits added can be directly placed in to the resultant list node, and the carry be reset to 0
            else
            {
                temp->val = addedValue;
                carry = 0;
            }
            // finally, once we have done everything for one iteration with the current pair of nodes, we iterate to the next pair of listNodes
            l1 = l1->next != nullptr ? l1->next : l1;
            l2 = l2->next != nullptr ? l2->next : l2;
            // and take the temp list node to point to the next value
            temp->next = new ListNode();
            temp = temp->next;
        }
        return result;
    }
};
// @lc code=end

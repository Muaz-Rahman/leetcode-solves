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
        // the loop will run as long as either of the lists have not been exhausted or there is a remaining 1 as carry; ANY one of these conditions being true takes to the next iteration
        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            // nodeValues represent the integers (val) from each of the linked list's current node; they will be added
            int nodeValue1 = 0, nodeValue2 = 0;
            // if we get either l1 or l2 to have reached the end of their list by checking if they have become nullptr, it will be as if we are adding 0, else the value they contain
            nodeValue1 = l1 == nullptr ? 0 : l1->val;
            nodeValue2 = l2 == nullptr ? 0 : l2->val;
            // now, the carry is always going to be addedValue/10 since it's either 0 or 1 and addedValue%10 will be the value for the current result node
            int addedValue = nodeValue1 + nodeValue2 + carry;
            temp->val = addedValue % 10;
            carry = addedValue / 10;
            // finally, once we have done everything for one iteration with the current pair of nodes, we iterate to the next pair of listNodes
            l1 = l1 != nullptr ? l1->next : nullptr;
            l2 = l2 != nullptr ? l2->next : nullptr;
            // and take the temp list node to point to the next value; but if the next value
            if ((l1 == nullptr && l2 == nullptr && carry == 0))
                break;
            temp->next = new ListNode();
            temp = temp->next;
        }
        return result;
    }
};
// @lc code=end

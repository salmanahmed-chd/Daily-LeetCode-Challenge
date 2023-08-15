/*
86. Partition List

https://leetcode.com/problems/partition-list/description/
*/

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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        vector<int> before, after;

        ListNode* newhead = head;
        ListNode* temp = head;

        if(!head) return NULL;

        while(head){
            if(head -> val < x) before.push_back(head -> val);
            else after.push_back(head -> val);

            head = head -> next;
        }

        int i = 0;

        while(i < before.size()){
            temp -> val = before[i];
            temp = temp -> next;
            i++;
        }

        i = 0;

        while(temp){
            temp -> val = after[i];
            temp = temp -> next;
            i++;
        }

        return newhead;        
        
    }
};

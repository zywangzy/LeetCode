#include "../IOLib.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Reverse the first half of linked list in O(n), then iterate through
first and second halves to decide if they equal to each other.
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = head, *end = head;
        while(end && end->next){
            mid = mid->next;
            end = end->next->next;
        }
        ListNode* prev = NULL, *curr = head, *temp = NULL;
        while(curr != mid){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = (end == NULL) ? mid : mid->next;
        while(curr){
            if(prev->val != curr->val) return false;
            prev = prev->next;
            curr = curr->next;
        }
        return true;
    }
};

int main(void){
    ListNode* root = readLinkedList();
    Solution solution;
    bool res = solution.isPalindrome(root);
    cout << "The linked list is " << (res?"":"not ") << "palindrome." << endl;
    return 0;
}

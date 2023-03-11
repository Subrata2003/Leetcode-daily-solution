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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        ListNode* middle = getMiddle(head);
        TreeNode* root = new TreeNode(middle->val);
        root->right = sortedListToBST(middle->next);
        middle->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
    
    ListNode* getMiddle(ListNode* head){
        //if(head == NULL || head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if(prev!=NULL) prev->next = NULL;
        return slow;
    }
};
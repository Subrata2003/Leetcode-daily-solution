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
    
    vector<ListNode*> nodes;

    Solution(ListNode* head) {
        while(head!=NULL)
        {
            nodes.push_back(head);
            head=head->next;
        }
    }
    
    int getRandom() {

      int n=nodes.size();
      int radn=rand()%n;
      return nodes[radn]->val;  
      
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
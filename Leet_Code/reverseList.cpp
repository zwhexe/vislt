#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2)
            return head;
        ListNode* tail = head;
        for(int i = 1; i < k; i++) {
            if(tail && tail->next)
                tail = tail->next;
            else // means length < k
                return head;
        }
        // recurse next reverse node list
        ListNode* after = reverseKGroup(tail->next, k);
        
        // reverse a list by put next to head 1by1
        ListNode* tmp = head->next;
        ListNode* pre = head;
        while(--k) {
            pre->next = tmp->next;
            tmp->next = head; 
            head = tmp;
            tmp = pre->next;
        }
        pre->next = after;
        return head;
    }
};

int main()
{
    ListNode t1(1);
    ListNode t2(2); t1.next = &t2;
    ListNode t3(3); t2.next = &t3;
    ListNode t4(4); t3.next = &t4;
    ListNode t5(5); t4.next = &t5;
    Solution sol;
    ListNode* t = sol.reverseKGroup(&t1, 3);

    while(t!=NULL){
        cout << t->val << endl;
        t = t->next;
    }

    return 0;
}

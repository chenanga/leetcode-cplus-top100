#include<iostream>


using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //  //使用哈希表，有点费时间
 // class Solution {
 // public:
 //     ListNode *detectCycle(ListNode *head) {
 //         unordered_set<ListNode *> node_set;

 //         ListNode *cur = head;
 //         while (cur != NULL) {

 //             if (node_set.count(cur))
 //                 return cur;
 //             node_set.insert(cur);
 //             cur = cur->next;
 //         }
 //         return NULL;
 //     }
 // };

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

  //数学推导，快慢指针
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                ListNode* cur = head;
                while (cur && slow) {
                    if (cur == slow)
                        return cur;
                    cur = cur->next;
                    slow = slow->next;
                }
            }
        }
        return NULL;
    }
};

int main() {

	system("pause");
	return 0;
}
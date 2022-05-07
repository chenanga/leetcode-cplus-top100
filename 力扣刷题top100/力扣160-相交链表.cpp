#include<iostream>


using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}

};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //  //使用哈希表
 // class Solution {
 // public:
 //     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

 //         unordered_set<ListNode *> setNode;

 //         while (headA != NULL) {
 //             setNode.insert(headA);
 //             headA = headA->next;
 //         }

 //         while (headB != NULL) {
 //             if (setNode.count(headB)) 
 //                 return headB;
 //             headB = headB->next;
 //         }

 //         return NULL;
 //     }
 // };

  //不使用哈希表
  //节点a从头遍历到尾后，再从b出发  
  //节点b从头遍历到尾后，再从a出发
  //如果相交，一定会在焦点相遇
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* nodeA = headA;
        ListNode* nodeB = headB;

        while (nodeA != NULL || nodeB != NULL) {

            if (nodeA == NULL)
                nodeA = headB;
            if (nodeB == NULL)
                nodeB = headA;
            if (nodeA == nodeB)
                return nodeA;

            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }

        return NULL;
    }
};

int main() {

	system("pause");
	return 0;
}
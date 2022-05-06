#include<iostream>
#include<unordered_map>

using namespace std;

/* �������û����������ٶȿ�

        moveToHead(hashMap_[key]);
        return node->value;

        DLinkNode* node = hashMap_[key];
        moveToHead(node);
        return node->value;
*/


struct DLinkNode {
    int key;
    int value;
    DLinkNode* pre;
    DLinkNode* next;
    // DLinkNode(): key(0), value(0), pre(nullptr), next(nullptr) {}
    DLinkNode(int _key, int _value) : key(_key), value(_value), pre(NULL), next(NULL) {}
};
class LRUCache {
public:
    LRUCache(int capacity) {
        dummy_node_head_ = new DLinkNode(-1, -1);
        dummy_node_tail_ = new DLinkNode(-2, -2);
        dummy_node_head_->next = dummy_node_tail_;
        dummy_node_tail_->pre = dummy_node_head_;
        capacity_ = capacity;
        size_ = 0;
    }

    int get(int key) {
        if (!hashMap_.count(key))
            return -1;
        DLinkNode* node = hashMap_[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!hashMap_.count(key)) {
            //�������ȴ���
            DLinkNode* addNode = new DLinkNode(key, value);
            //��ӵ���ϣ��
            hashMap_[key] = addNode;
            //��ӵ�˫������ͷ��
            addToHead(addNode);
            ++size_;
            if (size_ > capacity_) {

                //������β���Ƴ�
                DLinkNode* delNode = removeTail();
                //�ӹ�ϣ��ɾ��
                hashMap_.erase(delNode->key);
                //���´�С
                --size_;
                //�ͷţ���ֹ�ڴ�й©
                delete delNode;
            }
        }
        else {
            DLinkNode* node = hashMap_[key];
            node->value = value;
            moveToHead(node);
        }

        return;
    }
private:
    int capacity_;
    int size_;
    DLinkNode* dummy_node_head_;
    DLinkNode* dummy_node_tail_;
    unordered_map <int, DLinkNode*> hashMap_;

    void addToHead(DLinkNode* node) {
        node->next = dummy_node_head_->next;
        node->next->pre = node;
        dummy_node_head_->next = node;
        node->pre = dummy_node_head_;
    }

    void removeNode(DLinkNode* node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    void moveToHead(DLinkNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkNode* removeTail() {
        DLinkNode* node = dummy_node_tail_->pre;
        removeNode(node);
        return node;
    }
};


// //�ٷ�ʵ��
// struct DLinkedNode {
//     int key, value;
//     DLinkedNode* prev;
//     DLinkedNode* next;
//     DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
//     DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
// };

// class LRUCache {
// private:
//     unordered_map<int, DLinkedNode*> cache;
//     DLinkedNode* head;
//     DLinkedNode* tail;
//     int size;
//     int capacity;

// public:
//     LRUCache(int _capacity): capacity(_capacity), size(0) {
//         // ʹ��αͷ����αβ���ڵ�
//         head = new DLinkedNode();
//         tail = new DLinkedNode();
//         head->next = tail;
//         tail->prev = head;
//     }

//     int get(int key) {
//         if (!cache.count(key)) {
//             return -1;
//         }
//         // ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
//         DLinkedNode* node = cache[key];
//         moveToHead(node);
//         return node->value;
//     }

//     void put(int key, int value) {
//         if (!cache.count(key)) {
//             // ��� key �����ڣ�����һ���µĽڵ�
//             DLinkedNode* node = new DLinkedNode(key, value);
//             // ��ӽ���ϣ��
//             cache[key] = node;
//             // �����˫�������ͷ��
//             addToHead(node);
//             ++size;
//             if (size > capacity) {
//                 // �������������ɾ��˫�������β���ڵ�
//                 DLinkedNode* removed = removeTail();
//                 // ɾ����ϣ���ж�Ӧ����
//                 cache.erase(removed->key);
//                 // ��ֹ�ڴ�й©
//                 delete removed;
//                 --size;
//             }
//         }
//         else {
//             // ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
//             DLinkedNode* node = cache[key];
//             node->value = value;
//             moveToHead(node);
//         }
//     }

//     void addToHead(DLinkedNode* node) {
//         node->prev = head;
//         node->next = head->next;
//         head->next->prev = node;
//         head->next = node;
//     }

//     void removeNode(DLinkedNode* node) {
//         node->prev->next = node->next;
//         node->next->prev = node->prev;
//     }

//     void moveToHead(DLinkedNode* node) {
//         removeNode(node);
//         addToHead(node);
//     }

//     DLinkedNode* removeTail() {
//         DLinkedNode* node = tail->prev;
//         removeNode(node);
//         return node;
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    cout << " cout " << endl;
    clog << " clog" << endl;
	system("pause");
	return 0;
}
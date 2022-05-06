#include<iostream>
#include<unordered_map>

using namespace std;

/* 上面代码没有下面代码速度快

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
            //不存在先创建
            DLinkNode* addNode = new DLinkNode(key, value);
            //添加到哈希表
            hashMap_[key] = addNode;
            //添加到双向链表头部
            addToHead(addNode);
            ++size_;
            if (size_ > capacity_) {

                //从链表尾部移除
                DLinkNode* delNode = removeTail();
                //从哈希表删除
                hashMap_.erase(delNode->key);
                //更新大小
                --size_;
                //释放，防止内存泄漏
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


// //官方实现
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
//         // 使用伪头部和伪尾部节点
//         head = new DLinkedNode();
//         tail = new DLinkedNode();
//         head->next = tail;
//         tail->prev = head;
//     }

//     int get(int key) {
//         if (!cache.count(key)) {
//             return -1;
//         }
//         // 如果 key 存在，先通过哈希表定位，再移到头部
//         DLinkedNode* node = cache[key];
//         moveToHead(node);
//         return node->value;
//     }

//     void put(int key, int value) {
//         if (!cache.count(key)) {
//             // 如果 key 不存在，创建一个新的节点
//             DLinkedNode* node = new DLinkedNode(key, value);
//             // 添加进哈希表
//             cache[key] = node;
//             // 添加至双向链表的头部
//             addToHead(node);
//             ++size;
//             if (size > capacity) {
//                 // 如果超出容量，删除双向链表的尾部节点
//                 DLinkedNode* removed = removeTail();
//                 // 删除哈希表中对应的项
//                 cache.erase(removed->key);
//                 // 防止内存泄漏
//                 delete removed;
//                 --size;
//             }
//         }
//         else {
//             // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
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
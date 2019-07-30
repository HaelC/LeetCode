class MyLinkedList {
private:
    struct Node {
        int val;
        Node *prev;
        Node *next;
    };
    int size;
    Node *head;
    Node *tail;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *newHead = new Node;
        newHead->val = val;
        if (!head) {
            head = newHead;
            tail = newHead;
        }
        else {
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *newTail = new Node;
        newTail->val = val;
        if (!tail) {
            head = newTail;
            tail = newTail;
        }
        else {
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        if (index <= 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else {
            Node *temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node *newNode = new Node;
            newNode->val = val;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        if (index == 0) {
            if (size > 1) {
                head->next->prev = nullptr;
            }
            else {
                tail = head->next;
            }
            head = head->next;
        }
        else if (index == size - 1) {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        else {
            Node *temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            temp->next->next->prev = temp;
            temp->next = temp->next->next;
        }
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
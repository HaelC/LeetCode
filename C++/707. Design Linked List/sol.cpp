class MyLinkedList {
private:
    struct node {
        int val;
        node *next;
    };
    node *head;
    node *tail;
    int size;
    
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
        node *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        node *newhead = new node;
        newhead->val = val;
        newhead->next = head;
        head = newhead;
        if (!size)
            tail = newhead;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        node *newtail = new node;
        newtail->val = val;
        if (!size) {
            head = newtail;
            tail = newtail;
        }
        else {
            tail->next = newtail;
            tail = newtail;
        }
        size++;
        
        /*
        node *temp = new node;
        temp = head;
        while (temp != nullptr) {
            cout << temp->val;
            temp = temp->next;
        }
        cout << endl;
        cout << head->val << endl;
        cout << tail->val << endl;
        */
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (/*index < 0 || */index > size)
            return;
        if (index <= 0 ) {
            // node *newhead = new node;
            // newhead->val = val;
            // newhead->next = head;
            // head = newhead;
            addAtHead(val);
        }
        else if (index == size) {
            // node *newtail = new node;
            // newtail->val = val;
            // tail->next = newtail;
            // tail = newtail;
            addAtTail(val);
        }
        else {
            node *temp = new node;
            temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            node *newnode = new node;
            newnode->val = val;
            newnode->next = temp->next;
            temp->next = newnode;
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        if (index == 0) {
            node *temp = new node;
            temp = head;
            head = head->next;
            delete temp;
        }
        else {
            node *temp = new node;
            temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            node *deleteNode = temp->next;
            temp->next = deleteNode->next;
            if (index == size - 1)
                tail = temp;
            delete deleteNode;
        }
        size--;
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
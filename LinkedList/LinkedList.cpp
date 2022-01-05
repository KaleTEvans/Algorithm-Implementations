class Node {
    public:
    int val;
    Node *next;
    Node(int val) : val(val), next(nullptr) {}
};

class MyLinkedList {
public:
    int size = 0;
    Node *head = new Node(0);
    MyLinkedList() {
        
    }
    
    int get(int index) {
        Node *n = head->next;
        int i=0;
        while (n) {
            if (i == index) {
                return n->val;
            } else {
                i++;
                n = n->next;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node *next = head->next;
        head->next = new Node(val);
        head->next->next = next;
        size++;
    }
    
    void addAtTail(int val) {
        Node *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new Node(val);
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;
        int i=0;
        Node *prev = head;
        while (i < index) {
            i++;
            prev = prev->next;
        }
        Node *next = prev->next;
        prev->next = new Node(val);
        prev->next->next = next;
        size++;
        return;
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        Node *prev = head;
        while (prev->next) {
            if (i == index) {
                Node *next = prev->next;
                prev->next = next->next;
                next = NULL;
                size--;
                delete next;
                return;
            }
            i++;
            prev = prev->next;
        }
        return;
    }
};
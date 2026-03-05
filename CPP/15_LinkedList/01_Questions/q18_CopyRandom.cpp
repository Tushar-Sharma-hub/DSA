// 138. Copy List with Random Pointer

//1st method for interviews bcz T.C=O(n) and S.C.=O(1).
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy=new Node(0);
        Node* tempC=dummy;
        Node* temp=head;
        while(temp){ //Create a deep copy ignoring random pointer is first step.
            Node* a=new Node(temp->val);
            tempC->next=a;
            tempC=a;
            temp=temp->next;
        }
        //Now create alternative connection between og and dc.
        Node* duplicate=dummy->next;
        Node* a=head;
        Node* b=duplicate;
        dummy=new Node(-1);
        Node* tempD=dummy;
        while(a){
            tempD->next=a;
            a=a->next;
            tempD=tempD->next;
            tempD->next=b;
            b=b->next;
            tempD=tempD->next;
        }
        dummy=dummy->next;
        Node* t1=dummy;
        while(t1){ //Assign random pointer using alternaive connections.
            Node *t2=t1->next;
            if(t1->random) t2->random=t1->random->next;
            t1=t1->next->next;
        }
        //Now separate the list.
        int i=0;
        Node* d1=new Node(-1);
        Node* d2=new Node(-1);
        t1=d1;
        Node* t2=d2;
        Node* t=dummy;
        while(t){
            t1->next=t;
            t=t->next;
            t1=t1->next;
            t2->next=t;
            t=t->next;
            t2=t2->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next;
        d2=d2->next;
        return d2;
    }
};
//2nd method using map.T.C=O(n) and S.C.=O(n).
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        unordered_map<Node*, Node*> m;
        Node* t1 = head;
        Node* nh = NULL;
        Node* t2 = NULL;
        while(t1 != NULL){
            Node* t = new Node(t1->val);
            if(nh == NULL){
                nh = t;
                t2 = t;
            } 
            else{
                t2->next = t;
                t2 = t2->next;
            }
            t1 = t1->next;
        }
        t1 = head;
        t2 = nh;
        while(t1 != NULL){
            m[t1] = t2;
            t1 = t1->next;
            t2 = t2->next;
        }
        t1 = head;
        t2 = nh;
        while(t1 != NULL){
            if(t1->random != NULL)
                t2->random = m[t1->random];

            t1 = t1->next;
            t2 = t2->next;
        }
        return nh;
    }
};
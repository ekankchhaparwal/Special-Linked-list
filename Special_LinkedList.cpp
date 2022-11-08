// Special LinkedList where the centralNode is the node from where 
//the linked List diverges and Branches into two List
// I have implemented various functions to perfrom insert delete and searching in the special LinkedList
// Happy Coding !!
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next1;
    node *next2;
    node(int val)
    {
        data = val;
        next1 = NULL;
        next2 = NULL;
    }
};

void addFront(node* &head, node* &center, int val)
{
    // Addition Element at the beginning
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        center = temp;
        return;
    }
    temp->next1 = head;
    temp->next2 = head;
    head = temp;
}

void addLast(node* &head, node* &center, int data)
{
    node* temp = new node(data);
    if (head == NULL)
    {
        head = temp;
        center= temp;
        return;
    }
    node* n = head;
    while (n != center)
    {
        n = n->next1;
    }
    n->next1 = temp;
    n->next2 = temp;
    center = temp;
}


void addAtBranches(node* &center, int value1, int value2) {

    node* temp1 = new node(value1);
    node* temp2 = new node(value2);
    
    if (center == NULL) {
        cout<<"Create a New Linked List by using AddLast or AddFront function !! Happy Coding !!";
        return;
    }
    node* temp = center;
    // Insertion At Left Branch
    while (temp->next1!= NULL){
        temp = temp->next1;
    }
    temp->next1 = temp1;

    // Insertion At Right Branch
     temp = center;
    while(temp->next2!= NULL){
        temp = temp->next2;
    }
    temp->next2 = temp2;

}

void addAtCentre(node* &head,node* &center, int val) {
    node* temp = new node(val);
    if (center == NULL) {
        head = temp;
        center = temp;
        return;
    }
    temp->next1 = center->next1;
    temp->next2 = center->next2;
    center->next1 = temp;
    center->next2 = temp;
    center = temp ; 
}

void addAtMainBranch(node* &head,node* &center,int val,int index){
    node* temp = head;
    int pos = 0;
    node* newNode = new node(val);
    if(head==NULL) {
        cout<<"Create a new Linked List"<<endl;
        return ;
    }
    if (index==0) {
       addFront(head,center,val);
       return;
    }
    
    while (temp->next1 != center ) {
        if(pos==index-1){
            newNode->next1 = temp->next1->next1;             
            newNode->next2 = temp->next2->next2 ;    
            temp->next1 = newNode;
            temp->next2 = newNode;  
            return;      
        }
        temp = temp->next1;
        pos++;
    }
    addAtCentre(head,center,val);
}

void addAtSideBranch(node* &head,node* &center,int val,int index, bool leftORRight){
    node* newNode = new node(val);
    node* temp = center;
    int pos = 0;
    if(center==NULL) {
        head = NULL;
        center = NULL;
    }
    if(leftORRight){
        if(index==0) {
            addAtCentre(head, center,val);
        }
        while (temp->next1 != NULL ) {
            if(pos==index-1){
                newNode->next1 = temp->next1->next1;
                temp->next1 = newNode;
                return;            
            }
            temp = temp->next1;
            pos++;
        }
        cout<<"Index out of Left Branch for Adding"<<endl;
        
    } 
    else {
        pos==0;
        if(index==0) {
            addAtCentre(head,center,val);
            return;
        }
        while (temp->next2 != NULL ) {
            if(pos==index-1){
                newNode->next2 = temp->next2->next2;
                temp->next2 = newNode;
                return;
            }
        temp = temp->next2;
        pos++;
        
        }
        cout<<"Index out of Right Branch for Adding"<<endl;
        
    }
}

void display(node* &head,node* &center) {
    node* temp = head;
    while(temp!=center){
        cout<<temp->data<<"->";
        temp = temp->next1;
    }
    cout<<center->data<<endl;

    // Printing the Left Branch
    cout<<"Left Branch of "<<center->data<<" is: (Centre)";
     temp = center;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next1;
    }
    cout<<"END"<<endl;

    // Printing the Right Branch
    cout<<"Right Branch of "<<center->data<<" is: (Centre)";
     temp = center;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next2;
    }
    cout<<"END"<<endl;
} 

void search(node* &head,node* &center,int key) {
    node* temp = head;
    int pos = 0;
    // Searching in Main Branch

    while(temp!=center){
        if(temp->data == key){
            cout<<"Element "<<key<<"has been found at the Main Branch at position "<<pos;
            cout<<endl;
            return ;
        }
        temp = temp->next1;
        pos++;
        
    }
    
    // Searching in Left Branch
    temp = center;
    int sidePos = 1 ;
    while(temp!=NULL) {
        if(temp->data == key){
            cout<<"Element "<<key<<"has been found at position from Branching Point Node "<<sidePos<<endl;
            cout<<"Element "<<key<<"has been found at position from head Node at "<<pos<<endl;
           cout<<endl;
            return;
        }
        pos++;
        temp = temp->next1;
        
    }

    // Searching in Right Branch
    temp = center;
     sidePos = 1 ;
    while(temp!=NULL) {
        if(temp->data == key){
            cout<<"Element "<<key<<"has been found at position from Branching Point Node "<<sidePos<<endl;
            cout<<"Element "<<key<<"has been found at position from head Node at "<<pos<<endl;
           cout<<endl; return;
        }
        pos++;
        temp = temp->next2;
        
    }
    cout<<"Element Not Found in the LinkedList"<<endl;
}

int deleteHead(node* &head) {
    node* temp = head;
    if (head == NULL) {
        cout<<"Create a new Linked List"<<endl;
        return -1;
    } 
    int retrunValue = head->data;
    head = head->next1;
    delete temp;
    return retrunValue;
}

int deleteCenteralNode(node* &head,node* &center) {
    node* temp = head;
    int returnValue = center->data;
    if (head == NULL) {
        cout<<"Create a new Linked List"<<endl;
        return -1;
    }
    while(temp->next1 != center) {
        temp = temp->next1;
    }
    node* deletingNode = center;
    temp->next1 = center->next1;
    temp->next2 = center->next2;
    center = temp;
   
    delete deletingNode;
    return returnValue;
}

int deleteFromMain(node* &head,node* &center,int index) {
    node* temp = head;
    int pos = 0;
    
    if(head==NULL) {
        cout<<"Create a new Linked List"<<endl;
        return -1;
    }
    if (index==0) {
       return deleteHead(head);
    }
    
    while (temp->next1->next1 != center ) {
        if(pos==index-1){
            node* delNode = temp->next1;
            int returnValue = delNode->data;
             temp->next1 = temp->next1->next1;    
             temp->next2 = temp->next2->next2;    
             delete delNode;
             return returnValue;
                         
        }
        temp = temp->next1;
        pos++;
    }
    cout<<"Element Exceeded Use Branch Deletion Function";
    return -1;
} 

int deleteFromBranch(node* &head,node* &center,int index,bool LeftOrRight) {
    node* temp = center;
    int pos = 0;
    if(center==NULL) {
        cout<<"Create a new Linked List"<<endl;
        return -1;
    }
    if(LeftOrRight){
        if(index==0) {
            return deleteCenteralNode(head,center);
        }
        while (temp->next1 != NULL ) {
            if(pos==index-1){
                node* delNode = temp->next1;
                int returnValue = delNode->data;
                temp->next1 = temp->next1->next1;      
                delete delNode;
                return returnValue;
                            
            }
            temp = temp->next1;
            pos++;
        }
        cout<<"Index out of Left Branch "<<endl;
        return -1;
    } 
    else {
        pos==0;
        if(index==0) {
            return deleteCenteralNode(head,center);
        }
        while (temp->next2 != NULL ) {
            if(pos==index-1){
                node* delNode = temp->next2;
                int returnValue = delNode->data;
                temp->next2 = temp->next2->next2;      
                delete delNode;
                return returnValue;
            }
        temp = temp->next2;
        pos++;
        
        }
        cout<<"Index out of Right Branch "<<endl;
        return -1;
    }
}

int main()
{
    node *head = NULL;
    node *centralNode = NULL;
    addFront(head,centralNode,78);
    addFront(head,centralNode,71);
    addFront(head,centralNode,745);
    addLast(head,centralNode,34);
    addLast(head,centralNode,43);
    addLast(head,centralNode,40);
    addLast(head,centralNode,44);
    addAtBranches(centralNode,22,56);
    addAtBranches(centralNode,242,6);
    addAtBranches(centralNode,21,50);
    addAtMainBranch(head,centralNode,69,2);
    addAtMainBranch(head,centralNode,65,1);
    addAtMainBranch(head,centralNode,621,3);
    addAtSideBranch(head,centralNode,312,2,false);
    addAtSideBranch(head,centralNode,71,2,true);
    cout<<"Linkedlist is: ";
    display(head,centralNode);

    cout<<endl<<"Searching a element:\n"<<endl;
    search(head,centralNode,69);
    search(head,centralNode,312);
    search(head,centralNode,40);
    search(head,centralNode,404);

    deleteCenteralNode(head,centralNode);
    display(head,centralNode);

    deleteHead(head);
    display(head,centralNode);

    deleteFromMain(head,centralNode,1);
    deleteFromBranch(head,centralNode,1,true);
    deleteFromBranch(head,centralNode,1,false);
    display(head,centralNode);
}
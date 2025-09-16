#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    Node* child = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }

    ~Node()
    {
        cout << "Node " << this->data << endl;
        delete next;
    }
};

// next pointer
void insertAtTailNext(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
// child pointer
Node* insertAtTailChild(Node* tail,int data){
    Node* temp = new Node(data);
    tail->child = temp;
    tail = temp;
    return tail;
}

void print(Node* head){
    if(head==NULL)
        return ;
    Node* temp = NULL;
    while(head!=NULL){
        cout<<head->data;
        temp = head->child;
        while(temp!=nullptr){
            cout<<" "<<temp->data;
            temp = temp->child;
        } 
        cout<<" -> ";
        head = head->next;
    }
    cout<<endl;
    
    return;
}


Node* merge(Node* head,Node* right){
	if(head==nullptr) return right;
	if(right==nullptr) return head;

	Node* result = nullptr;
	Node* tail = result;
	
	Node* temp = head;
	Node* temp2 = right;
	
	while(temp!=nullptr && temp2!=nullptr){
		if(temp->data < temp2->data){
			if(result==nullptr){
				result = temp;
				tail = result;
				temp = temp->child;
			} else{
				tail->child = temp;
				tail = temp;
				temp = temp->child;
			}
		} else {
			if(result==nullptr){
				result = temp2;
				tail = result;
				temp2 = temp2->child;
			} else{
				tail->child = temp2;
				tail = temp2;
				temp2 = temp2->child;
			}
		}
	}
	if(temp!=nullptr){
		tail->child = temp;
	}
	if(temp2!=nullptr){
		tail->child = temp2;
	}

	return result;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==nullptr || head->next==nullptr)
		return head;
	
	Node* right = head->next;
	head->next = nullptr;

	right = flattenLinkedList(right);
	
	Node* ans = nullptr;
	ans = merge(head,right);

	return ans;
}

int main(){
    Node* head = new Node(2);
    Node* tail = head;
    
    insertAtTailNext(tail,3);
    Node* childTail = insertAtTailChild(tail,5);
    childTail = insertAtTailChild(childTail,6);
    childTail = insertAtTailChild(childTail,9);
    
    insertAtTailNext(tail,8);
    childTail =insertAtTailChild(tail,11);
    childTail = insertAtTailChild(childTail,43);
    childTail = insertAtTailChild(childTail,50);
    
    insertAtTailNext(tail,10);
    childTail = insertAtTailChild(tail,15);
    childTail = insertAtTailChild(childTail,23);
    
    insertAtTailNext(tail,17);
    
    insertAtTailNext(tail,19);
    childTail = insertAtTailChild(tail,20);

    print(head);
    Node* ans = flattenLinkedList(head);
    print(head);
}
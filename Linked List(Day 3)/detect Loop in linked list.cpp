#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cout<<"Enter elements(-1 to stop): "<<endl;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

bool detectLoop(Node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return false;
    }
    Node* slow=head,*fast=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

void removeLoop(Node *head)
{
    if(head==NULL || head->next==NULL)
        return;
    Node *slow =head,*fast=head;
    bool looppresent=false;
    while(head!=NULL && fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            looppresent=true;
            break;
        }
    }
    if(looppresent)
    {
        slow=head;
        if(slow==fast)
        {
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
        }
        else
        {
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        fast->next=NULL;
    }
}

int main()
{
    Node *head=takeinput();
    cout<<detectLoop(head)<<endl;
    print(head);
    removeLoop(head);
    print(head);
}


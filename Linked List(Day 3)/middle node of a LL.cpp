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

Node *midPoint1(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=slow->next;
    }
    return slow;
}

Node *midPoint(Node *head)
{
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    int mid=(cnt-1)/2;
    for(int i=0;i<mid;i++)
        head=head->next;
    return head;

}

Node *takeinput()
{
	int data;
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

int main()
{
    Node *head = takeinput();
    Node *mid = midPoint(head);
    if (mid != NULL)
    {
        cout << mid->data;
    }
    cout << endl;
}

#include <bits/stdc++.h>
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
Node *oddAfterEven(Node *head)
{
	if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *temp=head;
    Node *evenhead=NULL;
    Node *oddhead=NULL;
    Node *eventail=NULL;
    Node *oddtail=NULL;
    while(temp!=NULL)
    {
        if(temp->data%2!=0)
        {
        	if(oddhead==NULL)
            {
                oddhead=temp;
                oddtail=temp;
            }
            else
            {
                oddtail->next=temp;
                oddtail=temp;
            }
        }
        if(temp->data%2==0)
        {
        	if(evenhead==NULL)
            {
                evenhead=temp;
                eventail=temp;
            }
            else
            {
                eventail->next=temp;
                eventail=temp;
            }
        }
        temp=temp->next;
    }
    if(evenhead==NULL)
        return oddhead;
    else
    {
        if(evenhead!=NULL)
        {
            eventail->next=oddhead;
            oddtail->next=NULL;
            return evenhead;
        }
        else
        {
            eventail->next=NULL;
            return evenhead;
        }
    }

}
Node *evenAfterOdd(Node *head)
{
	if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *temp=head;
    Node *evenhead=NULL;
    Node *oddhead=NULL;
    Node *eventail=NULL;
    Node *oddtail=NULL;
    while(temp!=NULL)
    {
        if(temp->data%2!=0)
        {
        	if(oddhead==NULL)
            {
                oddhead=temp;
                oddtail=temp;
            }
            else
            {
                oddtail->next=temp;
                oddtail=temp;
            }
        }
        if(temp->data%2==0)
        {
        	if(evenhead==NULL)
            {
                evenhead=temp;
                eventail=temp;
            }
            else
            {
                eventail->next=temp;
                eventail=temp;
            }
        }
        temp=temp->next;
    }
    if(oddhead==NULL)
        return evenhead;
    else
    {
        if(evenhead!=NULL)
        {
            oddtail->next=evenhead;
            eventail->next=NULL;
            return oddhead;
        }
        else
        {
            oddtail->next=NULL;
            return oddhead;
        }
    }

}

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

int main()
{
    Node *head = takeinput();
    //Node* head1 = oddAfterEven(head);
    Node* head2 = evenAfterOdd(head);
    //print(head1);
    cout<<endl;
    print(head2);
}

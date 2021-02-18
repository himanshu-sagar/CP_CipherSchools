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

Node *reverseLinkedListRec(Node *head)// O(n^2)
{
    if(head==NULL || head->next==NULL)
        return head;

    Node *smallout=reverseLinkedListRec(head->next);
    Node *temp=smallout;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=head;
    head->next=NULL;
    return smallout;
}
Node *reverseLinkedListRec_best(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node *smallout=reverseLinkedListRec_best(head->next);
    Node *tail=head->next;
    tail->next=head;
    head->next=NULL;
    return smallout;
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
    head = reverseLinkedListRec(head);
    head = reverseLinkedListRec_best(head);
    print(head);
}

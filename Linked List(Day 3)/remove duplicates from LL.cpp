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


Node *removeDuplicates(Node *head)
{
    if(head==NULL)
    {
        return head;
    }
    Node *temp1=head;
    while(head->next!=NULL)
    {
        if(head->next->data==head->data)
        {
            Node *temp=head->next;
            head->next=temp->next;
            delete []temp;
        }
        else
        {
            head=head->next;
        }
    }

    return temp1;
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
    head = removeDuplicates(head);
    print(head);
}

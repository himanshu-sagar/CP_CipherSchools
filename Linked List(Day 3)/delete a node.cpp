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

Node* deleteNode(Node *head,int i)
{
    Node *temp=head;
    int n=0;
    if(i==0)
    {
        temp=head->next;
        delete head;
        return temp;
    }
    while(temp->next!=NULL && n<i-1)
    {
        temp=temp->next;
        n++;
    }
    if(temp->next!=NULL)
    {
        Node *temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }


    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);


}

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

Node* reverseLinkedListInGroups(Node *head,int k)
{
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    Node* curr=head,*next=NULL,*prev=NULL;
    int cnt=0;
    while(curr!=NULL && cnt<k)
    {
        cnt++;
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    if(next!=NULL)
    {
        head->next=reverseLinkedListInGroups(next,k);
    }
    return prev;
}

int main()
{
    Node *head=takeinput();
    head=reverseLinkedListInGroups(head,3);
    print(head);
}


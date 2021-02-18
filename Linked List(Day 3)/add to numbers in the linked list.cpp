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
Node *takeinput()
{
	int data;
	cout<<"Enter elements(Enter -1 for last node): "<<endl;
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

Node *addNumbers(Node* head1,Node* head2)
{
    Node* head3=NULL;
    Node* tail=NULL;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    int carry=0;
    int newdata=0;
    while(head1!=NULL || head2!=NULL)
    {

        int sum=carry+(head1 ? head1->data:0)+(head2 ? head2->data:0);
        carry=(sum>=10)?1:0;
        newdata=sum%10;
        Node *newnode=new Node(newdata);
        if(head3==NULL)
        {
            head3=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        if(head1)
            head1=head1->next;
        if(head2)
            head2=head2->next;
    }
    if(carry>0)
    {
        Node* newnode=new Node(carry);
        head3->next=newnode;
    }
    return head3;
}

int main()
{
	Node *head1=takeinput();
	Node *head2=takeinput();
	cout<<endl;
	Node *head3=addNumbers(head1,head2);
	print(head3);
}

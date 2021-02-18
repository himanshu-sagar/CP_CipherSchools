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

Node* ReverseLL(Node* head)
{
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL)
    {
        Node *tempnext=curr->next;
        curr->next=prev;
        prev=curr;
        curr=tempnext;
    }
    head=prev;
    return prev;
}
bool isPalindrome(Node *head)
{
    Node *head1=ReverseLL(head);
    bool flag=true;
    while(head!=NULL)
    {

        if(head->data != head1->data)
        {
            flag=false;
            break;
        }
        head=head->next;
        head1=head1->next;
    }

    if(flag)
    	return true;
    else
        return false;

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
    bool ans = isPalindrome(head);

    if (ans) cout << "true";
    else cout << "false";

    cout << endl;
}

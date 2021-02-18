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


int findNode(Node *head, int n)
{
    int i=0;
    bool flag=false;
    while(head!=NULL)
    {
        if(head->data==n)
        {
            flag=true;
            break;
        }
        head=head->next;
        i++;
    }
    if(flag==true)
        return i;
    else
    {
        return -1;
    }
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

int main()
{
    Node *head = takeinput();
    int val;
    cin >> val;
    cout << findNode(head, val) << endl;
}

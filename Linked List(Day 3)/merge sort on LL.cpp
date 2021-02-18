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
Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    //Write your code here
    Node* finalhead=NULL;
    Node* finaltail=NULL;

    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    if(h1->data<=h2->data)
        {
            finalhead=h1;
            finaltail=h1;
        	h1=h1->next;
        }
        else
        {
            finalhead=h2;
            finaltail=h2;
            h2=h2->next;
        }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<=h2->data)
        {
            finaltail->next=h1;
            finaltail=h1;
            h1=h1->next;
        }
        else
        {
            finaltail->next=h2;
            finaltail=h2;
            h2=h2->next;
        }
    }
    if(h1==NULL)
    {
        finaltail->next=h2;
    }
    else
    {
        finaltail->next=h1;
    }
    return finalhead;
}
void *split(Node *start,Node **ll1,Node **ll2)
{
    Node* slow = start;
   	Node* fast = start -> next;
   while(fast!= NULL) {
      fast = fast -> next;
      if(fast!= NULL) {
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   *ll1 = start;
   *ll2 = slow -> next;
   slow -> next = NULL;
}
Node *mergeSort(Node *head1)
{
	Node* head = head1;
   Node* ll1,*ll2;

   if(head == NULL || head->next == NULL) {
      return head;
   }
   split(head,&ll1,&ll2);

   ll1=mergeSort(ll1);
   ll2=mergeSort(ll2);

   head = mergeTwoSortedLinkedLists(ll1,ll2);
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
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	}

	return 0;
}

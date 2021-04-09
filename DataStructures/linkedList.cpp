#include "linkedList.h"

void delete_recursive(Node **head_ptr, int index)
{
    Node *head = *head_ptr;
    if(NULL == head)
        return;

    if(0 == index)
    {
        Node *temp = head;
        head = head-> next;
        delete temp;
        *head_ptr = head;
        return;
    }
    delete_recursive(&head->next, index-1);
}

void insert_recursive(Node **head_ptr, int index, int data)
{
    Node* head = *head_ptr;

    if(head == NULL)
        return;
    if(0 == index)
    {
        Node *n = new Node(data);
        n->next = head;
        *head_ptr = n;
    }
    insert_recursive(&head->next, index-1, data);
}

int ll_len(Node *head)
{
    if (NULL == head)
        return 0;
    return( 1 + ll_len(head-> next));
}

void print_ll(Node *head_ptr)
{
    if(NULL == head_ptr)
    {
        cout<< endl;
        return;
    }
    cout<< head_ptr-> data<< " ";
    print_ll(head_ptr-> next);
}

/*take input to form a linked list*/
Node* takeInput() {

    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(-1 != data) {
    
        Node *n = new Node(data);
        if (NULL == head) {
            head = n;
            tail = n;
        }
        else {
            tail -> next = n;
            tail = n;
        }

        cin >> data;
    }

    return head;
}

int getNode(Node *head, int index)
{
    if(head == NULL)
        return -1;
    if(0 == index)
    {
        return head-> data;
    }
    getNode(head->next, index-1);
}

/*Return the mid element of a list*/
int mid(Node *head)
{
    Node *slow = head;
    Node * fast = head-> next;
    while ((NULL != fast) && (NULL != fast->next)) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow-> data;
}

int main()
{
    int ind = -1;
    Node *head = takeInput();
    print_ll(head);

    /*length of the linked List*/
    cout << "Length = " << ll_len(head) << endl;

    /*find the mid element*/
    cout << mid(head) << endl;

    /*Insert a node at ith index*/
    cout << "Enter the index to insert a node: ";
    cin >> ind;
    
    int data;
    cout << endl<<"Enter data to insert at this node:";
    cin >> data;

    insert_recursive(&head, ind, data);
    cout << endl << "Modified LL:";
    print_ll(head);


    /*Delete a node from ith index*/
    cout << "Enter the index to delete: ";
    cin >> ind;
    delete_recursive(&head, ind);
    print_ll(head);
}

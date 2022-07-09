#include <iostream>
using namespace ::std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class circularlinkedList
{

public:
    Node *head;
    circularlinkedList()
    {
        head = NULL;
    }

    // this checks whether the node exists in the given linked list using the unique value key
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }
    //append the node in the last of circular linked list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value :" << n->key << endl;
            cout << " try with another key" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head; //points back itself
                cout << "Node appended at the first position" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                cout << "Node appended" << endl;
            }
        }
    }

    //prepend the node at the start of linked list
    void prependNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value :" << n->key << endl
                 << "try with another key" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head; //points back itself
                cout << "Node prepended at the first position" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                head = n;
                cout << "Node prepended" << endl;
            }
        }
    }

    //Insert the node after a given Node in Linked list by key
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node Exists with key value : " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value :" << n->key << endl
                     << "try with another key" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    n->next = head;
                    ptr->next = n;
                    cout << "Node inserted at the end" << endl;
                }
                else
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node Inserted in between" << endl;
                }
            }
        }
    }

    // Deleting the node by using the unique key
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node Exists with key value : " << k << endl;
        }
        else
        {
            if (ptr == head) //check if its the first node of the list
            {
                if (head->next == head)
                {
                    head = NULL;
                    cout << " Head node is unlinked from the list" << endl;
                    // this is diffrent from deleting here we are unlinking it so it cannot be accesed using the list ,the whole node
                }
                else
                {
                    Node *ptr1 = head;
                    while (ptr1->next != head)
                    {
                        ptr1 = ptr1->next;
                    }
                    ptr1->next = head->next;
                    head = head->next;
                    cout << "Node unlinked with the key value " << k << endl;
                }
            }
            else
            {
                Node *temp = NULL; //the given node is not the head of list
                Node *prevptr = head;
                Node *currentptr = head->next;
                while (currentptr != NULL)
                {

                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                prevptr->next = temp->next;
                cout << "Node unlinked from the list by key value " << k << endl;
            }
        }
    }

    // Update the node using a key
    void
    UpdateNodeByKey(int k, int new_d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = new_d;
            cout << "Node is Updated Successfully" << endl;
        }
        else
        {
            cout << "Node Does not exist with the given value of key: " << k << endl;
        }
    }

    //displaying or printing the entire linked list
    void printList()
    {
        if (head == NULL)
        {
            cout << "THE list is empty No Node is added " << endl;
        }
        else
        {
            cout << "the Head address" << head << endl;
            cout << "The circular Linked List values :" << endl;
            Node *temp = head;
            do
            {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ")-->";
                temp = temp->next;
            } while (temp != head);
        }
    }
};

int main()
{
    circularlinkedList c;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "*********************************************************************************" << endl;
        cout << "What operation do you wish to perform on circular linked list!!! Press 0 to exit!!!!" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. UpdateNodeByKey()" << endl;
        cout << "6. printList()" << endl;
        cout << "7.clearScreen()" << endl;
        cout << "**********************************************************************************" << endl;

        cin >> option;
        Node *n1 = new Node(); //Dynamic memory allocation and it is availabele after each iteration

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << " Enter the key and data for new node to be appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            c.appendNode(n1);
            cout << " " << n1->key << " , " << n1->data << "-->" << endl;
            break;

        case 2:
            cout << "Enter the key and data for new node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            c.prependNode(n1);
            cout << " " << n1->key << " , " << n1->data << "-->" << endl;
            break;

        case 3:
            cout << "Enter the Key after which you want to insert the New Node" << endl;
            cin >> k1;
            cout << "Enter the key and data for new node to be inserted" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            c.insertNodeAfter(k1, n1);
            cout << " " << n1->key << " , " << n1->data << "-->" << endl;
            break;

        case 4:
            cout << "Enter the key of Node Which you want to delete " << endl;
            cin >> k1;
            c.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Enter the key and the New data to be update in the node of the list" << endl;
            cin >> key1;
            cin >> data1;
            c.UpdateNodeByKey(key1, data1);
            break;
        case 6:
            c.printList();
            break;
        case 7:
            system("cls");

            break;
        default:
            cout << "Enter proper Option" << endl;
        }
    } while (option != 0);
    return 0;
}

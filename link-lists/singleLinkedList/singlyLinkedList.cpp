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

class singlyLinkedList
{

public:
    Node *head;
    singlyLinkedList()
    {
        head = NULL;
    }
    singlyLinkedList(Node *n)
    {
        head = n;
    }
    // this checks whether the node exists in the given linked list using the unique value key
    Node* nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    //append the node in the last of singly linked list
    void appendNode(Node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout<< "Node already exists with key value :" << n->key << endl;
             cout<< " try with another key" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout<< "Node appended"<< endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
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
            n->next = head;
            head = n;
            cout << "Node Prepended " << endl;
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
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
        }
    }

    // Deleting the node by using the unique key
    void deleteNodeByKey(int k)
    {

        if (head == NULL)
        {
            cout << "Singly Linked list already empty, Cannot delete any values" << endl;
        }
        else if (head!=NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << " Starting Node with key value:  " << k << " is unlinked from list" << endl;
                // this is diffrent from deleting here we are unlinking it so it cannot be accesed using the list ,the whole node
            }

            else
            {
                Node *temp = NULL;
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
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node Unlinked with Key value" << k << endl;
                }
                else
                {
                    cout << "The given key value does not exist" << k << endl;
                }
            }
        }
    }
    // Update the node using a key
    void UpdateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr!=NULL)
        {
            ptr->data = d;
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
        if (head==NULL)
        {
            cout << "THE list is empty No Node is added " << endl;
        }
        else
        {
            cout << "The singly Linked List values :";
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << " , " << temp->data << ")-->";
                temp = temp->next;
            }
        }
    }
};

int main()
{
    singlyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "*********************************************************************************" << endl;
        cout << "What operation do you wish to perform on singly linked list!!! Press 0 to exit!!!!" << endl;
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
            case 0 : 
            break;
            case 1 :
             cout << "Enter the key and data for new node to be appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            cout << " " << n1->key << " , " << n1->data << "-->"<<endl;
            break;

            case 2 : cout << "Enter the key and data for new node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            cout << " " << n1->key << " , " << n1->data << "-->"<<endl;
            break;

            case 3 : cout << "Enter the Key after which you want to insert the New Node" << endl;
            cin >> k1;
            cout << "Enter the key and data for new node to be inserted" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1, n1);
            cout << " " << n1->key << " , " << n1->data << "-->"<<endl;
            break;

        case 4:
            cout << "Enter the key of Node Which you want to delete " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Enter the key and the New data to be update in the node of the list" << endl;
            cin >> key1;
            cin >> data1;
            s.UpdateNodeByKey(key1, data1);
            break;
        case 6:
            s.printList();
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

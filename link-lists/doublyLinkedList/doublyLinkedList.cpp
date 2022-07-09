#include <iostream>
using namespace ::std;

class Node
{

public:
    int key;
    int data;
    Node *previous;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        previous = NULL;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        previous = NULL;
        next = NULL;
    }
};

class doublyLinkedList
{

public:
    Node *head;
    doublyLinkedList()
    {
        head = NULL;
    }
    doublyLinkedList(Node *n)
    {
        head = n;
    }

    //1. check if node exists with a key
    Node *nodeExists(int k)
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

    //2. Append a node to the list
    void appendNode(Node *n)
    {

        if (nodeExists(n->key)) //to view whether to use NULL here
        {
            cout << "The Node already exists with key " << n->key << " try another node with diffrent key" << endl;
        }
        else if (head == NULL)
        {
            head = n;
            cout << "Node Appended " << endl;
        }
        else if (head != NULL)
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->previous = ptr;
            cout << "Node Appended " << endl;
        }
    }

    //3. Prepend the Node to the list
    void prependNode(Node *n)
    {
        if (nodeExists(n->key)) //to view whether to use NULL here
        {
            cout << "The Node already exists with key " << n->key << " try another node with diffrent key" << endl;
        }
        else if (head == NULL)
        {
            head = n;
            cout << "Node prepended " << endl;
        }
        else
        {
            head->previous = n;
            n->next = head;
            head=n;
            cout << "Node prepended " << endl;
        }
    }

    //4 Inserting a Node after a given node with key
    void insertNodeAfter(int k, Node *n)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with that value" << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node cannot be inserted as key of node is already used" << endl;
            }
            else
            {
                cout << "INSERTING THE NODE" << endl;

                Node *nextNode = ptr->next;
                if (nextNode == NULL)
                {
                    //indicates the end of the list appending
                    ptr->next = n;
                    n->previous = ptr;
                    cout << "Node inserted at the end" << endl;
                }
                else
                {
                    //insertion in between
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }

    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with that value" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next; // point to ponder if code does not execute
                cout << "Node deleted at the start of the list" << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->previous;
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "Node deleted at the end of the list" << endl;
                }
                else
                {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    cout << "Node deleted between the list" << endl;
                }
            }
        }
    }

    void updateNodeByKey(int k, int d)
    {

        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No Node exists with the key " << k << endl;
        }
        else
        {
            ptr->data = d;
            cout << "Node with key " << k << " is updated with new data " << d << endl;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "The doubly linked list  is empty " << endl;
        }
        else
        {
            cout << "Doubly link list values: " << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ")"<< "<---->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }


};

int main()
{
      doublyLinkedList d;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "*********************************************************************************" << endl;
        cout << "What operation do you wish to perform on Doubly linked list!!! Press 0 to exit!!!!" << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. UpdateNodeByKey()" << endl;
        cout << "6. printList()" << endl;
        cout << "7.clearScreen()" << endl;
        cout << "**********************************************************************************" << endl;

        cin >> option;
        Node* n1 = new Node(); //Dynamic memory allocation and it is availabele after each iteration

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
            d.appendNode(n1);
            cout << "(" << n1->key << "," << n1->data << ")<-->"<<endl;
            break;

            case 2 : cout << "Enter the key and data for new node to be prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.prependNode(n1);
            cout << "(" << n1->key << "," << n1->data << ")<-->"<<endl;
            break;

            case 3 : cout << "Enter the Key after which you want to insert the New Node" << endl;
            cin >> k1;
            cout << "Enter the key and data for new node to be inserted" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            d.insertNodeAfter(k1, n1);
            cout << "(" << n1->key << "," << n1->data << ")<-->"<<endl;
            break;

        case 4:
            cout << "Enter the key of Node Which you want to delete " << endl;
            cin >> k1;
            d.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Enter the key and the New data to be update in the node of the list" << endl;
            cin >> key1;
            cin >> data1;
            d.updateNodeByKey(key1, data1);
            break;
        case 6:
            d.printList();
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
#include <iostream>

struct ListNode
{
    int       value;
    ListNode* next;
    ListNode* prev;

    /* 
     * Member initializer list
     * Initialize the data member of a class or strut before the body of the constructor executes
     */
    ListNode(int x): value(x), next(nullptr), prev(nullptr) {}
};

/* Global head pionter */
ListNode* head = nullptr;

int DeleteNode(ListNode* node)
{
    /* Function to delete a node */

    /* Check if either node or the head exits */
    if ((node == nullptr) || (head == nullptr))
    {
        return 1;
    }

    /* If only one node in the list */
    if(node == head->next)
    {
        delete head;
        head = nullptr;
        return 0;
    }

    /* Change the prev and next pointers and delete the node */
    node->prev->next = node->next;
    node->next->prev = node->prev;

    if (node == head)
    {
        head = node->next;
    }

    delete node;
    return 0;
}

int InsertNode(int data, int index)
{
    /* Function to insert a node into a given index */

    int count = 0;

    /* Create a node */
    ListNode* node = new ListNode(data);
    if (node == nullptr)
    {
        return 1;
    }

    /* If the list is empty */
    if (head == nullptr)
    {
        node->next = node;
        node->prev = node;
        head = node;
        return 0;
    }

    /* If node is inserted in the begining */
    if (index == 0)
    {
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
        head = node;
        return 0;
    }

    /* Traverse the list to find the index */
    ListNode* temp = head;
    while (temp->next != head)
    {
        if (count == index)
        {
            break;
        }
        temp = temp->next;
        count++;
    }
    // 0 -> x -> 0
    
    /* Insert the new node */
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node;
    temp->next = node;

    return 0;
}

void PrintList(void)
{
    /* Function to print the list */

    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    ListNode* current = head;
    do {
        std::cout << current->value << " <-> ";
        current = current->next;
    } while (current != head);

    std::cout << "(back to head)" << std::endl;
}


void LinkedListMain(void)
{
    /* Main function to test the linked list */

    /* Insert nodes */
    InsertNode(1, 0);  // Insert 1 at position 0
    InsertNode(2, 1);  // Insert 2 at position 1
    InsertNode(3, 2);  // Insert 3 at position 2
    InsertNode(0, 0);  // Insert 0 at position 0 (new head)

    /* Print the list */
    PrintList();

    /* Delete the head node */
    std::cout << "Deleting head node..." << std::endl;
    DeleteNode(head);
    PrintList(); // Expected: 1 <-> 2 <-> 3 <-> (back to head)

    /* Delete a middle node */
    std::cout << "Deleting node with value 2..." << std::endl;
    DeleteNode(head->next);
    PrintList(); // Expected: 1 <-> 3 <-> (back to head)

    /* Print the list */
    PrintList();
}



    

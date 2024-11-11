#include <iostream>
#include <string>

using namespace std;

/*
 * Problem Statement:
 * You are tasked with building a Task Management System for an ML Accelerator firmware that manages tasks with 
 * unique string IDs, integer priorities, and a data payload representing either a memory address or a data operation.
 *
 * Each task consists of:
 * - A string ID that uniquely identifies the task.
 * - An int priority level. Higher numbers indicate higher priority.
 * - A string data payload representing either:
 *  - A valid memory address: 
 *   - This must be a string in the format "0x..." or "0X..." followed by valid hexadecimal characters (0-9, A-F, a-f). 
 *     For example, "0x1A3F" or "0xBEEF" are valid memory addresses.
 *  - A valid data operation: 
 *   - This must be either "Read from Memory" or "Write to Register".
 *
 * Objectives:
 * - Implement a Task class that includes methods to:
 * - Check if the data payload is a valid memory address.
 * - Check if the data payload is a valid data operation.
 * - Implement a PriorityQueue class that manages these tasks using a custom linked list, sorted in descending order of 
 *   priority.
 * - Write methods to enqueue and dequeue tasks, and a method to print the current content of the queue.
 *
 * Example:
 * - If you enqueue tasks with the following details:
 *   Task("Task_1", 2, "0x1A3F") → Valid memory address
 *   Task("Task_2", 5, "Write to Register") → Valid data operation
 *   Task("Task_3", 3, "0xBEEF") → Valid memory address
 *   Task("Task_4", 5, "Read from Memory") → Valid data operation
 *   The queue will maintain the order based on priority: 5 -> 5 -> 3 -> 2.
 *
 * Definitions:
 * - Valid Memory Address:
 *  - A string that starts with "0x" or "0X" followed by one or more valid hexadecimal characters (0-9, A-F, a-f).
 *    Examples: "0x1A3F", "0xBEEF", "0xABC123".
 * - Valid Data Operation:
 *  - Must be one of the following two strings: "Read from Memory" or "Write to Register".
 *
 * Constraints:
 * - Assume all task IDs are unique and provided correctly.
 * - Your task is to implement the classes and methods to manage and validate tasks as described.
 */

class Task
{
    public:
        string id;
        string payload;
        int    priority;

        /* Constructor */
        Task(const string id, const string payload, int priority) : id(id), payload(payload), priority(priority) {}

        /* Methods */
        bool isValidMemoryAddress(void) const;
        bool isDataOperation(void) const;
};

bool Task::isValidMemoryAddress(void) const
{
    if (payload.length() < 3 || payload[0] != '0' || (payload[1] != 'x' && payload[1] != 'X')) 
    {
        return false;
    }
    
    for (size_t i = 2; i < payload.length(); ++i) // ++i is more efficient than i++
    {
        char c = payload[i];
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) 
        {
            return false;
        }
    }

    return true;
}

bool Task::isDataOperation(void) const
{
     return (payload == "Read from Memory" || payload == "Write to Register");
}

class PriorityQueue
{
    private:
        class Node
        {
            public:
                Task *task;
                Node *next;
                
                /* Constructor */
                Node(Task *task) : task(task), next(nullptr) {}
        };

        /* Pointer to the head of the node */
        Node *head;
    
    public:
        /* Constructor */
        PriorityQueue() : head(nullptr) {}
        
        /* Methods */
        bool isEmpty(void) const;
        void enqueue(Task *newTask);
        Task* dequeue(void);
        void printQueue(void) const;

        /* Destructor */
        ~PriorityQueue()
        {
            while(head)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
        }
};

bool PriorityQueue::isEmpty(void) const
{
    return (head == nullptr);
}

void PriorityQueue::enqueue(Task *newTask)
{
    Node* newNode = new Node(newTask);
    if (newNode != nullptr)
    {
        if ((head == nullptr) || (head->task->priority < newTask->priority))
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        
        while((current->next != nullptr) && (current->next->task->priority >= newTask->priority))
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;

        return;
    }
    else
    {
        cout << "Memory allocation failed for new task." << endl;
    }
}

Task* PriorityQueue::dequeue(void)
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
        return nullptr;
    }
    else
    {
        Node* temp = head;
        Task* task = head->task;
        head = head->next;
        delete temp;
        return task;
    }
}

void PriorityQueue::printQueue(void) const
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        Node* current = head;
        while(current != nullptr)
        {
            cout << "Task ID: "    << current->task->id
                 << ", Priority: " << current->task->priority
                 << ", Data: "     << current->task->payload << endl;
            current = current->next;
        }
    }
}

void PriorityQueueMain(void)
{
    PriorityQueue queue;

    /* Enqueue tasks */
    queue.enqueue(new Task("Task_1", "0x1A3F", 2));
    queue.enqueue(new Task("Task_2", "Write to Register", 5));
    queue.enqueue(new Task("Task_3", "0xBEEF", 3));
    queue.enqueue(new Task("Task_4", "Read from Memory", 5));

    /* Print the current content of the queue */
    queue.printQueue();

    /* Dequeue and process tasks */
    while (!queue.isEmpty()) 
    {
        Task *task = queue.dequeue();
        std::cout << "Processing Task ID: " << task->id
                  << ", Priority: "         << task->priority
                  << ", Data: "             << task->payload << std::endl;

        /* Validate the data payload */
        if (task->isValidMemoryAddress()) 
        {
            std::cout << "  - This is a valid memory address." << std::endl;
        } 
        else if (task->isDataOperation()) 
        {
            std::cout << "  - This is a recognized data operation." << std::endl;
        } 
        else 
        {
            std::cout << "  - Invalid data payload." << std::endl;
        }

        /* Clean up the task object */
        delete task;
    }
}
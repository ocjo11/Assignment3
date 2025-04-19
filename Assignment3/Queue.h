#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t queueSize;

    // Recursive helper function to find last occurrence
    int find_last_occurrence(Node* current, const T& target, int current_pos, int last_found) const
    {
        if (current == nullptr)
            return last_found;

        if (current->data == target)
            last_found = current_pos;

        return find_last_occurrence(current->next, target, current_pos + 1, last_found);
    }

public:
    // Constructor
    Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    // Destructor
    ~Queue()
    {
        while (!empty())
        {
            pop();
        }
    }

    // Copy constructor
    Queue(const Queue<T>& other) : frontNode(nullptr), rearNode(nullptr), queueSize(0)
    {
        Node* current = other.frontNode;
        while (current)
        {
            push(current->data);
            current = current->next;
        }
    }


    // Push element to the rear of the queue
    void push(const T& value)
    {
        Node* newNode = new Node(value);
        if (empty())
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    // Remove element from the front of the queue
    void pop()
    {
        if (empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
        if (empty())
        {
            rearNode = nullptr;
        }
    }

    // Get the front element
    T& front()
    {
        if (empty())
        {
            throw std::runtime_error("Queue is empty");
        }
        return frontNode->data;
    }

    // Get the size of the queue
    size_t size() const
    {
        return queueSize;
    }

    // Check if the queue is empty
    bool empty() const
    {
        return queueSize == 0;
    }

    // Move front element to the rear
    void move_to_rear()
    {
        if (size() <= 1)
        {
            return; // No effect if queue is empty or has only one element
        }
        push(front()); // Copy front element to rear
        pop();         // Remove original front element
    }

    // Public function to find last occurrence
    int find_last_occurrence(const T& target) const
    {
        return find_last_occurrence(frontNode, target, 0, -1);
    }

    void insertion_sort() {
        if (frontNode == nullptr || frontNode->next == nullptr)
            return; // Empty or single element queue

        Node* sorted = nullptr; // New sorted linked list
        Node* current = frontNode;

        while (current != nullptr) {
            Node* next = current->next;

            // Insert current in sorted list
            if (sorted == nullptr || current->data < sorted->data) {
                current->next = sorted;
                sorted = current;
            }
            else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }

            current = next;
        }

        // Update frontNode and rearNode
        frontNode = sorted;
        rearNode = frontNode;
        queueSize = 1; // Reset size, we'll count it

        while (rearNode->next != nullptr) {
            rearNode = rearNode->next;
            queueSize++;
        }
    }

};
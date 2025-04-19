#include "Queue.h"

// created with assitance of both chat gpt and deepseek LLMS
int main()
{
    // a) Instantiate the queue with integers and push 10 values
    Queue<int> q;
    cout << "Pushing values 1 through 10 into the queue...\n";
    for (int i = 1; i <= 10; ++i)
    {
        q.push(i);
    }

    // b) Comprehensive demonstration of all queue functions
    cout << "\n=== Demonstrating Queue Functions ===\n";

    // 1. Show size()
    cout << "1. Current queue size: " << q.size() << endl;

    // 2. Show empty()
    cout << "2. Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    // 3. Show front()
    cout << "3. Front element: " << q.front() << endl;

    // 4. Demonstrate move_to_rear()
    cout << "4. Moving front element to rear...\n";
    q.move_to_rear();
    cout << "   New front element: " << q.front() << endl;

    // 5. Display all elements using queue operations
    cout << "5. Current queue contents (using front/move_to_rear):\n   ";
    size_t currentSize = q.size();
    for (size_t i = 0; i < currentSize; ++i)
    {
        cout << q.front() << " ";
        q.move_to_rear();
    }
    cout << endl;

    // 6. Demonstrate pop()
    cout << "6. Popping the front element (" << q.front() << ")...\n";
    q.pop();
    cout << "   New front element: " << q.front() << endl;
    cout << "   New queue size: " << q.size() << endl;

    // Show final queue state
    cout << "\nFinal queue contents:\n";
    currentSize = q.size();
    for (size_t i = 0; i < currentSize; ++i)
    {
        cout << q.front() << " ";
        q.move_to_rear();
    }
    cout << endl;

    // Create and populate new queue
    Queue<int> q2;
    cout << "\n=== Demonstrating Sort and Find Functions ===";
    cout << "\nPushing values into new queue: 2, 5, 3, 7, 5, 9, 1, 5, 4\n";
    int values[] = { 2, 5, 3, 7, 5, 9, 1, 5, 4 };
    for (int val : values)
    {
        q2.push(val);
    }

    // Display queue contents
    cout << "\nQueue contents: ";
    Queue<int> temp = q2; // Copy for display
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Search for last occurrence of 5
    int target = 5;
    int last_pos = q2.find_last_occurrence(target);

    if (last_pos != -1)
    {
        cout << "\nLast occurrence of " << target << " is at position " << last_pos
            << " (0-based index)\n";

        // Find and display the actual value
        Queue<int> temp_q = q2;
        int current_pos = 0;
        while (current_pos < last_pos)
        {
            temp_q.pop();
            current_pos++;
        }
        cout << "Value at position " << last_pos << ": " << temp_q.front() << endl;
    }
    else
    {
        cout << target << " not found in the queue\n";
    }

    // Sorting linked list
    cout << "Before sorting: ";
    Queue<int> tmp = q2;
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;

    q2.insertion_sort();

    cout << "After sorting: ";
    Queue<int> temp_q = q2;
    while (!temp_q.empty()) {
        cout << temp_q.front() << " ";
        temp_q.pop();
    }
    cout << "\nQueue Size: " << q2.size() << endl;


    return 0;
}
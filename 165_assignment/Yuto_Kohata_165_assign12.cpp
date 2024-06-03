#include <bits/stdc++.h>

using namespace std;

// 1. Define the structure for a linked list node
struct LinkedList {
    int value;
    LinkedList* next;

    LinkedList(int val) : value(val), next(nullptr) {}
};

// 2. Function prototypes for linked list operations
void append_node(LinkedList*& head, int value);
void insert_node(LinkedList*& head, int value, int position);
void delete_node(LinkedList*& head, int value);
bool search_node(LinkedList* head, int value, int& position);
void destroy_list(LinkedList*& head);

int main() {
    LinkedList* head = nullptr; // 3. Initialize the head pointer to nullptr
    int choice, value, position;

    // Initial node creation
    std::cout << "Enter the number of initial nodes (must be at least 1): ";
    std::cin >> choice;
    while (choice < 1) {
        std::cout << "Enter the number of initial nodes (must be at least 1): ";
        std::cin >> choice;
    }
    std::cout << "Enter a number: ";
    std::cin >> value;
    head = new LinkedList(value);
    LinkedList* current = head;
    for (int i = 1; i < choice; i++) {
        std::cout << "Enter a number: ";
        std::cin >> value;
        current->next = new LinkedList(value);
        current = current->next;
    }

    std::cout << "Here are the initial values in the linked list:" << std::endl;
    current = head;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }

    // 4. Operations on the linked list
    while (true) {
        std::cout << "Enter 1 to append a node, 2 to insert a node, 3 to delete a node, 4 to search for a node, or 5 to exit: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // 5. Append a new node to the end of the linked list
                std::cout << "Enter a number for a new node to insert to the linked list: ";
                std::cin >> value;
                append_node(head, value);
                break;
            case 2:
                // 6. Insert a new node at a specified position in the linked list
                std::cout << "Enter a number for a new node to insert to the linked list: ";
                std::cin >> value;
                std::cout << "Enter the position to insert the node: ";
                std::cin >> position;
                insert_node(head, value, position);
                break;
            case 3:
                // 7. Delete a node with a specified value from the linked list
                std::cout << "Enter the number of the node that you want to delete from the linked list: ";
                std::cin >> value;
                delete_node(head, value);
                break;
            case 4:
                // 8. Search for a node with a specified value in the linked list
                std::cout << "Enter the number that you want to search for in the list: ";
                std::cin >> value;
                if (search_node(head, value, position)) {
                    std::cout << "Number found at index " << position << " in the linked list" << std::endl;
                } else {
                    std::cout << "Number not found in the linked list" << std::endl;
                }
                break;
            case 5:
                // 9. Destroy the linked list and free the dynamically allocated memory
                destroy_list(head);
                return 0;
            default:
                std::cout << "Invalid choice, try again." << std::endl;
        }

        std::cout << "Here is the updated linked list:" << std::endl;
        current = head;
        while (current != nullptr) {
            std::cout << current->value << std::endl;
            current = current->next;
        }
    }

    return 0;
}

// 10. Function to append a new node to the end of the linked list
void append_node(LinkedList*& head, int value) {
    LinkedList* newNode = new LinkedList(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        LinkedList* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 11. Function to insert a new node at a specified position in the linked list
void insert_node(LinkedList*& head, int value, int position) {
    LinkedList* newNode = new LinkedList(value);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    } else {
        LinkedList* current = head;
        for (int i = 0; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Invalid position!" << std::endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 12. Function to delete a node with a specified value from the linked list
void delete_node(LinkedList*& head, int value) {
    if (head == nullptr) {
        return;
    }
    if (head->value == value) {
        LinkedList* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    LinkedList* current = head;
    while (current->next != nullptr) {
        if (current->next->value == value) {
            LinkedList* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
    std::cout << "Node with value " << value << " not found in the list." << std::endl;
}

// Function to search for a node with a specified value in the linked list
bool search_node(LinkedList* head, int value, int& position) {
    LinkedList* current = head;
    position = 0;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
        position++;
    }
    return false;
}

// Function to destroy the linked list and free the dynamically allocated memory
void destroy_list(LinkedList*& head) {
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
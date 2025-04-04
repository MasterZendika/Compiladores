#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

// Stack (LIFO) - Implementación desde cero
template <typename T>
class Stack {
private:
    std::vector<T> stack; // Usamos un vector como base
public:
    void push(const T& value) {
        stack.push_back(value);
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        } else {
            std::cerr << "Error: Stack is empty. Cannot pop.\n";
        }
    }

    T top() const {
        if (!stack.empty()) {
            return stack.back();
        } else {
            throw std::runtime_error("Error: Stack is empty.");
        }
    }

    bool isEmpty() const {
        return stack.empty();
    }

    size_t size() const {
        return stack.size();
    }

    void print() const {
        std::cout << "Stack (top to bottom): ";
        for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";
    }
};

// Queue (FIFO) - Implementación desde cero
template <typename T>
class Queue {
private:
    std::deque<T> queue; // Usamos un deque como base
public:
    void enqueue(const T& value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.pop_front();
        } else {
            std::cerr << "Error: Queue is empty. Cannot dequeue.\n";
        }
    }

    T front() const {
        if (!queue.empty()) {
            return queue.front();
        } else {
            throw std::runtime_error("Error: Queue is empty.");
        }
    }

    bool isEmpty() const {
        return queue.empty();
    }

    size_t size() const {
        return queue.size();
    }

    void print() const {
        std::cout << "Queue (front to back): ";
        for (const auto& item : queue) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};

// Hash Table / Dictionary - Usando std::unordered_map
template <typename K, typename V>
class HashTable {
private:
    std::unordered_map<K, V> table;
public:
    void insert(const K& key, const V& value) {
        table[key] = value;
    }

    void remove(const K& key) {
        if (table.erase(key) == 0) {
            std::cerr << "Error: Key not found. Cannot remove.\n";
        }
    }

    V get(const K& key) const {
        auto it = table.find(key);
        if (it != table.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Error: Key not found.");
        }
    }

    bool contains(const K& key) const {
        return table.find(key) != table.end();
    }

    void print() const {
        std::cout << "Hash Table contents:\n";
        for (const auto& pair : table) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }
};

// Función para interactuar con el usuario
void runProgram() {
    int choice;
    do {
        std::cout << "\n=== Data Structures Menu ===\n";
        std::cout << "1. Stack (LIFO)\n";
        std::cout << "2. Queue (FIFO)\n";
        std::cout << "3. Hash Table\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Stack<int> stack;
            int stackChoice, value;
            do {
                std::cout << "\n--- Stack Menu ---\n";
                std::cout << "1. Push\n";
                std::cout << "2. Pop\n";
                std::cout << "3. Top\n"; // Nueva opción para mostrar el elemento superior
                std::cout << "4. Print\n";
                std::cout << "5. Exit Stack\n";
                std::cout << "Choose an option: ";
                std::cin >> stackChoice;

                switch (stackChoice) {
                    case 1:
                        std::cout << "Enter a value to push: ";
                        std::cin >> value;
                        stack.push(value);
                        break;
                    case 2:
                        stack.pop();
                        break;
                    case 3:
                        try {
                            std::cout << "Top element: " << stack.top() << "\n";
                        } catch (const std::runtime_error& e) {
                            std::cerr << e.what() << "\n";
                        }
                        break;
                    case 4:
                        stack.print();
                        break;
                    case 5:
                        std::cout << "Exiting Stack menu.\n";
                        break;
                    default:
                        std::cerr << "Invalid option. Try again.\n";
                }
            } while (stackChoice != 5);
        } else if (choice == 2) {
            Queue<int> queue;
            int queueChoice, value;
            do {
                std::cout << "\n--- Queue Menu ---\n";
                std::cout << "1. Enqueue\n";
                std::cout << "2. Dequeue\n";
                std::cout << "3. Print\n";
                std::cout << "4. Exit Queue\n";
                std::cout << "Choose an option: ";
                std::cin >> queueChoice;

                switch (queueChoice) {
                    case 1:
                        std::cout << "Enter a value to enqueue: ";
                        std::cin >> value;
                        queue.enqueue(value);
                        break;
                    case 2:
                        queue.dequeue();
                        break;
                    case 3:
                        queue.print();
                        break;
                    case 4:
                        std::cout << "Exiting Queue menu.\n";
                        break;
                    default:
                        std::cerr << "Invalid option. Try again.\n";
                }
            } while (queueChoice != 4);
        } else if (choice == 3) {
            HashTable<std::string, int> hashTable;
            int hashChoice;
            std::string key;
            int value;
            do {
                std::cout << "\n--- Hash Table Menu ---\n";
                std::cout << "1. Insert\n";
                std::cout << "2. Remove\n";
                std::cout << "3. Get\n";
                std::cout << "4. Print\n";
                std::cout << "5. Exit Hash Table\n";
                std::cout << "Choose an option: ";
                std::cin >> hashChoice;

                switch (hashChoice) {
                    case 1:
                        std::cout << "Enter a key: ";
                        std::cin >> key;
                        std::cout << "Enter a value: ";
                        std::cin >> value;
                        hashTable.insert(key, value);
                        break;
                    case 2:
                        std::cout << "Enter a key to remove: ";
                        std::cin >> key;
                        hashTable.remove(key);
                        break;
                    case 3:
                        std::cout << "Enter a key to get the value: ";
                        std::cin >> key;
                        try {
                            std::cout << "Value: " << hashTable.get(key) << "\n";
                        } catch (const std::runtime_error& e) {
                            std::cerr << e.what() << "\n";
                        }
                        break;
                    case 4:
                        hashTable.print();
                        break;
                    case 5:
                        std::cout << "Exiting Hash Table menu.\n";
                        break;
                    default:
                        std::cerr << "Invalid option. Try again.\n";
                }
            } while (hashChoice != 5);
        } else if (choice == 4) {
            std::cout << "Exiting program.\n";
        } else {
            std::cerr << "Invalid option. Try again.\n";
        }
    } while (choice != 4);
}

int main() {
    runProgram();
    return 0;
}

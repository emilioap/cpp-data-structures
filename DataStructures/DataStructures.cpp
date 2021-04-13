#include "Stack.h"
#include "Queue.h"
#include <iostream>

int execStack() {
    char character;
    Stack stack;
    char stackItem;

    std::cin.ignore();
    std::cout << "Add an String:" << std::endl;
    std::cin.get(character);

    while (character != '\n')
    {
        stack.push(character);
        std::cin.get(character);
    }

    std::cout << "\n\nFirst in, last out. Last in, first out:" << std::endl;

    while (!stack.isEmpty())
    {
        stackItem = stack.pop();
        std::cout << stackItem;
    }

    return 0;
}

int execQueue() {
    char character;
    Queue queue;
    char queueItem;

    std::cin.ignore();
    std::cout << "Add an String:" << std::endl;
    std::cin.get(character);

    while (character != '\n')
    {
        queue.enqueue(character);
        std::cin.get(character);
    }

    std::cout << "\n\nFirst in, first out. Last in, last out:" << std::endl;

    while (!queue.isEmpty())
    {
        queueItem = queue.dequeue();
        std::cout << queueItem;
    }

    return 0;
}

int execHashTable() {
    std::cout << "Not implemented yet :(" << std::endl;
    return 0;
}

int execBinarySearchTree() {
    std::cout << "Not implemented yet :(" << std::endl;
    return 0;
}

int execGraph() {
    std::cout << "Not implemented yet :(" << std::endl;
    return 0;
}

int main()
{
    std::cout << "Choose your data structure by typing the corresponding number: \n";
    std::cout << "1 - Stack" << std::endl;
    std::cout << "2 - Queue" << std::endl;
    std::cout << "3 - Hash Table" << std::endl;
    std::cout << "4 - Binary Search Tree" << std::endl;
    std::cout << "5 - Graph" << std::endl;

    char option = (char)std::cin.get();

    switch (option) {
        case '1':
            execStack();
            break;
        case '2':
            execQueue();
            break;
        case '3':
            execHashTable();
            break;
        case '4':
            execBinarySearchTree();
            break;
        case '5':
            execGraph();
            break;
        default:
            std::cout << std::endl;
    }

    std::cout << "\n\nEnd of program." << std::endl;
    std::cout << std::endl;
}
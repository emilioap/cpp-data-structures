#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include <iostream>

void execStack() {
    char character;
    Stack stack;
    char stackItem;

    std::cin.ignore();
    std::cout << "Type an string and press Enter:\n" << std::endl;
    std::cin.get(character);

    while (character != '\n')
    {
        stack.push(character);
        std::cin.get(character);
    }

    std::cout << "\n\nFirst in, last out. Last in, first out:\n" << std::endl;

    while (!stack.isEmpty())
    {
        stackItem = stack.pop();
        std::cout << stackItem;
    }
}

void execQueue() {
    char character;
    Queue queue;
    char queueItem;

    std::cin.ignore();
    std::cout << "Type an string and press Enter:\n" << std::endl;
    std::cin.get(character);

    while (character != '\n')
    {
        queue.enqueue(character);
        std::cin.get(character);
    }

    std::cout << "\n\nFirst in, first out. Last in, last out:\b" << std::endl;

    while (!queue.isEmpty())
    {
        queueItem = queue.dequeue();
        std::cout << queueItem;
    }
}

void execHashTable() {
    Hash studentsHash(10);
    int ids[7] = { 12880, 12001, 11988, 12567, 12411, 11710, 13011 };
    std::string names[7] = { "Samy", "Ash", "Slash", "Marcus", "Jimmy", "Anne", "Kate" };
    int arrLength = (sizeof(names) / sizeof(names[0]));

    for (int i = 0; i < arrLength; i++)
    {
        Student student = Student(ids[i], names[i]);
        studentsHash.insertItemWithoutCollision(student);
    }
    studentsHash.print();

    int newStudentId = 0;
    std::cin.ignore();
    std::cout << "Type an Id to search the student and press Enter:\n" << std::endl;
    std::cin >> newStudentId;

    Student newStudent(newStudentId, "");
    bool found = false;
    studentsHash.retrieveItemWithoutCollision(newStudent, found);

    if (found == false) {
        char addStudent;
        std::cout << "Not found. Do you want add this student? (Y/N)\n" << std::endl;
        std::cin >> addStudent;
        if (addStudent == tolower('y')) {
            std::string newStudentName;
            std::cout << "Type the name of the student and press Enter:\n" << std::endl;
            std::cin >> newStudentName;
            Student newStudent(newStudentId, newStudentName);
            studentsHash.insertItemWithoutCollision(newStudent);
            studentsHash.print();
            studentsHash.deleteItemWithoutCollision(newStudent);
        }
    }
    else
        std::cout << newStudent.getName() << ":" << found << std::endl;
}

void execBinarySearchTree() {
    std::cout << "Not implemented yet :(" << std::endl;
}

void execGraph() {
    std::cout << "Not implemented yet :(" << std::endl;
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

    std::cout << std::endl;
    return 0;
}
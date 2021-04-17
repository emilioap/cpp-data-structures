#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "HashTable.h"
#include "BinarySearchTree.h"
#include "Graph.h"

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
    BinarySearchTree searchTree;
    const int TOTAL_PRODUCTS = 8;
    int ras[TOTAL_PRODUCTS] = { 20, 18, 58, 7, 19, 26, 25, 30 };
    std::string names[TOTAL_PRODUCTS] = { "TV", "Phone", "Watch", "Bag", "Keyboard", "Pen", "Book", "Chair" };
    Product products[TOTAL_PRODUCTS];

    for (int i = 0; i < TOTAL_PRODUCTS; i++) {
        Product product = Product(ras[i], names[i]);
        products[i] = product;
        searchTree.insertProduct(product);
    }
    std::cout << "\nInserting products...\n" << std::endl;

    std::cout << "Pre: ";
    searchTree.printPreOrder();
    std::cout << std::endl;

    std::cout << "Post: ";
    searchTree.printPostOrder();
    std::cout << std::endl;

    std::cout << "In: ";
    searchTree.printInOrder();
    std::cout << std::endl;

    searchTree.deleteProduct(products[0].getCode());
    std::cout << "\nDeleting products...\n" << std::endl;

    std::cout << "Pre: ";
    searchTree.printPreOrder();
    std::cout << std::endl;

    std::cout << "Post: ";
    searchTree.printPostOrder();
    std::cout << std::endl;

    std::cout << "In: ";
    searchTree.printInOrder();
    std::cout << std::endl;
}

void execGraph() {
    Graph graph;

    std::cout << "\n\nCreated vertices and added initial edges:\n" << std::endl;
    Vertex a = Vertex("A"); graph.addVertex(a);
    Vertex b = Vertex("B"); graph.addVertex(b);
    Vertex c = Vertex("C"); graph.addVertex(c);
    Vertex d = Vertex("D"); graph.addVertex(d);
    Vertex e = Vertex("E"); graph.addVertex(e);
    graph.addEdge(a, b, 2);
    graph.addEdge(b, c, 3);
    graph.addEdge(d, e, 5);
    graph.addEdge(a, c, 1);
    graph.addEdge(c, e, 4);
    graph.printMatrix();
    
    while (true) {
        char vertex1;
        char vertex2;
        int weigth;

        char response;
        std::cout << "\nDo you want add more edges? (Y/N)\n" << std::endl;
        std::cin >> response;

        if (response != tolower('y'))
            break;

        std::cout << "Choose the vertex 1 (a,b,c,d or e) and press Enter:\n" << std::endl;
        std::cin >> vertex1;
        int index1 = graph.getIndexByName(std::string(1, toupper(vertex1)));
        Vertex v1 = graph.getVertexByIndex(index1);

        std::cout << "Choose the vertex 2 (a,b,c,d or e) and press Enter:\n" << std::endl;
        std::cin >> vertex2;
        int index2 = graph.getIndexByName(std::string(1, toupper(vertex2)));
        Vertex v2 = graph.getVertexByIndex(index2);

        std::cout << "Choose the an weigh (int) to edge and press Enter:\n" << std::endl;
        std::cin >> weigth;
        graph.addEdge(v1, v2, weigth);
    }

    graph.printMatrix();
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
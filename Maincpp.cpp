#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

// Structure for a book (used in Linked List, Doubly Linked List, and BST)
struct Book {
    int id;
    string title;
    string author;
    Book* next; // For Linked List
    Book* prev; // For Doubly Linked List
};

// Linked List for storing dynamic book details
class LinkedList {
private:
    Book* head;

public:
    LinkedList() : head(nullptr) {}

    void addBook(int id, string title, string author) {
        Book* newBook = new Book{id, title, author, nullptr, nullptr};
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newBook;
        }
        cout << "Book added to linked list: " << title << endl;
    }

    void displayBooks() {
        Book* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << endl;
            temp = temp->next;
        }
    }
};

// Doubly Linked List for managing book checkout and return history
class DoublyLinkedList {
private:
    Book* head;
    Book* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addHistory(int id, string title) {
        Book* newBook = new Book{id, title, "", nullptr, nullptr};
        if (!head) {
            head = tail = newBook;
        } else {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
        cout << "History added: " << title << endl;
    }

    void displayHistory() {
        Book* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Title: " << temp->title << endl;
            temp = temp->next;
        }
    }
};

// Stack for recent checkouts (Last-In-First-Out)
class CheckoutStack {
private:
    stack<Book> checkoutStack;

public:
    void pushBook(int id, string title) {
        checkoutStack.push({id, title, "", nullptr, nullptr});
        cout << "Book checked out: " << title << endl;
    }

    void popBook() {
        if (!checkoutStack.empty()) {
            Book recent = checkoutStack.top();
            checkoutStack.pop();
            cout << "Book returned: " << recent.title << endl;
        } else {
            cout << "No books to return!" << endl;
        }
    }
};

// Queue for book requests (First-In-First-Out)
class RequestQueue {
private:
    queue<Book> requestQueue;

public:
    void addRequest(int id, string title) {
        requestQueue.push({id, title, "", nullptr, nullptr});
        cout << "Request added for book: " << title << endl;
    }

    void processRequest() {
        if (!requestQueue.empty()) {
            Book request = requestQueue.front();
            requestQueue.pop();
            cout << "Processing request for book: " << request.title << endl;
        } else {
            cout << "No requests to process!" << endl;
        }
    }
};

// Binary Search Tree for organizing books by title
class BST {
private:
    struct TreeNode {
        string title;
        string author;
        int id;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int i, string t, string a) : id(i), title(t), author(a), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    void inOrder(TreeNode* node) {
        if (node) {
            inOrder(node->left);
            cout << "ID: " << node->id << ", Title: " << node->title << ", Author: " << node->author << endl;
            inOrder(node->right);
        }
    }

    TreeNode* insert(TreeNode* node, int id, string title, string author) {
        if (!node) return new TreeNode(id, title, author);
        if (title < node->title)
            node->left = insert(node->left, id, title, author);
        else
            node->right = insert(node->right, id, title, author);
        return node;
    }

public:
    BST() : root(nullptr) {}

    void addBook(int id, string title, string author) {
        root = insert(root, id, title, author);
        cout << "Book added to BST: " << title << endl;
    }

    void displayBooks() {
        cout << "Books in BST (in-order traversal):" << endl;
        inOrder(root);
    }
};

int main() {
    // Arrays for storing fixed book details
    const int MAX_BOOKS = 5;
    string bookTitles[MAX_BOOKS] = {"Linear Algebra", "Calculus", "Accounting", "DSA", "Physics"};
    int bookIDs[MAX_BOOKS] = {1, 2, 3, 4, 5};
    cout << "Books in Array:" << endl;
    for (int i = 0; i < MAX_BOOKS; i++) {
        cout << "ID: " << bookIDs[i] << ", Title: " << bookTitles[i] << endl;
    }

    // Linked List example
    LinkedList linkedList;
    linkedList.addBook(6, "Book F", "Author X");
    linkedList.addBook(7, "Book G", "Author Y");
    linkedList.displayBooks();

    // Doubly Linked List example
    DoublyLinkedList history;
    history.addHistory(1, "Book A");
    history.addHistory(2, "Book B");
    history.displayHistory();

    // Stack example
    CheckoutStack checkout;
    checkout.pushBook(3, "Book C");
    checkout.pushBook(4, "Book D");
    checkout.popBook();

    // Queue example
    RequestQueue requestQueue;
    requestQueue.addRequest(5, "Book E");
    requestQueue.processRequest();

    // BST example
    BST bst;
    bst.addBook(8, "Book H", "Author Z");
    bst.addBook(9, "Book I", "Author W");
    bst.addBook(10, "Book J", "Author V");
    bst.displayBooks();

    return 0;
}

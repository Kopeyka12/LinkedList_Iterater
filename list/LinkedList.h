//@avtor Мирошин В. И.
//Класс LinkedList
#include <iostream>
#include "Iterater.h"
template<typename T>
//класс LinkedList
class LinkedList {
private:
    //структура узла
    struct Node {
        T data;         //даные узла
        Node* next;     //следующий узел
        Node(const T& data) : data(data), next(nullptr) {}  //конструктор
    };

    Node* head; //узел
    int size;   //размер

public:
    //итератор
    class Iterator {
    private:
        Node* current;

    public:
        //конструктор итератора
        Iterator(Node* node) : current(node) {}
        //инкремент (переход к следующему элементу)
        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }
        //инкремент (переход к следующему элементу)
        Iterator operator++(int) {
            Iterator itr = *this;
            ++(*this);
            return itr;
        }
        //оператор вывода узла
        T& operator*() const {
            return current->data;
        }
        //операторы сравнния 
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };
    //итераторы, указывающие на начало и конец дерева соответственно
    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    //конструктор 
    LinkedList() : head(nullptr), size(0) {}
    
    //деструктор
    ~LinkedList() {
        clear();
    }
    //добавления узла
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    //метод вывода списка последнего элемента
    void pop_front() {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    //ф-ия определяет пустой список или нет
    bool isEmpty() const {
        return head == nullptr;
    }
    //вывод размера списка
    int getSize() const {
        return size;
    }
    //очищение списка
    void clear() {
        while (!isEmpty()) {
            pop_front();
        }
    }
    //вывод списка
    void printList() const {
        if (isEmpty()) {
            std::cout << "List is empty!\n";
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        //std::cout << std::endl;
    }
};



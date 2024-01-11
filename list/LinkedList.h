//@avtor ������� �. �.
//����� LinkedList
#include <iostream>
//#include "Iterater.h"
template<typename T>
//����� LinkedList ������������ ������
class LinkedList {
private:
    //��������� ���� 
    struct Node {
        T data;         //����� ����
        Node* next;     //��������� ����
        Node(const T& data) : data(data), next(nullptr) {}  //�����������
    };

    Node* head; //����
    int size;   //������

public:
    //��������
    class LinListIterator {
    private:
        Node* current;

    public:
        //����������� ���������
        LinListIterator(Node* node) : current(node) {}
        //��������� (������� � ���������� ��������)
        LinListIterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }
        //�������� �������� �� ��������� ���� (���������)
        LinListIterator operator++(int) {
            LinListIterator itr = *this;
            ++(*this);
            return itr;
        }
        //�������� ������ ����
        T& operator*() const {
            return current->data;
        }
        //��������� �������� 
        bool operator==(const LinListIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const LinListIterator& other) const {
            return !(*this == other);
        }
    };
    //���������, ����������� �� ������ � ����� ������ ��������������
    LinListIterator begin() const {
        return LinListIterator(head);
    }

    LinListIterator end() const {
        return LinListIterator(nullptr);
    }

    //����������� 
    LinkedList() : head(nullptr), size(0) {}
    
    //����������
    ~LinkedList() {
        clear();
    }
    //���������� ����
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }
    //����� ������ ������ ���������� ��������
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
    //�-�� ���������� ������ ������ ��� ���
    bool isEmpty() const {
        return head == nullptr;
    }
    //����� ������� ������
    int getSize() const {
        return size;
    }
    //�������� ������
    void clear() {
        while (!isEmpty()) {
            pop_front();
        }
    }
    //����� ������
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
    }
};



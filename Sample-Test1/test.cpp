//@avtor Мирошин В. И.
//Тест методов класса 
#include "pch.h"
#include <cassert>
#include <sstream>

TEST(TestList, TestPrint) 
{
    LinkedList <int> list1;

    list1.push_front(5);
    list1.push_front(9);
    list1.push_front(1);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    
    list1.printList();

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "1 9 5 ");
    list1.clear();

    list1.push_front(-9);
    list1.push_front(5);
    list1.push_front(12);
    list1.push_front(67);
    list1.push_front(99);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    list1.printList();

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "99 67 12 5 -9 ");
    list1.clear();
}

TEST(TestList, TestPop)
{
    LinkedList <int> list2;

    list2.push_front(5);
    list2.push_front(9);
    list2.push_front(1);
    list2.push_front(8);
    list2.push_front(12);
    list2.push_front(-9);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    list2.pop_front();
    //list2.printList();

    for (LinkedList<int>::Iterator itr = list2.begin(); itr != list2.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout.rdbuf(p_cout_streambuf);

    // тестируем наш метод
    assert(oss.str() == "12 8 1 9 5 ");
}
#include "pch.h"
//#include"C:\Users\Влад\Desktop\Учеба\УЧЁБА\3 курс\САОД\list\list\LinkedList.h"
#include <cassert>
#include <sstream>

//LinkedList<int> createList()
//{
//    LinkedList <int> list;
//    list.push_front(5);
//    list.push_front(9);
//    list.push_front(1);
//    return list;
//};

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
}
//TEST(TestCaseName, TestName) {
//  EXPECT_EQ(1, 1);
//  EXPECT_TRUE(true);
//}
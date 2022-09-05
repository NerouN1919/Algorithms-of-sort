#include "ForwardList.h"
#include "DoubleLinkedList.h"
#include "Sort.h"
#include <deque>
namespace sviridenko
{
  template< typename Iter >
  void print(Iter first, Iter last)
  {
    int number = 0;
    for (; first != last; first++)
    {
      if (number != 0)
      {
        std::cout << " ";
      }
      std::cout << *first;
      number++;
    }
    std::cout << "\n";
  }

  template< typename T >
  void viewSort(bool comp, int size)
  {
    std::deque< T > first;
    std::deque< T > second;
    std::deque< T > third;
    BidirectionalList< T > fourth;
    BidirectionalList< T > fifth;
    ForwardList< T > sixth;
    for (int i = 0; i < size; i++)
    {
      T a = static_cast<T>((rand() % (size * 100)) / 100.0);
      first.push_back(a);
      second.push_back(a);
      third.push_back(a);
      fourth.insertTail(a);
      fifth.insertTail(a);
      sixth.pushBack(a);
    }
    print(first.begin(), first.end());

    insertSort(first.begin(), first.end(), comp);
    shakerSort(second.begin(), second.end(), comp);
    oddEvenSort(third.begin(), third.end(), comp);
    insertSort(fourth.begin(), fourth.end(), comp);
    shakerSort(fifth.begin(), fifth.end(), comp);
    oddEvenSort(sixth.begin(), sixth.end(), comp);

    print(first.begin(), first.end());
    print(second.begin(), second.end());
    print(third.begin(), third.end());
    print(fourth.begin(), fourth.end());
    print(fifth.begin(), fifth.end());
    print(sixth.begin(), sixth.end());
  }
}

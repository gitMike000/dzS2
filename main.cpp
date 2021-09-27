#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include "Timer.h"

using namespace std;


template <typename T>
void swap(T *p1,T *p2) {
    T a=*p1;
    *p1=*p2;
    *p2=a;
}

template <typename X>
void SortPointers(vector<X> &p) {
sort(p.begin(),p.end(), [](X p1, X p2)
                          {return *p1 < *p2; });
}

string letter="AaEeIiOoUuYy";

bool contains1(char str)
{
  return (letter.find(str) != letter.npos);
}

size_t find1(const string_view& t) {
  return count_if(t.begin(),t.end(), contains1);
}

bool contains2(char str)
{
  for (size_t i=0;i<letter.length();++i) {
   if (letter[i]==str) return true;
  }
  return false;
}

size_t find2(const string_view& t) {
  return count_if(t.begin(),t.end(), contains2 );
}

size_t find3(const string_view& t) {
  size_t count=0;
  for(size_t i=0;i<t.length();++i) {
   if (letter.find(t[i]) != letter.npos) ++count;
  }
  return count;
}

size_t find4(const string_view& t) {
  size_t count=0;
  for(size_t i=0;i<t.length();++i) {
      for (size_t j=0;j<letter.length();++j) {
       if (letter[j]==t[i]) ++count;
      }
  }
  return count;
}

int main()
{
    // Task 1
//    Реализуйте шаблонную функцию Swap, которая принимает два указателя
//    и обменивает местами значения, на которые указывают эти указатели.
    cout << "--- Task 1---" << endl;
    char *p1; char *p2;
    char a='1',b='2';
    p1=&a;
    p2=&b;
    cout << "*p1=" << *p1 <<endl;
    cout << "*p2=" << *p2 <<endl;
    cout << "swap"<<endl;
    swap(p1,p2);
    cout << "*p1=" << *p1 <<endl;
    cout << "*p2=" << *p2 <<endl;

   // Task 2continue;
//   Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей
//   и сортирует указатели по значениям, на которые они указывают.
   cout <<endl << "--- Task 2---" << endl;
   vector<char*> pnumbers ={ new char('z'),new char('Z'),new char('f') };
   for_each (pnumbers.begin(),pnumbers.end(), [] (const auto& p)
                                                    {cout << *p << " ";});
   cout << endl;
   SortPointers(pnumbers);
   for_each (pnumbers.begin(),pnumbers.end(), [] (const auto& p)
                                                    {cout << *p << " ";});
    cout << endl;

    // Task 3
//    Подсчитайте количество гласных букв в книге “Война и мир”. Для подсчета используйте 4 способа:
//○      count_if и find
//○      count_if и цикл for
//○      цикл for и find
//○      2 цикла for
//Замерьте время каждого способа подсчета и сделайте выводы.
//Справка:
//count_if - это алгоритмическая функция из STL, которая принимает 3 параметра: итератор на начало,
//итератор на конец и унарный предикат (функцию, принимающую один параметр и возвращающую тип bool).
//find - это метод класса string, который возвращает позицию символа (строки), переданного в качестве
//параметра, в исходной строке. Если символ не найден, то метод возвращает string::npos.
    cout <<endl << "--- Task 3---" << endl;

    ifstream file("/home/mike/qtc/dzS2/War_and_peace.txt");
    file.seekg(0, ios::end);
    size_t size = file.tellg();
    file.seekg(0);
    string s(size, ' ');

    file.read(&s[0], size);

    Timer timer1("find 1");
    cout << "способ 1=" << find1(s)<<" гласных"<<endl;
    timer1.print();
    cout<<endl;

    Timer timer2("find 2");
    cout << "способ 2=" << find2(s)<<" гласных"<<endl;
    timer2.print();
    cout<<endl;

    Timer timer3("find 3");
    cout << "способ 3=" << find3(s)<<" гласных"<<endl;
    timer3.print();
    cout<<endl;

    Timer timer4("find 4");
    cout << "способ 4=" << find4(s)<<" гласных"<<endl;
    timer4.print();
    cout<<endl;

    return 0;
}

#include "MyList.h"
#include "DList.h"
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    /*using namespace mylist;
    Node<int>first(7);

    Node<int>second(4);
    first.next = &second;

    Node<int>third(9);
    second.next = &third;

    Node<int>fourth(2);
    third.next = &fourth;

    Node<int>* p = &first;
    while (p != nullptr) {
        cout << p->info << endl;
        p->showNode();
        p = p->next;
    }*/

    /*using namespace mylist;
    MyList<int> a;
    a.push_back(7);
    a.push_back(4);
    a.push_back(9);
    a.push_back(2);
    a.showList();*/

    /*DList<int> b;
    b.push_back(7);
    b.push_back(4);
    b.push_back(9);
    b.push_back(2);
    b.showList();

    b.destruct();*/

    /*list<string> p34;
    p34.push_back("Kyrylo");
    p34.push_back("Vitaliy");
    p34.push_back("Vladyslav");
    p34.push_back("Liza");

    list<string>::iterator p;
    for (p=p34.begin();p!=p34.end();p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    cout << "----------------------------------\n";
    p34.sort();
    for (auto stud : p34) 
    {
        cout << stud << " ";
    }
    cout << endl;*/

    list<int> numbers;
    for (int i = 0; i < 10; i++)
    {
        numbers.push_back(rand() % 10 - 5);
    }
    for (auto num : numbers)
    {
        cout << num << " ";
    }

    auto a = max_element(numbers.begin(), numbers.end());

    cout << "\nMax: " << *a<<endl;


    /*for (auto &num : numbers)
    {
        if (num < 0) {
            num = 0;
        }
    }*/

    replace_if(numbers.begin(), numbers.end(), [](int a) {
        return a < 0;
        },0);

    for (auto num : numbers)
    {
        cout << num << " ";
    }

    for_each(numbers.begin(), numbers.end(), [a](int& el) {
        el += *a; });
    cout << endl;
    for (auto num : numbers)
    {
        cout << num << " ";
    }
    int num;
    cout << "\nEnter num: ";
    cin >> num;
    auto user= find_if(numbers.begin(), numbers.end(), [num](int a) {
        return a == num; });
    if (user == numbers.end())
    {
        cout << "Not fount!!!\n";
    }
    else {
        numbers.erase(user);
    }
    for (auto num : numbers)
    {
        cout << num << " ";
    }
    cout << "\nEnter num: ";
    cin >> num;
    user = find_if(numbers.begin(), numbers.end(), [num](int a) {
        return a == num; });
    if (user == numbers.end())
    {
        cout << "Not fount!!!\n";
    }
    else {
        user++;
        numbers.insert(user,777);
    }
    for (auto num : numbers)
    {
        cout << num << " ";
    }

}
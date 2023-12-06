#include <iostream>
#include <list>

using namespace std;

class Point
{
private:
    int x, y;
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class List
{
private:
    list<float> myList;
    int currentPos = 1;
public:
    void pushBack(float value)
    {
        this->myList.push_back(value);
    }
    int operator () ()
    {
        return this->myList.size();
    }
    void operator +(float value)
    {
        for (list<float>::iterator myIterator = this->myList.begin(); myIterator != this->myList.end(); ++myIterator)
            *myIterator += value;
    }
    list<float>::iterator operator++(int)
    {
        list<float>::iterator myIterator = this->myList.begin();
        list<float>::iterator buffIterator = myIterator;
        advance(buffIterator, currentPos - 1);
        while (myIterator != buffIterator)
            myIterator++;
        currentPos++;
        return myIterator;
    }
    void operator *(float value)
    {
        srand(time(nullptr));
        int randPos = rand() % this->myList.size();
        list<float>::iterator buffIterator = this->myList.begin();
        advance(buffIterator, randPos);
        this->myList.insert(buffIterator, value);
    }
    float ListAverage()
    {
        float average = 0;
        for (list<float>::iterator myIterator = this->myList.begin(); myIterator != this->myList.end(); ++myIterator)
            average += *myIterator;
        return average / this->myList.size();
    }
    void printList()
    {
        for (float i : myList)
            std::cout << i << " ";
    }
};

int main()
{
    Point myPoint(1, 1);
    List buffList;
    buffList.pushBack(12);
    buffList.pushBack(11);
    buffList.pushBack(10);
    buffList.pushBack(9);
    buffList.printList();
    cout << endl;
    cout << buffList.ListAverage();
    buffList + buffList.ListAverage();
    cout << endl;
    buffList.printList();
}

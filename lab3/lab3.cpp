#include <iostream>
#include <list>

using namespace std;

class Point
{
private:
public:
    int x, y;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void PrintPoint()
    {
        cout << "X:" << this->x << " Y:" << this->y << endl;
    }
};

class List
{
private:
    list<float> myList;
    int currentPos = 1;
    int currentPointPos = 1;
    list<Point> myPointList;
public:
    void PushBack(float value)
    {
        this->myList.push_back(value);
    }
    void PushBack(Point value)
    {
        this->myPointList.push_back(value);
    }
    int operator () ()
    {
        return this->myList.size();
    }
    int operator () (Point)
    {
        return this->myPointList.size();
    }
    void operator +(float value)
    {
        for (list<float>::iterator myIterator = this->myList.begin(); myIterator != this->myList.end(); ++myIterator)
            *myIterator += value;
    }
    void operator +(Point value)
    {
        for (list<Point>::iterator myIterator = this->myPointList.begin(); myIterator != this->myPointList.end(); ++myIterator)
        {
            (*myIterator).x += value.x;
            (*myIterator).y += value.y;
        }
            
    }
    float operator++(int)
    {
        list<float>::iterator myIterator = this->myList.begin();
        list<float>::iterator buffIterator = myIterator;
        advance(buffIterator, currentPos - 1);
        while (myIterator != buffIterator)
            myIterator++;
        currentPos++;
        return *myIterator;
    }
    Point operator++()
    {
        list<Point>::iterator myIterator = this->myPointList.begin();
        list<Point>::iterator buffIterator = myIterator;
        advance(buffIterator, currentPointPos - 1);
        while (myIterator != buffIterator)
            myIterator++;
        currentPointPos++;
        return *myIterator;
    }
    void operator *(float value)
    {
        srand(time(nullptr));
        int randPos = rand() % this->myList.size();
        list<float>::iterator buffIterator = this->myList.begin();
        advance(buffIterator, randPos);
        this->myList.insert(buffIterator, value);
    }
    void operator *(Point value)
    {
        srand(time(nullptr));
        int randPos = rand() % this->myPointList.size();
        list<Point>::iterator buffIterator = this->myPointList.begin();
        advance(buffIterator, randPos);
        this->myPointList.insert(buffIterator, value);
    }
    float ListAverage()
    {
        float average = 0;
        for (list<float>::iterator myIterator = this->myList.begin(); myIterator != this->myList.end(); ++myIterator)
            average += *myIterator;
        return average / this->myList.size();
    }
    int PointListAverage()
    {
        float average = 0;
        for (list<Point>::iterator myIterator = this->myPointList.begin(); myIterator != this->myPointList.end(); ++myIterator)
            average += (*myIterator).x + (*myIterator).y;
        return average / this->myPointList.size();
    }
    void printList()
    {
        for (float i : myList)
            std::cout << i << endl;
    }

    void printPointList()
    {
        for (Point i : myPointList)
            i.PrintPoint();
    }
};

int main()
{
    cout << "the task with Point list:\nContainer:" << endl;

    Point point1(1, 1);
    Point point2(2, 2);

    List buffPointList;

    buffPointList.PushBack(point1);
    buffPointList.PushBack(point2);

    buffPointList.printPointList();
    cout << "\nAverage: " << buffPointList.PointListAverage() << endl;
    
    Point AverageValue(buffPointList.PointListAverage(), buffPointList.PointListAverage());

    cout << "\n" << "Task:" << endl;
    buffPointList + AverageValue;
    buffPointList.printPointList();
    
    //Задание с флоат:
    cout << "\nthe task with float list:\nContainer:" << endl;
    List buffList;

    buffList.PushBack(3.2);
    buffList.PushBack(7.1);

    buffList.printList();
    cout << "\n" << "Average: " << buffList.ListAverage() << endl;

    cout << "\n" << "Task:" << endl;
    buffList + buffList.ListAverage();
    buffList.printList();
}
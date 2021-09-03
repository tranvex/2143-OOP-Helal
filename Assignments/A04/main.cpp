/*****************************************************************************
*                    
*  Author:           Yoseph Helal
*  Email:            tranvex@gmail.com
*  Label:            A04
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This program implements a class that allows an array to be used just like 
*        a circular queue. It overloads the "<<" (delimiters) to print the class object
*        as if it were a normal variable using cout. The class has push and pop methods
*        without a need for a print function thanks to the overloaded operators. 
* 
*  Usage:
*        Not needed
* 
*  Files:            main.cpp    : driver program
*****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *      This class creates an array that behaves like a circular queue by taking a value
 *      in the constructor for size and setting the size of the array to it. Circular
 *      queues are an abstract data structure that dictates items are inserted at the
 *      back and removed at the front. The front loops around to the back, making it circular.
 *       
 * 
 * Public Methods:
 *                          CircularArrayQue()
 *                          CircularArrayQue(int size)
 *      void                Push(int item)
 *      int                 Pop()
 * 
 * Private Methods:
 *      void                init(int size = 0)
 *      bool                Full()
 * 
 * Usage: 
 * 
 *      CircularArrayQue C1;               // Creates CircularArrayQue object
 *                                         // with size 10
 *      
 *      CircularArrayQue C2(size)          // Creates CircularArrayQue object
 *                                         // with size "size"
 *      
 *      
 */

class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    
    /**
 * Private : init
 * 
 * Description:
 *      Marks newly created array as empty by setting all variables to 0 except for QueSize
 *      which is how many values the array can hold
 * 
 * Params:
 *      int     :  integer to set size of array
 * 
 * Returns:
 *      void :  nothing
 */
    
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

/**
        * Private : full
        * 
        * Description:
        *      Checks to see if the current size of the array is equal to the
        *      queue size
        *      basically if array is full or not
        * 
        * Params:
        *      None
        * 
        * Returns:
        *      bool     :   true or false based on if current size is equal
        *                   or not to queue size
*/
    
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
        * Public : CircularArrayQue
        * 
        * Description:
        *      Default constuctor that sets array/queue size to 10
        * 
        * Params:
        *      None
        *
        * Returns:
        *      None
    */
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
        * Public : CircularArrayQue
        * 
        * Description:
        *      Overloaded constuctor that initializes container value to
        *      user set size
        * 
        * Params:
        *      int      :      integer for user set size     
        *
        * Returns:
        *      None
    */
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

    /**
        * Public : Push
        * 
        * Description:
        *      inserts value to end of queue
        * 
        * Params:
        *      int      :   value to add to end of queue
        *
        * Returns:
        *      None
    */
    
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }

    /**
        * Public : Pop
        * 
        * Description:
        *      Removes an item from the front of the queue
        * 
        * Params:
        *      None
        *
        * Returns:
        *      int      :   the value removed from the front of the queue
    */
    
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
* Function : operator<<
* 
* Description:
*      Overloads the << operator so the queue can be printed as a normal
*      variable with cout
* 
* Params:
*      ostream &                    :   reference to the stream
*      const CircularArrayQueue&    :   constant class object passed by reference
*
* Returns:
*     ostream &                     :   a referece to the stream
*/

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}

/*****************************************************************************
*                    
*  Author:           Yoseph Helal
*  Email:            tranvex@gmail.com
*  Label:            MyVector Class
*  Title:            P01
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        Implementation of a vector in the form of a single linked list
*        class. Implementation allows you to push/pop to the front, 
*        to the rear, and at a specific point in the list. You're also
*        allowed to construct with another vector-list, input file,
*        and using an array. You're allowed to push whole vector-lists
*        to the front or rear of the list. Lastly, you can
*        search your list-vector and print it to console and file.
*        
* 
*  Usage:
*        Simply make use of the provided methods in the MyVector class
*        in main.
* 
*  Files: main.cpp (required)  Main Driver
*         input.dat (required) Sample input file, testing reading from file
*         main.out (created)   Program creates output file with created vectors
*****************************************************************************/
#include <iostream>  // Standard library
#include <fstream>   // File input/output
using namespace std; // std namespace

/**
 * node
 * 
 * Description:
 *      One node in a linked list. Holds data and next pointer
 * 
 * Public Methods:
 *      node - default constructor, initializes node object
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 
 *      node (5) // Creates node with data 5
 *      
 */
struct node {       // Node struct for vector implementation
  int data;         // data held in node
  node* next;       // next pointedr (linked list)
  node (int x) {    // Constructor
    data = x;       // initializes data
    next = nullptr; // initializes next pointer
  }
};

/**
 * MyVector
 * 
 * Description:
 *        Implementation of a vector in the form of a single linked list
 *        class. Implementation allows you to push/pop to the front, 
 *        to the rear, and at a specific point in the list. You're also
 *        allowed to construct with another vector-list, input file,
 *        and using an array. You're allowed to push whole vector-lists
 *        to the front or rear of the list. Lastly, you can
 *        search your list-vector and print it to console and file.
 * 
 * Public Methods:
 *      MyVector        MyVector ()
 *      MyVector        Myvector (int*A, int size)
 *      MyVector        MyVector (string fileName)
 *      MyVector        MyVector (const MyVector &obj)
 *      void            pushFront (int val)
 *      void            pushFront(MyVector vector)
 *      void            pushRear (int val)
 *      void            pushRear (MyVector vector)
 *      void            pushAt (int loc, int val)
 *      int             popFront()
 *      int             popRear ()
 *      int             popAt (int loc)
 *      int             find (int val)
 *      void            print (fstream &outfile)
 *      void            print(int x,fstream  &outfile)
 * 
 * Private Methods:
 *      None
 * 
 * Usage: 
 * 
 *      MyVector v1       // Creates instance of vector-list
 *      v1.pushFront(18)  // Pushes 18 to front of vector-list
 *      v1.pushRear(18)   // Pushes 18 to rear of vector-list
 *      MyVector v2(A,5)  // Creates vector-list from array A with size 5
 *      x = v1.popFront() // Pops value from the front of v1 and stores value
 *                        // in x
 *      x = v1.popRear()  // Pops value from the rear of v1 and stores value
 *                        // in x
 *      x = v2.popAt(3)   // Pops value at index 3 in v2 and stores it in x
 *      
 */
class MyVector {
  private:
    node* head; // pointer that represents beginning of MyVector object
    node* tail; // pointer that represents end of MyVector object
    int size;   // represents size of MyVector object
    

  public:
    
    /**
     * Public : MyVector
     * 
     * Description:
     *      Initializes MyVector object (constructor)
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      Initialized MyVector object
     */

    MyVector() {
      //outfile.open("main.out");
	  
      head = tail = nullptr;
      size = 0;
    }
    
    /**
     * Public : MyVector
     * 
     * Description:
     *      Construct MyVector object from array
     * 
     * Params:
     *      int*    :  array of integers
     *      int     :  array size
     * 
     * Returns:
     *      Initialized MyVector object
     */

    MyVector(int *A, int size) {
      //outfile.open("main.out");
	  

      head = tail = nullptr;
      this->size = size;
      for (int i = 0; i < size; i++) {
        pushRear(A[i]);
      }
    }
    
    /**
     * Public : MyVector
     * 
     * Description:
     *      Construct MyVector object from input file
     * 
     * Params:
     *      string    :  name of file to be opened
     * 
     * Returns:
     *      Constructed MyVector object.
     */

    MyVector(string fileName) {
      //outfile.open("main.out");
	 

      int x = 0;           // variable where numbers from input file will
                           // be read in
      ifstream fin;
      fin.open(fileName);
      size = 0;
      
      while(!fin.eof()) { // Read input file loop
        fin >> x;
        pushRear(x);
        size++;
      }
      fin.close();       // close input file
    }

    /**
     * Public : MyVector
     * 
     * Description:
     *      Consructs MyVector object from another MyVector object
     *      (Copy Constructor)
     * 
     * Params:
     *      const MyVector    :  Other MyVector object
     * 
     * Returns:
     *      Constructed new MyVector object
     */

    MyVector (const MyVector &obj) {
      //outfile.open("main.out");
	  

      head = tail = nullptr;
      size = 0;
      node* temp = obj.head;


      while(temp != nullptr) { // loop through old object to get values
        pushRear(temp->data);
        temp = temp->next;
        size++;
      }
    }

    
    /**
     * Public : pushFront
     * 
     * Description:
     *      Adds value to front of vector-list (MyVector object)
     * 
     * Params:
     *      int     :  value to be added
     * 
     * Returns:
     *      None
     */

    void pushFront (int val) {
      if (head == nullptr) {
        head = tail = new node (val);
        head->next = nullptr;
        tail->next = nullptr;
      }
      else if (head == tail) {
        head = new node (val);
        head-> next = tail;
        tail->next = nullptr;
      }
      else {
        node* temp = head;
        head = new node (val);
        head -> next = temp;
      }
      size++;
    }

    /**
     * Public : pushFront
     * 
     * Description:
     *      Adds other MyVector object to front of "this" MyVector object
     * 
     * Params:
     *      MyVector     :  other MyVector object
     * 
     * Returns:
     *      None
     */
    void pushFront(MyVector vector) {
      node* temp = vector.head; // traversing pointer
      int sz = vector.size;     // needed for sizing of array
      sz/=2;                    // only works if I do this, don't know why
      int* arr = new int [sz];  // Array to hold values of other vector
                                // Array Needed to properly put items in order
                                // in "this" MyVector object
      for (int i = 0; temp!=nullptr; i++) { // For loop needed to place values
                                            // in array
        arr[i] = temp->data;
        temp = temp->next;
      }
      for (int i = sz-1; i >= 0; i--) { // For loop to go through array in
                                        // reverse and put items in proper
                                        // order in "this" MyVector object
        pushFront(arr[i]);
        this->size++;
      }
    }
    
    /**
     * Public : pushRear
     * 
     * Description:
     *      Adds value to rear of vector-list (MyVector object)
     * 
     * Params:
     *      int     :  value to be added
     * 
     * Returns:
     *      None
     */
    void pushRear (int val) {
      if (tail == nullptr) {          // In case vector is empty
        head = tail = new node (val);
      }
      else if (head == tail) {       // In case only one item in vector
        node* temp = new node (val); // Needed for creation of node and relinking
        tail = temp;
        head->next = tail;
        tail->next = nullptr;
        temp = nullptr;
        delete temp;
      }
      else {                         // When vector is filled with items
        node* temp;                  // Needed for proper relinking, old tail
        temp = tail;
        tail = new node (val);
        temp->next = tail;
        tail->next = nullptr;
      }
      size++;
    }

    /**
     * Public : pushRear
     * 
     * Description:
     *      Adds other MyVector object to rear of "this" MyVector object
     * 
     * Params:
     *      MyVector     :  other MyVector object
     * 
     * Returns:
     *      None
     */
    void pushRear (MyVector vector) {
      node* temp = vector.head; // Traverses old vector
      while (temp!=nullptr) {
        pushRear(temp->data);   // Adds item to "this" MyVector object
        temp = temp->next;
        this->size++;
      }
    }

    /**
     * Public : pushAt
     * 
     * Description:
     *      Adds value to specific index of MyVector object
     * 
     * Params:
     *      int     :  index where value will be added
     *      int     :  Value to be added
     * 
     * Returns:
     *      None
     */
    void pushAt (int loc, int val) {
      int count = 0;           // to count index # when traversing
      node* temp = head;       // Needed to traverse
      node* temp1 = nullptr;   // Needed for proper relinking
      if (loc == 0) {          // In case index is 0
        pushFront(val);
        return;
      }
      
      while (count != loc-1 && temp!=nullptr) { // Gets temp to desired index
        temp = temp->next;
        count++;
      }
      if (count != loc-1 || size<loc) {        // In case location out of bounds
        cout << "Location doesn't exist";
        return;
      }
      temp1 = temp;                           // Keeps track of previous node
                                              // for proper relinking
      temp = new node (val);                  // Pushes node
      temp->next = temp1->next;               // Properly relinks
      temp1->next = temp;                     // Properly relinks
      size++;
    }

    /**
     * Public : popFront
     * 
     * Description:
     *      Pops node at the front of MyVector object and returns its value
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      int      :  popped object
     */
    int popFront () {
      int popped;           // value to be popped and returned
      node* temp = head;    // Needed to relink and reconnect head
      head = head->next;    // Head moves to next node
      temp->next = nullptr; // Cuts linking from node about to be popped
      popped = temp->data;  // Stores data before deletion for return
      delete temp;          // Deletes popped node
      size--;
      return popped;
    }
    
    /**
     * Public : popRear
     * 
     * Description:
     *      Pops node at the rear of MyVector object and returns its value
     * 
     * Params:
     *      None
     * 
     * Returns:
     *      int      :  popped object
     */
  int popRear () {
    int popped;                   // value to be popped and returned
    node* temp = head;            // Needed to relink and reconnect tail
    while (temp->next != tail) {  // Travels to node before tail
      temp = temp->next;
    }
    tail = temp;                  // Moves tail back up by 1
    temp = temp->next;            // Moves temp to old tail
    tail->next = nullptr;         // Cuts off linking
    temp->next = nullptr;         // Cuts off linking
    popped = temp->data;          // Stores data before deletion
    delete temp;                  // Deletes popped node
    size--;
    return popped;
  }

    /**
     * Public : popAt
     * 
     * Description:
     *      Pops node at specified index and returns its value
     * 
     * Params:
     *      int     :  index to be popped
     * 
     * Returns:
     *      int   : popped valued
     */

  int popAt (int loc) {
    int popped = 0;
    int count = 0;                            // Needed to keep track of index
    node* temp = head;                        // Needed to traverse
    node* temp1 = nullptr;                    // Needed for proper relinking
    if (loc == 0) {                           // In case index is 0
      popped = popFront();
      return popped;
    }
    while (count != loc-1 && temp!=nullptr) { // Gets temp before desired index
      temp = temp->next;
      count++;
    }
    if (count != loc-1) {                     // In case index is out of bounds
      cout << "Location doesn't exist";
      return 0;
    }
    temp1 = temp->next;                      // temp1 will be the popped node
    popped = temp1->data;                    // Stores value before popping
    temp->next = temp1->next;                // Relinks skipping temp1
    temp1->next = nullptr;                   // Cuts linking
    delete temp1;                            // Deletes popped node
    size--;
    return popped;
  }

  /**
     * Public : find
     * 
     * Description:
     *      Searches for value and returns index
     * 
     * Params:
     *      int     :  value to search for
     * 
     * Returns:
     *      int     : index of value, if found
     */

  int find (int val) {
    int count = 0;                              // Keeps track of search index
    int trig = -1;                              // Trigger if there's a match
    node* temp = head;                          // Traverses object for match
    if (temp->data == val) {                    // Checks if head is a match
      return 0;
    }
    while (temp!=nullptr && temp->data != val) {// Travels until match is found
      temp = temp->next;
      count++;
      if (temp!=nullptr && temp->data == val) {// If match found, trigger is hit
                                               // and count updated
        trig = 1;
        count++;
      }
    }
    
    if (trig == 1) { // Checks if trigger was hit and returns index of match
      return count;
    }
    // cout << "Value not found";
    return -1;      // -1 is a sentinel value if no match is found
  }

    /**
     * Public : print
     * 
     * Description:
     *      Prints MyVector Object with more than one item to console and
     *      output file
     * 
     * Params:
     *      fstream&    :  Output file printing
     * 
     * Returns:
     *      None
     */

  void print(fstream &outfile) {
    // outfile.open("main.out", iostream::app);
    node* temp = head;             // Travels MyVector object to print
    outfile << "[";                // Styling
    cout << "[";                   // Styling
    while (temp!=nullptr) {        // Loop to print and traverse
      outfile << temp->data;
      cout << temp->data;
      if (temp->next!=nullptr) {
        cout << ", ";              // Styling
        outfile << ", ";           // Styling
      }
      temp = temp->next;           // Traverses
    }
    cout << "]";                   // Styling
    outfile << "]";                // Styling
    cout << '\n';                  // Styling
    outfile << '\n';               // Styling
    // outfile.close();
  }

    /**
     * Public : print
     * 
     * Description:
     *      Prints MyVector Object with only one item to console and
     *      output file
     * 
     * Params:
     *      fstream&    :  Output file printing
     * 
     * Returns:
     *      None
     */
  void print(int x,fstream  &outfile) {
    // outfile.open("main.out", iostream::app);

    cout << x << '\n';    // Prints to console
    outfile << x << '\n'; // Prints to output file
    // outfile.close();
  }

  // v1 = { 1, 2, 3, 4, 5 };
  // v2 = { 10, 20, 30 };

  MyVector operator+ (const MyVector& rhs) {
    MyVector temp;

    node* ttravel = this->head;
    node* rtravel = rhs.head;

    while (ttravel != nullptr && rtravel != nullptr) {
      temp.pushRear(ttravel->data + rtravel->data);
      ttravel = ttravel->next;
      rtravel = rtravel->next;
    }

    while (ttravel != nullptr) {
      temp.pushRear(ttravel->data);
      ttravel = ttravel->next;
    }
  
    while (rtravel != nullptr) {
      temp.pushRear(rtravel->data);
      rtravel = rtravel->next;
    }
      
    return temp;
  }

  MyVector operator- (const MyVector& rhs) {
    MyVector temp;

    node* ttravel = this->head;
    node* rtravel = rhs.head;

    while (ttravel != nullptr && rtravel != nullptr) {
      temp.pushRear(ttravel->data - rtravel->data);
      ttravel = ttravel->next;
      rtravel = rtravel->next;
    }

    while (ttravel != nullptr) {
      temp.pushRear(ttravel->data);
      ttravel = ttravel->next;
    }
  
    while (rtravel != nullptr) {
      temp.pushRear(rtravel->data);
      rtravel = rtravel->next;
    }
      
    return temp;
  }

  MyVector operator* (const MyVector& rhs) {
    MyVector temp;

    node* ttravel = this->head;
    node* rtravel = rhs.head;

    while (ttravel != nullptr && rtravel != nullptr) {
      temp.pushRear(ttravel->data * rtravel->data);
      ttravel = ttravel->next;
      rtravel = rtravel->next;
    }

    while (ttravel != nullptr) {
      temp.pushRear(ttravel->data);
      ttravel = ttravel->next;
    }
  
    while (rtravel != nullptr) {
      temp.pushRear(rtravel->data);
      rtravel = rtravel->next;
    }
      
    return temp;
  }

  MyVector operator/ (const MyVector& rhs) {
    MyVector temp;

    node* ttravel = this->head;
    node* rtravel = rhs.head;

    while (ttravel != nullptr && rtravel != nullptr) {
      temp.pushRear(ttravel->data / rtravel->data);
      ttravel = ttravel->next;
      rtravel = rtravel->next;
    }

    while (ttravel != nullptr) {
      temp.pushRear(ttravel->data);
      ttravel = ttravel->next;
    }
  
    while (rtravel != nullptr) {
      temp.pushRear(rtravel->data);
      rtravel = rtravel->next;
    }
      
    return temp;
  }

  friend ostream& operator<< (ostream& output, const MyVector& other) {
    node* temp = other.head;             // Travels MyVector object to print
    output << "[";                // Styling
    while (temp!=nullptr) {        // Loop to print and traverse
      output << temp->data;
      if (temp->next!=nullptr) {
        output << ", ";           // Styling
      }
      temp = temp->next;           // Traverses
    }
    output << "]";                // Styling
    output << '\n';
    return output;
  }

  friend fstream& operator<< (fstream& fout, const MyVector& other) {
    node* temp = other.head;             // Travels MyVector object to print
    fout << "[";                // Styling
    while (temp!=nullptr) {        // Loop to print and traverse
      fout << temp->data;
      if (temp->next!=nullptr) {
        fout << ", ";           // Styling
      }
      temp = temp->next;           // Traverses
    }
    fout << "]";                // Styling
    fout << '\n';
    return fout;
  }

  int& operator[] (int index) {
    node* travel = this->head;
    if (index > this->size/2) {
      cout << "Out of bounds";
      exit(0);
    }
    int count = 0;
    if (index == 0) {
      return travel->data;
    }
    while (count != index ) {
      travel = travel->next;
      count++;
    }
    return travel->data;
  }

  bool operator== (MyVector& rhs) {
    if (this->size != rhs.size) {
      return false;
    }
    node* travel = this->head;
    node* travel1 = rhs.head;
    if (travel->data != travel1->data) {
      return false;
    }
    while (travel != nullptr && travel1 != nullptr) {
      travel = travel->next;
      travel1 = travel1->next;
      if (travel != nullptr && travel1 != nullptr) {
        if (travel->data != travel1->data) {
          return false;
        }
      }
    }
  return true;
  }

  MyVector operator= (const MyVector rhs) {
    node* temp = this->head;
    node* trash;
    while (temp != nullptr) {
      trash = temp;
      temp = temp->next;
      delete trash;
    }

    // rest "this"
    this->head = this->tail = nullptr;
    this->size = 0;

    node* assign = rhs.head;
    
    while (assign != nullptr) {
      this->pushRear(assign->data);
      assign = assign->next;
    }
    return *this;
  }

};

int main() {
  int a1[] = { 1, 2, 3, 4, 5 };
  int a2[] = { 10, 20, 30 };

  MyVector v1(a1,5);
  MyVector v2(a2,3);

  ofstream fout;
  fout.open("output.txt");

  cout << v1[2] << endl;
  // writes out 3

  v1[4] = 9;
  // v1 now = [1,2,3,4,9]

  cout << v1 << endl;
  // writes out [1,2,3,4,9] to console.

  fout << v1 << endl;
  // writes out [1,2,3,4,9] to your output file.

  MyVector v3 = v1 + v2;
  cout << v3 << endl;
  // writes out [11,22,33,4,9] to console.

  v3 = v1 - v2;
  cout << v3 << endl;
  // writes out [-9,-18,-27,4,9] to console.

  v3 = v2 - v1;
  cout << v3 << endl;
  // writes out [9,18,27,4,9] to console.

  v3 = v2 * v1;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 * v2;
  cout << v3 << endl;
  // writes out [10,40,90,4,9] to console.

  v3 = v1 / v2;
  cout << v3 << endl;
  // writes out [0,0,0,4,9] to console.

  v3 = v2 / v1;
  cout << v3 << endl;
  // writes out [10,10,10,4,9] to console.

  cout << (v2 == v1) << endl;
  // writes 0 to console (false) .

  MyVector v4 = v1;
  cout << (v4 == v1) << endl;
  // writes 1 to console (true) .
  return 0;
}

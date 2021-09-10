#include <iostream>
#include <fstream>
using namespace std;

struct node {
  int data;
  node* next;
  node (int x) {
    data = x;
    next = nullptr;
  }
};

class MyVector {
  private:
    node* head;
    node* tail;
    int size;
    

  public:
    MyVector() {
      //outfile.open("main.out");
	  
      head = tail = nullptr;
      size = 0;
    }
    
    MyVector(int *A, int size) {
      //outfile.open("main.out");
	  

      head = tail = nullptr;
      this->size = size;
      for (int i = 0; i < size; i++) {
        pushRear(A[i]);
      }
    }

    MyVector(string fileName) {
      //outfile.open("main.out");
	 

      int x = 0;
      ifstream fin;
      fin.open(fileName);
      size = 0;
      
      while(!fin.eof()) {
        fin >> x;
        pushRear(x);
        size++;
      }
      fin.close();
    }

    MyVector (const MyVector &obj) {
      //outfile.open("main.out");
	  

      head = tail = nullptr;
      size = 0;
      node* temp = obj.head;
      while(temp != nullptr) {
        pushRear(temp->data);
        temp = temp->next;
        size++;
      }
    }

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

    void pushFront(MyVector vector) {
      node* temp = vector.head;
      int sz = vector.size;
      sz/=2;
      int* arr = new int [sz];
      for (int i = 0; temp!=nullptr; i++) {
        arr[i] = temp->data;
        temp = temp->next;
      }
      for (int i = sz-1; i >= 0; i--) {
        pushFront(arr[i]);
        this->size++;
      }
    }
    
    void pushRear (int val) {
      if (tail == nullptr) {
        head = tail = new node (val);
      }
      else if (head == tail) {
        node* temp = new node (val);
        tail = temp;
        head->next = tail;
        tail->next = nullptr;
        temp = nullptr;
        delete temp;
      }
      else {
        node* temp;
        temp = tail;
        tail = new node (val);
        temp->next = tail;
        tail->next = nullptr;
      }
      size++;
    }

    void pushRear (MyVector vector) {
      node* temp = vector.head;
      while (temp!=nullptr) {
        pushRear(temp->data);
        temp = temp->next;
        this->size++;
      }
    }

    void pushAt (int loc, int val) {
      int count = 0;
      node* temp = head;
      node* temp1 = nullptr;
      if (loc == 0) {
        pushFront(val);
        return;
      }
      
      while (count != loc-1 && temp!=nullptr) {
        temp = temp->next;
        count++;
      }
      if (count != loc-1 || size<loc) {
        cout << "Location doesn't exist";
        return;
      }
      temp1 = temp;
      temp = new node (val);
      temp->next = temp1->next;
      temp1->next = temp;
      size++;
    }

    int popFront () {
      int popped;
      node* temp = head;
      head = head->next;
      temp->next = nullptr;
      popped = temp->data;
      delete temp;
      size--;
      return popped;
    }
    
  int popRear () {
    int popped;
    node* temp = head;
    while (temp->next != tail) {
      temp = temp->next;
    }
    tail = temp;
    temp = temp->next;
    tail->next = nullptr;
    temp->next = nullptr;
    popped = temp->data;
    delete temp;
    size--;
    return popped;
  }

  int popAt (int loc) {
    int popped = 0;
    int count = 0;
    node* temp = head;
    node* temp1 = nullptr;
    if (loc == 0) {
      popped = popFront();
      return popped;
    }
    while (count != loc-1 && temp!=nullptr) {
      temp = temp->next;
      count++;
    }
    if (count != loc-1) {
      cout << "Location doesn't exist";
      return 0;
    }
    temp1 = temp->next;
    popped = temp1->data;
    temp->next = temp1->next;
    temp1->next = nullptr;
    delete temp1;
    size--;
    return popped;
  }

  int find (int val) {
    int count = 0;
    int trig = -1;
    node* temp = head;
    if (temp->data == val) {
      return 0;
    }
    while (temp!=nullptr && temp->data != val) {
      temp = temp->next;
      count++;
      if (temp!=nullptr && temp->data == val) {
        trig = 1;
        count++;
      }
    }
    
    if (trig == 1) {
      return count;
    }
    // cout << "Value not found";
    return -1;
  }

  void print(fstream &outfile) {
    // outfile.open("main.out", iostream::app);
    node* temp = head;
    outfile << "[";
    cout << "[";
    while (temp!=nullptr) {
      outfile << temp->data;
      cout << temp->data;
      if (temp->next!=nullptr) {
        cout << ", ";
        outfile << ", ";
      }
      temp = temp->next;
    }
    cout << "]";
    outfile << "]";
    cout << '\n';
    outfile << '\n';
    // outfile.close();
  }

  void print(int x,fstream  &outfile) {
    // outfile.open("main.out", iostream::app);

    cout << x << '\n';
    outfile << x << '\n';
    // outfile.close();
  }
};

int main() {
  int x = 0;

  fstream outfile;
  outfile.open("main.out", iostream::app);
  cout << "Yoseph Helal\n";
  cout << "September 10, 2021\n";
  cout << "Fall '21 2143\n\n";
  outfile << "Yoseph Helal\n";
  outfile << "September 10, 2021\n";
  outfile << "Fall '21 2143" << endl << endl;


  MyVector v1;
  v1.pushFront(18);
  v1.pushFront(20);
  v1.pushFront(25);
  v1.pushRear(18);
  v1.pushRear(20);
  v1.pushRear(25);
  v1.print(outfile);
  // [25, 20, 18, 18, 20, 25]

  int A[] = {11,25,33,47,51};
  MyVector v2(A,5);
  v2.print(outfile);
  // [11, 25, 33, 47, 51]

  v2.pushFront(9);
  //v2.inOrderPush(27);
  v2.pushRear(63);
  v2.print(outfile);
  // [9, 11, 25, 33, 47, 51, 63]

  v1.pushRear(v2);
  v1.print(outfile);
  // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

  x = v1.popFront();
  x = v1.popFront();
  x = v1.popFront();
  v1.print(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
  v2.print(x,outfile);
  // 18

  x = v1.popRear();
  x = v1.popRear();
  x = v1.popRear();
  v1.print(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]
  v2.print(x,outfile);
  // 47

  x = v2.popAt(3);
  v2.print(outfile);
  // [9, 11, 25, 33, 47, 51, 63]
  v2.print(x,outfile);
  // 27

  x = v2.find(51);
  v2.print(x,outfile);
  // 5

  x = v2.find(99);
  v2.print(x,outfile);
  // -1

  MyVector v3(v1);
  v3.print(outfile);
  // [18, 20, 25, 9, 11, 25, 27, 33]

  v3.pushFront(v2);
  v3.print(outfile);
  //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

  MyVector v4("input.dat");
  v4.pushRear(v3);
  v4.print(outfile);
  // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]
  outfile.close();
  return 0;
}

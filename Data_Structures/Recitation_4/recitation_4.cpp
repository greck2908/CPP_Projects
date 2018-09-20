#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class Queue
{
  private:
    Node *head;
    Node *tail;

  public:
    Queue();
    int size;
    int capacity;
    void enqueue(int data);
    Node* dequeue();
    void createQueue();
    void printQueue();
    bool isEmpty();
    bool isFull();
};

Queue::Queue()
{
  this->head = NULL;
  this->tail = NULL;
  int size = 0;
  int capacity = 10;
}

void Queue::createQueue()
{
    Node *node1 = new Node;
    node1->data = 1;
    node1->next = NULL;
    this->head = this->tail = node1;
    this->size++;

    Node *node2 = new Node;
    node2->data = 2;
    node2->next = NULL;
    this->head->next = node2;
    this->tail = node2;
    this->size++;

    Node *node3 = new Node;
    node3->data = 3;
    node3->next = NULL;
    this->head->next->next = node3;
    this->tail = node3;
    this->size++;

    Node *node4 = new Node;
    node4->data = 4;
    node4->next = NULL;
    this->head->next->next->next = node4;
    this->tail = node4;
    this->size++;
}

void Queue::printQueue()
{
    cout << "QUEUE ELEMENTS:" << endl;
    Node *iterator = this->head;
    while (iterator->next != NULL)
    {
      cout << iterator->data << " --> ";
      iterator = iterator->next;
    }
    cout << iterator->data << endl;
}

bool Queue::isEmpty()
{
  return (size == 0);
}

bool Queue::isFull()
{
  return (size == 10);
}

/*
/////////////////////////////////////
*************************************
      Implement this function
*************************************
/////////////////////////////////////
*/
void Queue::enqueue(int data)
{
  cout << "Enqueuing " << data << endl;
  if(!isFull()) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    tail->next = temp;
    this->tail = temp;
  }
  else {
    cout << "Queue full" << endl;
  }
}

/*
/////////////////////////////////////
*************************************
      Implement this function
*************************************
/////////////////////////////////////
*/
struct Node* Queue::dequeue()
{
  cout << "Dequeuing" << endl;
  if (!isEmpty()){
    size --;
    Node *temp = this->head->next;
    delete this->head;
    this->head = temp;
  }
  else {
    cout << "array is empty" << endl;
  }

  return NULL;
}

int main()
{
  Queue q;
  q.createQueue();

  // 1 --> 2 --> 3 --> 4
  q.printQueue();

  /*
    TODO:UNCOMMENT THE BELOW CODE ONCE enqueue() and dequeue() are implemented
  */

    cout << "PERFORMING QUEUE OPERATIONS" << endl;

    // Expected  1 --> 2 --> 3 --> 4 --> 5
    q.enqueue(5);
    q.printQueue();

    // Expected 2 --> 3 --> 4 --> 5
    q.dequeue();
    q.printQueue();

    // Expected 3 --> 4 --> 5
    q.dequeue();
    q.printQueue();

    // Expected 3 --> 4 --> 5 --> 6
    q.enqueue(6);
    q.printQueue();

    // Expected 4 --> 5 --> 6
    q.dequeue();
    q.printQueue();

}

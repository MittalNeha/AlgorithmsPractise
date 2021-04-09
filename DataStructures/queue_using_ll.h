#include <iostream>

using namespace std;

template<typename T>

class Node {
    public:
        T data;
        Node<T> *next;

        Node(T data) {
            this -> data = data;
            this -> next = NULL;
        }
};


template<typename T>

class Queue {

    private:
        Node<T> *head;
        Node<T> *tail;
        int     size;

    public:
        Queue(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void enqueue(T data) {
            Node<T> *newdata = new Node<T>(data);
            if(NULL == head)
            {
                head = newdata;
                tail = head;
            }
            else
            {
                tail->next = newdata;
                tail = tail-> next;
            }
            size++;
            cout << "[QUEUE_INFO]Pushed "<< data <<endl;
        }

        T dequeue() {
        
            if(isEmpty()){
                cout <<"[QUEUE_INFO]Queue UnderFlow\n";
                return 0;
            }
            Node <T> *temp = head;
            T data = temp-> data;
            head = head->next;
            size --;
            delete temp;
            cout<< "[QUEUE_INFO] Pop "<< data <<endl;
            return data;
        }

        int getsize() {
            return size;
        }

        bool isEmpty() {
            return 0 == size;
        }

        T front() {
            if(isEmpty()) {
                cout << "[QUEUE_INFO]Empty Queue"<<endl;
                return 0;
            }
            return head->data;
        }
};

#include <iostream>

using namespace std;

template<typename T>

class Node {
    public:
        T data;
        Node<T> *next;

        Node(T data)
        {
            this -> data = data;
            this -> next = NULL;
        }
};

template<typename T>
class Stack {
    private:
        Node<T>* head;
        int size;

    public:
        Stack() {
            head = NULL;
            size = 0;
        }
        void push(T data){
            Node<T> *newdata = new Node<T>(data);

            newdata->next = head;
            head = newdata;
            size++;            
        }

        T pop(){
            T data;
            if (size > 0){
                Node<T> *temp = head;
                head = head->next;
                size--;
                data = temp->data;
                delete temp;
                return data;
            } else {
                cout <<"Stack UnderFlow\n";
                return 0;
            }
        }

        T top() {
            if (isEmpty()) {
                cout << "Empty Stack"<<endl;
                return 0;
            }
            return head->data;
        }
        
        int getsize() {
            return size;
        }

        bool isEmpty() {
            return 0 == size;
        }
};

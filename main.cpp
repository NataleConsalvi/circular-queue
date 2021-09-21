#include <iostream>
#include <stdexcept>
 
#include "circular_queue.h"
 
using namespace std;
 
int main() {

    cout << "Starting" << endl;
    Nats::CircularQueue q(7); // 7 = capacity

    cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
    q.enqueue('a');
    int a = q.get_size();
    cout << "size of the queue " << a << endl;
    string s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    cout << "top of the queue: " << q.top() << endl;
    cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
    q.enqueue('b');
    cout << "top of the queue: " << q.top() << endl;
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    char x = q.dequeue();
    cout << "char dequeued: " <<  x << endl;
    q.dequeue();
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    q.enqueue('f');
    q.enqueue('g');
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    q.dequeue();
    q.dequeue();
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    q.enqueue('h');
    q.enqueue('i');
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    q.enqueue('l');
    q.enqueue('m');
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;            // coda piena

    /*
    try {       
        q.enqueue('z');
    } catch (std::runtime_error& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    */

    q.dequeue();  // e
    q.dequeue();  // f
    q.dequeue();  // g
    q.dequeue();  // h
    q.dequeue();  // i
    q.dequeue();  // l
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;
    cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
    q.dequeue();  // m
    cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
    s = q.stamp_queue();
    cout << "stamp of the queue: " << s << endl;

    /*
    try {
        q.dequeue();
    } catch (std::runtime_error& ex) {
        cout << "something bad happened!" << ex.what() << endl;
        cout << "I caught the exception, will continue" << endl;
    };
    */

    cout << "end of the program!" << endl;


    return 0;

}

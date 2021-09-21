#include <iostream>
#include <stdexcept>
 
#include "circular_queue.h"
 
using namespace std;
 
int main() {

   cout << "Starting" << endl;
   Nats::CircularQueue q(7); // 7 = capacity

   //cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
    q.enqueue('a');
    int a = q.get_size();
    cout << a << endl;
    string s = q.stamp_queue();
    cout << s << endl;
   
   //cout << "top of the queue: " << q.top() << endl;
   //cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   q.enqueue('b');
   //cout << "top of the queue: " << q.top() << endl;
   q.enqueue('c');
   q.enqueue('d');
   q.enqueue('e');
    s = q.stamp_queue();
    cout << s << endl;
   char x = q.dequeue();  // a
   cout << x << endl;   // a
   q.dequeue();   // b
   q.enqueue('f');
   q.enqueue('g');
   s = q.stamp_queue();
    cout << s << endl;
    q.dequeue();
    q.dequeue();
    s = q.stamp_queue();
    cout << s << endl;
    q.enqueue('h');
    q.enqueue('i');
    s = q.stamp_queue();
    cout << s << endl;

   //q.enqueue('h');
   //q.enqueue('i');
   /*
   // coda piena
   try {       
       q.enqueue('z');
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
   q.dequeue();  // c
   q.dequeue();  // d
   q.dequeue();  // e
   q.dequeue();  // f
   q.dequeue();  // g
   q.dequeue();  // h
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   q.dequeue();  // i
 
   cout << "is queue empty? " << (q.isEmpty() ? "true" : "false") << endl;
   try {
       q.dequeue();
   } catch (std::runtime_error& ex) {
       cout << "something bad happened!" << ex.what() << endl;
       cout << "I caught the exception, will continue" << endl;
   };
 
   cout << "end of the program!" << endl;
   
  
   return 0;
*/
}

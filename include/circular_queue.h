#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
 
 
#include <stdexcept>
#include <string>
#include <iostream>
 
using namespace std;

namespace Nats {

    void to_stamp (string msn);

    /** 
    * A circular queue of chars with a fixed capacity
    **/
    class CircularQueue {
      
        private:
            int capacity;
            int size;
            char *array;
            int head;

        public:

            /**
             * Initializes the queue, reserving space for a number of elements equal to provided capacity.         
                - If capacity is <= 0, throws std::invalid_argument
            **/       
            CircularQueue(int capacity);

            /** 
             * Destroys the instance, deleting any dynamic attribute
            */
            ~CircularQueue();  

            /** 
             * Return the size of the queue.
            */
            int get_size();
 
            /** 
            * Return the capacity of the queue, that is, the maximum number of allowed elements in the queue.
            */           
            int get_capacity();

            /**
            * Return true if the queue is empty, false otherwise.
            */    
            bool isEmpty();

            /**
            * Return the element at the head of the queue, without removing it.
                - If the queue is empty, raises std::runtime_error  
            */
            char top();
 
            /**
            * Enqueues provided element v at the end of the queue.
                - If the queue is full, raises std::runtime_error
            */           
            void enqueue(char c);

            /**
            *Removes head element and returns it.
                -If the queue is empty, raises a std::runtime_error
            */ 
            char dequeue();

            /**
            * Function that stamp completed queue.
            */ 
            string stamp_queue();

   };
  


};
 
 
 
#endif // CIRCULAR_QUEUE_H

#include "circular_queue.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
void Nats::to_stamp (string msn){
    cout << "DEBUG: " << msn << "." << endl;
}

Nats::CircularQueue::CircularQueue(int capacity){

    Nats::to_stamp("queue initialization");
    if(capacity <= 0){
        throw std::invalid_argument(std::string("Capacity is null or negative! Capacity =") + std::to_string(capacity));
    }
    this->capacity = capacity;
    this->array = new char[capacity];
    this->size = 0;
    this->head = 0;
    Nats::to_stamp("initialization completed");
    Nats::to_stamp("queue with capacity of " + to_string(capacity) + " items");
}

Nats::CircularQueue::~CircularQueue(){

    Nats::to_stamp("queue elimination");
    delete this->array; 
    Nats::to_stamp("elimination completed");
}

int Nats::CircularQueue::get_size(){
    return size;
}

int Nats::CircularQueue::get_capacity(){
    return capacity;
}

bool Nats::CircularQueue::isEmpty(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

char Nats::CircularQueue::top(){
    bool t = isEmpty();
    if(t == false){
        return array[head];
    }else{
        throw std::runtime_error("Queue is empty!");
    }
}

void Nats::CircularQueue::enqueue(char c){
    string s;
    Nats::to_stamp("enqueing char \"" + s.append(1,c) + "\"");
    if(size >= capacity){
        throw std::runtime_error("Queue is full!");
    }else{
        int calculated_tail = (head + size) % capacity;
        array[calculated_tail] = c;
        size++;
    }
}

char Nats::CircularQueue::dequeue(){
    
    if(size == 0){
        throw std::runtime_error("Queue is empty!");
    }else{
        char c = array[head];
        head = (head + 1) % capacity;
        size--;
        string s;
        Nats::to_stamp("dequeing char \"" + s.append(1,c) + "\"");
        return c;
    }
}

string Nats::CircularQueue::stamp_queue(){
    string s;
    int ct = (head + size) % capacity;
    s += "[";
    if(size != 0){
        if(head < ct){
            for(int i = 0; i < head; i++){
                s += "_";
                s += ", ";
            }
            for(int i = head; i < ct; i++){
                s += array[i];
                s += ", ";
            }
            for(int i = ct; i < capacity; i++){
                s += "_";
                s += ", ";
            }
        }else{
            for(int i = 0; i < ct; i++){
                s += array[i];
                s += ", ";
            }
            for(int i = ct; i < head; i++){
                s += "_";
                s += ", ";
            }
            for(int i = head; i < capacity; i++){
                s += array[i];
                s += ", ";
            }
        }
    }else{
        for(int i = 0; i < capacity; i++){
            s += "_";
            s += ", ";
        }
    }

    int i = s.size();
    s.resize(i -2);
    s += "]";
    return s;
}


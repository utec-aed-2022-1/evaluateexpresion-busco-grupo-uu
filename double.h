#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

template <typename T>
class DoubleList : public List<T> {
    private:
        Node<T>* head;
        Node<T>* tail;
        int nodes = 0;
    public:
        DoubleList() : List<T>() {}

        ~DoubleList(){ 
         	// TODO            
        }
        T front(){
            return this->head->data;
        }

        T back(){
            return tail->data; 
        }

        void push_front(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
            } else {
                newNode->next = this->head; 
                this->head->prev = newNode; 
                this->head = newNode; 
            }
            this->nodes = this->nodes + 1; 
        }

        void push_back(T data){
            Node<T>* newNode = new Node<T>(data);
            if(this->size()==0) {
                this->head = newNode; 
                this->tail = newNode; 
            } else {
                newNode->prev = this->tail; 
                this->tail->next = newNode; 
                this->tail = newNode;
            }
            this->nodes = this->nodes + 1; 
        }

        T pop_front(){
            Node<T>* deleteNode = this->head; 
            T result = deleteNode->data; 
            this->head = this->head->next; 
            if(this->size() != 1){
                delete this->head->prev; 
                this->head->prev = nullptr;
            }
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T pop_back(){
            Node<T>* deleteNode = this->tail; 
            T result = deleteNode->data; 
            this->tail = this->tail->prev; 
            if(this->size() != 1){
                delete this->tail->next;    
                this->tail->next = nullptr;
            }
            this->nodes = this->nodes - 1; 
            return result; 
        }

        T insert(T data, int pos){
            Node<T>* newNode = new Node<T>(data);
            int i = 0;
            Node<T>* tempNode1 = this->head;
            while (true){
                if(i + 2  == pos){
                    Node<T>* tempNode2 = tempNode1->next;
                    tempNode1->next = newNode; 
                    newNode->prev = tempNode1; 
                    newNode->next = tempNode2;
                    tempNode2->prev = newNode; 
                    break; 
                } else {
                    tempNode1 = tempNode1->next; 
                }
                i++; 
            } 
            this->nodes = this->nodes + 1; 
            return data; 
        }

        T& operator[](int pos){
            int closeHead = pos - 0; 
            int closeTail = this->size() - pos; 
            if(closeHead <= closeTail){
                Node<T>* tempNode = this->head; 
                int i = 0; 
                while (true){
                    if(i + 1  == pos){
                        return tempNode->data; 
                        break; 
                    } else {
                        tempNode = tempNode->next; 
                    }
                i++; 
                }    
            } else {
                Node<T>* tempNode = this->head; 
                int i = this->size(); 
                while (true){
                    if(i - 1  == pos){
                        return tempNode->data; 
                        break; 
                    } else {
                        tempNode = tempNode->prev; 
                    }
                i--; 
                }   
            }
        }
        
        bool is_empty(){
            if(this->nodes == 0)return true;
            return false; 
        }

        int size(){
            return this->nodes;
        }
        
        void clear(){
            /*
            Node<T>* tempNode = this->head;
            while(this->head != nullptr){
                if(this->head->next != nullptr){
                    tempNode = this->head->next; 
                }
                if(this->head->next != nullptr){
                    this->head->killSelf(); 
                    this->head = tempNode; 
                    if(this->head->next == nullptr){
                        this->head->killSelf(); 
                        this->head = nullptr; 
                    }
                }
                this->nodes--;
            }
            this->tail = nullptr; 
            this->nodes--;
            */
            while(true){
                std::cout << this->head->data;
                if(this->head->next == nullptr){
                    break; 
                }
                this->pop_front();
            }
        }

        void precedencia(){
            std::string especial = "(";
            std::cout << "MANDRAGORA";

        }
        std::string name(){
            return "DoubleList";
        }
        
};
#endif
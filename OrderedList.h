//
//  OrderedList.h
//  Ordered List
//
//  Created by Allen Moody on 10/24/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//
#ifndef ORDEREDLIST_H_INCLUDED
#define ORDEREDLIST_H_INCLUDED
// Allen Moody Program 5 ListInsertionSort
template <typename T>
struct SLNode {
    T datum;
    SLNode<T> * next;
};

template <typename T>
class OrderedList {
private:
    SLNode<T> * head;  // head of the list
    SLNode<T> * curr; // ptr for rudimentary iteration
    SLNode<T> * temp; // ptr for temp storage
public:
    OrderedList() {
        head = curr = NULL;
       
    }
    // Didn't use
    void insertSecondItem(T item){
        temp = new SLNode<T>;
        temp -> datum = item;
        temp -> next = NULL;
        head -> next = temp;
        curr = temp;
    }
    // Used
    void insertAtEnd(T item){
        temp = new SLNode<T>;
        temp -> datum = item;
        temp -> next = NULL;
        curr -> next = temp;
        curr = temp;
    }
    // Used
    void insertFirstItem(T item){
        temp = new SLNode<T>;
        temp -> datum = item;
        temp -> next = NULL;
        head = temp;
        curr = temp;
        
    }
    
    void start (){
        curr=head;
    }
    
    bool hasNext (){
        return curr != NULL;
    }
    
    T next () {
        T value;
        
       value = curr -> datum;
        
        
        curr = curr -> next;
        
        return value;
        
    }
    
    void insertItem(T item) {
        
        
        // If list is empty, start list
        if (head == NULL)
        {
            insertFirstItem(item);
        }
        
        
        
        else {
            
        if    (item < head -> datum)
        {   temp = new SLNode<T>;
            temp -> datum = item;
            temp -> next = head;
            head = temp;
            curr = temp;
            
        }
        // If item is less than head, becomes new head
     
        else {
            
            start();
            while (curr -> next!= NULL && curr -> next -> datum <= item) {
                curr = curr -> next;
            }
            // If the last item in the list
            if (curr -> next == NULL) {
                insertAtEnd(item);
            }
            // If item is in between two other items
            else
            {   temp = new SLNode<T>;
                temp -> datum = item;
                temp -> next = curr -> next;
                curr -> next = temp;
                curr = temp;
            }
         
        }
        }        
    }
    
   
};

#endif // ORDEREDLIST_H_INCLUDED
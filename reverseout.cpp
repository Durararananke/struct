#include<iostream>
struct Node
{
    int data;
    Node *next;
};
using Linklist = Node *;
void ReverseOut(Linklist L){
    if(L->next)
        ReverseOut(L->next);
    if(L){
        std::cout << L->data << " ";
    }
}
#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;
class node{
	private:
		int data;
		node *prev;
		node *next;
	friend class DoublyLinkedList;
};
class DoublyLinkedList{
	private:
		node *head;
	public:
		DoublyLinkedList(){
			head=NULL;
		}
		~DoublyLinkedList(){
			while(head!=NULL){
				node *p=head;
				head=head->next;
				p->next=NULL;
				delete p;
			}
		}
		void insert_ascending(int value);
		void insert_descending(int value);
		void insert_front(int value);
		void insert_rear(int value);
		void insert_after(int n, int value);
		void insert_before(int n, int value);
		void erase(int value);
		void display_one(int n);
		void display_forward();
		void display_backward();
		void search(int value);
		bool isEmpty();
		int length();
};
#endif
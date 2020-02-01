#include "DLL.h"
void DoublyLinkedList::insert_ascending(int value){
	node *temp=new node;
	temp->data=value;
	if(head==NULL)
		head=temp;
	else if(temp->data < head->data){
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	else{
		node *p=head;
		node *q=head;
		while(p!=NULL && (p->data < temp->data)){
			q=p;
			p=p->next;
		}
		if(p!=NULL){
			temp->next=p;
			p->prev=temp;
			temp->prev=q;
			q->next=temp;
		}
		else{
			q->next=temp;
			temp->prev=q;
			p->prev=NULL;
		}
	}
}
void DoublyLinkedList::insert_descending(int value){
	node *temp=new node;
	temp->data=value;
	if(head==NULL)
		head=temp;
	else if(temp->data > head->data){
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	else{
		node *p=head;
		node *q=head;
		while(p!=NULL && (p->data > temp->data)){
			q=p;
			p=p->next;
		}
		if(p!=NULL){
			temp->next=p;
			p->prev=temp;
			temp->prev=q;
			q->next=temp;
		}
		else{
			q->next=temp;
			temp->prev=q;
			p->prev=NULL;
		}
	}
}
void DoublyLinkedList::insert_front(int value){
	node *temp=new node;
	temp->data=value;
	if(head==NULL)
		head=temp;
	else{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
}
void DoublyLinkedList::insert_rear(int value){
	node *temp=new node;
	temp->data=value;
	if(head==NULL)
		head=temp;
	else{
		node *p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
		temp->prev=p;
	}
}
void DoublyLinkedList::insert_after(int n, int value){
	if(n<1)
		cout<<"The entered position value can not be less than 1"<<endl;
	else if(n>length())
		cout<<"The entered position value is greater than the length of the list."<<endl;
	else{
		node *temp=new node;
		temp->data=value;
		if(n!=length()){
			node *p=head;
			node *q=head;
			while(n--){
				q=p;
				p=p->next;
			}
			temp->next=p;
			p->prev=temp;
			temp->prev=q;
			q->next=temp;
		}
		else{
			node *p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
			temp->prev=p;
		}
	}
}
void DoublyLinkedList::insert_before(int n, int value){
	if(n<1)
		cout<<"The entered position value can not be less than 1"<<endl;
	else if(n>length())
		cout<<"The entered position value is greater than the length of the list."<<endl;
	else{
		node *temp=new node;
		temp->data=value;
		if(n!=1){
			node *p=head;
			node *q=head;
			while(--n){
				q=p;
				p=p->next;
			}
			temp->next=p;
			p->prev=temp;
			temp->prev=q;
			q->next=temp;
		}
		else{
			temp->next=head;
			head->prev=temp;
			head=temp;
		}
	}
}
void DoublyLinkedList::erase(int value){
	if(head==NULL)
		cout<<"List is empty"<<endl;
	else{
		if(head->data==value){
			if(head->next!=NULL){
				node *p=head;
				head=head->next;
				head->prev=NULL;
				p->next=NULL;
				delete p;
			}
			else
				head=NULL;
		}
		else{
			node *p=head;
			node *q=head;
			while(p!=NULL && p->data!=value){
				q=p;
				p=p->next;
			}
			if(p!=NULL){
				node *temp=p->next;
				q->next=temp;
				temp->prev=q;
				p->next=NULL;
				p->prev=NULL;
				delete p;
			}
			else
				cout<<value<<" is not in the list"<<endl;
		}
	}
}
void DoublyLinkedList::display_one(int n){
	if(n>0){
		node *p=head;
		while(--n>0)
			p=p->next;
		cout<<p->data<<endl;
	}
	else
		cout<<"The input value is small"<<endl;
}
void DoublyLinkedList::display_forward(){
	if(head==NULL)
		cout<<"List is empty"<<endl;
	else{
		node *p=head;
		do{
			cout<<p->data<<' ';
			p=p->next;
		}while(p!=NULL);
		cout<<endl;
	}
}
void DoublyLinkedList::display_backward(){
	if(head==NULL)
		cout<<"List is empty"<<endl;
	else{
		node *p=head;
		while(p->next!=NULL)
			p=p->next;
		while(p!=NULL){
			cout<<p->data<<' ';
			p=p->prev;
		}
		cout<<endl;
	}
}
void DoublyLinkedList::search(int value){
	if(head!=NULL){
		node *p=head;
		while(p!=NULL && p->data!=value)
			p=p->next;
		if(p!=NULL)
			cout<<p->data<<" is in the list"<<endl;
		else
			cout<<value<<" is not in the list"<<endl;
	}
	else
		cout<<"List is empty"<<endl;
}
bool DoublyLinkedList::isEmpty(){
	if(head==NULL)
		return true;
	else
		return false;
}
int DoublyLinkedList::length(){
	int count=0;
	node *p=head;
	while(p!=NULL){
		count++;
		p=p->next;
	}
	return count;
}
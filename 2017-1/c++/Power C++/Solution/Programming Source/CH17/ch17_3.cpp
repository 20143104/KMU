#include <iostream>

using namespace std;

template<typename T>
class Node{
public:
	T data;
	Node()
	{
		data = 0;
		next = NULL;
		previous = NULL;
	}
	Node(T d)
	{
		data = d;
		next = NULL;
		previous = NULL;
	}
	Node<T> *next;
	Node<T> *previous;
	Node<T>* setNext(Node<T> *p, T d){
		Node *temp; 
		temp = new Node<T>;
		temp->data = d;
		temp->next = NULL;
		if(p->next == NULL){
			temp->previous = p;
			p->next = temp;
		}
		else{
			while(p->next!=NULL){
				p = p->next;
			}
			temp->previous = p;
			p->next = temp;
		}
		return p;
	}
};



int main(void)
{
	Node<int> *node;
	node = new Node<int>;
	node->setNext(node, 1);
	node->setNext(node, 2);
	node->setNext(node, 3);
	node->setNext(node, 4);

	cout<<"intÇü : [1,2,3,4]"<<endl;

	cout<<node->data<<endl;
	node = node->next;
	cout<<node->data<<endl;
	node = node->next;
	cout<<node->data<<endl;
	node = node->next;
	cout<<node->data<<endl;
	node = node->next;
	cout<<node->data<<endl;
	
	Node<double> *dnode;
	dnode = new Node<double>;
	dnode->setNext(dnode, 1.1);
	dnode->setNext(dnode, 2.2);
	dnode->setNext(dnode, 3.3);
	dnode->setNext(dnode, 4.4);

	cout<<"doubleÇü : [1.1,2.2,3.3,4.4]"<<endl;

	cout<<dnode->data<<endl;
	dnode = dnode->next;
	cout<<dnode->data<<endl;
	dnode = dnode->next;
	cout<<dnode->data<<endl;
	dnode = dnode->next;
	cout<<dnode->data<<endl;
	dnode = dnode->next;
	cout<<dnode->data<<endl;

	delete node;
	delete dnode;
	return 0;	
}

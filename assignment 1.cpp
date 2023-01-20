#include<iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* next;
	Node* previous;
	void insertbegining(int data);
	void insertEnd(int data);
	void insertspecific(int data, int key);
	void display();
};
Node *head=NULL;
//Insert at the beginning of the list.
void Node::insertbegining(int data)
{
  Node *ptr = new Node();
  ptr->data = data;
  ptr->next = NULL; 
  ptr->previous = NULL;
  if(head == NULL) {
    head = ptr;
  } else {
    head->previous = ptr;
    ptr->next = head;
    head = ptr;
  }    
}
//o	Insert at the end of the list.
void Node::insertEnd(int data)
{
  Node *ptr= new Node();
  ptr->data =data;
  ptr->next = NULL; 
  ptr->previous = NULL;
  if(head == NULL) {
    head = ptr;
  } else {
    Node* temp = head;
    while(temp->next != NULL)
      temp = temp->next;
    temp->next = ptr;
    ptr->previous = temp;
  }    
}
void Node::display()
{
	
	if(head==NULL){
		cout<<"List is Empty : "<<endl;
	}
	else{
		Node *ptr=head;
		cout<<"\n List After Inseration: "<<endl;
		while(ptr!=NULL)
		{
		
		cout<<ptr->data<< " ";
		ptr=ptr->next;
		}
		cout<<endl;
	}
}
//o	Insert at specific location in the list.
void Node::insertspecific(int data, int key)
{
	Node *ptr = new Node(); 
  ptr->data = data;
  ptr->next = NULL;
  ptr->previous = NULL;
  if(key< 1) {
    cout<<"\nPosition should be >= 1.";
  } else if (key == 1) {
    ptr->next = head;
    head->previous = ptr;
    head = ptr;
  } else {
    Node *temp = head;
    for(int i = 1; i < key-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
    if(temp != NULL) {
      ptr->next = temp->next;
      ptr->previous= temp;
      temp->next = ptr;
      if(ptr->next != NULL)
       ptr->next->previous = ptr;  
    } else {
      cout<<"\nThe Previous Node is NULL";
    } 
  }
}
int main()
{    
    Node obj;
    cout<<"\n \n \t Insertion "<<endl;
    cout<<"\n a) Insertion at the Begining of the List"<<endl;
    obj.insertbegining(6);
    obj.insertbegining(8);
    obj.insertbegining(9);
    obj.insertbegining(11);
     obj.display();
     cout<<"\n b) Insertion at the End of the List"<<endl;
     obj.insertEnd(21);
     obj.insertEnd(22);
     obj.insertEnd(23);
    obj.insertEnd(24);
     obj.display();
     cout<<"\n c) Insertion at the Sepcific Loaction in the List"<<endl;
     obj.insertspecific(10,3);
     obj.display();
    return 0;
}


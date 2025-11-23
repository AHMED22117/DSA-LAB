#include<iostream>
#include<string>
using namespace std;

struct Node
{
	int key;
	string name;
	Node* next;
	
	Node(int k,string n)
	{
		key=k;
		name=n;
		next=NULL;	
	}
};
const int size=10;
class hashing
{
	Node*table[size];
	
	int hashfunc(int key)
	{
		return key % size;
	}
public:
	hashing()
	{
		for(int i=0;i<size ; i++)\
		{
			table[i]=NULL;
		}
	}
	
	void insert(int key,string name)
	{
		int index=hashfunc(key);
		Node*newnode=new Node(key,name);
		if(table[index] == NULL)
		{
			newnode->next=table[index];
			table[index]=newnode;
		}
		else
		{
			Node*current=table[index];
			while(current != NULL)
			{
				if(current -> key == key)
				{
					current -> name = name;
					return;
				}
				current=current->next;
			}
			newnode->next=table[index];
			table[index]=newnode;
		}
	}
	
	
	void search(int key)
	{
		int index=hashfunc(key);
		Node* current=table[index];
		
		while(current != NULL )
		{
			if(current -> key == key)
			{
				cout<<"VALUE FOUND: "<<current -> name<<endl;
			}
			current=current ->next;
		}
		cout<<"value not found"<<endl;	 
	}
	
	
	void deletenode(int key)
	{
		int index=hashfunc(key);
		Node* temp=table[index];
		Node* prev=NULL;
		
		while(temp != NULL && temp -> key != key)
		{
			temp=temp->next;
			prev=temp;
		}
		if(temp == NULL)
		{
			cout<<"KEY : "<<key<<" NOT FOUND"<<endl;
			return;
		}
		if(prev == NULL)
		{
			table[index]=temp->next;
		}
		else
		{
			prev->next=temp->next;
		}
		delete temp;
		cout<<"KEY : "<<key<<" FOUND"<<endl;
	}

void display()
{
	for(int i=0;i<size;i++)
	{
		if(table[i] != NULL)
		{
			Node* current=table[i];
			while(current != NULL)
			{
				cout << "[" << current->key << " : " << current->name << "] -> ";
				current=current->next;
			}
			cout << "NULL" << endl;
		}
	}
}
};

int main()
{
		hashing a;
	a.insert(1, "FASTNU");
    a.insert(2, "CS");
    a.insert(3, "ENGINEERING");
    a.display();
    a.search(1);
    a.search(5);
    a.deletenode(2);
    a.deletenode(1);
    a.display();
}
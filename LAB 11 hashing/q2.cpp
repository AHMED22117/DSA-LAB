#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string name;
	string key;
	Node* next;
	
	Node(string k,string n)
	{
		key=k;
		name=n;
		next = NULL;
	}
};

const int size=100;

class hashing{
	Node* dictonary[100];
	
	int hashfunc(string key)
	{
		int sum=0;
		for(char ch :key)
		{
			sum += ch;
		}
		return sum % size;
	}
	
	public:
		hashing()
		{
			for(int i=0;i < size; i++)
			{
				dictonary[i]=NULL;
			}
		}
		
		void insert(string key,string name)
		{
		    Node* newnode= new Node(key,name);
			int index=hashfunc(key);
			
			if(dictonary[index] == NULL)
			{
				newnode->next=dictonary[index];
			}
			Node*current=dictonary[index];
			
			while(current != NULL)
			{
				if(current -> key == key)
				{
					current-> name = name;
					return;
				}
				current=current -> next;
			}
			newnode->next=dictonary[index];
			dictonary[index]=newnode;
		}
		
		string search(string key)
		{
			int index=hashfunc(key);
			Node*current = dictonary[index];
			
			while(current != NULL)
			{
				if(current -> key == key)
				{
					return current -> name;
				}
				current=current->next;
			}
			return"Key not found";
		}
		
		void display()
		{
			for(int i=0 ;i< size ;i++)
			{
				if(dictonary[i] != NULL)
				{
			cout << "Dictonary " << i << ": ";
    		Node*current=dictonary[i];
    		while (current != NULL)  {
                cout << "[" << current->key << " : " << current->name << "] -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
			}
		}
		}
		
		void deletenode(string key)
		{
			int index=hashfunc(key);
			Node*temp =dictonary[index];
			Node*prev=NULL;
			
			while(temp != NULL && temp->key != key)
			{
				temp=temp->next;
				prev=temp;
			}
			
			if(temp == NULL)
			{
				cout<<"KEY "<<key<<"NOT FOUND"<<endl;
			}
			
			if(prev == NULL)
			{
				dictonary[index]=temp->next;
			}
			else
			{
				prev->next=temp->next;
			}
			delete temp;
			cout<<"KEY "<<key<<" deleted"<<endl;
		}
};

int main()
{
	hashing a;
	a.insert("AB", "FASTNU");
    a.insert("CD", "CS");
    a.insert("EF", "ENGINEERING");
    a.display();
    a.search("AB");
    a.search("XB");
    a.deletenode("EF");
    a.deletenode("XY");
    a.display();
    
    
}
#include<iostream>
#include<string>
using namespace std;

struct Node
{
	string key;
	string name;
	Node*next;
	
	Node(string k,string n)
	{
		key=k;
		name=n;
		next=NULL;
	}
};

const int size=10;

class hashing
{
	Node* table[size];
	
	int hashfunc(string key)
{
	int sum=0;
	for(char ch: key)
	{
		sum += ch;
	}
	return sum % size;
}

public:
	hashing()
	{
	for(int i=0;i<size;i++)
	{
		table[i]=NULL;
	}
}
	void insert(string key,string name)
	{
		int index=hashfunc(key);
		Node*current =table[index];
		
		
		while(current != NULL)
		{
			current = current->next;
		}
		
		Node* newnode=new Node(key,name);
		newnode->next=table[index];
		table[index]=newnode;
	}
	
	string search(string key)
	{
		int index=hashfunc(key);
		Node*current=table[index];
		
		while(current != NULL)
		{
			if(current -> key == key)
			{
				return current-> name;
			}
			current=current->next;
		}
		return"Value NOT found";
    }  
    
    void display()
    {
    	for(int i=0; i < size ;i++)
    	{
    		cout << "TABLE " << i << ": ";
    		Node*current=table[i];
    		while (current) {
                cout << "[" << current->key << " : " << current->name << "] -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }
	};
    
int main()
{
	hashing h;
	h.insert("A","aaaaa");
	h.insert("B","bbbbb");
	h.insert("C","ccccc");
	h.insert("A","zzzzz");
	
	h.display();
	}    
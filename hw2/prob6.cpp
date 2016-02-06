#include <iostream>
#include <sstream>
#include <cstring> 

using namespace std;

struct Node {
    int value;
    Node *next;
};

Node* merge (Node*& first, Node*& second){
	Node* result;
//assume we were given valid inputs
	int fvalue = first->value;
	int svalue = second -> value;

	//cout << "beginning: " << fvalue << " " << svalue << endl;
	if (!first->next) //this is the last node in first
	{  
	    if(fvalue<=svalue)//the last node AND first's last node is bigger
	    // than the one you're comparing to
		{
			first->next=second;
			result = first;
		}
		else if (!second->next)//they're both the last node in their list
		{//already know first>second so first is last on list
			second -> next = first;
			result = second;
		}
		else//we have to keep going using the 
			//same node of first list and the rest of second
		{
			second -> next =merge(first, second -> next);
			result = second;
			
		}
	}
	else if (!second->next) //this is the last node in second
	{//already have a test if both are last node

		if (svalue <= fvalue)//second value is smaller than all of 
			//the rest of first list
		{
			second->next = first;
			result = second;
		
		}
		else //second value is bigger than the one in first
			//have to keep going with the last node of second and
			//the rest of first
		{
			first->next= merge(first->next, second);
			result = first;
		}
	}
	else if (fvalue <= svalue)//if it's not the end of EITHER list
	{  
					
		first->next = merge (first->next, second);
		result = first;
					
	}
	else if (fvalue > svalue)
	{ 
		second -> next = merge (first, second -> next);
		result = second;
		
	}

	return result;
}

int main (){
  	//this is a simple test I made
  	//it makes two arrays of size two
  	Node* one;
  	one= new Node();
	one->value = 1;

	Node* five;
	five = new Node();
	five->value = 5;
	one->next = five;
	//[1,5]
	Node* two;
	two = new Node();
	two->value = 2;
	Node* four;
	four = new Node();
	four-> value = 4;
	two->next = four;
	four->next = NULL;
	//[2, 4]

	//Now lets call merge on these two babies
	Node* test;
	test = merge(one, two);
	one = NULL; 
	two = NULL;
	//set the array to NULL so we can't touch them
	//just in case it didn't work
	if (!test->value)
		{cout<<"FAIL"<<endl;}
	//couts the order of the array
	while(test->next)
		{cout<<"HERE: "<<test->value<<endl;
		test = test->next;
		}
		//missed one!
	cout <<"Last one: "<<test->value<<endl;
	


	return 0;
}
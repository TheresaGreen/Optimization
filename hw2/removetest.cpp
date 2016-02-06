#include "llistint.h"
#include <iostream>

using namespace std;

//note to reader I am going to comment everything out that should give and error and abort


int main() {
	LListInt *tester = new LListInt();

	if (tester->empty())
		{
			cout<< "SUCCESS: Lovely it worked you have a new empty List!"<<endl;
		}	
	else
	{
		cout<<"FAIL: Uhoh no List was made! Check yourself before you wreck yourself"<<endl;
	}

	//let's give ourselves something to test!
	tester->insert(0,0);
	
	//test on just one
	tester->remove(0);
	if (tester->size()==0){
		cout<<"SUCCESS: removing the only item is fine"<<endl;
	}
	else 
	{
		cout<<"FAIL: removing the only item didn't work"<<endl;
		cout<<"Vaule of posistion 0 is"<<tester->get(0)<<endl;
	}

	tester->insert(0,0);
	tester->insert(1,1);
	tester->insert(2,2);
	tester->insert(3,3);
	tester->insert(4,4);
	tester->insert(5,5);

	//let's try to remove from the end of the list
	tester->remove(5);
	cout<<"This list is now: "<<tester->get(0)<<tester->get(1)<<tester->get(2)<<tester->get(3)<<tester->get(4)<<endl;

	//check to see if it's the right size
	if (tester->size()==5)
	{
		cout<<"SUCCESS: the size is now 5!"<<endl;
	}
	else
	{
		cout<<"FAIL: The size is now: "<<tester->size()<<endl;
	}

	cout<<"This list is now: "<<tester->get(0)<<tester->get(1)<<tester->get(2)<<tester->get(3)<<tester->get(4)<<endl;




	//let's see if it's gone!
	//this should make it return an invalid argument which it did
	
	/*if (!tester->get(5))
	{
		cout<<"SUCCESS:The item in posisiton 5 is now gone"<<endl;
	}
	else
	{
		cout<<"FAIL:There is: "<<tester->get(5)<<" in index 5"<<endl;
	}*/

	//removing from beggining of the list
	tester->remove(0);
	if (tester->size()==4)
	{
		cout<<"SUCCESS: the size is now 4!"<<endl;
	}
	else
	{
		cout<<"FAIL: The size is now: "<<tester->size()<<endl;
	}
	cout<<"This list is now: "<<tester->get(0)<<" "<<tester->get(1)<<" "<<tester->get(2)<<" "<<tester->get(3)<<endl;

	

	//finally let's check if we can remove from the middle
	//reminder the list is now [1,2,3,4]

	tester->remove(2);
	if (tester->size()==3)
	{
		cout<<"SUCCESS: the size is now 3!"<<endl;
	}
	else
	{
		cout<<"FAIL: The size is now: "<<tester->size()<<endl;
	}

	//reminder our list is now [1,2,4] let's check!!

	if (tester->get(0)==1){
		cout<<"SUCCESS: The first in the list is 1"<<endl;
	}
	else 
	{
		cout<<"FAIL: The first in the list is "<<tester->get(0)<<endl;
	}

	if (tester->get(1)==2){
		cout<<"SUCCESS: The second in the list is 2"<<endl;
	}
	else 
	{
		cout<<"FAIL: The second in the list is "<<tester->get(0)<<endl;
	}

	if (tester->get(2)==4){
		cout<<"SUCCESS: The 3rd in the list is 4"<<endl;
	}
	else 
	{
		cout<<"FAIL: The third in the list is "<<tester->get(0)<<endl;
	}


return 0;
}
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


	// lets try insert for the first time
    //this will be adding to an empty list

  	tester->insert(0, 0);

  	// make sure list is still empty.
  	if (!tester->empty())
  	 {
    cout << "SUCCESS: List is not empty after insertion!" << endl;
 	 } 
	else 
	 {
    cout << "FAIL: List is empty after insertion!" << endl;
     }

    if (tester->size() == 1)
     {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
     } 
    else
     {
    cout << "FAIL: List has size " << tester->size() << " after one insertion.";
    cout << endl;
     }

  // Check if the value is correct.
    if (tester->get(0) == 0) {
    cout << "SUCCESS: 0 is at the 0th index of the list." << endl;
    } 

    else {
    cout << "FAIL: 0 is not at the 0th index of the list, " << tester->get(0);
    cout << " is instead." << endl;
    }

  //Let's try to add onto the end of the List!

    tester->insert(1, 1);
    //let's see if the list is the right size!
    if (tester->size()==2)
    {
    	cout<<"SUCCESS: List has size two now"<<endl;
    }
    else
    {
    	cout<<"FAIL: List has size"<< tester->size()<<endl;
    }
    //double check it's the right value! should be [0,1]
    cout<<"This list is now: "<<tester->get(0)<<" "<<tester->get(1)<<endl;


    if(tester->get(1)==1)
    {
    	cout<<"SUCCESS: The value in the 1st index is 1!"<<endl;
    }
    else
    {
    	cout<<"FAIL:The value in the 1st index is: "<<tester->get(1)<<endl;
    }

	//Let's put an item into the middle of the list

	 tester->insert(1, 3);

   
    //let's see if the list is the right size!
    if (tester->size()==3)
    {
    	cout<<"SUCCESS: List has size three now"<<endl;
    }
    else
    {
    	cout<<"FAIL: List has size"<< tester->size()<<endl;
    }

    //let's see if that value is correct [0,3,1]
    
    cout<<"This list is now: "<<tester->get(0)<<" "<<tester->get(1)<<" "<<tester->get(2)<<endl;
//too wordy!

/*
            if(tester->get(1)==3)
            {
            	cout<<"SUCCESS: The value in the 1st index is 3!"<<endl;
            }
            else
            {
            	cout<<"FAIL:The value in the 1st index is: "<<tester->get(1)<<endl;
            }

            //let's make sure we didn't mess up the rest of the list
            
            if(tester->get(0)==12)
            {
            	cout<<"SUCCESS: The value in the 1st index is 12!"<<endl;
            }
            else
            {
            	cout<<"FAIL:The value in the 1st index is: "<<tester->get(1)<<endl;
            }
            if(tester->get(2)==14)
            {
            	cout<<"SUCCESS: The value in the 3rd index is 14!"<<endl;
            }
            else
            {
            	cout<<"FAIL:The value in the 3rd index is: "<<tester->get(1)<<endl;
            }
    */

    //let's try and add to the head of the list!

    tester->insert(0, 2);
    //let's see if the list is the right size!
    if (tester->size()==4)
    {
    	cout<<"SUCCESS: List has size four now"<<endl;
    }
    else
    {
    	cout<<"FAIL: List has size"<< tester->size()<<endl;
    }

    //double check it's the right value should be [2,0,1,3]
    cout<<"This list is now: "<<tester->get(0)<<" "<<tester->get(1);
    cout<<" "<<tester->get(2)<<" "<<tester->get(3)<<endl;

    if(tester->get(0)==2)
    {
    	cout<<"SUCCESS: The value in the 1st index is now 2!"<<endl;
    }
    else
    {
    	cout<<"FAIL:The value in the 1st index is now: "<<tester->get(1)<<endl;
    }


    //see if it'll let us put something where we shouldn't
	//there is no posistion -1  
	//tester->insert(-1, 12);
	
	//there is no posistion 5
	//tester->insert(5, 82);
	
    //everything worked as it should!! Yay!

return 0;
}
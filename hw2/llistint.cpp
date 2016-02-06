#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{
  int copyval = val;
  //int copyval=val;
  if(loc < 0 || loc > size_){
    throw std::invalid_argument("bad location");
  }
  //let's make a home for this value
  //initialize to NULL to start with
  Item *value;
  value = new Item;
  value->val = copyval;
  value->prev = NULL;
  value->next = NULL;

if (empty())//there is no list yet so simply change head and tail to
  //the new Item. prev and next still NULL
  {
    head_ = value;
    tail_ = value;
  }
else if (loc== size_)//you're at the end of the list
  {
   tail_->next=value;//change the Item at head's next to point
   //to the new Item value
   value->prev=tail_;
   value->next=NULL;
   tail_=value;
  }
else if (loc==0)//you're adding to the head of the list!
  {
    head_->prev =value;
    value->next=head_;
    head_=value;

  }
else//you're just in the list somewhere in the middle
  {
    //time to find yourself! Become buddhist! jk do a for loop
   Item *before;
   before = getNodeAt(loc-1);
   
   Item *after; //give you the place of the Item after you(you being the Item added)
   after=before->next;

   before->next=value;
   value->prev=before;
   value->next=after;
   after->prev=value;
   }
   size_=size_+1;
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
}

if (size_==1)//only one item in the list
{
  clear();
  size_++;//product of clear is decreasing size but this func takes care of it
}
else if ((loc==(size_-1)))//the end of the line eerr list!
  { Item *temp;
    
    tail_->prev->next=NULL;
    temp=tail_;
    tail_=tail_->prev;
    delete temp;
  }
  else if ((loc==0))//the front of the line!
  { 
    Item *temp;
    temp = new Item;
    temp=head_;
    head_=head_->next;
    delete temp;
  }
else//it's somewhere in the middle of the list
  {
    //Time again to find your place!
   Item *before;
   before = new Item;
   before = getNodeAt(loc-1);
   //need to find the place before the Item you want to delete
    
  Item *to_delete;//give you the place of the Item after you(you being the Item to delete)
   to_delete= new Item;
   to_delete=before->next;
   Item *after;
   after = new Item;
   after=to_delete->next;

   before->next=after;
   after->prev=before;
   to_delete->next=NULL;
   to_delete->prev=NULL;
   delete to_delete;
  }
  size_=size_-1; //decrease the size because you took one out!
}

void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


/**
 * Complete the following function
 */
LListInt::Item* LListInt::getNodeAt(int loc) const
{
if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
if ((loc==(size_-1)))//last Item!
  {
    return tail_;
  }  
if (loc==0) //first item!
  {
    return head_;
  } 
Item *goal;
goal = head_;
for (int i=0; i< loc; i++)
  {  goal=goal->next;
  }
return goal;
}


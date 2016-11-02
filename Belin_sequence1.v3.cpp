/**Program Name: Belin_sequence1.v3.cpp
   Programmer Name: Elliot Belin
   Date Submitted: 9/20/14
   Purpose: To implement the member functions of the static bag class
   Date Updated: 9/30/14
   Purpose of Update: updated sequence constructor so that current_index is initialized
                     to zero. Updated the is_item() so that it includes an else statement.
                     The source file now passes the sequence exam.
   Global Variable List: none.
 */
    
#include "main_savitch_sequence.h"
#include <cassert> 
#include <iostream>


namespace main_savitch_3
{
 
    //CONSTRUCTORS
    sequence::sequence( )
    {
     used=0;
     current_index=0;
    }
    // Postcondition: The sequence has been initialized as an empty sequence.
    
    //MODIFICATION MEMBER FUNCTIONS
    void sequence::start()
    {
     current_index=0;
    }
    // Postcondition: The first item on the sequence becomes the current item
    //(but if the sequence is empty, then there is no current item).
    
    void sequence::advance()
    {
     current_index++;
    }
    // Precondition: is_item returns true.
    // Postcondition: If the current item was already the last item in the
    // sequence, then there is no longer any current item. Otherwise, the new
    // current item is the item immediately after the original current item.

    
    void sequence::insert(const value_type& entry)
    {
    
     assert(used<CAPACITY);
     
     value_type tempdata[CAPACITY]={0};//temperary place holder for the items
                                     //that are stored in data[i]
     
     
     
     if(!(is_item())) //special case for when the cursor is run off the sequence.
     current_index=0;
     
     used++;
     
     int c=0;
     for(int i=0;i<used; i++) //tempdata[c] will store the items from data[i]
     if(i<current_index)    //while data[i] is partitioned.
     {
     tempdata[c]=data[i];
     c++;
     }
     else if(i==current_index)
     {
     tempdata[c]=entry;
     c++;
     }
     else if(i>current_index)
     {
     tempdata[c]=data[i-1];
     c++;
     }
     
    for(int i=0;i<used;i++)//items in tempdata[i] are transferred back into data[i].
    data[i]=tempdata[i];
    
    
}  
    // Precondition: size( ) < CAPACITY.
    // Postcondition: A new copy of entry has been inserted in the sequence
    // before the current item. If there was no current item, then the new entry
    // has been inserted at the front of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.

    
    void sequence::attach(const value_type& entry)
    {
         
    assert(used<CAPACITY);
    value_type tempdata[CAPACITY]={0};  //temperary place holder
    
        
    if(used==0)   //special case where a number is attached into an empty sequence
    tempdata[0]=entry;  // or when current_index=0.
    else 
    if(current_index==0)
    tempdata[0]=entry;
    
    if(current_index>used-1)//special case where the cursor is at or beyond the last
    current_index=used-1;  //item in the sequence.
    
    

     used++; 
     int c=0;
     if((used>1)||(current_index>0))
     for(int i=0;i<used; i++)
     if(i <=current_index)
     {
     tempdata[c]=data[i];
     c++;
     }
     else if(i==current_index+1)
     {
     tempdata[c]=entry;
     c++;
     }
     else if(i>current_index+1)
     {
     tempdata[c]=data[i-1];
     c++;
     }
     
     if((used>1)||(current_index>0)) //special case where current_index will not 
     current_index++;             //increment before a number is attached to an
                                //empty sequence.
     
       
    for(int i=0;i<used;i++) //the items in tempdata[i] are transferred back into data[i]
    data[i]=tempdata[i];
    

}    
    // Precondition: size( ) < CAPACITY.
    // Postcondition: A new copy of entry has been inserted in the sequence after
    // the current item. If there was no current item, then the new entry has
    // been attached to the end of the sequence. In either case, the newly
    // inserted item is now the current item of the sequence.

    
    void sequence::remove_current()
    {
    
     int c=0;
     value_type tempdata[CAPACITY]={0}; //temperary place holder  
     
     
     for(int i=0; i<used; i++) //items in data[i] are stored into tempdata[c] 
     if(i<current_index)
     {
     tempdata[c]=data[i];
     c++;
     }
     else if(i>current_index)
     {
     tempdata[c]=data[i];
     c++;
     }
     used--;
     
     for(int i=0;i<used;i++)  //the items in tempdata[i] are transferred back into data[i]
     data[i]=tempdata[i];
    }
    // Precondition: is_item returns true.
    // Postcondition: The current item has been removed from the sequence, and the
    // item after this (if there is one) is now the new current item.


    //CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size() const
    {
     return used;
    } 
    // Postcondition: The return value is the number of items in the sequence.
    
    bool sequence::is_item()const
    {
     if(current_index<used)return true;
     else return false;
     
    }
    // Postcondition: A true return value indicates that there is a valid
    // "current" item that may be retrieved by activating the current
    // member function (listed below). A false return value indicates that
    // there is no valid current item.
    
    sequence::value_type sequence::current() const
    {
     return data[current_index];
    }
    // Precondition: is_item( ) returns true.
    // Postcondition: The item returned is the current item in the sequence.
}

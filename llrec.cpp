#include "llrec.h"

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  smaller = NULL;
  larger = NULL;
  llpivotHelper(head, smaller, larger, pivot);
}

void llpivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot)
{

  if(head==NULL || head==nullptr)
  {
    return;
  } 
  else
  {

    Node*& temp = head;
    if(head->val>pivot)
    {
      larger = temp;
      head = head->next;
      larger->next = NULL;
      //cout<<"adding"<<head->val<<endl;
      llpivotHelper(head,smaller,larger->next,pivot);
    }
    else
    {
      smaller = temp;
      head = head->next;
      smaller->next=NULL;
      //cout<<"adding"<<head->val<<endl;
      llpivotHelper(head,smaller->next,larger,pivot);
    }
      head = NULL;
    
  }

}
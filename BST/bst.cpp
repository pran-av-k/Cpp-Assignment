
#include "bst.h"
template <typename KEY, typename T>


 Elem* initialize()
 {
    // create a dummy root node
    _root = new Elem;
    _root->left = _root;  // empty tree
    _root->right = null;
    _root->rightThread = false;
    _size = 0;

  return _root;

 }



template <typename KEY, typename T>
bool insert(Elem *&root, const KEY &key, const T &data, Elem *lastLeft)
 {

   
Elem* newNode = new Elem;
    newNode->key = k;
    newNode->data = d;
    newNode->rightThread = true;
    newNode->right = null;
    newNode->left = null;

    if( _root->left == _root )
    {
        newNode->right = _root;
        _root->left = newNode;
    }
    else
    {
        Elem* current = _root->left;
        Elem* parentNode = _root;
        while (current)
        {
            parentNode = current;

            if( k > current->key)
            {
                if(current->rightThread)
                    break;
                else
                    current = current->right;
            }
            else if(k < current->key)
            {
                current = current->left;


            }
            else
            {
                delete newNode;
                return false;
            }
        }

        
        if(current)
        {
            newNode->right =parentNode->right;
            parentNode->rightThread =false;
            parentNode->right = newNode;

        }

        else
        {
            parentNode->left = newNode;
            newNode->right = parentNode;
        }

    }


    _size++;
   return true;


}




template <typename KEY, typename T>
void printTree(ostream& out, int level, Elem *p) const;
{
   if(p == null)
     return;
 
   Elem* temp = p;
 
   while(temp->left!=null)
   {
     temp = temp->left; 
   }

   while(temp!=null)
   {
    out << temp->data <<" ";
    temp = inorder_successor(temp);
   }
}


  Elem* inorder_successor(Elem* ptr)
  {
    if(ptr-<rightThread == true)
      return ptr->right;

     else
     {
        ptr = ptr->right;

        while(ptr->left!=null)
           ptr = ptr->left;   

         return ptr;
     }
  }




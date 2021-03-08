
#include "bst.h"
#include "AVL.h"

struct Elem* createNode(const KEY &key,const T &data)
{
    struct Elem* temp = new Elem;
    temp->key = key;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->rightThread = false;
    
    return temp;
}

int height(struct Elem *node)
{
    int left_height,right_height;
    
      if(node && node->left)
	    left_height = node->left->height;
	
	  else left_height = 0;

	  if(node && node->right)
	   right_height = node->right->height;

	  else right_height = 0;


    return (left_height > right_height)?left_height + 1:right_height+1;

}


int balanceFactor(struct Elem *current)
{
   
   int left_height,right_height;

  if(current && current->left)
   left_height = current->left->height;
 
   else
    left_height = 0;
    
  if(current && current->right)
   right_height = current->right->height;
 
   else
    right_height = 0;


    return left_height - right_height;

}


void updateHeight(struct Elem *&current)
{

    int left_height,right_height;

  if(current && current->left)
   left_height = current->left->height;
 
   else
    left_height = 0;
    
  if(current && current->right)
   right_height = current->right->height;
 
   else
    right_height = 0;



    if(left_height > right_height)
        current->height = left_height+1;
    
    else
        current->height = right_height+1;
    

  
}


void rotateLeft(Elem *& node)
{
    struct Elem *node_left = node->left;
    struct Elem *node_leftright = node_left->right;
    
    node_left->right = node;
    node->left = node_leftright;
    
    updateHeight(node);
    updateHeight(node_left);
    
    if (root == node)
        root=node_left;
  
}


void doubleRotateLeft(Elem *& node)
{
    struct Elem *node_left = node->left;
    struct Elem *node_leftright = node_left->right;
    
    node_left->right = node_leftright->left;
    node->left = node_leftright->right;
    node_leftright->left = node_left;
    node_leftright->right = node;

    updateHeight(node_left);
    updateHeight(node);
    updateHeight(node_leftright);  

    if(root == node)
        root=node_leftright;
   
}
void rotateRight(Elem *& node)
{
    struct Elem *node_right = node->right;
    struct Elem *node_rightleft = node_right->left;

    node_right->left = node;
    node->right = node_rightleft;

    updateHeight(node);
    updateHeight(node_right);

    if (root == node)
        root = node_right;
    
}
void doubleRotateRight(Elem *& node)
{
    struct Elem *node_right=node->right;
    struct Elem *node_rightleft=node_right->left;

    node_right->left = node_rightleft->right;
    node->right = node_rightleft->left;
    node_rightleft->left = node;
    node_rightleft->right = node_right;

    updateHeight(node_right);
    updateHeight(node);
    updateHeight(node_rightleft);

    if(root == node)
        root = node_rightleft;
     
}


void balance(struct Elem *cur,const KEY &key)
{
    if(balanceFactor(cur) == 2 && balanceFactor(cur->left) == 1)  // LL Imbalance
         rotateLeft(cur);

    else if(balanceFactor(cur) == 2 && balanceFactor(cur->right) == -1)  // LR Imabalance
         doubleRotateLeft(cur);
    
    else if(balanceFactor(cur) == -2 && balanceFactor(cur->right) == -1)  // RR Imbalance
         rotateRight(cur);
    
    else if(balanceFactor(cur) == -2 && balanceFactor(cur->left) == 1)    // RL Imbalance
         doubleRotateRight(cur);
    
}

bool insert(Elem *& root,const KEY &key,const T &data,Elem *lastLeft)
{
  struct Elem* temp = createNode(key,data); 

  struct Elem* present = root;
  struct Elem* parent = NULL;
  
    if (present == NULL)
    {
      temp->left = NULL;
      temp->right = NULL;
      temp->rightThread = true;
      root = temp;
      temp->height = 1;
      temp = NULL;
      delete temp;
      return true;
  }

  else{
      while(true)
      {
          parent = present;

          if(key < present->key)
            {
              present = present->left;

              if(present == NULL)
                {
                  parent->left = temp;
                  temp->left = NULL;
                  temp->right = parent;
                  temp->rightThread = true;
                  
                  temp->height=height(temp);
                  balance(temp,temp->key);
                  temp = NULL;

                  delete temp;
                  return true;
              }
          }

          else if(key > present->key)
            {
              if(present->rightThread == false)
                  present = present->right;

              
              else
               {
                  Elem *t = present->right;
                  present->right = temp;
                  present->rightThread = false;
                  temp->left = NULL;
                  temp->right = t;
                  temp->rightThread = true;
                
                  temp->height = height(temp);
                  balance(temp,temp->key);

                  temp=NULL;

                  delete temp;
                  return true;
              }
          }
      }
  }
  

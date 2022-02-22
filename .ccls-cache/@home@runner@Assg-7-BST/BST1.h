#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {                                           
   struct treeNode *leftPtr;  
   int data;   
   int depth = 0;

   struct treeNode *rightPtr; 
}TreeNode; 
        
typedef TreeNode * TreeNodePtr; 
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes
void insertNode( BST *, int );

void insertNode( BST *b, int value ){ // insert a node
	 TreeNodePtr t = b->root, new_node;
	 int inserted = 0;

	new_node =(TreeNodePtr) malloc(sizeof( TreeNode));

	if(new_node){
		new_node->leftPtr = NULL;
		new_node->rightPtr = NULL;
		new_node->data = value;
		/*First Node*/

		if(!b->root) /*b->root == NULL*/ b->root = new_node;
		else {
      while(!inserted /*insert == 0*/){

        if(value <= t->data ){
          if(t->leftPtr == NULL) {
            t->leftPtr = new_node;
            inserted = 1;
          }
          else {
            t = t->leftPtr;
            t->depth++;
            // go left and insert if node is NULL
            // else change t 
          }
        }

        else /*value > t->data*/ {
          if(t->rightPtr == NULL) {
            t->rightPtr = new_node;
            inserted = 1;
            
          }
          else {
            t = t->rightPtr;
            t->depth++;
          
            // go right and insert if node is NULL
            // else change t
          }
        }
      }//end while		
    }//end else;
    b->size++;

    // find depth
    /*
    int depth = 0, count;
    count = b->size;

    while(count >= 2){
      count = count/2;
      depth++;  
    }

  new_node->depth = depth; 
  */
  
  printf("data %d, depth %d, size %d \n", new_node->data, new_node->depth, b->size);

  }
  
}//end function



// print all node in tree and already sort them.//
void inOrder( TreeNodePtr treePtr )  
{  // L-C-R
   if ( treePtr != NULL ) {      
      inOrder( treePtr->leftPtr );    //Recursion to the left
      printf("%3d ", treePtr->data) ;  //print the value  
      inOrder( treePtr->rightPtr );   //Recursion to the right
   } // end if                          
} // end 

void preOrder ( TreeNodePtr treePtr )
{
  // C-L-R
  if ( treePtr != NULL ) { 

    printf("%3d ", treePtr->data) ;  //print the value
    preOrder( treePtr->leftPtr );    //Recursion to the left  
    preOrder( treePtr->rightPtr );   //Recursion to the right
  }
} // end
void postOrder ( TreeNodePtr treePtr )
{
  // L-R-C
  if ( treePtr != NULL ) { 
    postOrder( treePtr->leftPtr );    //Recursion to the left
    postOrder( treePtr->rightPtr );   //Recursion to the right
    printf("%3d ", treePtr->data) ;   //print the value  
  }
} // end

//=================================//


void side_Tree(TreeNodePtr treePtr) 
{ 
   if (treePtr != NULL) { 
      side_Tree( treePtr->rightPtr );

      for(int i=0; i<=treePtr->depth*2; i++){
        printf("  ");
      }
      printf("%d \n", treePtr->data);
        
      side_Tree( treePtr->leftPtr );
   } // end if                        
} // end 

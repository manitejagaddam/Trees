#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data ;
    struct Node *left;
    struct Node *right;
};


struct Node *temp;

struct Node *root = NULL;


struct Node *create_a_node( int val){
    
    temp = (struct Node *) malloc (sizeof(struct Node));
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}


struct Node *Insert(struct Node *root , int val){
    if (root == NULL){
        return create_a_node(val);
    }
    if (val < root -> data){
        root -> left = Insert(root -> left , val);
    }else if( val > root -> data){
        root -> right = Insert(root -> right , val);
    }
    return root;


}
/*InorderTraversal = 
travesing direction:  left -> root -> right*/  

struct Node *InorderTraverse(struct Node * root){

    if(root != NULL){
        InorderTraverse(root -> left);
        printf("%d  ",root -> data);
        InorderTraverse(root -> right);
    }
    
    return NULL;
}

/*PostorderTraversal = 
travesing direction:  left -> right -> root*/  

struct Node * PostorderTraverse( struct Node * root){
    if (root != NULL){
        PostorderTraverse(root -> left);
        PostorderTraverse(root -> right);
        printf("%d  " , root -> data);
    }

    return NULL;
}

/*PreorderTraversal = 
travesing direction: root -> left -> right*/  

struct Node *PreorderTraverse(struct Node * root){
    if(root != NULL){
        printf("%d  ", root -> data);
        PreorderTraverse(root -> left);
        PreorderTraverse(root -> right);
    }

    return NULL;
}


/*
    binary tree : 
                50
              /    \
             30     70
            /  \   /  \
           20  40 60   80
*/


int main(){
    root = Insert(root, 50);
    Insert(root, 30);
    Insert(root, 20);
    Insert(root, 40);
    Insert(root, 70);
    Insert(root, 60);
    Insert(root, 80);

    InorderTraverse(root);
    printf("\n");
    PostorderTraverse(root);
    printf("\n");
    PreorderTraverse(root);
}

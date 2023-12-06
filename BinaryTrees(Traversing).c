#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data ;
    struct Node *left;
    struct Node *right;
};


struct Node *create_a_node( int val);
struct Node *Insert_value(struct Node *root , int val);
void InorderTraverse(struct Node * root);
void  PostorderTraverse( struct Node * root);
void PreorderTraverse(struct Node * root);
struct Node * Height_of_Tree(struct Node * root);
struct Node * freeTree(struct Node * root);



/*
    binary tree : 
                50
              /    \
             30     70
            /  \   /  \
           20  40 60   80
*/

// static Main
// int main(){
//     struct Node *root = NULL;
//     root = Insert_value(root, 50);
//     Insert_value(root, 30);
//     Insert_value(root, 20);
//     Insert_value(root, 40);
//     Insert_value(root, 70);
//     Insert_value(root, 60);
//     Insert_value(root, 80);

//     InorderTraverse(root);
//     printf("\n");
//     PostorderTraverse(root);
//     printf("\n");
//     PreorderTraverse(root);
// }

//Dynamic Main
int main(){
    struct Node * root = NULL;
    int option;

    do {
        printf("*****-----Main Menu-----*****\n");
        printf("1.Insert a value\n");
        printf("2.Delete a value\n");
        printf("3.In order Traversing\n");
        printf("4.Pre order Traversing\n");
        printf("5.Post order Traversing\n");
        printf("6.Height of Tree\n");
        printf("7.Exit\n");
        printf("*****------The End------*****\n");

        printf("Choose any Option : ");
        scanf("%d" ,&option);
        int val;

        switch (option)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            root = Insert_value(root , val);
            break;
        
        case 2:

            break;

        case 3:
            InorderTraverse(root);
            printf("\n");
            break;

        case 4:
            PreorderTraverse(root);
            printf("\n");
            break;

        case 5:
            PostorderTraverse(root);
            printf("\n");
            break;

        case 6:
            printf("Height of Tree: %d\n", Height_of_Tree(root));
            break;
        
        case 7:
            freeTree(root);
            break;

        default:
            printf("Choose a valid option");
        }
    }while(option != 7);
}

struct Node *create_a_node( int val){
    
    struct Node *temp;
    temp = (struct Node *) malloc (sizeof(struct Node));
    temp -> data = val;
    temp -> left = NULL;
    temp -> right = NULL;
    
    return temp;
}


struct Node *Insert_value(struct Node *root , int val){

    if (root == NULL){
        return create_a_node(val);
    }
    if (val < root -> data){
        root -> left = Insert_value(root -> left , val);
    }else if( val > root -> data){
        root -> right = Insert_value(root -> right , val);
    }
    return root;


}


/*InorderTraversal = 
travesing direction:  left -> root -> right*/  


void InorderTraverse(struct Node * root){

    if(root != NULL){
        InorderTraverse(root -> left);
        printf("%d  ",root -> data);
        InorderTraverse(root -> right);
    }
}


/*PostorderTraversal = 
travesing direction:  left -> right -> root*/  


void PostorderTraverse( struct Node * root){
    if (root != NULL){
        PostorderTraverse(root -> left);
        PostorderTraverse(root -> right);
        printf("%d  " , root -> data);
    }
}


/*PreorderTraversal = 
travesing direction: root -> left -> right*/  


void PreorderTraverse(struct Node * root){
    if(root != NULL){
        printf("%d  ", root -> data);
        PreorderTraverse(root -> left);
        PreorderTraverse(root -> right);
    }
}


struct Node * Height_of_Tree(struct Node * root){
    int height = 0;
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = Height_of_Tree(root->left);
        int rightHeight = Height_of_Tree(root->right);

        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}


struct Node * freeTree(struct Node * root){
    while (root != NULL){
        root -> left = freeTree(root -> left);
        root -> right = freeTree(root -> right);
        free(root);

        root = NULL;
        
    }
}
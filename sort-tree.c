//二叉排序树的实现
//http://blog.csdn.net/whuslei/article/details/7272450

#include<stdio.h>  
#include<stdlib.h>  
#include<assert.h>  
  
//二叉树节点  
typedef struct node{  
    int data;  
    struct node *left,*right,*parent;  
}bsnode;  
  
//遍历二叉树(中序)  
void print_bstree(bsnode *tree){  
    if(tree!=NULL){  
        print_bstree(tree->left);//递归  
        printf("%d,",tree->data);  
        print_bstree(tree->right);  
    }  
}  
  
//查找元素(非递归)  
bsnode * find(bsnode *tree,int k){  
    while(tree!=NULL && tree->data !=k){  
        if(k < tree->data){  
            tree = tree->left;  
        }else{  
            tree = tree->right;  
        }  
    }  
    return tree;//返回指向data域等于k的节点的指针！  
}  
  
//查找元素(递归)  
bsnode * re_find(bsnode *tree,int k){  
    if(tree==NULL ||  tree->data ==k){  
        return tree;      
    }else if(k < tree->data){  
        return re_find(tree->left,k);  
    }else{  
        return re_find(tree->right,k);  
    }  
}  
  
//求最小值(给定一个二叉查找树的根snode，求这颗树的最小节点)  
bsnode * find_min(bsnode *snode){  
    bsnode *p=NULL;  
    while(snode!=NULL){  
        p=snode;  
        snode=snode->left;  
    }  
    return p;//树的最左子树叶节点  
}  
  
//求最大值  
bsnode * find_max(bsnode *snode){  
    bsnode *p=NULL;  
    while(snode!=NULL){  
        p=snode;  
        snode=snode->right;  
    }  
    return p;  
}  
  
//查找前驱  
bsnode * find_prev(bsnode *m){  
    assert(m!=NULL);  
    if(m->left != NULL){  
        return find_max(m->left);      
    }else{  
        //寻找m的祖先中满足这样关系的点：righ[p[m]] == m  
        bsnode *p = m->parent;  
        bsnode *child = m;  
        while(p!=NULL && p->right != child){  
            child=p;  
            p=child->parent;  
        }  
        return p;  
    }  
}  
  
//查找后继  
bsnode * find_next(bsnode *m){  
    assert(m==NULL);  
    if(m->right !=NULL){  
        return find_min(m->right);  
    }else{  
        bsnode *p=m->parent;  
        bsnode *child=m;  
        while(p!=NULL && p->left != child){  
            child=p;  
            p=p->parent;  
        }  
        return p;  
    }  
}  
  
//插入元素(递归)  
bsnode *re_insert(bsnode *tree,bsnode *newer){  
    if(tree==NULL){  
        tree=newer;  
    }else{  
        if(newer->data < tree->data){  
            tree->left=re_insert(tree->left,newer);  
        }else{  
            tree->right=re_insert(tree->right,newer);  
        }  
    }  
    return tree;  
}  
  
//插入元素(非递归)  
bsnode *insert(bsnode *tree,bsnode *newer){  
    bsnode *root=tree;  
    bsnode *p= NULL;  
    while(root!=NULL){  
        p=root;  
        if(newer->data < root->data){//往左子树  
            root=root->left;  
        }else{  
            root=root->right;  
        }  
    }//p指针就是要插入节点的父亲  
  
    newer->parent = p;//修改parent指针，让其指向父亲  
  
    if(p==NULL){//只有一个节点  
        tree = newer;  
    }else{  
        if(newer->data < p->data){  
            p->left=newer;  
        }else{  
            p->right=newer;  
        }  
    }  
  
    return tree;  
}  
  
//删除元素  
bsnode * delete(bsnode *tree,int k){  
    bsnode *delnode = find(tree,k);  
    if(delnode ==NULL){  
        printf("要删除的节点不存在！请检查\n");  
    }else{  
        bsnode *xnode = NULL;  
        bsnode *ynode = NULL;   
        if(delnode->left == NULL || delnode->right == NULL){  
            xnode = delnode;//delnode有一个孩子或者没有，则xnode表示它本身  
        }else{  
            xnode = find_next(delnode);//delnode有两个孩子，xnode则表示它的后继节点  
        }  
  
        //得到xnode的孩子节点  
        if(xnode->left != NULL){  
            ynode = xnode->left;  
        }else{  
            ynode = xnode->right;  
        }  
  
        if(ynode != NULL){  
            ynode->parent = xnode->parent;  
        }  
  
        if(xnode->parent == NULL){  
            tree = ynode;     
        }else{  
            if(xnode->parent->left == xnode){  
                xnode->parent->left = ynode;  
            }else{  
                xnode->parent->right = ynode;  
            }  
        }  
  
        if(xnode != delnode){//两个孩子的情况，得将后继节点的值赋给delnode,以实现逻辑删除  
            delnode->data = xnode->data;  
        }  
  
        //删除掉节点  
        free(xnode);  
    }  
  
    return tree;  
}  
  
int main(){  
    bsnode *tree=NULL;  
    int data[]={10,2,11,3,8,6,1,7};  
    int i;  
    for(i=0;i<sizeof(data)/sizeof(int);i++){  
        bsnode *newer = (bsnode *)malloc(sizeof(bsnode));  
        newer->data=data[i];  
        newer->left=newer->right=newer->parent=NULL;  
        tree = insert(tree,newer);//插入  
    }  
    print_bstree(tree);//中序遍历  
    printf("\n");  
      
    tree = delete(tree,2);//删除节点  
    print_bstree(tree);  
    printf("\n");  
    return 0;  
}  
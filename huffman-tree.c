#include <stdio.h> 
#include <string.h> 

#define MAXBIT 100 
#define MAXVALUE 10000 
#define MAXLEAF 30 
#define MAXNODE MAXLEAF*2-1 

typedef struct 
{ 
    int bit[MAXBIT]; 
    int start; 
}HCodeType; 

typedef struct 
{ 
    int weight; 
    int parent; 
    int lchild; 
    int rchild; 
}HNodeType; 

//构造一颗哈夫曼树 
void HuffmanTree(HNodeType HuffNode[MAXNODE],int n) 
{ 
    int i,j,m1,m2,x1,x2; 

    //初始化树中所有的结点 
    for(i=0;i<2*n-1;i++) 
    { 
        HuffNode[i].weight = 0; 
        HuffNode[i].parent = -1; 
        HuffNode[i].lchild = -1; 
        HuffNode[i].rchild = -1; 
    } 

    //输入叶子结点的权值，也就是在字符集中共有多少个该结点 
    for(i=0;i<n;i++) 
    { 
        printf("请输入叶子结点的权值%d:\n",i); 
        scanf("%d",&HuffNode[i].weight); 
    } 

    //循环查找在字符集中最小的两个值，都成一颗二叉树 
    //总共需要循环n-1次，因为到n-1次的时候除了根结点，所有的结点都会循环完毕 
    for(i=0;i<n-1;i++) 
    { 
        m1 = m2 = MAXVALUE; 
        x1 = x2 = 0; 

        //在每次循环中找到两个最小的结点（上一次循环会把其中的两个最小结点生成的结点加入到了数组中，HuffNode的2n-1个结点），然后找到这些结点中没有父亲结点的结点中两个最小的结点，组成一棵二叉树 
        for(j=0;j<n+i;j++) 
        { 
            if(HuffNode[j].weight<m1 && HuffNode[j].parent == -1) 
            { 
                m2 = m1; 
                x2 = x1; 
                m1 = HuffNode[j].weight; 
                x1 = j; 
            } 
            else if(HuffNode[j].weight<m2&&HuffNode[j].parent == -1) 
            { 
                m2 = HuffNode[j].weight; 
                x2 = j; 
            } 
        } 
        HuffNode[x1].parent = n+i; 
        HuffNode[x2].parent = n+i; 
        HuffNode[n+i].weight = HuffNode[x1].weight 
                    + HuffNode[x2].weight; 
        HuffNode[n+i].lchild = x1; 
        HuffNode[n+i].rchild = x2; 
         
        printf("x1.weight and x2.weight in round %d:%d,%d\n", 
                i+1,HuffNode[x1].weight,HuffNode[x2].weight); 
        printf("\n"); 
    } 
} 


int main() 
{ 
    HNodeType HuffNode[MAXNODE]; 
    HCodeType HuffCode[MAXLEAF],cd; 

    int i,j,c,p,n; 
    printf("请输入叶子结点的个数：\n"); 
    scanf("%d",&n); 

    //构造huffman树 
    HuffmanTree(HuffNode,n); 

    //对huffman树进行编码 
    for(i=0;i<n;i++) 
    { 
        cd.start = n-1; 
        c = i; 
        p = HuffNode[c].parent; 
        while(p != -1) 
        { 
            if(HuffNode[p].lchild == c) 
                cd.bit[cd.start] = 0; 
            else 
                cd.bit[cd.start] = 1; 
            cd.start--; 
            c = p; 
            p = HuffNode[c].parent; 
        } 
        for(j = cd.start+1;j<n;j++) 
        { 
            HuffCode[i].bit[j] = cd.bit[j]; 
        } 
        HuffCode[i].start = cd.start; 
    } 

    //输出huffman编码，最终结果 
    for(i=0;i<n;i++) 
    { 
        printf("%d的哈夫曼编码是：",i); 
        for(j = HuffCode[i].start+1;j<n;j++) 
            printf("%d",HuffCode[i].bit[j]); 
        printf("\n"); 
    } 
    return 0; 
} 
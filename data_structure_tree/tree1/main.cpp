#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct node
{
    char data;
    struct node*lChild;
    struct node*rChild;
}BiTNode,*BiTree;

void midPrecreat(BiTree*root, char mid[], char pre[], int lm, int rm, int lp, int rp)
{
    *root=(BiTree)malloc(sizeof(BiTNode));
    (*root)->data=pre[lp];
    (*root)->lChild=NULL;
    (*root)->rChild=NULL;
    int pos=lm;
    while(mid[pos]!=pre[lp])
        pos++;
    int childLen= pos - lm;//用来控制子树在字符串中的范围

    if(pos>lm)//有左子树,递归创建
        midPrecreat((&((*root)->lChild)), mid, pre, lm, pos - 1, lp + 1, lp + childLen);
    if(pos<rm)//有右子树,递创建
        midPrecreat((&((*root)->rChild)), mid, pre, pos + 1, rm, lp + childLen + 1, rp);
}
void print(BiTree p)
{      if(p != NULL)
    {
        print(p->lChild); //遍历左子树
        print(p->rChild); //遍历右子树
        printf("%c",p->data);     //输出该结点
    }
}
int main()
{
    char    pre[100] ; //存储先序序列
    char    mid[100] ; //存储中序序列
    int n;

    BiTree root;
    printf("输入前序：\n");
    gets(pre);
    printf("输入中序：\n");
    n=strlen(pre);
    
    gets(mid);
    midPrecreat(&root, mid, pre, 0, n - 1, 0, n - 1);
    printf("后续遍历该二叉链表二叉树：\n");
    print(root);

    return 0;
}

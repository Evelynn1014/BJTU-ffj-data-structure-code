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
    int childLen= pos - lm;//���������������ַ����еķ�Χ

    if(pos>lm)//��������,�ݹ鴴��
        midPrecreat((&((*root)->lChild)), mid, pre, lm, pos - 1, lp + 1, lp + childLen);
    if(pos<rm)//��������,�ݴ���
        midPrecreat((&((*root)->rChild)), mid, pre, pos + 1, rm, lp + childLen + 1, rp);
}
void print(BiTree p)
{      if(p != NULL)
    {
        print(p->lChild); //����������
        print(p->rChild); //����������
        printf("%c",p->data);     //����ý��
    }
}
int main()
{
    char    pre[100] ; //�洢��������
    char    mid[100] ; //�洢��������
    int n;

    BiTree root;
    printf("����ǰ��\n");
    gets(pre);
    printf("��������\n");
    n=strlen(pre);
    
    gets(mid);
    midPrecreat(&root, mid, pre, 0, n - 1, 0, n - 1);
    printf("���������ö��������������\n");
    print(root);

    return 0;
}

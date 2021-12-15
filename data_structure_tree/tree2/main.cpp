#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef BASE
#define BASE
#define OVERFLOW -2
#endif
#define TElemType char
void visit(TElemType e) {
    printf("%c ", e);
}
typedef struct CSNode{
    TElemType data;
    struct CSNode *firstChild, *nextSibling;
}CSNode, *CSTree;


#define maxSize 50

CSTree CreateCSTreeByLevelDegree(char *levelstr, int *num) {
    int cnt,i,parent;
    CSNode *p;
    CSNode *tmp[maxSize];

    //先创建结点
    for (i=0; i < strlen(levelstr); ++i) {
        p = (CSNode *)malloc(sizeof(CSNode)); if (!p) exit(OVERFLOW);
        p->data = levelstr[i];p->firstChild=p->nextSibling=NULL;
        tmp[i]=p;
    }
    //连接
    parent=0;
    cnt=0;
    i=1;
    while (i<strlen(levelstr)) {
        if (num[parent]==0 || cnt==num[parent]) {
            cnt=0;
            parent++;
            continue;
        }

        cnt++;
        if (cnt==1) {
            //i是parent的第一个孩子
            tmp[parent]->firstChild = tmp[i];
        } else {
            //不是第一个孩子
            tmp[i-1]->nextSibling = tmp[i];
            //它是前面的兄弟
        }

        i++;
    }

    return tmp[0];
}

void PrintAsTree(CSTree T,int i) {
    int cnt;
    if (T) {
        //输出空格
        for (cnt=1; cnt<i; cnt++) printf("  ");
        //输出字符
        visit(T->data);
        printf("\n");
        PrintAsTree(T->firstChild, i+1);
        PrintAsTree(T->nextSibling, i);
    }
}
int main() {
    CSTree CST;
    char levelstr[50]; //层次遍历的序列
    int num[50]; //每个结点的度
    int i;
    scanf("%s", levelstr); //输入层次序列
    for (i=0; i<strlen(levelstr); i++) scanf("%d", &num[i]); //每个结点的度
    CST = CreateCSTreeByLevelDegree(levelstr, num); //6.68
    printf("斜着的树：\n");
    PrintAsTree(CST, 1); //6.71
    return 0;
}

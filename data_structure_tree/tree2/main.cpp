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

    //�ȴ������
    for (i=0; i < strlen(levelstr); ++i) {
        p = (CSNode *)malloc(sizeof(CSNode)); if (!p) exit(OVERFLOW);
        p->data = levelstr[i];p->firstChild=p->nextSibling=NULL;
        tmp[i]=p;
    }
    //����
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
            //i��parent�ĵ�һ������
            tmp[parent]->firstChild = tmp[i];
        } else {
            //���ǵ�һ������
            tmp[i-1]->nextSibling = tmp[i];
            //����ǰ����ֵ�
        }

        i++;
    }

    return tmp[0];
}

void PrintAsTree(CSTree T,int i) {
    int cnt;
    if (T) {
        //����ո�
        for (cnt=1; cnt<i; cnt++) printf("  ");
        //����ַ�
        visit(T->data);
        printf("\n");
        PrintAsTree(T->firstChild, i+1);
        PrintAsTree(T->nextSibling, i);
    }
}
int main() {
    CSTree CST;
    char levelstr[50]; //��α���������
    int num[50]; //ÿ�����Ķ�
    int i;
    scanf("%s", levelstr); //����������
    for (i=0; i<strlen(levelstr); i++) scanf("%d", &num[i]); //ÿ�����Ķ�
    CST = CreateCSTreeByLevelDegree(levelstr, num); //6.68
    printf("б�ŵ�����\n");
    PrintAsTree(CST, 1); //6.71
    return 0;
}

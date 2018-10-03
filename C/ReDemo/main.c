
#include<stdio.h>
#include<malloc.h>
#define maxsize  1024  //���Ա����󳤶�
typedef struct{        //�������
    int data[maxsize];//��Ĵ���ռ�
    int last;
    int len;
}sqlist,*sqlink;      //˵����ʾ��


void CreateList(sqlink L,int len);//���ձ�
void ClearList(sqlink L);//�ÿձ�
int GetList(sqlink L,int no);//ȡ��Ԫ��
int LengthList(sqlink L);//���
int InsertList(sqlink L,int data,int no);//����Ԫ��
int DeleteList(sqlink L,int no);//ɾ��Ԫ��
int LocateList(sqlink L,int data);//��λԪ��
int EmptyList(sqlink L);//�пձ�
void PrintList(sqlink L);//��ӡ��Ԫ��

int main(){

    sqlink L = (sqlink)malloc(sizeof(sqlist));
    int len;
    printf("���볤�ȣ�");
    scanf("%d",&len);
    CreateList(L,len);
    PrintList(L);

    int data,x;
    printf("������Ҫ��������ݺ�λ�ã�");
    scanf("%d %d",&data,&x);
    InsertList(L,data,x);
    PrintList(L);

    return 0;
}

void CreateList(sqlink L,int len){
    int tempNo = 1;
    int tempData = 0;
    L->len = len;
    do{
        printf("������˳����%d��Ԫ�أ�",tempNo);
        scanf("%d",&tempData);
        if(tempData!=-1){
            L->data[tempNo-1] = tempData;
            L->last = tempNo-1;
            tempNo++;
        }
    }while(tempNo<=len&&tempData!=-1);
}
void PrintList(sqlink L){
    int i;
    for(i = 0;i<LengthList(L);i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
void ClearList(sqlink L){
    L->last = -1;
}
int GetList(sqlink L,int no){
    int tempData = 0;
    tempData = L->data[no-1];
    return tempData;
}
int LengthList(sqlink L){
    int tempL;
    tempL = L->last+1;
    return tempL;
}
//����Ԫ��
int InsertList(sqlink L,int data,int no){
    int j;
    if(L->last >= L->len-1){
        printf("û�п��пռ䣡\n");
        return 0;
    }else if(no<0||no>L->last+1){
        printf("����λ�ò����ڣ�\n");
        return 0;
    }else{
        for(j=L->last;j>=no-1;j--)
            L->data[j+1] = L->data[j];
        L->data[no-1] = data;
        L->last++;
        return 0;
    }
}
//ɾ��Ԫ��
int DeleteList(sqlink L,int no){
    int j;
    if(no<0||no>L->last){
        printf("ɾ����Ԫ�ز�����");
        return 0;
    }else{
        for(j=no;j+1<=L->last;j++)
            L->data[j] = L->data[j+1];
        L->last--;
        return 0;
    }
}
//��λԪ��
int LocateList(sqlink L,int data){
    int i = 0;
    while(i<=L->last&&L->data[i]!=data)
        i++;
    if(i<L->last) return i;
    else return 0;
}

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
1.	��֪����10�������Ĳ��ұ����£���9��13��15��7��45��32��56��89��60��36�����Ӽ���������һ����������˳����ҵķ����ڲ��ұ��в��Ҹ������������ڣ������Ԫ�ص��±�ֵ�����򣬸�����Ӧ����Ϣ��
2.	���������ݱ�(5��7��9��12��15��18��20��22��25��30��100)����д�����۰���ҷ�������12��28��
*/

int main(int argc, char *argv[]) {
	int a[10] = {9,13,15,7,45,32,56,89,60,36};
	int b[10] = {5,7,9,12,15,18,20,22,25,30,100};
	int n,i;
	int k = 0;
	//˳����� 
	printf("-------------˳�����-------------\n");
	printf("������Ҫ���ҵ�ֵ��");
	scanf("%d",&n);
	if(SeqSearch(a,n) == -1){
		printf("û���ҵ�����ҵ�ֵ\n"); 
	}else{
		int j = SeqSearch(a,n);
		printf("����ҵ�ֵΪ%d���±���%d\n",a[j],j);
	}
	//�۰���� 
	printf("-------------���ֲ���-------------\n");
	do{
		if(k!=0){
		  	i = BinSearch(b,k);
		  	if(i == -1){
		    printf("û���ҵ�����ҵ�ֵ\n"); 
	       }else{
	         printf("����ҵ�ֵΪ%d���±���%d\n",b[i],i);
	       }
		}
		printf("��������Ҫ���ҵ�ֵ��-1����:"); 
		scanf("%d",&k);
	}while(k != -1);

	return 0;
}


int SeqSearch(int R[10],int n)
{
  int i=0;
while(i < 10&&R[i]!=n)
{
i++;
}
if(i>=n)
return -1;
else 
{
return i;
}
}


int BinSearch(int R[10],int n)
{
int low=0,high=9,mid,count=0;
while(low<=high)
{
mid=(low+high)/2;
printf("��%d�β��ң���[ %d ,%d]���ҵ�Ԫ��R[%d]:%d\n ",++count,low,high,mid,R[mid]);
if(R[mid]==n)
return mid;
if(R[mid]>n)
high=mid-1;
else
low=mid+1;
}
return -1;
}




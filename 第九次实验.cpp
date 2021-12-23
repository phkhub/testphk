#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//
typedef struct{
    int no;   //8λѧ��
    char name[20]; //����
    int price;     //�ɼ�
}Student,ElemType;
typedef  struct {
  Student   *elem=NULL;     //ָ������Ԫ�صĻ���ַ
  int  length;       //���Ա�ĵ�ǰ����
 }SqList;

SqList L;

void InitList()
{
    L.elem=new ElemType[MAXSIZE];
    if(!L.elem) exit(0);
    L.length=0;
}
int menu_select()//ѡ��˵�����
{
    char s[3];
    int c;
    printf("\n         ***************���˵�**************\n");
    printf("         *    1. ¼���¼�¼                *\n");
    printf("         *    2. �����ʾ���м�¼          *\n");
    printf("         *    3. �����¼                  *\n");
    printf("         *    4. ɾ����¼                  *\n");
    printf("         *    5. ͳ�Ƽ�¼                  *\n");
    printf("         *    6. ������˳����ʾ���м�¼    *\n");
    printf("         *    7. ��ѧ��˳����ʾ���м�¼    *\n");
    printf("         *    8. ͨ���������Ҽ�¼          *\n");
    printf("         *    9. ͨ��ѧ�Ų��Ҽ�¼          *\n");
    printf("         *    10. �˳�                      *\n");
    printf("         ***********************************\n\n");

    do
    {
        printf("         ��ѡ�����(1-10):");
        scanf("%s",s);
        c=atoi(s);
    }while(c<0||c>10); 
    return(c); 
}

void Create()
{//�½�ѧ������
    int n;
    cout<<"����ָ��ѧ���������������ѧ����Ϣ:"<<endl;
    cout<<"ѧ������n=";
    cin>>n;
    if(n<1||L.length+n>MAXSIZE){
        cout<<"����ʧ��"<<endl;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        L.length++;
        cout<<"��"<<i+1<<"��ѧ������"<<endl<<"����:";
        cin>>L.elem[L.length].name;
        cout<<"ѧ��:";
        cin>>L.elem[L.length].no;
        cout<<"�ɼ�:";
        cin>>L.elem[L.length].price;
    }
    cout<<"***�����ɹ�***"<<endl;
}
void ShowAllDate()
{
    if(L.length<1)
    {
        cout<<endl<<"    ���ź����ձ���û���κμ�¼�ɹ���ʾ!"<<endl;
        return ;
    }
    cout<<"************ STUDENT ************"<<endl;
    cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=1;i<=L.length;i++)
    {
        cout<<"   "<<i<<"��     "<<L.elem[i].name<<"��     "<<L.elem[i].no<<"��     "<<L.elem[i].price<<endl;
    }
    cout<<"*********************************"<<endl;
    cout<<"***�����ɹ�***"<<endl;
}

bool InsertByID()
{
    int i;
    ElemType e;
    cout<<"����һ��ѧ����Ϣ�����뵽����ָ����λ��"<<endl;
    ShowAllDate();
    cout<<"����������λ��:";
    cin>>i;
    if((i<1)||(i>L.length+1)){cout<<"λ�ò��Ϸ�"; return false;}//iֵ���Ϸ�
    if(L.length==MAXSIZE) {cout<<"�洢�ռ�����";return false;}//�洢�ռ�����
    cout<<"��������������:"<<endl;
    cout<<"����:";
    cin>>e.name;
    cout<<"ѧ��:";
    cin>>e.no;
    cout<<"�ɼ�:";
    cin>>e.price;
    for(int j=L.length;j>=i;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i]=e;
    ++L.length;
    cout<<"***�����ɹ�***"<<endl;
    return true;
}
bool DeleteByID()
{
    int i;
    cout<<"ɾ��ָ��λ�õ�ѧ����¼"<<endl;
    cout<<"λ��i=";
    cin>>i;
    if((i<1)||(i>L.length)){
        cout<<"λ�ò��Ϸ�";
        return false;
    }
    for(int j=i;j<=L.length-1;j++){
        L.elem[j]=L.elem[j+1];
    }
    --L.length;
    cout<<"***�����ɹ�***"<<endl;
    return true;
}

int flag=0;

void InsertSort(ElemType *a);
void BInsertSort(ElemType *a);

void SelectSort()
{
    if(L.length<1){
        cout<<endl<<" ���ź����ձ���û���κμ�¼�ɹ���ʾ!"<<endl;
        return ;
    }
    cout<<"�ڰ���������֮ǰ����ѡ�����򷽷�:1.ֱ�Ӳ�������  2.�۰��������"<<endl;
    cout<<"��ѡ�����1-2(Ĭ��ѡ��1):";
    int n;
    cin>>n;
    cout<<"��ȷ�ϼ�¼�Ƿ�����ʽ���棺1.ֱ����ʾ�����¼ 2.�������򷽰�����ʾ��¼"<<endl;
    cout<<"��ѡ�����1-2(Ĭ��ѡ��1):";
    cin>>flag;
    if(flag!=2){
        ElemType a[MAXSIZE];
      
        for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
        if(n==2)
            BInsertSort(a);
        else
            InsertSort(a);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"��     "<<a[i].name<<"��     "<<a[i].no<<"��     "<<a[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***�����ɹ�***"<<endl;
        flag=1;
    }else{
        if(n==2)
            BInsertSort(L.elem);
        else
            InsertSort(L.elem);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"��     "<<L.elem[i].name<<"��     "<<L.elem[i].no<<"��     "<<L.elem[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***�����ɹ�***"<<endl;
    }
}
void InsertSort(ElemType a[])
{
    for(int i=2;i<=L.length;i++)
        if(strcmp(a[i].name,a[i-1].name)<0)
        {
            a[0]=a[i];
            a[i]=a[i-1];
            int j;
            for(j=i-2;strcmp(a[0].name,a[j].name)<0;j--)
                a[j+1]=a[j];
            a[j+1]=a[0];
        }
}
void BInsertSort(ElemType a[])
{
    for(int i=2;i<=L.length;i++)
    {
        a[0]=a[i];
        int low=1,high=i-1;
        while(low<=high)
        {
            int m=(low+high)/2;
            if(strcmp(a[0].name,a[m].name)<0) high=m-1;
            else low=m+1;
        }
        for(int j=i-1;j>=high+1;--j) a[j+1]=a[j];
        a[high+1]=a[0];
    }
}
int Partition(ElemType a[],int low,int high)
{
    a[0]=a[low];
    int pivotkey=a[low].no;
    while(low<high)
    {
        while(low<high &&a[high].no>=pivotkey) --high;
        a[low]=a[high];
        while(low<high&&a[low].no<=pivotkey) ++low;
        a[high]=a[low];
    }
    a[low]=a[0];
    return low;
}
//�������򣬶�ѧ�Ž�������
void QSort(ElemType a[],int low,int high)
{
    if(low<high){
        int pivotloc=Partition(a,low,high);
        QSort(a,low,pivotloc-1);
        QSort(a,pivotloc+1,high);
    }
}
void QuickSort()
{
    if(L.length<1){
        cout<<endl<<"    ���ź����ձ���û���κμ�¼�ɹ���ʾ!"<<endl;
        return ;
    }
    cout<<"��ȷ�ϼ�¼�Ƿ�����ʽ���棺1.ֱ����ʾ�����¼ 2.�������򷽰�����ʾ��¼"<<endl;
    cout<<"��ѡ�����1-2(Ĭ��ѡ��1):";
    cin>>flag;
    
    if(flag!=2){
        ElemType a[MAXSIZE];//����ר����ʱ����
        for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
        QSort(a,1,L.length);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"��     "<<a[i].name<<"��     "<<a[i].no<<"��     "<<a[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***�����ɹ�***"<<endl;
        flag=1;
    }else{
        QSort(L.elem,1,L.length);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"��     "<<L.elem[i].name<<"��     "<<L.elem[i].no<<"��     "<<L.elem[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***�����ɹ�***"<<endl;
        flag=3;
    }
}
int Search_Bin(ElemType a[],char *key,int low,int high)
{
    if(low>high)
        return 0;
    else{
        int mid=(low+high)/2;
        if(strcmp(key,a[mid].name)==0) return mid;
        else if(strcmp(key,a[mid].name)<0) Search_Bin(a,key,low,mid-1);
        else Search_Bin(a,key,mid+1,high);
    }
}

void BinSearchByName()
{
    if(L.length<1){
        cout<<endl<<"    ���ź����ձ���û���κμ�¼�ɹ���ʾ!"<<endl;
        return ;
    }
    char s[20];
    cout<<"�����������в��ң����ش�ѧ����ѧ�źͳɼ�"<<endl;
    cout<<"������ѧ������:";
    cin>>s;
    if(flag!=2){
        cout<<"��⵽����δ�����ݿ����ݽ�����������";
        cout<<"���������ַ�����1.���ı�ԭ��������²��� 2.��ԭ���ݰ�����������ٲ���"<<endl;
        cout<<"��ѡ�����1-2(Ĭ��ѡ��1):";
        cin>>flag;
        if(flag!=2)
        {
            ElemType a[MAXSIZE];
            for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
            BInsertSort(a);
            int pos=Search_Bin(a,s,1,L.length);
            if(pos){//���ҵ����ݺ�
                cout<<"************ STUDENT ************"<<endl;
                cout<<"  ����     ѧ��     �ɼ�"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"   "<<a[pos].name<<"��     "<<a[pos].no<<"��     "<<a[pos].price<<endl;
                cout<<"*********************************"<<endl;
            }else{
                cout<<"û�в��ҵ�������"<<s<<"�ļ�¼";
            }
            flag=1;
        }else{
            BInsertSort(L.elem);
        }
    }
    if(flag==2){
        int pos=Search_Bin(L.elem,s,1,L.length);
        if(pos){//���ҵ����ݺ�
            cout<<"************ STUDENT ************"<<endl;
            cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"   "<<pos<<"��     "<<L.elem[pos].name<<"��     "<<L.elem[pos].no<<"��     "<<L.elem[pos].price<<endl;
            cout<<"*********************************"<<endl;
        }else{
            cout<<"û�в��ҵ�������"<<s<<"�ļ�¼";
        }
    }
}
//�۰����,�ǵݹ鷽��
int Non_Search_Bin(ElemType a[],int key)
{
    int low=1,high=L.length;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(key==a[mid].no) return mid;
        else if(key<a[mid].no) high=mid-1;
        else low=mid+1;
    }
    return 0;
}
void BinSearchByID()
{
    if(L.length<1){
        cout<<endl<<"    ���ź����ձ���û���κμ�¼�ɹ���ʾ!"<<endl;
        return ;
    }
    int s;
    cout<<"����ѧ�Ž��в��ң����ش�ѧ���������ͳɼ�"<<endl;
    cout<<"������ѧ��ѧ��:";
    cin>>s;
    if(flag!=3){
        cout<<"��⵽����δ�����ݿ����ݽ���ѧ������";
        cout<<"���������ַ�����1.���ı�ԭ��������²��� 2.��ԭ���ݰ�ѧ��������ٲ���"<<endl;
        cout<<"��ѡ�����1-2(Ĭ��ѡ��1):";
        cin>>flag;
        if(flag!=2)
        {
            ElemType a[MAXSIZE];
            for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
            QSort(a,1,L.length);
            int pos=Non_Search_Bin(a,s);
            if(pos){
                cout<<"************ STUDENT ************"<<endl;
                cout<<"  ����     ѧ��     �ɼ�"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"   "<<a[pos].name<<"��     "<<a[pos].no<<"��     "<<a[pos].price<<endl;
                cout<<"*********************************"<<endl;
            }else{
                cout<<"û�в��ҵ�������"<<s<<"�ļ�¼";
            }
            flag=1;
        }else{
            QSort(L.elem,1,L.length);
            flag=3;
        }
    }
    if(flag==3){
        int pos=Non_Search_Bin(L.elem,s);
        if(pos){
            cout<<"************ STUDENT ************"<<endl;
            cout<<"  ���     ����     ѧ��     �ɼ�"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"   "<<pos<<"��     "<<L.elem[pos].name<<"��     "<<L.elem[pos].no<<"��     "<<L.elem[pos].price<<endl;
            cout<<"*********************************"<<endl;
        }else{
            cout<<"û�в��ҵ�������"<<s<<"�ļ�¼";
        }
    }
}
int main()
{
                
    InitList();
    for(;;)               
    {
        switch(menu_select())               /*�������˵�����������ֵ������������������*/
        {
            case 1: Create();break;        //�½���¼
            case 2: ShowAllDate();break;   //��ʾȫ����¼
            case 3: InsertByID();break;    //�����¼
            case 4: DeleteByID();break;    //ͨ��IDɾ����¼
            case 5: cout<<"��ǰ�浵ѧ������Ϊ:"<<L.length;break;   //��ʾ����ѧ������
            case 6: SelectSort();break;//����ֱ�Ӳ�����������۰����������������������
            case 7: QuickSort();break;//���ÿ���������ѧ�Ž�������
            case 8: BinSearchByName();break;//�������������۰���ң�Ҫ��ʹ�õݹ��㷨ʵ�֣��ɹ����ش�ѧ����ѧ�źͳɼ���
            case 9: BinSearchByID();break;//����ѧ�Ž����۰���ң�Ҫ��ʹ�÷ǵݹ��㷨ʵ�֣��ɹ����ش�ѧ���������ͳɼ���
            case 10: exit(0);                  
        }
    }
    return 0;
}

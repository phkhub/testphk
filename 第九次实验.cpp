#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
#define MAXSIZE 100//
typedef struct{
    int no;   //8位学号
    char name[20]; //姓名
    int price;     //成绩
}Student,ElemType;
typedef  struct {
  Student   *elem=NULL;     //指向数据元素的基地址
  int  length;       //线性表的当前长度
 }SqList;

SqList L;

void InitList()
{
    L.elem=new ElemType[MAXSIZE];
    if(!L.elem) exit(0);
    L.length=0;
}
int menu_select()//选择菜单函数
{
    char s[3];
    int c;
    printf("\n         ***************主菜单**************\n");
    printf("         *    1. 录入新记录                *\n");
    printf("         *    2. 浏览显示所有记录          *\n");
    printf("         *    3. 插入记录                  *\n");
    printf("         *    4. 删除记录                  *\n");
    printf("         *    5. 统计记录                  *\n");
    printf("         *    6. 按姓名顺序显示所有记录    *\n");
    printf("         *    7. 按学号顺序显示所有记录    *\n");
    printf("         *    8. 通过姓名查找记录          *\n");
    printf("         *    9. 通过学号查找记录          *\n");
    printf("         *    10. 退出                      *\n");
    printf("         ***********************************\n\n");

    do
    {
        printf("         请选择操作(1-10):");
        scanf("%s",s);
        c=atoi(s);
    }while(c<0||c>10); 
    return(c); 
}

void Create()
{//新建学生数据
    int n;
    cout<<"根据指定学生个数，逐个输入学生信息:"<<endl;
    cout<<"学生个数n=";
    cin>>n;
    if(n<1||L.length+n>MAXSIZE){
        cout<<"创建失败"<<endl;
        return ;
    }
    for(int i=0;i<n;i++)
    {
        L.length++;
        cout<<"第"<<i+1<<"个学生数据"<<endl<<"姓名:";
        cin>>L.elem[L.length].name;
        cout<<"学号:";
        cin>>L.elem[L.length].no;
        cout<<"成绩:";
        cin>>L.elem[L.length].price;
    }
    cout<<"***操作成功***"<<endl;
}
void ShowAllDate()
{
    if(L.length<1)
    {
        cout<<endl<<"    很遗憾，空表中没有任何记录可供显示!"<<endl;
        return ;
    }
    cout<<"************ STUDENT ************"<<endl;
    cout<<"  编号     姓名     学号     成绩"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=1;i<=L.length;i++)
    {
        cout<<"   "<<i<<"　     "<<L.elem[i].name<<"　     "<<L.elem[i].no<<"　     "<<L.elem[i].price<<endl;
    }
    cout<<"*********************************"<<endl;
    cout<<"***操作成功***"<<endl;
}

bool InsertByID()
{
    int i;
    ElemType e;
    cout<<"给定一个学生信息，插入到表中指定的位置"<<endl;
    ShowAllDate();
    cout<<"请输入插入的位置:";
    cin>>i;
    if((i<1)||(i>L.length+1)){cout<<"位置不合法"; return false;}//i值不合法
    if(L.length==MAXSIZE) {cout<<"存储空间已满";return false;}//存储空间已满
    cout<<"请输入插入的数据:"<<endl;
    cout<<"姓名:";
    cin>>e.name;
    cout<<"学号:";
    cin>>e.no;
    cout<<"成绩:";
    cin>>e.price;
    for(int j=L.length;j>=i;j--){
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i]=e;
    ++L.length;
    cout<<"***操作成功***"<<endl;
    return true;
}
bool DeleteByID()
{
    int i;
    cout<<"删除指定位置的学生记录"<<endl;
    cout<<"位置i=";
    cin>>i;
    if((i<1)||(i>L.length)){
        cout<<"位置不合法";
        return false;
    }
    for(int j=i;j<=L.length-1;j++){
        L.elem[j]=L.elem[j+1];
    }
    --L.length;
    cout<<"***操作成功***"<<endl;
    return true;
}

int flag=0;

void InsertSort(ElemType *a);
void BInsertSort(ElemType *a);

void SelectSort()
{
    if(L.length<1){
        cout<<endl<<" 很遗憾，空表中没有任何记录可供显示!"<<endl;
        return ;
    }
    cout<<"在按姓名排序之前请先选择排序方法:1.直接插入排序  2.折半插入排序"<<endl;
    cout<<"请选择序号1-2(默认选择1):";
    int n;
    cin>>n;
    cout<<"请确认记录是否按排序方式保存：1.直接显示排序记录 2.保存排序方案并显示记录"<<endl;
    cout<<"请选择序号1-2(默认选择1):";
    cin>>flag;
    if(flag!=2){
        ElemType a[MAXSIZE];
      
        for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
        if(n==2)
            BInsertSort(a);
        else
            InsertSort(a);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  编号     姓名     学号     成绩"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"　     "<<a[i].name<<"　     "<<a[i].no<<"　     "<<a[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***操作成功***"<<endl;
        flag=1;
    }else{
        if(n==2)
            BInsertSort(L.elem);
        else
            InsertSort(L.elem);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  编号     姓名     学号     成绩"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"　     "<<L.elem[i].name<<"　     "<<L.elem[i].no<<"　     "<<L.elem[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***操作成功***"<<endl;
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
//快速排序，对学号进行排序
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
        cout<<endl<<"    很遗憾，空表中没有任何记录可供显示!"<<endl;
        return ;
    }
    cout<<"请确认记录是否按排序方式保存：1.直接显示排序记录 2.保存排序方案并显示记录"<<endl;
    cout<<"请选择序号1-2(默认选择1):";
    cin>>flag;
    
    if(flag!=2){
        ElemType a[MAXSIZE];//排序专用临时数组
        for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
        QSort(a,1,L.length);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  编号     姓名     学号     成绩"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"　     "<<a[i].name<<"　     "<<a[i].no<<"　     "<<a[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***操作成功***"<<endl;
        flag=1;
    }else{
        QSort(L.elem,1,L.length);
        cout<<"************ STUDENT ************"<<endl;
        cout<<"  编号     姓名     学号     成绩"<<endl;
        cout<<"---------------------------------"<<endl;
        for(int i=1;i<=L.length;i++)
        {
            cout<<"   "<<i<<"　     "<<L.elem[i].name<<"　     "<<L.elem[i].no<<"　     "<<L.elem[i].price<<endl;
        }
        cout<<"*********************************"<<endl;
        cout<<"***操作成功***"<<endl;
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
        cout<<endl<<"    很遗憾，空表中没有任何记录可供显示!"<<endl;
        return ;
    }
    char s[20];
    cout<<"根据姓名进行查找，返回此学生的学号和成绩"<<endl;
    cout<<"请输入学生姓名:";
    cin>>s;
    if(flag!=2){
        cout<<"检测到您还未对数据库数据进行姓名排序。";
        cout<<"现在有两种方案：1.不改变原数据情况下查找 2.给原数据按姓名排序后再查找"<<endl;
        cout<<"请选择序号1-2(默认选择1):";
        cin>>flag;
        if(flag!=2)
        {
            ElemType a[MAXSIZE];
            for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
            BInsertSort(a);
            int pos=Search_Bin(a,s,1,L.length);
            if(pos){//查找到数据后
                cout<<"************ STUDENT ************"<<endl;
                cout<<"  姓名     学号     成绩"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"   "<<a[pos].name<<"　     "<<a[pos].no<<"　     "<<a[pos].price<<endl;
                cout<<"*********************************"<<endl;
            }else{
                cout<<"没有查找到姓名："<<s<<"的记录";
            }
            flag=1;
        }else{
            BInsertSort(L.elem);
        }
    }
    if(flag==2){
        int pos=Search_Bin(L.elem,s,1,L.length);
        if(pos){//查找到数据后
            cout<<"************ STUDENT ************"<<endl;
            cout<<"  编号     姓名     学号     成绩"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"   "<<pos<<"　     "<<L.elem[pos].name<<"　     "<<L.elem[pos].no<<"　     "<<L.elem[pos].price<<endl;
            cout<<"*********************************"<<endl;
        }else{
            cout<<"没有查找到姓名："<<s<<"的记录";
        }
    }
}
//折半查找,非递归方法
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
        cout<<endl<<"    很遗憾，空表中没有任何记录可供显示!"<<endl;
        return ;
    }
    int s;
    cout<<"根据学号进行查找，返回此学生的姓名和成绩"<<endl;
    cout<<"请输入学生学号:";
    cin>>s;
    if(flag!=3){
        cout<<"检测到您还未对数据库数据进行学号排序。";
        cout<<"现在有两种方案：1.不改变原数据情况下查找 2.给原数据按学号排序后再查找"<<endl;
        cout<<"请选择序号1-2(默认选择1):";
        cin>>flag;
        if(flag!=2)
        {
            ElemType a[MAXSIZE];
            for(int i=1;i<=L.length;i++) a[i]=L.elem[i];
            QSort(a,1,L.length);
            int pos=Non_Search_Bin(a,s);
            if(pos){
                cout<<"************ STUDENT ************"<<endl;
                cout<<"  姓名     学号     成绩"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<"   "<<a[pos].name<<"　     "<<a[pos].no<<"　     "<<a[pos].price<<endl;
                cout<<"*********************************"<<endl;
            }else{
                cout<<"没有查找到姓名："<<s<<"的记录";
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
            cout<<"  编号     姓名     学号     成绩"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"   "<<pos<<"　     "<<L.elem[pos].name<<"　     "<<L.elem[pos].no<<"　     "<<L.elem[pos].price<<endl;
            cout<<"*********************************"<<endl;
        }else{
            cout<<"没有查找到姓名："<<s<<"的记录";
        }
    }
}
int main()
{
                
    InitList();
    for(;;)               
    {
        switch(menu_select())               /*调用主菜单函数，返回值整数作开关语句的条件*/
        {
            case 1: Create();break;        //新建记录
            case 2: ShowAllDate();break;   //显示全部记录
            case 3: InsertByID();break;    //插入记录
            case 4: DeleteByID();break;    //通过ID删除记录
            case 5: cout<<"当前存档学生个数为:"<<L.length;break;   //显示表中学生个数
            case 6: SelectSort();break;//利用直接插入排序或者折半插入排序按照姓名进行排序；
            case 7: QuickSort();break;//利用快速排序按照学号进行排序；
            case 8: BinSearchByName();break;//根据姓名进行折半查找，要求使用递归算法实现，成功返回此学生的学号和成绩；
            case 9: BinSearchByID();break;//根据学号进行折半查找，要求使用非递归算法实现，成功返回此学生的姓名和成绩。
            case 10: exit(0);                  
        }
    }
    return 0;
}

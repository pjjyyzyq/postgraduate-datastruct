#include<iostream>
using namespace std;

// 哈夫曼树的结点结构体定义，采用顺序存储
typedef struct{
    int weight;
    int parent,lchild,rchild;
}HTNode,*HuffmanTree;

// 构造哈夫曼树
void CreateHuffmanTree(HuffmanTree HT,int n){
    // 检验参数合法性
    if(n<=1)
        return;
    // 哈夫曼树共2n-1个元素结点
    int m=2*n-1;
    // 动态分配数组大小为HT[m+1]；HT[0]不使用，从下标1开始存；HT[m]表示根节点
    HT=(HTNode *)malloc((m+1)*sizeof(HTNode));
    // 将2n-1个元素结点的parent，lchild，rchild设为0
    for(int i=1;i<=m;i++){
        HT[i].parent=0;
        HT[i].lchild=0;
        HT[i].rchild=0;
    }
    // 输入前n个元素结点的weight值
    for(int i=1;i<=n;i++){
        cin>>HT[i].weight;
    }
    for(int i=n+1;i<=m;i++){
        int s1,s2;
        // Select函数实现在HT[1,i-1]中选择weight最小且parent为0的2个元素结点，其下标分别为s1，s2
        Select(HT,i-1,s1,s2);
        // s1和s2的双亲结点为i
        HT[s1].parent=i;
        HT[s2].parent=i;
        // 当前i结点的左右孩子分别为s1，s2
        HT[i].lchild=s1;
        HT[i].rchild=s2;
        // 当前i结点的weight值为s1，s2的weight值之和
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }   
}

typedef char *HuffmanCode;

// 构造哈夫曼编码，从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode *HC,int n){
    // 从动态数组下标1开始存，所以申请n+1个
    HC=(HuffmanCode *)malloc((n+1)*sizeof(char));
    char *cd=(char *)malloc(n*sizeof(char));
    cd[n-1]='\0';
    for(int i=1;i<=n;i++){
        int start=n-1;
        int c=i;
        int f=HT[i].parent;
        while(f!=0){
            --start;
            if(HT[f].lchild==c)
                cd[start]='0';
            else{
                c=f;
                f=HT[f].parent;
            }
            HC[i]=(char *)malloc((n-start)*sizeof(char));
            strcpy(HC[i],&cd[start]);
        }
    }
    free(cd);
}
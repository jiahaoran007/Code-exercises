#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAX_SIZE = 100;

class Set{
private:
    int a[MAX_SIZE];
    int n;

public:
    // 构造函数
    Set():n(0){
        memset(a, 0, sizeof(a));
    }

    // 元素增加操作
    void add(int x){
        if(n<MAX_SIZE && !find(x)){  // 集合内最多只存放100个元素，且元素不存在才能添加
            a[n++] = x;
            sort(a, a+n);  // 保证集合元素递增排列
        }
    }

    // 元素删除操作
    void remove(int x){
        int idx = find_index(x);  // 查找元素对应的下标
        if(idx!=-1){
            a[idx] = a[--n];  // 删除元素并覆盖后面的元素
        }
    }

    // 查询元素是否存在
    bool find(int x){
        return find_index(x)!=-1;  // 如果下标为-1，说明元素不存在
    }

    // 查找元素对应的下标
    int find_index(int x){
        for(int i=0;i<n;i++){
            if(a[i]==x){
                return i;
            }
        }
        return -1;
    }

    // 显示集合元素
    void show(){
        for(int i=0;i<n;i++){
            cout<<a[i]<<",";
        }
        cout<<endl;
    }

    // 集合交运算
    Set intersection(Set& rhs){
        Set ans;

        for(int i=0;i<n;i++){
            if(rhs.find(a[i])){
                ans.add(a[i]);
            }
        }

        return ans;
    }

    // 集合并运算
    Set union_set(Set& rhs){
        Set ans = *this;
        for(int i=0;i<rhs.n;i++){
            if(!ans.find(rhs.a[i])){
                ans.add(rhs.a[i]);
            }
        }

        return ans;
    }

    // 集合差运算
    Set difference(Set& rhs){
        Set ans = *this;

        for(int i=0;i<rhs.n;i++){
            ans.remove(rhs.a[i]);
        }

        return ans;
    }
};

int main(){
    int m, n;
    cin>>m>>n;

    Set A, B;

    for(int i=0;i<m;i++){
        int x; cin>>x;
        A.add(x);
    }

    for(int i=0;i<n;i++){
        int x; cin>>x;
        B.add(x);
    }

    cout<<"A: "; A.show();
    cout<<"B: "; B.show();

    cout<<"Intersection of A and B: "; A.intersection(B).show();
    cout<<"Union of A and B: "; A.union_set(B).show();
    cout<<"Difference between A and B: "; A.difference(B).show();

    return 0;
}

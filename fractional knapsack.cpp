//fractional knapsack problem

#include<bits/stdc++.h>
using namespace std;
class item{
public:
    int wt, val;
    item(int wt, int val){
        this->wt = wt;
        this->val = val;
    }
};

bool cmp(item a, item b){
    double r1 = (double)a.val/a.wt;
    double r2 = (double)b.val/b.wt;
    return r1>r2;
}
double fractionalKnapsack(int W, item arr[], int n){
    sort(arr, arr+n, cmp);
    int curWeight = 0;
    double finalValue = 0.0;

    for(int i=0; i<n; i++){
        if(curWeight + arr[i].wt <= W){
            curWeight += arr[i].wt;
            finalValue += arr[i].val;
        }
        else{
            int remain = W - curWeight;
            finalValue += arr[i].val*((double)remain/arr[i].wt);
            break;
        }
    }
    return finalValue;
}
int main(){
    int W = 50;
    item arr[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum value we can obtain = "<<fractionalKnapsack(W, arr, n);
    return 0;
}

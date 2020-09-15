#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define M 1000000007
void heapify(int a[] , int i,int k){
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if (l < k && a[l] < a[i])
        smallest = l;
    if (r < k && a[r] < a[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        heapify(a,smallest,k);
    }
}
void minheap(int a[] , int k){
    for(int i =  k/2-1 ; i>=0 ; i--){
        heapify(a,i,k);
    }
}
int main()
{
    fast
    int t;
    cin >> t;
    while(t--){
        int k , n;
        cin >> k >> n;
        int a[n+1];
        int count = 0 ,x;
        while(n--){
            cin >>x;
            if(count<k-1){
                a[count++] = x;
                cout << "-1 ";
            }
            else if(count == k-1){
                a[count++] = x;
                minheap(a,k);
                cout<<a[0]<<" ";
            }
            else{
                if(x>a[0]){
                    a[0]=x;
                    heapify(a,0,k);
                    cout<<a[0]<<" ";
                }
                else
                cout<<a[0]<< " ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

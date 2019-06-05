///https://www.codechef.com/LTIME60B/problems/TRACE
#include<bits/stdc++.h>
#include<utility>
using namespace std;
int binary_search(int a[],int N,int x){
    int low=1,high=N;
    int mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==x)
            break;
        else if(a[mid]<x)
            low=mid+1;
        else
            high=mid-1;
        mid=(low+high)/2;
    }
    return mid;
}

long long int f(int a[],int b[],int index[],int N,int X){
    long long int swaps=0;
    int temp=binary_search(b,N,X);
    int indexX=index[temp];
    int sp=temp-1,hp=N-temp,small=0,large=0; // no of small & large elements than 'X'
    int low=1,high=N;
    int mid=(low+high)/2;
    while(low<=high){
        if(a[mid]==X)
            break;
        if(indexX>mid){
            if(a[mid]>X) // case like 7....'4'
				large+=1;
			low=mid+1;
        }
        else if(indexX<mid){
            if(X>a[mid]) // case like '7'....4
				small+=1;
			high=mid-1;
        }
        mid=(low+high)/2;
    }
    if(large>small){
		swaps=small;
		large=large-small;
		sp=sp-small;
		if(sp>=large)return swaps+large;
		else return -1;
    }
    else if(small>large){
		swaps=large;
		small=small-large;
		hp=hp-large;
		if(hp>=small)return swaps+small;
		else return -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        long long int row[N]={0},col[N]={0};
        int a[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>a[i][j];
                if(j>=i)
                    row[j-i]+=a[i][j];
                else
                    col[i-j]+=a[i][j];
            }
        }
        long long int m=0;
        for(int i=0;i<N;i++)
            m=max(m,row[i]);
        for(int i=1;i<N;i++)
            m=max(m,col[i]);
        cout<<m<<"\n";
    }
    return 0;
}

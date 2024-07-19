// Minimise the maximum difference between heights [V.IMP] 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin>>k>>n;

    vector<int> vec(n);

    cout<<"vec = ";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    

    //sorting
    sort(vec.begin(),vec.end());

    int ans = vec[n-1] - vec[0];

    int sm = vec[0] +k;
    int lg = vec[n-1] -k;
    int mi,ma;

    for(int i=0;i<n-1;i++){

        mi = min(sm,vec[i+1]-k);
        ma = max(lg,vec[i]+k);

        if(mi<0)
            continue;
    
        ans = min(ans,ma-mi);
    }

    cout<<"ans = "<<ans;

}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    vector<string> v1 ={"119","97674223", "1195524421"};
    vector<string> v2 ={"123","456","789"};
    vector<string> v3 ={"12","123","1235","567","88"};
    string sum;

    //정렬을 조지면 제일 작은 크기의 문자열이 0번으로 무조건 온다
    sort(v1.begin(), v1.end());
    //따라서 정렬 후에

    bool answer = true;
    for(int i=0;i<v3.size();i++){
        cout<<v1[i]<<endl;
        if(sum.find(v3[0])!=string::npos){
            answer=false;
            sum.append(v3[i]);
        }
        else{
            answer=true;
            sum.append(v3[i]);
        }
    }
    cout<<sum<<endl;
    cout<<answer<<endl;
}
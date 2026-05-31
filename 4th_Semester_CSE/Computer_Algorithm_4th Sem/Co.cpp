#include<iostream>
using namespace std;
int main(){
    int N;
    string S;
cout<<"Enter the String Length"<<endl;
cin>>N;
cout<<"Enter the String:"<<endl;
cin>>S;
int freq[26]={0};
for(char C:S){
    freq[C-'a']++;
}
int Deletions=0;
for(int i=0;i<26;i++){
   if(freq[i]%2==1){
    Deletions++;
}
}
cout<<N-Deletions<<endl;
return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
int main()
{
    vector<int> v = {7,4,3,9,1,8,5,2,6};
    string vv = "abciiidef";
    int k=3;
    int m = max_number_vowels(vv,k);
    cout<<m<<endl;

    return 0;
}
*/

string longest_substrings_k_distincts_char1(string& text, int k){
    int n = text.size();

    string res = "";
    string l = "";

    unordered_map<char, int> m;

    for(int i=0; i<text.size(); i++){
        l += text[i];
        m[text[i]]++;

        if(m.size()>k){
            m[l[0]]--;
            if(m[l[0]]==0){
                m.erase(l[0]);
            }
            l.erase(0,1);
        }

        if(l.size()>=res.size() && m.size()==k){
            res = l;

        }
    }

    return res;
}

string longest_substrings_k_distincts_char(string& text, int k){

    string res = "";
    int l = 0;

    int lb = 0;
    int len = 0;

    unordered_map<char, int> m;

    for(int r=0; r<text.size(); r++){

        m[text[r]]++;

        while(m.size()>k){
            m[text[l]]--;
            if(m[text[l]]==0){
                m.erase(text[l]);
            }
            l++;
        }

        if(m.size()<=k && r-l+1>len){
            lb = l;
            len = r-l+1;
        }
    }

    res = text.substr(lb, len);
    return res;
}

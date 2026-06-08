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

string longest_substrings_k_distincts_char3(string v, int k){

    int n = 0;
    string res = "";
    string sub = "";
    for(int i=0; i<v.size(); i++){
        sub = v[i]; n = 1;
        for(int j=i+1; j<v.size(); j++){
            if(sub.find(v[j]) == std::string::npos){
                n++;
                if(n>k){
                    break;
                }
                else{
                    sub += v[j];
                }
            }
            else{
                sub += v[j];
            }
        }
        if(sub.size()>res.size()){
            res = sub;
        }
    }

    cout<<res<<endl;
    return res;
}

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

/*
7. **Length of the Longest Substring That Doesn't Contain Any Vowels**

   Input: `s = "codeforintelligents"`

   Output: `3`

   Explanation: 'nts' is the longest substring that doesn't contain any vowels.
*/

int longest_substring_no_vowels(string v){

    string vowels = "aeiouy";
    string res = "";

    int left = 0;

    int start = 0;
    int len = 0;

    for(int right=0; right<v.size(); right++){

        if(vowels.find(v[right]) != std::string::npos){
            left = right+1;
        }

        if(right-left+1>len){
            len = right-left+1;
            start = left;
        }
    }

    res = v.substr(start, len);
    cout<<res<<res.size()<<endl;
    return res.size();
}

// No sliding window
int longest_substring_no_vowels_no_sw(string v){

    string vowels = "aeiouy";
    string res = "";
    string sub = "";

    int left = 0;


    for(int right=0; right<v.size(); right++){

        if(vowels.find(v[right]) == std::string::npos){
            sub += v[right];
        }
        else{
            sub = "";
        }

        if(sub.size()>res.size()){
            res = sub;
        }
    }

    return res.size();
}

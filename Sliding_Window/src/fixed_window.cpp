#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
1. **Maximum Sum Subarray of Size K**

   Given an array of positive integers and a positive number k, find the maximum sum of any contiguous subarray of size k.

   Input: `[3, 5, 2, 1, 7]`, `k=2`
   Output: `8`

   The subarray `[1, 7]` is the sum of the maximum sum.

*/

int max_sum_subarray(vector<int>& v, int k){
    int sub = 0;

    for(int i=0; i<k; i++){
        sub += v[i];
    }

    int res = sub;

    for(int i=k; i<v.size(); i++){
        sub += v[i] - v[i-k];
        res = max(sub, res);
    }

    return res;
}

/*
2. **Count Occurrences of Anagram**

   Given a word and a text, return the count of occurrences of the anagrams of the word in the text.

   Input: `text = gotxxotgxdogt`, `word = got`
   Output: `3`

   Words "got," "otg" and "ogt" are anagrams of "got."

*/
bool isAnagram(string& word1, string& word2){

    if (word1.size() != word2.size()){
        return false;
    }

    map<char, int> m1;
    map<char, int> m2;

    for(char& m: word1){
        m1[m]++;
    }

    for(char& m: word2){
        m2[m]++;
    }

    return m1==m2;
}

int cout_occurences(string& text, string& word){
    int n = text.size();
    int k = word.size();
    int res = 0;
    string sub = "";

    for(int i=0; i<k; i++){
        sub += text[i];
    }

    if(isAnagram(sub, word)){
        res++;
    }

    for(int i=k; i<n; i++){
        sub += text[i];
        sub.erase (0,1);
        if(isAnagram(sub, word)){
            res++;
        }
    }

    return res;
}

/*
3. **Difference Between the Maximum and Minimum Average of all K-Length Continuous Subarrays**

   Input: `arr[] = {3, 8, 9, 15}`, `K = 2`
   Output: `6.5`

   All subarrays of length 2 are `{3, 8}`, `{8, 9}`, `{9, 15}`
   and their averages are `(3+8)/2 = 5.5`, `(8+9)/2 = 8.5`, and `(9+15)/2 = 12.0` respectively.

   Therefore, the difference between the maximum(=12.0) and minimum(=5.5) is `12.0 - 5.5 = 6.5`.

*/


float average_min_max_mean(vector<int>& v, int k){


    float sub = 0;
    for(int i=0; i<k; i++){
        sub += v[i];
    }

    float mean = sub/k;

    float maxi = mean;
    float mini = mean;

    for(int i=k; i<v.size(); i++){
        sub += v[i] - v[i-k];
        mean = sub/k;
        maxi = max(maxi, mean);
        mini = min(mini, mean);
    }

    return maxi - mini;
}

/*
5. **Find Duplicates Within a Range 'K' in an Array**

   Input: `nums = [5, 6, 8, 2, 4, 6, 9]`, `k = 2`
   Output: `False`

*/

bool find_duplicate_within_range1(vector<int>& v, int k){

    unordered_set<int> s;

    for(int i=0; i<v.size(); i++){
        auto it = s.find(v[i]);
        if(it != s.end()){
            return true;
        }
        else{
            s.insert(v[i]);
        }

        if(s.size()>k){
            s.erase(v[i-k]);
        }
    }

    return false;
}

bool find_duplicate_within_range2(vector<int>& v, int k){

    list<int> s;

    for(int& a: v){
        auto it = find(s.begin(), s.end(), a);
        if(it != s.end()){
            return true;
        }
        else{
            s.push_back(a);
        }

        if(s.size()>k){
            s.pop_front();
        }
    }

    return false;
}

/*
6. **Find Minimum Sum SubArray of Size K**

   Input: `arr = [10, 4, 2, 5, 6, 3, 8, 1]`, `k = 3`
   Output: `11`

*/

int min_sum_subarray(vector<int>& v, int k){
    int sub = 0;

    for(int i=0; i<k; i++){
        sub += v[i];
    }

    int res = sub;

    for(int i=k; i<v.size(); i++){
        sub += v[i] - v[i-k];
        res = min(res, sub);
    }

    return res;
}

/*
8. **Count Negative Elements Present in Every K-Length Subarray**

   Input: `arr = [-1, 2, -2, 3, 5, -7, -5]`, `K = 3`
   Output: `2, 1, 1, 1, 2`
*/

vector<int> neg_elements_in_subarray(vector<int>& v, int k){
    vector<int> res;
    int n = 0;

    for(int i=0; i<k; i++){
        if(v[i]<0){
            n++;
        }
    }

    res.push_back(n);

    for(int i=k; i<v.size(); i++){
        if(v[i]<0){
            n++;
        }
        if(v[i-k]<0){
            n--;
        }
        res.push_back(n);
    }

    for(auto a: res){
        cout<<a<<" ";
    }

    return res;
}

/*
11. **Count Distinct Absolute Values in a Sorted Array**

    Input: `{ -1, -1, 0, 1, 1, 1 }`
    Output: The total number of distinct absolute values is 2 (0 and 1).
*/

int count_distinct_absolute_values(vector<int>& v){
    int res = 0;
    set<int> s;

    for(int i=0; i<v.size(); i++){
        if(s.find(abs(v[i]))==s.end()){
            s.insert(abs(v[i]));
        }
    }

    return s.size();
}

/*
12. **Permutation in String**

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    Input: `s1 = "ab"`, `s2 = "eidbaooo"`
    Output: `true`
    Explanation: s2 contains one permutation of s1 ("ba").
*/

bool isAnagramm(string& s1, string& s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    map<char, int> m;

    for(auto a: s1){
        m[a]++;
    }

    for(auto a: s2){
        m[a]--;
    }

    for(auto a: m){
        if(a.second!=0){
            return false;
        }
    }

    return true;
}

bool permutation_in_string(string& s1, string& s2){
    int k = s1.size();
    string w = "";

    for(int i=0; i<k; i++){
        w += s2[i];
    }

    if(isAnagramm(s1,w)){
        return true;
    }

    for(int i=k; i<s2.size(); i++){
        w += s2[i];
        w.erase(0, 1);
        if(isAnagramm(s1,w)){
            return true;
        }
    }

    return false;
}

/*
13. **Find All Anagrams in a String**

    Input: `s = "cbaebabacd"`, `p = "abc"`
    Output: `[0,6]`
    Explanation:
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

vector<int> find_all_anagrams(string& s1, string& s2){
    int k = s1.size();
    string w = "";
    vector<int> res;

    for(int i=0; i<k; i++){
        w += s2[i];
    }

    if(isAnagramm(s1,w)){
        res.push_back(0);
    }

    for(int i=k; i<s2.size(); i++){
        w += s2[i];
        w.erase(0, 1);
        if(isAnagramm(s1,w)){
            res.push_back(i-k+1);
        }
    }

    for(auto a: res){
        cout<<a<<" ";
    }

    return res;
}

/*
14. **Maximum Average Subarray I**

    You are given an integer array of nums consisting of n elements and an integer k.

    Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10⁻⁵ will be accepted.

    Input: `nums = [1,12,-5,-6,50,3]`, `k = 4`
    Output: `12.75000`
    Explanation: Maximum average is `(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75`.
*/


double max_average_subarray(vector<int>& v, int k){

    double res;
    double sub = 0;

    for(int i=0; i<k; i++){
        sub += v[i];
    }

    res = sub;

    for(int i=k; i<v.size(); i++){
        sub += v[i] - v[i-k];
        res = max(res, sub);
    }

    return res/k;
}

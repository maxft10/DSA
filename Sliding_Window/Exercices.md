# Sliding Window Algorithm

```
Taille fixe (k est donné)
1, 3, 6, 8, 14, 15, 16, 20, 24, 29

Taille variable (la fenêtre grandit/rétrécit selon une condition)
4, 7, 9, 10, 17, 18, 21, 23, 25, 26, 27, 28, 30, 31, 33, 34, 35

2 (fixed size + hashmap), 
5 (fixed size + hashmap), 
11 (two pointers ou bien hashmap), 
12 (fixed size + hashmap), 
13 (comme 2 et 12), 
19 (Taille fixe sur minSize suffit (le maxSize est un piège)), 
22 (Fenêtre fixe sur le complément (inverser le problème)), 
32
```

1. **Maximum Sum Subarray of Size K**

    Given an array of positive integers and a positive number k, find the maximum sum of any contiguous subarray of size k.

    Input: `[3, 5, 2, 1, 7]`, `k=2`
   
    Output: `8`

    The subarray `[1, 7]` is the sum of the maximum sum.

3. **Count Occurrences of Anagram**

    Given a word and a text, return the count of occurrences of the anagrams of the word in the text.

    Input: `text = gotxxotgxdogt`, `word = got`
   
    Output: `3`

    Words "got," "otg" and "ogt" are anagrams of "got."

5. **Difference Between the Maximum and Minimum Average of all K-Length Continuous Subarrays**

    Input: `arr[] = {3, 8, 9, 15}`, `K = 2`
   
    Output: `6.5`

    All subarrays of length 2 are `{3, 8}`, `{8, 9}`, `{9, 15}` and their averages are `(3+8)/2 = 5.5`, `(8+9)/2 = 8.5`, and `(9+15)/2 = 12.0` respectively.

    Therefore, the difference between the maximum(=12.0) and minimum(=5.5) is `12.0 - 5.5 = 6.5`.

7. **Find the Longest Substring of a String Containing 'K' Distinct Characters**

    Input: `s = 'abcbdbdbbdcdabd'`, `k = 2`
   
    Output: `bdbdbbd`

9. **Find Duplicates Within a Range 'K' in an Array**

    Input: `nums = [5, 6, 8, 2, 4, 6, 9]`, `k = 2`
   
    Output: `False`

11. **Find Minimum Sum SubArray of Size K**

    Input: `arr = [10, 4, 2, 5, 6, 3, 8, 1]`, `k = 3`
   
    Output: `11`

11. **Length of the Longest Substring That Doesn't Contain Any Vowels**

    Input: `s = "codeforintelligents"`
      
    Output: `3`
      
    Explanation: 'nts' is the longest substring that doesn't contain any vowels.

11. **Count Negative Elements Present in Every K-Length Subarray**

    Input: `arr = [-1, 2, -2, 3, 5, -7, -5]`, `K = 3`
   
    Output: `2, 1, 1, 1, 2`

11. **Minimum Size Subarray Sum**

    Input: `target = 7`, `nums = [2,3,1,2,4,3]`
   
    Output: `2`
   
    Explanation: The subarray `[4,3]` has the minimal length under the problem constraint.

11. **Longest Repeating Character Replacement**

    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Input: `s = "ABAB"`, `k = 2`
    
    Output: `4`
    
    Explanation: Replace the two 'A's with two 'B's or vice versa.

13. **Count Distinct Absolute Values in a Sorted Array**

    Input: `{ -1, -1, 0, 1, 1, 1 }`
    
    Output: The total number of distinct absolute values is 2 (0 and 1).

15. **Permutation in String**

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    Input: `s1 = "ab"`, `s2 = "eidbaooo"`
    
    Output: `true`
    
    Explanation: s2 contains one permutation of s1 ("ba").

17. **Find All Anagrams in a String**

    Input: `s = "cbaebabacd"`, `p = "abc"`
    
    Output: `[0,6]`
    
    Explanation:
    
    The substring with start index = 0 is "cba", which is an anagram of "abc".
    
    The substring with start index = 6 is "bac", which is an anagram of "abc".

19. **Maximum Average Subarray I**

    You are given an integer array of nums consisting of n elements and an integer k.

    Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10⁻⁵ will be accepted.

    Input: `nums = [1,12,-5,-6,50,3]`, `k = 4`
    
    Output: `12.75000`
    
    Explanation: Maximum average is `(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75`.

21. **K Radius Subarray Averages**

    Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

    Input: `nums = [7,4,3,9,1,8,5,2,6]`, `k = 3`
    
    Output: `[-1,-1,-1,5,4,4,-1,-1,-1]`

23. **Substrings of Size Three With Distinct Characters**

    A string is good if there are no repeated characters.

    Given a string s, return the number of good substrings of length three in s. If there are multiple occurrences of the same substring, every occurrence should be counted. A substring is a contiguous sequence of characters in a string.

    Input: `s = "xyzzaz"`
    
    Output: `1`
    
    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". The only good substring of length 3 is "xyz".

25. **Frequency of the Most Frequent Element**

    The frequency of an element is the number of times it occurs in an array.

    You are given an integer array nums and an integer k. In one operation, you can choose an index of nums and increment the element at that index by 1.

    Return the maximum possible frequency of an element after performing at most k operations.

    Input: `nums = [1,2,4]`, `k = 5`
    
    Output: `3`
    
    Explanation: Increment the first element three times and the second element two times to make `nums = [4,4,4]`. 4 has a frequency of 3.

27. **Maximum Erasure Value**

    You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

    Return the maximum score you can get by erasing exactly one subarray.

    An array b is called to be a subarray if it forms a contiguous subsequence of a — that is if it is equal to `a[l], a[l+1], …, a[r]` for some `(l, r)`.

    Input: `nums = [4,2,4,5,6]`
    
    Output: `17`
    
    Explanation: The optimal subarray here is `[2,4,5,6]`.

29. **Maximum Number of Occurrences of a Substring**

    Given a string s, return the maximum number of occurrences of any substring under the following rules:
    - The number of unique characters in the substring must be less than or equal to maxLetters.
    - The substring size must be between minSize and maxSize inclusive.

    Input: `s = "aababcaab"`, `maxLetters = 2`, `minSize = 3`, `maxSize = 4`
    
    Output: `2`
    
    Explanation: Substring "aab" has 2 occurrences in the original string. It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

31. **Number of Subarrays of Size K and Average Greater than or Equal to Threshold**

    Given an array of integers arr and two integers k and threshold.

    Return the number of subarrays of size k and average greater than or equal to a threshold.

    Input: `arr = [2,2,2,2,5,5,5,8]`, `k = 3`, `threshold = 4`
    
    Output: `3`
    
    Explanation: Sub-arrays `[2,5,5]`, `[5,5,5]` and `[5,5,8]` have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

33. **Number of Substrings Containing All Three Characters**

    Given a string s consisting only of characters a, b and c.

    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Input: `s = "abcabc"`
    
    Output: `10`
    
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

35. **Maximum Points You Can Obtain from Cards**

    There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

    In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

    Your score is the sum of the points of the cards you have taken.

    Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

    Input: `cardPoints = [1,2,3,4,5,6,1]`, `k = 3`
    
    Output: `12`
    
    Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of `1 + 6 + 5 = 12`.

37. **Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit**

    Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to the limit.

    Input: `nums = [8,2,4,7]`, `limit = 4`
    
    Output: `2`
    
    Explanation: All subarrays are:
    ```
    `[8]` with maximum absolute diff `|8-8| = 0 <= 4`.
    `[8,2]` with maximum absolute diff `|8-2| = 6 > 4`.
    `[8,2,4]` with maximum absolute diff `|8-2| = 6 > 4`.
    `[8,2,4,7]` with maximum absolute diff `|8-2| = 6 > 4`.
    `[2]` with maximum absolute diff `|2-2| = 0 <= 4`.
    `[2,4]` with maximum absolute diff `|2-4| = 2 <= 4`.
    `[2,4,7]` with maximum absolute diff `|2-7| = 5 > 4`.
    `[4]` with maximum absolute diff `|4-4| = 0 <= 4`.
    `[4,7]` with maximum absolute diff `|4-7| = 3 <= 4`.
    `[7]` with maximum absolute diff `|7-7| = 0 <= 4`.
    Therefore, the size of the longest subarray is 2.
    ```

39. **Maximum Number of Vowels in a Substring of Given Length**

    Given a string s and an integer k.

    Return the maximum number of vowel letters in any substring of s with length k.

    Vowel letters in English are (a, e, i, o, u).

    Input: `s = "abciiidef"`, `k = 3`
    
    Output: `3`
    
    Explanation: The substring "iii" contains 3 vowel letters.

40. **Find Two Non-Overlapping Subarrays Each With Target Sum**

    Given an array of integers arr and an integer target.

    You have to find two non-overlapping subarrays of arr each with a sum equal to target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two subarrays is minimum.

    Return the minimum sum of the lengths of the two required subarrays, or return -1 if you cannot find such two subarrays.

    Input: `arr = [3,2,2,4,3]`, `target = 3`
    
    Output: `2`
    
    Explanation: Only two sub-arrays have sum = 3 (`[3]` and `[3]`). The sum of their lengths is 2.

42. **Longest Subarray of 1's After Deleting One Element**

    Given binary array nums, you should delete one element from it.

    Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

    Input: `nums = [1,1,0,1]`
    
    Output: `3`
    
    Explanation: After deleting the number in position 2, `[1,1,1]` contains 3 numbers with value of 1's.

44. **Minimum Operations to Reduce X to Zero**

    You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

    Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

    Input: `nums = [1,1,4,2,3]`, `x = 5`
    
    Output: `2`
    
    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

46. **Get Equal Substrings Within Budget**

    You are also given an integer maxCost.

    Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost.

    If there is no substring from s that can be changed to its corresponding substring from t, return 0.

    Input: `s = "abcd"`, `t = "bcdf"`, `maxCost = 3`
    
    Output: `3`
    
    Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

48. **Grumpy Bookstore Owner**

    There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array of customers of length n where `customers[i]` is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

    For some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where `grumpy[i]` is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

    When the bookstore owner is grumpy, the customers during that minute aren't satisfied, otherwise, they are satisfied.

    The bookstore owner knows a secret technique to keep themselves not grumpy for consecutive minutes but can only use it once.

    Return the maximum number of customers that can be satisfied throughout the day.

    Input: `customers = [1,0,1,2,1,1,7,5]`, `grumpy = [0,1,0,1,0,1,0,1]`, `minutes = 3`
    
    Output: `16`
    
    Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
    The maximum number of customers that can be satisfied = `1 + 1 + 1 + 1 + 7 + 5 = 16`.

50. **Max Consecutive Ones III**

    Given binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

    Input: `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`
    
    Output: `6`
    
    Explanation: `[1,1,1,0,0,1,1,1,1,1,1]`
    
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

52. **Binary Subarrays With Sum**

    Given binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal. A subarray is a contiguous part of the array.

    Input: `nums = [1,0,1,0,1]`, `goal = 2`
    
    Output: `4`
    
    Explanation: The 4 subarrays are:
    ```
    `[1,0,1,0,1]`
    `[1,0,1,0,1]`
    `[1,0,1,0,1]`
    `[1,0,1,0,1]`
    ```

54. **Maximum Length of Repeated Subarray**

    Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

    Input: `nums1 = [1,2,3,2,1]`, `nums2 = [3,2,1,4,7]`
    
    Output: `3`
    
    Explanation: The repeated subarray with maximum length is `[3,2,1]`.

56. **Longest Turbulent Subarray**

    Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

    A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

    Input: `arr = [9,4,2,10,7,8,8,1,9]`
    
    Output: `5`
    
    Explanation: `arr[1] > arr[2] < arr[3] > arr[4] < arr[5]`

58. **Longest Substring Of All Vowels in Order**

    Given a string word consisting of English vowels, return the length of the longest beautiful substring of a word. If no such substring exists, return 0.

    A substring is a contiguous sequence of characters in a string.

    Input: `word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"`
    
    Output: `13`
    
    Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.

60. **Fruit Into Baskets**

    You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where `fruits[i]` is the type of fruit the ith tree produces.

    You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
    - You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
    - Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
    - Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

    Given the integer array, return the maximum number of fruits you can pick.

    Input: `fruits = [1,2,1]`
    
    Output: `3`
    
    Explanation: We can pick from all 3 trees.

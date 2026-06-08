# Sliding Window Algorithm

**Taille fixe (k est donné)**
1, 3, 6, 8, 14, 15, 16, 20, 24, 29

**Taille variable (la fenêtre grandit/rétrécit selon une condition)**
4, 7, 9, 10, 17, 18, 21, 23, 25, 26, 27, 28, 30, 31, 33, 34, 35

**Variantes :**
- 2 (fixed size + hashmap)
- 5 (fixed size + hashmap)
- 11 (two pointers ou bien hashmap)
- 12 (fixed size + hashmap)
- 13 (comme 2 et 12)
- 19 (Taille fixe sur minSize suffit (le maxSize est un piège))
- 22 (Fenêtre fixe sur le complément (inverser le problème))
- 32

---

1. **Maximum Sum Subarray of Size K**

   Given an array of positive integers and a positive number k, find the maximum sum of any contiguous subarray of size k.

   Input: `[3, 5, 2, 1, 7]`, `k=2`

   Output: `8`

   The subarray `[1, 7]` is the sum of the maximum sum.

2. **Count Occurrences of Anagram**

   Given a word and a text, return the count of occurrences of the anagrams of the word in the text.

   Input: `text = gotxxotgxdogt`, `word = got`

   Output: `3`

   Words "got," "otg" and "ogt" are anagrams of "got."

3. **Difference Between the Maximum and Minimum Average of all K-Length Continuous Subarrays**

   Input: `arr[] = {3, 8, 9, 15}`, `K = 2`

   Output: `6.5`

   All subarrays of length 2 are `{3, 8}`, `{8, 9}`, `{9, 15}` and their averages are `(3+8)/2 = 5.5`, `(8+9)/2 = 8.5`, and `(9+15)/2 = 12.0` respectively.

   Therefore, the difference between the maximum(=12.0) and minimum(=5.5) is `12.0 - 5.5 = 6.5`.

4. **Find the Longest Substring of a String Containing 'K' Distinct Characters**

   Input: `s = 'abcbdbdbbdcdabd'`, `k = 2`

   Output: `bdbdbbd`

5. **Find Duplicates Within a Range 'K' in an Array**

   Input: `nums = [5, 6, 8, 2, 4, 6, 9]`, `k = 2`

   Output: `False`

6. **Find Minimum Sum SubArray of Size K**

   Input: `arr = [10, 4, 2, 5, 6, 3, 8, 1]`, `k = 3`

   Output: `11`

7. **Length of the Longest Substring That Doesn't Contain Any Vowels**

   Input: `s = "codeforintelligents"`

   Output: `3`

   Explanation: 'nts' is the longest substring that doesn't contain any vowels.

8. **Count Negative Elements Present in Every K-Length Subarray**

   Input: `arr = [-1, 2, -2, 3, 5, -7, -5]`, `K = 3`

   Output: `2, 1, 1, 1, 2`

9. **Minimum Size Subarray Sum**

   Input: `target = 7`, `nums = [2,3,1,2,4,3]`

   Output: `2`

   Explanation: The subarray `[4,3]` has the minimal length under the problem constraint.

10. **Longest Repeating Character Replacement**

    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Input: `s = "ABAB"`, `k = 2`

    Output: `4`

    Explanation: Replace the two 'A's with two 'B's or vice versa.

11. **Count Distinct Absolute Values in a Sorted Array**

    Input: `{ -1, -1, 0, 1, 1, 1 }`

    Output: The total number of distinct absolute values is 2 (0 and 1).

12. **Permutation in String**

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    Input: `s1 = "ab"`, `s2 = "eidbaooo"`

    Output: `true`

    Explanation: s2 contains one permutation of s1 ("ba").

13. **Find All Anagrams in a String**

    Input: `s = "cbaebabacd"`, `p = "abc"`

    Output: `[0,6]`

    Explanation: The substring with start index = 0 is "cba", which is an anagram of "abc". The substring with start index = 6 is "bac", which is an anagram of "abc".

14. **Maximum Average Subarray I**

    You are given an integer array of nums consisting of n elements and an integer k.

    Input: `nums = [1,12,-5,-6,50,3]`, `k = 4`

    Output: `12.75000`

    Explanation: Maximum average is `(12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75`.

15. **K Radius Subarray Averages**

    Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

    Input: `nums = [7,4,3,9,1,8,5,2,6]`, `k = 3`

    Output: `[-1,-1,-1,5,4,4,-1,-1,-1]`

16. **Substrings of Size Three With Distinct Characters**

    Given a string s, return the number of good substrings of length three in s.

    Input: `s = "xyzzaz"`

    Output: `1`

    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". The only good substring of length 3 is "xyz".

17. **Frequency of the Most Frequent Element**

    You are given an integer array nums and an integer k. In one operation, you can increment any element by 1. Return the maximum possible frequency of an element after performing at most k operations.

    Input: `nums = [1,2,4]`, `k = 5`

    Output: `3`

    Explanation: Increment the first element three times and the second element two times to make `nums = [4,4,4]`.

18. **Maximum Erasure Value**

    You are given an array of positive integers nums. Return the maximum score you can get by erasing exactly one subarray containing unique elements.

    Input: `nums = [4,2,4,5,6]`

    Output: `17`

    Explanation: The optimal subarray here is `[2,4,5,6]`.

19. **Maximum Number of Occurrences of a Substring**

    Input: `s = "aababcaab"`, `maxLetters = 2`, `minSize = 3`, `maxSize = 4`

    Output: `2`

    Explanation: Substring "aab" has 2 occurrences. It satisfies the conditions: 2 unique letters and size 3.

20. **Number of Subarrays of Size K and Average Greater than or Equal to Threshold**

    Input: `arr = [2,2,2,2,5,5,5,8]`, `k = 3`, `threshold = 4`

    Output: `3`

    Explanation: Sub-arrays `[2,5,5]`, `[5,5,5]` and `[5,5,8]` have averages 4, 5 and 6 respectively.

21. **Number of Substrings Containing All Three Characters**

    Given a string s consisting only of characters a, b and c, return the number of substrings containing at least one occurrence of all three characters.

    Input: `s = "abcabc"`

    Output: `10`

22. **Maximum Points You Can Obtain from Cards**

    In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

    Input: `cardPoints = [1,2,3,4,5,6,1]`, `k = 3`

    Output: `12`

    Explanation: The optimal strategy is to take the three cards on the right: `1 + 6 + 5 = 12`.

23. **Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit**

    Input: `nums = [8,2,4,7]`, `limit = 4`

    Output: `2`

24. **Maximum Number of Vowels in a Substring of Given Length**

    Input: `s = "abciiidef"`, `k = 3`

    Output: `3`

    Explanation: The substring "iii" contains 3 vowel letters.

25. **Find Two Non-Overlapping Subarrays Each With Target Sum**

    Input: `arr = [3,2,2,4,3]`, `target = 3`

    Output: `2`

    Explanation: Only two sub-arrays have sum = 3 (`[3]` and `[3]`). The sum of their lengths is 2.

26. **Longest Subarray of 1's After Deleting One Element**

    Input: `nums = [1,1,0,1]`

    Output: `3`

    Explanation: After deleting the number in position 2, `[1,1,1]` contains 3 numbers with value of 1's.

27. **Minimum Operations to Reduce X to Zero**

    Input: `nums = [1,1,4,2,3]`, `x = 5`

    Output: `2`

    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

28. **Get Equal Substrings Within Budget**

    Input: `s = "abcd"`, `t = "bcdf"`, `maxCost = 3`

    Output: `3`

    Explanation: "abc" of s can change to "bcd". That costs 3, so the maximum length is 3.

29. **Grumpy Bookstore Owner**

    Input: `customers = [1,0,1,2,1,1,7,5]`, `grumpy = [0,1,0,1,0,1,0,1]`, `minutes = 3`

    Output: `16`

    Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. Maximum satisfied customers = `1 + 1 + 1 + 1 + 7 + 5 = 16`.

30. **Max Consecutive Ones III**

    Given binary array nums and an integer k, return the maximum number of consecutive 1's if you can flip at most k 0's.

    Input: `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`

    Output: `6`

31. **Binary Subarrays With Sum**

    Given binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.

    Input: `nums = [1,0,1,0,1]`, `goal = 2`

    Output: `4`

32. **Maximum Length of Repeated Subarray**

    Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

    Input: `nums1 = [1,2,3,2,1]`, `nums2 = [3,2,1,4,7]`

    Output: `3`

    Explanation: The repeated subarray with maximum length is `[3,2,1]`.

33. **Longest Turbulent Subarray**

    Input: `arr = [9,4,2,10,7,8,8,1,9]`

    Output: `5`

    Explanation: `arr[1] > arr[2] < arr[3] > arr[4] < arr[5]`

34. **Longest Substring Of All Vowels in Order**

    Input: `word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"`

    Output: `13`

    Explanation: The longest beautiful substring is "aaaaeiiiiouuu" of length 13.

35. **Fruit Into Baskets**

    You only have two baskets, each holding a single type of fruit. Return the maximum number of fruits you can pick moving only to the right.

    Input: `fruits = [1,2,1]`

    Output: `3`

    Explanation: We can pick from all 3 trees.

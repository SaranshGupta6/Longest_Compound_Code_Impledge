# Longest_Compound_Code_Impledge

Solution of a question Longest Compounded Word

Explanation of the above Code
The concept of data structure which is used to solve this problem is Dynamic Programming.
For finding the longest compounded word, we will first sort the strings given on the basis of their lengths and if the length is equal then the strings are sorted in an alphabatical manner.
We will start from the end of the list of strings and will find that the current string can be formed from the smaller words or not.
If the answer is YES then store the string in ans1 and repeat the same thing to find the second longest compounded word.
As we get the second string we will store it in ans2.
When we get both the strings, we will stop and print both the strings.
n: no. of strings k: maximum length of the string

Time complexity:

Best case-> O(k^2) Average Case-> O(nk) Worst Case-> O(nk^2)

Space complexity: O(k)

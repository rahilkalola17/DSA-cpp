### String Maker
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.<br>
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
### Input Format :
Line 1 : String A<br>
Line 2 : String B<br>
Line 3 : String C
### Output Format :
The number of ways to form string C
### Constraints :
1 <= |A|, |B|, |C| <= 50
### Sample Input :
abc<br>
abc <br>
abc
### Sample Output :
8
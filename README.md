# Push_Swap :bar_chart:  
A number sorting algorithm using 2 stacks in C

## Method :twisted_rightwards_arrows:  
2 sorting methods- one for 3 number sorting and one for anything over 3.  
For big sort (briefly):  
Index all values for easier sorting  
All but 3 numbers pushed to stack B  
Sort stack A with 3 sort  
Find target positions in stack A for numbers in stack B  
Do a move cost analysis  
Carry out the cheapest moves to push all numbers back to stack A  
Do a last reshuffle on stack A  
Done!  

## Results :heavy_check_mark:
For 100 numbers : 5 points  
For 500 numbers : 5 points  
  
Succeeded with 100%    
  
Tester Used: https://github.com/Yoo0lh/push-swap-tester-42



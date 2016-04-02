/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>



int * find_sequences(int *a, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (a == NULL)
		return NULL;
	int j = 0;
	int x = 0;
	int *rs = (int*)malloc(6*sizeof(int));
		if (a[1] - a[0] == a[2] - a[1])
		{
			int d = a[1] - a[0];
			int i = 2;
			while (1)
			{
				if (a[i + 1] - a[i] != d)
				{
					rs[0] = 0;
					rs[1] = i;
					break;
				}
				i++;
			}

			i = i + 1;
			int g = i;
			int r = a[i+1] / a[i];
			if (a[i+2] / a[i+1] == r)
			{
				i = i + 2;
				while (1)
				{
					if (a[i + 1] / a[i] != r)
					{
						rs[4] = g;
						rs[5] = i;
						break;
					}
					i++;
				}
				rs[2] = i + 1;
				rs[3] = len-1;
				return rs;
 			}
			else
			{
				int d = a[i+1] - a[i];
				i = i+2;
				while (1)
				{
					if (a[i + 1] - a[i] != d)
					{
						rs[2] = g;
						rs[3] = i;
						break;
					}
					i++;
				}
				rs[4] = i ;
				rs[5] = len-1;
				return rs;
			}
		}
		else
		{
			int r = a[1] / a[0];
			int i = 0;
			if (a[i + 2] / a[i + 1] == r)
			{
				i = i + 2;
				while (1)
				{
					if (a[i + 1] / a[i] != r)
					{
						rs[4] = 0;
						rs[5] = i;
						break;
					}
					i++;
				}
				int g = i;
				int d = a[i + 1] - a[i];
				i = i + 2;
				while (1)
				{
					if (a[i + 1] - a[i] != d)
					{
						rs[2] = g;
						rs[3] = i;
						break;
					}
					i++;
				}
				rs[5] = len - 1;
				if (a[i + 1] - a[i] == a[i + 2] - a[i + 1])
					rs[4] = i;
				rs[4] = i + 1;
				return rs;
			}
		}
}
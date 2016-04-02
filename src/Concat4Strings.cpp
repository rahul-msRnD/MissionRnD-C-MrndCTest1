/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	int x = s1[0];
	int y = s2[0];
	int z = s3[0];
	int l = s4[0];
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int l3 = strlen(s3);
	int l4 = strlen(s4);
	char* rs = (char*)malloc(l1 + l2 + l3 + l4 + 1);
	if (x > y && y > z && z > l)
	{
		strcat(rs, s1);
		strcat(rs, s2);
		strcat(rs, s3);
		strcat(rs, s4);
		return rs;
	}
	return NULL;
}
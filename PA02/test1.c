#include<stdio.h>


int main() 
{
 char* first = "thegreat";
 char* second = "kumar";
 
 my_strinsert(first, second, 2);
 

 return 0; 
}






void my_strinsert(char *s1, const char *s2, int pos)
{
    int ind1 = 0;
    int ind2 = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    while(s2[ind2] !='\0')
    {
        if(pos >= len1)
        {
            my_strcat(s1,s2);
        }
	else
	{
            for(ind1=0;ind1<len1-pos;ind1++)
            {
            	s1[len1-1+len2-ind1] = s1[len1-1-ind1];
            
            }
       	    for(ind2=0;ind2<len2;ind2++)
            {
	       s1[pos+ind2] = s2[ind2];
	    
            }
	} 
        return;
    }
}

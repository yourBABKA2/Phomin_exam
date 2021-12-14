#include <stdio.h>
#include <string.h> // strlen() 

int main()
{
    char string[30];	
    fgets(string, 30, stdin);	

    char *number = strchr(string, '\n');	
    if(number != NULL)
    { 
        *number = '\0';	
    }

    char d[100];	
    int di = 0;	

    char o = string[0];	
    int r = 0;	

    int l = strlen(string);	
    for(int i = 1; i <= l; i++)	
    {
	    char c = string[i];	
	    if(o == c)	
	    {
		    r++;	
	    }
	    else
	    {
		    d[di] = o;	
		    di++;	
		    if(r > 0)	
		    {
			    int w = sprintf(d + di, "%d", r + 1);	
			    di += w;	
		    }
		    r = 0;	
	    }
	    o = c;
    }
    d[di] = '\0';
    puts(d);

    return 0;	
}

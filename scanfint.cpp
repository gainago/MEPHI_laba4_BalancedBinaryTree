#include <iostream>
int scanfint(int *integer)
{ int flag=-1;
    int correct=1;
int minusflag=0;
    char c;
   *integer=0;
    while(c=getchar())
     { if(c==' '||c==EOF||c=='\n')
        {
            
            if(flag==1){
                if(minusflag%2!=0)
                    *integer=*integer*(-1);
                return correct;
            }
            minusflag=0;
        }
        else{
            if(c=='-'){
                minusflag++;
                if(minusflag==2)
                    correct=-1;
        
            }
            if((int)c>='0'&&(int)c<='9')
            {   
                flag=1;
                (*integer)*=10;
                (*integer)+=(int)c-48;
            }
            else{
                if(c!='-')
                    correct=-1;

            }
            if(*integer>2000000)
                correct=-1;
        }


    } 
    return -1;
}
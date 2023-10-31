#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,car,end,temp;
    int s[24]={0};
    int d[24]={0};

while(scanf("%d%d",&s[n],&d[n])!=EOF){
        n+=1;
    }

    int ssch[256][512]={0};
    int dsch[256][512]={0};

    for (int i=0;i<n;i++)
    {

        for(int j=i;j<n;j++){
            if(s[i]>s[j]){
                temp=s[j];
                s[j]=s[i];
                s[i]=s[j];
                temp=d[j];
                d[j]=d[i];
                d[i]=temp;
            }
        }
    }
    end=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(s[k]>=end && s[k]!=0){
                    end=d[k];
                    ssch[i][j]=s[k];
                    dsch[i][j]=d[k];
                    s[k]=0;
                    d[k]=0;
                    j++;
                }
            }
        }
        end=0;
    }

    for(int c=0;c<=n;c++){
        if (ssch[c][0]==0){
            car=c;
            printf("%d\n",car);
            break;
        }
    }

    for(int d=0;d<car;d++){
        printf("Driver %d's schedule is" ,d+1 );
        for(int f=0;f<n*2;f++){
            if(ssch[d][f]!=0){
                printf("%d %d",ssch[d][f],dsch[d][f]);
                if (f < n * 2 - 1 && ssch[d][f + 1] != 0)
                printf(" ");
            }
            else{
                printf("\n");
                break;
            }
        }
    }
}

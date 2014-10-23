#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char a[1200],num[10];
    scanf("%d",&t);
    while(t--)
    {
        int m;
        scanf("%s%d",a,&m);
        int n=strlen(a);
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            num[a[i]-'0']++;
        }
        int j=0;
        while(j<n&&m>0)
        {
            if(j==0)
            {
                for(int k=1;k<10;k++)
                {
                    if(num[k]!=0)
                    {
                        if(k<a[j]-'0')
                        {
                            for(int l=n-1;l>j;l--)
                            {
                                if(a[l]-'0'==k)
                                {
                                    char c=a[j];
                                    a[j]=a[l];
                                    a[l]=c;
                                    num[k]--;
                                    m--;
                                    break;
                                }
                            }
                        }
                        else num[a[j]-'0']--;
                        j++;
                        break;
                    }
                }
            }
            else
            {
                for(int k=0;k<10;k++)
                {
                    if(num[k]!=0)
                    {
                        if(k<a[j]-'0')
                        {
                            for(int l=n-1;l>j;l--)
                            {
                                if(a[l]-'0'==k)
                                {
                                    char c=a[j];
                                    a[j]=a[l];
                                    a[l]=c;
                                    num[k]--;
                                    m--;
                                    break;
                                }
                            }
                        }
                        else num[a[j]-'0']--;
                        j++;
                        break;
                    }
                }
            }
        }
        printf("%s\n",a);
    }
}

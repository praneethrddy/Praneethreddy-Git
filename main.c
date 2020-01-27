#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct A
{
    int x;
    int y;
    double dist;
};
int comp(const void* p, const void* q)
{
    int s=((struct A*)p)->x;
    int j=((struct A*)p)->y;
    double l=sqrt((s*s)+(j*j));
    s=((struct A*)q)->x;
    j=((struct A*)q)->y;
    double m=sqrt((s*s)+(j*j));
    if(l<m)
    {
        return(0);
    }
    else
    return(1);
}
int route(int x,int y,int a,int b)
{
    while(a!=x)
    {
        a=a+1;
        printf("R");
    }
    while(y!=b)
    {
        b=b+1;
        printf("U");
    }
}
int main()
{
    long t;
    scanf("%ld",&t);
    while(t--)
    {
        long n;
        scanf("%ld",&n);
        struct A k[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&k[i].x,&k[i].y);
            k[i].dist=sqrt((k[i].x*k[i].x)+(k[i].y*k[i].y));
        }
        qsort(k, n, sizeof(struct A), comp); 
        int e=0;
        // for(int i=0;i<n;i++)
        // {
        //     printf("%d %d\n",k[i].x,k[i].y);
        // }
        for(int i=1;i<n;i++)
        {
            if(k[i-1].x<=k[i].x && k[i-1].y<=k[i].y)
            {
                e=0;
            }
            else
            {
                e=100;
                break;
            }
        }
       // printf("\n%d",e);
        if(e==100)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            int a=0,b=0;
            for(int i=0;i<n;i++)
            {
            route(k[i].x,k[i].y,a,b);
            a=k[i].x;
            b=k[i].y;
            }
            printf("\n");
        }
        //route(k[0].x,k[0].y,a,b);
    }
}
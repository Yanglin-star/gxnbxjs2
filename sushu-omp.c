#include<stdio.h>
int isprime(int k)
{
    int i;
    for(i=2;i*i<=k;i++)
    {
	if(k%i==0)
	    return 0;
    }
    return 1;
}

int main()
{
    omp_set_num_threads(8);
    FILE *fp = fopen("out-omp.txt", "w");
    long i, n=1000000, sum=0;
    //scanf("%ld", &n);
    #pragma omp parallel for private(i) reduction(+:sum)
    for(i=2;i<=n;i++)
    {
	if(isprime(i))
        {
	    sum+=i;
            fprintf(fp,"%ld\n",i);     
	}
    }
    fclose(fp);
    printf("%ld", sum);
    return 0;
}

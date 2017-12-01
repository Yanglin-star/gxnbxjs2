#include <stdio.h>
#include <time.h>
#include <omp.h>
//reduction
int main()
{
    omp_set_num_threads(8);
    clock_t start,end;  
    start = clock();  
    int i, n;
    float a[100], b[100], result;
    // initializations
    n = 100;
    result = 0.0;
    for (i = 0; i < n; i++)
    {
        a[i] = i * 1.0;
        b[i] = i * 2.0;
        
    }
    #pragma omp parallel for private(i) reduction(+:result)
    for (i = 0; i < n; i++)
    {
        
        result = result + (a[i] * b[i]);
    }
    end = clock();  
    printf("time=%fs\n",(double)(end-start)/CLOCKS_PER_SEC); 
    printf("a*b= %12.6lf\n", result);
    
    return 0;
}

/* Amina Colovic
* Kattis Problem: Quality-Adjusted Life-Year
* Problem ID: qaly
* CPU Time limit: 1 sec
* Memory limit: 1024 MB
* Difficulty: 1.3
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d",&n);

    float qaly = 0.0;
    
    for (int i = 0; i < n; i++)
    {
        float q, y;
        scanf("%f %f", &q, &y);
        qaly += q *y;
    }
    printf("%.3f\n",qaly);
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int t, x1, y1, r1, x2, y2, r2, result;
    double distance;
    scanf("%d", &t);

    while(t--){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        distance = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

        if(x1==x2 && y1==y2 && r1==r2){
            result = -1;
        }
        else if(distance < (r1+r2) && abs(r1-r2) < distance ){
            result = 2;
        }
        else if((r1+r2) == distance || distance == abs(r1-r2) ){
            result = 1;
        }
        else{
            result = 0;
        }
        printf("%d\n", result)
    }
    return 0;
}

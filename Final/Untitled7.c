#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sign(int x){
    if (x > 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return -1;
    }
    return 0;  
}

int main(){
    int i, j;
    int x0,x1,y0,y1;
    int array_x;
    int array_y;
    char canvas[100][100];
    printf("Integer x0: ");
    scanf("%d",&x0);
    printf("Integer x1: ");
    scanf("%d",&x1);
    printf("Integer y0: ");
    scanf("%d",&y0);
    printf("Integer y1: ");
    scanf("%d",&y1);
        
    if (x0 > x1)
    {
        array_x = x0;
    }
    if (x1 >= x0)
    {
        array_x = x1;
    }
    if (y0 > y1)
    {
        array_y = y0;
    }
    if (y1 >= y0)
    {
        array_y = y1;
    }

    for (i = 0; i < array_x; i++)
    {
        for (j = 0; j < array_y; j++)
        {
            canvas[i][j] = ' ';
        }    
    }
    
    int dx = fabs(x1 - x0);
    int dy = fabs(y1 - y0);
    int error = 0;
    int y = y0;
    int x = x0;

    if (dx >= dy){   
        if (x1 >= x0){    
            for (i = x0; i < x1; i++){
                canvas[y][i] = '#';
                error += 2*dy;

                if (error >= 0 && dx!=0){
                    y = y + sign(y1-y0);
                    error -= 2 * dx;
                }
            }
        }

        else{
            for (i = x1; i < x0; i++){
                canvas[y][i] = '#';
                error += 2*dy;

                if (error >= 0 && dx!=0){
                    y = y + sign(y1-y0);
                    error -= 2 * dx;
                }
            }
        }
    }
    
    else{
        if (y1 >= y0){    
            for (i = y0; i < y1; i++){
                canvas[i][x] = '#';
                error += 2*dx;
                if (error >= 0 && dy!=0){
                    x = x + sign(x1-x0);
                    error -= 2 * dy;
                }
            }

        }

        else{
            for (i = y1; i < y0; i++){
                canvas[i][x] = '#';
                error += 2*dx;

                if (error >= 0 && dy!=0){
                    x = x + sign(x1-x0);
                    error -= 2 * dy;
                }
            }
        }
    }

    for (i = 0; i < array_y; i++)
    {
        for (j = 0; j < array_x; j++)
        {
            printf("%c\t",canvas[i][j]);
        }
        printf("\n");
    }
}

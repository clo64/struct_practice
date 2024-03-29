#include <stdio.h>

typedef enum {FALSE, TRUE} bool;

struct point {
        
        int x, y;
        
    };
    
struct rectangle {
        
        struct point upper_left, lower_right;
        
    };

int absolute_value(int a);
int area(struct rectangle a);
struct point mid_point(struct rectangle a);
struct rectangle move_rec(struct rectangle a, int x, int y);
bool within_bounds(struct rectangle a, struct point p);


int main()
{
   
     struct rectangle a;
     struct point b;
     struct point p;
     a.upper_left.x = 0;
     a.upper_left.y = 4;
     a.lower_right.x = 4;
     a.lower_right.y = 0;
     
     int tempArea = 0;
     
     tempArea = area(a);
     
     printf("The area of your rectangle is: %d\n", tempArea);
    
     b = mid_point(a);
     
     printf("The midpoint of your rectangle is x: %d, Y: %d\n", b.x, b.y);
     
     //Move rectangle right 3 units
     //Print both sets of coordinates
     
     a = move_rec(a, 3, 0);
     
     printf("Rectangle has been moved\n");
     printf("Upper left x: %d, y: %d\n", a.upper_left.x, a.upper_left.y);
     printf("Lower right x: %d, y: %d\n", a.lower_right.x, a.lower_right.y);
     
     //Is the point (2, 3) within bounds?
     p.x = 2;
     p.y = 3;
     a.upper_left.x = 0;
     a.upper_left.y = 4;
     a.lower_right.x = 4;
     a.lower_right.y = 0;
     
     if(within_bounds(a, p) == TRUE)
     {
         printf("Point is within bounds\n");
     }
     else
     {
         printf("Point is not within bounds\n");
     }
    
    return 0;
}

int area(struct rectangle a){
    
    int xLen, yLen;
    xLen = absolute_value(a.upper_left.x - a.lower_right.x);
    yLen = absolute_value(a.upper_left.y - a.lower_right.y);
    return xLen*yLen;
}

int absolute_value(int a){
    
    if(a<0)
    {
        return (a*-1);  
    }
    else return a;
    
}

struct point mid_point(struct rectangle a){
    
    struct point tempPoint;
    tempPoint.x = ((a.upper_left.x + a.lower_right.x)/2);
    tempPoint.y = ((a.upper_left.y + a.lower_right.y)/2);
    return tempPoint;
    
}

struct rectangle move_rec(struct rectangle a, int x, int y){
    
    struct rectangle tempRec;
    tempRec.upper_left.x = a.upper_left.x + x;
    tempRec.lower_right.x = a.lower_right.x + x;
    tempRec.upper_left.y = a.upper_left.y + y;
    tempRec.lower_right.y = a.lower_right.y +y;
    return tempRec;
    
}

bool within_bounds(struct rectangle a, struct point p){
    
    if(p.x > a.upper_left.x && p.x < a.lower_right.x && p.y > a.lower_right.y && p.y < a.upper_left.y)
    return TRUE;
    else return FALSE;
    
}

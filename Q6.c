#include <stdio.h>
#include <math.h>

struct Point3D{
    double x;
    double y;
    double z;
};

double calculateDistance(struct Point3D point1, struct Point3D point2){
    return sqrt(pow(point1.x - point2.x,2) + pow(point1.y - point2.y,2) + pow(point1.z - point2.z,2));
}

int main(){
    struct Point3D point1, point2;
    printf("Enter Coordinated for point 1: ");
    scanf("%lf %lf %lf",&point1.x,&point1.y,&point1.z);

    printf("Enter Coordinated for point 2: ");
    scanf("%lf %lf %lf",&point2.x,&point2.y,&point2.z);

    double distance = calculateDistance(point1,point2);
    printf("Distance btw the 2 points : %lf\n",distance);
    return 0;
}
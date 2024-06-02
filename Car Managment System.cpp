
//This Program Is Created By PatelDharam23CE092.
//Purpose :- Develop a system to calculate the area of a shape
//concept :- Function Over loading.
#include<iostream>
using namespace std;
struct area_calculation{
public :
//Find the area of Circle.
//area function with (1 parameter);
float area(float radius){
    return 3.14*radius*radius;
}
//find The area Of Rectangle.
//area function with (2 parameter);
int area(int height_of_r,int weight_of_r){
    return height_of_r*weight_of_r;
}
//Find The area of Cuboid.
//area function with (3 parameter);
int area (int height_of_c,int weight_of_c,int depth_of_c){
    return 2*((height_of_c*weight_of_c)+(weight_of_c*depth_of_c)+(depth_of_c*height_of_c));
}
}ac;
int main()
{
    float radius;
    int height_of_r,weight_of_r;
    int height_of_c,weight_of_c,depth_of_c;
    cout<<"Enter The Radius Of A Circle : ";
    cin>>radius;
    cout<<endl<<"The Area Of A Circle Is : "<<ac.area(radius)<<endl;
    cout<<"Enter The height Of a Rectangle : ";
    cin>>height_of_r;
    cout<<endl<<"Enter The Width Of a Rectangle : ";
    cin>>weight_of_r;
    cout<<"The area of Rectangle is : "<<ac.area(height_of_r,weight_of_r);
    cout<<endl<<"Enter The Height Of Cuboid : ";
    cin>>height_of_c;
    cout<<endl<<"Enter The Width Of Cuboid : ";
    cin>>weight_of_c;
    cout<<endl<<"Enter The Depth Of Cuboid : ";
    cin>>depth_of_c;
    cout<<"The Area Of Cuboid Is : "<<ac.area(height_of_c,weight_of_c,depth_of_c);
    return 0;
}

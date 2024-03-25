#include <iostream>
#include <cmath>
using namespace std;

class point{
  int a, b;
public:
  point() { a = 0; b = 0; }
  void setpoint(int a, int b) { this->a = a; this->b = b; }
  int operator-(point &mid){
    int aa = pow(this->a - mid.a, 2);
    int bb = pow(this->b - mid.b, 2);
    return sqrt(aa + bb);
  }
  int geta(){
    return a;
  }
  int getb(){
    return b;
  }
};

class circle{
  point mid;
  int radius;
public:
  circle() {}
  void setradius(int r) { this->radius = r;}
  void setmid(point m) { this->mid = m; }
  point getmid() { return mid; }
  int getradius() { return radius; }
};

class shape{
  circle* ptr;
  int count;
  point Point[2];
public:
  shape() {
    int a1, b1, c1, d1;
    cin >> a1 >> b1 >> c1 >> d1;
    Point[0].setpoint(a1, b1);
    Point[1].setpoint(c1, d1);
    int radius, b, c;
    cin >> count;
    ptr = new circle [count];
    for(int i=0; i<count; i++){
      point pnt;
      cin >> b >> c >> radius;
      pnt.setpoint(b,c);
      ptr[i].setradius(radius);
      ptr[i].setmid(pnt);
    }
  }
  void show() {
    cout << "("<<Point[0].geta() << ", " <<Point[0].getb() << ")";
    cout << count;
    for(int i =0; i<count; i++){
      cout << ptr[i].getradius();
    }
  }
  int find(){
    int sum = 0;
    for(int i = 0; i < count; i++){
      point a;
      a = ptr[i].getmid();
      double p_to_mid1 = Point[0]-a;
      double p_to_mid2 = Point[1]-a;
      double k = Point[0] - Point[1];
      if(ptr[i].getradius() > p_to_mid1){
        sum++;
      }
      if(ptr[i].getradius() > p_to_mid2){
        sum++;
      }
      if((ptr[i].getradius() > p_to_mid1) && (ptr[i].getradius() > p_to_mid2)){
        sum = sum - 2;
      }
    }
    return sum;
  }
};

int main(){
  int count;
  cin >> count;
  shape Shape[count];
  for(int i=0; i<count; i++)
    cout << Shape[i].find() << endl;
}
#include<iostream>
using namespace std;
class Complex{
	private:
	int imag, real;
	public:
		Complex(){
			
		}
		Complex(int r){
			imag = r;
			real = r;
		}
		
		Complex(int i, int r){
			imag = r;
			real = i;
		}
		
		Complex add(Complex a, Complex b){
			Complex c;
			c.imag = a.imag + b.imag;
			c.real = a.real + b.real;
			return c;
		}
		void display(){
			cout<<real<< "+"<<imag<<"i"<<endl;
		}
};
int main(){
	Complex a(2,3), d;
	Complex b(3,4), c;
	c = d.add(a,b);
	c.display();
    return 0;
}
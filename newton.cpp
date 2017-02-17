#include <iostream>

double funct(double x);
double derive_at_x(double x);
double find_zero(double user_in, int depth);

int main(){
	double user_in = 0;
	int depth = 0;
	std::cout << "Enter a number\n";//starting value x in f(x)
	std::cin >> user_in;
	std::cout << "Enter depth\n";//user specified depth of recursion
	std::cin >> depth;
	//find zero
	std::cout << find_zero(user_in,depth) << "\n";
}

double funct(double x){
	std::cout << "funct(" << x << ") ";
	x = x*x - 5;//test function
	std::cout << "= " << x << "\n";
	return x;
}

double derive_at_x(double x){
	double deriv_x = (funct(x+0.01)-funct(x))/0.01;
	std::cout << "deriv(" << x << ") = " << deriv_x;
	return deriv_x;
}

double find_zero(double user_in, int depth){
	double x = user_in;
	double deriv_x = derive_at_x(x);
	if(deriv_x != 0){
		x = x - funct(x)/deriv_x;
	}else{
		std::cout << "error: derivative equals zero.\n";
	}
	if(depth == 1){
		return x;
	}else{
		return find_zero(x,depth-1);
	}	
}

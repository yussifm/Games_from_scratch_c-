#include <iostream>


template<class T>
T app_max (T a, T b){
	return (a>b?a:b);
}
int main(int argc, char const *argv[])
{
	auto r1 = app_max(5, 6);
     std::cout<< r1<< std::endl;
	return 0;
}
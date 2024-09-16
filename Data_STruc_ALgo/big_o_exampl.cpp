
#include <iostream>


// Big O is a way of comparing two codes 
// mathematical on how long they run

 // 0(n)
void printItemsON(int n){
	for (int i = 0; i < n; ++i)
	{
		std::cout << i << std::endl;
	}
}

 // 0(n^2)
void printItemsONTwo(int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				std::cout << i <<" " <<j << " " << k<<std::endl;
			}
			
		}
		
	}
}

// 0(1) -> O of One
int addItems(int n){
	return n+n+n;
}

// 0(logN) -> O of logN



int main(){

   //printItemsON(10);
   printItemsONTwo(10);
	return 0;

}
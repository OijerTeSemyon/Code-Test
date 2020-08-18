#include <iostream>;
using namespace std;

void sort(int a[10]){
	int temp;
	for (int i=0;i<10;i++){
		for (int j=0;j<10-i-1;j++)
	 	{
	 		if (a[j]>a[j+1]){
	 			temp = a[j];a[j]=a[j+1];a[j+1]=temp;
			 }
		 }
	}
}

void outa(int a[10]){
for (int i=0;i<10;i++){
    	cout << a[i]<<" ";
	}
}
int main()
{	
	int i,j,a[10];
    for (i=0;i<10;i++){
    	cin >> a[i];
	} 
	sort(a);
    outa(a);
	}
	





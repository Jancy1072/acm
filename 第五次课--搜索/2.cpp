#include <fstream>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool isPrime[10000]={0};
int prime[10000];
int num=0;
void init(){
	memset( isPrime, 0, sizeof(isPrime) );
	int i, j;
	double d=sqrt(10000*1.0);
	for( i=2; i<=d; i++)
		for( j=2; j*i<10000; j++)  
			isPrime[i*j]=1;
	for( i=2; i<10000; i++ )
		if(!isPrime[i]){
			prime[num] = i;
			num++;
		}
};

int main()
{
	int n, i, j;	
	int m, a, b, p, q;	
	init();
	while ( cin >> m >> a >> b && m!=0 ){
		float aspect = a*1.0/b;
		int product, final = 0;
		for( i=num-1; i>=0; i-- ){
			for( j=num-1; j>=i; j--){
				product = prime[i]*prime[j];
				if( product<=m && prime[i]*1.0/prime[j]>=aspect ){
					if( product>final ){
						final = product;
						p = prime[i];
						q = prime[j];
					}
					break;
				}
			}
		}
		cout << p << " " << q << endl;
	}
    return 0;
}

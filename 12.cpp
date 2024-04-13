#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int dectotri(int dec) {
    	vector<int> tri;
    	long long int a = 0;
    	if (dec == 0) {
        	tri.push_back(0);
    	}
    	while (dec > 0) {
        	int remainder = dec % 3;
        	tri.insert(tri.begin(), remainder);
	        dec /= 3;
	}
	for(int i = 0; i<tri.size(); i++) 
		a+=tri[i]*pow(10, tri.size()-i-1);
	return a;
}

vector<int> pov(int a) {
        int b = a, k = 0, kc = 0;
        vector <int> ch;
        while(b>0) {
                ch.push_back(b%10);
                if(b%10==1)
                        k++;
                b=b/10;
                kc++;
        }
        for(int i = 0; i<kc; i++)
                a+=pow(10, i);
        int p = pow(10, kc-k);
        int j = a%p;
        int i = a/p;
        int res = j*pow(10, k)+i;
        for(int i = kc-1; i>=0; i--) {
                ch[i]=res%10-1;
                res=res/10;
        }
        return ch;
}

int main() {
    	int n;
	vector<int> a;
	cin >> n;
	int kod[n];
	for(int i = 0; i<n; i++) 
		cin >> kod[i];
	int kodtri[n];
	for(int i = 0; i<n; i++) 
		kodtri[i] = dectotri(kod[i]);
	for(int i = 0; i<n; i++) {
		a=pov(kodtri[i]);
		for(int j = 0; j<a.size(); j++)
			cout << a[j];
		cout << endl;
	}
	return 0;
}

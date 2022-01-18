#include <iostream>
#include <cmath>
#define EDX 1701720

using namespace std;

long long HamXuly_0040109B(long long EBX, long long len_EAX) {
	return (984 + EBX) * 2 * (EDX + 3 + 2 * len_EAX) - 1;
}

int main()
{
	long long _mu32 = pow(2, 32);
	long long sub;

	for (long long n = 1; n < 9; n++)
	{
		for (long long EBX = 0; EBX <= 9999; EBX++)
		{
			// code tối ưu --- 
			// với k_max == k_min thì k tồn tại số 10^(n-1) <= EAX < 10^(n)  == HamXuly_0040109B
			int k_max = (HamXuly_0040109B(EBX, n) - pow(10, n) - 1) / _mu32;
			int k_min = (HamXuly_0040109B(EBX, n) - pow(10, n - 1)) / _mu32;
			if (k_max == k_min) { continue; }

			for (long long EAX = pow(10, n - 1); EAX < pow(10, n); EAX++)
			{
				sub = HamXuly_0040109B(EBX, n) - EAX;
				sub %= _mu32;

				if (sub == 0) {
					cout << "ID = " << EBX << " --- Serial = " << EAX << endl;
				}
			}
		}
	}
}


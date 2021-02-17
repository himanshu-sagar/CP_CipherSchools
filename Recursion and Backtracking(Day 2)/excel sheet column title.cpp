#include <bits/stdc++.h>
#define MAX 60
using namespace std;
void columnTitle(int n)
{
	char str[MAX];
	int i = 0;

	while (n > 0) {

		int out = n % 26;
		if (out == 0) {
			str[i++] = 'Z';
			n = (n / 26) - 1;
		}
		else
		{
			str[i++] = (out - 1) + 'A';
			n = n / 26;
		}
	}
	str[i] = '\0';
	reverse(str, str + strlen(str));
	cout << str << endl;

	return;
}
int main()
{
	columnTitle(28);

}

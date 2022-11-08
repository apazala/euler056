
#include <stdio.h>

#define ONEMILL 1000000

int main()
{
	int sixdig[1000];
	int nsix = 0;

	int i;
    const int n = 100;
	int answer = 1;
	for (int a = 2; a < n; a++) {
		sixdig[0] = 1;
		nsix = 1;
		for (int b = 1; b < n; b++) {
			//Multiplication
			int rem = 0, v;
			for (int i = 0; i < nsix; i++) {
				v = sixdig[i] * a + rem;
				if (v >= ONEMILL) {
					sixdig[i] = v % ONEMILL;
					rem = v / ONEMILL;
				}
				else {
					sixdig[i] = v;
					rem = 0;
				}
			}
			while(rem >= ONEMILL) {
				sixdig[nsix++] = rem % ONEMILL;
				rem /= ONEMILL;
			}
			
			sixdig[nsix++] = rem;
			
			//sum sigits
			int sum = 0;
			for (int i = 0; i < nsix; i++) {
				v = sixdig[i];
				while (v > 9) {
					sum += v % 10;
					v /= 10;
				}
				sum += v;
			}

			if (sum > answer)
				answer = sum;
			
		}
	}

	printf("%d\n", answer);

    return 0;
}

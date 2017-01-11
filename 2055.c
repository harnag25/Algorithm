#include <stdio.h>
#include <stdlib.h>

int ascending (const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return 1;
	else if (*(int *)a < *(int *)b)
		return -1;
	else
		return 0;
}

void main() {
	int array[5000] = {};
	int a, b, i;
	int count = 3;

	scanf("%d %d", &a, &b);

	array[0] = 1;
	array[1] = a;
	array[2] = b;
	for(i=2; i*i<=b; i++) {
		if(a%i==0 && a/2 > i) {
			array[count++] = i;
			array[count++] = a/i;
		}
		if(b%i==0) {
			array[count++] = i;
			array[count++] = b/i;
		}
	}
	qsort(array, count, sizeof(int), ascending);
	for (i=0; i<count; i++)
		if(array[i] != array[i+1]) printf("%d ", array[i]);
}

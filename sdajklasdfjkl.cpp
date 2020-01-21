#include <stdio.h>
#include <stdlib.h>

int main() {
	int *a;
	a = (int*)malloc(40);
	*a = 123;
	a[1]=3;
	printf("%d",a[1]);
	free(a);
	
} 


#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *ifp = fopen("sample.csv", "r");
	if (ifp != NULL) {
		int studentId;
		int grade;

		while (fscanf(ifp, "%d,%d", &studentId, &grade) == 2) {
			printf("%d,%d\n", studentId, grade);
		}
		fclose(ifp);
	}
}
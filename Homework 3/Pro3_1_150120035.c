//Omer Deligoz 150120035
#include <stdio.h>
int sum (int n);
int lineNumber;
int totalEars;

int main() {

    printf("Please enter the number of lines (n=): ");
    scanf("%d", &lineNumber);

    sum(lineNumber);
    return 0;
}
//This method finds the number of ears recursively
int sum(int n) {
    //Base Case
    if (n == 0) {
        printf("bunnyEars%d(%d) -> %d\n", lineNumber, n , n);
        return 0;
    }
    //Recursive step
    else if (n % 2 != 0) {
        totalEars = sum(n - 1) + 2;
        printf("bunnyEars%d(%d) -> %d\n", lineNumber, n, totalEars);
        return totalEars;
    }
    //Recursive step
    else if (n % 2 == 0) {
        totalEars = sum(n - 1) + 3;
        printf("bunnyEars%d(%d) -> %d\n", lineNumber, n, totalEars);
        return totalEars;
    }
}

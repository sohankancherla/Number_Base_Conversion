#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Let the program know functions exists
char* base_converter(int base_1, char* number, int base_2);
int to_decimal(int base, char* number);

// Get the system arguments
int main(int argc, char* argv[]) {

    // Check for the proper number of arguments
    if (argc != 4) {
        printf("Usage: %s <current_base> <number> <desired_base>\n", argv[0]);
        return 1;
    }

    // Assign the system arguments into variables
    int current_base = atoi(argv[1]);
    char* number = argv[2];
    int desired_base = atoi(argv[3]);

    // Call the Base Converter Function
    char* result = base_converter(current_base, number, desired_base);
}

// Base Converter Function that returns the number of the desired base
char* base_converter(int base_1, char* number, int base_2) {

    // First convert the number to base 10
    int base_10  = to_decimal(base_1, number);
    printf("%i", base_10);

}

// Convert the number to Decimal or Base 10 first
int to_decimal(int base, char* number) {

    // Get the length of the number and initialize a total counter variable to store the sum of each digit
    int len = strlen(number);
    int total = 0;

    // Loop through the number backwards and add each digit's value to total
    for (int i = len - 1; i >= 0; i--) {

        // The ith digit of number 
        char digit = number[i];
        
        // If digit is between 0 and 9, multiply the digit by the base^the digit place and add the value to total
        if (digit >= '0' && digit <= '9') {
            total =  total + (pow(base, (len-1-i)) *  (digit - '0'));
        }
        // Apply the same logic for digits between A and F
        else if (digit >= 'A' && digit <= 'F') {
            total = total + (pow(base, (len-1-i)) * (digit - 'A' + 10));
        }
        // Check for lowercase characters
        else if (digit >= 'a' && digit <= 'f') {
            total = total + (pow(base, (len-1-i)) * (digit - 'a' + 10));
        }
        // Invalid Characters
        else {
            return -1;
        }

    }
    
    return total;
} 


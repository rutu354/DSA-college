#include <stdio.h> 
 
int pallindrome(char input[]); 
void copy(char input[], char output[]); 
int stringlength(char input[]); 
void substring(char input[]); 
void reverse(char input[]); 
 
int main() { 
    int ch; 
    char str[50]; 
    char output[50]; 
 
    printf("Enter a string: "); 
    scanf("%49s", str); 
    printf("Choose an Operation:\n1. Check Palindrome\n2. Copy String\n3. Check String 
Length\n4. Substring\n5. Reverse String\n"); 
    scanf("%d", &ch); 
 
    switch(ch) { 
        case 1: { 
            int c = pallindrome(str); 
            if (c == 1) 
                printf("Palindrome\n"); 
            else 
                printf("Not a Palindrome\n"); 
            break; 
        } 
        case 2: 
            copy(str, output); 
            break; 
        case 3: 
            printf("String length is: %d\n", stringlength(str)); 
            break; 
        case 4: 
            substring(str); 
            break; 
        case 5: 
            reverse(str); 
            break; 
        default: 
            printf("Invalid choice\n"); 
    } 
    return 0; 
} 
 
int stringlength(char input[]) { 
    int i = 0; 
    while(input[i] != '\0') { 
        i++; 
    } 
    return i; 
} 
 
int pallindrome(char input[]) { 
    int i = 0, j = stringlength(input) - 1; 
     
    while(i < j) { 
        if(input[i] != input[j]) { 
            return 0; 
        } 
        i++; 
        j--; 
    } 
    return 1; 
} 
 
void copy(char input[], char output[]) { 
    int i; 
    for (i = 0; input[i] != '\0'; i++) { 
        output[i] = input[i]; 
    } 
    output[i] = '\0'; 
    printf("Output string is: %s\n", output); 
} 
 
void substring(char input[]) { 
    int i, position; 
    char output[50]; 
    int n = stringlength(input); 
 
    printf("Enter the position of substring: "); 
    scanf("%d", &position); 
 
    if(position >= 0 && position < n) { 
        for(i = 0; i < n - position; i++) { 
            output[i] = input[position + i]; 
        } 
        output[i] = '\0'; 
        printf("Input string: %s\nOutput substring: %s\n", input, output); 
    } else { 
        printf("Position entered is out of range\n"); 
    } 
}
void reverse(char input[]) { 
    int i; 
    int n = stringlength(input); 
    char output[50]; 
 
    for(i = 0; i < n; i++) { 
        output[n - 1 - i] = input[i]; 
    } 
    output[n] = '\0'; 
    printf("Input string: %s\nOutput (reversed) String: %s\n", input, output); 
} 

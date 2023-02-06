#include<stdio.h>
#include<string.h>
#include <math.h>
#include <stdlib.h>

void char_to_binary(unsigned char c, char binary_string[9]) {
    int i;
    for (i = 7; i >= 0; i--) {
        binary_string[7 - i] = ((c & (1 << i)) ? '1' : '0');
    }
    binary_string[8] = '\0';
}

int string_to_int(char str[]) {
    int i;
    int decimal = 0;
    int length = strlen(str);
    for (i = 0; str[i]; i++) {
        decimal += (str[i] - '0') * pow(10, length - i - 1);
    }
    return decimal;
}

void string_array_to_int_array(char str_array[100][9], int int_array[], int length) {
    int i;
    for (i = 0; i < length; i++) {
        int_array[i] = string_to_int(str_array[i]);
    }
}

int XOR(int a, int b) {
    return (a != b);
}

void add_binary_arrays(int *result, const int *a, const int *b, int size_a, int size_b) {
    int carry = 0;
    int i;
    for (i = 0; i < size_a || i < size_b; i++) {
        int a_val = (i < size_a) ? a[i] : 0;
        int b_val = (i < size_b) ? b[i] : 0;
        int sum = a_val + b_val + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
    if (carry > 0) {
        result[i] = carry;
    }
}

int binary_to_decimal(int binary[], int length) {
    int decimal = 0;
    int i;
    for (i = 0; i < length; i++) {
        decimal += binary[i] * pow(2, length - 1 - i);
    }
    return decimal;
}
void int_to_array(int *array, int number) {
    int temp = number;
    int count = 0;
    while (temp > 0) {
        count++;
        temp /= 10;
    }
    int i;
    for (i = 0; i < count; i++) {
        array[i] = number % 10;
        number /= 10;
    }
}

int main(){
    int arr[32];
    for(int i=0; i<32; i++){
        arr[i]=0;
    }
    char Word[100];
    scanf("%s", Word);
    int word_length = strlen(Word);

    char binary_representation[100][9];
    for (int i = 0; Word[i]; i++) {
        char_to_binary(Word[i], binary_representation[i]);
    }
    int int_array[word_length];
    string_array_to_int_array(binary_representation, int_array, word_length);
    int final_result[32];
    for(int i=0; i<32; i++){
        final_result[i]=0;
    } 
    int loop_count=0;
    
    for(int i=0; i<word_length;i++ ){
        int result[32];
        
        for(int i=0; i<32; i++){
            result[i]=0;
        }
        int n[8];
        int_to_array(n, int_array[i]);

        add_binary_arrays(result, arr, n, 32, 8);
        loop_count+=1;
        if(loop_count=5){
            for(int i=0; i<32; i++){
                final_result[i]=result[i];
            }
            int i,j,temp;
            for (i = 0, j = 32 - 1; i < j; i++, j--) {
                temp = final_result[i];
                final_result[i] = final_result[j];
                final_result[j] = temp;
            }      
        }


        for(int i=0;i<32;i++){
            arr[i]=result[i];
        }
        int new_array[36];
        int add_array[4];

        for(int i=0; i<36; i++){
            new_array[i]=0;
        }
        for(int i=0; i<4; i++){
            add_array[i]=0;
        }
        for(int i=4;i<36; i++){
            new_array[i]=arr[i-4];
        }
        for(int i=0; i<4; i++){
            add_array[i]=arr[i+28];
        }
        for(int i=0; i<4; i++){
            new_array[i+11]=XOR(new_array[i+11],add_array[i]);
        }
        for(int i=0;i<32;i++){
            arr[i]=new_array[i];
        }
        
    }

    int decimal = 0;
    decimal = binary_to_decimal(final_result, 32);
    printf("%d",decimal);
    printf("\n");
    int remainder=0;
    remainder=decimal%11;
    printf("%d",remainder);
    printf("\n");
    

}



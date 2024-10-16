#include<stdio.h>
#include<math.h>

int check_number(int k){
    if(sqrt(k) == 1){
        return 0;
    }
    return 1;
}

void input_massif(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

void task8a(){
    unsigned N;
    int count = 0;

    printf("Enter size n: ");
    scanf("%u", &N);

    int arr[N];
    input_massif(arr, N);

    for(int i = 0; i < N; i++){
        if(check_number(arr[i]) == 0){
           count += 1; 
        }
    }
    printf("Result: %d\n", count);
}

int find_most_frequent_digit(int count[]) {
    int max_count = 0;
    int most_frequent_digit = 0;

    for (int i = 0; i < 10; i++) {
        if (count[i] > max_count || (count[i] == max_count && i > most_frequent_digit)) {
            max_count = count[i];
            most_frequent_digit = i;
        }
    }
    return most_frequent_digit;
}

void task15(){
    int num;
    int count[10] = {0};
    printf("Enter number: ");
    
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    while (num > 0) {
        int digit = num % 10;
        count[digit]++;
        num /= 10;
    }
    printf("Result: %d\n", find_most_frequent_digit(count));
}

int main(){
    task8a();
    task15();
}

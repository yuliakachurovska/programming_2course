#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>

using namespace std;

void task1(){ //є фото
    double x, y, res;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    res = pow(x, y);
    cout <<"x^y = " << res;
}

void task2(){
    char str[10];
    unsigned a;
    unsigned long long sum=0L;
    cout << "Enter:\n";
    unsigned n = 0;

    unsigned mas[1000];
    size_t sz;
    
    while(cin.get(str, 10)){
        cout<<str<<","<<endl;
        // a = atoi(str); по швидкому можна через це, але буде падати, якщо буде не рядок, а цифра
        a = stoul(str, &sz);
        mas[n] = a;
        n++;
        sum += a;
    } cout << "summa = " << sum << "\n";
}

void task3(){
    unsigned n;
    double res;
    cout<<"Enter n: ";
    cin >> n;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i=1; i<=n; i++){
        cout<<" "<<i<<"      ";
    }
    cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    for(int i=1; i<=n; i++){
        res = sqrt(i);
        cout.precision(3);
        cout<<" "<<res<<"    ";
    }
}


void task4() {
    unsigned n;
    cout << "Enter n: ";
    cin >> n;

    if(n == 0){
        cerr << "Error: n must be a positive integer.\n";
        return;
    }

    int* m = new int[n];
    double* x = new double[n];

    for(unsigned i = 0; i < n; i++){
        cout << "Enter m[" << i << "]: ";
        cin >> m[i];
    }

    ifstream f1("input4.txt");
    if(!f1){
        cerr << "Error: Unable to open input4.txt.\n";
        delete[] m;
        delete[] x;
        return;
    }

    unsigned i = 0;
    while(f1 >> x[i]){
        i++;
        if (i >= n) break;
    }
    f1.close();

    if(i < n){
        cerr << "Error: Not enough data in input4.txt. Expected " << n << " numbers, got " << i << ".\n";
        delete[] m;
        delete[] x;
        return;
    }

    ofstream f2("output4.txt");
    if(!f2){
        cerr << "Error: Unable to open output4.txt.\n";
        delete[] m;
        delete[] x;
        return;
    }

    for(unsigned i = 0; i < n; i++){
        double z = pow(x[i], m[i]);
        f2 << z << endl;
    }
    f2.close();
    delete[] x;
    delete[] m;
    cout << "Task completed successfully. Check output4.txt for results.\n";
}

void task5() {
    double mas[1 << 16];
    ifstream f1("input_1.txt");

    if(!f1){
        cerr << "Error. File cannot be open  \n";
        return;
    }

    unsigned i = 0;
    while(f1 >> mas[i] && i < (1 << 16)){
        i++;
    }
    f1.close();
    cout << fixed << setprecision(4);
    for(unsigned j = i; j > 0; j--){
        double res = sqrt(mas[j - 1]);
        cout << res << endl;
    }
}

int main(){
    task1();
    task2();
    task3();
    task4();
    task5();
}

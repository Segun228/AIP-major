#include <iostream>
using namespace std;


int input_matrix(int a[1000][1000],int m,int n ){
    cout << "input matrix elements:"<< endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> *(j+*(a+i));
        }
    }
    return 1;
}


int output_matrix(int a[1000][1000],int m,int n ){
    cout << "outputting matrix elements..." << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << *(j+*(a+i)) << " ";
        }
        cout << endl;
    }
    return 1;
}

int* find_first_positive(int a[1000][1000],int m,int n ){
    
    cout << "searching for first positive..." << endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(*(j+*(a+i))>0){
                return (j+*(a+i));
            }
        }
    }
    return 0;
}

int* find_last_negative(int a[1000][1000],int m,int n ){
    cout << "searching for last negative..." << endl;
    int* elem = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(*(j+*(a+i))<0){
                elem = (j+*(a+i));
            }
        }
    }
    return elem;
    
}

int main()
{
    int matr[1000][1000];
    int m, n;
    int* first_positive_ptr, * last_negative_ptr,  buf;
    cout << "Enter the number of lines"<<endl;
    cin >> m;
    cout << "Enter the number of columns"<<endl;
    cin >> n;

    input_matrix(matr, m, n);
    cout << "entered matrix:" << endl;
    output_matrix(matr, m, n);
    first_positive_ptr = find_first_positive(matr, m, n);
    
    if(!first_positive_ptr){
        cout<< "there is no first positive" << endl;
        return 1;
    }
    cout << "first positive is " << *(first_positive_ptr) << endl;
    last_negative_ptr = find_last_negative(matr, m, n);
    if(!last_negative_ptr){
        cout<< "there is no last negative" << endl;
        return 1;
    }
    cout << "last negative is " << *(last_negative_ptr) << endl;
    

    
    
    buf = *first_positive_ptr;
    *first_positive_ptr = *last_negative_ptr;
    *last_negative_ptr = buf;
    
    cout << "Matrix with swapped elements:" << endl;
    output_matrix(matr, m, n );
    return 0;
}

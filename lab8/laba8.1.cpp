#include <iostream>
#include <string>
#include <vector>
using namespace std;
int linear_input(int* a){
    int n;
    cout << "How many elements you wanna input" << endl;
    cin >> n;
    cout << "Enter the elements" << endl;
    for(int i=0;i<n;i++){
        cin >> *(a+i);
        
    }
    cout << "elements were inputted" << endl;
    return n;
}

int linear_output(int* a, int n){
    cout << "Outputing the elements..." << endl;
    if(!n){
        cout << "You are trying to output an emty array..."<< endl;
    }
    for(int i=0;i<n;i++){
        cout << *(a+i) << " ";
        
    }
    cout << endl;

    return n;
}

int createSet(int* a, int lenA, int* d){
    int flag=1, counter =0, lenD=0;
    for(int i=0; i<lenA; i++){
        for(int j=0; j<lenA; j++){
            if(*(a+i)==*(a+j)){
                counter++;
            }
        }
        if(counter==1){
            *(d+lenD)=*(a+i);
            lenD++;
        }
        counter = 0;
    }
    return lenD;
}

int main(){
    int a[100], b[100], aLen, bLen, c[100], aSet[100], bSet[100], aSetLen, bSetLen, flag=1, counter =0 ;
    cout << "Inputting array A" << endl;
    aLen = linear_input(a);
    cout << "Inputting array B" << endl;
    bLen = linear_input(b);
    aSetLen = createSet(a, aLen, aSet);
    bSetLen = createSet(b, bLen, bSet);
    for(int i=0;i<bSetLen;i++){
        for(int j=0;j<aSetLen;j++){
            if(*(bSet+i)==*(aSet+j)){
                flag = 0;
            }
        }
        if(flag){
            *(c+counter)=*(bSet+i);
            counter++;
        }
        flag =1;
    }
    
    cout << "Array A set" << endl;
    linear_output(aSet, aSetLen);
    cout << "Array B set" << endl;
    linear_output(bSet, bSetLen);
    if (!counter){
        cout <<"array C is empty"<<endl;
        return 0;
    }
    cout << "Array C:";
    linear_output(c, counter);
}
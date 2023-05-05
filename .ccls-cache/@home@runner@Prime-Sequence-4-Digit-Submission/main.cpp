#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num);
int* numberSplitter(int num);
int* arraySort(int size, int array[]);
bool digitCheck(int a, int b, int c);

int main() {
  int primeArray[1061];
  int counter = 0;
  int difference = 0;
  int thirdTerm = 0;
  for(int i = 1000; i < 10000; i++) {
    if(isPrime(i)) {
      //cout << i << endl;
      primeArray[counter] = i;
      counter++;
    } 
  }
  for(int i = 0; i < 1061; i++) {
    for(int j = i+1; j < 1061; j++) {
      difference = primeArray[j] - primeArray[i];
      thirdTerm = primeArray[j] + difference;
      if(isPrime(thirdTerm) && thirdTerm < 10000) {
        if(digitCheck(primeArray[i],primeArray[j],thirdTerm)) {
          if(primeArray[i] != 1487) {
            cout << primeArray[i] << primeArray[j] << thirdTerm << endl;
          }
        }
      }
    }  
  }
  
  return 0;
}

bool isPrime(int num) {
    bool result = true;
    if(num < 2) {
      result = false;
      return result;
    }
    for(int i = 2; i <= ceil(num/2); i++) { 
        if(num % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

int* arraySort(int size, int array[]){
  int temp = 0;
  for(int i = 0; i <size; i++){
    for(int j = 0; j < size -1; j++) {
      if(array[j] > array[i]){
        temp = array[i]; //swap them
			  array[i] = array[j];
        array[j] = temp;	
      }
    }
  }
  return array;
}

bool digitCheck(int a, int b, int c){
  int aDigits[4];
  int bDigits[4];
  int cDigits[4];
  
  for(int i = 3; i >= 0; i--) {
        aDigits[i] = a%10;
        a /= 10;
  }
  for(int i = 3; i >= 0; i--) {
        bDigits[i] = b%10;
        b /= 10;
  }
  for(int i = 3; i >= 0; i--) {
        cDigits[i] = c%10;
        c /= 10;
  }
  
  int* aDigitsSorted = arraySort(4, aDigits);
  int* bDigitsSorted = arraySort(4, bDigits);
  int* cDigitsSorted = arraySort(4, cDigits);
  
  for (int i = 0; i < 4; i++){
        if ((aDigitsSorted[i] == bDigitsSorted[i]) && (bDigitsSorted[i] == cDigitsSorted[i])){
          continue;
        }
        else{
          return false;
        }
  }
  return true;
}
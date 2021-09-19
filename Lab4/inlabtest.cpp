//John Link, jwl9vq@virginia.edu, 9/17/21, prelab4.cpp

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void sizeOfTest(){
string str = "";
int x = 0;
cout << "Size of  int: " << sizeof(x) << endl;
cout << "Hex representation: " << hex << x << endl; 
unsigned int un = 0;
str = to_string(un);
cout << "Size of  unsigned int: " << sizeof(un) << endl;
cout << "Hex representation: " << hex << un << endl;
float fl = 0.0;
str = to_string(fl);
cout << "Size of  float: " << sizeof(fl) << endl;
cout << "Hex representation: " << hex << fl << endl;
double d = 0.0;
str = to_string(d);
cout << "Size of  double: " << sizeof(d) << endl;
cout << "Hex representation: " << hex << d << endl;
char c = ' ';
str = to_string(c);
cout << "Size of  char: " << sizeof(c) << endl;
cout << "Hex representation: " << hex << c << endl;
bool b = false;
str = to_string(b);
cout << "Size of  bool: " << sizeof(b) << endl;
cout << "Hex representation: " << hex << b << endl;
int* ix;
cout << "Size of  int*: " << sizeof(ix) << endl;
char* ch;
cout << "Size of  char*: " << sizeof(ch) << endl;
double* id;
cout << "Size of  double*: " << sizeof(id) << endl;

}

void overflow(){
unsigned int power = 0;
for(int x = 0; x < 32; x++){
    power += pow(2, x);
}
unsigned int over = power  + 1;
cout << power << " + 1 = " << over << endl;
}


string outputBinary(unsigned int x){
string str = "";
int bit = 31;
unsigned int power;
int divis;
while(str.length() < 32){
    power = pow(2, bit);
    divis = x / power;
    if(divis == 1){
        str += "1";
        x = x % power;
    }
    else{
        str += "0";
    }
    bit --;
}
return str;
}

int main() {

int input = 0;
cin >> input;

sizeOfTest();
overflow();
string out = outputBinary(input);
for(int x = 4; x < out.length() - 1; x += 5){
    out = out.substr(0, x) + " " + out.substr(x);
}
cout << out << endl;


return 0;
}

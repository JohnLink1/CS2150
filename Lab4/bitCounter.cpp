//John Link, jwl9vq@virginia.edu, 9/21/21, bitCounter.cpp

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int bitCounter(int x){
if(x == 0)
    return 0;
if(x % 2 == 1)
    return 1 + bitCounter(x / 2);
return bitCounter(x / 2);
}

string baseConverter(string num, int oBase, int fBase){
    int decimal = 0;
    while(num.length() > 0){
        if(num.at(0) > 57)
            decimal += (num.at(0) - 55) * pow(oBase, num.length() - 1);
        else
            decimal += (num.at(0) - 48) * pow(oBase, num.length() - 1);
        num = num.substr(1);
    }
    string ans = "";

    while(decimal > 0){
        if(decimal % fBase >= 10)
            ans += ((char)((decimal % fBase) + 55));
        else
            ans += ((char)((decimal % fBase) + 48));
        decimal /= fBase;
    }
    string revans = "";
    for(int x = ans.length() - 1; x >= 0 ; x--){
        revans += ans.at(x);

    }
    return revans;
}

int main(int argc, char **argv) {

argc = 4;

cout << argv[1] << " has " << bitCounter(stoi(argv[1], nullptr)) << " bit(s)" << endl;
cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(argv[2], stoi(argv[3], nullptr), stoi(argv[4], nullptr)) << " (base " << argv[4] << ")" << endl;

return 0;
}

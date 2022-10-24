
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class bigNumber {
    
public:
    vector<int> bigNum;
    bigNumber(string bigNumStr) {
        for (auto i : bigNumStr) {
            string temp = "";
            temp += i;
            bigNum.push_back(stoi(temp));
        }
    }
    bigNumber() {
        bigNum.push_back(0);
    }

    void operator=(bigNumber bignum) {
        bigNum = bignum.bigNum;
    }

    void operator+(bigNumber bignum) {
        if (bignum.bigNum.size() > bigNum.size()) {
            for (int i = 0; i < bignum.bigNum.size() - bigNum.size(); ++i) {
                bigNum.insert(bigNum.begin(), 0);
            }
        }
        else
            if (bignum.bigNum.size() < bigNum.size()) {
                for (int i = 0; i < bigNum.size() - bignum.bigNum.size(); ++i) {
                    bignum.bigNum.insert(bignum.bigNum.begin(), 0);
                }
            }
        for (int i = 0; i < bigNum.size(); ++i) {
            bigNum[i] += bignum.bigNum[i];
        }
        for (int i = bigNum.size() - 1; i >= 0; --i) {
            if (bigNum[i] > 9) {
                bigNum[i] = bigNum[i] % 10;
                if (i == 0) {
                    bigNum.insert(bigNum.begin(), 1);
                }
                else {
                    bigNum[i - 1]++;
                }             
            }
        }
    }

    void operator*(int num) {
        for (int i = 0; i < bigNum.size(); ++i) {
            bigNum[i] *= num;
            //cout << bigNum[i] << " ";
        }
        cout << endl;
        for (int i = bigNum.size() - 1; i >= 0; --i) {
            if (bigNum[i] > 9) {
                int current = bigNum[i] % 10;
                int next = bigNum[i] / 10;
                bigNum[i] = current;
                if (i != 0) {
                    bigNum[i - 1] += next;
                }
                else {
                    bigNum.insert(bigNum.begin(), next);
                }
            }
        }

    }

    void operator*(bigNumber bignum) {
        bigNumber* big = new bigNumber[bignum.bigNum.size()];
        for (int i = 0; i < bignum.bigNum.size(); ++i) {
            big[i].bigNum = bigNum;
        }
        for (int i = bignum.bigNum.size() - 1; i >= 0; --i) {
            int temp = bignum.bigNum[i];
            big[i] * temp;
            for (int j =  0; j < i; ++j) {
                big[i].bigNum.push_back(0);
            }
        }
        for (int i = 1; i < bignum.bigNum.size(); ++i) {
            big[0] + big[i];
        }
        bigNum = big[0].bigNum;
    }

    void printNumber() {
        for (int i = 0; i < bigNum.size(); ++i) {
            cout << bigNum[i];
        }
        cout << endl;
    }
};




int main()
{
    string firstNum;
    string secondNum;
    cout << "Input first number: ";
    cin >> firstNum;
    cout << "Input second number: ";
    cin >> secondNum;
    bigNumber firstBnum(firstNum);
    firstBnum.printNumber();
    bigNumber secondBnum(secondNum);
    secondBnum.printNumber();
    firstBnum * secondBnum;
    //secondBnum + secondBnum;
    //firstBnum + secondBnum;
    
    firstBnum.printNumber();
    //secondBnum.printNumber();
}


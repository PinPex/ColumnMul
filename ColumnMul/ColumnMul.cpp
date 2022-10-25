
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

    bigNumber operator=(bigNumber bignum) {
        return bignum;
    }

    int countOper = 0;

    int plus(bigNumber &big1, bigNumber& big2) {
        bigNumber big;
        if (big2.bigNum.size() > big1.bigNum.size()) {
            for (int i = 0; i < big2.bigNum.size() - big1.bigNum.size(); ++i) {
                big1.bigNum.insert(big1.bigNum.begin(), 0);
            }
        }
        else
            if (big2.bigNum.size() < big1.bigNum.size()) {
                for (int i = 0; i < big1.bigNum.size() - big2.bigNum.size(); ++i) {
                    big2.bigNum.insert(big2.bigNum.begin(), 0);
                }
            }
        for (int i = 0; i < big1.bigNum.size(); ++i) {
            big1.bigNum[i] += big2.bigNum[i];
            this->countOper++;
        }
        for (int i = big1.bigNum.size() - 1; i >= 0; --i) {
            if (big1.bigNum[i] > 9) {
                big1.bigNum[i] = big1.bigNum[i] % 10;
                if (i == 0) {
                    big1.bigNum.insert(bigNum.begin(), 1);
                }
                else {
                    big1.bigNum[i - 1]++;
                }
                this->countOper++;
            }
        }
        return this->countOper;
    }

    int Mul(bigNumber& big, int num) {
        for (int i = 0; i < big.bigNum.size(); ++i) {
            big.bigNum[i] *= num;
            this->countOper++;
            //cout << bigNum[i] << " ";
        }
        cout << endl;
        for (int i = big.bigNum.size() - 1; i >= 0; --i) {
            if (big.bigNum[i] > 9) {
                int current = big.bigNum[i] % 10;
                int next = big.bigNum[i] / 10;
                big.bigNum[i] = current;
                if (i != 0) {
                    big.bigNum[i - 1] += next;
                }
                else {
                    big.bigNum.insert(big.bigNum.begin(), next);
                }
                this->countOper++;
            }
        }
        return this->countOper;
    }

    vector<int> addNulls(vector<int> &bigNum, int countZeros) {
        for (int i = 0; i < countZeros; ++i) {
            bigNum.push_back(0);
        }
        return bigNum;
    }


    int Mul(bigNumber &big1, bigNumber& big2) {
        
        bigNumber* big = new bigNumber[big2.bigNum.size()];
        for (int i = 0; i < big2.bigNum.size(); ++i) {
            big[i].bigNum = big1.bigNum;
        }
        int j = 0;
        for (int i = big2.bigNum.size() - 1; i >= 0; --i) {
            int temp = big2.bigNum[i];
            this->countOper += Mul(big[j], temp);
            j++;
            //big[i] * temp;
        }
        for (int i = 0; i < big2.bigNum.size(); ++i) {
            big[i].bigNum = addNulls(big[i].bigNum, i);
            //big[i].printNumber();
        }
        for (int i = 1; i < big2.bigNum.size(); ++i) {
            this->countOper += plus(big[0], big[i]);
        }
        cout << endl;
        big1.bigNum = big[0].bigNum;
        return this->countOper;
    }

    void printNumber() {
        for (int i = 0; i < bigNum.size(); ++i) {
            cout << bigNum[i];
        }
        cout << endl;
    }

    void printCountOper() {
        cout << countOper << endl;
    }
    void CountOperNull() {
        countOper = 0;
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
    //firstBnum.printNumber();
    bigNumber secondBnum(secondNum);
    //secondBnum.printNumber();
    cout << "Result: ";
    firstBnum.printNumber();
    cout << "Count operations: ";
    int count = firstBnum.Mul(firstBnum, secondBnum);
    cout << count << endl;
    
    //firstBnum.printNumber();
    //firstBnum.printCountOper();
    //secondBnum + secondBnum;
    //firstBnum + secondBnum;
    
    //firstBnum.printNumber();
    //secondBnum.printNumber();
}


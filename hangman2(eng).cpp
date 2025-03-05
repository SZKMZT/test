#include <iostream>
using namespace std;

void check(char thu, string a, string &a1, bool &test, int &mang, char tusai[]){
    test = false;
    for (int i=0; i<a.length();++i) {
        if (thu == a[i]) {
            test = true;
            a1[i] = thu;
        }
    }
    if (test == false) {
        mang--;
        int temp = 8 - mang;
        tusai[temp] = thu;
    }
}

void hienthi(string a1,char tusai[], int mang) {
    cout << "doan tu: ";
    cout << a1;
    cout << " (tu khong phai:";
    for (int i=0; i<9;++i) {
        if (tusai[i] != ' '){
            cout << tusai[i] << " ";
        }
    }
    cout << "); Mang con lai: "  << mang << endl << " Tu ban doan: ";
}

int main() {
    string a, a1;
    char thu = 'a';
    a = "pluviophile";
    a1.resize(a.length(), '-');
    int mang = 9;
    char tusai[9];
    for (int i=0; i<9;++i) tusai[i] = ' ';
    bool test, win;
    test = false;
    win = false;

    while (mang != 0) {
        hienthi(a1, tusai, mang);
        cin >> thu;
        check(thu, a, a1, test, mang, tusai);
        win = true;
        for (int i=0; i< a.length(); ++i) {
            if(a1[i] == '-') win = false; 
        }

        if (win) {
            cout << "chuc mung ban da thang: " << a;
            return 0;
        }
    }
    cout << "thua cmmr";
    return 0;
}

#include <iostream>
#pragma gcc optimize(2)
#include <string>
 
using namespace std;
 
// 大整数相加函数
string add(string num1, string num2) {
    int carry = 0;
    string result;
 
    // 从最低位开始逐位相加
    int i = num1.length() - 1;
    int j = num2.length() - 1;
 
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
 
        int sum = digit1 + digit2 + carry;
        carry = sum / 10; // 进位
        result = to_string(sum % 10) + result; // 把当前位的结果加到最终结果的前面
        i--;
        j--;
    }
 
    return result;
}
 
// 大整数相减函数
string subtract(string num1, string num2) {
    string result;
    int borrow = 0;
 
    // 从最低位开始逐位相减
    int i = num1.length() - 1;
    int j = num2.length() - 1;
 
    while (i >= 0) {
        int digit1 = num1[i] - '0';
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
 
        // 减去借位
        int diff = digit1 - digit2 - borrow;
 
        if (diff < 0) {
            diff += 10; // 借位
            borrow = 1;
        }
        else {
            borrow = 0;
        }
 
        result = to_string(diff) + result; // 把当前位的结果加到最终结果的前面
        i--;
        j--;
    }
 
    // 去除结果中的前导零
    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
    }
 
    return (result.empty()) ? "0" : result;
}
 
// 大整数乘法函数
string multiply(string num1, string num2) {
    int n = num1.length();
    int m = num2.length();
 
    // 基本情况：如果有一个操作数为0，则结果为0
    if (n == 0 || m == 0 || num1 == "0" || num2 == "0") {
        return "0";
    }
 
    // 基本情况：如果有一个操作数为1，则结果为另一个操作数
    if (num1 == "1") {
        return num2;
    }
 
    if (num2 == "1") {
        return num1;
    }
 
    // 如果操作数很小，直接相乘
    if (n <= 2 || m <= 2) {
        long long int result = stoll(num1) * stoll(num2);
        return to_string(result);
    }
 
    // 将操作数分成两部分
    int mid = min(n, m) / 2;
    string num1Low = num1.substr(0, n - mid);
    string num1High = num1.substr(n - mid);
    string num2Low = num2.substr(0, m - mid);
    string num2High = num2.substr(m - mid);
 
    // 递归计算子问题的乘积
    string z0 = multiply(num1Low, num2Low);
    string z1 = multiply(num1High, num2High);
    string z2 = multiply(add(num1Low, num1High), add(num2Low, num2High));
    string z3 = subtract(subtract(z2, z1), z0);
 
    // 计算最终的乘积
    string result = add(add(z0 + string(mid * 2, '0'), z1), z3 + string(mid, '0'));
 
    return result;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="0";
    string deta="0";
    for(int i=0;i<s.length();i++){
        deta=add(deta,to_string((i+1)*(s[i]-'0')));
        if(i!=0) ans.push_back('0');
        ans=add(ans,deta);

      //  cout<<ans<<' '<<deta<<endl;
    }
    cout<<ans<<'\n';

    return 0;
}
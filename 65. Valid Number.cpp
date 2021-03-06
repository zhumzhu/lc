/*65. Valid Number

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

string s1 = "0"; // True
string s2 = " 0.1 "; // True
string s3 = "abc"; // False
string s4 = "1 a"; // False
string s5 = "2e10"; // True

string s6 = "-e10"; // False
string s7 = " 2e-9 "; // True
string s8 = "+e1"; // False
string s9 = "1+e"; // False
string s10 = " "; // False

string s11 = "e9"; // False
string s12 = "4e+"; // False
string s13 = " -."; // False
string s14 = "+.8"; // True
string s15 = " 005047e+6"; // True

string s16 = ".e1"; // False
string s17 = "3.e"; // False
string s18 = "3.e1"; // True
string s19 = "+1.e+5"; // True
string s20 = " -54.53061"; // True

string s21 = ". 1"; // False

Note: It is intended for the problem statement to be ambiguous. 
You should gather all requirements up front before implementing one.
*/


/*所有的字符可以分为六大类，空格，符号，数字，小数点，自然底数和其他字符，我们需要五个标志变量，
num, dot, exp, sign分别表示数字，小数点，自然底数和符号是否出现，numAfterE表示自然底数后面是否有数字，
那么我们分别来看各种情况：

- 空格：我们需要排除的情况是，当前位置是空格而后面一位不为空格，但是之前有数字，小数点，自然底数或者符号出现时返回false。

- 符号：符号前面如果有字符的话必须是空格或者是自然底数，标记sign为true。

- 数字：标记num和numAfterE为true。

- 小数点：如果之前出现过小数点或者自然底数，返回false，否则标记dot为true。

- 自然底数：如果之前出现过自然底数或者之前从未出现过数字，返回false，否则标记exp为true，numAfterE为false。

- 其他字符：返回false。

最后返回num && numAfterE即可 */

class Solution {
public:
    bool isNumber(string s) {
        bool num = false, numAfterE = true;
        bool dot = false, exp = false, sign = false;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (i < n-1 && s[i+1] != ' ' && (num||dot||exp||sign)){ 
                    return false;
                }
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i-1] != 'e' && s[i-1] != ' ') return false;
                sign = true;
            } else if (isdigit(s[i])) {
                num = true;
                numAfterE = true;
            } else if (s[i] == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (s[i] == 'e') {
                if (exp || !num) return false;
                exp = true;
                numAfterE = false;
            } else{ 
                return false;
            }
        }
        return num && numAfterE;
    }
};







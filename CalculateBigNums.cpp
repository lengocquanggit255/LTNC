#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int compareAbs(string num1, string num2)
{
    if (num1.length() > num2.length())
        return 1;
    if (num1.length() < num2.length())
        return -1;
    return num1.compare(num2);
}

string add(string num1, string num2)
{
    if (num2.length() < num1.length())
    {
        swap(num1, num2);
    }
    string res = "";
    int diffInLen = num2.length() - num1.length();
    int carry = 0;

    for (int i = num1.size() - 1; i >= 0; i--)
    {
        int sum = (num1[i] - '0') + (num2[i + diffInLen] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    for (int i = num2.size() - num1.size() - 1; i >= 0; i--)
    {
        int sum = (num2[i] - '0') + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry != 0)
    {
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

// alwways num1 - num2
string subtract(string num1, string num2)
{
    string res = "";
    if (compareAbs(num1, num2) < 0)
        swap(num1, num2);
    int diffInLen = num1.length() - num2.length();
    int carry = 0;
    for (int i = num2.size() - 1; i >= 0; i--)
    {
        int difference = 0;
        if ((num1[i + diffInLen] - '0') - (num2[i] - '0') - carry >= 0)
        {
            difference = (num1[i + diffInLen] - '0') - (num2[i] - '0') - carry;
            carry = 0;
        }
        else
        {
            difference = 10 + (num1[i + diffInLen] - '0') - (num2[i] - '0') - carry;
            carry = 1;
        }
        res.push_back(difference + '0');
    }

    for (int i = num1.size() - num2.size() - 1; i >= 0; i--)
    {
        int difference = 0;
        if ((num1[i] - '0') - carry >= 0)
        {
            difference = (num1[i] - '0') - carry;
            carry = 0;
        }
        else
        {
            difference = (num1[i] - '0') - carry;
            carry = 1;
        }
        if (difference != 0)
            res.push_back(difference + '0');
    }
    reverse(res.begin(), res.end());
    int i = 0;
    while (res[i] == '0')
    {
        res.erase(i, 1);
    }

    return res;
}

class BigInt
{
    string value;
    int sign;

public:
    // Hàm khởi tạo số nguyên lớn
    BigInt();
    BigInt(const char *);
    BigInt(int);
    BigInt(const BigInt &);

    // Toán tử in ra màn hình
    friend ostream &operator<<(ostream &, const BigInt &);

    // Toán tử gán
    BigInt &operator=(int);
    BigInt &operator=(const char *);
    BigInt &operator=(const BigInt &);

    // Toán tử cộng
    friend BigInt operator+(const BigInt &, const BigInt &);
    friend BigInt operator+(const BigInt &, int);
    friend BigInt operator+(int, const BigInt &);

    // Toán tử trừ
    friend BigInt operator-(const BigInt &, const BigInt &);
    friend BigInt operator-(const BigInt &, int);
    friend BigInt operator-(int, const BigInt &);

    // Toán tử cộng rồi gán
    BigInt &operator+=(int);
    BigInt &operator+=(const BigInt &);

    // Toán tử trừ rồi gán
    BigInt &operator-=(int);
    BigInt &operator-=(const BigInt &);
};

BigInt::BigInt()
{
    this->value = "0";
    this->sign = 1;
}
BigInt::BigInt(const char *_value)
{
    int index = 1;
    if (_value[0] == '-')
    {
        index = 1;
        this->sign = -1;
    }
    else
    {
        index = 0;
        this->sign = 1;
    }
    while (*(_value + index) != '\0')
    {
        this->value += *(_value + index);
        index++;
    }
}
BigInt::BigInt(int _value)
{
    if (_value >= 0)
        this->sign = 1;
    else
        this->sign = -1;

    this->value = to_string(abs(_value));
}
BigInt::BigInt(const BigInt &other)
{
    this->value = other.value;
    this->sign = other.sign;
}

ostream &operator<<(ostream &os, const BigInt &other)
{
    if (other.sign == -1)
        os << '-';
    os << other.value;
    return os;
}

BigInt &BigInt ::operator=(int _value)
{
    if (_value >= 0)
        this->sign = 1;
    else
        this->sign = -1;

    this->value = to_string(abs(_value));
    return *this;
}
BigInt &BigInt ::operator=(const char *_value)
{
    this->value.clear();
    int index = 1;
    if (_value[0] == '-')
    {
        index = 1;
        this->sign = -1;
    }
    else
    {
        index = 0;
        this->sign = 1;
    }
    while (*(_value + index) != '\0')
    {
        this->value += *(_value + index);
        index++;
    }
    return *this;
}
BigInt &BigInt ::operator=(const BigInt &other)
{
    this->value = other.value;
    this->sign = other.sign;
    return *this;
}

BigInt operator+(const BigInt &num1, const BigInt &num2)
{
    BigInt result;
    if (num1.sign == num2.sign)
    {
        result.sign = num1.sign;
        result.value = add(num1.value, num2.value);
    }
    else
    {
        if (compareAbs(num1.value, num2.value) >= 0)
        {
            result.value = subtract(num1.value, num2.value);
            result.sign = num1.sign;
        }
        else
        {
            result.value = subtract(num2.value, num1.value);
            result.sign = num2.sign;
        }
    }
    return result;
}
BigInt operator+(const BigInt &num1, int num)
{
    return num1 + BigInt(num);
}
BigInt operator+(int num, const BigInt &num2)
{
    return num2 + BigInt(num);
}

BigInt operator-(const BigInt &num1, const BigInt &num2)
{
    BigInt res;
    if (num1.sign == num2.sign)
    {
        if (compareAbs(num1.value, num2.value) >= 0)
        {
            if (num1.sign == -1)
                res.sign = -1;
            else
                res.sign = 1;
            res.value = subtract(num1.value, num2.value);
        }
        else
        {
            if (num1.sign == 1)
                res.sign = -1;
            else
                res.sign = -1;
            res.value = subtract(num1.value, num2.value);
        }
    }
    else
    {
        res.sign = num1.sign;
        res.value = add(num1.value, num2.value);
    }
    return res;
}
BigInt operator-(const BigInt &num1, int num2)
{
    return num1 - BigInt(num2);
}
BigInt operator-(int num1, const BigInt &num2)
{
    return BigInt(num1) - num2;
}

BigInt &BigInt::operator+=(int num)
{
    *this = *this + num;
    return *this;
}
BigInt &BigInt::operator+=(const BigInt &other)
{
    *this = *this + other;
    return *this;
}

BigInt &BigInt::operator-=(int num)
{
    *this = *this - num;
    return *this;
}
BigInt &BigInt::operator-=(const BigInt &other)
{
    *this = *this - other;
    return *this;
}

int main()
{
    BigInt a;
    a = "1232498719263921631236123";
    cout << a;

    return 0;
}
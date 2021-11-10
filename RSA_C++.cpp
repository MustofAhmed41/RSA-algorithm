#include <bits/stdc++.h>

using namespace std;

long long Is_Prime(long long x)
{
    for(long long j=x ; j>=2 ; j--)
    {
        int flag = 0;
        if(j%2==0)
        {
            flag = 1;
            continue;
        }
        for(long long i = 3; i <= sqrt(j); i+=2)
        {
            if(j % i == 0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return j;
        }
    }
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

int convertCharToInteger(char c)
{
    //char c = 'a';
    int a;
    if(c>='A' && c<='Z')
    {
        a = c;
        a -= 65;
    }
    else if(c>='a' && c<='z')
    {
        a = c;
        a -= 70;
    }
    else if(c==' ')
    {
        a = 26;
    }
    return a;
}

long long convertToCipher(string input)
{
    long long converted = 0;
    long long counter = 1;

    for(int i = input.size()-1 ; i >=0  ; i--)
    {
        int toInt = convertCharToInteger(input.at(i));
        if(toInt < 9)
        {
            toInt *= counter;
            counter *= 10;
        }
        else
        {
            toInt *= counter;
            counter *= 100;
        }
        converted += toInt;
    }
    return converted;
}

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

char decypherText(long long a){
    char c = a ;
    c -= 191;
    cout << "Plain Text After decryption: "<<c << endl;
}

main()
{
    string input_string = "1111";
    //cin >> input_string;
    cout << "Input bit : " << input_string << endl;
    long long num=0;
    num = stoi(input_string, 0, 2);
    //generating prime numbers
    long long p = Is_Prime(num);
    long long q = Is_Prime(p-1);
    long long n = p * q;
    long long fieN = (p-1) * (q-1);
    string text = "B";
    long long cipherText = convertToCipher(text);

    cout << "NumberSize : " << num   << endl;
    cout << "p : " << p << endl;
    cout << "q : " << q << endl;
    cout << "n : " << n << endl;
    cout << "fieN : " << fieN << endl;
    cout << "PlainText before Encryption: " << text << endl;
    cout << "CipherText before sending: " << cipherText << endl;

    for(long long i = fieN/10 ; i>=1 ; i--)
    {
        long long ret = gcd(fieN,i);
        if(ret==1)
        {
            cout << "e :  " << i << endl;
            for(long long j = 2 ; j < fieN*2 ; j++)
            {
                long long ret2 = (i*j)%fieN;
                if(ret2==1)
                {
                    cout << "e :  " << i << "  d : " << j << "  fieN : " << fieN << endl;
                    long long C = pow(cipherText,i);
                    C = C%n;
                    cout << "C : " << C << endl;
                    long long P = pow(C,j);
                    P = P%n;
                    cout << "P : (Received Text Before De-cyphering) " << P << endl;
                    decypherText(P);
                    break;
                }
            }
            break;
        }
    }
}

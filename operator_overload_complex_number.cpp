/*You are given a class - Complex.

class Complex
{
public:
    int a,b;
};
Operators are overloaded by means of operator functions, which are regular functions with special names. Their name begins with the operator keyword followed by the operator sign that is overloaded. The syntax is:

type operator sign (parameters) { }
You need to overload operators + and << for the Complex class.

The operator + should add complex numbers according to the rules of complex addition:

(a+ib)+(c+id) = (a+c) + i(b+d)  
Overload the stream insertion operator << to add "" to the stream:

cout<<c<<endl;
The above statement should print "" followed by a newline where  and .

Input Format

The overloaded operator + should receive two complex numbers ( and ) as parameters. It must return a single complex number.

The overloaded operator << should add "" to the stream where  is the real part and  is the imaginary part of the complex number which is then passed as a parameter to the overloaded operator.

Sample Input

3+i4
5+i6
Sample Output

8+i10
*/
#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

Complex operator+(Complex x,Complex y)
{
	Complex z;
	z.a = x.a+y.a;
	z.b = x.b + y.b;
	return z;
}
ostream& operator<<(ostream& os, const Complex& z)  
{  
    os << z.a <<"+i"<< z.b;  
    return os;  
}  
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}


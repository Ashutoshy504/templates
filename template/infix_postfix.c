#include<bits/stdc++.h>
using namespace std;
bool isOperant(char s)
{
	if(s=='+'||s=='-'||s=='*'||s=='/'||s==')'||s=='(')
	return false;
	else
	return true;
}
bool isOperator(char s)
{
	if(s=='+'||s=='-'||s=='*'||s=='/')
	return true;
	else
	return false;
}
void infix_to_postfix(string str1,string str2)
{
	stack<char>s;
	s.push(str1[0]);
	int k=0;
	for(int i=1;i<str1.size();i++)
	{
		if(isOperant(str1[i]))
		{
		str2[k]=str1[i];
		k++;
	       }
		else  //(a+((b+c)+(d+e)*f)/g)
		{
			if(isOperator(str1[i]))
			{
				if(str1[i]=='+')
				{

					while(s.top()=='+'||s.top()=='-')
					{
						str2[k]=s.top();
						s.pop();
						k++;
					}
					s.push(str1[i]);
				}
				else
				{
				if(str1[i]=='-')
				{
					while(s.top()=='-'||s.top()=='+')
					{
						str2[k]=s.top();
						s.pop();
						k++;
					}
					s.push(str1[i]);
				}
				else
				{
					if(str1[i]=='*')
					{
						while(s.top()=='*'||s.top()=='/')
						{
							str2[k]=s.top();
							k++;
							s.pop();
						}
						s.push(str1[i]);
					}
					else
					{
						while(s.top()=='/')
						{
							str2[k]=s.top();
							k++;
							s.pop();
						}
						s.push(str1[i]);
					}
				}
				}
			}
			else
			{
				if(str1[i]=='(')
				{
				s.push(str1[i]);
				}
				else
				{

				while(s.top()!='(')
				{
				str2[k]=s.top();
				k++;
				s.pop();}
				s.pop();}
			}
		}
	}
	for(int i=0;i<k;i++)
	cout<<str2[i];
}
int main()
{
	printf("ASHUTOSH YADAV\nSCHOLAR NO. 181112022\n\n");
	string str1,str2;
	cin>>str1;
	infix_to_postfix(str1,str2);
}

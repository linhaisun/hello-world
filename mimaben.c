#include<iostream>
using namespace std;

void encrypt(char *key,char *data,char *encrypt);
int main(void)
    {
    char s1[500],s2[500],s3[500];
    while(cin>>s1>>s2)
        {
        encrypt(s1,s2,s3);
		cout<<s2<<s3<<endl;
    }
    return 0;
    }

void encrypt(char *key,char *data,char *encrypt)
    {
    char table[26];
    bool flag[26];
    int cnt=0;
	for(int i=0;i<26;i++)
		flag[i]=false;
    while(*key!='\0')
        {
        if(*key>='a'&&*key<='z')
            {
            if(!flag[(*key)-'a'])
                {
                flag[(*key)-'a']=true;
                table[cnt++]=(*key)-'a'+'A';
            }
        }
        else if(*key>='A'&&*key<='Z')
            {
            if(!flag[(*key)-'A'])
                {
                flag[(*key)-'A']=true;
                table[cnt++]=(*key);
            }
        }
        key++;
    }
    for(int i=0;i<26;i++)
        {
        if(!flag[i])
            table[cnt++]=i+'A';
    }
	/*for(int i=0;i<26;i++)
        cout<<char('A'+i)<<" ";
	cout<<endl;
    for(int i=0;i<26;i++)
        cout<<table[i]<<" ";
    cout<<endl;*/
	while(*data!='\0')
	{
		if(*data>='a'&&*data<='z')
			*encrypt=table[*data-'a']-'A'+'a';
		else if(*data>='A'&&*data<='Z')
			*encrypt=table[*data-'A'];
		data++;
		encrypt++;
	}
	*encrypt=0;
}
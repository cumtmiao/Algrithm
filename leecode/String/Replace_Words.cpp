/*
In English, we have a concept called root, which can be followed by some other words to form 
another longer word - let's call this word successor. For example, the root an, followed by other, 
which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. 
You need to replace all the successor in the sentence with the root forming it. 
If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.
Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000

*/
//�û����ֵ������ɽ�������ֵ��е�ǰ׺�ַ��������ֵ����У�����ÿ�����ӵĵ��ʣ��ҵ���̵�ǰ׺���ؼ���
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
struct Trie{//�ֵ��������ݽṹ��ÿ���ڵ����һ��ֵ��26�����ӽڵ�
	int val;
	vector<Trie*> child;
	Trie() :child(vector<Trie*>(26, NULL)), val(-1){}
};
void insert(string s, Trie *root)//�ֵ����Ĺ��������ַ���s��ӵ��ֵ�����
{
	for (int i = 0; i < s.size(); i++)
	{
		int num = s[i] - 'a';
		if (root->child[num] == NULL)
			root->child[num]= new Trie();
		
		root = root->child[num];
		if (i != s.size() - 1 && root->val != 0)
			root->val = 1;
		else
			root->val = 0;	
	}
}
string seach(string s, Trie *root)//�����ֵ�������̵�ǰ׺
{
	string res = "";
	for (int i = 0; i < s.size(); i++)
	{
		int num = s[i] - 'a';
		if (root->child[num] == NULL)
			break;
		else
		{
			res += s[i];
			root = root->child[num];
		}
		if (root->val == 0)
			return res;
	}
	if (root->val == 0)
		return res;
	else
		return s;
}
string replaceWords(vector<string>& dict, string sentence) {
	Trie *root = new Trie();
	string res = "";
	for (string s : dict)
		insert(s, root);
	stringstream ss(sentence);//ʵ���ַ����ķָ
	string s;
	int sign = 1;
	while (ss >> s)
	{
		string temp = seach(s, root);
		if (sign != 1)
			res += " ";
	/*	if (temp.empty())
			res += s;
		else
			res += temp;
			*/
		res += temp;
		sign++;
	}
	return res;

}
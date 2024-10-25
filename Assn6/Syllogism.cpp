#include <iostream>
#include "MultiHeadList.h"

using namespace std;

// class which is used for polysyllogism
class Syllogism
{
private:
	typedef pair<string, string> T;
	MultiHeadList<T> syl; // MultiHeadList which stores logics

public:
	// add logic arguments and connect them if they can
	void put(const pair<string, string> &argument)
	{
		// push back argument to syl
		syl.push_back(argument);
		// connect arguments if they have same element
		for (int i = 0; i != syl.headSize(); i++)
		{
			for (auto it = syl.begin(i); it != syl.end(); it++)
			{
				// if ith list's last element corresponds to argument's first element
				if ((*it).second == argument.first)
				{
					// attach list which contains argument to ith list
					syl.merge(i, (syl.headSize() - 1));
				}

				// if argument's last element corresponds to ith list's first element
				else if ((*it).first == argument.second)
				{
					// attach ith list to list which contains argument
					syl.merge((syl.headSize() - 1), i);
				}
			}
		}
		// connect arguments again if they have same element
		for (int i = 0; i != syl.headSize(); i++)
		{
			for (auto it = syl.begin(i); it != syl.end(); it++)
			{
				// if ith list's last element corresponds to argument's first element
				if ((*it).second == argument.first)
				{
					// attach list which contains argument to ith list
					syl.merge(i, (syl.headSize() - 1));
				}
				// if argument's last element corresponds to ith list's first element
				else if ((*it).first == argument.second)
				{
					// attach ith list to list which contains argument
					syl.merge((syl.headSize() - 1), i);
				}
			}
		}
	}
	// make a question q and answer with polysyllogism
	void qna(const string &q)
	{
		string ans;
		for (int i = 0; i != syl.headSize(); i++)
		{
			for (auto it = syl.begin(i); it != syl.end(); it++)
			{
				// if ith list's element's first or second element correspond to q
				if ((*it).first == q || (*it).second == q)
				{
					// first node of ith list
					Node<T> *curNode = syl.begin(i).getcurr();
					while (true)
					{
						// assign ith list's last element to ans
						if (curNode->next->data.first == "tail1")
						{
							ans = curNode->data.second;
							break;
						}
						curNode = curNode->next;
					}
				}
			}
		}
		// print qna's result
		cout << "if " << q << ", then " << ans << endl;
	}
	// print syl's elements
	void print()
	{
		cout << "=============" << endl;
		// print each list's elements
		for (int i = 0; i != syl.headSize(); i++)
		{
			cout << i << " : ";
			for (auto it = syl.begin(i); it != syl.end(); it++)
			{
				if (it == syl.begin(i))
				{
					cout << (*it).first << "->" << (*it).second;
				}
				else
				{
					cout << "->" << (*it).second;
				}
			}
			cout << endl;
		}
	}
};
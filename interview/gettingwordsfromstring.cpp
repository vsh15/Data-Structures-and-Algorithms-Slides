#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {

	int n = 3;
	
	string input;
	vector<string> myvec;
	while (n != 0) {
		getline(cin, input);

		int pos = 0;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ' ')
			{
				string sub;
				sub = input.substr(pos, i - pos);
				myvec.push_back(sub);
				pos = i + 1;
			}
			else if (i == input.length() - 1)
			{
				string sub;
				sub = input.substr(pos, i - pos + 1);
				myvec.push_back(sub);
				pos = i + 1;
			}


		}

		vector<string>::iterator itr;
		itr = myvec.begin();
		for (itr = myvec.begin(); itr != myvec.end(); itr++)
		{
			string test = *itr;
			cout << *itr << endl;
			if (isdigit(test[0])) {
			cout<< stoi(*itr);
			}
		}
		n--;
	}
	system("pause");
	return 0;
}
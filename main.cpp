#include <iostream>
using namespace std;

class SIndexArr
{
	private:
		struct sindexarrobj
		{
			char* index;
			int value;
		};
		sindexarrobj* objs;
		int size;

	public:
		SIndexArr() { size = 0; }
		int operator[](char* index)
		{
			for(int i = 0; i < size; i++)
			{
				if(strcmp(index, objs[i].index) == 0)
					return objs[i].value;
			}
			return -1;
		}
		bool add(char* index, int value)
		{
			bool exists = false;
			for(int i = 0; i < size; i++)
				if(strcmp(index, objs[i].index) == 0)
					exists = true;

			if(!exists)
			{
				if(size > 0)
				{
					sindexarrobj* tmp = objs;
					objs = new sindexarrobj[size + 1];
					for(int i = 0; i < size; i++)
					{
						objs[i].index = tmp[i].index;
						objs[i].value = tmp[i].value;
					}
				}
				else
					objs = new sindexarrobj[1];

				objs[size].index = index;
				objs[size].value = value;

				size++;
				return true;
			}
			else
			{
				for(int i = 0; i < size; i++)
				{
					if(objs[i].index == index)
					{
						objs[i].value = value;
						return true;
					}
				}
			}
			return false;
		}
};

int main()
{
	SIndexArr x;
	x.add("hello",15);
	x.add("blah",84);
	x.add("nineteen",19);
	x.add("nineteen",37);
	x.add("fox",32);

	cout << x["blah"] << endl;
	return 0;
}

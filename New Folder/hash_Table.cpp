#include"Hash_Table.h"

static string HTID = "0";
Hash_Table::Hash_Table(int size)
{
	this->size = size;
	this->table = new HashNode[size];
}


Hash_Table::~Hash_Table()
{
	delete[]table;
}

void Hash_Table::resize(string key, string value)
{
	int oldSize = size;
	if (size == 0)size++;
	size *= 2;
	HashNode* newTable = new HashNode[size];
	ofstream createFile(fileName);
	for (size_t i = 0; i < size; i++)
	{
		createFile << "None:None\n";
	}
	createFile.close();
	for (int j = 0; j < oldSize; j++)
	{
		if (table[j].isOccupied)
		{
			int index = hashFunc(table[j].key);
			while (newTable[index].isOccupied)
			{
				index = (index + 1) % size;
			}
			newTable[index].key = table[j].key;
			newTable[index].value = table[j].value;
			newTable[index].isOccupied = true;
			newTable[index].NoneDeletePresence = 3;
		}
	}
	delete []table;
	table = newTable;
	HSET(key, value);
}
void Hash_Table::HSET(string key, string value)
{
	if (size == 0)
	{
		resize(key, value);
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			table[index].value = value;
			return;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			resize(key, value);
			return;
		}
	}
	table[index].key = key;
	table[index].value = value;
	table[index].isOccupied = true;
	table[index].NoneDeletePresence = 3;
}


int Hash_Table::hashFunc(string key)
{
	int k = ByteToInt(key);
	return (k % size);//+ i * (1 + (k % (size - 1)))) % size;
	// первая хэш-функция + i*втроая хэш фукнция
}

string Hash_Table::HGET(string key)
{
	if (size == 0)
	{
		return "нет элементов";
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].NoneDeletePresence == 1)
		{
			return "такого нет\n";
		}
		if (table[index].key == key)
		{	
			return table[index].value;
		}
		
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			break;
		}
	}
	return "такого нет\n";
}

string Hash_Table::HDEL(string key)
{
	if (size == 0)
	{
		return "нет элементов";
	}
	int i = 0;
	int index = hashFunc(key);
	int oldIndex = index;
	while (table[index].isOccupied)
	{
		if (table[index].key == key)
		{
			string res = table[index].value;
			table[index].isOccupied = false;
			table[index].NoneDeletePresence = 2;
			return res;
		}
		index = (index + 1) % size;
		if (oldIndex == index)
		{
			return "такого нет\n";
		}
	}
	return "такого нет\n";
}

void Hash_Table::PRINT()
{
	int index = 0;
	while (index<size)
	{
		if (table[index].isOccupied)
		{
			cout << table[index].key << ":" << table[index].value << "\n";
		}
		index++;
	}

}

//void Hash_Table::LoadHT(string key, string value)
//{
//	ifstream file(fileName);
//	string data;
//	while (!file.eof())
//	{
//		string buf = "";
//		getline(file, buf);
//		data += buf+'\n';
//	}
//	file.close();
//	int counter = 0;
//	int len = data.size();
//	string bufKey = "";
//	string newData = "";
//	bool replacve = false;
//	for (int i = 0; i < len; i++)
//	{
//		if (data[i] == ':')
//		{
//			counter++;
//			if (bufKey == key)
//			{
//				replacve = true;
//				newData += key + ":" + value;
//				while (data[i++] != '\n');
//			}
//			else
//			{
//				newData += bufKey+':';
//				while (data[i++] != '\n') newData += data[i];
//			}
//			bufKey = "";
//			
//		}
//		bufKey += data[i];
//	}
//	if (replacve)
//	{
//		ofstream fwr(fileName);
//		fwr << newData;
//		fwr.close();
//		return;
//	}
//	else
//	{
//		newData = "";
//		bool isPrecenese = false;
//		for (size_t i = 0; i < len; i++)
//		{
//			if (data[i + 1] == 'o' &&
//				data[i + 2] == 'n' &&
//				data[i + 3] == 'e' &&
//				data[i] == 'N' && !isPrecenese)
//			{
//				newData += key + ":" + value+'\n';
//				while (data[i++] != '\n');
//				isPrecenese = true;
//			}
//			newData += data[i];
//		}
//		ofstream fwr(fileName);
//		fwr << newData;
//		fwr.close();
//	}
//
//}
#include"Array.h"

static string ARRID = "0";

void Array::MINSERT(string elem, int index)
{
    if (capacity == 0)
    {
        if (index != 0)
        {
            cout << "������ ������� ���\n";
            return;
        }
        capacity = 2;
        currentLen = 1;
        arr = new string[capacity];
        arr[currentLen - 1] = elem;
    }

    if (index > currentLen)
    {
        cout << " ������ ������� ���\n";
        return;
    }
    if (currentLen == capacity)
    {
        Array newArr(currentLen + 1);;
        for (int i = 0; i < index; i++)
        {
            newArr.arr[i] = this->MGET(i);
        }
        newArr.arr[index] = elem;
        for (int i = index + 1; i < currentLen + 1; i++)
        {
            newArr.arr[i] = this->MGET(i);
        }
        delete[]arr;
        this->arr = newArr.arr;
    }
    else
    {
        if (index == 0)
        {
            arr[index] = elem;
            return;
        }
        for (int i = currentLen; i >= index; i--)
        {
            arr[i] = arr[i - 1];
        }
        this->arr[index] = elem;
        currentLen++;
    }



}


string Array::MGET(int index)
{

    if (index >= currentLen)
    {
        return " ������ ������� ���\n";
        

    }
    return arr[index];
}


void Array::MPUSH(string elem)
{
    if (capacity == 0)
    {
        capacity = 2;
        currentLen = 1;
        arr = new string[capacity];
        arr[currentLen - 1] = elem;

       
    }
    else if (currentLen == capacity)
    {
        string* newArr = new string[currentLen];
        for (int i = 0; i < currentLen; i++)
        {
            newArr[i] = arr[i];
        }
        
        this->capacity = (this->currentLen) * 2;
        delete[]arr;
        arr = new string[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = newArr[i];
        }
        this->currentLen = this->currentLen + 1;
        delete[]newArr;
        arr[currentLen - 1] = elem;



    }
    else
    {
        this->arr[currentLen++] = elem;
    }
}


Array::Array(int capacity, string fileName, string Name)
{
    this->Name = Name;
    if (capacity > 0)
    {
        this->capacity = capacity * 2;
        this->currentLen = capacity;
        //this->currentLen = 0;
        this->arr = new string[this->capacity];
        for (size_t i = 0; i < capacity; i++)
        {
            arr[i] = "0";
        }
    }

    //else
    //{
    //    this->fileName = fileName;

    //    if (!fileExists(fileName))
    //    {
    //        createNewFile(fileName, Name);
    //    }
    //    else
    //    {
    //        ifstream readFile(fileName);
    //        json j;
    //        readFile >> j;
    //        readFile.close();

    //        if (j["Array"][Name].is_null())
    //        {
    //            j["Array"][Name] = json::array();

    //        }
    //        else
    //        {
    //            for (const auto& item : j["Array"][Name])
    //            {
    //                this->MPUSH(item);
    //            }
    //        }

    //        ofstream FileWrite(fileName);
    //        FileWrite << j.dump(4);
    //        FileWrite.close(); 
    //        
    //    }
    //    
    //}
    
   
}


Array::~Array()
{
    delete[]arr;
    arr = nullptr;
}

Array::Array(Array& other)
{
    other.capacity = this->capacity;
    other.currentLen = this->currentLen;
    other.arr = new string[other.capacity];
    for (int i = 0; i < this->currentLen; ++i)
    {
        other.arr[i] = this->arr[i];
    }
}


Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] arr;

        currentLen = other.currentLen;
        capacity = other.capacity;
        arr = new string[capacity];
        for (int i = 0; i < currentLen; i++)
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

int Array::MLEN()
{
    return this->currentLen;
}

void Array::MDEL(int index)
{
    if (index >= currentLen)
    {
        cout << "������ ������� ���\n";
        return;
    }
    for (int i = index; i < currentLen-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    currentLen--;
}
void Array::PRINT()
{
    for (size_t i = 0; i < currentLen; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void Array::MSET(string elem, int index)
{
    if (index >= currentLen)
    {
        cout << "������ ������� ���\n";
        return;
    }
    arr[index] = elem;

}



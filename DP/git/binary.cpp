#include <iostream>


int checkBit(char c, int n) {
    return c & (1 << n);
}

void setBit(char *c, int n) {
    *c |= 1 << n;
}

class memBlock
{
    private:
    char *mem;
    unsigned long length;

    public:
    memBlock(char *data,unsigned long len, unsigned long startingPoint)
    {
        length = len;
        mem = new char[length-startingPoint];
        for(unsigned long index = startingPoint; index < length;index++)
            mem[index] = data[index]; //copy the data
    }
    memBlock(char *data, unsigned long len)
    {
        length = len;
        mem = new char[length];
        for(unsigned long index = 0; index < length;index++)
            mem[index] = data[index]; //copy the data

    }
    ~memBlock()
    {
        delete mem;
    }

    int GetBit(unsigned long index)
    {
        unsigned long byteIndex = index/8;//get the byte to read
        unsigned long bitIndex = index%8; //get the bit to read
        if(byteIndex > length)
            return -1;
        else
            return  mem[byteIndex] & (1 << bitIndex);
    };
    void SetBit(unsigned long index)
    {
        unsigned long byteIndex = index/8;//get the byte to read
        unsigned long bitIndex = index%8; //get the bit to read
        if(!(byteIndex > length))
        mem[byteIndex] |= 1 << bitIndex;
    };

};



int main()
{

}

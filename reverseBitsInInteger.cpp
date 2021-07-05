/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <limits.h>
#include <stdint.h>
#include <bitset>

using namespace std;

int16_t revBits(int16_t n, uint16_t li, uint16_t hi);

int main()
{
    
    int16_t n = 123;
    
    cout << "num          :: " << n << endl;
    cout << "num          :: " << bitset<16>(n) << endl;
    
    int16_t n_rev = revBits(n, 5, 14);
    cout << "num_rev      :: " << n_rev << endl;
    cout << "num_rev      :: " << bitset<16>(n_rev) << endl;

    return 0;
}

int16_t revBits(int16_t n, uint16_t li, uint16_t hi)
{
    int16_t revBits = 0;
    //uint16_t pow = 15;
    uint16_t numRevBits = hi - li + 1;
    for (int i = 0; i < numRevBits; ++i)
    {
       int16_t bitToShiftMask = 1<<(16-hi+i);
       int16_t bitToShift = (n & bitToShiftMask);
       uint16_t shiftBy = (numRevBits-2*i);
       revBits += (bitToShift << shiftBy);
    }
    
    int16_t mask = 0xFFFFFFFF;
    int16_t mask_l = (mask << (16-li+1));
    int16_t mask_h = (mask << (16-hi));
    mask = mask_l ^ mask_h;
    
    revBits = (~mask & n) + (mask & revBits);
    
    return revBits;
}

/*
int16_t cshiftl(int16_t n, uint16_t c)
{
    int16_t n_csl = (n << c) | (n >> (16-c)); 
    return n_csl;
}

int16_t revBits(int16_t n)
{
    int16_t rev = 0;
    uint16_t pow = 15;
    
    while (n ! = 0)
    {
        rev += (n & 1) << pow;
        n = n >> 1; 
        pow -= 1;
    }
}
*/


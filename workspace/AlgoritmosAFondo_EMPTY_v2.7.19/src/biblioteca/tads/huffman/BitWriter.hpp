#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"

using namespace std;

struct BitWriter
{
};

BitWriter bitWriter(FILE* f)
{
   return {};
}

void bitWriterWrite(BitWriter& bw,int bit)
{
}

void bitWriterWrite(BitWriter& bw,string sbit)
{
}


int bitWriterFlush(BitWriter& bw)
{
   return 0;
}

#endif

#include<iostream>
#include<string>
#include<sstream>
#include<time.h>

#include"SilnikGry.h"

using namespace sf;
using namespace std;



int main()
{
    srand(time(NULL));  

    SilnikGry gra;
    gra.run();
}
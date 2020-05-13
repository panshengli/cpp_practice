#include <iostream>
#include "logger.h"
 
using namespace std;
 
int main(int argc, char *argv) 
{
    initLogger("./sssss.txt","aa.txt","bb.txt");
    LOG(INFO)<<"hello world";
    LOG(ERROR)<<"hello log";
    LOG(WARNING)<<"hello life";
    return 0;
}

#include <iostream>
#include <unistd.h>
#include "lib/client.h"

using namespace std;

int main() {
    client client;
    client.broadcast_disover_all();
    sleep(10);
    return 0;
}
#include <iostream>
#include "loading.h"
#include <string>
#include <Windows.h> 
#include "loginVerification.h"
#include "functionality.h"

using namespace std;



int main()
{

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    loadingBar(); 
    system("color 40"); // Red background and black text

    loginVerification();
    return 0;
}

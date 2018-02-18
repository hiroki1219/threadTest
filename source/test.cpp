#include <iostream>
#include <thread>
#include <unistd.h>

void input( int &check )
{
    while( true ){
        std::cin >> check;
    }
}

void output( int &i, int &check )
{

std::thread t2( input, std::ref(check) );
    while( check != 1 ){
        i++;
        std::cout << i << "\n" << std::endl;
        sleep( 1 );
    }
    t2.detach();
}

int main( void )
{
    int i = 0;
    int check = 0;

    std::thread t1( output, std::ref(i), std::ref(check) );
    t1.join();

    std::cout << "Last number : " << i << std::endl;

    return 0;
}

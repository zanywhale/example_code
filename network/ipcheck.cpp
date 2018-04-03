// g++ -o ipcheck ipcheck.cpp
#include <string>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>

std::string CheckIP();

int main(){
    std::string ip;
    ip = CheckIP();
    std::cout << ip << std::endl;   
}

std::string CheckIP(){
    std::string ipAddress="Unable to get IP Address";
    struct ifaddrs *interfaces = NULL;
    struct ifaddrs *temp_addr = NULL;
    int success = 0;
    // retrieve the current interfaces - returns 0 on success
    success = getifaddrs(&interfaces);
    if (success == 0) {
        // Loop through linked list of interfaces
        temp_addr = interfaces;
        while(temp_addr != NULL) {
            if(temp_addr->ifa_addr->sa_family == AF_INET) {
                if( (strcmp(temp_addr->ifa_name, "eth0")==0) || (strcmp(temp_addr->ifa_name, "docker0")==0) ){
                    ipAddress=inet_ntoa(((struct sockaddr_in*)temp_addr->ifa_addr)->sin_addr);
                }
            }
            temp_addr = temp_addr->ifa_next;
        }
    }
    // Free memory
    freeifaddrs(interfaces);
    return ipAddress;
}

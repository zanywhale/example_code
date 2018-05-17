void check_ipaddr(char *ip1, char *ip2)
{
    regex reg("^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    smatch m1;
    smatch m2;
    std::string str1(ip1);
    std::string str2(ip2);
    if( !regex_match(str1, m1, reg)){
        cout << "\033[1;34mError : ip address is strange... Check it plz.\033[0m" << endl;
        cout << "\033[1;32mUsage: send_arp <interface> <sender(victim) ip> <target ip> \033[0m" << endl <<\
                "\033[1;31mEx)send_arp wlan0 192.168.10.2 192.168.10.1\033[0m\n";
        exit(1);
    }
    if( !regex_match(str2, m2, reg)){
        cout << "\033[1;34mError : ip address is strange... Check it plz.\033[0m" << endl;
        cout << "\033[1;32mUsage: send_arp <interface> <sender(victim) ip> <target ip> \033[0m" << endl <<\
                "\033[1;31mEx)send_arp wlan0 192.168.10.2 192.168.10.1\033[0m\n";
        exit(1);
    }
}

// g++ -o singleton sitngleton.cpp
#include <iostream>

class Singleton{
    private:
        // private constructor and destructor
        Singleton(){}
        virtual ~Singleton(){}

        // private copy constructor and assign operator
        Singleton(const Singleton&);
        const Singleton& operator = (const Singleton&);

        // instance
        static Singleton* instance;
    public:
        static Singleton* getInstance()
        {
            if(instance ==0)
            {
                instance = new Singleton();
            }
            return instance;
        }
};

Singleton* Singleton::instance = 0;

int main(int argc, char *argv[])
{
    Singleton* a = Singleton::getInstance();
    Singleton* b = Singleton::getInstance();

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    return 0;
}

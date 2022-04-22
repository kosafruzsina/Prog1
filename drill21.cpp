#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <numeric>

template<typename K, typename V>
void print(std::map<K, V>& m){
        // for(auto& i : m)
        for(std::pair<K, V> i: m)
        {
            std::cout << i.first << '\t' << i.second << std::endl;
        }
}

void read_map(std::map<std::string, int>& m){
    std::string s;
    int i=0;
    while (m.size() < 10){
        std::cin >> s >> i;
        // m[s] = i;
        m.insert(std::make_pair(s,i));
    }
}

int main()
    try {

        std::map<std::string, int> msi;
        msi["a"] = 2;
        msi["b"] = 3;
        msi["abc"] = 4;
        msi["cd"] = 5;
        msi["qwqw"] = 2;
        msi["xy"] = 3;
        msi["ac"] = 8;
        msi["zs"] = 5;
        msi["sjk"] = 2;
        msi["tr"] = 2;

        print(msi);

        msi.erase("a");
        std::cout<<std::endl << "Egy elem törlése után: " << std::endl;
        print(msi);

        msi.erase(msi.begin(), msi.end());
        std::cout<<std::endl << "Teljes törlés után: " << std::endl;
        print(msi);

        std::cout << "Adj meg 10 kulcs érték párt" << std::endl;
        read_map(msi);
        print(msi);

    }   catch(std::exception& e){
            std::cerr << "Exception: " << e.what() << '\n';
            return 1;
    }   catch(...){
            std::cerr << "Unknown exception" << '\n';
            return 2;
        }
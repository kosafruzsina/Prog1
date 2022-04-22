#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <numeric>
#include <algorithm>

/* class Less_than {
    double v;
    public:
        Less_than(double vv) : v{vv}{}
        bool operator()(const double val) {return val < v;}
}
*/

template< typename C>
void print(const C& c, char sep = '\n' ){
    std::cout<<"Container elements: " << std::endl;

    for(const auto elem: c){
        std::cout << elem << sep;
    }
    std::cout << std::endl;
}
int main()
try{
    const std::string iname {"input_floats.txt"};
    std::ifstream ifs {iname};
    if (!ifs) throw std::runtime_error("Could not read file: " + iname);

    std::vector<double> vd;
    for(double d; ifs >> d;){
        vd.push_back(d);
    }
    print (vd);

    std::vector<int> vi(vd.size());
    /* for(auto& i: vd){
        vi.push_back(i);
    } */
    std::copy(vd.begin(), vd.end(), vi.begin());
    print(vi);

    for(int i=0; i<vd.size(); i++)
    {
        std::cout << vd[i] << '\t' << vi[i] << std::endl;
    }

    // vd sum
    double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
    std::cout << "Sum of vd vector: " << vd_sum << std::endl;
    
    // vd reversed
    std::reverse(vd.begin(), vd.end());
    print(vd);

    // vd atlag
    double vd_mean = vd_sum / vd.size();
    std::cout << "Mean value of vd is: "<< vd_mean << std::endl;

    //atlagnal kevesebb vector
    std::vector<double> vd2(vd.size());

    for (int i=0 ; i<vd.size() ; i++){
        if (vd[i]<vd_mean) vd2.push_back(vd[i]);
    }
    std::cout<<"The elements which are lower than the mean: \n";
    print(vd2);

    /*
    auto it = std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
    vd2.resize(std::distance(vd2.begin(), it()))
    */

    std::sort(vd.begin(), vd.end());
    print(vd);

} catch(std::exception& e) {
    std::cerr<<e.what() <<'\n';
    return 1;
} catch(...) {
    std::cerr<< "Unknown exception!" << '\n';
    return 2;
}
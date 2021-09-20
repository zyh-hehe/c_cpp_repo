#include <iostream> 
#include<algorithm>
#include <vector>
#include <limits>
//using namespace std;
using std::vector;

template <typename T>
class Array {
    T* data_;
    int size_;
public:
    Array(vector<T> v) {
        size_ = v.size();
        data_ = static_cast<T*> (new T[size_]);
        for (int i = 0; i < size_; i++) {
            data_[i] = v[i];
        }
    }
    ~Array() {
        delete this->data_;
        data_ = nullptr;
    }
    int seek(T key) {
        for (int i = 0; i < size_; i++) {
            if (key == data_[i]) {
                return i;
            }
        }
        return -1;
    }
    void display() {
        int i;
        for (i = 0; i < size_; i++) {
            std::cout << data_[i];
            if (i != size_ - 1)
                std::cout << " ";  // 输出一个空格
        }
    }
    void sort() {
        std::sort(this->data_, this->data_+size_);
    }
};

int main() {
    vector<int> vi;
    int ti;
    vector<double> vd;
    double td;
    vector<char> vc;
    char tc;

    while (std::cin.get() != '\n') {
        std::cin.unget();
        std::cin >> ti;
        vi.push_back(ti);
    }

    while (std::cin.get() != '\n') {
        std::cin.unget();
        std::cin >> td;
        vd.push_back(td);
    }

    while (std::cin >> tc) {
        vc.push_back(tc);
    }

    Array<int> ai(vi);
    Array<double> ad(vd);
    Array<char> ac(vc);

    std::cout << ai.seek(10) << std::endl;
    std::cout << ad.seek(10.0) << std::endl;
    std::cout << ac.seek('a') << std::endl;

    ai.sort();
    ad.sort();
    ac.sort();

    ai.display();
    std::cout << std::endl;
    ad.display();
    std::cout << std::endl;
    ac.display();

    // GCC及VC编译器在调试模式下会暂停，便于查看运行结果
#if ( defined(__DEBUG__) || defined(_DEBUG) )
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
#endif
    return 0;
}
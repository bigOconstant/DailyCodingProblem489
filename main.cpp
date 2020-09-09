#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;

bool containsRepeated(std::vector<int> input){
        std::unordered_map<int,bool> values;
        
        for(auto it = input.begin(); it < input.end(); ++it) {
                auto found = values.find((*it));
                if(found != values.end()){
                        return true;
                } else {
                        values[(*it)] = true;
                }
        }
        return false;
};

int main(int argc, char **argv) {
    std::cout << "Starting app2!" << std::endl;
    
    std::vector<int> test1 = {5, 1, 3, 5, 2, 3, 4, 1};
    
    int longest = 0;
    
    for(int i = 0; i < test1.size(); ++i) {
        for(int j = i; j < test1.size(); ++j) {
                if((j -i) <= longest){
                        continue;
                }
                auto subv = std::vector<int> (test1.begin() +i,test1.begin() +j);
                if(!containsRepeated(subv)){
                        longest = subv.size();
                }
        }
    }
    cout<<"longest:"<<longest<<endl;
    return 0;
}

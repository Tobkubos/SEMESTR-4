#include <iostream>
#include <vector>

using namespace std;


void ShowAll(vector<vector<string>> a, string code, string decoded){
    for(const auto &element : a){
        for(const auto &element2 : element){
            cout<<element2<<" ";
        }
        cout<<endl;
    }
    cout<<code<<endl;
    cout<<decoded<<endl;
}

vector<string> Convert(string a){

    vector<string> code;
    string l = a.substr(0,1);
    code.push_back(l);

    int size = a.size();

    for(int i = 2; i<size-2; i+=4){
        string part = a.substr(i, 3);
        code.push_back(part);
    }
    return code;
}

string Decode(vector<vector<string>> codes, string code){
    int size = code.size();
    string Decoded;
    for(int i = 0; i<size-2; i+=3){
        string d = code.substr(i,3);
        for(const auto& element : codes){
            for(const auto &element2 : element){
                if(d == element2){
                    Decoded.push_back(element[0][0]);
                }
            }
        }
    }
    return Decoded;
}

int main(){

    int cases = 0;
    cin>>cases;

    for(int i =0; i<cases;i++){
        int amino = 0;
        cin>>amino;
        vector<vector<string>> AllCodes;
        
        for(int j = 0; j<amino; j++){
            string aminoacid;
            getline(cin>>ws, aminoacid);
            vector<string> vec = Convert(aminoacid);
            AllCodes.push_back(vec);
        }
        string code;
        cin >> code;
        string decoded = Decode(AllCodes, code);
        ShowAll(AllCodes, code, decoded);
    }
    return 0;
}
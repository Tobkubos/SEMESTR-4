#include <iostream>

using namespace std;


int Walk(int data){
    int minutes=1;
    if(data==0) return 15;
    if(data<3000 && data>0)
    {
        int temp = data;
        while(temp<3000 && minutes < 15)
        {
            temp+=data;
            minutes +=1;
        }
        return minutes;
    }
    return minutes;
}

int main(){

    int cases = 0;
    cin>>cases;

    for(int i = 0; i<cases; i++){
        int temp = 0;
        cin>>temp;
        cout<<Walk(temp)<<endl;
    }

    return 0;
}

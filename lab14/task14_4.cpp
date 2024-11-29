#include<iostream>
#include<fstream>

using namespace std;

bool checkTags(ifstream f1, string openTD = "<td>", string closeTD = "</td>"){
    int opentag = 0;
    int closetag = 0;
    string buf;
    while(!f1.eof()){
        if(f1>>buf){
            if(buf == openTD){
                opentag++;
            }
            else if(buf == closeTD){
                closetag++;
            }
            if(closetag>opentag){
                return false;
            }
        }
        else{
            break;
        }
    }
    return closetag==opentag;
}

int main(){
    const char *fname = "t.4txt";
    ifstream f1(name);
    if(f1.bad()){
        cerr<<"error opening"<<fname<<endl;
    }
    cout<<"\nCheck"<<boolalpha<<checkTags(f1);
    f1.close();
}
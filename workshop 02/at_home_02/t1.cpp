#include <iostream>
#include <string>

using namespace std;

string swap(string parm1) {

  if (parm1.length() == 8u){
    return "Sandwiches";
  }

  else if (parm1 != "Ever"){
    return parm1;
  }

  else{
    return "9876";
  }

}

void print(string curr, string(*func)(string)){

try{
  string temp = func(curr);
  cout<< temp <<endl;
}
catch (double){
  cout<< "Woops!" <<endl;

}
catch(...){
  cout<<"Oh No !"<<endl;
}
}

int main(){
  string arr[] =  {"Midterms", "Are","My","Things","Ever", "3"};

  for (auto x : arr){
    print(x,swap);
  }
return 0;
}


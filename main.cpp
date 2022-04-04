//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_YourLastName

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
#include <cassert>
#include <stack>
#include <set>
#include <utility>
#include <map>
using namespace std;
typedef map<string, int> MapT;
typedef MapT::const_iterator MapIterT;

//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1 (vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
          {
              cout << vec[i] << " "; 
          }    
      } 
};

class MyClassVector2
{
  private:
    vector<int> vec;
  public:
    MyClassVector2 (vector<int> v) : vec(v)
    {      
    }
    void print()
    {
      for (int i = 0; i < vec.size(); i++)
      {
        cout << vec[i] << " ";
      }
    }
};

class MyClassVector3
{
  private:
    vector<int>& vec;
 
  public:
    MyClassVector3(vector<int>& arr)
      : vec(arr)
    {
    }
    void print()
    {
      for (int i = 0; i < vec.size(); i++)
      {
        cout << vec[i] << " ";
      }
    }
};

bool less_than_7(int value)
{
  return value < 7;
}

int main() 
{
    /****Section_Name***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1);
    vd.push_back(2);
    vd.push_back(3);
    vd.push_back(55.4);
    vd.push_back(10.3);
    vd.push_back(68.6);
    vd.push_back(76.8);
    

    //add 3 elements to the vi vector

    vi.push_back(26);
    vi.push_back(2);
    vi.push_back(29);

   // add 3 elements to the vs vector

    vs.push_back("vd vector");
    vs.push_back("vi vector");
    vs.push_back("vs vector");

   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector

    cout << "\nValues in vi: " << endl;
    for(int vals : vi)
    {
      cout << vals << endl;
    }

   // display the 3 elements in the vs vector

    cout << "\nValues in vs: " << endl;
    for (string vals : vs)
    {
      cout << vals << endl;
    }

    /****Section_Name***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

   cout << "\nVector_as_Class_Member" << endl; 
    vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print();
      
      //Continue with MyClassVector2 and MyClassVector3

    cout << "\n\nVector_initialized_list" << endl; 
    vector<int> vec2; 
    for (int i = 5; i >= 1; i--)
    {
      vec2.push_back(i);
    } 
    MyClassVector2 init(vec2); 
    init.print();

    cout << "\n\nVector_as_Class_Member_3" << endl; 
    vector<int> vec3; 
    for (int i = 1; i <= 5; i++)
    {
      vec3.push_back(i);
    } 
    MyClassVector3 ref(vec3); 
    ref.print();

    /****Section_Name***STL_Iterators*/ 

    cout << "\n\nSTL Iterators" << endl;
    vector<int> vint(3);    //Vector size 3 initialized 10, 20, 30 
    vint[0] = 10;
    vint[1] = 20;
    vint[2] = 30;

    vector<int>::iterator it;    //Something about derefrencing to access the value pointed by it
    for (it = vint.begin(); it != vint.end(); ++it)
    {
      cout << *it << " ";
    }

    /****Section_Name*** Stack*/

    stack<int> st;    //Declare stack of ints

    st.push(100);    //Add 100 to stack
    assert(st.size() == 1);    //Verify size
    assert(st.top() == 100);    //Verify value of element

    st.top() = 456;    //Assign new value
    assert(st.top() == 456);

    st.pop();    //Remove element
    assert(st.empty() == true);

    /****Section_Name**** Set*/
    //Write the code as presented in: 3. std::set

    cout << "\n\nSet" << endl;
    set<int> iset;    //Set of unique ints

    iset.insert(11);    //Add values
    iset.insert(-11);
    iset.insert(55);
    iset.insert(22);
    iset.insert(22);
    if (iset.find(55) != iset.end())    //Check for value
    {
      iset.insert(55);
    }
    assert(iset.size() == 4);    //Confirmation
    set<int>::iterator it2;
    for (it2 = iset.begin(); it2 != iset.end(); it2++)
    {
      cout << *it2 << " ";
    }

    /****Section_Name****Pair_Structure*/
    //Write the code as presented in: 4. std::pair structure

    pair<string, string> strstr;    //Pair of a two strings
    strstr.first = "Hello";
    strstr.second = "World";

    pair<int, string> intstr;    //Pair of int and str
    intstr.first = 1;
    intstr.second = "one";

    pair<string, int> strint("two", 2);    //Pair of str and int
    assert(strint.first == "two");
    assert(strint.second == 2);

    /****Section_Name**** Map_Insert*/
    //Write the code as presented in: 14. std::map::insert

    MapT amap;    //I'm not bothering to pretend to know what on earth is happening here
    pair<MapIterT, bool> result = amap.insert(make_pair("Fred", 45));
    assert(result.second == true);
    assert(result.first->second == 45);

    result = amap.insert(make_pair("Fred", 54));    //Yup no idea

    assert(result.second == false);
    assert(result.first->second == 45);

    /****Section_Name****Map_Summary*/
    //Write the code as presented in: 16. Map summary

    cout << "\n\nMap_Summary" << endl;
    map<string, string> phone_book;    //Create a map of str and str
    phone_book["411"] = "Directory";
    phone_book["911"] = "Emergency";
    phone_book["508-678-2811"] = "BCC";
    if (phone_book.find("411") != phone_book.end())    //Check for "411" and add it if not found
    {
      phone_book.insert(make_pair(string("411"), string("Directory")));
    }
    assert(phone_book.size() == 3);
    map<string, string>::const_iterator it3;
    for (it3 = phone_book.begin(); it3 != phone_book.end(); ++it3)
    {
      cout << it3->first << " " << it3->second << " " << endl;
    }

    /****Section_Name**** Sort_Algorithm*/
    //Write the code as presented in: 23. sort example

    int arr[100];    //Declare arrary with 100 elements
    sort(arr, arr + 100);    //Sort array from beginning to 100th element
    vector<int> v1(100);    //Declare vector (I had to add <int> and the 100 because I would get errors copying the guide)
    sort(v1.begin(), v1.end());    //Sort from start to end

    /****Section_Name****Predicate_Algorithm*/
    //Write the code as presented in: 25. count_if and predicate function

    vector<int> v2;
    int count_less = std::count_if(v2.begin(), v2.end(), less_than_7);    //Count if vvalue equal to or less than 7

    return 0; 
 }
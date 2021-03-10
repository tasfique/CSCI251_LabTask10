//Name-Tasfique Enam
//Question 2
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main () {

        ifstream input ("document.txt"); //reading the txt file
        char data;
        bool check = true;
        int c=0;
        vector<char> v;
        while (input >> data) {

            cout<<data;
            v.push_back(data); //inputting the data in vector.
            //c++;
        }
        cout << " " << endl;
        //cout << c << endl;
        input.close();

        cout << "\nThe data in the Vectors are " << endl;
        for(int i=0; i<v.size(); i++) {
            cout << v[i]; //displaying to see if the vector have the data or not?
        }

        //cout << v.empty()<<endl; //checking if the vector is empty or not?

        vector<char>::iterator ptr; //iterator for beginning and ending...
        vector<char>::reverse_iterator itrE;
        ptr = v.begin();
        itrE = v.rbegin();


        while (ptr != v.end() && itrE != v.rend()) {
        if (*ptr == *itrE) {
            ptr++;
            itrE++;
        }
        else {
            check = false;
            break;
        }
    }
    if (check)
    {
        cout << "\nThe forward text: ";
        ptr = v.begin();
        while (ptr != v.end()) {
            cout << *ptr;
            ptr++;
        }

        cout << "\nThe reverse text: ";
        itrE = v.rbegin();
        while (itrE != v.rend()) {
            cout << *itrE;
            itrE++;
        }

        cout << "\nIt is a palindrome." << endl;
    } else
        cout << "\nIt is not a palindrome." << endl;

        /*cout << "\nThe vector elements are : ";
        for (ptr = v.begin(); ptr < v.end(); ptr++)
            cout << *ptr << " ";*/

        //string::reverse_iterator ri=*ptr.rbegin();

        /*if(equal(v.begin(),v.end(),*ptr)) {
            cout<<v<<" is a Pallindrome!"<<endl;
        } else {
            cout<<str<<" is not a Pallindrome!"<<endl;

        }*/

    return 0;
}


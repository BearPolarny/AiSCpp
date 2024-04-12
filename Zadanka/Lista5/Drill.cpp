#include <iostream>
#include <vector>
#include <sstream>

using std::cout;

class MyException: public std::exception
{};


int main(){
    try {
        //1
        //Cout << "Success!\n";
        cout << "Success!1\n";
        //2
        // cout << "Success !\n;
        cout << "Success !2\n";
        //3
        // cout << "Success" << !\n"
        cout << "Success3" << "!\n";
        //4
        // cout << success << endl;
        std::string success = "Success!4";
        cout << success << std::endl;
        //5
        // string res = 7; vector<inl> v(10); v[5] = res; cout << "Success!\n";
        int res = 7; std::vector<int> v(10); v[5] = res; cout << "Success!5\n";
        //6
        // vector<inl> v(10); v(S) = 7; if (v(5)! =7) cout << "Success!\n"; 
        std::vector<int> v1(10); v1[5] = 7; if (v1[5] == 7) cout << "Success!6\n";
        //7
        // if (cond) cout << "Success!7\n"; else cout << "Fail!7\n";
        bool cond = 1;
        if (cond) cout << "Success!7\n"; else cout << "Fail!7\n";
        //8
        bool c = false; if (!c) cout << "Success!8\n"; else cout << "Fail!8\n";
        //9
        // string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!9\n";
        std::string s = "ape"; bool c1 = "fool"<s; if (!c1) cout << "Success!9\n";
        //10
        // string s = "ape"; if (s=="fool") cout << "Success!10\n";
        std::string s1 = "ape"; if (s1 != "fool") cout << "Success!10\n";
        //11
        // string s = "ape" ; if (s=="fool") cout < "Success!11\n";
        std::string s2 = "ape" ; if (s2 != "fool") cout << "Success!11\n";
        //12
        // string s= "ape"; if (s+"fool ") cout < "Success!12\n";
        std::string s3 = "ape"; 
        if ( std::istringstream(s3 + "fool")) 
            cout << "Success!12\n";
        //13
        // vector<char> v(5); for (int i=O; O<v.size(); ++i) ; cout << "Success!13\n";
        std::vector<char> v2(5); for (int i=0; i<v2.size(); ++i) ; cout << "Success!13\n";
        //14
        // vector<char> v(S); for (int i=O; i<=v.size(); ++i) ; cout << "Success!14\n";
        std::vector<char> v3(5); for (int i=0; i<=v3.size(); ++i) ; cout << "Success!14\n";
        //15
        // string s= "Success!15\n"; for (int i=O; i<6; ++i) cout << s[i];
        std::string s4= "Success!15\n"; for (int i=0; i<11; ++i) cout << s4[i];
        //16
        // if (true) then cout << "Success!16\n"; else cout << "Fail!16\n";
        if (true) cout << "Success!16\n"; else cout << "Fail!16\n";
        //17
        // int x = 2000; char c = x; if (c==2000) cout << "Success!17\n";
        int x = 2000; char c2 = x; if (c2==2000) cout << "Success!17\n";  // false bo char overflow
        //18
        // string s = "Success!18\n"; for (int i=O; i<10; ++i) cout << s[i];
        std::string s5 = "Success!18\n"; for (int i = 0; i < 11; ++i) cout << s5[i];
        //19
        // vector v(5); for (int i=O; i<=v.size(); ++i) ; cout << "Success !19\n";
        std::vector<int> v4(5); for (int i=0; i<=v4.size(); ++i) ; cout << "Success !19\n";
        //20
        // int i=O; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!20\n";
        int i1=0; int j1 = 9; while (i1 < 10) ++i1; if (j1 < i1) cout << "Success!20\n";
        //21
        // int x = 2; double d= 5/(x-2); if (d==2*x+0.5) cout << "Success!21\n"; 
        int x2 = 2; double d = 5/(x2-1); if (d==2*x2+0.5) cout << "Success!21\n"; // dzielenie przez 0
        //22
        // string<char> s = "Success!22\n"; for (int i=O; i<=10; ++i) cout << s[i];
        std::string s6 = "Success!22\n"; for (int i=0; i <= 11; ++i) cout << s6[i];
        //23
        // int i=O; while (i<10) ++j; if (j<i) cout << "Success!23\n";
        int i2=0, j2=0; while (j2 < 10) ++j2; if (j2 <= i2) cout << "Success!23\n";
        //24
        // int x = 4; double d = 5/(x-2); if (d=2*x+0.5) cout << "Success!24\n";
        int x3 = 4; double d2 = 5/(x3-2); if (d2!=2*x3+0.5) cout << "Success!24\n";
        //25
        // cin << "Success!25\n"; 
        cout << "Success!25\n"; 
        
        std::cin>>x;
        return 0;
    }
    catch (MyException e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    catch ( ... ) {
        std::cerr << "Oops: unknown exception !\n";
        return 2;
    }
}
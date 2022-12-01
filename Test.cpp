////
////  Test.cpp
////  Project 4
////
////  Created by Angela Kan on 11/12/20.
////
//
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//int appendToAll(string a[], int n, string value);
//int lookup(const string a[], int n, string target);
//int positionOfMax(const string a[], int n);
//int rotateLeft(string a[], int n, int pos);
//int countRuns(const string a[], int n);
//int flip(string a[], int n);
//int differ(const string a1[], int n1, const string a2[], int n2);
//int subsequence(const string a1[], int n1, const string a2[], int n2);
//int lookupAny(const string a1[], int n1, const string a2[], int n2);
//int divide(string a[], int n, string divider);
//
//int main()
//{
//    string h[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
//    assert(lookup(h, 7, "kamala") == 5);
//    assert(lookup(h, 7, "joe") == 2);
//    assert(lookup(h, 2, "joe") == -1);
//    assert(positionOfMax(h, 7) == 3);
//
//    string g[4] = { "martha", "mark", "lindsey", "sara" };
//    assert(differ(h, 4, g, 4) == 2);
//    assert(appendToAll(g, 4, "?") == 4 && g[0] == "martha?" && g[3] == "sara?");
//    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "lindsey?" && g[3] == "mark?");
//
//    string e[4] = { "joe", "susan", "", "kamala" };
//    assert(subsequence(h, 7, e, 4) == 2);
//
//    string d[5] = { "mark", "mark", "mark", "susan", "susan" };
//    assert(countRuns(d, 5) == 2);
//
//    string f[3] = { "lindsey", "joe", "mike" };
//    assert(lookupAny(h, 7, f, 3) == 2);
//    assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "lindsey");
//
//    assert(divide(h, 7, "lindsey") == 3);
//
//    cout << "All tests succeeded" << endl;
//}
//
//int appendToAll(string a[], int n, string value){
//    if (n < 0){
//        return -1;
//    } else {
//        for (int i=0; i<n; i++){
//            a[i] += value;
//        }
//        return n;
//    }
//}
//
//int lookup(const string a[], int n, string target){
//    if (n < 0){
//        return -1;
//    } else {
//        for (int i=0; i<n; i++){
//            if (a[i] == target){
//                return i;
//            }
//        }
//        return -1;
//    }
//}
//
//int positionOfMax(const string a[], int n){
//    if (n <= 0){
//        return -1;
//    } else {
//        //do we have to check for empty string here? might as well add an if statement.., or do we check w/ the top if statement (n<=0)...i think so?
//        string max = a[0];
//        int pos = 0;
//        for (int i=0; i<n; i++){
//            if (a[i] > max){
//                max = a[i]; // technically not necessary, but good to update max
//                pos = i;
//            }
//        }
//        //what does it mean to have no interesting elements?
//        return pos;
//    }
//}
//
//int rotateLeft(string a[], int n, int pos){
//    if (n <= 0){
//        return -1;
//    } else {
//        if(pos >= 0 && pos < n){    //what about a case where only one element, n=1, pos =0?should be fine.... just skip for loop ;;; WHAT IF POSITION = N but n < array size-1?
//            string tempStr = a[pos];
//            for (int i=pos; i<n - 1; i++){
//                a[i] = a[i+1];
//            }
//            a[n-1] = tempStr;
//            return pos;
//        } else {
//            return -1;
//        }
//    }
//}
//
//int countRuns(const string a[], int n){
//    if (n < 0){
//        return -1;
//    } else {
//        int count = 0;
//        for (int i=0; i<n-1; i++){
//            if (a[i] != a[i+1]){
//                count++;
//            }
//        }
//        if (n != 0){
//            count++;
//            return count;
//        } else {
//            return 0;
//        }
//    }
//}
//
//int flip(string a[], int n){
//    if (n < 0){
//        return -1;
//    } else {
//        for (int i=0; i<n/2; i++){
//            string tempStr = a[i];
//            a[i] = a[n-1-i];
//            a[n-1-i] = tempStr;
//        }
//        return n;
//    }
//}
//
//int differ(const string a1[], int n1, const string a2[], int n2){
//    if (n1 < 0 || n2 < 0){
//        return -1;
//    } else {
//        int smallerN;
//        if (n1 <= n2){
//            smallerN = n1;
//        } else {
//            smallerN = n2;
//        }
//        for (int i=0; i<smallerN; i++){
//            if (a1[i] != a2[i]){
//                return i;
//            }
//        }
//        return smallerN;
//    }
//}
//
//int subsequence(const string a1[], int n1, const string a2[], int n2){
//    if (n1 < 0 || n2 < 0){
//        return -1;
//    } else {
//        if (n2 == 0){
//            return 0;
//        }
//        if (n1 == 0 || n2>n1){
//            return -1;
//        }
//        bool isSubseq = false;
//        for (int i=0; i<n1; i++){   //what if n1 = 0? return 0 if n2 = 0, -1 if not; what if n2>n1? return -1...if n2 is ever 0, always return 0..
//            if (a2[0] == a1[i]){
//                isSubseq = true;
//                int pos = i;
//                for (int j=0; j<n2; j++){
//                    if ((i+j) >= n1){   //what if n1 < a1[i+j]?? ADDRESS!/TEST!!
//                        isSubseq = false;
//                        return -1;
//                    } if (a1[i+j] != a2[j]){
//                        isSubseq = false;
//                    }
//                }
//                if (isSubseq){
//                    return pos; //return position in a1 where subsequence begins
//                }
//            }
//        }
//        return -1;
//    }
//}
//
//int lookupAny(const string a1[], int n1, const string a2[], int n2){
//    if (n1 <= 0 || n2 <= 0){
//        return -1;
//    } else {
//        for (int i=0; i<n1; i++){
//            for (int j=0; j<n2; j++){
//                if (a1[i] == a2[j]){
//                    return i;
//                }
//            }
//        }
//        return -1;
//    }
//}
//
//int divide(string a[], int n, string divider){
//    if (n < 0){     // test case for n=0 should return 0!
//        return -1;
//    } else {
//        int countLessThan = 0;
//        for (int i=0; i<n; i++){
//            if (a[i] < divider){
//                countLessThan++;
//            }
//        }
//        for (int j=0; j<n; j++){
//            for (int i=0; i<n-1; i++){
//                if (a[i] > a[i+1]){
//                    string tempStr = a[i];
//                    a[i] = a[i+1];
//                    a[i+1] = tempStr;
//                }
//            }
//        }
//        if (countLessThan < n){
//            return countLessThan;
//        } else {    //if (countLessThan == n)
//            return n;
//        }
//    }
//}

//
//  main.cpp
//  Project 4
//
//  Created by Angela Kan on 11/10/20.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//declare all the functions for readability/program order
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int main() {
    //test cases for the 10 functions, in order declared and separated by paragraphs
    string g[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "martha?" && g[3] == "sara?");
    string g1[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(g1, 3, "3") == 3 && g1[0] == "martha3" && g1[3] == "sara");
    string g2[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(g2, 0, "?") == 0 && g2[0] == "martha" && g2[3] == "sara");
    string g3[4] = { "martha", "mark", "lindsey", "sara" };
    assert(appendToAll(g3, -4, "?") == -1 && g3[0] == "martha" && g3[3] == "sara");
    string g4[4] = { "", "mark", "lindsey", "sara" };
    assert(appendToAll(g4, 4, "?") == 4 && g4[0] == "?" && g4[3] == "sara?");
    string g5[5] = { "donald", "joe", "mike", "lindsey", "kamala" };
    assert(appendToAll(g5, 5, "!!!") == 5 && g5[0] == "donald!!!" && g5[4] == "kamala!!!");

    string h[7] = { "martha", "mark", "joe", "joe", "", "kamala", "lindsey" };
    assert(lookup(h, 7, "kamala") == 5);
    assert(lookup(h, 7, "joe") == 2);
    assert(lookup(h, 2, "joe") == -1);
    assert(lookup(h, 0, "martha") == -1);
    assert(lookup(h, -2, "joe") == -1);
    assert(lookup(h, 7, "") == 4);
    assert(lookup(h, 7, "Joe") == -1);

    string k[6] = { "jamie", "lindsey", "mark", "susan", "joe", "donald" };
    assert(positionOfMax(k, 6) == 3);
    string k1[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(k1, 7) == 3);
    string k2[0] = { };
    assert(positionOfMax(k2, 0) == -1);
    string k3[0] = { };
    assert(positionOfMax(k3, -5) == -1);
    string k4[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(k4, -5) == -1);
    string k5[7] = { "", "", "", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(k5, 3) == 0);
    string k6[7] = { "", "", "", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(k6, 4) == 3);
    string k7[7] = { "susan", "mark", "joe", "martha", "", "kamala", "lindsey" };
    assert(positionOfMax(k7, 7) == 0);
    string k8[7] = { "martha", "susan", "joe", "susan", "", "kamala", "lindsey" };
    assert(positionOfMax(k8, 7) == 1);
    string k9[1] = { "martha"};
    assert(positionOfMax(k9, 1) == 0);
    string k10[7] = { "susan", "mark", "joe", "martha", "", "kamala", "lindsey" };
    assert(positionOfMax(k10, 0) == -1);

    string l[5] = { "kamala", "jamie", "lindsey", "sara", "mark" };
    assert(rotateLeft(l, 5, 1) == 1 && l[1] == "lindsey" && l[4] == "jamie");
    string l1[4] = { "martha", "mark", "lindsey", "sara" };
    assert(rotateLeft(l1, 4, 1) == 1 && l1[1] == "lindsey" && l1[3] == "mark");
    string l2[4] = { "martha", "mark", "lindsey", "sara" };
    assert(rotateLeft(l2, 4, 1) == 1 && l2[1] == "lindsey" && l2[3] == "mark");
    string l3[0] = { };
    assert(rotateLeft(l3, 0, 3) == -1);
    assert(rotateLeft(l3, 0, -1) == -1);
    assert(rotateLeft(l3, -1, 3) == -1);
    assert(rotateLeft(l3, 0, 3) == -1);
    string l4[4] = { "martha", "mark", "lindsey", "sara" };
    assert(rotateLeft(l4, 0, 1) == -1);
    assert(rotateLeft(l4, 4, -1) == -1);
    assert(rotateLeft(l4, 4, 4) == -1);
    assert(rotateLeft(l4, 4, 5) == -1);
    assert(rotateLeft(l4, 4, 0) == 0 && l4[0] == "mark" && l4[3] == "martha");
    string l5[4] = { "martha", "", "lindsey", "sara" };
    assert(rotateLeft(l5, 4, 1) == 1 && l5[1] == "lindsey" && l5[3] == "");
    string l6[1] = { "martha" };
    assert(rotateLeft(l6, 1, 0) == 0 && l6[0] == "martha");
    string l7[4] = { "martha", "mark", "lindsey", "sara" };
    assert(rotateLeft(l7, 4, 3) == 3 && l7[0] == "martha" && l7[3] == "sara");
    assert(rotateLeft(l7, 3, 3) == -1);
    assert(rotateLeft(l7, 3, 2) == 2 && l7[0] == "martha" && l7[2] == "lindsey" && l7[3] == "sara");
    assert(rotateLeft(l7, 3, 1) == 1 && l7[0] == "martha" && l7[1] == "lindsey" && l7[2] == "mark" && l7[3] == "sara");

    string d[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(d, 9) == 5);
    string d1[5] = { "mark", "mark", "mark", "susan", "susan" };
    assert(countRuns(d1, 5) == 2);
    string d3[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "" };
    assert(countRuns(d3, 9) == 6);
    string d4[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "rob" };
    assert(countRuns(d4, 9) == 6);
    string d5[7] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe" };
    assert(countRuns(d5, 7) == 4);
    string d6[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(d6, 4) == 3);
    string d7[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(d7, 5) == 4);
    string d8[0] = { };
    assert(countRuns(d8, 0) == 0);
    string d9[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(d9, 0) == 0);
    string d10[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "mike", "mike" };
    assert(countRuns(d10, -4) == -1);
    string d11[9] = { "susan", "donald", "mike", "mike", "joe", "joe", "joe", "", "" };
    assert(countRuns(d11, 9) == 5);

    string f[3] = { "lindsey", "joe", "mike" };
    assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "lindsey");
    string f1[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(f1, 4) == 4 && f1[0] == "susan" && f1[1] == "" && f1[2] == "mike");
    string f2[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(f2, 0) == 0 && f2[0] == "donald" && f2[1] == "mike");
    string f3[0] = { };
    assert(flip(f3, 0) == 0);
    string f4[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(f4, -2) == -1);
    string f5[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(f5, 6) == 6 && f5[0] == "jamie" && f5[1] == "sara" && f5[2] == "susan");
    string f6[3] = { "lindsey", "joe", "mike" };
    assert(flip(f6, 2) == 2 && f6[0] == "joe" && f6[2] == "mike");
    string f7[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    assert(flip(f7, 5) == 5 && f7[0] == "sara" && f7[1] == "susan" && f7[2] == "");

    string mx[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string my[4] = { "martha", "mark", "lindsey", "sara" };
    assert(differ(mx, 4, my, 4) == 2);
    assert(differ(mx, 7, my, 4) == 2);
    assert(differ(mx, 0, my, 4) == 0);
    assert(differ(mx, -1, my, 4) == -1);
    assert(differ(mx, 4, my, -4) == -1);
    assert(differ(mx, 0, my, 0) == 0);
    string mx1[6] = { "donald", "mike", "", "susan", "sara", "jamie" };
    string my1[5] = { "donald", "mike", "jamie", "", "susan" };
    assert(differ(mx1, 6, my1, 5) == 2);
    assert(differ(mx1, 2, my1, 1) == 1);
    string mx2[0] = { };
    string my2[5] = { "donald", "mike", "jamie", "", "susan" };
    assert(differ(mx2, 0, my2, 5) == 0);
    string mx3[5] = { "donald", "mike", "jamie", "susan", "sara" };
    string my3[5] = { "donald", "mike", "jamie", "susan", "sara" };
    assert(differ(mx3, 5, my3, 5) == 5);

    string nx[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string ny[4] = { "joe", "susan", "", "kamala" };
    assert(subsequence(nx, 7, ny, 4) == 2);
    assert(subsequence(nx, 6, ny, 3) == 2);
    assert(subsequence(nx, 5, ny, 4) == -1);
    string nx1[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
    string ny1[10] = { "mark", "sara", "martha" };
    assert(subsequence(nx1, 6, ny1, 3) == 1);
    string ny2[10] = { "kamala", "martha" };
    assert(subsequence(nx, 5, ny2, 2) == -1);
    assert(subsequence(nx1, 0, ny1, -3) == -1);
    assert(subsequence(nx1, 0, ny1, 0) == 0);
    assert(subsequence(nx1, 9, ny1, 0) == 0);
    assert(subsequence(nx1, 0, ny1, 1) == -1);
    assert(subsequence(nx1, 2, ny1, 3) == -1);
    string nx3[10] = { "kamala", "mark", "liz", "martha", "donald", "lindsey" };
    string ny3[10] = { "mark", "sara", "martha" };
    assert(subsequence(nx3, 6, ny3, 3) == -1);
    string nx4[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
    string ny4[10] = { "donald", "lindsey", "martha" };
    assert(subsequence(nx4, 6, ny4, 3) == -1);
    string nx5[10] = { "kamala", "mark", "sara", "kamala", "mark", "lindsey" };
    string ny5[10] = { "kamala", "mark", "lindsey" };
    assert(subsequence(nx5, 6, ny5, 2) == 0);
    assert(subsequence(nx5, 6, ny5, 3) == 3);
    string nx6[10] = { "kamala", "mark", "sara", "kamala", "mark", "lindsey" };
    string ny6[10] = { "kamala", "sara", "kamala" };
    assert(subsequence(nx6, 6, ny6, 3) == -1);

    string ox[10] = { "kamala", "mark", "sara", "martha", "donald", "lindsey" };
    string oy[10] = { "jamie", "donald", "martha", "mark" };
    assert(lookupAny(ox, 6, oy, 4) == 1);
    string oy1[10] = { "susan", "joe" };
    assert(lookupAny(ox, 6, oy1, 2) == -1);
    string ox2[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string oy2[3] = { "lindsey", "joe", "mike" };
    assert(lookupAny(ox2, 7, oy2, 3) == 2);
    assert(lookupAny(ox2, 3, oy2, 0) == -1);
    assert(lookupAny(ox2, 0, oy2, 0) == -1);
    assert(lookupAny(ox2, -1, oy2, 3) == -1);
    assert(lookupAny(ox2, 7, oy2, 1) == 6);
    assert(lookupAny(ox2, 6, oy2, 1) == -1);
    string ox3[7] = { "", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string oy3[3] = { "lindsey", "", "mike" };
    assert(lookupAny(ox3, 7, oy3, 3) == 0);
    string ox4[7] = { "", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string oy4[3] = { "dory", "rath", "amy" };
    assert(lookupAny(ox4, 7, oy4, 3) == -1);

    string p[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(divide(p, 7, "lindsey") == 3);
    assert(divide(p, 0, "lindsey") == 0);
    string p1[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    assert(divide(p1, 1, "lindsey") == 0);
    assert(divide(p1, -11, "lindsey") == -1);
    string p2[7] = { "martha", "mark", "joe", "susan", "", "kamala", "lindsey" };
    string p3[6] = { "jamie", "lindsey", "mark", "susan", "joe", "donald" };
    assert(divide(p3, 6, "kamala") == 3);
    string p4[4] = { "mark", "sara", "lindsey", "mike" };
    assert(divide(p4, 4, "mike") == 2);
    string p5[4] = { "mark", "sara", "lindsey", "mike" };
    assert(divide(p5, 3, "mike") == 2 && p5[3] == "mike");
    string p6[3] = { "a", "a", "a" };
    assert(divide(p6, 3, "a") == 0);
    string p7[3] = { "a", "a", "a" };
    assert(divide(p7, 3, "b") == 3);
    string p8[3] = { "b", "b", "b" };
    assert(divide(p8, 3, "a") == 0);
    string p9[3] = { "c", "b", "a" };
    assert(divide(p9, 3, "c") == 2 && p9[0] == "a" && p9[1] == "b" && p9[2] == "c");
    string p10[3] = { "c", "b", "a" };
    assert(divide(p10, 2, "c") == 1 && p10[0] == "b" && p10[1] == "c" && p10[2] == "a");

    cout << "All tests succeeded" << endl;
}

//adds string value to each element in the array specifed by n
int appendToAll(string a[], int n, string value){
    if (n < 0){
        return -1;
    } else {
        for (int i=0; i<n; i++){
            a[i] += value;
        }
        return n;   //returns n when done
    }
}

//looks for string target in array specified by n, returns position in array i of the target
int lookup(const string a[], int n, string target){
    if (n < 0){
        return -1;
    } else {
        for (int i=0; i<n; i++){
            if (a[i] == target){
                return i;
            }
        }
        return -1;  //if target isn't present, returns -1
    }
}

//returns position of the element >= all other elements
int positionOfMax(const string a[], int n){
    if (n <= 0){    //returns -1 if there's no interesting elements (n=0)
        return -1;
    } else {
        string max = a[0];  //sets string max to first element in array at first
        int pos = 0;
        for (int i=0; i<n; i++){
            if (a[i] > max){    //compares each element to current max element
                max = a[i]; // updates max to current max element
                pos = i;    //updates position to position i of the max element
            }
        }
        return pos;     //returns position of the max element
    }
}

//shifts all elements to the left starting with the element one to the right of the given int position, moves the replaced element at pos to the end of the array specified by n
int rotateLeft(string a[], int n, int pos){
    if (n <= 0){
        return -1;      //returns -1 if negative n OR if n=0, because then pos will > n which is accessing the array out of the bounds specified by n
    } else {
        if(pos >= 0 && pos < n){    //checks if pos is in bounds specified for the array
            string tempStr = a[pos];
            for (int i=pos; i<n - 1; i++){  //shifts all elements after specified pos one to the left
                a[i] = a[i+1];
            }
            a[n-1] = tempStr;        //replaces last element with the replaced element originally at pos
            return pos; //returns pos when done
        } else {
            return -1;  //returns -1 if pos is out of bounds specified
        }
    }
}
    
//returns the number (count) of consecutive, identical sequences >= 1 element(s)
int countRuns(const string a[], int n){
    if (n < 0){
        return -1;
    } else {
        int count = 0;
        for (int i=0; i<n-1; i++){
            if (a[i] != a[i+1]){
                count++;    //adds one to the count by comparing the current element with the one to the right
            }
        }
        if (n != 0){
            count++;    //addresses fencepost error: if n>0, adds one to count for last element in array specified by n
            return count;   //returns count
        } else {
            return 0;   //if n=0, there are 0 consecutive identical sequences of >= 1 element(s)
        }
    }
}

//reverses the order of the array and returns n
int flip(string a[], int n){
    if (n < 0){
        return -1;
    } else {
        for (int i=0; i<n/2; i++){   //only iterates through first half, because the second half gets flipped too
            string tempStr = a[i];  //stores string in a temporary variable first before replacing a[i]
            a[i] = a[n-1-i];    //swaps element a[i] and its corresponding match on the other end of the array
            a[n-1-i] = tempStr;
        }
        return n;
    }
}

//returns the pos of the first corresponding elements of arrays a1 and a2 that aren't equal; if they're equal up until the end of at least one, returns the smaller n1 or n2 value
int differ(const string a1[], int n1, const string a2[], int n2){
    if (n1 < 0 || n2 < 0){
        return -1;
    } else {
        int smallerN;
        if (n1 <= n2){  //compares whether n1 or n2 is smaller value
            smallerN = n1;
        } else {
            smallerN = n2;
        }
        for (int i=0; i<smallerN; i++){
            if (a1[i] != a2[i]){    //compares the corresponding elements of a1 and a2
                return i;   //returns the earliest pos of differing corresponding elements
            }
        }
        return smallerN;
    }
}

//returns earliest beginning pos of a1 in which a2 appears consecutively and completely
int subsequence(const string a1[], int n1, const string a2[], int n2){
    if (n1 < 0 || n2 < 0){
        return -1;
    } else {
        if (n2 == 0){   //treats an empty array as a subsequence of any array starting at pos 0
            return 0;
        }
        if (n1 == 0 || n2>n1){  //if n1=0 and n2 doesn't equal zero OR if a2 is longer than a1, then a1 can't contain subsequence a2, so returns -1
            return -1;
        }
        bool isSubseq = false;  //stores whether subseq is present or not, updates as program iterates through the array
        for (int i=0; i<n1; i++){
            if (a2[0] == a1[i]){
                isSubseq = true;
                int pos = i;
                for (int j=0; j<n2; j++){
                    if ((i+j) >= n1){   //checks to make sure a1 doesn't access out of bounds element, returns -1 if it does
                        isSubseq = false;
                        return -1;
                    } if (a1[i+j] != a2[j]){
                        isSubseq = false;   //updates subseq again if there is any discrepancy between the two arrays as it iterates through both
                    }
                }
                if (isSubseq){
                    return pos; //return position in a1 where subsequence begins
                }
            }
        }
        return -1;  //if no subsequence present in a1, returns -1
    }
}

//returns smallest position of a1 that is equal to any element in a2
int lookupAny(const string a1[], int n1, const string a2[], int n2){
    if (n1 <= 0 || n2 <= 0){    //if either n1 or n2 is negative or =0, then there is no way they will contain equal elements (a1 and a2, respectively), so returns -1
        return -1;
    } else {
        for (int i=0; i<n1; i++){
            for (int j=0; j<n2; j++){
                if (a1[i] == a2[j]){
                    return i;   //if there's a match, returns earliest pos i that match occurs in a1
                }
            }
        }
        return -1;  //returns -1 if no match after iterating through a1
    }
}

//rearranges string so that elements <string divider will come before elements >divider, returns first position of element that isn't <divider, or n if they're all <divider
int divide(string a[], int n, string divider){
    if (n < 0){
        return -1;
    } else {
        int countLessThan = 0;
        for (int i=0; i<n; i++){
            if (a[i] < divider){
                countLessThan++;    //adds one for each element in array specified by n that is less than the divider, this will be the position of the first element that isn't <divider
            }
        }
        for (int j=0; j<n; j++){    //bubble sort from least to greatest (increasing order), iterates through n times
            for (int i=0; i<n-1; i++){
                if (a[i] > a[i+1]){     //swaps elements one-by-one if they're not in the correct order
                    string tempStr = a[i];
                    a[i] = a[i+1];
                    a[i+1] = tempStr;
                }
            }
        }
        if (countLessThan < n){
            return countLessThan;   //returns first position of element that isn't <divider
        } else {    //if all elements are <divider OR n=0, return n
            return n;
        }
    }
}

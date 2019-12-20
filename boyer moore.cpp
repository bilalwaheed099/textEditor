#include <iostream>
#include <bits/stdc++.h>

using namespace std;
# define NO_OF_CHARS 256

void badCharHeuristic( string str, int size,
                       int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int) str[i]] = i;
}

int * search( string txt, string pat)
{
    int counter = 0;
    static int array[10];
    for (int i=0;i<10;i++){
        array[i]=-1;
    }

    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;

    while(s <= (n - m))
    {
        int j = m - 1;

        while(j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            counter++;
            array[counter-1]=s;

            s += (s + m < n)? m-badchar[txt[s + m]] : 1;

        }

        else
            s += max(1, j - badchar[txt[s + j]]);
    }


    return array;
}

void search_position(string txt, string pat_search){
    int *p = search(txt,pat_search);
    for(int i=0; i<10 ; i++){
        if(p[i]>-1)  {
            cout<<p[i]<<endl;
        }
        }
}

void replace_string(string txt, string pat_search, string pat_replace){

    int *p = search(txt,pat_search);

    for(int i=0; i<10 ; i++){
    if(p[i]>-1)  {
        txt.replace(p[i],pat_search.size(),pat_replace);
    }
    }

    for (int i = 0 ; i<=txt.size() ; i++){
        cout << txt[i];
    }
}
///* Driver code */
//int main()
//{
//    string txt= "ABAAABCDABCE";
//    string pat = "ABC";
//    string rep = "DEF";
//
//    search_position(txt,pat);
//
//    replace_string(txt,pat,rep);
//    return 0;
//}

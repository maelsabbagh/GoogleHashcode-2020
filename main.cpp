#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5;
vector<int> scores;

struct lib
{
    int numOfBooks;
    int daysToSign;
    int BPD;
    int id;
    vector<pair<int, int>> bookIDs;
    set<int>UsedBooks;
    long long maxScore = 0;
    long long ActualScore =0;
    int maxNumOfBooks;
    double rat = 0;
};

set<int>Used;
bool comp(lib l1, lib l2)
{
    return (l1.rat>l2.rat && l1.daysToSign < l2.daysToSign);
}

int l, b, d;

int main()
{
    freopen("a_example.txt", "r", stdin);
	freopen("a.txt", "w", stdout);

    cin>>b>>l>>d;
    int days = d;
    //cout<<b<<" "<<l<<" "<<d<<endl;

    int x;
    for(int i=0;i<b;i++){
        cin>>x;
        //cout<<x<<" ";
        scores.push_back(x);
    }
    //cout<<endl;

    vector<lib> libs(l);

    for(int i=0;i<l;i++){
        cin>>libs[i].numOfBooks>>libs[i].daysToSign>>libs[i].BPD;
        libs[i].id = i;
        //cout<<libs[i].numOfBooks<<" "<<libs[i].daysToSign<<" "<<libs[i].BPD<<endl;
        for(int j=0;j<libs[i].numOfBooks;j++){
            cin>>x;
            //cout<<x<<" ";
            libs[i].bookIDs.push_back(make_pair(scores[x], x));
        }
        //cout<<endl;

        libs[i].maxNumOfBooks = (d - libs[i].daysToSign) * libs[i].BPD;

        sort(libs[i].bookIDs.rbegin(), libs[i].bookIDs.rend());

        for(int j=0;j< min(libs[i].maxNumOfBooks, libs[i].numOfBooks);j++){
            libs[i].maxScore += libs[i].bookIDs[j].first;
        }

        libs[i].rat = (float)libs[i].maxScore / libs[i].daysToSign;


        /*
        for(int j=0;j<libs[i].bookIDs.size();j++){
            cout<<libs[i].bookIDs[j].first<<" "<<libs[i].bookIDs[j].second<<"\n";
        }
        */
    }

    sort(libs.begin(), libs.end(), comp);

    int i = 0;
    while(d > 0 && i< l)
    {
        d -= libs[i].daysToSign;
        if(d > 0)
            i++;
        else
            break;
    }

    cout<<i<<endl;

    int start = 0;
    int remain;

    for(int j=0;j<i;j++){

        start += libs[j].daysToSign;
        remain = days - start;

        unsigned long long no_of_books = remain * libs[j].BPD;
        no_of_books = min((unsigned long long)libs[j].numOfBooks, no_of_books);

        //if(no_of_books < 0)
        cout << libs[j].id << " ";
        cout << no_of_books << "\n";
        int z = 0;
        int w =0;
        bool Cycle = false;
        while(w < no_of_books)
        {
            if(Used.find(libs[j].bookIDs[z].second) == Used.end() || Cycle)
            {
                if(libs[j].UsedBooks.find(libs[j].bookIDs[z].second) ==libs[j].UsedBooks.end())
                {
                    cout << libs[j].bookIDs[z].second << " ";
                    Used.insert(libs[j].bookIDs[z].second);
                    libs[j].UsedBooks.insert(libs[j].bookIDs[z].second);
                    w++;
                }
            }

            z = (z +1) % libs[j].numOfBooks ;

            if(z == 0)
            {
                Cycle = true;
            }

            //libs[j].ActualScore += libs[j].bookIDs[z].second;
        }
        cout << endl;

    }




    /*
    for(int i=0;i<libs.size();i++){
        cout<<libs[i].rat<<" "<<libs[i].id<<"\n";
    }
    */


    return 0;
}


long long Solve(int Day,int i)
{

}


// codejamQualif.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Activity {
    int start;
    int end;
    Activity(int start, int end) : start(start), end(end) {}

    bool overlaps(Activity& other) {
        return 
            //   xxxxx
            //xxxxx
            (other.end > start&& other.end <= end) 
            //xxxxx
            //   xxx
            || (other.start >= start && other.start < end) 
            //  xxx
            //xxxxxxx
            || (other.start <= start && other.end >= end);
    }
};
struct Solution { 
    vector<Activity> C;
    vector<Activity> J;
    string solution;

       static bool canAddActivity(vector<Activity>& v, Activity& ac) {
        for (Activity& a : v) {
            if (a.overlaps(ac)) return false;
        }
        return true;
    }
};

string getSolutionRec(vector<Activity>& activities, int nextActivityInd, Solution curSolution, bool addToC) {
    if (nextActivityInd >= activities.size()) return curSolution.solution;

    Activity ac = activities[nextActivityInd];
    //add and verif
    if (addToC) {
        if (Solution::canAddActivity(curSolution.C, ac)) {
            curSolution.C.push_back(ac);
            curSolution.solution += "C";
        }
        else return "IMPOSSIBLE";
    }
    else {
        if (Solution::canAddActivity(curSolution.J, ac)) {
            curSolution.J.push_back(ac);
            curSolution.solution += "J";
        }
        else return "IMPOSSIBLE";
    }

    
    string res = getSolutionRec(activities, nextActivityInd + 1, curSolution, true);
    if (res != "IMPOSSIBLE") return res;

    return getSolutionRec(activities, nextActivityInd + 1, curSolution, false);
}

string getSolution(vector<Activity>& activities) {
    Solution s = Solution();
    string res = getSolutionRec(activities, 0, s, true);
    if (res != "IMPOSSIBLE") return res;

    return getSolutionRec(activities, 0, s, false);
}

int main()
{
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        int N;
        cin >> N;
        vector<Activity> ac;
        for (int activity = 0; activity < N; activity++) {
            int start, end;
            cin >> start >> end;
            ac.push_back(Activity(start, end));
        }
        
        cout << "Case #" + to_string(t) + ": " << getSolution(ac) << endl;
    }
}

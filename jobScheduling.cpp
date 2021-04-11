
//  choose jobs for maximum profits within deadline..

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct job {
    char name;
    int profit;
    int deadline;
};

void getInput(job arr[], int n){
    for(int i=0; i<n; i++) {
        cout << "Enter the (name, profit, deadline) for this job : ";
        cin >> arr[i].name >> arr[i].profit >> arr[i].deadline;
    }
    cout << endl;   
}

bool sortBydesc(job a, job b) {
    return (a.profit > b.profit);
}

int schedule(job arr[], int n){
    // sorting array with respect to profit..
    sort(arr, arr+n, sortBydesc);

    int profit = 0;
    vector<char> res;             // result array..
    bool slot[n];            // slots to keep track of free..

    // initialising all slots as free..
    for(int i=0; i<n; i++) {
        slot[i] = false;
    }

    for(int i=0; i<n; i++) {
        for(int j=min(n, arr[i].deadline)-1; j>=0; j--) {
            //  if free slot found
            if(!slot[j]) {
                res.push_back(arr[i].name);
                profit += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }

    cout << " (";
    for(int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout <<") ";
    return profit;
}

int main() {
    // job arr[] = {
    //     {'a', 100, 2}, 
    //     {'b', 19, 1},
    //     {'c', 27, 2},
    //     {'d', 25, 1},
    //     {'e', 15, 3} 
    // };

    int n;
    cout << "Enter number of Jobs : ";
    cin >> n;
    job arr[n];
    getInput(arr, n);

    int sum = schedule(arr, n);
    cout << "following are selected work with maximim profit of " << sum << endl;

    return 0;
}

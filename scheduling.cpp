
// maximum number of activities are possible with given set of activities...  

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class schedule {
    public:
        void getInput(int arr1[], int arr2[], int n){
            for(int i=0; i<n; i++){
                cout << " Enter START and END time of this activity : ";
                cin >> arr1[i] >> arr2[i];
            }
        }

        void display(vector<pair<int, int>> v){
            for(int i=0; i<v.size(); i++){
                cout << "(" << v[i].first << " " << v[i].second << ") ";
            }
            cout << "\n";
        }

        void createSchedule(vector<pair<int, int>> v){
            int i=0;
            cout<< "(" <<v[i].first<< ", "<<v[i].second << ") \n"; 
            for (int j = 1; j < v.size(); j++) { 
                if (v[j].first >= v[i].second) {	 
                    cout<< "(" <<v[j].first<< ", "<<v[j].second << ") \n"; 
                    i = j; 
                } 
            }
        }
};

bool sortByInc(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second < b.second);
}

int main() {

    // int arr1[] = {5, 1, 3, 0, 5, 8};
    // int arr2[] = {9, 2, 4, 6, 7, 9};
    int n;
    cout << "Enter number of activities : ";
    cin >> n;
    int arr1[n], arr2[n];

    schedule obj;    
    obj.getInput(arr1, arr2, 6);
    
    //  make vector pair..
    vector< pair<int, int> > v;
    for(int i=0; i<6; i++){
        v.push_back(make_pair(arr1[i], arr2[i]));
    }

    sort(v.begin(), v.end(), sortByInc);
    cout << "\nAfter Sorting : ";
    obj.display(v);
    cout << "Selected Activities in order : \n";
    obj.createSchedule(v);


    return 0;
}
#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100; // Assuming a maximum size for arrays A and B
    int n1, n2, i, j,r;
    int A[MAX_SIZE], B[MAX_SIZE];
    
    cout << "Enter the no. of elements in the set A : ";
    cin >> n1;
    cout << "Enter the no. of elements in the set B : ";
    cin >> n2;

    cout << "Enter the members of the set A" << endl;
    for (i = 0; i < n1; i++) {
        cout << "Element " << i + 1 << " = ";
        cin >> A[i];
    }

    cout << "Enter the members of the set B" << endl;
    for (i = 0; i < n2; i++) {
        cout << "Element " << i + 1 << " = ";
        cin >> B[i];
    }

    // Union of A and B
    cout << "Union of set A and B: {";
    for (i = 0; i < n1; i++) {
        if (i > 0) cout << ",";
        cout << A[i];
    }
    for(i=0;i<n2;i++) {
    
        for(j=0;j<n1;j++) {
            if (A[j]==B[i]) {
                r=1;
                break;
            }
            r=0;
        }
        if (r==0) {
            cout << "," << B[i];
        }
    }
    cout << "}" << endl;

    // Intersection of A and B
    cout << "Intersection of set A and B: {";
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                cout << A[i];
                if (i < n1 - 1) cout << ",";
                break;
            }
        }
    }
    cout << "}" << endl;

    // Difference A - B
    
    cout<<"Difference A - B: {";
    for(i=0;i<n1;i++) {
        r=0;
        for(j=0;j<n2;j++) {
            if (A[i] == B[j]) {
                r=1;
                break;
            }
        }
        if (r==0) {
            cout << A[i];
            if (i<n1-1)cout<<",";
        }
    }
    cout<<"}"<<endl;

    return 0;
}

#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    int N, F;
    ifstream in("spacein.txt");
    in >> N >> F;
    vector<int> fuelCosts(N);
    for (int i = 0; i < N; ++i)
    {
        in >> fuelCosts[i];
    }
    in.close();

    // Create a vector for the minimum costs from each day to the last day
    vector<int> minCostFromDay(N);
    minCostFromDay[N - 1] = fuelCosts[N - 1];
    for (int i = N - 2; i >= 0; --i)
    {
        minCostFromDay[i] = min(fuelCosts[i], minCostFromDay[i + 1]);
    }

    int maxSamples = -1;
    int launch = 0, returnDay = 1;
    int currentMinCost = numeric_limits<int>::max();

    while (launch < N - 1)
    {
        // Find the farthest returnDay where the total fuel cost is within the
        // limit
        while (returnDay < N &&
               fuelCosts[launch] + minCostFromDay[returnDay] <= F)
        {
            returnDay++;
        }

        // Check if the previous condition was true for at least one returnDay >
        // launch
        if (returnDay >
            launch + 1)  // returnDay is now one ahead of the actual date
        {
            maxSamples = max(maxSamples, returnDay - launch);
            printf("launch=%d,return=%d\n", launch, returnDay);
        }

        launch++;
        if (returnDay <= launch)
        {  // Make sure returnDay is always ahead of launch
            returnDay = launch + 1;
        }
    }

    ofstream out("spaceout.txt");
    out << maxSamples << endl;
    out.close();
    return 0;
}
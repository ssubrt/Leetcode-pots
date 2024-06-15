------------------->>>>>>>>>>>>>>>>>> Approach <<<<<<<<<<<<<<<<<<<<<<<<<------------------------
//  time complexity of the given code is O(n log n + k log n)

// space complexity of the given code is O(n)


struct Project {
    int capital;
    int profit;
};

// Comparator for max heap (priority queue)
struct MaxProfitComparator {
    bool operator()(const Project& p1, const Project& p2) {
        return p1.profit < p2.profit;
    }
};

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    int n = Profits.size();
    vector<Project> projects(n);
    
    // Populate the projects array
    for (int i = 0; i < n; ++i) {
        projects[i] = {Capital[i], Profits[i]};
    }
    
    // Sort projects by capital ascending
    sort(projects.begin(), projects.end(), [](const Project& p1, const Project& p2) {
        return p1.capital < p2.capital;
    });
    
    // Priority queue (max heap) to store profits of projects that can be started
    priority_queue<Project, vector<Project>, MaxProfitComparator> maxHeap;
    
    int currentCapital = W;
    int index = 0;
    
    // Process up to k projects
    for (int i = 0; i < k; ++i) {
        // Add all projects that we can currently start to the max heap
        while (index < n && projects[index].capital <= currentCapital) {
            maxHeap.push(projects[index]);
            index++;
        }
        
        // If there are no projects that can be started
        if (maxHeap.empty()) {
            break;
        }
        
        // Select the project with maximum profit that we can start
        Project topProject = maxHeap.top();
        maxHeap.pop();
        
        // Update current capital
        currentCapital += topProject.profit;
    }
    
    return currentCapital;
}
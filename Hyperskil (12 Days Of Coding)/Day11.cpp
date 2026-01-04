#include<bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    int duration;
    vector<int> successors; // Tasks that depend on this one
    int in_degree = 0;      // Number of dependencies this task has
    long long cp_score = -1; // Critical Path length from this node to the end
};

map<int, Task> tasks;

// Recursively calculate Critical Path (Bottom Level)
// CP = Duration + Max(CP of all successors)
long long get_cp(int u) {
    if (tasks[u].cp_score != -1) return tasks[u].cp_score;
    
    long long max_next = 0;
    for (int v : tasks[u].successors) {
        max_next = max(max_next, get_cp(v));
    }
    
    tasks[u].cp_score = tasks[u].duration + max_next;
    return tasks[u].cp_score;
}

// Comparator for Priority Queue (Max Heap based on CP Score)
struct CompareReady {
    bool operator()(int a, int b) {
        // We want the task with the HIGHER cp_score to be popped first.
        // In C++ priority_queue, if compare(a,b) is true, a is ordered "below" b.
        // So if cp_score[a] < cp_score[b], b goes to top.
        if (tasks[a].cp_score != tasks[b].cp_score) {
            return tasks[a].cp_score < tasks[b].cp_score;
        }
        // Tie-breaker: usually lower ID first helps stability, 
        // though not strictly required unless specified.
        return tasks[a].id > tasks[b].id; 
    }
};

int main() {
    // 1. Parse Input
    string line;
    while (cin >> line) {
        // Replace commas with spaces for easy parsing
        for (char &c : line) if (c == ',') c = ' ';
        
        stringstream ss(line);
        int id, dur;
        string deps;
        ss >> id >> dur >> deps;
        
        if (tasks.find(id) == tasks.end()) tasks[id].id = id;
        tasks[id].duration = dur;
        
        // Handle dependencies
        if (deps != "none") {
            for (char &c : deps) if (c == ':') c = ' ';
            stringstream ss_deps(deps);
            int dep_id;
            while (ss_deps >> dep_id) {
                // Determine graph direction:
                // Input: "5, 20, 2:3" -> 5 requires 2 and 3.
                // Graph: 2 -> 5, 3 -> 5. 
                // 5 is a successor of 2.
                if (tasks.find(dep_id) == tasks.end()) tasks[dep_id].id = dep_id;
                tasks[dep_id].successors.push_back(id);
                tasks[id].in_degree++;
            }
        }
    }

    // 2. Calculate Critical Path Scores for all nodes
    for (auto &pair : tasks) {
        get_cp(pair.first);
    }

    // 3. Initialize Scheduler
    // Priority Queue holds tasks that are ready (in_degree == 0), ordered by CP score
    priority_queue<int, vector<int>, CompareReady> ready_pq;
    
    for (auto &pair : tasks) {
        if (pair.second.in_degree == 0) {
            ready_pq.push(pair.first);
        }
    }

    // Min-heap for events: {finish_time, task_id}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> events;
    
    long long current_time = 0;
    int active_workers = 0;
    int max_workers = 11;
    int total_tasks = tasks.size();
    int finished_tasks = 0;

    // 4. Run Simulation
    while (finished_tasks < total_tasks) {
        // Assign free workers to ready tasks
        while (active_workers < max_workers && !ready_pq.empty()) {
            int u = ready_pq.top();
            ready_pq.pop();
            
            // Task starts now, finishes at current_time + duration
            events.push({current_time + tasks[u].duration, u});
            active_workers++;
        }

        // If no workers exist (and we aren't done), we must wait for the next event
        if (events.empty()) {
            if (finished_tasks < total_tasks) {
                // This shouldn't happen in a valid connected DAG unless ready_pq is empty but workers are busy
                break; 
            }
        }

        // Fast forward to the next finishing task
        long long next_finish_time = events.top().first;
        current_time = next_finish_time;

        // Process all tasks finishing at this exact time
        while (!events.empty() && events.top().first == current_time) {
            int finished_u = events.top().second;
            events.pop();
            active_workers--;
            finished_tasks++;

            // Unlock successors
            for (int v : tasks[finished_u].successors) {
                tasks[v].in_degree--;
                if (tasks[v].in_degree == 0) {
                    ready_pq.push(v);
                }
            }
        }
    }

    cout << current_time << endl;

    return 0;
}
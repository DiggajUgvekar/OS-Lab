#include <iostream>
using namespace std;
class sequencing {
 int burst_time;
 int arrival_time;
 int waiting_time;
 int turnaround_time;
 int status;
 int priority;
 int remaining_time;
public:
 void input(int);
 void nonPreemptivePriority(int, sequencing[]);
 void output(int);
 int minimum(int, sequencing[]);
};
#define pending 1
#define finished 2
void sequencing::input(int i) {
 cout << "\n<< P[" << i + 1 << "] >>\nBURST TIME : ";
 cin >> burst_time;
 cout << "ARRIVAL TIME : ";
 cin >> arrival_time;
 cout << "PRIORITY : ";
 cin >> priority;
 status = pending;
 remaining_time = burst_time;
}

void sequencing::output(int i) {
 cout << "P[" << i + 1 << "] \t" << burst_time << "\t\t" << arrival_time << " \t" <<
waiting_time << "\t\t" << turnaround_time << "\t\t" << priority << endl;
}
void sequencing::nonPreemptivePriority(int n, sequencing p[]) {
    int total_time = minimum(n, p);
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    cout << "\nGantt Chart:" << endl;
    cout << total_time;
    while (true) {
        int lowest_priority = 9999;  
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (p[j].status == pending && p[j].arrival_time <= total_time) {
                if (p[j].priority < lowest_priority) {
                    k = j;
                    lowest_priority = p[j].priority;
                }
            }
        }
        if (k == -1) {
            total_time++;
            continue;
        }
        total_time += p[k].burst_time;
        p[k].status = finished;
        p[k].turnaround_time = total_time - p[k].arrival_time;
        avg_turnaround_time += p[k].turnaround_time;
        p[k].waiting_time = p[k].turnaround_time - p[k].burst_time;
        avg_waiting_time += p[k].waiting_time;
        cout << "|__P[" << k + 1 << "]__|" << total_time;
        int if_finished = 1;
        for (int i = 0; i < n; i++) {
            if (p[i].status == pending) {
                if_finished = 0;
                break;
            }
        }

        if (if_finished)
            break;
    }
    cout << "\n";
    cout << "\nAVERAGE WAITING TIME : " << avg_waiting_time / n;
    cout << "\nAVERAGE TURNAROUND TIME : " << avg_turnaround_time / n << endl;
}

int sequencing::minimum(int n, sequencing p[]) {
 int min = 9999;
 for (int i = 0; i < n; i++) {
 if (p[i].arrival_time < min)
 min = p[i].arrival_time;
 }
 return min;
}
int main() {
 int n;
 cout << "ENTER THE NUMBER OF JOBS : ";
 cin >> n;
 sequencing *p;
 p = new sequencing[n];
 for (int i = 0; i < n; i++)
 p[i].input(i);
 sequencing x;
 x.nonPreemptivePriority(n, p);
 cout << "\nPROCESS BURST TIME ARRIVAL TIME WAITING TIME TURNAROUND TIME PRIORITY:\n";
 for (int i = 0; i < n; i++)
 p[i].output(i);
 return 0;
}

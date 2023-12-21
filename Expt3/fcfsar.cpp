#include<bits/stdc++.h>

using namespace std;

void input_burst_time(int n ,int burst_time[]){
cout<<"Enter Burst Time"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>burst_time[i];
    }
}

void input_arrival_time(int n ,int arrival_time[]){
cout<<"Enter Arrival Time"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arrival_time[i];
    }
}
void calculate_cp(int n,int burst_time[],int arrival_time[],int cp_time[]){
    cp_time[0] = arrival_time[0];
    cp_time[1] = arrival_time[0]+ burst_time[0];
    for(int i = 2; i <= n; i++){
    cp_time[i] = cp_time[i-1] + burst_time[i-1];
    }
}

void calculate_waiting(int n ,int wt_time[],int cp_time[],int arrival_time[]){
    wt_time[0]=0;
    for (int i = 1; i < n; i++)
    {
        wt_time[i]= cp_time[i] - arrival_time[i];
    }
    cout<<endl;
}

void calulate_turn_around(int n , int wt_time[],int burst_time[],int turn_around[]){
    for (int i = 0; i < n; i++)
    {
        turn_around[i] = wt_time[i] + burst_time[i];
    }
    cout<<endl;
}

void display(int n,int wt_time[],int turn_around[]){
    cout<<"Waiting time of processes"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<wt_time[i]<<"  ";
    }
     cout<<"\nTurn around time of processes"<<endl;
      for (int i = 0; i < n; i++)
    {
        cout<<turn_around[i]<<"  ";
    }
    cout<<"\n";
}
void gchart(int n ,int burst_time[],int cp_time[]){
    cout<<"\nGantt Chart:"<<endl;
    int current_time = 0;
    int size=3;
    for (int i = 0; i < n*7; i++)
    {
        cout<<'-';
    }
    cout<<'-';
    cout<<endl;
    cout<<"|  ";
    for (int i = 0; i < n; i++)
    {
        cout<<'p'<<i+1<<"  |  ";
    }
    cout<<"\n";
    for (int i = 0; i < n*7; i++)
    {
        cout<<'-';
    }
    cout<<'-';
    cout<<endl;
     for (int i = 0; i <= n; i++)
    {
        cout<<cp_time[i]<<"      ";
    }

    cout<<"\n";
}

void avg_tat(int n,int turn_around[],int wt_time[]){
    float avg_sum =0.0;
    float avg_wt = 0.0;
    for (int i = 0; i < n; i++)
    {
            avg_sum += turn_around[i];
            avg_wt +=  wt_time[i];
    }

    cout<< "\nAverage waiting time is "<<(avg_wt/n)<<endl;
    cout<< "\nAverage Turn around time is "<<(avg_sum/n)<<endl;
}


int main(){
    int n; //no of processes

    //take input
    cout<<"Enter no of processes : "<<endl;
    cin>>n;

    int burst_time[n]={0};
    input_burst_time(n,burst_time);
    int arrival_time[n]={0};
    input_arrival_time(n,arrival_time);

    int cp_time[n]={0};
    calculate_cp(n,burst_time,arrival_time,cp_time);
    int wt_time[n]={0};
    calculate_waiting(n,wt_time,cp_time,arrival_time);

    int turn_around[n]={0};
    calulate_turn_around(n,wt_time,burst_time,turn_around);

    //dispalys wt and tat

    display(n,wt_time,turn_around);
    cout<<"\n";
    //calulate and display average

    avg_tat(n,turn_around,wt_time);
    cout<<"\n";
    //display gantt chart

    gchart(n,burst_time,cp_time);

}

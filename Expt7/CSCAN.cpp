#include <bits/stdc++.h>
#include <iostream>
#include<vector>

using namespace std;

int scan(vector<int> &rq, int current_head,int limit) {
    int head = current_head, distance;
    vector<int> seq;
    sort(rq.begin(), rq.end());
    auto it = lower_bound(rq.begin(), rq.end(), head);
    int mid = *it;
    int midPos;
    int var=1;
    while(var==1){
         if (head < *it) {
        midPos = it - rq.begin();
        var=0;
    } else {
        ++it;
        midPos = it - rq.begin();
    }
    }


    for (int i = midPos; i < rq.size(); i++) {
        distance += abs(rq[i] - current_head);
        if(i == rq.size()-1){
            distance+=abs(rq[rq.size()-1]-limit)+limit;
            current_head=0;
            seq.push_back(rq[i]);
            seq.push_back(limit);
            seq.push_back(0);
        }else{
            current_head = rq[i];
            seq.push_back(rq[i]);
        }
    }
    for(int i=0;i<midPos;i++){
         distance += abs(rq[i] - current_head);
        current_head = rq[i];
        seq.push_back(rq[i]);
    }
    cout << "Seek sequence is: " << head << "-->";
    for (int i = 0; i < seq.size(); i++) {

        if (i == seq.size() - 1) {
            cout << seq[i];
        }else{
            cout << seq[i] << "-->";
        }
    }

    cout << endl;

    return distance;  // Return the total seek distance
}

int main() {
//    vector<int> requests = {75, 90, 40, 135, 50, 170, 65, 10};
//    int current_head = 45;
	int qsize,current_head;
		cout <<"enter the queue size:";
		cin>>qsize;
		vector<int> requests;
		requests.resize(qsize);
		cout<<"enter the values of request queue"<<endl;
		for(int i =0;i<qsize;i++){
			cin>>requests[i];
		}
		cout<<"enter the current pos of head"<<endl;
		cin>>current_head;
    int limit;
    cout<<"enter the limt of the memory"<<endl;
    cin>>limit;
    int seek_distance = scan(requests, current_head,limit);

    cout << "Total seek distance: " << seek_distance << endl;

    return 0;
}


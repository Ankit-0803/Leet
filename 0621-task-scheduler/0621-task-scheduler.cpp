class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       int x=tasks.size();
       vector<int>freq(26,0);
       //count frequencies of all the tasks
       for(char c:tasks){
        freq[c-'A']++;
       }
       //find the task with max frequency 
       int maxfreq=*max_element(freq.begin(), freq.end());
       //count how many tasks have max frequency
       int maxcount=count(freq.begin(), freq.end(), maxfreq);
       //minimum intervals required to place all most frequent tasks while respecting cooldowns.
       int part1=(maxfreq-1)*(n+1)+maxcount;
       return max(x,part1);

    }
    };

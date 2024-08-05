class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        vector<bool>visited(n, false);

        for(int i = 0; i < edges.size(); i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];

            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        queue<int>q;
        q.push(0);
        visited[0] = true;

        int ans = 1;
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int curr = q.front();
                q.pop();
                visited[curr] = true;

                for(int i = 0; i < graph[curr].size(); i++)
                {   
                    int child = graph[curr][i];
                    if(visited[child] != true)
                    {
                        q.push(child);
                        visited[child] = true;
                    }
                }

            }

            if(q.empty())
            {   
                bool flag = false;

                for(int i = 0; i < n; i++)
                  if(visited[i] != true)
                  {
                    q.push(i); flag = true;
                    break;
                  }
                  

                if(flag)
                    ans++;
                
            }
        
            
        }

        return ans;

    }
};
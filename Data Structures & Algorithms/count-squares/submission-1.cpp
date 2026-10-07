class CountSquares {
public:
    map<vector<int>, int> f;
    int minx = 1001;
    int miny = 1001;
    int maxX = 0;
    int maxY = 0;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        f[point]+=1;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        for(auto it: f){
            vector<int> p = it.first;
            if(p[0] == x or p[1] == y){
                continue;
            }

            if(abs(x-p[0]) != abs(y-p[1])) continue;
            int side = p[0]-x;
            
            if(f.count({x,p[1]}) && f.count({p[0], y})){
                ans+= f[{x,p[1]}]* f[{p[0],y}] * it.second;
            }
        }
        
        return ans;
    }
};

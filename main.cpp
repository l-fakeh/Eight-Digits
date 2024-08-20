#include<iostream>
#include<functional>
#include<string>
#include<queue>
#include<unordered_map>

std::string ans;
std::queue<std::string> q;
std::unordered_map<std::string,int> dis;
int d;

int main() {
    for(int i = 0 ;i < 9 ; i ++) {
        char c;
        std::cin >> c;
        ans += c;
    }

    std::function<int()> bfs = [&]() -> int {
        q.push(ans);
        int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};

        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            int d = dis[t];
            if(t == "12345678x") return d;

            int k = t.find('x');
            int x = k / 3, y = k % 3;

            for(int i = 0 ; i < 4 ; i++) {
                int a = x + dx[i], b = y + dy[i];
                if(a >= 0 && a < 3 && b >= 0 && b < 3 ) {
                    std::swap(t[k], t[a * 3 + b]);
                    if(!dis.count(t)) {
                        q.push(t);
                        dis[t] = d + 1;
                    }
                    std::swap(t[k], t[a * 3 + b]);
                }
            }
        }
        return -1;
    };

    d = bfs();  

    std::cout << d << '\n';
}
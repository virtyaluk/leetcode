class Vertex {
public:
    int vid;
    bool offline = false;
    int pgid = -1;

    Vertex() {}
    Vertex(int id): vid(id) {}
};

class Solution {
private:
    vector<Vertex> vertices = vector<Vertex>();

    void traverse(Vertex& u, int pgid, priority_queue<int, vector<int>, greater<int>>& pg, vector<vector<int>>& g) {
        u.pgid = pgid;
        
        pg.push(u.vid);

        for (const int& vid: g[u.vid]) {
            Vertex& v = vertices[vid];

            if (v.pgid == -1) {
                traverse(v, pgid, pg, g);
            }
        }
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> g(c + 1);
        vertices.resize(c + 1);
        vector<priority_queue<int, vector<int>, greater<int>>> pgs;
        vector<int> ans;

        for (int i = 1; i <= c; i++) {
            vertices[i] = Vertex(i);
        }

        for (const vector<int>& con: connections) {
            g[con.at(0)].push_back(con.at(1));
            g[con.at(1)].push_back(con.at(0));
        }

        for (int i = 1, pgid = 0; i <= c; i++) {
            auto& v = vertices[i];

            if (v.pgid == -1) {
                priority_queue<int, vector<int>, greater<int>> pg;

                traverse(v, pgid, pg, g);

                pgs.push_back(pg);

                pgid++;
            }
        }

        for (const vector<int>& q: queries) {
            int op = q.at(0),
                x = q.at(1);
            
            if (op == 1) {
                if (not vertices[x].offline) {
                    ans.push_back(x);
                } else {
                    auto& pg = pgs[vertices[x].pgid];

                    while (not empty(pg) and vertices[pg.top()].offline) {
                        pg.pop();
                    }

                    ans.push_back(not empty(pg) ? pg.top() : -1);
                }
            } else if (op == 2) {
                vertices[x].offline = true;
            }
        }

        return ans;
    }
};
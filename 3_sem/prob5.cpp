#include <iostream>
#include <vector>
using namespace std;

class Container {
    std::vector<Container*> g;
    int n;
    double x;

public:
    Container() {
        g.push_back(this);
        n = 1;
        x = 0;
    }

    double getAmount() {
        return x;
    }

    void addWater(double x) {
        double y = x / n;
        for (int i = 0; i < n; i++)
            g[i]->x += y;
    }

    void connectTo(Container* c) {
        double z = (x * n + c->x * c->n) / (n + c->n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c->n; j++) {
                g[i]->g.push_back(c->g[j]);
                c->g[j]->g.push_back(g[i]);
                //cerr << g[i] << " " << c -> g[j]<<endl;
            }
        }

        n += c->n;
        for (int i = 0; i < n; i++) {
            g[i]->n = n;
            g[i]->x = z;
        }
    }
};

int main(){
    Container a;
    Container b;
    Container c;
    Container d;
    
    a.addWater(12);
    d.addWater(12);
    a.connectTo(&b);
    cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << endl;
    a.connectTo(&d);
    cout << a.getAmount() << " " << b.getAmount() << " " << c.getAmount() << " " << d.getAmount() << endl;

}
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct Factory
{
    int price, rate;
    bool taken = false;
    Factory() : price(0), rate(0) {}
    Factory(int price, int rate) : price(price), rate(rate) {}
};

int D, C;
Factory factory1, factory2;

int ans;

void BuyFactory(Factory &factory)
{
    factory.taken = true;
    ans -= factory.price;
    C += factory.rate;
}

int main()
{
    ifstream fin("cookiesin.txt");
    fin >> D >> C >> factory1.price >> factory1.rate >> factory2.price >> factory2.rate;
    fin.close();

    while (D--)
    {
        ans += C;
        int f1 = -1, f2 = -1, fb = -1;
        if (!factory1.taken && ans >= factory1.price)
        {
            f1 = D * (factory1.rate + C) - factory1.price;
        }
        if (!factory2.taken && ans >= factory2.price)
        {
            f2 = D * (factory2.rate + C) - factory2.price;
        }
        
        if (f1 >= 0 && f2 >= 0)
        {
            if (ans >= factory1.price + factory2.price)
            {
                BuyFactory(factory1);
                BuyFactory(factory2);
            }
            else
            {
                if (f1 >= f2)
                {
                    BuyFactory(factory1);
                }
                else
                {
                    BuyFactory(factory2);
                }
            }
        }
        else if (f1 >= 0) BuyFactory(factory1);
        else if (f2 >= 0) BuyFactory(factory2);
        else continue;
    }

    ofstream fout("cookiesout.txt");
    fout << ans << endl;
    fout.close();

    return 0;
}
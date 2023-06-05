#include <iostream>

using namespace std;

const double PI = 3.1415;

double butelka(double cm)
{
    return 10 - (cm - 2) * (cm - 2);
}

double volume(unsigned int nr_of_rectangles, unsigned int a, unsigned int b)
{
    double h = (b-a)/(double)nr_of_rectangles;
    //cout<<"b-a: "<<b-a;
    double result = 0;

   // cout << "krok: h=" << h << endl;

    for(unsigned int i = 1; i<=nr_of_rectangles; ++i)
    {
        result += butelka(a + i*h)*h;
        //cout<<"Result: "<<result<<endl;
    }

    return result;
}

int main()
{
    unsigned int max_volume;
    double filled_volume;

    {
        unsigned int x, y, z;
        cin >> x >> y >> z;

        max_volume = x * y * z;
    }

    {
        double fill_level;
        cin >> fill_level;

        filled_volume = max_volume * fill_level;
    }

    unsigned int n;
    cin>>n;

    for(unsigned int i=1; i<=n; ++i)
    {
        double x;
        cin>>x;

        filled_volume += volume(100, 0, x);

        cout<<filled_volume<<endl;

        if(filled_volume > max_volume)
        {
            cout<<i;
            return 0;
        }
    }

    cout<<"NIE";

    return 0;
}